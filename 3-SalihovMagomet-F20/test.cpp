#include "pch.h"
#include "labF.h"

TEST(FunctionalTest, MinimumK_Even) 
{
	FILE * input = fopen("input.txt", "r");
	ASSERT_TRUE(input);
	FILE* output = fopen("outputEven.txt", "w");
	ASSERT_TRUE(output);
	LabSolution(input, output, 6);
	fclose(input);
	fclose(output);
	int keyExpected, keyOutput;
	int i = 1;
	FILE* expected = fopen("expectedEven.txt", "r");
	ASSERT_TRUE(expected);
	output = fopen("outputEven.txt", "r");
	ASSERT_TRUE(output);
	fseek(output, 0, SEEK_END);
	fseek(expected, 0, SEEK_END);
	EXPECT_EQ(ftell(output), ftell(expected));
	fseek(output, 0, SEEK_SET);
	fseek(expected, 0, SEEK_SET);
	while (fscanf(output, "%i", &keyOutput) != EOF && fscanf(expected, "%i", &keyExpected) != EOF)
	{
		EXPECT_EQ(keyExpected, keyOutput);
	}
	fclose(output);
	fclose(expected);
}


TEST(FunctionalTest, MinimumK_Odd) 
{
	FILE* input = fopen("input.txt", "r");
	ASSERT_TRUE(input);
	FILE* output = fopen("outputOdd.txt", "w");
	ASSERT_TRUE(output);
	LabSolution(input, output, 7);
	fclose(input);
	fclose(output);
	int key;
	int i = 0;
	output = fopen("outputOdd.txt", "r");
	ASSERT_TRUE(output);
	fseek(output, 0, SEEK_END);
	i = ftell(output);
	EXPECT_EQ(i, 1);
	fseek(output, 0, SEEK_SET);
	fscanf(output, "%i", &key);
	EXPECT_EQ(9, key);
	fclose(output);
}


TEST(FunctionalTest, NotFound) 
{
	FILE* input = fopen("input.txt", "r");
	ASSERT_TRUE(input);
	FILE* output = fopen("outputNotFound.txt", "w");
	ASSERT_TRUE(output);
	LabSolution(input, output, 10);
	fclose(input);
	fclose(output);
	int key;
	int i = 0;
	output = fopen("outputNotFound.txt", "r");
	ASSERT_TRUE(output);
	fseek(output, 0, SEEK_END);
	i = ftell(output);
	EXPECT_EQ(i, 0);
	fclose(output);
}


TEST(EmptyFile, LabSolution_TEST)
{
	FILE* input = fopen("empty.txt", "r");
	ASSERT_TRUE(input);
	FILE* output = fopen("outputEmpty.txt", "w");
	ASSERT_TRUE(output);
	LabSolution(input, output, 6);
	fclose(input);
	fclose(output);
	output = fopen("outputEmpty.txt", "r");
	ASSERT_TRUE(output);
	fseek(output, 0, SEEK_END);
	int i = 0;
	i = ftell(output);
	EXPECT_EQ(i, 0);
	fclose(output);
}
