#include "Array.h"


void Insert(float *arr, int* arr_size, int pos, float value){

    if (pos == -1){
        arr[(*arr_size)] = value;
    }else{
        float temp = value, temp2;
        for(int i = pos; i <= (*arr_size); i++){
            temp2 = arr[i];
            arr[i] = temp;
            temp = temp2;
        }
    }

    (*arr_size)++;
}

void Insert_Sorted(float *arr, int *arr_size, float value){

    int pos = -1;

    for (int i = 0; i < (*arr_size); i++) {
        if(arr[i] >= value){
            pos = i;
            break;
        }
    }

    Insert(arr, arr_size, pos, value);
}


int main(){

    float arr[100] = {0};
    int size = 0;
    float value;

    Input_Array(arr, &size, "\nEnter the array elements in sorted order and to exit enter '-1': ");    

    Print_Array(arr, size, "\nArray entered is: ");

    printf("\nEnter the value to be inserted : ");
    scanf("%f", &value);
    Insert_Sorted(arr, &size, value);

    Print_Array(arr, size, "\nArray after sorted insertion is: ");


    return 0;

}