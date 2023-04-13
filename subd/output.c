#include "struct.h"


void output(struct Client clients[10], struct Client* last_put) {
	struct Client* client = clients;
	for (client; client < last_put; client++) {
		printf("Клиент %s %d %lld %d %d\n", client->name, client->age, client->phone, client->date_month, client->date_day);
	}
}