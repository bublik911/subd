#include "struct.h"


void set_name(struct Client* last_put);
int set_age();
long long set_phone();
int set_date_month();
int set_date_day();


void set_client(struct Client clients[10], struct Client* last_put) {
	set_name(last_put);
	last_put->age = set_age();
	last_put->phone = set_phone(clients, last_put);
	last_put->date_month = set_date_month();
	last_put->date_day = set_date_day();
}


void set_name(struct Client* last_put) {
	printf("Введите имя клиента\n");
	scanf("%s", last_put->name);
}


int set_age() {
	int age;
	int res;
	do {
		printf("Введите возраст\n");
		res = scanf("%d", &age);
		while (getchar() != '\n');
	if (res == 1) {
			if (age > 0 && age <= 100) return age;
			else{
				res = 0;
				age = 0;
				printf("Некорректный возраст\n");
			}
	}
	else {
		age = 0;
		printf("Некорректный возраст\n");
	}
	} while (res != 1);
}


long long set_phone(struct Client clients[10], struct Client* last_put){
	struct Client* client = clients;
	long long phone;
	long long check;
	int res;
	do {
		printf("Введите номер телефона\n");
		res = scanf("%lld", &phone);
		check = phone;
		while (getchar() != '\n');
		if (res == 1) {
			int k = 1;
			while (check = check / 10) k++;
			if (k > 10) {
				for (client; client < last_put; client++) {
					if (client->phone == phone) {
						res = 0;
						printf("Номер телефона уже есть в базе\n");
					}
				}
			}
			else {
				res = 0;
				printf("Некорректный номер телефона\n");
			}
		}
		else {
			printf("Некорректный номер телефона\n");
		}
	} while (res != 1);
	return phone;
}


int set_date_month() {
	int date_month;
	int res;
	do {
		printf("Введите месяц рождения клиента\n");
		res = scanf("%d", &date_month);
		while (getchar() != '\n');
		if (res == 1) {
			if (date_month > 0 && date_month <= 12) return date_month;
			else {
				res = 0;
				date_month = 0;
				printf("Некорректный месяц\n");
			}
		}
		else {
			date_month = 0;
			printf("Некорректный месяц\n");
		}
	} while (res != 1);
}


int set_date_day() {
	int date_day;
	int res;
	do {
		printf("Введите день рождения клиента\n");
		res = scanf("%d", &date_day);
		while (getchar() != '\n');
		if (res == 1) {
			if (date_day > 0 && date_day <= 31) return date_day;
			else {
				res = 0;
				date_day = 0;
				printf("Некорректный день\n");
			}
		}
		else {
			date_day = 0;
			printf("Некорректный день\n");
		}
	} while (res != 1);
}