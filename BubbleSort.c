#include <stdio.h>

void Swap(float* a, float* b){
    float temp = *a;
    *a = *b;
    *b = temp;
}

int BubbleSort(float arr[], int size){
    int swapped = 0;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < i; j++) {
            if(arr[j] > arr[i]) {
                Swap(&arr[j], &arr[i]);
                printf("\nAfter pass '%d', Array: ", swapped + 1);
                for (int k = 0; k < size; k++)
                    printf("%.2f ", arr[k]);
                swapped++;
            }
        }
    }
    return swapped;
}


void InputArray(float arr[], int *size){
    printf("\nEnter no of Elements in array: ");
    scanf("%d", size);
    printf("\nEnter the Array Elements: ");
    for (int i = 0; i < *size; i++)
        scanf("%f", &arr[i]);    
}


int main(){

    printf("\nName: Vaibhav Garg    | Enrollment NO : 05613203122\n");


    float arr[100];
    int size;
    InputArray(arr, &size);

    int swapped = BubbleSort(arr, size);
    printf("\n\nSorted Array is: ");
    for (int i = 0; i < size; i++)
        printf("%.2f ", arr[i]);
    
    printf("\nNumber of times swapped: %d.\n", swapped);

    return 0;

}