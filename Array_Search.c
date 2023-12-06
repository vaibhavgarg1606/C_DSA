#include "Array.h"


int Linear_Search(float *arr, int arr_size, float target){
    for (int i = 0; i < arr_size; i++)
        if (arr[i] == target)
            return i;

    return -1;
}


int Binary_Search_iter(float *arr, int high, int low, float target){
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


int Binary_Search_recur(float *arr, int high, int low, float target){
    int mid = (high + low) / 2;

    if (low <= high){
        if (arr[mid] == target) return mid;
        else if (arr[mid] < target) return Binary_Search_recur(arr, high, mid + 1, target);
        else return Binary_Search_recur(arr, mid - 1, low, target);
    }
    return -1;
}



int main() {

    float arr[100], target;
    int arr_size = 0, input;
    Input_Array(arr, &arr_size,  "Enter the array elements and to exit enter '-1': ");

    printf("\nEnter the element to find its position in the array: ");
    scanf("%f", &target);

    printf("\nSelect Searching Method: ");
    printf("\n1. Linear Search");
    printf("\n2. Binary Search\n");
    scanf("%d", &input);

    switch (input)
    {
    case 1:
        printf("\nThe Position of Element '%.2f' in Array is '%d'.", target, Linear_Search(arr, arr_size, target));
        break;
    case 2:
        printf("\nThe Position of Element '%.2f' in Array is '%d'.", target, Binary_Search_iter(arr, arr_size - 1, 0, target));
        break;
    case 3:
        printf("\nThe Position of Element '%.2f' in Array is '%d'.", target, Binary_Search_recur(arr, arr_size - 1, 0, target));
        break;
    default:
        break;
    }


}