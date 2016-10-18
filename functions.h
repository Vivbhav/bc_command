#ifndef __FUNCTIONS_H
#define __FUNCTIONS_H

number Add(number num1, number num2);
int less(number num1, number num2);
int greater(number num1, number num2);
int equal(number num1, number num2);

void print_number(number *l);
number create_number(char *str);
//void init(number *a);
void insert(number *l, char *c);
#endif
