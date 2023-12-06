#include <stdio.h>
#define MAX_ELEMENT 5


typedef struct Stack{
    float stack_arr[MAX_ELEMENT];
    int top;

} Stack;





int Push(Stack* stack, float value){

    if(stack->top == MAX_ELEMENT-1){
        printf("\n[ERROR] Stack Overflow\n");
        return -1;
    }
    stack->stack_arr[++(stack->top)] = value;
    return 0;
}


float Pop(Stack* stack){
    if(stack->top == -1){
        printf("\n[ERROR] Stack Underflow\n");
        return -1;
    }
    return stack->stack_arr[stack->top--];
}

void Display(Stack* stack){
    printf("\nDisplaying Stack:\t");
    for(int i = 0; i < stack->top + 1; i++){
        printf("%.2f ", stack->stack_arr[i]);
    }
    printf("\n");
}


int main(){
    
    Stack stack = {.top = -1};

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
        case 4:
            printf("Terminating...\n");
            break;
        case 5:
            system("cls");
            break;
        default:
            printf("Invalid choice. Please enter a valid option.\n");
        }

    }
}