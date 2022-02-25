#include "labF.h"


tree_t* CreateTree(int key) 
{
	tree_t* myTree = (tree_t*)malloc(sizeof(tree_t));
	if (myTree == NULL)
	{
		return NULL;
	}
	myTree->key = key;
	myTree->left = myTree->right = NULL;
	myTree->number = 1;
	return myTree;
}


void DeleteTree(tree_t* myTree)
{
	if (myTree == NULL)
	{
		return;
	}
	DeleteTree(myTree->left);
	DeleteTree(myTree->right);
	free(myTree);
	return;
}


int AddElement(tree_t* myTree, int key) 
{
	int flag = 0;
	if (myTree == NULL)
	{
		return 0;
	}
	if (key < myTree->key) 
	{
		if (myTree->left == NULL)
		{
			myTree->left = CreateTree(key);
			if (myTree->left)
			{
				myTree->number++;
				flag = 1;
			}
		}
		else 
		{
			flag = AddElement(myTree->left, key);
			if (flag)
			{
				myTree->number++;
			}
		}
	}
	if (key > myTree->key) 
	{
		if (myTree->right == NULL)
		{
			myTree->right = CreateTree(key);
			if (myTree->right) 
			{
				myTree->number++;
				flag = 1;
			}
		}
		else
		{
			flag = AddElement(myTree->right, key);
			if (flag)
			{
				myTree->number++;
			}
		}
	}
	return flag;
}


tree_t* MinimumK(tree_t* myTree, int k) 
{
	int r;
	if (myTree == NULL)
	{
		return NULL;
	}
	if (myTree->left)
	{
		r = myTree->left->number + 1;
	}
	else
	{
		r = 1;
	}
	if (r != k)
	{
		if (r > k)
		{
			myTree = MinimumK(myTree->left, k);
		}
		else
		{
			myTree = MinimumK(myTree->right, k - r);
		}
	}
	return myTree;
}


void PrintLesser(tree_t* myTree, int key, FILE* file) 
{
	if (myTree == NULL)
	{
		return;
	}
	PrintLesser(myTree->left, key, file);
	if (myTree->key < key) 
	{
		fprintf(file, "%i ", myTree->key);
		PrintLesser(myTree->right, key, file);
	}
	return;
}


void PrintTree(tree_t* myTree) 
{
	if (myTree == NULL)
	{
		return;
	}
	printf("%i ", myTree->key);
	if (myTree->left)
	{
		PrintTree(myTree->left);
	}
	if (myTree->right)
	{
		PrintTree(myTree->right);
	}
}


void PrintMinimumK(tree_t* myTree, int k, FILE* file) 
{
	tree_t* tmpTree = MinimumK(myTree, k);
	if (tmpTree == NULL)
	{
		return;
	}
	if (tmpTree->key % 2 == 0) 
	{
		PrintLesser(myTree, tmpTree->key, file);
	}
	else
	{
		fprintf(file, "%i", tmpTree->key);
	}
	return;
}


tree_t* ReadFile(FILE* file)
{
	int key = -1;
	tree_t* myTree = NULL;
	fscanf(file, "%i", &key);
	if (key == -1)
	{
		return NULL;
	}
	myTree = CreateTree(key);
	if (myTree == NULL)
	{
		return NULL;
	}
	while (fscanf(file, "%i", &key) != EOF)
	{
		if (!AddElement(myTree, key))
		{
			return myTree;
		}
	}
	return myTree;
}


void LabSolution(FILE* input, FILE* output, int k) 
{
	tree_t* myTree = ReadFile(input);
	if (myTree == NULL)
	{
		return;
	}
	PrintMinimumK(myTree, k, output);
	DeleteTree(myTree);
	return;
}