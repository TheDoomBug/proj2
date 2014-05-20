#ifndef _MOVIE
 #define _MOVIE

#include <string>

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

  void setTitle(string newTitle);
  void setCost(float newCost);
  void setTimesRented(unsigned int t);
};


#endif