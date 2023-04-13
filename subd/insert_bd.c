#include "struct.h"


struct Client* insert_bd(struct Client* last_put) {
	set_client(last_put);
	last_put++;
	return last_put;
}