#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Структура для представления элемента списка
struct Node {
    char data[6]; // Хранит строки размерностью не более 5 символов
    struct Node* next; // Указатель на следующий элемент списка
};

// Функция для вставки элемента в упорядоченный список
void insertNode(struct Node** head, char newData[]) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    strcpy(newNode->data, newData);

    if (*head == NULL || strcmp(newNode->data, (*head)->data) < 0) {
        newNode->next = *head;
        *head = newNode;
    }
    else {
        struct Node* current = *head;
        while (current->next != NULL && strcmp(newNode->data, current->next->data) > 0) {
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
    }
}

// Функция для удаления элемента из списка по заданной подстроке
void deleteNodeBySubstring(struct Node** head, char substring[]) {
    struct Node* temp = *head;
    struct Node* prev = NULL;

    while (temp != NULL) {
        if (strstr(temp->data, substring) != NULL) {
            if (prev == NULL) {
                *head = temp->next;
            }
            else {
                prev->next = temp->next;
            }
            free(temp);
            temp = prev != NULL ? prev->next : *head;
        }
        else {
            prev = temp;
            temp = temp->next;
        }
    }
}

// Функция для поиска элемента по вводимой подстроке
void searchNodeBySubstring(struct Node* head, char substring[]) {
    int found = 0;
    while (head != NULL) {
        if (strstr(head->data, substring) != NULL) {
            printf("Element found: %s\n", head->data);
            found = 1;
        }
        head = head->next;
    }
    if (!found) {
        printf("Element s podstrokoy \"%s\" not found.\n", substring);
    }
}

// Функция для печати списка
void printList(struct Node* head) {
    while (head != NULL) {
        printf("%s ", head->data);
        head = head->next;
    }
    printf("\n");
}

// Функция освобождения памяти
void freeList(struct Node* head) {
    struct Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

int main() {
    struct Node* head = NULL;
    FILE* inputFile = fopen("input.txt", "r");
    if (inputFile == NULL) {
        // Создание файла, если его нет
        inputFile = fopen("input.txt", "w");
        fclose(inputFile);
        inputFile = fopen("input.txt", "r");

        if (inputFile == NULL) {
            printf("Error.\n");
            return 1;
        }

        char buffer[6];
        while (fscanf(inputFile, "%5s", buffer) == 1) {
            insertNode(&head, buffer);
        }

        fclose(inputFile);

        int choice;
        char searchSubstr[6];
        char deleteSubstr[6];
        do {
            printf("\nMenu:\n");
            printf("1. Paste element\n");
            printf("2. Delete element po podstroke\n");
            printf("3. Found element po podstroke\n");
            printf("4. Print spisok\n");
            printf("5. Exit\n");
            printf("Chose action: ");
            scanf("%d", &choice);

            switch (choice) {
            case 1:
                printf("Vvedite new element: ");
                scanf("%5s", buffer);
                insertNode(&head, buffer);
                break;
            case 2:
                printf("Vvedite podstroku for delete: ");
                scanf("%5s", deleteSubstr);
                deleteNodeBySubstring(&head, deleteSubstr);
                break;
            case 3:
                printf("Vvedite podstroku for found: ");
                scanf("%5s", searchSubstr);
                searchNodeBySubstring(head, searchSubstr);
                break;
            case 4:
                printf("Spisok: ");
                printList(head);
                break;
            case 5:
                break;
            default:
                printf("Error. Try again\n");
            }
        } while (choice != 5);

        // Освобождение памяти
        freeList(head);

        return 0;
    }
}