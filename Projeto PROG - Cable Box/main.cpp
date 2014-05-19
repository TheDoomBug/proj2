#include <iostream>
#include <cstdlib>
#include <stdlib.h>
#include <time.h>
#include <fstream>
#include <vector>
#include <conio.h>

#include "Channel.h"
#include "Date.h"
#include "Box.h"

using namespace std;


// Randomly generates a valid day, hour and minute
Date currentDate(){
	int day;
	int hour;
	int minutes;

	day = rand() % 7 + 1;
	hour = rand() % 24;
	minutes = rand() % 60;

	Date date("Domingo", hour, minutes);

	if (day == 1)
		Date date("Segunda", hour, minutes);
	else if (day == 2)
		Date date("Terca", hour, minutes);
	else if (day == 3)
		Date date("Quarta", hour, minutes);
	else if (day == 4)
		Date date("Quinta", hour, minutes);
	else if (day == 5)
		Date date("Sexta", hour, minutes);
	else if (day == 6)
		Date date("Sabado", hour, minutes);

	return date;
}

int main(){
	srand(time(NULL));

	ifstream gen;




	gen.open("general.txt");

	string pass;
	getline(gen, pass);

	static Box box = Box(pass, currentDate());

	box.Box::menu1();

	exit(0);
}
