#include "struct.h"
#include "output.h"
#include "filtered_save.h"


struct Client* filter_by_name(struct Client clients[10], struct Client* last_put);
struct Client* filter_by_age(struct Client clients[10], struct Client* last_put);
struct Client* filter_by_month(struct Client clients[10], struct Client* last_put);
struct Client* filter_by_day(struct Client clients[10], struct Client* last_put);


struct Client* filter(struct Client clients[10], struct Client* last_put) {
	int command, * command_pt = &command;
	printf("��� �� ������ ������������� ������?\n"
		"1) �� ������ ����� �����\n"
		"2) �� ��������\n"
		"3) �� ������ ��������\n"
		"4) �� ��� ��������\n");
	scanf("%d", command_pt);
	switch (*command_pt) {
	case 1: {
		last_put = filter_by_name(clients, last_put);
		break;
	}
	case 2: {
		last_put = filter_by_age(clients, last_put);
		break;
	}
	case 3: {
		last_put = filter_by_month(clients, last_put);
		break;
	}
	case 4: {
		last_put = filter_by_day(clients, last_put);
		break;
	}
	default:
		break;
	}
	return last_put;
}


struct Client* filter_by_name(struct Client clients[10], struct Client* last_put) {
	char min[10] = {"a"}, max[10] = { "z" };
	struct Client* client = clients;
	struct Client filtered_clients[10];
	printf("������� �� ����� ����� ����������� �������\n");
	scanf("%s", min);
	printf("������� �� ����� ����� ����������� �������\n");
	scanf("%s", max);
	int i = 0;
	for (client; client < last_put; client++) {
		if (client->name[0] >= min[0] && client->name[0] <= max[0]) {
			filtered_clients[i] = *client;
			i += 1;
		}
	}
	printf("������������ ������:\n");
	output(filtered_clients, &filtered_clients[i]);
	int command, * command_pt = &command;
	printf("��������� ������ ��� ��������� � ������������?\n"
		"1) ���������\n"
		"2) �� ���������\n");
	scanf("%d", command_pt);
	switch (*command_pt) {
	case 1: {
		last_put = save_new_list(clients, filtered_clients, &filtered_clients[i], last_put);
		break;
	}
	default:
		break;
	}
	return last_put;
}


struct Client* filter_by_age(struct Client clients[10], struct Client* last_put) {
	int min = -100, max = 100;
	struct Client* client = clients;
	struct Client filtered_clients[10];
	printf("������� ����������� ������� �������\n");
	scanf("%d", &min);
	printf("������� ������������ ������� �������\n");
	scanf("%d", &max);
	int i = 0;
	for (client; client < last_put; client++) {
		if (client->age >= min && client->age <= max) {
			filtered_clients[i] = *client;
			i += 1;
		}
	}
	printf("������������ ������:\n");
	output(filtered_clients, &filtered_clients[i]);
	int command, * command_pt = &command;
	printf("��������� ������ ��� ��������� � ������������?\n"
		"1) ���������\n"
		"2) �� ���������\n");
	scanf("%d", command_pt);
	switch (*command_pt) {
	case 1: {
		last_put = save_new_list(clients, filtered_clients, &filtered_clients[i], last_put);
		break;
	}
	default:
		break;
	}
	return last_put;
}


struct Client* filter_by_month(struct Client clients[10], struct Client* last_put) {
	int min = 0, max = 13;
	struct Client* client = clients;
	struct Client filtered_clients[10];
	printf("������� ����������� ����� �������� �������\n");
	scanf("%d", &min);
	printf("������� ������������ ����� �������� �������\n");
	scanf("%d", &max);
	int i = 0;
	for (client; client < last_put; client++) {
		if (client->date_month >= min && client->date_month <= max) {
			filtered_clients[i] = *client;
			i += 1;
		}
	}
	printf("������������ ������:\n");
	output(filtered_clients, &filtered_clients[i]);
	int command, * command_pt = &command;
	printf("��������� ������ ��� ��������� � ������������?\n"
		"1) ���������\n"
		"2) �� ���������\n");
	scanf("%d", command_pt);
	switch (*command_pt) {
	case 1: {
		last_put = save_new_list(clients, filtered_clients, &filtered_clients[i], last_put);
		break;
	}
	default:
		break;
	}
	return last_put;
}


struct Client* filter_by_day(struct Client clients[10], struct Client* last_put) {
	int min = 0, max = 32;
	struct Client* client = clients;
	struct Client filtered_clients[10];
	printf("������� ����������� ���� �������� �������\n");
	scanf("%d", &min);
	printf("������� ������������ ���� �������� �������\n");
	scanf("%d", &max);
	int i = 0;
	for (client; client < last_put; client++) {
		if (client->date_day >= min && client->date_day <= max) {
			filtered_clients[i] = *client;
			i += 1;
		}
	}
	printf("������������ ������:\n");
	output(filtered_clients, &filtered_clients[i]);
	int command, * command_pt = &command;
	printf("��������� ������ ��� ��������� � ������������?\n"
		"1) ���������\n"
		"2) �� ���������\n");
	scanf("%d", command_pt);
	switch (*command_pt) {
	case 1: {
		last_put = save_new_list(clients, filtered_clients, &filtered_clients[i], last_put);
		break;
	}
	default:
		break;
	}
	return last_put;
}