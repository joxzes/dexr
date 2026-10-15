#ifndef TRADE_H_
#define TRADE_H_

#include <cstdint>

namespace dexr {

  struct Trade {
    std::uint64_t buy_order_id{};
    std::uint64_t sell_order_id{};
    std::int64_t price{};
    std::uint64_t quantity{};
  };
  
} // namespace dexr

#endif /* TRADE_H_ */