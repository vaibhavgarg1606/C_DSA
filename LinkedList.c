#include <stdio.h>





typedef struct Node
{
    int data;
    struct Node* next;
} Node;



void LinkedListInsert(Node** head, int value, int index) {
    
    // if(index == 0 && (*head)->next == NULL){
    //     Node* new_head = (Node*)malloc(sizeof(Node));
    //     new_head->data = value;
    //     new_head->next = NULL;
    //     free(*head);
    //     *head = new_head;
    //     return;
    // }


    if (index == 0) {
        Node* new_head = (Node*)malloc(sizeof(Node));
        // Node* new_head = new Node;
        new_head->data = value;
        new_head->next = *head;
        *head = new_head;
        return;
    }

    Node* current, * previous;
    current = *head, previous = NULL;


/*  --------------------TODO: - Out of Range Inserion BUG-----------------
    if inserted with index out of list, there will be a extra Node added between new node and prev node,
    this extra node is due to initialisation of Head Node in main func, to debug it
    1.  Remove Insertion Of list by Head Node .. and instead Use void ptr Start, as taught by DSA lecturer in clg
    2. Change First Time Inserion so that instead of Making new Node (As did above by new_head), we will assign value to Head Node in main func
    3. Or Delete (or free) the head node passed [i.e in first insertion , it is (*head) and after that it is (*head)->next], so that the extra node can be removed... 

*/




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

    printf("End");
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
    while(head != NULL){
        printf("%d -> ", head->data);
        head = head->next;
    }
}






int main() {


    //TODO:
    /*
    try :
        Node * Head = NULL;
    */


    Node* Head = (Node*)malloc(sizeof(Node));
    Head->next = NULL;
    int input = 0, value, index;


    while (input != 4) {
        printf("\nEnter the command to perform operation: \n1.Insert\n2.Delete\n3.Traverse\n4.Exit\n=>");
        scanf("%d", &input);

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
            printf("\nLinkedList: ");
            Node* current = Head;
            while (current->next != NULL) {
                printf("%d -> ", current->data);
                current = current->next;
            }
            break;
        default:
            printf("Terminating...\n");
            break;
        }

    }

}

