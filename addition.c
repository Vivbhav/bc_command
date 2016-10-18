#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"number.h"
#include"functions.h"
#include"init.h"

number Add(number num1 , number num2) {
	number sum;
	init(&sum);
	int n1, n2, s , i = 0;
	static int carry = 0;
	char carr[10];
	node *p, *q, *r, *t;
	t = NULL;
	p = num1.tail;
	q = num2.tail;
	while( (p != NULL) || (q != NULL) ) {
		if(p == NULL) 
			n1 = 0;
		else {
			n1 = atoi(p->ch);
		}
		if(q == NULL) 
			n2 = 0;
		else {
			n2 = atoi(q->ch);
		}
		s = n1 + n2 + carry;
		carry = s / 100000000 ; // 10 to the power 8 

		if(carry != 0)
			s = s - 100000000 ; // 10 to the power 8
		r = (node*) malloc(sizeof(node));
		sprintf(carr , "%d" , s);
		r->ch = (char*) malloc(strlen(carr) + 1) ;
		strcpy(r->ch , carr);
		r->next = t;
		if( t != NULL)
			t->prev = r;
		t = r;
		if(p != NULL)
			p = p->prev;
		if(q != NULL)
			q = q->prev;
		sum.len++;
	}
	sum.head = t;
	return sum;
}
