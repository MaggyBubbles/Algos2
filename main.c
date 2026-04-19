#include <stdio.h>
#include <stdlib.h>
#include "tree.h"
#include <limits.h> //für INT_MAX

int main()
{
    //struct tnode* tree = NULL;
    printf("Enter file name:\n");
    scanf("%49s", &filename[0]);
    treecheck(filename);
//    tree = getTreeFromFile(tree, filename); //legt den binary tree an
//    traverseTree(tree);
//    int min = 0;
//    min = findMin(tree);
//    printf("min: %d\n", min);

    return 0;
}

void treecheck(char filename[])
{
    struct tnode* tree = NULL;
    tree = getTreeFromFile(tree, filename); //legt den binary tree an
    traverseTree(tree);
    int min = findMin(tree);
    printf("min: %d, ", min);
    int max = findMax(tree);
    printf("max: %d, ", max);
}

struct tnode* insertion(int key, struct tnode* tree)
{
    if (tree == NULL)
    {
        tree = (struct tnode *)malloc(sizeof(struct tnode));
        tree->key=key;
        tree->left=NULL;
        tree->right=NULL;
    }
    else
    {
        if (key < tree->key)
        {
            tree->left=insertion(key,tree->left);
        }
        else if(key > tree->key)
        {
            tree->right=insertion(key,tree->right);
        }
    }
    return tree;
}

struct tnode* getTreeFromFile(struct tnode* tree, char filename[])
{
    FILE* file;
    file = fopen(filename, "r"); //Open to read
    if(file == NULL)
    {
        printf("Error opening file\n");
    }
    else
    {
        int x;
        while(fscanf(file, "%d\n", &x) == 1)//solange 1 Element gefunden wird, wird die Datei ausgelesen
        {
            tree = insertion(x, tree); //hier findet das Einfügen in den binary tree statt
        }
        fclose(file);
    }
    return tree;
}



void traverseTree(struct tnode* tree)
{

    if(tree != NULL)
    {
        traverseTree(tree->right);
        traverseTree(tree->left);
        int balace = heightOfNode(tree->right)-heightOfNode(tree->left);
        printf("bal(%d) = %d", tree->key, balace);

        if(balace < -1 || balace > 1)
        {
            printf(" (AVL violation!)");
        }
        printf("\n");
    }
}

int heightOfNode(struct tnode* tree)
{
   if(tree == NULL)
   {
       return 0;
   }
   int right = 0;
   int left = 0;
   int height = 0;
   if(tree != NULL)
   {
    right = heightOfNode(tree->right);
    left = heightOfNode(tree->left);
   }
   if(right > left)
   {
       height = right+1;
   }
   else
   {
       height = left+1;
   }

   return  height;
}

int findMin(struct tnode* tree)
{
   if(tree == NULL)
   {
       return INT_MAX; //= 2147483647 (32 bit)
   }
   int min = tree->key;
   int leftMin = 0;
   int rightMin = 0;
   if(tree != NULL)
   {
    rightMin = findMin(tree->right);
    leftMin = findMin(tree->left);
   }

   if(rightMin < min)
   {
       min = rightMin;
   }
   else if(leftMin < min)
   {
       min = leftMin;
   }

   return  min;
}

int findMax(struct tnode* tree)
{
   if(tree == NULL)
   {
       return INT_MIN; //= -2147483647 (32 bit)
   }
   int max = tree->key;
   int leftMax = 0;
   int rightMax = 0;
   if(tree != NULL)
   {
    rightMax = findMax(tree->right);
    leftMax = findMax(tree->left);
   }

   if(rightMax > max)
   {
       max = rightMax;
   }
   else if(leftMax > max)
   {
       max = leftMax;
   }
   return  max;
}
