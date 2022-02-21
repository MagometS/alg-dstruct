#ifdef __cplusplus
extern "C" {
#endif

#pragma warning (disable:4996)
#include <stdio.h>
#include <stdlib.h>

    typedef struct tree 
    {
        int number;
        int key;
        struct tree* left;
        struct tree* right;
    }tree_t;

    tree_t* CreateTree(int key);
    void DeleteTree(tree_t* myTree);
    int AddElement(tree_t* myTree, int key);
    tree_t* MinimumK(tree_t* myTree, int k);
    void PrintLesser(tree_t* myTree, int key, FILE* file);
    void PrintTree(tree_t* myTree);
    void PrintMinimumK(tree_t* myTree, int k, FILE* file);
    tree_t* ReadFile(FILE* file);
    void LabSolution(FILE* input, FILE* output, int k);

#ifdef __cplusplus
}
#endif 