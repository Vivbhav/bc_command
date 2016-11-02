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

number subtract(number num1, number num2) {

	int equal = 0;
	equal = number_compare(num1, num2);
	if(equal == 0) {
		number b;
		init(&b);
		b.num = (char*) malloc(sizeof(char));
		b.num[0] = '0';
		b.intlen = 1;
		b.declen = 0;
		b.sign = 0;
		return b;
	}		
	number sub , add;
	init(&sub);
	init(&add);
	int maxdeclen = 0, t, j, i;
	int maxintlen = 0, maxlen = 0;
	int flag = 0;
//	if first numbers magnitude is smaller than the other, then the order of the numbers is reversed and sign is inverted.
	if((num1.sign == 0) && (num2.sign == 0)) {	
		int t = mag_compare(num1, num2);
		if(t < 0) {
			add = subtract(num2, num1);
			add.sign = 1;
			return add;
		}
	}

//	if the first number is positive and the second is negative, two negatives make a positive and hence addition function is called
	if((num1.sign == 0) && (num2.sign == 1)) {
		num2.sign = 0;
		add = addition(num1, num2);
		return add;
	}

//	same as above case
	if((num1.sign == 1) && (num2.sign == 0)) {
		num1.sign = 0;
		add = addition(num1, num2);
		add.sign = 1;
		return add;
	}

//	if both numbers are negative then the order is changed for ordering of the correct sign.
	if((num1.sign == 1) && (num2.sign == 1)) {
		num2.sign = 0;
		sub = addition(num2 , num1);
		return sub;
	}
	
//	actual function to subtract a number with smaller magnitude than a number with greater magnitude starts here
//	similar to addition, the decimal and integral parts are calculated separately.

//	first computing for decimal part.
	maxdeclen = int_maximum(num1.declen, num2.declen);
	t = int_compare(num1.declen , num2.declen);
	char *no1, *no2;
	no1 = (char*) malloc(sizeof(char) * maxdeclen);
	no2 = (char*) malloc(sizeof(char) * maxdeclen);
//	for proper adjustment while calculation, zeroes are added to the right in the appropriate number whereever necesary
//	situation handled case wise whether equal, or one of the two numbers has a greater length.
	if(t == 0) {
		j = num1.intlen + 1;
		for(i = 0 ; i < num1.declen ; i++ , j++) 
			no1[i] = num1.num[j];
		j = num2.intlen + 1;
		for(i = 0 ; i < num2.declen ; i++, j++) 
			no2[i] = num2.num[j];
	}
	if(t == 1) {
		j = num1.intlen + 1;
		for(i = 0 ; i < num1.declen ; i++, j++) 
			no1[i] = num1.num[j];
		j = num2.intlen + 1;
		for(i = 0 ; i < num2.declen; i++,j++) 
			no2[i] = num2.num[j];
		j = i;
		for(i = 0; i < (maxdeclen - num2.declen) ;i++,j++) {
			no2[j] = '0';
		}
	}
	if(t == -1) {
		j = num2.intlen + 1;
		for(i = 0 ; i < num2.declen ; i++, j++) 
			no2[i] = num2.num[j];
		j = num1.intlen + 1;
		for(i = 0 ; i < num1.declen; i++,j++) 
			no1[i] = num1.num[j];
		j = i;
		for(i = 0; i < (maxdeclen - num1.declen) ;i++,j++) {
			no1[j] = '0';
		}
	}

//	now doing above procedure for integral part.
//	zeroes added to the left wherever required.
	maxintlen = int_maximum(num1.intlen, num2.intlen);
	t = int_compare(num1.intlen, num2.intlen);
	char *n1, *n2;
	n1 = (char*) malloc(sizeof(char) * maxintlen);
	n2 = (char*) malloc(sizeof(char) * maxintlen);
	if(t == 0) {
		for(i = 0 ; i < num1.intlen ; i++) 
			n1[i] = num1.num[i];

		for(i = 0 ; i < num2.intlen ; i++) 
			n2[i] = num2.num[i];
	}
	if(t == 1) {
		for(i = 0 ; i < maxintlen ; i++) 
			n1[i] = num1.num[i];
		int add = num1.intlen - num2.intlen ;
		for(i = 0 ; i < add ; i++) 
			n2[i] = '0';
		for(i = add, j = 0 ; i < maxintlen ; j++, i++) 
			n2[i] = num2.num[j];
	}	
	if(t == -1) {
		for(i = 0 ; i < maxintlen ; i++) 
			n2[i] = num2.num[i];
		int add = num2.intlen - num1.intlen ;
		for(i = 0 ; i < add ; i++) 
				n1[i] = '0';
		for(i = add, j = 0 ; i < maxintlen ; j++, i++) 
			n1[i] = num1.num[j];
	}	
	maxlen = maxintlen + maxdeclen;

//	first and second store the value of the first and second number without any decimal point in between.
//	allocating space as required, for the numbers to be copied
	char *first = (char*) malloc(sizeof(char) * maxlen);
	char *second = (char*) malloc(sizeof(char) * maxlen);
	char *result = (char*) malloc(sizeof(char) * (maxlen + 1));

//	integral part is directly copied. and the decimal string is then concatenated to this first string.
	strcpy(first , n1);
	strcat(first, no1);
//	done for second number as done for the first number
	strcpy(second, n2);
	strcat(second, no2);

//	computing the resultant digit by digit.
//	both digits taken, previous borrow adjusted and the resultant calculated
	int borrow = 0;
	int d1, d2, d3;
	for(i = maxlen - 1 ;i >= 0 ; i--) {
		d1 = first[i] - '0';
		d2 = second[i] - '0';
		d3 = d1 - d2 - borrow;
		if(d3 < 0) {
			d3 += 10;
			borrow = 1;
		}
		else
			borrow = 0;
		result[i] = d3 + '0';
	}	
//	decimal point needs to be adjusted eventually.
//	so the number of decimals as known from earlier, those many digits are shifted to the right by one position.
// 	in the empty space created the decimal point is inserted and thus the correct output is generated.
	for(i = maxlen, j = 0 ; j <maxdeclen ; i--,j++) {
		result[i] = result[i-1];
	}
	result[i] = '.';
//	number created from the result string and then returned
	sub = create_number(result);
	return sub;
}
