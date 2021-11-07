#ifdef __cplusplus
extern "C" {
#endif

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define BUF_SIZE 128


	typedef struct list_people
	{
		char* name;
		char* surname;
		char* lastname;
		struct list_people* next;
	}list_people_t;

	void PrintList(list_people_t* p);
	int AddToList(list_people_t* s, list_people_t* newnode);
	list_people_t* CreateList(void);
	list_people_t* Clear(list_people_t* node);
	list_people_t* CreateNode(list_people_t* s, char* str);
	list_people_t* SearchPlace(list_people_t* s, char* str);
	list_people_t* FindPeople(list_people_t* s, char* str);
	list_people_t* FileToList(list_people_t* s, char* filename);

#ifdef __cplusplus
}
#endif