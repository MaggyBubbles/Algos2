#include <stdlib.h>
#include <stdio.h>

struct tnode{
int key;
struct tnode* left;
struct tnode* right;
};

FILE* file;
char filename[50] = "tree.txt";

struct tnode* insertion(int key, struct tnode* tree);
struct tnode* getTreeFromFile(struct tnode* tree, char filename[]);
int calcBalance(int left, int right);
void traverseTree(struct tnode* tree);
int heightOfNode(struct tnode* tree);
