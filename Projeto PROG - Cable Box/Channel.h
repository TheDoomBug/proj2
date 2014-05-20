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

  vector <Program> set_list_programs();
  void set_name(string newname);

  bool programOverlap(Program program1, Program program2) const;
  static unsigned int string_to_int(string str);

  void addProg(Program Prog);


};

#endif