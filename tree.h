#include <stdlib.h>
#include <stdio.h>

struct tnode{
int key;
struct tnode* left;
struct tnode* right;
};

char filename[50] = "tree.txt";
int avl = 1; //wir gehen davon aus, dass es ein avl tree ist, bis eine violation stattfindet

void treecheck(char filename[]);
struct tnode* insertion(int key, struct tnode* tree);
struct tnode* getTreeFromFile(struct tnode* tree, char filename[]);
int findMin(struct tnode* tree);
int findMax(struct tnode* tree);
int findSum(struct tnode* tree);
int countEntries(struct tnode* tree);
int heightAndBalance(struct tnode* tree);
int searchKey(struct tnode* tree, int key); //added
int searchKeyHelper(struct tnode* tree, int key, int path[], int depth);
int isSameTree(struct tnode* a, struct tnode* b);
int searchSubtree(struct tnode* tree, struct tnode* subtree);