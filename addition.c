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

// this function accepts two strings and returns their addition as output.
// carry is another arguement as first the decimals are added and the carry should be used while adding the integral part.
char* add_strings(char* n1, char* n2, int* carry) {
	int d1, d2;
	int i, s;
	int n = strlen(n1);
	char* res;
	res = (char*) malloc(sizeof(char) * (n + 1));
	for(i = n - 1 ; i >= 0 ; i--) {
		d1 = n1[i] - '0';
		d2 = n2[i] - '0';
		s = d1 + d2 + *carry; // result digit calculated by addition of the corresponding digit in the numbers and the earlier carry.
		*carry = s / 10;
		if(*carry != 0)
			s = s - 10; // adjusting the sum and carry in case the sum goes above 10. (and thus carry may get generated.)
		res[i] = s + '0';
	}
	res[n] ='\0';
	return res;
}

number addition(number num1, number num2) {
	number sub;
	init(&sub);  // this will be the result.
	int z;

// if one number is positive and the other negative, then the two numbers are subtracted. so those cases are being considered before further operations separately.
	if((num1.sign == 0) && (num2.sign == 1)) {  
		z = mag_compare(num1, num2);  // the smaller number of the two in magnitude will be subtracted from the other
		if(z >= 0) {
			num2.sign = 0;
			sub = subtract(num1, num2);
			sub.sign = 0;
			return sub; 
		}
		else {
			num2.sign = 0;
			sub = subtract(num2, num1);
			sub.sign = 1;
			return sub;
		}
	}

// similar case to above when the second number passed is negative and the first positive
	if((num2.sign == 0) && (num1.sign == 1)) { 
		z = mag_compare(num2 , num1);
		if(z >= 0) {
			num1.sign = 0;
			sub = subtract(num2,  num1);
			sub.sign = 0;
			return sub;
		}
		else {
			num1.sign = 0;
			sub = subtract(num1, num2);
			sub.sign = 1;
			return sub;
		}
	}

// code for adding two numbers of same sign
	number sum;
	init(&sum);
	int maxdeclen = 0, maxintlen = 0 ;
	int i , j, t;
	int* carry = (int*) malloc(sizeof(int));
	carry = 0;
	maxdeclen = int_maximum(num1.declen, num2.declen); // calculating maximum number of digits in decimal.

	t = int_compare(num1.declen , num2.declen);
	char *no1, *no2;
	no1 = (char*) malloc(sizeof(char) * maxdeclen); // allocating space for the decimals according to the requirement calculated
	no2 = (char*) malloc(sizeof(char) * maxdeclen);


// for adding the decimal part of the two numbers, the number of digits in both the numbers must be same. so code written according to different cases which may arise.
	if(t == 0) { // if they already have equal number of digits. the two numbers just need to be copied to the new strings in this case
		j = num1.intlen + 1;
		for(i = 0 ; i < num1.declen ; i++ , j++) 
			no1[i] = num1.num[j];
		j = num2.intlen + 1;
		for(i = 0 ; i < num2.intlen ; i++, j++) 
			no2[i] = num2.num[j];
	}
	if(t == 1) { // if the first number has more digits
		j = num1.intlen + 1;
		for(i = 0 ; i < num1.declen ; i++, j++)  // first string is copied as is
			no1[i] = num1.num[j];
		j = num2.intlen + 1;
		for(i = 0 ; i < num2.declen; i++,j++) 
			no2[i] = num2.num[j]; 		// second string copied with the digits it has
		j = i;
		for(i = 0; i < (maxdeclen - num2.declen) ;i++,j++) {
			no2[j] = '0'; 			// adding zeroes to the end of the second string to keep value same and be able to add
		}
	}
	if(t == -1) {
		j = num2.intlen + 1;
		for(i = 0 ; i < num2.declen ; i++, j++) // second string copied with as is
			no2[i] = num2.num[j];
		j = num1.intlen + 1;
		for(i = 0 ; i < num1.declen; i++,j++) 
			no1[i] = num1.num[j];		// first string copied with as many digits as it has
		j = i;
		for(i = 0; i < (maxdeclen - num1.declen) ;i++,j++) {
			no1[j] = '0';			// adding zeroes to the end of the first string
		}	
	}
	char *dec = (char*) malloc(sizeof(char) * maxdeclen);  // creating this string for storing the result
	dec = add_strings(no1, no2, &carry);

// decimal part addition is completed. now moving to integral part addition. addition is done similarly as before. in this case the number which has lesser digits is added with requisite number of zeroes to the left.
	maxintlen = int_maximum(num1.intlen, num2.intlen);
	t = int_compare(num1.intlen, num2.intlen);
	char *n1, *n2;
	n1 = (char*) malloc(sizeof(char) * maxintlen);// strings to store the integral part of the numbers
	n2 = (char*) malloc(sizeof(char) * maxintlen);
	if(t == 0) {					// case where both the numbers have equal digits. and are both copied as is.
		for(i = 0 ; i < num1.intlen ; i++) 
			n1[i] = num1.num[i];

		for(i = 0 ; i < num2.intlen ; i++) 
			n2[i] = num2.num[i];
	}
	if(t == 1) {					// if first number has more number of digits
		for(i = 0 ; i < maxintlen ; i++) 
			n1[i] = num1.num[i];		// first stirng copied as is
		int add = num1.intlen - num2.intlen ;
		for(i = 0 ; i < add ; i++) 
			n2[i] = '0';			// zeroes inserted before the number to make the number of digits equal
		for(i = add, j = 0 ; i < maxintlen ; j++, i++) 
			n2[i] = num2.num[j];		// copying the actual digits of the number
	}	
	if(t == -1) {					// if first number has lesser number of digits
		for(i = 0 ; i < maxintlen ; i++) 
			n2[i] = num2.num[i];		// copying the second number as is
		int add = num2.intlen - num1.intlen ;
		for(i = 0 ; i < add ; i++) 
				n1[i] = '0';		// adding zeroes as required in the first number
		for(i = add, j = 0 ; i < maxintlen ; j++, i++) 
			n1[i] = num1.num[j];		// copying the actual digits of the number
	}	

	char* intadd;
	intadd = (char*) malloc(sizeof(char) * maxintlen + 1);
	intadd = add_strings(n1, n2, &carry);		// adding the integral part of the numbers

	char* result = (char*) malloc(sizeof(char) * (maxintlen + maxdeclen + 2));
	strcpy(result, intadd);				// copying the integral part into the final result
	result[maxintlen] = '.';			
	strcat(result, dec);				// concatenating the decimal part after inserting the .
	sum = create_number(result);
	if((num1.sign == 1) && (num2.sign == 1))	
		sum.sign = 1;				// if both numbers are negative converting the sign of the result also to be negative
	return sum;	
}
