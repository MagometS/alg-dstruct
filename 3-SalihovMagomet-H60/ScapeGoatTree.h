#include "stdio.h"
#include "stdbool.h"

typedef struct node
{
	struct node* parent;
	struct node* left;
	struct node* right;
	int val;

}node_t;


typedef struct scapeGoat
{
	node_t* root;
	int size;
	int maxSize;

}scapeGoat_t;


void Init(scapeGoat_t* tree);
scapeGoat_t* Insert(scapeGoat_t* tree, int x);
node_t* Search(node_t* r, int val);
scapeGoat_t* Delete(scapeGoat_t* tree, int key);
void Preorder(node_t* node);



void CreateNode(node_t* node);
void DestroyNode(node_t* node);
void DestroyTree(node_t* node);
int PackIntoArray(node_t* node, node_t* a[], int i);
node_t* BuildBalanced(node_t** a, int i, int ns);
int Size(node_t* r);
int AddWithDepth(scapeGoat_t* tree, node_t* u);
void Rebuild(scapeGoat_t* tree, node_t* u);
node_t* minValueNode(node_t* node);


