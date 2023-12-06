#include <stdio.h>

int InsertionSort(float arr[], int size){
    int swapped = 0;
    for (int i = 0; i < size; i++) {
        float key = arr[i];
        int j = i-1;
        while(j > -1 && arr[j] > key){
            arr[j+1] = arr[j];
            j--;
            printf("\nAfter pass '%d', Array: ", swapped + 1);
            for (int k = 0; k < size; k++)
                printf("%.2f ", arr[k]);
            swapped++;
        }
        arr[j+1] = key;
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

    int swapped = InsertionSort(arr, size);
    printf("\n\nSorted Array is: ");
    for (int i = 0; i < size; i++)
        printf("%.2f ", arr[i]);
    
    printf("\nNumber of times swapped: %d.\n", swapped);

    return 0;

}