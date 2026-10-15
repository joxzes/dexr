#ifndef MATCHING_ENGINE_H_
#define MATCHING_ENGINE_H_

#include <cstdint>
#include "order.h"

namespace dexr {
  std::uint64_t match_orders(Order& buy, Order& sell);
} // namspace dexr

#endif /* MATCHING_ENGINE_H_ */