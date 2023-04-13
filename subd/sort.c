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
	printf("Выберите тип сортировки:\n"
		"1) Сортировка по имени\n"
		"2) Сортировка по возрасту\n"
		"3) Сортировка по месяцу рождения\n"
		"4) Сортировка по дню рождения\n");
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
	printf("База отсортирована\n");
	output(clients, last_put);
}


void sort_by_age(struct Client clients[10], struct Client* last_put) {
	int k = 0;
	for (struct Client* client = clients; client < last_put; client++) {
		k++;
	}
	qsort(clients, k, sizeof(struct Client), compare_age);
	printf("База отсортирована\n");
	output(clients, last_put);
}


void sort_by_month(struct Client clients[10], struct Client* last_put) {
	int k = 0;
	for (struct Client* client = clients; client < last_put; client++) {
		k++;
	}
	qsort(clients, k, sizeof(struct Client), compare_month);
	printf("База отсортирована\n");
	output(clients, last_put);
}


void sort_by_day(struct Client clients[10], struct Client* last_put) {
	int k = 0;
	for (struct Client* client = clients; client < last_put; client++) {
		k++;
	}
	qsort(clients, k, sizeof(struct Client), compare_day);
	printf("База отсортирована\n");
	output(clients, last_put);
}