#include "Array.h"


int Linear_Search(float *arr, int arr_size, float target){
    for (int i = 0; i < arr_size; i++)
        if (arr[i] == target)
            return i;

    return -1;
}


int main() {

    float arr[100], target;
    int arr_size = 0;
    Input_Array(arr, &arr_size,  "Enter the array elements and to exit enter '-1': ");

    printf("\nEnter the element to find its position in the array using Linear Search: ");
    scanf("%f", &target);


    printf("\nThe Index of Element '%.2f' in Array is '%d'.\n", target, Linear_Search(arr, arr_size, target));


}