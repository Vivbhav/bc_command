#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"number.h"
#include"functions.h"

int main(int argc, char *argv[]) {
	int res, flag = 0 ;
	if(argc > 2) {
		perror("Bad arguments.");
		exit(1);
	}
	if(argv[1]) {
		FILE *fp;
		char st[] = "-h" ;
		if(!strcmp(argv[1],st)) {
			flag = 1;
			fp = fopen("help","r");
			char ch;
			while((ch = getc(fp)) != EOF) {
				printf("%c",ch);
			}
			fclose(fp);
			exit(1);
		}
		if(flag == 0) {
			printf("Give command line arguement as -h for help. For the calculator run code without any command line arguements.\n");
			exit(1);
		}
	}

	char *str, *str1, op; 
	str = (char*) malloc(sizeof(char) * 100);
	str1 = (char*) malloc(sizeof(char) * 100);
	scanf("%s%s",str,str1);
	getchar();
	scanf("%c",&op);
	printf("First number entered.\n");
	printf("%s\t %c\t %s",str,op,str1);
	number a , b;
	a = create_number(str);
	b = create_number(str1);
	if(op == '>') {
		res = greater(a, b);
		printf("%d\n",res);
	}
			
	if(op == '<') {
		res = greater(a, b);
		printf("%d\n",res);
	}
	if(op == '=') {
		res = greater(a, b);
		printf("%d\n",res);
	}

	if(op == '+') {
		number i = Add(a , b);
		print_number(&i);
		printf("\n");
	}
}
