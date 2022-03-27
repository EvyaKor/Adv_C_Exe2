#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Section A
typedef struct {
	unsigned long id;
	char* name;
	unsigned long salary;
	union StartingYear
	{
		char HebYear[7];
		unsigned long EngYear;
	};
}Worker;

char* initString();
Worker* CreateWorker(int Heb_or_Eng);
void PrintWorker(Worker* worker, int Heb_or_Eng);

void main()
{
	Worker* worker1 = CreateWorker(2);
	PrintWorker(worker1, 1);
	return;
}

// Dynamic string input
char* initString()
{
	char temp_str[50];
	fseek(stdin, 0, SEEK_END);
	gets(temp_str);
	int size = strlen(temp_str);
	char* new_str = (char*)malloc(size * sizeof(char) + 1);
	if (!new_str)
	{
		printf("Memory allocation failed!\n");
		exit(0);
	}
	strcpy(new_str, temp_str);
	return new_str;
}

// Creats new worker
Worker* CreateWorker(int Heb_or_Eng)
{
	Worker* NewWorker = (Worker*)malloc(sizeof(Worker));
	if (!NewWorker)
	{
		printf("Memory allocation failed!\n");
		exit(0);
	}
	printf("Please enter worker information:\n\n");
	printf("Enter worker ID:\n");
	scanf("%ld", &NewWorker->id);
	printf("Enter worker name:\n");
	NewWorker->name = initString();
	printf("Enter worker salary:\n");
	scanf("%ld", &NewWorker->salary);
	printf("Enter worker's starting year:\n");
	switch (Heb_or_Eng)
	{
		case 0:
		{
			fseek(stdin, 0, SEEK_END);
			gets(NewWorker->HebYear);
			break;
		}
		case 1:
		{
			scanf("%ld", &NewWorker->EngYear);
			break;
		}
		default:
		{
			printf("Wrong choice!\n");
			free(NewWorker);
			return NULL;
		}
	}
	return NewWorker;
}

// Prints worker information
void PrintWorker(Worker* worker, int Heb_or_Eng)
{
	printf("Worker information:\n\n");
	printf("Worker's ID: %ld\n", worker->id);
	printf("Worker's name: %s\n", worker->name);
	printf("Worker's salary: %ld\n", worker->salary);
	switch (Heb_or_Eng)
	{
		case 0:
		{
			printf("Worker's starting year: %s\n", worker->HebYear);
			break;
		}
		case 1:
		{
			printf("Worker's starting year: %ld\n", worker->EngYear);
			break;
		}
		default:
		{
			printf("Wrong year type!\n");
			return;
		}
	}
}