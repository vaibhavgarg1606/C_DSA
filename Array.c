#include "Array.h"



void Insert_UnSorted(float *arr, int* arr_size, int pos, float value){

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

    Insert_UnSorted(arr, arr_size, pos, value);
}

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

    Input_Array(arr, &size, "\nEnter the array elements and to exit enter '-1': \n");
    

    LOOP_BEGIN:
    printf("\nEnter the respective number to run the command : ");
    printf("\nTo print Array                            ---->   0 ");
    printf("\nTo Insert an Element at given Position    ---->   1 ");
    printf("\nTo Insert an Element in Sorted Araay      ---->   2 ");
    printf("\nTo Delete an Element from array           ---->   3 ");
    printf("\nTo Exit                                   ---->   -1 \n");

    int inputed_command, pos;
    scanf("%d", &inputed_command);

    switch (inputed_command)
    {
    case 0:
        Print_Array(arr, size, "\nArray"); goto LOOP_BEGIN; break;
    case 1:
        printf("\nEnter the value and pos to be inserted at: ");
        scanf("%f %d", &value, &pos);
        Insert_UnSorted(arr, &size, pos, value);
        goto LOOP_BEGIN;
        break;
    case 2:
        printf("\nEnter the value to be inserted : ");
        scanf("%f", &value);
        Insert_Sorted(arr, &size, value);
        goto LOOP_BEGIN;
        break;
    case 3:
        printf("\nEnter the Element to be deleted : ");
        scanf("%f", &value);
        pos = Delete_Element(arr, &size, value);
        if(pos >= 0 && pos <=size){
            printf("\nThe ELement '%0.2f' at Position '%d' has been deleted from the Array.", value, pos);
        } else{
            printf("\nThere is no element with value '%0.2f' in Array.", value);
        }
        goto LOOP_BEGIN;
        break;
    case 4:
        printf("\nSize : %d", size);
        goto LOOP_BEGIN;
    default:
        break;
    }


}