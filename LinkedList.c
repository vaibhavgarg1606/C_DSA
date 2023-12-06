#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;


void insertAtBeginning(Node** head, int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = *head; // Point the new node to the current head
    // Update the head to the new node
    *head = newNode;
}

void insertInBetween(Node** head, int value, int position) {
    if (position < 1) {
        printf("Invalid position.\n");
        return;
    }

    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;

    if (position == 1) {
        newNode->next = *head;
        *head = newNode;
        return;
    }

    Node* current = *head;
    for (int i = 1; i < position - 1 && current != NULL; ++i) {
        current = current->next;
    }
    // Check if the position is valid
    if (current == NULL) {
        printf("Invalid position.\n");
        free(newNode);
        return;
    }

    newNode->next = current->next;
    current->next = newNode;
}

void insertAtLast(Node** head, int value){

    if(*head == NULL){
        insertAtBeginning(head, value);
        return;
    }

    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;

    Node* current = *head;
    while(1){
        if(current->next == NULL) break;
        current = current->next;
    }

    newNode->next = current->next;
    current->next = newNode;   

}


void deleteFromBegin(Node** head) {
    if (*head == NULL) {
        printf("Linked list is empty. Cannot delete.\n");
        return;
    }
    Node* temp = *head;
    *head = temp->next;
    free(temp);
}

void deleteFromBetween(Node** head, int position) {
    if (*head == NULL) {
        printf("Linked list is empty. Cannot delete.\n");
        return;
    }
    if (position == 1) {
        deleteFromBegin(head);
        return;
    }
    Node* current = *head;
    Node* prev = NULL;
    for (int i = 1; i < position && current != NULL; ++i) {
        prev = current;
        current = current->next;
    }
    if (current == NULL) {
        printf("Invalid position. Cannot delete.\n");
        return;
    }
    prev->next = current->next;
    free(current);
}

void deleteAtLast(Node** head) {
    if (*head == NULL) {
        printf("Linked list is empty. Cannot delete.\n");
        return;
    }
    Node* current = *head;
    Node* prev = NULL;
    while (current->next != NULL) {
        prev = current;
        current = current->next;
    }
    if (prev == NULL) {
        *head = NULL;
    } else {
        prev->next = NULL;
    }
    free(current);
}

void display(Node* head) {
    printf("Linked List: ");
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

int FindElement(Node* head, int value){
    int index = 0;
    while (head != NULL){
        head = head->next;
        index++;
        if(head->data != value) break;
    }
    return index;
}

int main() {
    Node* head = NULL;
    int choice, value, position;

    do {
        printf("\nMenu:\n");
        printf("1. Insert at beginning\n");
        printf("2. Insert in between\n");
        printf("3. Insert at last\n");
        printf("4. Delete from beginning\n");
        printf("5. Delete from between\n");
        printf("6. Delete at last\n");
        printf("7. Display\n");
        printf("8. Traverse\n");
        printf("9. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter the value to insert: ");
                scanf("%d", &value);
                insertAtBeginning(&head, value);
                break;
            case 2:
                printf("Enter the value to insert and pos: ");
                scanf("%d %d", &value, &position);
                insertInBetween(&head, value, position);
                break;
            case 3:
                printf("Enter the value to insert: ");
                scanf("%d", &value);
                insertAtLast(&head, value);
                break;
            case 4:
                deleteFromBegin(&head);
                break;
            case 5:
                printf("Enter the position to delete: ");
                scanf("%d", &position);
                deleteFromBetween(&head, position);
                break;
            case 6:
                deleteAtLast(&head);
                break;
            case 7:
                display(head);
                break;
            case 8:
                printf("Enter the element to find its position : ");
                scanf("%d", &value);
                printf("Element '%d' is present at index '%d'\n", value, FindElement(head, value));
                break;
            case 9:
                printf("Exiting the program.\n");
                break;
            default:
            printf("Invalid choice. Please enter a valid option.\n");
        }
    } while (choice != 9);
    return 0;
}