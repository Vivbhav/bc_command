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

int main(int argc, char* argv[]) {
	int base = 10;
	if(argc > 2) {
		perror("Bad arguements.\n");
		exit(0);
	}
	if(argv[1]) {
		FILE *fp;
		char st[] = "-h";
		if(!strcmp(argv[1], st)) {
			fp = fopen("helpfile","r");
			char ch;
			while((ch = getc(fp)) != EOF) 
				printf("%c",ch);
			fclose(fp);
			exit(0);
		}
		else if(strcmp(argv[1], "-b") == 0) {
			printf("Enter the obase you choose\n");
			scanf("%d",&base);	
		}
		else if(strcmp(argv[1], "--ds") == 0) {
			printf("typedef struct number {\n	char *num;\n	int intlen;\n	int declen;\n	int sign;\n} number;\n");
			exit(0);
		}
		else {
			printf("Give command line arguement as -h for help. If you want to run the program directly, run the code without any command line arguements.\n");
			exit(0);
		}
	}
	char *str, *str1;
	char *op;
	int d;
	op = (char*) malloc(sizeof(char) * 10);
	str = (char*) malloc(sizeof(char) * 500);
	str1 = (char*) malloc(sizeof(char) * 500);
	while(	scanf("%s%s%s",str,op, str1) != -1 ) {
		number a = create_number(str);
		number b = create_number(str1);
		number result, result1;
		init(&result);
		init(&result1);

		if(!strcmp(op, "+")) {
			result = addition(a , b);
			printf("%s + %s = ",str, str1);
			if(strcmp(argv[1], "-b") == 0) 
				convert_decimal_tobase(result, base);
			else
				print_number(result);
			printf("\n");
			continue;
		}
		if(!strcmp(op, "-")) {
			result = subtract(a , b);
			printf("%s - %s = ", str, str1);
			if(strcmp(argv[1], "-b") == 0) 
				convert_decimal_tobase(result, base);
			else
				print_number(result);
			printf("\n");
			continue;
		}
		if(!strcmp(op, "*")) {
			result = multiplication(a , b);
			printf("%s * %s = ",str, str1);
			if(strcmp(argv[1], "-b") == 0) 
				convert_decimal_tobase(result, base);
			else
				print_number(result);
			printf("\n");
			continue;
		}
		if(!strcmp(op, "/")) {
			result = division(a , b);
			printf("%s / %s = ", str, str1);
			if(strcmp(argv[1], "-b") == 0) 
				convert_decimal_tobase(result, base);
			else
				print_number(result);
			printf("\n");
			continue;
		}
		if(!strcmp(op, "^")) {
			result = power(a,b);
			printf("%s ^ %s = ",str, str1);
			if(strcmp(argv[1], "-b") == 0) 
				convert_decimal_tobase(result, base);
			else
				print_number(result);
			printf("\n");
			continue;
		}
		if(!strcmp(op, "%")) {
			result = modulus(a , b);
			printf("%s mod %s = ", str, str1);
			if(strcmp(argv[1], "-b") == 0) 
				convert_decimal_tobase(result, base);
			else
				print_number(result);
			printf("\n");
			continue;
		}
		if(!strcmp(op, ">")) {
			d = number_compare(a, b);
			if(d > 0) 
				printf("1\n\n");
			else
				printf("0\n\n");
			continue;
		}		
		if(!strcmp(op, "<")) {
			d = number_compare(a, b);
			if(d < 0) 
				printf("1\n\n");
			else
				printf("0\n\n");
			continue;
		}		
		if(!strcmp(op, "==")) {
			d = number_compare(a, b);
			if(d == 0) 
				printf("1\n\n");
			else
				printf("0\n\n");
			continue;
		}
		if(!strcmp(op, ">=")) {
			d = number_compare(a, b);
			if(d >= 0) 
				printf("1\n\n");
			else
				printf("0\n\n");
			continue;
		}
		if(!strcmp(op, "<=")) {
			d = number_compare(a, b);
			if(d <= 0) 
				printf("1\n\n");
			else
				printf("0\n\n");
			continue;
		}
		if(!strcmp(op, "=")) {
			d = number_compare(a, b);
			if(d == 0) 
				printf("1\n\n");
			else
				printf("0\n\n");
			continue;
		}
		if(!strcmp(op,"length")) {
			d = a.intlen + a.declen;		
			printf("The length of %s is %d.\n",str, d);
			d = b.intlen + b.declen;
			printf("The length of %s is %d.\n\n",str1, d); 
			continue;
		}
		if(!strcmp(op,"scale")) {
			d = a.declen;		
			printf("The scale of %s is %d.\n",str, d);
			d = b.declen;
			printf("The scale of %s is %d.\n\n",str1, d); 
			continue;
		}
		if(!strcmp(op,"&&")) {
			d = logical_and(a, b);
			printf("%d\n\n",d);
			continue;
		}
		if(!strcmp(op,"||")) {
			d = logical_or(a, b);
			printf("%d\n\n",d);
			continue;
		}
	}
}
