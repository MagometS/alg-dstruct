#include "info.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#define SUCCESS 1;
#define FAIL -1;


list_people_t* CreateList(void)
{

	list_people_t* p = NULL, * q;
	q = (list_people_t*)malloc(sizeof(list_people_t));
	if (q == NULL)
	{
		printf("error");
		return NULL;
	}
	q->name = NULL;
	q->surname = NULL;
	q->lastname = NULL;

	q->next = p;
	return q;
}


list_people_t* Clear(list_people_t* node)
{
	list_people_t* tmp = NULL;
	while (node != NULL)
	{
		tmp = node;
		node = node->next;
		free(tmp->name);
		free(tmp->surname);
		free(tmp->lastname);
		free(tmp);
	}

	return node;
}


void PrintList(list_people_t* p)
{
	list_people_t* tmp = p->next;
	if (tmp == NULL)
	{
		printf("List is empty\n");
	}
	else
	{
		while (tmp != NULL)
		{
			printf("%s %s %s", tmp->name, tmp->surname, tmp->lastname);
			tmp = tmp->next;
			if (tmp == NULL)
			{
				printf(".\n");
			}
			else
			{
				printf(", ");
			}
		}
	}
}


list_people_t* CreateNode(char* str)
{
	if (str == NULL)
	{
		printf("nothing to write");
		return NULL;
	}
	list_people_t* p = NULL;
	list_people_t* s = (list_people_t*)malloc(sizeof(list_people_t));
	if (s == NULL)
	{
		printf("error");
		return NULL;
	}
	char* word = strtok(str, " ,.");
	s->name = (char*)malloc(strlen(word) + 1);
	if (s->name == NULL)
	{
		printf("error");
		free(s);
		return NULL;
	}
	strcpy(s->name, word);

	word = strtok(NULL, " ,.");
	s->surname = (char*)malloc(strlen(word) + 1);
	if (s->surname == NULL)
	{
		printf("error");
		free(s->name);
		free(s);
		return NULL;
	}
	strcpy(s->surname, word);

	word = strtok(NULL, " ,.");
	s->lastname = (char*)malloc(strlen(word) + 1);
	if (s->lastname == NULL)
	{
		printf("error");
		free(s->surname);
		free(s->name);
		free(s);
		return NULL;
	}

	strcpy(s->lastname, word);

	s->next = p;

	return s;
}


list_people_t* SearchPlace(list_people_t* s, char* str)
{
	list_people_t* p1;
	list_people_t* p2;
	p2 = s;
	p1 = s->next;
	char buf[BUF_SIZE];

	if (p1 == NULL)
	{
		return p2;
	}

	snprintf(buf, sizeof(buf), "%s %s %s", p1->name, p1->surname, p1->lastname);

	while (strcmp(str, buf) > 0)
	{
		p2 = p1;
		p1 = p1->next;
		if (p1 == NULL)
		{
			break;
		}
		snprintf(buf, sizeof(buf), "%s %s %s", p1->name, p1->surname, p1->lastname);
	}

	return p2;
}


int AddToList(list_people_t* s, list_people_t* newNode)
{
	if (s == NULL || newNode == NULL)
	{
		printf("Error");
		return FAIL;
	}
	newNode->next = s->next;
	s->next = newNode;
	return SUCCESS;
}


list_people_t* FileToList(char* filename)
{
	FILE* fp;
	list_people_t* s = CreateList();
	if (s == NULL)
	{
		printf("error");
		return NULL;
	}
	char buf[BUF_SIZE];
	if ((fp = fopen(filename, "r")) == NULL)
	{
		printf("Cannot open file.\n");
		s = Clear(s);
		return NULL;
	}

	while (!feof(fp))
	{
		if (fgets(buf, sizeof(buf), fp))
		{

			list_people_t* newplace = SearchPlace(s, buf);
			list_people_t* newnode = NULL;
			newnode = CreateNode(buf);
			if (newnode == NULL)
			{
				printf("error");
				fclose(fp);
				Clear(s);
				return NULL;
			}
			AddToList(newplace, newnode);
			
		}
	}
	fclose(fp);
	return s;
}


list_people_t* FindPeople(list_people_t* s, char* str)
{
	list_people_t* p2 = s;
	list_people_t* p1 = s->next;
	list_people_t* tmp = NULL;
	list_people_t* founded = CreateList();
	if (founded == NULL)
	{
		printf("error");
		return NULL;
	}
	char* name = NULL;
	char* surname = NULL;
	char* lastname = NULL;

	char* word;
	word = strtok(str, "<>");
	name = word;
	word = strtok(NULL, "<>");
	surname = word;
	word = strtok(NULL, "<>");
	lastname = word;
	if (p1 == NULL)
	{
		printf("List is empty");
		return NULL;
	}
	while (p1 != NULL)
	{
		if (strncmp(name, p1->name, strlen(name)) == 0 || *name == ' ')
		{
			if (strncmp(surname, p1->surname, strlen(surname)) == 0 || *surname == ' ')
			{
				if (strncmp(lastname, p1->lastname, strlen(lastname)) == 0 || *lastname == ' ')
				{
					tmp = (list_people_t*)malloc(sizeof(list_people_t));
					if (tmp == NULL)
					{
						printf("error");
						Clear(founded);
						return NULL;
					}
					tmp->name = (char*)malloc(strlen(p1->name) + 1);
					if (tmp->name == NULL)
					{
						printf("error");
						free(tmp);
						Clear(founded);
						return NULL;
					}
					strcpy(tmp->name, p1->name);

					tmp->surname = (char*)malloc(strlen(p1->surname) + 1);
					if (tmp->surname == NULL)
					{
						printf("error");
						free(tmp->name);
						free(tmp);
						Clear(founded);
						return NULL;
					}
					strcpy(tmp->surname, p1->surname);

					tmp->lastname = (char*)malloc(strlen(p1->lastname) + 1);
					if (tmp->lastname == NULL)
					{
						printf("error");
						free(tmp->name);
						free(tmp->surname);
						free(tmp);
						Clear(founded);
						return NULL;
					}
					strcpy(tmp->lastname, p1->lastname);

					tmp->next = founded->next;
					founded->next = tmp;
				}

			}

		}
		p2 = p1;
		p1 = p1->next;
	}
	return founded;
}


int main()
{
	FILE* fp;
	char buf[BUF_SIZE];
	list_people_t* s = NULL;

	if ((fp = fopen("People.txt", "w")) == NULL)
	{
		printf("Cannot open file.\n");
		s = Clear(s);
		return -1;
	}

	char* words = "A A A \nC A A \nB A A \nD A A \nA B A \nA A B \nXA X X \nX X X";
	fputs(words, fp);
	fclose(fp);

	char* filename = "People.txt";
	s = FileToList(filename);
	if (s == NULL)
	{
		printf("error");
		return -1;
	}

	fgets(buf, sizeof(buf), stdin);
	list_people_t* p = FindPeople(s, buf);
	if (p == NULL)
	{
		Clear(s);
		return -1;
	}

	printf("People search: ");
	PrintList(p);
	p = Clear(p);

	printf("All people: ");
	PrintList(s);
	s = Clear(s);
	
	return 0;
}
