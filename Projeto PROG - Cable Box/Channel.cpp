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


