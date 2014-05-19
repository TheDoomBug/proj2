#ifndef _CHANNEL
 #define _CHANNEL

#include <iostream>
#include <cstdlib>
#include <string>
#include <stdlib.h>
#include <time.h>
#include <fstream>
#include <vector>
#include <conio.h>
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
  static unsigned int string_to_int(string str);

  void addProg(Program Prog);
  vector<Program> getPrograms();


};

#endif