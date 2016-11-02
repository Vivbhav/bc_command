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
#include"list.h"

//	this file contains only those functions of list which are required in the software.
//	also all required list functions are in this file itself
//	the type of list used is doubly linked null terminated list.

// 	initializes the list to null.
void linit(list *l) {
	l->head = l->tail = NULL;
	l->len = 0;
}

//	when an integer is passed it is added to the tail of the list and hence this function is append.
void append(list *l, int num) {
	node *p , *q;
	q = (node*) malloc(sizeof(node)) ;	// creating a node to store the new number.
	q->num = num;
	p = l->tail;
	if(!p) {			//	special case when the list is initially empty
		l->head = l->tail = q;
		q->prev = q->next = NULL;
		l->len++;
		return;	
	}
	p->next = q;	//			adjusting pointers so that the new node points to null and also to the  previously last node
	q->next = NULL;
	q->prev = p;
	l->tail = q;	//			adjusting the tail and the length of the list
	l->len++;
	return;
}

//	traversing the list and printing each node as we go through it 
void traverse(list l) {
	node *p = l.head;		
	if(!p) {	//			special case when the list is empty.
		printf("List is empty.\n");
		return;
	}
	do {
		printf("%d\n",p->num);
		p = p->next;
	}while(p != NULL);		//	printing till the list is empty
	return;
}

//	return the length of the list i.e. the number of nodes in the list
int length(list l) {
	return l.len;
}

