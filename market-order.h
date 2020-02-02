#ifndef MARKET_ORDER_H
#define MARKET_ORDER_H

#include "market-types.h"

void MarketOrder_init(MarketOrder* o, 
	                  MarketID customer, 
	                  MarketID item,
	                  MarketOrderType type,
	                  double price,
	                  double amount);

double MarketOrder_buy_power(const MarketOrder* o);

#endif // MARKET_ORDER_H
