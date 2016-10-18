#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"number.h"
#include"functions.h"

int less(number num1, number num2) {
	if(num1.len < num2.len)
		return 1;
	if(num1.len > num2.len)
		return 0;
	if(strlen(num1.tail->ch) < strlen(num2.tail->ch))
		return 1;
	if(strlen(num1.tail->ch) > strlen(num2.tail->ch))
		return 0;
	node *p, *q;
	p = num1.head;
	q = num2.head;
	while( (p != NULL) || (q != NULL)) {
		if( (p == NULL) && (q != NULL) )
			return 1;
		if( (p != NULL) && (q == NULL) )
			return 0;
		int n1, n2;
		n1 = atoi(p->ch);
		n2 = atoi(q->ch);
		if(n1 < n2) {
			printf("I returned from loop.\n");
			return 1;
		}
		if(n1 > n2) 
			return 0;
		p = p->next;
		q = q->next;
	}
	return 0;
}

int greater(number num1, number num2) {
	if(num1.len > num2.len)
		return 1;
	if(num1.len < num2.len)
		return 0;
	if(strlen(num1.tail->ch) > strlen(num2.tail->ch))
		return 1;
	if(strlen(num1.tail->ch) < strlen(num2.tail->ch))
		return 0;
	node *p, *q;
	p = num1.head;
	q = num2.head;
	while( (p != NULL) || (q != NULL)) {
		if( (p == NULL) && (q != NULL) )
			return 0;
		if( (p != NULL) && (q == NULL) )
			return 1;
		int n1, n2;
		n1 = atoi(p->ch);
		n2 = atoi(q->ch);
		if(n1 > n2) {
			return 1;
		}
		if(n1 < n2) 
			return 0;
		p = p->next;
		q = q->next;
	}
	return 0;
}

int equal(number num1, number num2) {
	node *p, *q;
	if(num1.len > num2.len){
		printf("I ret 1\n");
		return 0;
	}
	if(num1.len < num2.len) {
		printf("I ret 3\n");
		return 0;
	}
	if(strlen(num1.tail->ch) > strlen(num2.tail->ch)) {
		printf("I ret 2\n");
		return 0;
	}
	if(strlen(num1.tail->ch) < strlen(num2.tail->ch))
		return 0;
	p = num1.head;
	q = num2.head;
	while( (p != NULL) || (q != NULL)) {
		printf("I am in loop.\n");
		if( (p == NULL) && (q != NULL) )
			return 0;
		if( (p != NULL) && (q == NULL) )
			return 0;
		int n1, n2;
		n1 = atoi(p->ch);
		n2 = atoi(q->ch);
		if(n1 > n2) {
			return 0;
		}
		if(n1 < n2) 
			return 0;
		p = p->next;
		q = q->next;
	}
	return 1;
}
