#include <stdio.h>

int ShellSort(float arr[], int size) { 
    int swapped = 0;
    for (int gap = size/2; gap > 0; gap /= 2) {
        for (int i = gap; i < size; i += 1) { 
            float temp = arr[i]; 
            int j;             
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) {
                arr[j] = arr[j - gap];
                printf("\nAfter pass '%d' Array: ", swapped + 1);
                for (int k = 0; k < size; k++)
                    printf("%.2f ", arr[k]);
                swapped++;
            }
            arr[j] = temp; 
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

    int swapped = ShellSort(arr, size);
    printf("\n\nSorted Array is: ");
    for (int i = 0; i < size; i++)
        printf("%.2f ", arr[i]);
    
    printf("\nNumber of times swapped: %d.\n", swapped);

    return 0;

}