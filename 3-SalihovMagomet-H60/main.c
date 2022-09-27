#include "ScapeGoatTree.h"


int main()
{

	scapeGoat_t tree;
    tree.root = NULL;
    tree.size = 0;
    tree.maxSize = 0;


   // Init(tree);    
    Insert(&tree, 34);
    Insert(&tree, 67);
    Insert(&tree, 11);
    Insert(&tree, 24);
    Insert(&tree, 6);
    Insert(&tree, 97);
    Insert(&tree, 12);
    Insert(&tree, 57);

    printf("sCAPE gOAT tEST\n");
    Preorder(tree.root);
    char ch;
    int val;
/*
    do
    {
        int choice = getchar();
        switch (choice)
        {
        case 1:
            val = getchar();
            Insert(&tree, val);
            break;
        
        }

        ch = getchar();
    } while (ch == 'Y' || ch == 'y');
    */


	return 0;
}