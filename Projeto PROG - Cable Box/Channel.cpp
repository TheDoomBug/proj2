#include <fstream>
#include <string>
#include <vector>

#include "Channel.h"
#include "Program.h"
#include "Date.h"

Channel::Channel(string channelName){
	name = channelName;
	programs = set_list_programs();
}

string Channel::getName() const {
	return name;
}

vector<Program> Channel::getPrograms() const {
	return programs;
}

vector<Program> Channel::set_list_programs() const{
	ifstream ficheiro;
	string nome = "ChannelsList.txt";
	string name;
	string duration;
	string weekDay;
	string hour;
	string minutes;
	vector<Program> vec;

	ficheiro.open(nome.c_str());

	while (getline(ficheiro, name) != "EOC")
	{
		getline(ficheiro, duration);
		getline(ficheiro, weekDay);
		getline(ficheiro, hour);
		getline(ficheiro, minutes);


		Program	program(name, string_to_int(duration), weekDay, string_to_int(hour), string_to_int(minutes));

		vec.push_back(program);
	}

	getline(ficheiro, name); //Retirar o EOC que marca o fim do canal
	ficheiro.close();

	return vec;
}

unsigned int string_to_int(string str)
{
	unsigned int n = 0;
	int s;
	for (unsigned int i = 0; i < str.size(); i++)
	{
		s = str[i] - 48;
		n = n + s*pow(10, i);
	}
	return n;
}


bool Channel::programOverlap(Program anterior, Program actual, Program seguinte) const {
	if (compareDates(anterior.getExhibitionDate().addMinutes(anterior.getExhibitionDate, anterior.getDuration), actual.getExhibitionDate()) == 1)
		return true;
	else if (compareDates(actual.getExhibitionDate().addMinutes(actual.getExhibitionDate, actual.getDuration), seguinte.getExhibitionDate()) == 1)
		return true;
	else return false;
}