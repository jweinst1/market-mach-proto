#include "unit-test-helper.h"
#include "market-order.h"


static void test_MarketOrder_buy_power(void)
{
	MarketOrder foo;
	double result;
	foo.price = 50.0;
	foo.amount = 10.0;
	foo.type = MARKET_ORDER_TYPE_BUY_M;
	result = MarketOrder_buy_power(&foo);
	UNIT_CHECK(result == 500.0);
	foo.type = MARKET_ORDER_TYPE_SELL_M;
	UNIT_CHECK(MarketOrder_buy_power(&foo) == 0.0);
}

static const MarketOrder TEST_HOM_DEMAND_ORDS[] = {
	{2, 4, MARKET_ORDER_TYPE_BUY_M, 5.0, 5.0},
	{10, 3, MARKET_ORDER_TYPE_BUY_M, 5.0, 5.0}
};

static const size_t TEST_HOM_DEMAND_ORDS_SIZE = sizeof(TEST_HOM_DEMAND_ORDS) / sizeof(MarketOrder);

static void test_MarketOrder_hom_demand(void)
{
	double result;
	double expected = 50.0;
	result = MarketOrder_hom_demand(TEST_HOM_DEMAND_ORDS, TEST_HOM_DEMAND_ORDS_SIZE);
	UNIT_CHECK(result == expected);
}

int main(int argc, char const *argv[])
{
	test_MarketOrder_buy_power();
	test_MarketOrder_hom_demand();
	return 0;
}
