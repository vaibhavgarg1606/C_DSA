#include "Array.h"


int Delete_Element(float* arr, int *arr_size, float value){

    for (int i = 0; i < *arr_size; i++){
        if(arr[i] == value){
            arr[i] = 0;
            for (int j = i; j < *arr_size; j++){
                arr[j] = arr[j + 1];
            }
            (*arr_size)--;
            return i;
        }
    }
    return -1;
}


int main(){

    float arr[100] = {0};
    int size = 0;
    float value;

    Input_Array(arr, &size, "\nEnter the array elements in sorted order and to exit enter '-1': ");    

    Print_Array(arr, size, "\nArray entered is: ");

    printf("\nEnter the Element to be deleted : ");
    scanf("%f", &value);
    int pos = Delete_Element(arr, &size, value);
    if(pos >= 0 && pos <=size){
        printf("\nThe ELement '%0.2f' at Position '%d' has been deleted from the Array.", value, pos- 1);
    } else{
        printf("\nThere is no element with value '%0.2f' in Array.", value);
    }

    Print_Array(arr, size, "\nArray after deletion is: ");


    return 0;

}