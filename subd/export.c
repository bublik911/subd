#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "struct.h"


void export_db(struct Client clients[10], struct Client* last_put) {
	struct Client* client = clients;
	FILE* f = fopen("filename.txt", "w+");
	for (client; client < last_put; client++) {
		fprintf(f, "%s %d %lld %d %d\n", client->name, client->age, client->phone, client->date_month, client->date_day);
	}
	printf("База экспортирована\n");
	fclose(f);
}