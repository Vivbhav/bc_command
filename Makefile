#  This file is part of Infinite Calculator. 
#
#   Infinite Calculator is free software: you can redistribute it and/or modify
#   it under the terms of the GNU General Public License as published by
#   the Free Software Foundation, either version 3 of the License, or
#   (at your option) any later version.
#
#   Infinite Calculator is distributed in the hope that it will be useful,
#   but WITHOUT ANY WARRANTY; without even the implied warranty of
#   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
#   GNU General Public License for more details.
#
#   This software has been developed and mantained by Vivek Bhave. The only release of this software is in 2016. 
#

project : addition.o modulus.o createnum.o main.o comparison.o multiplication.o list.o general.o subtract.o base.o logical_operators.o division.o power.o
	gcc addition.o createnum.o comparison.o list.o main.o multiplication.o general.o base.o subtract.o logical_operators.c division.o power.o modulus.o -o project

modulus.o : modulus.c number.h functions.h division.c addition.c subtract.c
	gcc -c modulus.c

power.o : power.c functions.h number.h multiplication.c
	gcc -c power.c

division.o : division.c functions.h number.h
	gcc -c division.c

addition.o : addition.c functions.h general.c number.h
	gcc -c addition.c

createnum.o : createnum.c functions.h number.h
	gcc -c createnum.c

comparison.o : comparison.c functions.h number.h
	gcc -c comparison.c

multiplication.o : multiplication.c list.c list.h  functions.h number.h
	gcc -c multiplication.c list.c

subtract.o : subtract.c number.h functions.h
	gcc -c subtract.c

base.o : base.c number.h functions.h
	gcc -c base.c

general.o : general.c 
	gcc -c general.c

logical_operators.o : logical_operators.c number.h functions.h
	gcc -c logical_operators.c 

main.o : main.c createnum.c addition.c comparison.c multiplication.c  list.c functions.h number.h list.h general.c base.c
	gcc -c main.c

clean :
	rm modulus.o addition.o createnum.o comparison.o main.o list.o multiplication.o general.o base.o subtract.o logical_operators.o division.o project power.o 
