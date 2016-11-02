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

//	this function computes exponent. takes two numbers as input. first base and the other index.
//	output is base ^ index
number power(number num1, number num2) {
	number power;
//	the exponent can at maximum be INT_MAX. hence simple check to guarantee that the index is within range
	if(num2.intlen >= 10) {
		perror("Runtime error (func=(main), adr = 20): exponent too large in raise");
		exit(0);
	}
	int n = atoi(num2.num);
	int i;	
	number result;
	init(&result);
	result = convert_int_tonum(1);
	for(i = 0 ; i < n ; i++) {
		result = multiplication(result, num1);
	}
	return result;				
}


