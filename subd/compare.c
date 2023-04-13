#include "struct.h"


int compare_name(const struct Client* i, const struct Client* j) {
	const char* name1 = i->name;
	const char* name2 = j->name;
	return strcmp(name1, name2);
}


int compare_age(const struct Client* i, const struct Client* j) {
	return i->age - j->age;
}


int compare_month(const struct Client* i, const struct Client* j) {
	return i->date_month - j->date_month;
}


int compare_day(const struct Client* i, const struct Client* j) {
	return i->date_day - j->date_day;
}