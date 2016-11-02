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

number division(number num1, number num2) {
	int len1 = num1.intlen + num1.declen;
	int len2 = num2.intlen + num2.declen;
	int i = 0, j = 0, t;
	char *dividend = (char*) malloc(sizeof(char) * len1);	// required for taking care of each digit in the dividend
	while(num1.num[i]) {
		if(num1.num[i] != '.') {
			dividend[j] = num1.num[i];
			j++;
		}
		i++;
	}
	i = 0;
	j = 0;
	char *divisor = (char*) malloc(sizeof(char) * len2);	// required for taking care of each digit in the dividend
	while(num2.num[i]) {
		if(num2.num[i] != '.') {
			divisor[j] = num2.num[i];
			j++;
		}
		i++;
	}
	char* quotient = (char*) malloc(sizeof(char) * (len1 + 22)); // quotient string created for storing the full value and also upto 20 decimal digits.
	i = 0;
	int y = strlen(quotient);
	while(i < y) {
		quotient[i] = '0';
		i++;
	}
	int t1, t2;
	number newdiv;				// newdiv is a number created to create the dividend after each additional character taken
	init(&newdiv);
	number num10;
	init(&num10);
	num10 = convert_int_tonum(10);
	number digit;
	int c; 
	i = 0;
	number mult1;
	number mult2;
	init(&mult1);
	init(&mult2);
	
	number divisor1;
	init(&divisor1);
	divisor1 = create_number(divisor);

	number dividend1;
	init(&dividend1);
	dividend1 = create_number(dividend);
	
	while(dividend[i]) {		//	input one character at a time and adjust the dividend accordingly.
		c = dividend[i] - '0';				// conversion to integer
		newdiv = multiplication(newdiv, num10);		//multiplying original dividend by 10 as new integer in units place to be added
		init(&digit);
		digit = convert_int_tonum(c);

		newdiv = addition(newdiv, digit);			// adding the extra digit which is newly taken from the dividend
		t = number_compare(newdiv, divisor1);
			
		if(t >= 0) {		// if the dividend is greater or equal to the divisor which means there can be a quotient of 1 or more.
			for(j = 1 ; j < 10 ; j++) {		// loop to search linearly and find out the quotient between 1 to 9.
//	the dividend should be greater when multiplied by j, but smaller when multiplied by j + 1;
				if(j == 9) {
					quotient[i] = '9';
					break;
					i++;
				}
				init(&digit);
				digit = convert_int_tonum(j);
				init(&mult1);
				mult1 = multiplication(divisor1, digit);

				init(&digit);
				digit = convert_int_tonum(j + 1);
				init(&mult2);
				mult2 = multiplication(divisor1, digit);
				
				t1 = number_compare(mult1, newdiv);
				t2 = number_compare(mult2, newdiv);
				if((t1 <= 0) && (t2 > 0)) {
		/*  making newdiv = newdiv - (j * divisor) ;*/
					number temp1, temp2, temp3, temp4;
					init(&digit);
					digit = convert_int_tonum(j);
					init(&temp1);
					init(&temp2);
					temp2 = multiplication(digit, divisor1);
					newdiv = subtract(newdiv, temp2);
					quotient[i] = j + '0';
					break;
				}	
				
			}	
			// write a loop condition for 0 to 9 to find appropriate value of i
		}
//	if the dividend is already smaller than the divisor the quotient is 0 itself.
		else {
			quotient[i] = '0';
		}
		i++;
	}
// 	now computing for decimal part after inserting a decimal point in the quotient string.
	quotient[i] = '.';
	j = 0 ;
	i++;
	while(j < 5) {
		newdiv = multiplication(newdiv, num10);		//multiplying original dividend by 10 as new integer in units place to be added

		t = number_compare(newdiv, divisor1);
		if(t >= 0) {		// if the dividend is greater or equal to the divisor which means there can be a quotient of 1 or more.
			for(j = 1 ; j < 10 ; j++) {		// loop to search linearly and find out the quotient between 1 to 9.
//	the dividend should be greater when multiplied by j, but smaller when multiplied by j + 1;
				if(j == 9) {
					quotient[i] = '9';
					break;
					i++;
				}
				init(&digit);
				digit = convert_int_tonum(j);
				init(&mult1);
				mult1 = multiplication(divisor1, digit);

				init(&digit);
				digit = convert_int_tonum(j + 1);
				init(&mult2);
				mult2 = multiplication(divisor1, digit);
				
				t1 = number_compare(mult1, newdiv);
				t2 = number_compare(mult2, newdiv);
				if((t1 <= 0) && (t2 > 0)) {
					number temp1, temp2;
					init(&digit);
					digit = convert_int_tonum(j);
					init(&temp1);
					init(&temp2);
					temp2 = multiplication(digit, divisor1);
					newdiv = subtract(newdiv, temp2);
					quotient[i] = j + '0';
					break;
				}	
			}	
		}
		else {
			quotient[i] = '0';
		}
		i++;
		j++;
	}
	number z = create_number(quotient);
	if(((num1.sign == 0) && (num2.sign == 1)) || ((num1.sign == 1) && (num2.sign == 0)))	
		z.sign = 1;
	return z;
}
