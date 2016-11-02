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

int number_compare(number num1, number num2) {
	int x;
	// lesser means if num1 is strictly lesser than num2 i will return 1 else i return 0
	if((num1.sign == 1) && (num2.sign == 0)) 	// if the first number is negative and the other positive, immediately the first number becomes smaller
		return -1;
	if((num1.sign == 0) && (num2.sign == 1)) 	// if the first number is positive and the other negative, immediately the first is greater
		return 1;
	if(num1.intlen > num2.intlen) {
		x = ret_value(1, num1, num2);		// the one with greater length of integers will be greater than the other
		return x;
	} 
	if(num1.intlen < num2.intlen) {
		x = ret_value(-1, num1, num2);		// second is greater by above logic
		return x;
	}
	int i , j, check , t;
	int mindeclen;
	for(i = 0 ; i < num1.intlen ; i++) {
		check = compare(num1.num[i] , num2.num[i]);	// comparing in the integer part digit by digit
//	if any digit is greater than the other corresponding digit, then the corresponding number is greater. if same continues to the next digit of both the numbers
		if(check == 1) {
			x = ret_value(1,num1, num2);	// checks if the first number is greater
			return x;
		}
		if(check == -1) {			// checks if second number is greater
			x = ret_value(-1, num1, num2);
			return x;
		}
	}	
	// now checking for decimals as integral part of both numbers are same
	if(num1.declen < num2.declen) 
		mindeclen = num1.declen;
	else
		mindeclen = num2.declen;		// finding for minimum decimal length

	for(i = 0, j = num1.intlen + 1;i < mindeclen ; i++,j++) {
		check = compare(num1.num[j] , num2.num[j]);	// comparing decimal digits as done for integral digits
// 	same as above cases declaring number greater or smaller if they are unequal
		if(check == 1) {
			x = ret_value(1,num1, num2);
			return x;
		}
		if(check == -1) {
			x = ret_value(-1, num1, num2);
			return x;
		}
	}
	// all decimals and integers so far are same, so checking if anything extra non-zero present and thus declare 
	if(num1.declen == num2.declen)
		return 0;		// if all digits in integrals are also same then the two numbers become equal and hence 0 is returned

//	at this point the two numbers have same integral digits and also same number of minimum decimal digits.
//	now if the number with extra decimals has atleast one non zero value it will be greater. 
//	hence checking for non-zero digits
	if(num1.declen > num2.declen) {
//	above case if the first number has more number of decimals
		j = mindeclen + 1 + num1.intlen;
		for(i = 0 ; i < num1.declen - mindeclen ; i++) {
			t = compare(num1.num[j] , '0') ;
			if(t != 0) {
				x = ret_value(1, num1, num2);
				return x;	
			}
			j++;
		}
		return 0;
// 	if no nonzero value is got then again the two numbers will be equal as 0 carries null significance value
	}
	if(num2.declen > num1.declen) {
// 	similar above logic if the second number has extra decimals
		j = mindeclen + 1 + num1.intlen;
		for(i = 0 ; i < num2.declen - mindeclen; i++) {
			t = compare(num2.num[j] , '0') ;
			if(t != 0) {
				x = ret_value(-1, num1, num2);
				return x;	
			}
			j++;
		}
		return 0;
// 	if no nonzero value is got then again the two numbers will be equal as 0 carries null significance value
	}
}

// 	this function takes two characters as input, converts them to integers. then checks if they are greater, smaller, and returns value accordingly.
// this operation is required repeatedly in the loop and hence is written as a separate function
int compare(char a, char b) {
	if((a - '0') > (b - '0')) 
		return 1;
	else {
		if(a == b) 
			return 0;
		else
			return -1;
	}
}

//	the above function checks the magnitude of the numbers. however if the sign of the two numbers is negative then the greater magnitude becomes smaller and vice-versa.
//	hence this function checks the sign of the numbers and returns the correct return value as required.
int ret_value(int a, number num1, number num2) {
	if((num1.sign == 0) && (num2.sign == 0)) {
		return a;
	}
	else {
		if(a == 1)
			return -1;
		else
			return 1;
	}
}

// 	this function uses logic same as above, just that it checks only the magnitude of the two numbers. 
//	this function is used largely while going through the different cases in addition and subtraction codes.
int mag_compare(number num1, number num2) {
	int c = int_compare(num1.intlen , num2.intlen);
	if(c == 1)
		return 1;
	if(c == -1)
		return -1;
	int i , j, check , t;
	int mindeclen;
	for(i = 0 ; i < num1.intlen ; i++) {
		check = compare(num1.num[i] , num2.num[i]);
		if(check == 1) {
			return 1;
		}
		if(check == -1) {
			return -1;
		}
	}	
	// now checking for decimals as integral part of both numbers are same
	if(num1.declen < num2.declen) 
		mindeclen = num1.declen;
	else
		mindeclen = num2.declen;

	for(i = 0, j = num1.intlen + 1;i < mindeclen ; i++,j++) {
		check = compare(num1.num[j] , num2.num[j]);
		if(check == 1) {
			return 1;
		}
		if(check == -1) {
			return -1;
		}
	}
	// all decimals and integers so far are same, so checking if anything extra non-zero present and thus declare 
	if(num1.declen == num2.declen)
		return 0;
	if(num1.declen > num2.declen) {
		j = mindeclen + 1 + num1.intlen;
		for(i = 0 ; i < num1.declen - mindeclen ; i++) {
			t = compare(num1.num[j] , '0') ;
			if(t != 0) 
				return 1;
			j++;
		}
		return 0;
	}
	if(num2.declen > num1.declen) {
		j = mindeclen + 1 + num1.intlen;
		for(i = 0 ; i < num2.declen - mindeclen; i++) {
			t = compare(num2.num[j] , '0') ;
			if(t != 0)
				return -1;
			j++;
		}
		return 0;
	}
}

