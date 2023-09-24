#include <stdio.h>


typedef struct Student{
    int Roll_No;
    char* Name;
} Student;



typedef struct LinkedList
{
    Student data;
    LinkedList* next;
} LinkedList;


LinkedList LinkedListInsert(LinkedList head, int index, Student value){
    if (index == 0){
        LinkedList new_head = {value};
        new_head.next = &head;
        return new_head;
    }

    LinkedList* current, *previous;
    current = &head, previous = NULL;

    int count = 0;
    while (count < index && current != NULL){
        previous = current;
        current = current->next;
        count++;
    }

    if(count < index){
        printf("[ERROR] Index Error: insertion pass end of list\n");
    }

    LinkedList new_node = {value};
    new_node.next = previous->next;
    previous->next = &new_node;
}


LinkedList* LinkedListDeletion(LinkedList head, int index){
    if(&head == NULL)
        return NULL;

    if (index == 0){
        LinkedList *new_head = head.next;
        head.next = new_head->next;
        return new_head;
    }

    LinkedList* current, *previous;
    current = &head, previous = NULL;
    int count = 0;
    while (count < index && current != NULL){
        previous = current;
        current = current->next;
        count++;
    }

    if(current != NULL){
        previous->next = current->next;
        current->next = NULL;
    } else{
        printf("[ERROR]Index Error: no element at specified index\n");
    }
    return &head;
}



int main(){



}