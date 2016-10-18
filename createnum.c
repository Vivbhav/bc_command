#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"number.h"
#include"functions.h"
//#include"init.h"

void print_number(number* l) {
	node *p;
	p = l->head;
	while( p != NULL) {
		printf("%s",(p->ch));
		p = p->next;
	}
}

void insert(number *l, char* c) {
	node *p;
	p = (node*) malloc(sizeof(node));
	p->ch = (char *)malloc(strlen(c) + 1);
	strcpy(p->ch, c);
	p->prev = NULL;
	p->next = l->head;
	if(l->head) 
		l->head->prev = p;
	l->head = p;
	l->len++;
	if(l->tail == NULL)
		l->tail= p;
}

number create_number(char* str) {
	number a;
	init(&a);
	int i;
	int len , count , k = 0 , l , j;
	len = strlen(str);
	count = len / 8;
	if(len % 8 != 0) 
		count++;
	l = len - 1;
	char *c;
	c = (char*) malloc(sizeof(char) * 8 ) ;
	while(count != 1) {
		for(i = 7 ; i >= 0; i--) {
			c[i] = str[l];
			l--;
		}
		insert(&a, c);
		count--;
	}
	k = 0;
	c = (char*) malloc(sizeof(char) * l ) ;
	for(i = 0 ; i < l + 1; i++,k++) {
		c[i] = str[k];
	}
	insert(&a, c);
	return a;
}
