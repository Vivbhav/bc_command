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

#ifndef __LIST_H
#define __LIST_H

//	type of the individual blocks of the list which is created
typedef struct node {
	int num;
	struct node *next, *prev;
}node;

//	creating the structure of the list which is a doubly linked null terminated list.
typedef struct list {
	node *head, *tail;
	int len;
}list;

//	prototypes of all list functions 
void linit(list *l);
void append(list *l, int num);
void traverse(list l);
int length(list l);
#endif
