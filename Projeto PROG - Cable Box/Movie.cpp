#include "Movie.h"
#include "Program.h"
#include <string>
#include <vector>
#include <fstream>

using namespace std;

Movie::Movie(string movieTitle, float movieCost) {
	
	title = movieTitle;
	cost = movieCost;
	timesRented = 0;
}

string Movie::getTitle() const{
	return title;
}

float Movie::getCost() const{
	return cost;
}

void Movie::setTimesRented(unsigned int t) {
	timesRented = t;
}




