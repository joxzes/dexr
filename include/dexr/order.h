#ifndef ORDER_H_
#define ORDER_H_

#include <cstdint>

namespace dexr {

  enum class Side {
    Buy,
    Sell
  };

  struct Order {
    std::uint64_t id{};
    Side side{};
    std::int64_t price{};
    std::uint64_t quantity{};
  };
  
} // namespace dexr

#endif /* ORDER_H_ */