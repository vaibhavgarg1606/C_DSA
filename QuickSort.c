#include <stdio.h>


void swap(float* a, float* b){
    float temp = *a;
    *a = *b;
    *b = temp;
}


int partition(float arr[],int low,int high) {
    int pivot=arr[high];
    int i=(low-1);
    for(int j=low;j<=high;j++) {
        if(arr[j]<pivot) {
            i++; 
            swap(&arr[i],&arr[j]);
        }
    }
    swap(&arr[i+1],&arr[high]);
    return (i+1);
}
             
void QuickSort(float arr[], int low, int high) {
  if(low<high) {     
    int pi=partition(arr,low,high);

    QuickSort(arr,low,pi-1);
    QuickSort(arr,pi+1,high);
  }
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

    QuickSort(arr, 0, size-1);
    printf("\nSorted Array is: ");
    for (int i = 0; i < size; i++)
        printf("%.2f ", arr[i]);
    printf("\n");

    return 0;

}