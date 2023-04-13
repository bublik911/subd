#include "struct.h"


void swap_client(struct Client* a, struct Client* b) {
	struct Client tmp_a = *a;
	struct Client tmp_b = *b;
	*a = tmp_b;
	*b = tmp_a;
}