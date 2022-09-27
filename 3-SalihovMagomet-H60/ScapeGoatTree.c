#include "ScapeGoatTree.h"

void Init(scapeGoat_t* tree)
{
    tree = (scapeGoat_t*)malloc(sizeof(scapeGoat_t));
    tree->root = NULL;
    tree->size = 0;
    tree->maxSize = 0;
}


void DestroyNode(node_t* node)
{
    free(node);
}


void DestroyTree(node_t* node)
{
    if (node == NULL)
    {
        return;
    }

    if (node->left != NULL)
    {
        DestroyTree(node->left);
    }

    if (node->right != NULL)
    {
        DestroyTree(node->right);
    }

    free(node);
}


int Size(node_t* r)
{
    if (r == NULL)
        return 0;
    else
    {
        int l = 1;
        l += Size(r->left);
        l += Size(r->right);
        return l;
    }
}


int PackIntoArray(node_t* node, node_t* a[], int i)
{
    if (node == NULL)
    {
        return i;
    }

    i = PackIntoArray(node->left, a, i);
    a[i++] = node;

    return PackIntoArray(node->right, a, i);
}


node_t* BuildBalanced(node_t** a, int i, int ns)
{
    if (ns == 0)
    {
        return NULL;
    }

    int m = ns / 2;
    a[i + m]->left = BuildBalanced(a, i, m);

    if (a[i + m]->left != NULL)
    {
        a[i + m]->left->parent = a[i + m];
    }

    a[i + m]->right = BuildBalanced(a, i + m + 1, ns - m - 1); 

        if (a[i + m]->right != NULL)
        {
            a[i + m]->right->parent = a[i + m];
        }

    return a[i + m];
}


int AddWithDepth(scapeGoat_t* tree, node_t* u)
{
    node_t* w = tree->root;
    if (w == NULL)
    {
        tree->root = u;
        tree->size++;
        tree->maxSize++;

        return 0;
    }

    bool done = 0;
    int d = 0;
    do
    {
        if (u->val < w->val)
        {
            if (w->left == NULL)
            {
                w->left = u;
                u->parent = w;
                done = 1;
            }
            else
            {
                w = w->left;
            }
        }
        else if (u->val > w->val)
        {
            if (w->right == NULL)
            {
                w->right = u;
                u->parent = w;
                done = 1;
            }
            else
            {
                w = w->right;
            }
        }
        else
            return -1;
        d++;
    } while (!done);

    tree->size++;
    tree->maxSize++;

    return d;
}


void Rebuild(scapeGoat_t* tree, node_t* u)
{
    int ns = Size(u);

    node_t* p = u->parent;
    node_t** a = (node_t**)malloc(sizeof(node_t*) * ns);
    if (a == NULL)
    {
        return;
    }
    PackIntoArray(u, a, 0);
    if (p == NULL)
    {
        tree->root = BuildBalanced(a, 0, ns);
        tree->root->parent = NULL;
    }
    else if (p->right == u)
    {
        p->right = BuildBalanced(a, 0, ns);
        p->right->parent = p;
    }
    else
    {
        p->left = BuildBalanced(a, 0, ns);
        p->left->parent = p;
    }
}


static int const Log32(int q)
{
    double const log23 = 2.4663034623764317;
    return (int)ceil(log23 * log(q));
}


scapeGoat_t* Insert(scapeGoat_t* tree, int x)
{
    node_t* u = (node_t*)malloc(sizeof(node_t));
    if (u == NULL)
    {
        return tree;
    }
    u->val = x;
    u->parent = NULL;
    u->left = NULL;
    u->right = NULL;

    int d = AddWithDepth(tree,u);
    if (d > Log32(tree->maxSize))
    {
        node_t* w = u->parent;
        while (3 * Size(w) <= 2 * Size(w->parent))
        {
            w = w->parent;
        }
        Rebuild(tree, w->parent);
    }
    return tree;
}


node_t* Search(node_t* r, int val)
{
    node_t* found = NULL;
    while ((r != NULL) && !found)
    {
        int rval = r->val;
        if (val < rval)
            r = r->left;
        else if (val > rval)
            r = r->right;
        else
        {
            found = r;
            break;
        }
        found = Search(r, val);
    }
    return found;
}


void CreateNode(node_t* node, int val)
{
    node_t* tmp = malloc(sizeof(node_t));
    node = tmp;
    node->parent = NULL;
    node->left = NULL;
    node->right = NULL;
    node->val = val;
}


void Preorder(node_t* node)
{
    if (node != NULL)
    {
        printf("%d ", node->val);
        Preorder(node->left);
        Preorder(node->right);
    }
}


scapeGoat_t* Delete(scapeGoat_t* tree, int key)
{
    node_t* curr = tree->root;
    node_t* prev = NULL;

    while (curr != NULL && curr->val != key) 
    {
        prev = curr;
        if (key < curr->val)
            curr = curr->left;
        else
            curr = curr->right;
    }

    if (curr == NULL)
    {
        return tree;
    }

    if (curr->left == NULL || curr->right == NULL)
    {

        node_t* newCurr;

        if (curr->left == NULL)
            newCurr = curr->right;
        else
            newCurr = curr->left;

        if (prev == NULL)
            return newCurr;

        if (curr == prev->left)
            prev->left = newCurr;
        else
            prev->right = newCurr;
        free(curr);
    }
    else 
    {
        node_t* p = NULL;
        node_t* temp;

        temp = curr->right;
        while (temp->left != NULL) {
            p = temp;
            temp = temp->left;
        }
        if (p != NULL)
            p->left = temp->right;
        else
            curr->right = temp->right;

        curr->val = temp->val;
        free(temp);
    }

    Rebuild(tree, tree->root);
    return tree;
}


node_t* minValueNode(node_t* node)
{
    struct node* current = node;

    while (current && current->left != NULL)
        current = current->left;

    return current;
}