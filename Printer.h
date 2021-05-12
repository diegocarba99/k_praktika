#include "Lag.h"

void printErrorsPreamble();
void printErrors (message_list errors);
void kalkulatuErroreak(message_list &errors, var_st &var, expr_st &expr);
void kalkulatuErroreak(message_list &errors, int type, expr_st &expr);
void kalkulatuErroreak(message_list &errors, int type, var_st &var);
int kalkulatuMota(expr_st &e, expr_st &e1, expr_st &e2);
