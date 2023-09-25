
#include <stdio.h>



typedef struct Node
{
    float data;
    Node* next;
    Node* prev;
} Node;


typedef struct DoubleCircularLinkedList
{
    Node* head;
}DoubleCircularLinkedList;

Node* deleteDoubleCircularLinkedList(DoubleCircularLinkedList* list, int index){
    
    if(index == 0){ // i.e to remove head node
        Node* new_head = list->head->next;
        list->head->prev->next = new_head;
        new_head->prev = list->head->prev;
        Node* prev_head = list->head;
        list->head = new_head;
        return prev_head;
    }

    Node *current, *previous;
    current = list->head, previous = NULL;
    int count = 0;

    while(count < index && current != NULL){
        previous = current;
        current = current->next;
        count++;
    }

    
    if(current != NULL){
        previous->next = current->next;
        current->next->prev = previous;
        current->next = NULL;
        current->prev = NULL;
        return current;
    } else{
        printf("[ERROR]Index Error: no element at specified index\n");
        return NULL;
    }
}


int insertDoubleCircularLinkedList(DoubleCircularLinkedList* list, int index, float data){
    
    if(index == 0){ // Insert new node as head
        Node *newHead;  newHead->data = data, newHead->next = NULL, newHead->prev = NULL;   // Initialize newHead node with value data and nullptr
        newHead->next = list->head;
        newHead->prev = list->head->prev;
        newHead->prev->next = newHead;
        list->head->prev = newHead;
        list->head = newHead;
    }


    Node *current, *previous;
    current = list->head, previous = NULL;
    int count = 0;

    while(count < index && current != NULL){
        previous = current;
        current = current->next;
        count++;
    }

    
    Node *node;  node->data = data, node->next = NULL, node->prev = NULL;   // Initialize node with value data and nullptr
    previous->next = node; 
    node->prev = previous;
    node->next = current;
    current->prev = node;
}