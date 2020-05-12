#include "list.h"
#include "get.h"

#include "locale.h"

int main()
{
	setlocale(LC_ALL, "RU");

	list l;
	initList(&l);

	int ch;

	do
	{
		printf("\nНажмите цифру операции, которую Вы хотите выполнить и ENTER");
		printf("\n0.Выход\n1.Добавить контакт\n2.Изменить имя\n3.Изменить номер\n4.Изменить почту");
		printf("\n5.Изменить индекс\n6.Вывести список\n7.Поиск\n8.Удалить контакт\n");
		getInt(&ch, 0, 8);
		if (ch == 1)
		{
			printf("Имя: ");
			char* nname = getStr();
			printf("Номер телефона: ");
			char* nphoneNumber = getStr();
			printf("Почтовый ящик: ");
			char* nemail = getStr();
			printf("Индекс: ");
			int nzipCode;
			mingetInt(&nzipCode, 0);
			contact s;
			contactInit(&s);
			contactDefine(&s, nname, nphoneNumber, nemail, (int)nzipCode);
			pushBack(&l, s);
			printf("Контакт добавлен\n");
		}
		else if (ch == 2)
		{
			printf("Имя: ");
			char* nname = getStr();
			printf("Номер телефона: ");
			char* nphoneNumber = getStr();
			printf("Почтовый ящик: ");
			char* nemail = getStr();
			contact s;
			contactInit(&s);
			contactDefine(&s, nname, nphoneNumber, nemail, 0);
			contact* fs = listFind(l, s);
			if (fs == NULL) { printf("Контакт не найден\n"); return; }
			printf("Найденный контакт: ");
			contactPrint(*fs);
			printf("\nВведите новое имя: ");
			char* newname = getStr();
			contactChangeName(fs, newname);
			printf("Имя изменено\n");
		}
		else if (ch == 3)
		{
			printf("Имя: ");
			char* nname = getStr();
			printf("Номер телефона: ");
			char* nphoneNumber = getStr();
			printf("Почтовый ящик: ");
			char* nemail = getStr();
			contact s;
			contactInit(&s);
			contactDefine(&s, nname, nphoneNumber, nemail, 0);
			contact* fs = listFind(l, s);
			if (fs == NULL) { printf("Контакт не найден\n"); return; }
			printf("Найденный контакт: ");
			contactPrint(*fs);
			printf("\nВведите новый номер телефона: ");
			char* newPhoneNumber = getStr();
			contactChangePhoneNumber(fs, newPhoneNumber);
			printf("Номер изменен\n");
		}
		else if (ch == 4)
		{
			printf("Имя: ");
			char* nname = getStr();
			printf("Номер телефона: ");
			char* nphoneNumber = getStr();
			printf("Почтовый ящик: ");
			char* nemail = getStr();
			contact s;
			contactInit(&s);
			contactDefine(&s, nname, nphoneNumber, nemail, 0);
			contact* fs = listFind(l, s);
			if (fs == NULL) { printf("Контакт не найден\n"); return; }
			printf("Найденный контакт: ");
			contactPrint(*fs);
			printf("\nВведите новый почтовый ящик: ");
			char* newEmail = getStr();
			contactChangePhoneNumber(fs, newEmail);
			printf("Почтовый ящик изменен\n");
		}
		else if (ch == 5)
		{
			printf("Имя: ");
			char* nname = getStr();
			printf("Номер телефона: ");
			char* nphoneNumber = getStr();
			printf("Почтовый ящик: ");
			char* nemail = getStr();
			contact s;
			contactInit(&s);
			contactDefine(&s, nname, nphoneNumber, nemail, 0);
			contact* fs = listFind(l, s);
			if (fs == NULL) { printf("Контакт не найден\n"); return; }
			printf("Найденный контакт: ");
			contactPrint(*fs);
			printf("\nВведите новый индекс: ");
			int nzipCode;
			mingetInt(&nzipCode, 0);
			contactChangeZipCode(fs, (int)nzipCode);
			printf("Индекс изменен\n");
		}
		else if (ch == 6)
		{
			printf("Список контактов: ");
			listPrint(l);
		}
		else if (ch == 7)
		{
			printf("Имя: ");
			char* nname = getStr();
			printf("Номер телефона: ");
			char* nphoneNumber = getStr();
			printf("Почтовый ящик: ");
			char* nemail = getStr();
			contact s;
			contactInit(&s);
			contactDefine(&s, nname, nphoneNumber, nemail, 0);
			contact* fs = listFind(l, s);

			if (fs != NULL)
			{
				printf("\nНайденный контакт: ");
				contactPrint(*fs);
			}
			else
			{
				printf("Контакт не найден\n");
			}
		}
		else if (ch == 8)
		{
			printf("Имя: ");
			char* nname = getStr();
			printf("Номер телефона: ");
			char* nphoneNumber = getStr();
			printf("Почтовый ящик: ");
			char* nemail = getStr();
			contact s;
			contactInit(&s);
			contactDefine(&s, nname, nphoneNumber, nemail, 0);
			contact* fs = listFind(l, s);

			if (fs != NULL)
			{
				printf("\nНайденный контакт: ");
				contactPrint(*fs);
				contactFree(fs);
				printf("\nКонтакт удалён.");
			}
			else
			{
				printf("Контакт не найден\n");
			}
		}

	} while (ch);

	listFree(&l);
	return 0;
}