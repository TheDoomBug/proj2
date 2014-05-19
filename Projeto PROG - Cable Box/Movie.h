#ifndef _MOVIE
 #define _MOVIE

#include<iostream>

using namespace std;

class Movie{

private:
  string title;
  //  string type; // removed in the final version of the work text
  float cost;
  unsigned timesRented;
 public:
  Movie(string title, float cost);
  Movie(string title, float cost, int seen);

  string getTitle() const;
  float getCost() const;
  unsigned getTimesRented() const;

  void setTimesRented(unsigned int t);
};


#endif