#include "struct.h"


struct Client* insert_bd(struct Client clients[10], struct Client* last_put) {
	set_client(clients, last_put);
	last_put++;
	return last_put;
}