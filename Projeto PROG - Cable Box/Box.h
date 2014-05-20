#ifndef _BOX
 #define _BOX

#include<iostream>
#include<vector>
#include<string>

#include "Date.h"
#include "Channel.h"
#include "Program.h"
#include "Movie.h"

using namespace std;


class Box{
  string password;
  Date currentDate;
  vector<Channel> channels;
  vector<Movie> movieClub;
  vector<Movie> seenMovies;
  vector<Program> recordList;  // stores recorded programs and programs yet to be recorded
  //  vector<Program> recorded;    // removed in the final version of the work text

 public:
  Box(string passwd, Date currentDate);

  vector<Movie> get_list_movies() const;
  vector<Movie> get_list_rented_movies() const;
  vector<Channel> get_list_channels() const;
  bool insert_rented_movie(Movie movie); // Inserir um filme recentemente alugado na lista de filmes alugados

  void set_new_channel(string name);

  vector<Program> listByDay(string day) const;
  vector<Program> listByChannel(string channel, string day) const;
  vector<Program> listByType(string type, string day) const;
  bool rentMovies(string title);
  float moneySpent() const;
  int timesWatched(string title) const;
  bool changePassword();          // ask, verify and change the password
  // Channel CRUD
  bool createdChannel();
  bool removeChannel();
  bool updateChannel();
  // Program CRUD
  bool createdProgram(string channel);
  bool removeProgram();
  bool updateProgram();
  // Movie CRUD
  bool createdMovie();
  bool removeMovie();
  bool updateMovie();

  void menu1();
  void menutv();
  void menuvideo();
  void canais();
  void Dias_canal(vector<Program> canal);
  bool testPass();
  string getPassword();
};

#endif
