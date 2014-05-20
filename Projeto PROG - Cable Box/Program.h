#ifndef _PROGRAM
 #define _PROGRAM

#include<iostream>
#include "Date.h"


using namespace std;


class Program{

private:
  string name;
  string type;    // introduced in the final version of the work text
  bool recorded;  // introduced in the final version of the work text
  int duration;   // in minutes
  Date exhibitionDate;

 public:
  Program(string name, string tipo, unsigned int duration, string day, unsigned int hour, unsigned int minutes);

  string getName() const;
  string getType() const;
  int getDuration() const;
  Date getExhibitionDate() const;
  bool isRec() const;

  void setRecorded();
  void setName(string newname);
  void setType(string newtype);
  void setDuration(int newduration);
  void setExhibitionDate(Date newExhibitionDate);

  bool programOverlap(Date date1, Date date2) const;
};

#endif
