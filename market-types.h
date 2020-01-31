#ifndef MARKET_TYPES_H
#define MARKET_TYPES_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

/**
 * Single header of the types uses for a market.
 */

/**
 * A unique ID for every type of member in a market.
 */
typedef long MarketID;

typedef enum {
  MARKET_STRATEGY_OP_LT,
  MARKET_STRATEGY_OP_EQ,
  MARKET_STRATEGY_OP_GT
} MarketStrategyOp;

typedef enum {
  MARKET_ORDER_TYPE_SELL_M,
  MARKET_ORDER_TYPE_SELL_L,
  MARKET_ORDER_TYPE_BUY_M,
  MARKET_ORDER_TYPE_BUY_L
} MarketOrderType;

typedef struct {
  MarketID customer;
  MarketID item;
  MarketStrategyOp op;
  double amount;
  double cprice;
  MarketOrderType act;
  double lprice; // not used for market orders.
} MarketStrategy;

typedef struct {
	MarketID customer;
	MarketID item;
	MarketOrderType type;
	double price;
	double amount;
} MarketOrder;

typedef struct {
	MarketID id;
	double price;
	MarketOrder* buy_orders;
	size_t buy_size;
	MarketOrder* sell_orders;
	size_t sell_size;
} MarketItem;

typedef struct {
	MarketID item;
	double cost_basis;
	double amount;
} MarketCustomerPosition;

typedef struct {
	MarketID id;
	MarketCustomerPosition* owned;
	MarketID owned_size;
	double cash;
} MarketCustomer;

typedef struct {
	MarketCustomer* customers;
	MarketID customers_size;
	MarketItem* items;
	MarketID items_size;
	MarketStrategy* strategies;
	size_t strategy_size;
	unsigned votality;
	size_t turns;
} Market;

#endif // MARKET_TYPES_H
