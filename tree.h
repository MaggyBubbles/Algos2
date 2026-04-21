#include <stdlib.h>
#include <stdio.h>

struct tnode{
int key;
struct tnode* left;
struct tnode* right;
};

char filename[50] = "tree.txt";
int avl = 1; //wir gehen davon aus, dass es ein avl tree ist, bis eine violation stttfindet

void treecheck(char filename[]);
struct tnode* insertion(int key, struct tnode* tree);
struct tnode* getTreeFromFile(struct tnode* tree, char filename[]);
void traverseTree(struct tnode* tree);
int heightOfNode(struct tnode* tree);
int findMin(struct tnode* tree);
int findMax(struct tnode* tree);
int findSum(struct tnode* tree);
int countEntries(struct tnode* tree);
int heightAndBalance(struct tnode* tree);
