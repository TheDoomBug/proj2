#include <fstream>
#include <string>
#include <vector>
#include <iostream>

#include "Box.h"
#include "Movie.h"
#include "Channel.h"
#include "Date.h"



// Fim das funcoes auxiliares

Box::Box(string passwd, Date date):currentDate(date){
  password = passwd;
  currentDate = date;
  seenMovies = get_list_rented_movies();
  movieClub = get_list_movies();
  channels = get_list_channels();
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
	if (seenMovies[i].getTitle == title)
		return seenMovies[i].getTimesRented;

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
	if (channels[i].getName == removedChannel)
	{
		channels.erase(channels.begin() + i);
		return true;
	}
	return false;
}

//Por fazer
bool Box::updateChanel(){

}


//Program CRUD

bool Box::createdProgram(string channel){

	string newprogram;
	unsigned duration;

	string day;
	unsigned hour;
	unsigned minutes;

	cout << "Program Name: " << endl;
	cin >> newprogram;

	cout << "Program Duration: " << endl;
	cin >> duration;

	cout << "Start Time: " << endl;
	cout << "Day: " << endl;
	cin >> day;
	cout << "Hour: " << endl;
	cin >> hour;
	cout << "Minutes: " << endl;
	cin >> minutes;

	Program program(newprogram, duration, day, hour, minutes);
	Date date(day, hour, minutes);

	
	// Determinar o canal a colocar o programa, bem como a sua posicao na programacao

	for (unsigned i = 0; i < channels.size(); i++)
	{
		if (channels[i].getName == channel) // Procura pelo canal certo para o programa
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
}

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
				channels[i].getPrograms()[j].
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

bool Box::removeProgram() {

	string removedMovie;

	cout << "Movie to remove: (space and lowercase/uppercase sensitive)" << endl;
	cin >> removedMovie;

	for (unsigned i = 0; i < movieClub.size(); i++)
	if (movieClub[i].getTitle == removedMovie)
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

// Coloca num vector todos os filmes alugados
vector<Movie> Box::get_list_rented_movies() const
{
	ifstream ficheiro;
	string nome = "MoviesSeen.txt";
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
		ficheiro >> timesRented;

		size_t* idx = 0;
		cost = stof(cost_t, idx); // Conversao da string obtida do ficheiro txt para float

		Movie movie(movie_title, cost);

		vec.push_back(movie);
	}

	ficheiro.close();

	return vec;
}


// Coloca no vetor de filmes ja alugados um novo filme

bool Box::insert_rented_movie(Movie movie){
	seenMovies.push_back(movie);

	return true;
}


vector<Channel> Box::get_list_channels() const
{
	ifstream ficheiro;
	string nome = "ChannelsList.txt";
	string name;
	vector<Channel> vec;

	ficheiro.open(nome.c_str());

	while (!ficheiro.eof())
	{
		getline(ficheiro, name);
		Channel channel(name);
		vec.push_back(channel);
	}

	ficheiro.close();

	return vec;
}

