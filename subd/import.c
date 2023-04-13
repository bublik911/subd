#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "struct.h"


struct Client* import_db(struct Client clients[10], struct Client* last_put) {
	last_put = clients;
	FILE* f = fopen("filename.txt", "r");
	while (fscanf(f, "%s %d %lld %d %d", &last_put->name, &last_put->age, &last_put->phone, &last_put->date_month, &last_put->date_day) != EOF) last_put++;
	printf("База импортирована\n");
	fclose(f);
	return last_put;
}