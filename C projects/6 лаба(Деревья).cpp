#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

struct TreeNode {
    char data[9];
    struct TreeNode* left;
    struct TreeNode* right;
};

void insert(struct TreeNode** root, struct TreeNode* newNode) {
    if (*root == NULL) {
        *root = newNode;
    }
    else {
        if (strcmp(newNode->data, (*root)->data) < 0) {
            if ((*root)->left == NULL) {
                (*root)->left = newNode;
            }
            else {
                insert(&((*root)->left), newNode);
            }
        }
        else {
            if ((*root)->right == NULL) {
                (*root)->right = newNode;
            }
            else {
                insert(&((*root)->right), newNode);
            }
        }
    }
}

void breadthFirstTraversal(struct TreeNode* root, char* destination) {
    if (root == NULL) {
        return;
    }
    struct TreeNode* queue[100];
    int front = 0, rear = 0;
    queue[rear++] = root;
    while (front < rear) {
        struct TreeNode* current = queue[front++];
        if (strcmp(current->data, destination) == 0) {
            printf("%s ", current->data);
            break;
        }
        printf("%s ", current->data);
        if (current->left != NULL) {
            queue[rear++] = current->left;
        }
        if (current->right != NULL) {
            queue[rear++] = current->right;
        }
    }
}

struct TreeNode* createNode(char* data) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    strncpy(newNode->data, data, 8);
    newNode->data[8] = '\0'; 
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

int main() {
    struct TreeNode* root = NULL;
    setlocale(LC_ALL, "Russian");
    char input[9];

    printf("Введите значение корневой вершины: ");
    scanf("%8s", input);
    root = createNode(input);

    int numNodes;
    printf("Введите количество вершин для вставки: ");
    scanf("%d", &numNodes);

    for (int i = 0; i < numNodes; i++) {
        printf("Введите значение вершины %d: ", i + 1);
        scanf("%8s", input);
        struct TreeNode* newNode = createNode(input);
        insert(&root, newNode);
    }

    char destination[9];
    printf("Введите вершину, в которую хотите пойти: ");
    scanf("%8s", destination);

    printf("Обход в ширину до выбранной вершины: ");
    breadthFirstTraversal(root, destination);

    struct TreeNode* current = root;
    printf("\nОбход в ширину до максимально-заданной вершины: ");
    breadthFirstTraversal(root, current->data + 1);
    printf("\n");

    return 0;
}
/*

struct TreeNode {
    struct TreeNode* left;
    struct TreeNode* right;
    char* data;
};

struct TreeNode* createNode(char* data) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newNode->data = _strdup(data);
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

void insert(struct TreeNode* root, struct TreeNode* newNode) {
    if (root == NULL) {
        root = newNode;
    }
    else {
        if (strcmp(newNode->data, root->data) < 0) {
            if (root->left == NULL) {
                root->left = newNode;
            }
            else {
                insert(root->left, newNode);
            }
        }
        else {
            if (root->right == NULL) {
                root->right = newNode;
            }
            else {
                insert(root->right, newNode);
            }
        }
    }
}

void breadthFirstTraversal(struct TreeNode* root, char* destination) {
    if (root == NULL) {
        return;
    }
    struct TreeNode* queue[100];
    int front = 0, rear = 0;
    queue[rear++] = root;
    while (front < rear) {
        struct TreeNode* current = queue[front++];
        if (strcmp(current->data, destination) == 0) {
            printf("%s ", current->data);
            break;
        }
        printf("%s ", current->data);
        if (current->left != NULL) {
            queue[rear++] = current->left;
        }
        if (current->right != NULL) {
            queue[rear++] = current->right;
        }
    }
}
int main() {
    struct TreeNode* root = NULL;
    setlocale(LC_ALL, "Russian");
    char input[9];

    printf("Введите значение корневой вершины: ");
    scanf("%s", input);
    root = createNode(input);

    int numNodes;
    printf("Введите количество вершин для вставки: ");
    scanf("%d", &numNodes);

    for (int i = 0; i < numNodes; i++) {
        printf("Введите значение вершины %d: ", i + 1);
        scanf("%s", input);
        struct TreeNode* newNode = createNode(input);
        insert(root, newNode);
    }

    char destination[9];
    printf("Введите вершину, в которую хотите пойти: ");
    scanf("%s", destination);

    printf("Обход в ширину до выбранной вершины: ");
    breadthFirstTraversal(root, destination);

    struct TreeNode* current = root; 
    printf("\nОбход в ширину до максимально-заданной вершины: ");
    breadthFirstTraversal(root, current->data+1);
    printf("\n");

    return 0;
}*/
