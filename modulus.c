#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"number.h"
#include"functions.h"

number modulus(number num1, number num2) {
	number result, ans, temp;
	init(&temp);
	init(&result);
	init(&ans);

	ans = division(num1, num2);
	temp = multiplication(ans, num2);
	result = subtract(num1, temp);
	return ans;
}
