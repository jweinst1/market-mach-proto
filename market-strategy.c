#include "market-strategy.h"

int Market_strategy_op_parse(char ch, MarketStrategyOp* op)
{
	switch(ch) {
		case '=':
		    *op = MARKET_STRATEGY_OP_EQ;
		    return 1;
		case '>':
		    *op = MARKET_STRATEGY_OP_GT;
		    return 1;
		case '<':
		    *op = MARKET_STRATEGY_OP_LT;
		    return 1;
		default:
		    return 0;
	}
}

char Market_strategy_op_tochar(MarketStrategyOp op)
{
	switch(op) {
		case MARKET_STRATEGY_OP_GT:
		    return '>';
		case MARKET_STRATEGY_OP_LT:
		    return '<';
		case MARKET_STRATEGY_OP_EQ:
		    return '=';
	}
	return '\0';
}
