#include "market-order.h"

void MarketOrder_init(MarketOrder* o, 
	                  MarketID customer, 
	                  MarketID item,
	                  MarketOrderType type,
	                  double price,
	                  double amount)
{
	o->customer = customer;
	o->item = item;
	o->type = type;
	o->price = price;
	o->amount = amount;
}

double MarketOrder_buy_power(const MarketOrder* o)
{
	switch (o->type) {
		case MARKET_ORDER_TYPE_BUY_L:
		case MARKET_ORDER_TYPE_BUY_M:
		    return o->price * o->amount;
		default:
		    return 0.0;
	}
}

double MarketOrder_sell_power(const MarketOrder* o)
{
	switch (o->type) {
		case MARKET_ORDER_TYPE_SELL_L:
		case MARKET_ORDER_TYPE_SELL_M:
		    return o->price * o->amount;
		default:
		    return 0.0;
	}
}

double MarketOrder_het_demand(const MarketOrder* o, size_t length)
{
	double demand = 0.0;
	const MarketOrder* oend = o + length;
	while (o != oend) {
		switch(o->type) {
			case MARKET_ORDER_TYPE_BUY_L:
			case MARKET_ORDER_TYPE_BUY_M:
			    demand += (o->price * o->amount);
			default:
			    break;	
		}
		++o;
	}

	return demand;
}

double MarketOrder_hom_demand(const MarketOrder* o, size_t length)
{
	double demand = 0.0;
	const MarketOrder* oend = o + length;
	while (o != oend) {
		demand += (o->price * o->amount);
		++o;
	}
	return demand;
}
