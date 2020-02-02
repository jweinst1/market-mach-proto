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
