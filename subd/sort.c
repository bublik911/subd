#include "struct.h"
#include "compare.h"
#include <stdlib.h>
#include "swap.h"
#include "output.h"


void sort_by_name(struct Client clients[10], struct Client* last_put);
void sort_by_age(struct Client clients[10], struct Client* last_put);
void sort_by_month(struct Client clients[10], struct Client* last_put);
void sort_by_day(struct Client clients[10], struct Client* last_put);


void sort(struct Client clients[10], struct Client* last_put) {
	int command, *command_pt = &command;
	printf("�������� ��� ����������:\n"
		"1) ���������� �� �����\n"
		"2) ���������� �� ��������\n"
		"3) ���������� �� ������ ��������\n"
		"4) ���������� �� ��� ��������\n");
	scanf("%d", command_pt);
	switch (*command_pt) {
	case 1: {
		sort_by_name(clients, last_put);
		break;
	}
	case 2: {
		sort_by_age(clients, last_put);
		break;
	}
	case 3: {
		sort_by_month(clients, last_put);
		break;
	}
	case 4: {
		sort_by_day(clients, last_put);
		break;
	}
	default:
		break;
	}
}


void sort_by_name(struct Client clients[10], struct Client* last_put) {
	int k = 0;
	for (struct Client* client = clients; client < last_put; client++) {
		k++;
	}
	qsort(clients, k, sizeof(struct Client), compare_name);
	printf("���� �������������\n");
	output(clients, last_put);
}


void sort_by_age(struct Client clients[10], struct Client* last_put) {
	int k = 0;
	for (struct Client* client = clients; client < last_put; client++) {
		k++;
	}
	qsort(clients, k, sizeof(struct Client), compare_age);
	printf("���� �������������\n");
	output(clients, last_put);
}


void sort_by_month(struct Client clients[10], struct Client* last_put) {
	int k = 0;
	for (struct Client* client = clients; client < last_put; client++) {
		k++;
	}
	qsort(clients, k, sizeof(struct Client), compare_month);
	printf("���� �������������\n");
	output(clients, last_put);
}


void sort_by_day(struct Client clients[10], struct Client* last_put) {
	int k = 0;
	for (struct Client* client = clients; client < last_put; client++) {
		k++;
	}
	qsort(clients, k, sizeof(struct Client), compare_day);
	printf("���� �������������\n");
	output(clients, last_put);
}