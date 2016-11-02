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
#include"list.h"

number multiplication(number num1, number num2) {
	number output;
	list n1 = createlist(num1);
	list n2 = createlist(num2);
	int len1 = n1.len;
	int len2 = n2.len;
	int i, j;
	node *p = n1.tail;
	node *q = n2.tail;
	int* arr = (int*) malloc(sizeof(int) * (len1 + len2)) ;
	int carry = 0;
	for(i = 0 ; i < (len1 + len2) ; i++) {
		arr[i] = 0;
	}
	for(i = 0 ; i < len2 ; i++) {
		p = n1.tail;
		for(j = 0 ; j < len1 ; j++) {
			arr[i+j] += p->num * q->num;
			p  = p->prev;
			arr[i+j] += carry;
			if(arr[i+j] >= 10000) {		
				carry = arr[i+j] / 10000;
				arr[i+j] %= 10000;
			}
			else
				carry = 0;
		}
		if(carry != 0) 
			arr[i+j] = carry;
		carry = 0;
		q = q->prev;
	}
	char *res = (char*) malloc(sizeof(char) * 4 * (len1 + len2) + 2);
	res[(len1+len2) * 4 + 1] = '\0';
	for(i = len1+ len2 - 1; i >= 0 ; i--) {
		j = len1 + len2 - i -1;
		create_string(res, arr[i], j);
	}	
	int extra1, extra2;
	if((num1.intlen + num1.declen) % 4 == 0)
		extra1 = 0;
	else
		extra1 = 4 - ((num1.intlen + num1.declen) % 4) ;

	if((num2.intlen + num2.declen) % 4 == 0)
		extra2 = 0;
	else
		extra2 = 4 - ((num2.intlen + num2.declen) % 4) ;

	int totaldec = extra1 + extra2 + num1.declen + num2.declen;
	j = (len1 + len2) * 4 - totaldec;
	for(i = (len1 + len2) * 4;i > j; i--)  
		 res[i] = res[i-1];
	res[i] = '.';
	output = create_number(res);
	if(((num1.sign == 0) && (num2.sign == 1)) ||  ((num1.sign == 1) && (num2.sign == 0))) 
		output.sign = 1;
	return output;
}

void create_string(char *res, int k, int j) {
	char ch[4];
	int i, t;
	int p;
	if(k == 0) {
		for(i = 0 ; i < 4;i++) 
			ch[i] = '0';	
		goto somewhere;
	}
	if(k >= 1000) {
		for( i = 3 ; i >= 0 ;i--) {
			t = k % 10;
			ch[i] = t + '0';
			k /= 10; 			
		}
		goto somewhere;
	}
	if(k>=100) {
		ch[0] = '0';
		for( i = 3 ; i >= 1 ;i--) {
			t = k % 10;
			ch[i] = t + '0';
			k /= 10; 			
		}
		goto somewhere;
	}
	if(k>=10) {
		ch[0] = '0';
		ch[1] = '0';
		for( i = 3 ; i >= 2 ;i--) {
			t = k % 10;
			ch[i] = t + '0';
			k /= 10; 			
		}
		goto somewhere;
	}
	ch[0] = '0';
	ch[1] = '0';
	ch[2] = '0';
	t = k % 10;
	ch[3] = t + '0';
	somewhere :
		p = 4 * j;
		for(i = 0 ; i < 4; i++,p++) {
			res[p] = ch[i];
		}
}

list createlist(number num1) {
	int length1 = num1.intlen + num1.declen;
	int i, n, temp;
	list n1;
	linit(&n1);
	int len = length1, count = 0, extra = 0; 
	char ch[4];
	char c;
	while(len >= 4) {
		for(i = 0 ; i < 4 ; i++) {
			c = num1.num[count];
			if(c == '.') {
				count++;
				i--;
				continue;
			}
			ch[i] = c;			
			count++;
		}
		n = atoi(ch);
		append(&n1, n);
		len = len - 4;
	}
	extra = len % 4;
	
	if(extra == 0)
		goto move;

	c = num1.num[count];
	if(c == '.') {
		count++;
		c = num1.num[count];
	}
	temp = c - '0' ;
	n =  temp * 1000;
	if(extra == 1)
		goto loop;

	count++;
	c = num1.num[count];
	if(c == '.') {
		count++;
		c = num1.num[count];
	}
	temp = c - '0';
	n = n + temp * 100;
	if(extra == 2) 
		goto loop;	
			
	count++;
	c = num1.num[count];
	if(c == '.') {
		count++;
		c = num1.num[count];
	}
	temp = c - '0';
	n  = n +  temp * 10;
	
	loop :
		append(&n1, n);
	move :
	return n1;
}
	

