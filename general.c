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

//	simply compares two integers and return -1, 0 or 1 depending on whether first is smaller, equal to or bigger than the second
int int_compare(int a, int b) {
	if(a > b) 
		return 1;
	if(a < b) 
		return -1;
	return 0;
}

//	computes the maximum value of the two integers
//	if the two numbers are equal, the same value will be returned as equality is not the point here, it is just about getting the larger integer of the two
int int_maximum(int a, int b) {
	if(a > b) 
		return a;
	return b;
}

//	similar to the above function calculating to the minimum of the two integers.
//	as above even if the two numbers are equal, the same value will be returned as the equality condition doesn't matter here.
int int_minimum(int a, int b) {
	if(a < b)
		return 1;
	return 0;
}

// this function converts an integer to a number. an integer's digits need to be converted into characters and other parameters need to be generated.
// as this requirement props up several times in the code, a function for convineient usage has been developed for the same
number convert_int_tonum(int a) {
	number num1;
	init(&num1);
	int i = 0, j;
	char c;
	char* str = (char*) malloc(sizeof(char) * 10);/*
	if(a == 0) {
		num1.num = "0";
		num1.intlen = 1;
		num1.declen = 0;
		return num1;
	}*/
	if(a < 0) 
		num1.sign = 1;
	while(a != 0) {
		j = a % 10;
		c = j + '0';
		str[i] = c ;
		a /= 10;
		i++;
	}
	str[i] = '\0';

	for(j = 0 ; j < i/2 ; j++) {
		c = str[j];
		str[j] = str[i - j - 1];
		str[i - j - 1] = c;
	}

	num1 = create_number(str);
	return num1;
}
