#ifndef MARKET_DEBUG_MESSAGES_H
#define MARKET_DEBUG_MESSAGES_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DEBUG_MES(mes) printf("DEBUG::mes -> '%s'\n", mes)
#define DEBUG_MES_EXP(exp) printf("DEBUG::exp -> '%s'\n", #exp)

#define DEBUG_MES_WLINE(mes) printf("DEBUG::mes -> '%s' LINE:%u\n", mes, (unsigned)__LINE__)



#endif // MARKET_DEBUG_MESSAGES_H
