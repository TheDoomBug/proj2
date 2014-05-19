#include "Date.h"

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

	if (date1.weekDay > date2.weekDay)

Date Date::addMinutes(Date date, int duration) const{
	
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
	if (weekDay == "Segunda")
		return 0;
	else if (weekDay == "Terca")
		return 1;
	else if (weekDay == "Quarta")
		return 2;
	else if (weekDay == "Quinta")
		return 3;
	else if (weekDay == "Sexta")
		return 4;
	else if (weekDay == "Sabado")
		return 5;
	else
		return 6;
}

// Funcao que transforma o numero em dia da semana

string int_to_weekday(int weekDay)
{
	if (weekDay == 0)
		return "Segunda";
	else if (weekDay == 1)
		return "Terca";
	else if (weekDay == 2)
		return "Quarta";
	else if (weekDay == 3)
		return "Quinta";
	else if (weekDay == 4)
		return "Sexta";
	else if (weekDay == 5)
		return "Sabado";
	else
		return "Domingo";
}