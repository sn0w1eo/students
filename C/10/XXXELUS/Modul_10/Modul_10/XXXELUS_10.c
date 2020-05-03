#include "..\phomeBook_dll\phnbook.h"

int main() 
{
	system("mode con cols=142 lines=30");
	char key=' ';
	int searchIndex=0;
	char* contacts[CONTACTS] = {NULL};
	
	addContactStatic(contacts, "Loqiemean", "+75588996633", "26");
	addContactStatic(contacts, "Scriptonite", "+996553238899", "29");
	addContactStatic(contacts, "ATL", "0555444888", "30");
	addContactStatic(contacts, "Kirill", "BOMJ", "14");

	showContacts(contacts);
	showLegend();
	do
	{
		 key = getch();

		switch (key)
		{
		case 'A':
		case 'a':
			addContactByKeyboard(contacts);	
			system("cls");
			showContacts(contacts);
			showLegend();
			break;

		case 'D':
		case'd':
			deleteContact(contacts);
			system("cls");
			showContacts(contacts);
			showLegend();
			break;
		case 'S':
		case's':
			 
			searchIndex=searchContact(contacts);
			if (searchIndex != -1) {
				setPosition(72, 16);
				color(LIGHT_GREEN);
				printf("contact with that name under number: %d", searchIndex);
				printContact(contacts, searchIndex);
				wait();
				system("cls");
				showContacts(contacts);
				showLegend();
			}
			else
			{
				printf("Contact not found\n");
				wait();
				system("cls");
				showContacts(contacts);
				showLegend();
			}
			break;
		case'U':
		case'u':
			updateContact(contacts);
			
			system("cls");
			showContacts(contacts);
			showLegend();
			break;
		case ESC:
			return 0;
		}
	} while (1);
}