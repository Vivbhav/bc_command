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

// function to check if the input is valid for given base
int base_legal(number a, int b) { 			
	if((b <= 0) || (b > 36)) 
		return 0;				// can satisfy only till base 16. so returns in case the value is not in range
	int len = a.intlen + a.declen + 1;
	int i, n , j;
	char c;
	int flag = 0;
	if( (b >= 1) && (b <= 10) ) {			// for decimal digits only
		int stop = 46 + b + 1;			// deciding till which digits are valid for the given input base
		for( i = 0 ; i < len ; i++) {
			c = a.num[i];
			n = c;
			flag = 0;
			for(j = 46; j <= stop ; j++) { 	// checking if input value is one of those valid characters
				if(n == 47)
					continue;
				if(n == j) {
					flag = 1;
					break;		// breaking if the digit is valid
				}
			}
			if(flag == 0)			// incase the digit is not valid returs 0 signifying invalid
				return 0; 
		}
		return 1;				// valid if all characters remain valid
	}
	int stop = 54 + b;				// deciding stop value for bases above 10
	for( i = 0 ; i < len ; i++) {
		c = a.num[i];
		n = c;
		flag = 0;
		for(j = 46; j <= 57; j++) {		// checking if the character is decimal
			if(n == 47)
				continue;
			if(n == j) {			// flag made to 1 for valid signifying the character is valid
				flag = 1;
				break;
			}
		}
		for(j = 65 ; j <= stop ;j++) {		// also checking if the character belongs to a valid character to that particular base
			if(n == j) {
				flag = 1;
				break;
			}
		}
		if(flag == 0)				// returns 0 in case any character is not valid.
			return 0; 
	}
	return 1;
}

// following function converting from decimal to given other base
number convert_decimal_tobase(number a, int b) {
	int mod;
	int n = atoi(a.num);
//	printf("The received number is %d.\n",n);
	char str[20];
	char *str1;
	int j = 0;
//	for(i = 0 ;i < a.intlen ; i++, j--) {
	while( n > 0 ) {
		mod = n % b;			// calculating the modulus which gives the number in that corresponding base
		n = n / b;			// dividing the number for further calculations
		str[j] = mod + '0';		// converting to character and writing to the string
		j++;
	}
	int i;
	
//	str1 = strrev(str);			
	for(i = j - 1 ; i >= 0 ;i--) 	
		printf("%c",str[i]);
	printf("\n");
	//printf("The output string is %s.\n",str);
/*	int len = strlen(str);
	len = 20 - len;
	if(len > 0) {
		
	}*/
/*inumber res;
	res = create_number(str);*/
}

number convert_base_todecimal(number a, int b) {
	int len = a.intlen;
	number result;
	init(&result);
	number temp;
	init(&temp);
	int d, i;
	char c;
	for(i = 0 ; i < len ; i++) {
		c = a.num[i];	
		d = c + '0';
	/*	temp = multiplication(b, power(d , (len - 1)));
		result = addition(result, temp);*/
	}
	
}
