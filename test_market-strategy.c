#include "unit-test-helper.h"
#include "market-strategy.h"


static void test_Market_strategy_op_parse(void)
{
	MarketStrategyOp op;
	char to_test = '>';
	char to_test_2 = 'e';
	UNIT_CHECK(Market_strategy_op_parse(to_test, &op));
	UNIT_CHECK(!Market_strategy_op_parse(to_test_2, &op));
}


int main(int argc, char const *argv[])
{
	test_Market_strategy_op_parse();
	return 0;
}
