#include <algorithm>
#include "matching_engine.h"

namespace dexr {
  std::uint64_t match_orders(Order& buy, Order& sell)
  {
    if (buy.side != Side::Buy ||
        sell.side != Side::Sell ||
        buy.price <= 0 ||
        sell.price <= 0 ||
        buy.price < sell.price ||
        !buy.quantity ||
        !sell.quantity) {
          return 0;
        }

      const auto matched = std::min(buy.quantity, sell.quantity);

      buy.quantity -= matched;
      sell.quantity -= matched;

      return matched;
  }

}