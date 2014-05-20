#include <fstream>
#include <string>
#include <vector>

#include "Channel.h"
#include "Program.h"
#include "Date.h"

vector <Program> vecprog(string name);

unsigned int string_to_int(string s);


Channel::Channel(string name)

{

	ifstream canal;


	this->name = name;


	string nome = name;


	programs = vecprog(nome);

}

bool Channel::programOverlap(Program program1, Program program2) const
{

	// Testa se o programa 1 sobrepoe o programa 2

	Date program1beg(program1.getExhibitionDate); //Data de inicio do programa 1
	Date program2beg(program2.getExhibitionDate); //Data de inicio do programa 2
	Date program1end(Date::addMinutes(program1.getExhibitionDate, program1.getDuration)); //Data de fim do programa 1
	Date program2end(Date::addMinutes(program2.getExhibitionDate, program2.getDuration)); //Data de fim do programa 2

	if ((compareDates(program1beg, program1beg) == -1 && compareDates(program1end, program1beg) == 1) || compareDates(program1beg, program2beg) == 0)
		//Se o programa 1 comecar antes do programa 2, e acabar depois, há overlap.
		//Se o programa 1 comecar antes do programa 2 e acabar antes, nao ha overlap
		//Se comecarem ao mesmo tempo, ha overlap
		//Se o programa 1 comecar depois do 2, nao ha overlap
		return true;

	else return false;
}


vector <Program> vecprog(string name)

{

	name += ".txt";


	ifstream cria;

	vector <Program> prog;

	string nome;

	string tipo;

	string sdur;

	string shora;

	string smin;

	unsigned int dur;

	string dia;

	unsigned int hora;

	unsigned int min;


	cria.open(name);



	while (!cria.eof())

	{

		for (int i = 6; i > 0; i--)

		{

			getline(cria, nome);

			getline(cria, tipo);

			getline(cria, dia);

			getline(cria, shora);

			getline(cria, smin);

			getline(cria, sdur);


			dur = string_to_int(sdur);

			min = string_to_int(smin);

			hora = string_to_int(shora);


			Program pro = Program(nome, tipo, dur, dia, hora, min);

			prog.push_back(pro);

		}

	}



	return prog;

}


void Channel::set_name(string newname) {
	name = newname;
}

vector<Program> Channel::getPrograms() const
{

	return programs;

}



string Channel::getName() const
{

	return name;

}



void Channel::addProg(Program Prog)
{

	programs.push_back(Prog);

}


