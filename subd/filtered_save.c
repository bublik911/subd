#include "struct.h"


struct Client* save_new_list(struct Client clients[10], struct Client filtered_clients[10], struct Client* filter_last_put, struct Client* last_put) {
	struct Client* new_list_client = filtered_clients;
	last_put = clients;
	for (new_list_client; new_list_client < filter_last_put; new_list_client++) {
		*last_put = *new_list_client;
		last_put++;
	}
	return last_put;
}