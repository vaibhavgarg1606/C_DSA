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


int main(){

    float arr[100] = {0};
    int size = 0, pos;
    float value;

    Input_Array(arr, &size, "\nEnter the array elements and to exit enter '-1': ");    

    Print_Array(arr, size, "\nArray entered is: ");

    printf("\nEnter the value and position to be inserted at: ");
    scanf("%f %d", &value, &pos);
    Insert(arr, &size, pos, value);

    Print_Array(arr, size, "\nArray after unsorted insertion is: ");


    return 0;

}