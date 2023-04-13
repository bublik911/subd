#include "struct.h"
#include "setters.h"
#include "output.h"


struct Client* delete(struct Client clients[10], struct Client* last_put) {
	struct Client* client = clients;
	long long delete_phone;
	printf("Введите номер телефона клиента, которого хотите удалить\n");
	output(clients, last_put);
	delete_phone = set_phone();
	for (client; client < last_put; client++) {
		if (client->phone == delete_phone) {
			for (int i = 0; i < 10; i++) {
				client->name[i] = (last_put - 1)->name[i];
			}
			client->age = (last_put - 1)->age;
			client->phone = (last_put - 1)->phone;
			client->date_month = (last_put - 1)->date_month;
			client->date_day = (last_put - 1)->date_day;
			last_put--;
		}
	}
	output(clients, last_put);
	return last_put;
}