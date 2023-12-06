#include "Array.h"



int Binary_Search(float *arr, float target, int size){
    int low = 0, high = size - 1;
    while (low <= high){
        int mid = (high + low) / 2;
        if (arr[mid] == target)
            return mid;
        if (arr[mid] < target)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;
}



int main() {

    float arr[100], target;
    int arr_size = 0, input;
    Input_Array(arr, &arr_size,  "\nEnter the array elements and to exit enter '-1': ");

    printf("\nEnter the element to find its position in the array using Binary Search: ");
    scanf("%f", &target);

    printf("\nThe Index of Element '%.2f' in Array is '%d'.\n", target, Binary_Search(arr, target, arr_size));

}