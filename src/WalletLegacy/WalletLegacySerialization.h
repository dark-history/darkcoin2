// Copyright (c) 2011-2016 The Cryptonote developers
// Copyright (c) 2018-2022 The Cash2 developers
// Distributed under the MIT/X11 software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#pragma once

#include <stdexcept>
#include <algorithm>
#include <string>

#include "IWalletLegacy.h"

namespace CryptoNote {
class ISerializer;

struct UnconfirmedTransferDetails;
struct WalletLegacyTransaction;
struct WalletLegacyTransfer;

void serialize(UnconfirmedTransferDetails& utd, ISerializer& serializer);
void serialize(WalletLegacyTransaction& txi, ISerializer& serializer);
void serialize(WalletLegacyTransfer& tr, ISerializer& serializer);

}
