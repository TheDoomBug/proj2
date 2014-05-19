#include "Program.h"
#include <vector>
#include <fstream>
#include <string>

Program::Program(string programName, string tipo, unsigned int programDuration, string day, unsigned int hour, unsigned int minutes):exhibitionDate(day, hour, minutes){
	name = programName;
	duration = programDuration;
	type = tipo;
	recorded = false;
}

void Program::setRecorded() {
	recorded = true;
}

string Program::getName() const{
	return name;
}
string Program::getType() const{
	return type;
}

int Program::getDuration() const{
	return duration;
}

Date Program::getExhibitionDate() const{
	return exhibitionDate;
}

void Program::setName(string newname) {
	name = newname;
}
void Program::setType(string newtype) {
	type = newtype;
}
void Program::setDuration(int newduration) {
	duration = newduration;
}
void Program::setExhibitionDate(Date newExhibitionDate) {

}
	