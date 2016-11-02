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

#ifndef __NUMBER_H
#define __NUMBER_H

//	defining the data structure of how a number of infinite digits is stored in the entire software.
//	the digits of the number (the way a number is represented on paper) is stored in a character array.
//	the character pointer in this data structure points to this character array.
//	the intlen and declen represent the number of digits before and after the decimal point respectively.
//	the sign is one which tells whether the number is positive or negative.
//	sign = 0 for positive
//	sign = 1 for positive

typedef struct number {
	char *num;
	int intlen;
	int declen;
	int sign;
}number;
#endif

