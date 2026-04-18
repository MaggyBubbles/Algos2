#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

int main()
{
    struct tnode* tree = NULL;
    printf("Enter file name:\n");
    scanf("%49s", &filename[0]);
    tree = getTreeFromFile(tree, filename); //legt den binary tree an

    //test zur Ausgabe
    printf("%d\n%d\n%d\n%d\n", tree->key, tree->right->key, tree->right->right->key, tree->left->key);

    return 0;
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
    file = fopen(filename, "r"); //Open to read
    if(file == NULL)
        printf("Error opening file\n");
    else
    {
        printf("File opened\n");
        int x;
        while(fscanf(file, "%d\n", &x) == 1)//solange 1 Element gefunden wird, wird die Datei ausgelesen
        {
           tree = insertion(x, tree); //hier findet das Einfügen in den binary tree statt
        }
        fclose(file);
    }
    return tree;
}

int balance(int left, int right)
{
    return right-left;
}
