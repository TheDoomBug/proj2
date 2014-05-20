#include <fstream>
#include <string>
#include <vector>
#include <iostream>
#include <conio.h>
#include <sstream>
#include <cstdlib>
#include <stdlib.h>
#include <time.h>

#include "Box.h"
#include "Movie.h"
#include "Channel.h"
#include "Date.h"

vector <Channel> vecchan(int n);
vector <Movie> vecmov(int n);
vector <Movie> vecseen(int n);
vector <Program> vecrec(int n);
string int_to_string(int n);
void printbox(string titul);
void rdc(string cenas);
void rdc2(string cenas, int x);
unsigned int string_to_int(string str);
void showDays();
void show_inf_Prog(Program prog);

Box::Box(string passwd, Date date) :currentDate(date){
	password = passwd;

	ifstream gen;
	gen.open("general.txt");
	vector <int> numbers;

	int x;

	gen.ignore(LONG_MAX, '\n');

	for (int i = 4; i > 0; i--)
	{
		gen >> x;
		numbers.push_back(x);
	}

	channels = vecchan(numbers.at(0));
	movieClub = vecmov(numbers.at(1));
	seenMovies = vecseen(numbers.at(2));
	recordList = vecrec(numbers.at(3));

}

vector<Program> Box::listByDay(string day) const {

	vector<Program> vec;

	for (unsigned i = 0; i < channels.size(); i++)
	for (unsigned j = 0; j < channels[i].getPrograms().size(); j++)
	if (channels[i].getPrograms()[j].getExhibitionDate().getDay() == day)
		vec.push_back(channels[i].getPrograms()[j]);

	return vec;
}
vector<Program> Box::listByChannel(string channel, string day) const {

	vector<Program> vec;

	for (unsigned i = 0; i < channels.size(); i++)
	if (channels[i].getName() == channel)
	{
		for (unsigned j = 0; i < channels[i].getPrograms().size(); i++)
		if (day == "NULL" || channels[i].getPrograms()[j].getExhibitionDate().getDay() == day)
			vec.push_back(channels[i].getPrograms()[j]);
	}
	return vec;
}

vector<Program> Box::listByType(string type, string day) const {
	vector<Program> vec;

	for (unsigned i = 0; i < channels.size(); i++)
	for (unsigned j = 0; j < channels[i].getPrograms().size(); j++)
	if (channels[i].getPrograms()[j].getType() == type)
	if (day == "NULL" || channels[i].getPrograms()[j].getExhibitionDate().getDay() == day)
		vec.push_back(channels[i].getPrograms()[j]);

	return vec;
}

vector <Channel> vecchan(int n)
{
	ifstream cria;
	vector <Channel> canal;
	string nome;

	cria.open("channels.txt");
	if (cria.fail())
		cout << "FAIL";

	for (; n > 0; n--)
	{
		getline(cria, nome);
		Channel can(nome);
		canal.push_back(can);
	}

	return canal;
}

vector <Movie> vecmov(int n)
{
	ifstream cria;
	vector <Movie> filmes;
	float x;
	string nome;

	cria.open("moviesclub.txt");

	for (n; n > 0; n--)
	{
		cria >> x;
		getline(cria, nome);
		Movie filme = Movie(nome, x);
		filmes.push_back(filme);
	}

	return filmes;
}

vector <Movie> vecseen(int n)
{
	ifstream cria;
	vector <Movie> filmes;
	float x;
	string nome;
	int seen;

	cria.open("moviesseen.txt");

	for (n; n > 0; n--)
	{
		cria >> x;
		cria.ignore();
		getline(cria, nome);
		cria >> seen;
		cria.ignore();
		Movie filme = Movie(nome, x, seen);
		filmes.push_back(filme);
	}

	return filmes;
}

vector <Program> vecrec(int n)
{
	ifstream cria;
	vector <Program> programa;
	string nome;
	string tipo;
	string sdia;
	string shoras;
	string smin;
	string sdura;

	cria.open("recProg");

	for (n; n > 0; n--)
	{
		getline(cria, nome);
		getline(cria, tipo);
		getline(cria, sdia);
		getline(cria, shoras);
		getline(cria, smin);
		getline(cria, sdura);
		Program prog = Program(nome, tipo, string_to_int(sdura), sdia, string_to_int(shoras), string_to_int(smin));
		programa.push_back(prog);
	}

	return programa;
}


bool Box::rentMovies(string title){
	
	
	for (int i = 0; i < movieClub.size(); i++)
	{
		if (movieClub[i].getTitle() == title)
		{
			insert_rented_movie(movieClub[i]);
			movieClub.erase(movieClub.begin() + i);
			return true;
		}
	}
	return false;
}

float Box::moneySpent() const
{
	float cost = 0;

	for (unsigned i = 0; i < seenMovies.size(); i++)
		cost = cost + seenMovies[i].getCost();

	return cost;
}

int Box::timesWatched(string title) const {

	for (unsigned i = 0; i < seenMovies.size();i++)
	if (seenMovies[i].getTitle() == title)
		return seenMovies[i].getTimesRented();

	return 0;
}

bool Box::changePassword() {

	string pw; //password a inserir pelo utilizador
	string newpw; //the new password, if the password provided by the user matches the box's password

	cout << "Please insert the current password: ";
	cin >> pw;

	if (pw == password)
	{
		cout << endl << "Please insert the new password: ";
		cin >> newpw;

		password == newpw;
		return true;
	}
	else
		cout << endl << "Wrong password";

	return false;
}

// Channel CRUD

bool Box::createdChanel() {

	string newchannel;

	cout << "Channel Name: " << endl;
	cin >> newchannel;

	Channel channel(newchannel);
	channels.push_back(channel);

	return true;
}

bool Box::removeChanel() {

	string removedChannel;

	cout << "Channel to remove: " << endl;
	cin >> removedChannel;

	for (unsigned i = 0; i < channels.size();i++)
	if (channels[i].getName() == removedChannel)
	{
		channels.erase(channels.begin() + i);
		return true;
	}
	return false;
}

//Por fazer
bool Box::updateChanel(){
	return false;
}


//Program CRUD

/*bool Box::createdProgram(string channel){

	string newprogram;
	unsigned duration;

	string type;
	string day;
	unsigned hour;
	unsigned minutes;

	cout << "Program Name: " << endl;
	cin >> newprogram;

	cout << "Program Type: " << endl;
	cin >> type;

	cout << "Program Duration: " << endl;
	cin >> duration;

	cout << "Start Time: " << endl;
	cout << "Day: " << endl;
	cin >> day;
	cout << "Hour: " << endl;
	cin >> hour;
	cout << "Minutes: " << endl;
	cin >> minutes;

	Program program(newprogram, type, duration, day, hour, minutes);
	Date date(day, hour, minutes);

	
	// Determinar o canal a colocar o programa, bem como a sua posicao na programacao

	for (unsigned i = 0; i < channels.size(); i++)
	{
		if (channels[i].getName() == channel) // Procura pelo canal certo para o programa
		{
			for (unsigned j = 0; i < channels[i].getPrograms().size(); i++) // Percorre todos os programas desse canal...
			{
				// Falta fazer condicao para primeiro e ultimo elemento do vetor
				if (channels[i].programOverlap(channels[i].getPrograms()[j - 1], channels[i].getPrograms()[j], channels[i].getPrograms()[j + 1]))
							{
								// Verifica se o programa se sobrepoe ao programa seguinte...
								cout << endl << "Ha sobreposicao de programas!";
							}
				else channels[i].getPrograms().insert(channels[i].getPrograms().begin() + j, program); // Nao ha problema nenhum, podemos inserir o programa!
						}
					}
	}

	return true;
}*/

bool Box::removeProgram() {

	string removedProgram;

	cout << "Program to remove: (space and lowercase/uppercase sensitive)" << endl;
	cin >> removedProgram;

	for (unsigned i = 0; i < channels[i].getPrograms().size(); i++)
	if (channels[i].getPrograms()[i].getName() == removedProgram)
	{
		channels[i].getPrograms().erase(channels[i].getPrograms().begin() + i);
		return true;
	}
	return false;
}

bool Box::updateProgram()
{

	string oldName;
	string channelName;
	string newName;
	unsigned choice;
	unsigned newduration;
	string newDay;
	unsigned int newHour;
	unsigned int newMinutes;

	cout << "O que pretende alterar? ";
	cout << endl << endl << "1- Nome";
	cout << endl << "2- Duracao";
	cout << endl << "3- Data";
	cout << endl << "0- Cancelar alteracao";
	cin >> choice;

	cout << endl << "Insira o nome do canal do programa que pretende fazer alteracoes (case-sensitive): ";
	cin >> channelName;

	cout << endl << "Insira o nome do programa que pretende fazer alteracoes (case-sensitive): ";
	cin >> oldName;

	if (cin.fail()) {
		cin.ignore();
		cin.clear();
		return false;
	}
	else if (choice == 0)
		return true;
	else for (unsigned i = 0; i < channels.size(); i++)
	if (channels[i].getName() == channelName)
	for (unsigned j = 0; j < channels[i].getPrograms().size(); j++) {
		if (channels[i].getPrograms()[j].getName() == oldName) {
			if (choice == 1)
			{
				cout << endl << "Insira o novo nome do canal: ";
				cin >> newName;
				if (cin.fail())
				{
					cin.clear();
					cin.ignore();
					return false;
				}
				channels[i].getPrograms()[j].setName(newName);
				return true;
			}
			if (choice == 2)
			{
				cout << endl << "Insira o novo valor para a duracao: ";
				cin >> newduration;
				if (cin.fail())
				{
					cin.clear();
					cin.ignore();
					return false;
				}
				channels[i].getPrograms()[j].setDuration(newduration);
				return true;
			}
			if (choice == 3)
			{
				cout << endl << "Insira o novo valor para o dia: ";
				cin >> newDay;
				if (cin.fail())
				{
					cin.clear();
					cin.ignore();
					return false;
				}
				cout << endl << "Insira o novo valor para a hora: ";
				cin >> newHour;
				if (cin.fail())
				{
					cin.clear();
					cin.ignore();
					return false;
				}
				cout << endl << "Insira o novo valor para os minutos: ";
				cin >> newMinutes;
				if (cin.fail())
				{
					cin.clear();
					cin.ignore();
					return false;
				}
				Date date(newDay, newHour, newMinutes);
				channels[i].getPrograms()[j].setExhibitionDate(date);
				return true;
			}
		}
	}
}

//Movie CRUD

bool Box::createdMovie()
{
	string newmovie;
	float cost;

	cout << "Movie name: " << endl;
	cin >> newmovie;

	cout << "Movie cost: " << endl;
	cin >> cost;

	Movie movie(newmovie,cost);
	movieClub.push_back(movie);

	return true;
}

bool Box::removeMovie() {

	string removedMovie;

	cout << "Movie to remove: (space and lowercase/uppercase sensitive)" << endl;
	cin >> removedMovie;

	for (unsigned i = 0; i < movieClub.size(); i++)
	if (movieClub[i].getTitle() == removedMovie)
	{
		channels[i].getPrograms().erase(channels[i].getPrograms().begin() + i);
		return true;
	}
	return false;
}

// Coloca num vetor todos os filmes num videoclube
vector<Movie> Box::get_list_movies() const
{
	ifstream ficheiro;
	string nome = "MovieClub.txt";
	string movie_title;
	string cost_t;
	float cost;
	unsigned timesRented;
	vector<Movie> vec;

	ficheiro.open(nome.c_str());

	while (!ficheiro.eof())
	{
		getline(ficheiro, movie_title);
		getline(ficheiro, cost_t);

		size_t* idx = 0;
		cost = stof(cost_t, idx); // Conversao da string obtida do ficheiro txt para float

		Movie movie(movie_title, cost);

		vec.push_back(movie);
	}

	ficheiro.close();

	return vec;
}



bool Box::insert_rented_movie(Movie movie){
	seenMovies.push_back(movie);

	return true;
}

void rdc(string cenas)
{
	int tam = cenas.length();
	int i = (80 - tam) / 2;
	for (i; i > 0; i--)
		cout << " ";

	cout << cenas << '\n';
}

void rdc2(string cenas, int x)
{
	string ind = "(";
	ind += int_to_string(x);
	ind += ") ";
	ind += cenas;

	int tam = ind.length();
	int i = (80 - tam) / 2;
	for (i; i > 0; i--)
		cout << " ";

	cout << ind << '\n';
}

void Box::menu1()
{
	system("cls");

	printbox("boxascii.txt");

	char c;

	rdc("(1) TV");
	cout << '\n';
	rdc("(2) VideoClub");

	c = _getch();

	if (c == '1')
		menutv();
	if (c == '2')
		menuvideo();



	system("pause");
}

void Box::menutv()
{
	system("cls");
	printbox("tvascii.txt");

	char c;

	rdc("(1) Guide");
	cout << '\n';
	rdc("(2) CHannels");
	cout << '\n';
	rdc("(3) Type");
	cout << '\n';
	rdc("(0) Previous");

	c = _getch();

	if (c == '1')
		menutv();
	if (c == '2')
		canais();
	if (c == '0')
		menu1();
}

void Box::menuvideo()
{
	system("cls");
	printbox("videoascii.txt");

	char c;

	rdc("(1) List");
	cout << '\n';
	rdc("(2) Seen Movies");
	cout << '\n';
	rdc("(0) Previous");

	c = _getch();

	if (c == '1')
		menutv();
	if (c == '2')
		menuvideo();
	if (c == '0')
		menu1();
}

void printbox(string titul)
{
	ifstream titulo;
	string x;

	titulo.open(titul);

	if (titulo.fail())
		cout << "fail";

	cout << '\n' << '\n';

	while (!titulo.eof())
	{
		getline(titulo, x);
		rdc(x);
	}

	cout << '\n';
}

void Box::canais()
{
	system("cls");
	printbox("tvascii.txt");

	for (int i = 1; i <= channels.size(); i++)
	{
		rdc2(channels.at(i - 1).getName(), i);
		cout << '\n';
	}

	//escolha do canal
	char c;
	int n;
	stringstream ss;
	c = _getch();
	ss << c;
	ss >> n;

	//escolha do dia
	system("cls");
	printbox("tvascii.txt");
	showDays();
	int d;
	c = _getch();
	ss << c;
	ss >> d;

	//abre o menu que mostra os programas de um certo canal e dia
	Dias_canal(listByChannel(channels.at(n-1).getName, Date::int_to_weekday(d));
}

string int_to_string(int n)
{
	int temp;
	int i = 0;
	int contador = 0;

	temp = n;

	for (temp; temp > 0; temp = temp / 10)
		i++;

	string num;

	num.insert(0, i, '0');

	temp = n;

	for (temp; temp > 0; temp = temp / 10)
	{
		num.at(i - 1) = (char)((temp % 10) + (int)'0');
		i--;
	}

	return num;
}

unsigned int string_to_int(string str)
{
	unsigned int n = 0;
	int s;

	for (int i = 0; i < str.size(); i++)
	{
		s = str[i] - 48;
		n = n + s*pow(10, i);
	}

	return n;
}

void Box::Dias_canal(vector<Program> canal)
{
	printbox("tvascii.txt");

	for (int i = 1; i <= canal.size(); i++)
		rdc2(canal.at(i - 1).getName(), i);

	char c;
	int n;
	stringstream ss;
	c = _getch();
	ss << c;
	ss >> n;

	show_inf_Prog(Program prog);
}

void showDays()
{
	vector <string> semana = { "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday" };

	for (int i = 1; i <= 7; i++)
		rdc2(semana.at(i - 1), i);
}

void show_inf_Prog(Program prog)
{
	rdc(prog.getName());
	cout << '\n';
	cout << '\t' << prog.getType();

	string data = prog.getExhibitionDate().getDay();
	cout << '\t' << data << "   " << prog.getExhibitionDate().getHour();
	cout << ":" << prog.getExhibitionDate().getMinutes();

	Date acaba = prog.getExhibitionDate().addMinutes(prog.getExhibitionDate(), prog.getDuration());

	cout << " - " << acaba.getHour() << ":" << acaba.getMinutes() << '\n';

	if (prog.isRec())
		cout << '\t' << "Recorded" << '\n';
	else
		cout << '\t' << "1 to Record" << '\n';

	cout << '\n' << "(0) Previous";


}

bool Box::testPass()
{
	string pass;
	
	system("cls");
	cout << '\n' << '\t' << '\t' << '\t' << '\t' << "LOGIN";
	cout << '\n' << '\t' << '\t' << '\t' << '\t' << "Password: ";
	cin >> pass;

	if (pass == password)
		return true;
	else
		return false;
}