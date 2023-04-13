#include "struct.h"


struct Client* bulk_insert_bd(struct Client clients[10], struct Client* last_put) {
	struct Client client;
	int flag = 1;
	do {
		set_client(clients, last_put);
		last_put++;
		printf("Хотите добавить еще одного клиента?\n"
			"1) Да\n"
			"2) Нет. В меню\n");
		scanf("%d", &flag);
	} while (flag == 1);
	return last_put;
}