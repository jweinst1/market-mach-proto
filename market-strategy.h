#ifndef MARKET_STRATEGY_H
#define MARKET_STRATEGY_H

#include "market-types.h"

/**
 * @file Functionality for the market strategy type.
 */

#define MARKET_STRATEGY_OP_CHECK(ch) ((ch) == '>' || (ch) == '=' || (ch) == '<')

int Market_strategy_op_parse(char ch, MarketStrategyOp* op);

char Market_strategy_op_tochar(MarketStrategyOp op);

void Market_strategy_debug(const MarketStrategy* mst);


#endif // MARKET_STRATEGY_H
