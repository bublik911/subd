#include "struct.h"


struct Client* bulk_insert_bd(struct Client* last_put) {
	struct Client client;
	int flag = 1;
	do {
		set_client(last_put);
		last_put++;
		printf("������ �������� ��� ������ �������?\n"
			"1) ��\n"
			"2) ���. � ����\n");
		scanf("%d", &flag);
	} while (flag == 1);
	return last_put;
}