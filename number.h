#ifndef __NUMBER_H
#define __NUMBER_H

typedef struct node {
	char *ch;
	struct node *prev , *next;
}node;

typedef struct number {
	int len;
	node *head , *tail;
}number;
#endif
