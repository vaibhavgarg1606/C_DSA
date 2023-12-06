#include <stdio.h>
#define MAX_ELEMENT 5


typedef struct CircularQueue{
    float arr[MAX_ELEMENT];
    int front, rear;

} CircularQueue;





int EnQueue(CircularQueue* cirQueue, float value){

    if((cirQueue->front == 0 && cirQueue->rear == MAX_ELEMENT-1) ||
        ((cirQueue->rear + 1) % MAX_ELEMENT == cirQueue->front)){
        printf("\n[ERROR] CircularQueue Overflow\n");
        return -1;
    }
    if(cirQueue->front == -1)
        cirQueue->rear = cirQueue->front = 0;
    else if (cirQueue->rear == MAX_ELEMENT-1 && cirQueue->front !=0)
        cirQueue->rear = 0;
    else
        cirQueue->rear++;
        
    cirQueue->arr[cirQueue->rear] = value;
    return 0;
}


float DeQueue(CircularQueue* cirQueue){
    if(cirQueue->front == -1){
        printf("\n[ERROR] CircularQueue Underflow\n");
        return -1;
    }
    float data = cirQueue->arr[cirQueue->front];
    if(cirQueue->front == cirQueue->rear)
        cirQueue->front = cirQueue->rear = -1;
    else if (cirQueue->front == MAX_ELEMENT -1)
        cirQueue->front = 0;
    else
        cirQueue->front++;
    return data;
}

void Display(CircularQueue* cirQueue){
    if(cirQueue->front == -1){
        printf("\nQueue is Empty\n");
        return;
    }
    printf("\nDisplaying CircularQueue:\t");
    
    if (cirQueue->rear >= cirQueue->front){
        for(int i = cirQueue->front; i < cirQueue->rear + 1; i++)
            printf("%.2f ", cirQueue->arr[i]);
    }else{
        for(int i = cirQueue->front; i < MAX_ELEMENT; i++)
            printf("%.2f ", cirQueue->arr[i]);
        for(int i = 0; i < cirQueue->rear + 1; i++)
            printf("%.2f ", cirQueue->arr[i]);
    }
    printf("\n");
}


int main(){
    
    CircularQueue cirQueue = {.front = -1, .rear = -1};

    int input = 0; 
    float value;

    while (input != 4) {
        printf("\nEnter the command to perform operation on CircularQueue :\n1.EnQueue\n2.DeQueue\n3.Display\n4.Exit\n=>");
        scanf("%d", &input);

        switch (input)
        {
        case 1:
            printf("\nInput the Number to Enqueue in CircularQueue: ");
            scanf("%f", &value);
            EnQueue(&cirQueue, value);
            break;
        case 2:
            value = DeQueue(&cirQueue);
            if(value != -1) printf("\nElement '%.2f' is dequeued from CircularQueue.\n", value);
            break;
        case 3:
            Display(&cirQueue);
            break;
        case 4:
            printf("Terminating...\n");
            break;
        case 5:
            system("cls");
            break;
        default:
            printf("Invalid choice. Please enter a valid option.\n");
            break;
        }

    }
}