/*  This file is part of Infinite Calculator.

    Infinite Calculator is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    Infinite Calculator is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    This software has been developed and mantained by Vivek Bhave. The only release of this software is in 2016. 
*/

#ifndef __FUNCTIONS_H
#define __FUNCTIONS_H

#include"number.h"
#include"list.h"


//	this file includes the prototypes of all functions used in any file of the source code of the software
// 	writing the file names before the prototypes of all functions used in thar particular file.

//	createnum.c
void init(number *a);
number create_number(char *str);
void print_number(number a);
int check_legal(char *str);
number adjust_decimal(number num1);
number adjust_number(number a);

//	addition.c
number addition(number num1, number num2);
char* add_strings(char* n1, char* n2, int* carry);

//	multiplication.c
number multiplication(number num1, number num2);
void create_string(char *res, int k, int j);
list createlist(number num1);

//	comparison.c
int number_compare(number num1, number num2);
int compare(char c, char d);
int ret_value(int a, number num1, number num2);
int mag_compare(number num1, number num2);

//	general.c
int int_compare(int a, int b);
int int_maximum(int a, int b);
int int_minimum(int a, int b);
//number adjut_number(number a);
number convert_int_tonum(int a);

//	base.c
int base_legal(number a, int b);
number convert_decimal_tobase(number a, int base);

//	subtract.c
number subtract(number num1, number num2);

//	logical_operators.c
int logical_and(number a, number b);
int logical_or(number a, number b);

//	division.c
number division(number num1, number num2);

//	power.c
number power(number num1, number num2);

//	modulus.c
number modulus(number num1, number num2);
#endif
