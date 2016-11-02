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

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"number.h"
#include"functions.h"

//	this function basically sets the value of any number to be zero.
//	it will set the character array to null and all other digit lenghts also to be 0.
void init(number *a) {
	a->num = NULL;
	a->intlen = 0;
	a->declen = 0;
	a->sign = 0;
	return;
}

int check_legal(char *str) {
	int len = strlen(str);
	int i;
	for(i = 0 ; i < len ; i++) { 
		if((str[i] == '-') ||(str[i] == '.') || (str[i] == '0') || (str[i] == '1') || (str[i] == '2') || (str[i] == '3') || (str[i] == '4') || (str[i] == '5') || (str[i] == '6') || (str[i] == '7') || (str[i] == '8') || (str[i] == '9')) 
		continue;
		else {
			return 1;
		}
	}
	return 0;
}

number adjust_decimal(number num1) {
	int i, flag = 0, j = 0, k;
	int len = strlen(num1.num);
	for(i = len - 1 ; i > num1.intlen ; j++, i--) {
		if(num1.num[i] != '0') {
			flag = 1;
			break;
		}
	}
	if(flag == 0) {	
		number c;
		init(&c);
		c.num = (char*) malloc(sizeof(char) * num1.intlen);
		for(j = 0 ; j < num1.intlen ; j++)
			c.num[j] = num1.num[j];
		c.intlen = num1.intlen;
		c.declen = 0;
		c.sign = num1.sign;
		return c;
	}
	if(flag == 1) {
		if(i == len - 1)
			return num1;
		number c;
		init(&c);
		c.num = (char*) malloc(sizeof(char) * (len - j));
		for(k = 0 ; k < (len - j) ; k++)
			c.num[k] = num1.num[k];
		c.intlen = num1.intlen;
		c.declen = num1.declen - j;
		c.sign = num1.sign;
		return c;
	}
}
number adjust_number(number a) {
	if(a.declen != 0) 
		a = adjust_decimal(a);
	number b;
	init(&b);
	int nonzero = 0;
	int i = 0, j, k;
	while(a.num[i]) {
		if((a.num[i] != '0') && (a.num[i] != '.')) {
			nonzero = 1;
			break;
		}
		i++;
	}
	i = 0;
	if(nonzero == 0) {
		b.num = (char*) malloc(sizeof(char) * 1);
		b.num[0] = '0';
		b.intlen = 0;
		b.declen = 0;
		b.sign = 0;
		return b;
	}
	
	int flag = 0;
	while(a.num[i] != '.') {
		if(a.num[i] != '0') {
			if(i == 0) {	
				return a;
				break;
			}
			k = 0;
			j = i;
			b.num = (char*) malloc(sizeof(char) * (a.declen + 1 + a.intlen - j));
			while(a.num[i]) {
				b.num[k] = a.num[i];
				k++;
				i++;
			}
			b.declen = a.declen;
			b.sign = a.sign;
			b.intlen = a.intlen - j;
			return b;
			
			// remove all zeroes to the left
			// set flag to 1
			break;
		}
		i++;
	}
	k = 0 ;
	b.num = (char*) malloc(sizeof(char) * (a.declen + 1));
	while(a.num[i]) {
		b.num[k] = a.num[i];
		k++;
		i++;
	}
	b.intlen = 0;
	b.declen = a.declen;
	b.sign = a.sign;
	return b;
	//	if(flag == 0) then start pointing at the decimal point itself and set intlen to be zero.
}

//	this function creates a number from a given string.
//	this function is widely used in operation functions to create and return a number once the result is obtained in a string.
number create_number(char *str) {
//	str = remove_zero(str);
	int legal = check_legal(str);
	if(legal == 1) {
		perror("(standard_in) 1:syntax error");	// basic check to see if the stirng is valid or not.
		exit(0);
	}
	number a;
	init(&a);
	int len , i = 0;
	len = strlen(str);
	a.num = (char*) malloc(sizeof(char) * len);	// generating enough space for the entire number to fit
	strcpy(a.num , str);				// copying in the data structure
	if(a.num[0] == '-') {
		a.sign = 1;				// adjustment required for negative numbers
		a.num++;				// sign converted and points to the next proper digit
	}
	len = strlen(a.num);
	i = 0;
	while(i < len) {
		if(a.num[i] == '.') {
			a.intlen = i;			// calculating the integer length till a decimal point is found.
			a.declen = len - a.intlen - 1;	// calculating the decimal length accordingly
//			return a;
			goto ahead;
		}
		i++;
	}
	a.intlen = len;
	a.declen = 0;
	ahead : ;
	number c;
	c = adjust_number(a);
	return c;
	
}

//	this function prints the number.
//	used so that once a number is passed it will point to the string and print by itself and need not be done in other requisite functions.
void print_number(number a) {		
	if(a.sign == 1)
		printf("-");	
	printf("%s\n",a.num);
//	printf("%d %d %d\n", a.intlen, a.declen, a.sign);
	return;
}

