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
#include<string.h>
#include<stdlib.h>
#include"number.h"
#include"functions.h"

// 	logical and function
// 	it will return a 1 if both numbers are non-zero. even if one number is zero it will return a 0.
//	by non-zero number it means that it has atleast one digit in integer or decimal which is non-zero thus proving that it has some face value
int logical_and(number a, number b) {
	int i;
	int numa = 0 , numb = 0;
	int len = a.intlen + a.declen ;
	if(a.declen == 0)
		len--;
	for(i = 0 ;i < len + 1; i++) {			
//	 checking over the full length if there is a character which is neither a decimal point nor a zero.
		if((a.num[i] != '0') && (a.num[i] != '.')) {
			numa = 1;				// setting the flag appropriately
		}
	}

//	doing similar calculations for the second number and setting the appropriate flag
	len = b.intlen + b.declen;
	if(b.declen == 0) 
		len--;
	for(i = 0 ;i < len + 1; i++) {
		if((b.num[i] != '0') && (b.num[i] != '.'))
			numb = 1;
	}

//	checking if both flags and returning 1 else returns 0
	if((numa == 1) && (numb == 1))
		return 1;
	return 0;
}

// 	logical or function
// 	it will return a 1 if any of the two numbers are non-zero. only if both numbers are zero it will return a 0.
int logical_or(number a, number b) {
	int i;
	int numa = 0 , numb = 0;
	int len = a.intlen + a.declen ;

//	finding out the non-zeroness of the first number
	if(a.declen == 0)
		len--;
	for(i = 0 ;i < len + 1; i++) {
		if((a.num[i] != '0') && (a.num[i] != '.'))
			numa = 1;
	}

//	now the non-zeroness of the second number
	len = b.intlen + b.declen;
	if(b.declen == 0) 
		len--;
	for(i = 0 ;i < len + 1; i++) {
		if((b.num[i] != '0') && (b.num[i] != '.'))
			numb = 1;
	}

//	returns 1 if either is 1 else 0
	if((numa == 1) || (numb == 1))
		return 1;
	return 0;
}
