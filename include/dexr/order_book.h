#ifndef ORDER_BOOK_H_
#define ORDER_BOOK_H_

#include <cstddef>
#include <cstdint>
#include <functional>
#include <list>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <vector>

#include "order.h"
#include "trade.h"

namespace dexr {

class OrderBook {
 public:
  OrderBook() = default;
  OrderBook(const OrderBook&) = delete;
  OrderBook& operator=(const OrderBook&) = delete;

  std::vector<Trade> submit_order(Order incoming);
  bool cancel_order(std::uint64_t id);
  std::size_t size() const noexcept;

 private:
  using PriceLevel = std::list<Order>;

  using Bids =
      std::map<std::int64_t, PriceLevel, std::greater<>>;

  using Asks =
      std::map<std::int64_t, PriceLevel>;

  struct Location {
    Side side;
    std::int64_t price;
    PriceLevel::iterator position;
  };

  void add_resting_order(const Order& order);

  Bids bids_;
  Asks asks_;

  std::unordered_map<std::uint64_t, Location> locations_;
  std::unordered_set<std::uint64_t> used_ids_;
};

}  // namespace dexr

#endif /* ORDER_BOOK_H_ */