#include <stdio.h>

void Swap(float* a, float* b){
    float temp = *a;
    *a = *b;
    *b = temp;
}

int min(float arr[], int start, int size){
    float min = arr[start];
    int loc = start;
    for (int i = start; i < size; i++){
        if(arr[i] < min){
            min = arr[i];
            loc = i;
        }
    }
    return loc;    
}

int SelectionSort(float arr[], int size){
    int swapped = 0;
    for (int i = 0; i < size; i++) {
        int loc = min(arr, i, size);
        if(arr[i] != arr[loc]){
            Swap(&arr[i], &arr[loc]);
            printf("\nAfter pass '%d', Array: ", swapped + 1);
            for (int k = 0; k < size; k++)
                printf("%.2f ", arr[k]);
            swapped++;
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

    int swapped = SelectionSort(arr, size);
    printf("\n\nSorted Array is: ");
    for (int i = 0; i < size; i++)
        printf("%.2f ", arr[i]);
    
    printf("\nNumber of times swapped: %d.\n", swapped);

    return 0;

}