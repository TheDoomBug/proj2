#ifndef _DATE
 #define _DATE

#include <iostream>

using namespace std;


class Date{
	friend bool compareDates(Date date1, Date date2);
private:
  string weekDay;
  unsigned int hour;
  unsigned int minutes;
 public:
  Date(string day, unsigned int hour, unsigned int minutes);

  string getDay() const;
  unsigned getHour() const;
  unsigned getMinutes() const;
  
  int compareDates(Date date1, Date date2) const;
  bool sameDate(Date date1, Date date2) const;
  static Date addMinutes(Date date, int duration) const;
  static string int_to_weekday(int dia);
};

#endif
