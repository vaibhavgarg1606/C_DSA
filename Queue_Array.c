#include <stdio.h>
#define MAX_ELEMENT 5


typedef struct Queue{
    float queue_arr[MAX_ELEMENT];
    int front, rear;

} Queue;





int EnQueue(Queue* queue, float value){

    if(queue->rear == MAX_ELEMENT-1){
        printf("\n[ERROR] Queue Overflow\n");
        return -1;
    }
    if(queue->rear == -1){
        queue->rear = 0; queue->front = 0;
    } else {
        queue->rear++;
    }
    queue->queue_arr[queue->rear] = value;
    return 0;
}


float DeQueue(Queue* queue){
    if(queue->front == -1 || queue->front > queue->rear){
        printf("\n[ERROR] Queue Underflow\n");
        return -1;
    }
    return queue->queue_arr[queue->front++];
}

void Display(Queue* queue){
    printf("\nDisplaying Queue:\t");
    for(int i = queue->front; i < queue->rear + 1; i++){
        printf("%.2f ", queue->queue_arr[i]);
    }
    printf("\n");
}


int main(){
    
    Queue queue = {.front = -1, .rear = -1};

    int input = 0; 
    float value;

    while (input != 4) {
        printf("\nEnter the command to perform operation on Queue :\n1.EnQueue\n2.DeQueue\n3.Display\n4.Exit\n=>");
        scanf("%d", &input);

        switch (input)
        {
        case 1:
            printf("\nInput the Number to Enqueue in Queue: ");
            scanf("%f", &value);
            EnQueue(&queue, value);
            break;
        case 2:
            value = DeQueue(&queue);
            if(value != -1) printf("\nElement '%.2f' is dequeued from queue.\n", value);
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