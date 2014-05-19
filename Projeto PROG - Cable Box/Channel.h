#ifndef _CHANNEL
 #define _CHANNEL

#include<iostream>
#include<vector>
#include<string>
#include "Program.h"

using namespace std;

class Channel{

private:
  string name;
  vector<Program> programs;
 public:
  Channel(string name);

  string getName() const;
  vector<Program> getPrograms() const;

  vector <Program> set_list_programs() const;

  bool programOverlap(Program anterior, Program actual, Program seguinte) const;
 

  
};

#endif