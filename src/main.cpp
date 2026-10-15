#include <iostream>
#include "order.h"
#include "matching_engine.h"
#include "order_book.h"

int main()
{
  dexr::Order buy{1, dexr::Side::Buy, 105, 5};
  dexr::Order sell{2, dexr::Side::Sell, 100, 3};

  dexr::OrderBook book;

  const auto matched = dexr::match_orders(buy, sell);

  if (!matched) {
    std::cout << "No match\n";
    return 0;
  }

  std::cout << "Trade executed!\n";
  std::cout << "Matched quantity: " << matched << '\n';
  std::cout << "Buy remaining: " << buy.quantity << '\n';
  std::cout << "Sell remaining: " << sell.quantity << '\n';

  book.add_order({3, dexr::Side::Buy, 104, 2});
  book.add_order({4,dexr::Side::Sell, 103, 1});
  book.add_order({5, dexr::Side::Buy, 102, 8});

  std::cout << "Stored orders: " << book.size() << '\n';
  std::cout << "First order price: " << book.at(0).price << '\n'; 

  const bool cancelled = book.cancel_order(4);

  std::cout << "Order cancelled: " << (cancelled ? "True" : "False") << '\n';
  std::cout << "Remaining orders: " << book.size() << '\n';

  return 0;
} 