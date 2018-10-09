#include "gtest/gtest.h"
#include "CryptoNoteCore/Difficulty.h"
#include "CryptoNoteCore/Difficulty.cpp"
#include <random>

using namespace CryptoNote;

/*

My Notes

mul()
mul()
cadd()
cadc()()
check_hash()

*/

uint32_t loopCount = 100;

// mul(uint64_t a, uint64_t b, uint64_t &low, uint64_t &high)
TEST(Difficulty, 1)
{
  uint64_t low;
  uint64_t high;

  // 1 x 1
  // store least significant 64 bits of result in low
  // store most significant 64 bits of result in high
  // result is 128 bits long
  mul(1, 1, low, high);
  ASSERT_EQ(low, 1);
  ASSERT_EQ(high, 0);

  mul(100, 100, low, high);
  ASSERT_EQ(low, 10000);
  ASSERT_EQ(high, 0);

  // 2^64 = 18446744073709551616
  // need suffix ULL because the number is too large for an int
  // a equals 2^64 - 1
  // a equals binary 1111111111111111111111111111111111111111111111111111111111111111
  uint64_t a = 18446744073709551615ULL;
  
  // result of a x 2 is 1|1111111111111111111111111111111111111111111111111111111111111110 where high is to the left of | and low is to the right of |
  mul(a, 2, low, high);
  // low equals binary 1111111111111111111111111111111111111111111111111111111111111110 which equals 18446744073709551614 in decimal
  ASSERT_EQ(low, 18446744073709551614ULL);
  ASSERT_EQ(high, 1);
}

// bool cadd(uint64_t a, uint64_t b)
// tells if a + b causes an overflow
TEST(Difficulty, 2)
{
  // 1 + 1 < 1
  ASSERT_FALSE(cadd(1, 1));
  // 100 + 5 < 100
  ASSERT_FALSE(cadd(100, 5));
  ASSERT_FALSE(cadd(18446744073709551614ULL, 1));

  // 18446744073709551615ULL equals 1111111111111111111111111111111111111111111111111111111111111111
  // adding 1 will cause the number to wrap around back to zero
  ASSERT_TRUE(cadd(18446744073709551615ULL, 1));
}

// bool cadc(uint64_t a, uint64_t b, bool c)
// tells if a + b causes an overflow
// if c is true, tells if a + b equals 2^64 - 1
TEST(Difficulty, 3)
{
  ASSERT_FALSE(cadc(1, 1, true));
  ASSERT_FALSE(cadc(100, 100, true));

  // sum equals 2^64 - 1
  ASSERT_FALSE(cadc(18446744073709551614ULL, 1, false));
  ASSERT_TRUE(cadc(18446744073709551614ULL, 1, true));

  // overflow has occurred
  ASSERT_TRUE(cadc(18446744073709551615ULL, 1, false));
  ASSERT_TRUE(cadc(18446744073709551615ULL, 1, true));
}

// check_hash()
//   checks for overflow in hash by multiplying each word of hash with difficulty and seeing if there is overflow
// swap64le(((const uint64_t *) &hash)[3])
TEST(Difficulty, 4)
{
  Crypto::Hash hash =
    {
      0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
      0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
      0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
      0x00, 0x00
    };
  difficulty_type difficulty = 1;
  ASSERT_TRUE(check_hash(hash, difficulty));

  // a hash has 32 uint8_t
  // each uint8_t is 8 bits long or 1 byte long
  // therefore a hash is 32 bytes long or 256 bits long
  // on a 64-bit machine, a word is 64 bits long or 8 bytes long
  // since each hash is 32 bytes long, there are 4 words in each hash
  // the highest word is the right-most 8 bytes or right-most 8 entries
  hash =
    {
      0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
      0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
      0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFF,
      0xFF, 0xFF
    };
  // temp equals 0xFFFFFFFF00000000
  // [3] means the 4th word in hash
  uint64_t temp = swap64le(((const uint64_t *) &hash)[3]);

  hash =
    {
      0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
      0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
      0x00, 0x00, 0x00, 0x00, 0x01, 0x23, 0x45, 0x67, 0x89, 0xAB,
      0xCD, 0xEF
    };
  // temp equals 0xEFCDAB8967452301
  temp = swap64le(((const uint64_t *) &hash)[3]);
}

// check_hash()
// check if highest word overflows
TEST(Difficulty, 5)
{
  Crypto::Hash hash =
    {
      0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
      0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
      0x00, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
      0xFF, 0x0F
    };

  // multiply by 2 is the same as left shift by 1
  difficulty_type difficulty = 2;
  // temp equals 0x0FFFFFFFFFFFFFFF
  // if we left shift temp by 1, temp does not overflow
  uint64_t temp = swap64le(((const uint64_t *) &hash)[3]);
  ASSERT_TRUE(check_hash(hash, difficulty));

  hash =
    {
      0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
      0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
      0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
      0x00, 0x80
    };

  // multiply by 2 is the same as left shift by 1
  difficulty = 2;
  // temp equals 0x8000000000000000
  // 0x80 is 10000000 in binary
  // if we left shift 10000000 by 1, there will be overflow
  temp = swap64le(((const uint64_t *) &hash)[3]);
  ASSERT_FALSE(check_hash(hash, difficulty));

  // for there to not be overflow in the highest word, hash[31] must be less than 0x80 or 128
}

// check_hash()
// overflows
TEST(Difficulty, 6)
{
  Crypto::Hash hash =
    {
      0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x00, 0x00,
      0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
      0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
      0x00, 0x00
    };

  // multiply by 2 is the same as left shift by 1
  difficulty_type difficulty = 2;
  // temp equals 0x8000000000000000
  // if we left shift temp by 1, temp overflows
  uint64_t temp = swap64le(((const uint64_t *) &hash)[0]);
  ASSERT_TRUE(check_hash(hash, difficulty));

  hash =
    {
      0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x40, 0x00, 0x00,
      0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
      0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
      0x00, 0x00
    };

  // multiply by 4 is the same as left shift by 2
  difficulty = 4;
  // temp equals 0x4000000000000000
  // if we left shift temp by 2, temp overflows
  temp = swap64le(((const uint64_t *) &hash)[0]);
  ASSERT_TRUE(check_hash(hash, difficulty));

  hash =
    {
      0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0F, 0x00, 0x00,
      0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
      0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
      0x00, 0x00
    };

  // multiply by 32 is the same as left shift by 5
  difficulty = 32;
  // temp equals 0x0F00000000000000
  // if we left shift temp by 5, temp overflows
  temp = swap64le(((const uint64_t *) &hash)[0]);
  ASSERT_TRUE(check_hash(hash, difficulty));
}

int main(int argc, char** argv)
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}