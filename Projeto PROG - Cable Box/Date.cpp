#include "Date.h"

unsigned weekday_to_int(string weekDay);


Date::Date(string day, unsigned int dateHour, unsigned int dateMinutes){

	weekDay = day;
	hour = dateHour;
	minutes = dateMinutes;

}

string Date::getDay() const {
	return weekDay;
}

unsigned Date::getHour() const {
	return hour;
}

unsigned Date::getMinutes() const {
	return minutes;
}

int Date::compareDates(Date date1, Date date2) const{

	// Se date1 vier antes de date2, retorna -1. Se vierem ao mesmo tempo, retorna 0. Se vier depois, retorna 1

	if (date1.weekDay > date2.weekDay)
		return 1;
	else if (date1.weekDay < date2.weekDay)
		return -1;
	else if (date1.hour > date2.hour)
		return 1;
	else if (date1.hour < date2.hour)
		return -1;
	else if (date1.minutes > date2.minutes)
		return 1;
	else if (date1.minutes < date2.minutes)
		return -1;
	else return 0;
}

Date Date::addMinutes(Date date, int duration){
	
	int minutes = date.minutes + duration;
	int hour = date.hour;
	int weekDay = weekday_to_int(date.weekDay);

	if (minutes >= 60)
	{
		hour = hour + hour / minutes;
		minutes = minutes % 60;
	}

	if (hour >= 24)
	{
		weekDay = weekDay + weekDay / 24;
		hour = hour % 24;
	}

	Date rdate(int_to_weekday(weekDay), hour, minutes);
	return rdate;
}

bool Date::sameDate(Date date1, Date date2) const {
	if (compareDates(date1, date2))
		return false;
	else return true;
}



// Funcoes auxiliares

// Funcao que transforma o dia da semana num numero para comparacao

unsigned weekday_to_int(string weekDay)
{
	if (weekDay == "Monday")
		return 1;
	else if (weekDay == "Tuesday")
		return 2;
	else if (weekDay == "Wednesday")
		return 3;
	else if (weekDay == "Thursday")
		return 4;
	else if (weekDay == "Friday")
		return 5;
	else if (weekDay == "Saturday")
		return 6;
	else if (weekDay == "Sunday")
		return 7;
	else
		return -1;
}

// Funcao que transforma o numero em dia da semana

string Date::int_to_weekday(int dia)
{
	if (dia == 1)
		return "Monday";
	else if (dia == 2)
		return "Tuesday";
	else if (dia == 3)
		return "Wednesday";
	else if (dia == 4)
		return "Thursday";
	else if (dia == 5)
		return "Friday";
	else if (dia == 6)
		return "Saturday";
	else if (dia == 7)
		return "Sunday";
}