#include "sec/LinkedList.h"




typedef struct Stack{
    Node* top;
} Stack;


int Push(Stack* stack, float value){
    insertAtBeginning(&(stack->top), value);
    return 0;
}


float Pop(Stack* stack){
    if(stack->top == NULL){
        printf("\n[ERROR] Stack Underflow\n");
        return -1;
    }
    return deleteFromBegin(&(stack->top));
}

void Display(Stack* stack){
    printf("\nDisplaying Stack:\t");
    display(stack->top);
}


int main(){
    
    Stack stack = {.top = NULL};

    int input = 0; 
    float value;

    while (input != 4) {
        printf("\nEnter the command to perform operation on Stack :\n1.Push\n2.Pop\n3.Display\n4.Exit\n=>");
        scanf("%d", &input);

        switch (input)
        {
        case 1:
            printf("\nInput the Number to Push in Stack: ");
            scanf("%f", &value);
            Push(&stack, value);
            break;
        case 2:
            value = Pop(&stack);
            printf("\nElement '%.2f' is Poped from stack.\n", value);
            break;
        case 3:
            Display(&stack);
            break;
        case 5:
            system("cls");
            break;
        case 4:
            printf("Terminating...\n");
            break;
        default:
            printf("Invalid choice. Please enter a valid option.\n");
        }

    }
}
