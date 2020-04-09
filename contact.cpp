#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <cstdio>
#include <stdlib.h>
#include <string.h>
#include <string>

typedef struct contact {
	char name[20]; //이름
	char phonenumber[20]; //전화번호
	char address[50]; //주소
	char email[30]; //이메일
} Contact;

FILE* fp;
FILE* ft;
Contact ct;
Contact nct;
int count = 0;
char search[20];

int main()
{
MAIN:
	system("cls");
	printf("\n\t**** Welcome to Contact Management System ****\n");
	printf("\n");
	printf("\t\t\tMAIN MENU\n");
	printf("\t\t=====================\n");
	printf("\t\t[1] Add a new Contact\n");
	printf("\t\t[2] List all Contacts\n");
	printf("\t\t[3] Search for Contact\n");
	printf("\t\t[4] Edit a Contact\n");
	printf("\t\t[5] Delete a Contact\n");
	printf("\t\t[6] Information\n");
	printf("\t\t[0] Exit\n");
	printf("\t\t=====================\n");
	printf("\t\tEnter the choice: ");

	int menu = 0;
	int exit = 0;
	scanf("%d", &menu);

	switch (menu)
	{
	case 0: // Exit
		system("cls");
		goto COMMENT;

	case 1: //Add a new Contact
		system("cls");
		fp = fopen("contacts.bin", "ab");

		printf("\n\t\t\t================================");
		printf("\n\t\t\t\t  ADD CONTACTS");
		printf("\n\t\t\t================================");
		printf("\n\tEnter as follows:");
		printf("\n\n\tName: HongGilDong");
		printf("\n\tPhone: 010-2345-6789");
		printf("\n\tAddress: Buk-gu,Gwangju");
		printf("\n\tE-mail: Hongg@gmail.com");
		printf("\n\t(Please mark the space as '_'(Underscore).");

		fflush(stdin);
		printf("\n\n\tName: ");
		scanf("%s", ct.name);
		fflush(stdin);
		printf("\tPhone: ");
		scanf("%s", ct.phonenumber);
		fflush(stdin);
		printf("\tAddress: ");
		scanf("%s", ct.address);
		fflush(stdin);
		printf("\tE-mail: ");
		scanf("%s", ct.email);
		printf("\n");
		fwrite(&ct, sizeof(ct), 1, fp);

		fclose(fp);
		goto COMMENT;
		break;

	case 2: //List all Contacts
		system("cls");
		fp = fopen("contacts.bin", "r+b");

		printf("\n\t\t\t================================");
		printf("\n\t\t\t\tLIST OF CONTACTS");
		printf("\n\t\t\t================================");
		printf("\n\n\tName\t\tPhone No\tAddress\t\t\tE-mail");
		printf("\n\t================================================================================\n");
		
		fread(&ct, sizeof(ct), 1, fp);
		while (true)
		{
			if (fread(&ct, sizeof(ct), 1, fp) == 0)
				break;
			printf("\t%s\t%s\t%s\t%s\n", ct.name, ct.phonenumber, ct.address, ct.email);
			fseek(fp, sizeof(ct), SEEK_CUR);
		}
		printf("\n\t================================================================================\n");
		fclose(fp);
		break;

	case 3: //Search for Contact
		system("cls");
		fp = fopen("contacts.bin", "r+b");

		printf("\n\t\t\t================================");
		printf("\n\t\t\t\tSEARCH CONTACTS");
		printf("\n\t\t\t================================");

		printf("\n\n\tEnter the name or phone number you want to find: ");
		scanf("%s", search);
		while (true)
		{
			fread(&ct, sizeof(ct), 1, fp);
			if ((strcmp(search, ct.name) == 0) || (strcmp(search, ct.phonenumber) == 0))
				break;
			fseek(fp, 120, SEEK_CUR);
		}

		printf("\n\t\t\t================================");
		printf("\n\t\t\tName: %s", ct.name);
		printf("\n\t\t\tPhone: %s", ct.phonenumber);
		printf("\n\t\t\tAddress: %s", ct.address);
		printf("\n\t\t\tE-mail: %s", ct.email);
		printf("\n\t\t\t================================");

		goto COMMENT;
		break;

	case 4: //Edit a Contact
		system("cls");
		fp = fopen("contacts.bin", "r+b");

		printf("\n\t\t\t================================");
		printf("\n\t\t\t\t  EDIT CONTACTS");
		printf("\n\t\t\t================================");

		printf("\n\n\tEnter the name of contact you want to edit: ");
		scanf("%s", search);
		while (true)
		{
			fread(&ct, sizeof(ct), 1, fp);
			if (strcmp(search, ct.name) == 0)
				break;
			fseek(fp, 120, SEEK_CUR);
		}

		printf("\n\t\t\t================================");
		printf("\n\t\t\tName: %s", ct.name);
		printf("\n\t\t\tPhone: %s", ct.phonenumber);
		printf("\n\t\t\tAddress: %s", ct.address);
		printf("\n\t\t\tE-mail: %s", ct.email);
		printf("\n\t\t\t================================");

		//fseek(fp, 0, SEEK_CUR);
		printf("\n\n\tPlease correct the above contact.");
		fflush(stdin);
		printf("\n\tName: ");
		scanf("%s", nct.name);
		fflush(stdin);
		printf("\tPhone: ");
		scanf("%s", nct.phonenumber);
		fflush(stdin);
		printf("\tAddress: ");
		scanf("%s", nct.address);
		fflush(stdin);
		printf("\tE-mail: ");
		scanf("%s", nct.email);
		printf("\n");

		fwrite(&nct, sizeof(ct), 1, fp);

		printf("\n\t\t\tEditing is complete.");
		printf("\n\t\t\t================================");
		printf("\n\t\t\tName: %s", ct.name);
		printf("\n\t\t\tPhone: %s", ct.phonenumber);
		printf("\n\t\t\tAddress: %s", ct.address);
		printf("\n\t\t\tE-mail: %s", ct.email);
		printf("\n\t\t\t================================");

		goto COMMENT;
		break;

	case 5: //Delete a Contact
		system("cls");
		fp = fopen("contacts.bin", "r+b");
		ft = fopen("contacts.bin", "r+b");

		printf("\n\t\t\t================================");
		printf("\n\t\t\t\t DELETE CONTACTS");
		printf("\n\t\t\t================================");

		printf("\n\n\tEnter the name of contact you want to delete: ");
		scanf("%s", search);
		while (true)
		{
			fread(&ct, sizeof(ct), 1, fp);
			if (strcmp(search, ct.name) == 0)
				break;
			fseek(fp, 120, SEEK_CUR);
		}

		printf("\n\t\t\t================================");
		printf("\n\t\t\tName: %s", ct.name);
		printf("\n\t\t\tPhone: %s", ct.phonenumber);
		printf("\n\t\t\tAddress: %s", ct.address);
		printf("\n\t\t\tE-mail: %s", ct.email);
		printf("\n\t\t\t================================");

		fseek(ft, -120, SEEK_END);
		fread(&ct, sizeof(ct), 1, fp);
		fread(&nct, sizeof(ct), 1, ft);
		fwrite(&nct, sizeof(ct), 1, fp);
		fwrite(NULL, sizeof(ct), 1, ft);

		break;

	case 6:
		system("cls");
		printf("\n\n\t\t============================================\n");
		printf("\t\t============================================\n");
		printf("\t\t              INFORMATION\n");
		printf("\t\t\n");
		printf("\t\tVERSION \n");
		printf("\t\t=> 1.0 \n");
		printf("\t\t\n");
		printf("\t\tDEVELOPER\n");
		printf("\t\t=> 최지연, 유영택, 박재현(Team1)\n");
		printf("\t\t\n");
		printf("\t\tEMAIL: \n");
		printf("\t\t=> choijy1010@gmail.com \n");
		printf("\t\t   yt010108@naver.com  \n");
		printf("\t\t============================================\n");
		printf("\t\t============================================\n");
		goto COMMENT;

	default: //선택지 이외의 숫자를 입력할 경우
		goto MAIN;
		break;
	}

COMMENT:
	printf("\n\n\tTo finish System, Press 0 and To go back Main Menu, Press 1: ");
	scanf(" %d", &exit);

	if (exit == 0)
		goto EXIT;
	else if (exit == 1)
		goto MAIN;
	else {
		printf("\n\tIncorrect Input. Abnormal Termination.");
		goto EXIT;
	}

EXIT:
	return 0;
}