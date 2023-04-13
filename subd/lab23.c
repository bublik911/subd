#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <locale.h>
#include "struct.h"
#include "bulk_insert_bd.h"
#include "insert_bd.h"
#include "output.h"
#include "delete.h"
#include "sort.h"
#include "filter.h"
#include "export.h"
#include "import.h"


void main() {
	setlocale(LC_ALL, "Russian");
	struct Client clients[10];
	struct Client* last_put = clients;
	int command;
	int* command_pt = &command;
	do {
		printf("Выберите команду\n"
			"1) Ввести несколько клиентов\n"
			"2) Ввести одного клиента\n"
			"3) Вывести всех клиентов\n"
			"4) Удалить клиента\n"
			"5) Сортировка\n"
			"6) Фильтры\n"
			"7) Экспортировать базу\n"
			"8) Импортировать базу\n"
			"0) Завершить программу\n");
		scanf("%d", command_pt);
		switch (*command_pt) {
		case 1: {
			last_put = bulk_insert_bd(clients, last_put);
			break;
		}
		case 2: {
			last_put = insert_bd(clients, last_put);
			break;
		}
		case 3: {
			output(clients, last_put);
			break;
		}
		case 4: {
			last_put = delete(clients, last_put);
			break;
		}
		case 5: {
			sort(clients, last_put);
			break;
		}
		case 6: {
			last_put = filter(clients, last_put);
			break;
		}
		case 7: {
			export_db(clients, last_put);
			break;
		}
		case 8: {
			last_put = import_db(clients, last_put);
			break;
		}
		default:
			break;
		}
	} while (*command_pt != 0);
}