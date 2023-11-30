#include <stdio.h>



typedef struct Node
{
    int data;
    struct Node* next;
} Node;



void LinkedListInsert(Node** head, int value, int index) {
    if (index == 0) {
        Node* new_head = (Node*)malloc(sizeof(Node));
        new_head->data = value;
        new_head->next = *head;
        *head = new_head;
        return;
    }

    Node* current, * previous;
    current = *head, previous = NULL;

    int count = 0;
    while (count < index && current != NULL) {
        previous = current;
        current = current->next;
        count++;
    }

    if (count < index) {
        printf("[ERROR] Index Error: insertion pass end of list\n");
    }

    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->data = value;
    new_node->next = previous->next;
    previous->next = new_node;

}


void LinkedListDeletion(Node** head, int index) {
    if (head == NULL)
        return;

    if (index == 0) {
        printf("\nNode with value '%d' at index '%d' is deleted.", (*head)->data, index);
        *head = (*head)->next;
        return;
    }

    Node* current, * previous;
    current = *head, previous = NULL;
    int count = 0;
    while (count < index && current != NULL) {
        previous = current;
        current = current->next;
        count++;
    }

    if (current != NULL) {
        previous->next = current->next;
        printf("\nNode with value '%d' at index '%d' is deleted.", current->data, index);
        free(current);
    }
    else {
        printf("[ERROR]Index Error: no element at specified index\n");
    }
}






void PrintLinkedList(Node* head){
    printf("Linked List: ");
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}






int main() {


    Node* Head = NULL;
    int input = 0, value, index;


    while (input != 4) {
        printf("\nEnter the command to perform operation: \n1.Insert\n2.Delete\n3.Traverse\n4.Exit\n=>");
        int scan =scanf("%d", &input);

        if(scan == 0){
            while(getchar() != '\n');
            input = 10;
        }

        switch (input)
        {
        case 1:
            printf("\nInput the Number and index to be inserted in LinkedList: ");
            scanf("%d %d", &value, &index);
            LinkedListInsert(&Head, value, index);
            break;
        case 2:
            printf("\nInput the Index to delete the node in LinkedList: ");
            scanf("%d", &index);
            LinkedListDeletion(&Head, index);
            break;
        case 3:
            PrintLinkedList(Head);
            break;
        case 4:
            printf("Terminating...\n");
            break;
        default:
            printf("Invalid Input.\n");
            break;
        }

    }

}



