#define _CRT_SECURE_NO_WARNINGS
#include "pch.h"
#include "info.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<gtest/gtest.h>



TEST(TestCaseName, TestName)
{
  EXPECT_EQ(1, 1);
  EXPECT_TRUE(true);
}


TEST(Creation, CreateList_TEST)
{
	list_people_t* tmp = CreateList();
	ASSERT_NE(tmp, nullptr);
	EXPECT_EQ(tmp->next, nullptr);
	free(tmp);
}


TEST(Creation, CreateNode_TEST)
{
	char str[] = "A A A";
	/*char* str2 = (char*)malloc(strlen(str1));
	ASSERT_NE(str2, nullptr);
	strcpy(str2, str1);*/
	list_people_t* tmp = nullptr;
	tmp = CreateNode(tmp, str);
	ASSERT_NE(tmp, nullptr);
	EXPECT_EQ(tmp->next, nullptr);
	free(tmp);
}


TEST(WriteInfo, CreateNode_TEST)
{
	char* str1 = "A B C";
	char str[BUF_SIZE];
	strcpy(str, str1); 
	//char str[] = "A B C";
	list_people_t* tmp = nullptr;
	tmp = CreateNode(tmp, str);
	EXPECT_EQ(*(tmp->name), 'A');
	EXPECT_EQ(*(tmp->surname), 'B');
	EXPECT_EQ(*(tmp->lastname), 'C');

	free(tmp);
}


TEST(WriteNothing, CreateNode_TEST)
{
	char* str = nullptr;
	list_people_t* tmp = nullptr;
	tmp = CreateNode(tmp, str);
	EXPECT_EQ(tmp, nullptr);

	free(tmp);
}


TEST(RightPlace, SearchPlace_TEST)
{
	char* name1 = "A";
	char* surname1 = "A";
	char* lastname1 = "A";

	char* name2 = "A";
	char* surname2 = "A";
	char* lastname2 = "B";

	char* name3 = "A";
	char* surname3 = "D";
	char* lastname3 = "D";

	char* str1 = "A A C";
	char str[BUF_SIZE];
	strcpy(str, str1);

	list_people_t* s = (list_people_t*)malloc(sizeof(list_people_t));
	ASSERT_NE(s, nullptr);
	list_people_t* node1 = (list_people_t*)malloc(sizeof(list_people_t));
	ASSERT_NE(node1, nullptr);
	list_people_t* node2 = (list_people_t*)malloc(sizeof(list_people_t));
	ASSERT_NE(node2, nullptr);
	list_people_t* node3 = (list_people_t*)malloc(sizeof(list_people_t));
	ASSERT_NE(node3, nullptr);
	list_people_t* end = nullptr;

	s->next = node1;

	node1->name = name1;
	node1->surname = surname1;
	node1->lastname = lastname1;
	node1->next = node2;

	node2->name = name2;
	node2->surname = surname2;
	node2->lastname = lastname2;
	node2->next = node3;

	node3->name = name3;
	node3->surname = surname3;
	node3->lastname = lastname3;
	node3->next = end;

	list_people_t* newplace = SearchPlace(s, str);
	EXPECT_EQ(newplace, node2);

	
	free(node3);
	free(node2);
	free(node1);
	free(s);
}


TEST(EmptyList, SearchPlace_TEST)
{
	list_people_t* s = (list_people_t*)malloc(sizeof(list_people_t));
	s->next = NULL;
	char str[] = "Andrey Andreev Andreevich";
	list_people_t* newplace = SearchPlace(s, str);
	EXPECT_EQ(newplace, s);
	free(s);
}


TEST(SearchByNameSurnameLastname, FindPeople_TEST)
{
	char* name1 = "A";
	char* surname1 = "A";
	char* lastname1 = "A";

	char* name2 = "A";
	char* surname2 = "A";
	char* lastname2 = "B";

	char* name3 = "A";
	char* surname3 = "D";
	char* lastname3 = "D";

	char* str1 = "<A><A><A>";
	char str[BUF_SIZE];
	strcpy(str, str1); 

	list_people_t* s = (list_people_t*)malloc(sizeof(list_people_t));
	ASSERT_NE(s, nullptr);
	list_people_t* node1 = (list_people_t*)malloc(sizeof(list_people_t));
	ASSERT_NE(node1, nullptr);
	list_people_t* node2 = (list_people_t*)malloc(sizeof(list_people_t));
	ASSERT_NE(node2, nullptr);
	list_people_t* node3 = (list_people_t*)malloc(sizeof(list_people_t));
	ASSERT_NE(node3, nullptr);
	list_people_t* end = NULL;

	s->next = node1;

	node1->name = name1;
	node1->surname = surname1;
	node1->lastname = lastname1;
	node1->next = node2;

	node2->name = name2;
	node2->surname = surname2;
	node2->lastname = lastname2;
	node2->next = node3;

	node3->name = name3;
	node3->surname = surname3;
	node3->lastname = lastname3;
	node3->next = end;

	list_people_t* founded = FindPeople(s, str);
	EXPECT_EQ(founded->next->name, name1);
	EXPECT_EQ(founded->next->surname, surname1);
	EXPECT_EQ(founded->next->lastname, lastname1);

	free(node3);
	free(node2);
	free(node1);
	free(s);
	free(founded);
}


TEST(SearchOnlyByName, FindPeople_TEST)
{
	char* name1 = "A";
	char* surname1 = "A";
	char* lastname1 = "A";

	char* name2 = "A";
	char* surname2 = "A";
	char* lastname2 = "B";

	char* name3 = "D";
	char* surname3 = "D";
	char* lastname3 = "D";

	char* str1 = "<A>< >< >";
	/*char* str = (char*)malloc(sizeof(str1));
	ASSERT_NE(str, nullptr);*/
	char str[BUF_SIZE];
	strcpy(str, str1);

	list_people_t* s = (list_people_t*)malloc(sizeof(list_people_t));
	ASSERT_NE(s, nullptr);
	list_people_t* node1 = (list_people_t*)malloc(sizeof(list_people_t));
	ASSERT_NE(node1, nullptr);
	list_people_t* node2 = (list_people_t*)malloc(sizeof(list_people_t));
	ASSERT_NE(node2, nullptr);
	list_people_t* node3 = (list_people_t*)malloc(sizeof(list_people_t));
	ASSERT_NE(node3, nullptr);
	list_people_t* end = NULL;

	s->next = node1;

	node1->name = name1;
	node1->surname = surname1;
	node1->lastname = lastname1;
	node1->next = node2;

	node2->name = name2;
	node2->surname = surname2;
	node2->lastname = lastname2;
	node2->next = node3;

	node3->name = name3;
	node3->surname = surname3;
	node3->lastname = lastname3;
	node3->next = end;

	list_people_t* founded = FindPeople(s, str);
	EXPECT_EQ(founded->next->name, name2);
	EXPECT_EQ(founded->next->surname, surname2);
	EXPECT_EQ(founded->next->lastname, lastname2);
	EXPECT_EQ(founded->next->next->name, name1);
	EXPECT_EQ(founded->next->next->surname, surname1);
	EXPECT_EQ(founded->next->next->lastname, lastname1);


	free(node3);
	free(node2);
	free(node1);
	free(s);
	free(founded->next->next);
	free(founded->next);
	free(founded);
}


TEST(SearchByEmptyStr, FindPeople_TEST)
{
	char* name1 = "A";
	char* surname1 = "A";
	char* lastname1 = "A";

	char* name2 = "A";
	char* surname2 = "A";
	char* lastname2 = "B";

	char* name3 = "D";
	char* surname3 = "D";
	char* lastname3 = "D";

	char* str1 = "< >< >< >";
	/*char* str = (char*)malloc(sizeof(str1));
	ASSERT_NE(str, nullptr);*/
	char str[BUF_SIZE];
	strcpy(str, str1);

	list_people_t* s = (list_people_t*)malloc(sizeof(list_people_t));
	ASSERT_NE(s, nullptr);
	list_people_t* node1 = (list_people_t*)malloc(sizeof(list_people_t));
	ASSERT_NE(node1, nullptr);
	list_people_t* node2 = (list_people_t*)malloc(sizeof(list_people_t));
	ASSERT_NE(node2, nullptr);
	list_people_t* node3 = (list_people_t*)malloc(sizeof(list_people_t));
	ASSERT_NE(node3, nullptr);
	list_people_t* end = NULL;

	s->next = node1;

	node1->name = name1;
	node1->surname = surname1;
	node1->lastname = lastname1;
	node1->next = node2;

	node2->name = name2;
	node2->surname = surname2;
	node2->lastname = lastname2;
	node2->next = node3;

	node3->name = name3;
	node3->surname = surname3;
	node3->lastname = lastname3;
	node3->next = end;

	list_people_t* founded = FindPeople(s, str);
	EXPECT_EQ(founded->next->name, name3);
	EXPECT_EQ(founded->next->surname, surname3);
	EXPECT_EQ(founded->next->lastname, lastname3);
	EXPECT_EQ(founded->next->next->name, name2);
	EXPECT_EQ(founded->next->next->surname, surname2);
	EXPECT_EQ(founded->next->next->lastname, lastname2);
	EXPECT_EQ(founded->next->next->next->name, name1);
	EXPECT_EQ(founded->next->next->next->surname, surname1);
	EXPECT_EQ(founded->next->next->next->lastname, lastname1);


	free(node3);
	free(node2);
	free(node1);
	free(s);
	//free(str);
	free(founded->next->next);
	free(founded->next);
	free(founded);
}


TEST(AddingNewNodeAfter, AddToList_TEST)
{
	list_people_t* first = (list_people_t*)malloc(sizeof(list_people_t));
	list_people_t* second = (list_people_t*)malloc(sizeof(list_people_t));
	list_people_t* newNode = (list_people_t*)malloc(sizeof(list_people_t));
	first->next = second;
	int chek = AddToList(first, newNode);
	EXPECT_EQ(chek, 1);
	EXPECT_EQ(first->next, newNode);
	EXPECT_EQ(newNode->next, second);
	free(second);
	free(newNode);
	free(first);
}


TEST(EmptyList, AddToList_TEST)
{
	list_people_t* first = NULL;
	list_people_t* newNode = (list_people_t*)malloc(sizeof(list_people_t));
	int chek = AddToList(first, newNode);
	EXPECT_EQ(chek, -1);
	free(newNode);
}

/*
int main(int argc, char ** argv)
{
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
*/
