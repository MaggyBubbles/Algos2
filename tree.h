#include <stdlib.h>
#include <stdio.h>

struct tnode{
int key;
struct tnode* left;
struct tnode* right;
};

char filename[50] = "tree.txt";

void treecheck(char filename[]);
struct tnode* insertion(int key, struct tnode* tree);
struct tnode* getTreeFromFile(struct tnode* tree, char filename[]);
void traverseTree(struct tnode* tree);
int heightOfNode(struct tnode* tree);
int findMin(struct tnode* tree);
int findMax(struct tnode* tree);
