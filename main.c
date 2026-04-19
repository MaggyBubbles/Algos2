#include <stdio.h>
#include <stdlib.h>
#include "tree.h"
#include <limits.h> //für INT_MAX, INT_MIN

int main()
{
    printf("Enter file name:\n");
    scanf("%49s", &filename[0]);
    treecheck(filename);

    return 0;
}

void treecheck(char filename[])
{
    struct tnode* tree = NULL;
    tree = getTreeFromFile(tree, filename); //legt den binary tree an
    traverseTree(tree); //Durchläuft Baum und gibt ihn und den Balance Faktor aus
    int min = findMin(tree);
    printf("min: %d, ", min);
    int max = findMax(tree);
    printf("max: %d, ", max);
    float avg = (float)findSum(tree)/countEntries(tree);
    printf("avg: %.1f\n", avg);
    if(avl)
    {
        printf("AVL: yes\n");
    }
    else
    {
        printf("AVL: no\n");
    }
}

//fügt den Int an die passende Stelle ein
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

//Ließt Werte aus dem File und fügt sie im Tree ein
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

//Durchlauft den Baum und gibt den Balance Faktor aus
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
            int *p = &avl;
            *p = 0; //setzt avl auf "false", um am Ende auszugeben, ob es ein AVL Baum ist oder nicht
        }
        printf("\n");
    }
}

//Berechnet die Höhe eines Knoten
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

int findSum(struct tnode* tree)
{
   if(tree == NULL)
   {
       return 0;
   }
   int sum = 0;
   int rightSum = tree->key;
   int leftSum = tree->key;
   if(tree != NULL)
   {
    rightSum = findSum(tree->right);
    leftSum = findSum(tree->left);
   }

    sum = rightSum + leftSum + tree->key;

   return  sum;
}

int countEntries(struct tnode* tree)
{
    if(tree == NULL)
   {
       return 0;
   }
   int count = 0;
   int rightCount = 0;
   int leftCount = 0;
   if(tree != NULL)
   {
    rightCount = countEntries(tree->right);
    leftCount = countEntries(tree->left);
   }

    count = rightCount + leftCount+1;

   return  count;
}
