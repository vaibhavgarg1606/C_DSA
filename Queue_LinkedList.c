#include "sec/LinkedList.h"




typedef struct Queue{
    Node* top;
} Queue;


int EnQueue(Queue* queue, float value){
    insertAtLast(&(queue->top), value);
    return 0;
}


float DeQueue(Queue* queue){
    if(queue->top == NULL){
        printf("\n[ERROR] Queue Underflow\n");
        return -1;
    }
    return deleteFromBegin(&(queue->top));
}

void Display(Queue* queue){
    printf("\nDisplaying Queue:\t");
    display(queue->top);
}


int main(){
    
    // printf("\nName: Vaibhav Garg    | Enrollment NO : 05613203122\n");

    Queue queue = {.top = NULL};

    int input = 0; 
    float value;

    while (input != 4) {
        printf("\nEnter the command to perform operation on Queue :\n1.EnQueue\n2.DeQueue\n3.Display\n4.Exit\n=>");
        scanf("%d", &input);

        switch (input)
        {
        case 1:
            printf("\nInput the Number to EnQueue in Queue: ");
            scanf("%f", &value);
            EnQueue(&queue, value);
            break;
        case 2:
            value = DeQueue(&queue);
            printf("\nElement '%.2f' is Dequeued from Queue.\n", value);
            break;
        case 3:
            Display(&queue);
            break;
        case 4:
            printf("Terminating...\n");
            break;
        case 5:
            system("cls");
            break;
        default:
            printf("Invalid choice. Please enter a valid option.\n");        }

    }
}
