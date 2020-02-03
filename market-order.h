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

double MarketOrder_sell_power(const MarketOrder* o);
/**
 * @brief Calculates the demand, assumes orders are heterogenous (both by and sell)
 */
double MarketOrder_het_demand(const MarketOrder* o, size_t length);
/**
 * @brief Calculates the demand, assumes orders are homogenous (only buy)
 */
double MarketOrder_hom_demand(const MarketOrder* o, size_t length);

#endif // MARKET_ORDER_H
