#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = newNode->prev = NULL;
    return newNode;
}

void insertEnd(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        newNode->next = newNode->prev = newNode;
    } else {
        struct Node* last = (*head)->prev;
        newNode->next = *head;
        (*head)->prev = newNode;
        newNode->prev = last;
        last->next = newNode;
    }
}

void printList(struct Node* head) {
    if (head == NULL) return;
    struct Node* temp = head;
    do {
        printf("Address: %p, Data: %d\n", (void*)temp, temp->data);
        temp = temp->next;
    } while (temp != head);
}

void sortList(struct Node** head) {
    if (*head == NULL || (*head)->next == *head) return;

    struct Node *i, *j;
    for (i = (*head); i->next != *head; i = i->next) {
        for (j = i->next; j != *head; j = j->next) {
            if (i->data > j->data) {
        
                int tempData = i->data;
                i->data = j->data;
                j->data = tempData;
            }
        }
    }
}

int main() {
    struct Node* head = NULL;
    int N;
    
    scanf("%d", &N);
    int data;
    
    for (int i = 0; i < N; i++) {
        scanf("%d", &data);
        insertEnd(&head, data);
    }
    
    printList(head);
    
    sortList(&head);
    
    printList(head);
    
    return 0;
}

