
#include <cassert>
#include <iostream>

#include "order_book.h"

int main() {
  dexr::OrderBook book;

  auto first = book.submit_order({
      1, dexr::Side::Buy, 105, 5
  });

  assert(first.empty());

  auto trades = book.submit_order({
      2, dexr::Side::Sell, 100, 3
  });

  assert(trades.size() == 1);
  assert(trades[0].buy_order_id == 1);
  assert(trades[0].sell_order_id == 2);
  assert(trades[0].price == 105);
  assert(trades[0].quantity == 3);

  for (const auto& trade : trades) {
    std::cout << "Trade: buy=" << trade.buy_order_id
              << " sell=" << trade.sell_order_id
              << " price=" << trade.price
              << " quantity=" << trade.quantity << '\n';
  }

  std::cout << "Resting orders: " << book.size() << '\n';

  book.submit_order({3, dexr::Side::Sell, 106, 2});

  std::cout << "Cancelled: " << std::boolalpha
            << book.cancel_order(3) << '\n';

  std::cout << "Resting orders: " << book.size() << '\n';

  return 0;
}
