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
}

int main(int argc, char const *argv[])
{
	test_MarketOrder_buy_power();
	return 0;
}
