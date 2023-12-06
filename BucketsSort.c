#include <stdio.h>

int getMax(int a[], int n) {  
    int max = a[0];  
    for (int i = 1; i < n; i++)  
        if (a[i] > max)  
            max = a[i];  
    return max;  
}  

void bucketSort(int a[], int n) {  
    int max = getMax(a, n);
    int* bucket = (int*) malloc(sizeof(int) * (max+1));

    for (int i = 0; i <= max; i++)  
        bucket[i] = 0;  
    for (int k = 0; k < n; k++)  
        bucket[a[k]]++;  
    for (int i = 0, j = 0; i <= max; i++)  {
        while (bucket[i] > 0) {  
            a[j++] = i;  
            bucket[i]--;  
        }  
    }

    free(bucket);
}  

 

void InputArray(int arr[], int *size){
    printf("\nEnter no of Elements in array: ");
    scanf("%d", size);
    printf("\nEnter the Array Elements: ");
    for (int i = 0; i < *size; i++)
        scanf("%d", &arr[i]);    
}


int main(){

    printf("\nName: Vaibhav Garg    | Enrollment NO : 05613203122\n");


    int arr[100];
    int size;
    InputArray(arr, &size);

    bucketSort(arr, size);
    printf("\nSorted Array is: ");
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    
    printf("\n");

    return 0;

}