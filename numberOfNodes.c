#include <stdio.h>
#include <stdlib.h>

struct tree {
    int data;
    struct tree* right;
    struct tree* left;
};

typedef struct tree* TREE;

TREE insert(TREE tree, int data);
TREE newNode(int n);
void inorder(TREE root);
void countNodesAtEachLevel(TREE root, int level, int* count);
int getHeight(TREE root);
void showStructure(TREE root, int level);


int main() {
    int num, ch;
    TREE root = NULL;
    while (1) {
        printf("Enter a choice\nChoice 1: Insert\nChoice 2: Inorder\nChoice 3: Tree Type\nChoice 4: Nodes at each level\nChoice 5:End program\n");
        scanf("%d", &ch);
        switch (ch) {
            case 1:
                printf("Enter a number\n");
                scanf("%d", &num);
                if (root == NULL) {
                    root = insert(root, num);
                } else {
                    insert(root, num);
                }
                break;
            case 2:
                inorder(root);
                break;
            case 3:
                TreeType(root);
                break;
            case 4:
                displayLevelCounts(root);
                break;
                case 5:
    printf("Binary Tree Structure:\n");
    showStructure(root, 0);
    break;

                case 6:exit(0);
                break;
        }
    }
}

TREE newNode(int n) {
    TREE temp = (TREE)malloc(sizeof(struct tree));
    temp->data = n;
    temp->left = temp->right = NULL;
    return temp;
}

void inorder(TREE root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d->", root->data);
        inorder(root->right);
    }
}

TREE insert(TREE tree, int data) {
    if (tree == NULL) {
        return newNode(data);
    }
    if (data < tree->data) {
        tree->left = insert(tree->left, data);
    } else if (data > tree->data) {
        tree->right = insert(tree->right, data);
    }
    return tree;
}

void TreeType(TREE root) {
    if (root == NULL) {
        printf("Tree is empty.\n");
    } else if (root->left == NULL && root->right == NULL) {
        printf("Tree is a leaf.\n");
    } else if (root->left == NULL) {
        printf("Tree is right-skewed.\n");
    } else if (root->right == NULL) {
        printf("Tree is left-skewed.\n");
    } else {
        printf("Tree is balanced.\n");
    }
}

int getHeight(TREE root) {
    if (root == NULL) {
        return 0;
    } else {
        int leftHeight = getHeight(root->left);
        int rightHeight = getHeight(root->right);
        return 1 + (leftHeight > rightHeight ? leftHeight : rightHeight);
    }
}

void countNodesAtEachLevel(TREE root, int level, int* count) {
    if (root == NULL) {
        return;
    }
    if (level == 1) {
        (*count)++;
    } else if (level > 1) {
        countNodesAtEachLevel(root->left, level - 1, count);
        countNodesAtEachLevel(root->right, level - 1, count);
    }
}

void printLevelCount(TREE root, int level, int* count)
{
    if (root == NULL)
        return;
    if (level == 1)
    {
            (*count)++;
    }   else if (level > 1)
    {
        printLevelCount(root->left, level - 1, count);
        printLevelCount(root->right, level - 1, count);
    }
}

void displayLevelCounts(TREE root)
{
    int height = getHeight(root);
    int level;
    for (level = 1; level <= height; level++)
        {
        int count = 0;
        printLevelCount(root, level, &count);
        printf("Level %d: %d nodes\n", level-1, count);
    }

    void showStructure(TREE root, int level) {
    if (root == NULL) {
        return;
    }

    showStructure(root->right, level + 1);

    for (int i = 0; i < level; i++) {
        printf("\t");
    }

    printf("%d\n", root->data);

    showStructure(root->left, level + 1);
}

}
