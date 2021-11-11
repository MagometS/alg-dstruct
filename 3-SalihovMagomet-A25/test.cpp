#define _CRT_SECURE_NO_WARNINGS
#include "pch.h"
#include "info.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <gtest/gtest.h>



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
	list_people_t* tmp = CreateNode(str);
	ASSERT_NE(tmp, nullptr);
	EXPECT_EQ(tmp->next, nullptr);
	free(tmp->name);
	free(tmp->surname);
	free(tmp->lastname);
	free(tmp);
}


TEST(WriteInfo, CreateNode_TEST)
{
	char* str1 = "A B C";
	char str[BUF_SIZE];
	strcpy(str, str1); 
	//char str[] = "A B C";
	
	list_people_t* tmp = CreateNode(str);
	ASSERT_NE(tmp, nullptr);
	EXPECT_STREQ(tmp->name, "A");
	EXPECT_STREQ(tmp->surname, "B");
	EXPECT_STREQ(tmp->lastname, "C");

	free(tmp->name);
	free(tmp->surname);
	free(tmp->lastname);
	free(tmp);
}


TEST(WriteNothing, CreateNode_TEST)
{
	char* str = nullptr;
	list_people_t* tmp = CreateNode(str);
	EXPECT_EQ(tmp, nullptr);

	free(tmp);
}


TEST(DifferentNames, SearchPlace_TEST)
{
	char* name1 = "Aaa";
	char* surname1 = "Abc";
	char* lastname1 = "Abc";

	char* name2 = "Aab";
	char* surname2 = "Abc";
	char* lastname2 = "Abc";

	char* name3 = "Bcd";
	char* surname3 = "Abc";
	char* lastname3 = "Abc";

	char* str1 = "Aba Abc Abc";
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


TEST(DifferentSurnames, SearchPlace_TEST)
{
	char* name1 = "Abc";
	char* surname1 = "Aaa";
	char* lastname1 = "Abc";

	char* name2 = "Abc";
	char* surname2 = "Aab";
	char* lastname2 = "Abc";

	char* name3 = "Abc";
	char* surname3 = "Abc";
	char* lastname3 = "Abc";

	char* str1 = "Abc Aba Abc";
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


TEST(DifferentLastnames, SearchPlace_TEST)
{
	char* name1 = "Abc";
	char* surname1 = "Abc";
	char* lastname1 = "Aaa";

	char* name2 = "Abc";
	char* surname2 = "Abc";
	char* lastname2 = "Aab";

	char* name3 = "Abc";
	char* surname3 = "Abc";
	char* lastname3 = "Abc";

	char* str1 = "Abc Abc Aba";
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


TEST(EverythingIsDifferent, SearchPlace_TEST)
{
	char* name1 = "Aaandrey";
	char* surname1 = "Abc";
	char* lastname1 = "Aaa";

	char* name2 = "Abc";
	char* surname2 = "Abc";
	char* lastname2 = "Aab";

	char* name3 = "Abc";
	char* surname3 = "Abd";
	char* lastname3 = "Abc";

	char* str1 = "Abc Abd Aba";
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
	char* name1 = "Abc";
	char* surname1 = "Abc";
	char* lastname1 = "Abc";

	char* name2 = "Andrey";
	char* surname2 = "Andreyev";
	char* lastname2 = "Barb";

	char* name3 = "Arrar";
	char* surname3 = "Abakan";
	char* lastname3 = "Diablo";

	char* str1 = "<A><Ab><Abc>";
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
	ASSERT_NE(founded, nullptr);
	EXPECT_EQ(founded->next->next, nullptr);
	EXPECT_STREQ(founded->next->name, name1);
	EXPECT_STREQ(founded->next->surname, surname1);
	EXPECT_STREQ(founded->next->lastname, lastname1);

	free(node3);
	free(node2);
	free(node1);
	free(s);
	free(founded->next->name);
	free(founded->next->surname);
	free(founded->next->lastname);
	free(founded->next);
	free(founded);
}


TEST(SearchOnlyByName, FindPeople_TEST)
{
	char* name1 = "Andrey";
	char* surname1 = "Amphetaminiy";
	char* lastname1 = "Amphibrahov";

	char* name2 = "Antonio";
	char* surname2 = "Anapest";
	char* lastname2 = "Biridov";

	char* name3 = "Adron";
	char* surname3 = "Darkiy";
	char* lastname3 = "Darkov";

	char* str1 = "<An>< >< >";
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
	ASSERT_NE(founded, nullptr);
	EXPECT_EQ(founded->next->next->next, nullptr);
	EXPECT_STREQ(founded->next->name, name2);
	EXPECT_STREQ(founded->next->surname, surname2);
	EXPECT_STREQ(founded->next->lastname, lastname2);
	EXPECT_STREQ(founded->next->next->name, name1);
	EXPECT_STREQ(founded->next->next->surname, surname1);
	EXPECT_STREQ(founded->next->next->lastname, lastname1);

	free(node3);
	free(node2);
	free(node1);
	free(s);
	free(founded->next->next->name);
	free(founded->next->next->surname);
	free(founded->next->next->lastname);
	free(founded->next->next);
	free(founded->next->name);
	free(founded->next->surname);
	free(founded->next->lastname);
	free(founded->next);
	free(founded);
}


TEST(SearchOnlyBySurname, FindPeople_TEST)
{
	char* name1 = "Andrey";
	char* surname1 = "Anapetaminiy";
	char* lastname1 = "Amphibrahov";

	char* name2 = "Antonio";
	char* surname2 = "Anapest";
	char* lastname2 = "Biridov";

	char* name3 = "Adron";
	char* surname3 = "Darkiy";
	char* lastname3 = "Darkov";

	char* str1 = "< ><Anap>< >";
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
	ASSERT_NE(founded, nullptr);
	EXPECT_EQ(founded->next->next->next, nullptr);
	EXPECT_STREQ(founded->next->name, name2);
	EXPECT_STREQ(founded->next->surname, surname2);
	EXPECT_STREQ(founded->next->lastname, lastname2);
	EXPECT_STREQ(founded->next->next->name, name1);
	EXPECT_STREQ(founded->next->next->surname, surname1);
	EXPECT_STREQ(founded->next->next->lastname, lastname1);


	free(node3);
	free(node2);
	free(node1);
	free(s);
	free(founded->next->next->name);
	free(founded->next->next->surname);
	free(founded->next->next->lastname);
	free(founded->next->next);
	free(founded->next->name);
	free(founded->next->surname);
	free(founded->next->lastname);
	free(founded->next);
	free(founded);
}


TEST(SearchOnlyByLastname, FindPeople_TEST)
{
	char* name1 = "Andrey";
	char* surname1 = "Amphetaminiy";
	char* lastname1 = "Amphibrahov";

	char* name2 = "Antonio";
	char* surname2 = "Anapest";
	char* lastname2 = "Amphibrahov";

	char* name3 = "Adron";
	char* surname3 = "Darkiy";
	char* lastname3 = "Darkov";

	char* str1 = "< >< ><Amp>";
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
	ASSERT_NE(founded, nullptr);
	EXPECT_EQ(founded->next->next->next, nullptr);
	EXPECT_STREQ(founded->next->name, name2);
	EXPECT_STREQ(founded->next->surname, surname2);
	EXPECT_STREQ(founded->next->lastname, lastname2);
	EXPECT_STREQ(founded->next->next->name, name1);
	EXPECT_STREQ(founded->next->next->surname, surname1);
	EXPECT_STREQ(founded->next->next->lastname, lastname1);


	free(node3);
	free(node2);
	free(node1);
	free(s);
	free(founded->next->next->name);
	free(founded->next->next->surname);
	free(founded->next->next->lastname);
	free(founded->next->next);
	free(founded->next->name);
	free(founded->next->surname);
	free(founded->next->lastname);
	free(founded->next);
	free(founded);
}


TEST(SearchByCombination, FindPeople_TEST)
{
	char* name1 = "Andrey";
	char* surname1 = "Amphetaminiy";
	char* lastname1 = "Amphibrahov";

	char* name2 = "Antonio";
	char* surname2 = "Anapest";
	char* lastname2 = "Amphibrahov";

	char* name3 = "Adron";
	char* surname3 = "Darkiy";
	char* lastname3 = "Darkov";

	char* str1 = "<A>< ><Amp>";
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
	ASSERT_NE(founded, nullptr);
	EXPECT_EQ(founded->next->next->next, nullptr);
	EXPECT_STREQ(founded->next->name, name2);
	EXPECT_STREQ(founded->next->surname, surname2);
	EXPECT_STREQ(founded->next->lastname, lastname2);
	EXPECT_STREQ(founded->next->next->name, name1);
	EXPECT_STREQ(founded->next->next->surname, surname1);
	EXPECT_STREQ(founded->next->next->lastname, lastname1);


	free(node3);
	free(node2);
	free(node1);
	free(s);
	free(founded->next->next->name);
	free(founded->next->next->surname);
	free(founded->next->next->lastname);
	free(founded->next->next);
	free(founded->next->name);
	free(founded->next->surname);
	free(founded->next->lastname);
	free(founded->next);
	free(founded);
}


TEST(NothingToFound, FindPeople_TEST)
{
	char* name1 = "Andrey";
	char* surname1 = "Amphetaminiy";
	char* lastname1 = "Ahibrahov";

	char* name2 = "Antonio";
	char* surname2 = "Anapest";
	char* lastname2 = "Ahibrahov";

	char* name3 = "Adron";
	char* surname3 = "Darkiy";
	char* lastname3 = "Darkov";

	char* str1 = "<A>< ><Amp>";
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
	ASSERT_NE(founded, nullptr);
	EXPECT_EQ(founded->next, nullptr);


	free(node3);
	free(node2);
	free(node1);
	free(s);
	free(founded);
}


TEST(SearchByEmptyStr, FindPeople_TEST)
{
	char* name1 = "Axcv";
	char* surname1 = "Axcb";
	char* lastname1 = "Axcvb";

	char* name2 = "Axc";
	char* surname2 = "Axcv";
	char* lastname2 = "Bbv";

	char* name3 = "Dxcv";
	char* surname3 = "Dbvc";
	char* lastname3 = "Dxcv";

	char* str1 = "< >< >< >";
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
	ASSERT_NE(founded, nullptr);
	EXPECT_EQ(founded->next->next->next->next, nullptr);
	EXPECT_STREQ(founded->next->name, name3);
	EXPECT_STREQ(founded->next->surname, surname3);
	EXPECT_STREQ(founded->next->lastname, lastname3);
	EXPECT_STREQ(founded->next->next->name, name2);
	EXPECT_STREQ(founded->next->next->surname, surname2);
	EXPECT_STREQ(founded->next->next->lastname, lastname2);
	EXPECT_STREQ(founded->next->next->next->name, name1);
	EXPECT_STREQ(founded->next->next->next->surname, surname1);
	EXPECT_STREQ(founded->next->next->next->lastname, lastname1);


	free(node3);
	free(node2);
	free(node1);
	free(s);
	free(founded->next->next->next->name);
	free(founded->next->next->next->surname);
	free(founded->next->next->next->lastname);
	free(founded->next->next->next);
	free(founded->next->next->name);
	free(founded->next->next->surname);
	free(founded->next->next->lastname);
	free(founded->next->next);
	free(founded->next->name);
	free(founded->next->surname);
	free(founded->next->lastname);
	free(founded->next);
	free(founded);
}


TEST(AddingNewNodeAfter, AddToList_TEST)
{
	list_people_t* first = (list_people_t*)malloc(sizeof(list_people_t));
	ASSERT_NE(first, nullptr);
	list_people_t* second = (list_people_t*)malloc(sizeof(list_people_t));
	ASSERT_NE(second, nullptr);
	list_people_t* newNode = (list_people_t*)malloc(sizeof(list_people_t));
	ASSERT_NE(newNode, nullptr);
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
	ASSERT_NE(newNode, nullptr);
	int chek = AddToList(first, newNode);
	EXPECT_EQ(chek, -1);
	free(newNode);
}


TEST(ReadFromFile, FileToList_TEST)
{
	FILE* fp;
	char buf[BUF_SIZE];


	fp = fopen("People.txt", "w");
	ASSERT_NE(fp, nullptr);
	char* words = "Abc Abc Abc \nCde Abc Abc \nBcd Abc Abc";
	fputs(words, fp);
	fclose(fp);

	char* filename = "People.txt";
	list_people_t* s = FileToList(filename);
	ASSERT_NE(s, nullptr);
	EXPECT_STREQ(s->next->name, "Abc");
	EXPECT_STREQ(s->next->surname, "Abc");
	EXPECT_STREQ(s->next->lastname, "Abc");
	EXPECT_STREQ(s->next->next->name, "Bcd");
	EXPECT_STREQ(s->next->next->surname, "Abc");
	EXPECT_STREQ(s->next->next->lastname, "Abc");
	EXPECT_STREQ(s->next->next->next->name, "Cde");
	EXPECT_STREQ(s->next->next->next->surname, "Abc");
	EXPECT_STREQ(s->next->next->next->lastname, "Abc");
	EXPECT_EQ(s->next->next->next->next, nullptr);
	
	free(s->next->next->next->name);
	free(s->next->next->next->surname);
	free(s->next->next->next->lastname);
	free(s->next->next->next);
	free(s->next->next->name);
	free(s->next->next->surname);
	free(s->next->next->lastname);
	free(s->next->next);
	free(s->next->name);
	free(s->next->surname);
	free(s->next->lastname);
	free(s->next);
	free(s);

}


TEST(ReadFromEmptyFile, FileToList_TEST)
{
	FILE* fp;


	fp = fopen("People.txt", "w");
	ASSERT_NE(fp, nullptr);
	fclose(fp);

	char* filename = "People.txt";
	list_people_t* s = FileToList(filename);
	ASSERT_NE(s, nullptr);
	EXPECT_EQ(s->next, nullptr);
	free(s);
}


TEST(NonExistentFile, FileToList_TEST)
{

	char* filename = "People7.txt";
	list_people_t* s = FileToList(filename);
	EXPECT_EQ(s, nullptr);
}


/*
int main(int argc, char ** argv)
{
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
*/
