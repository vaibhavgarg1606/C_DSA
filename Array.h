#include <stdio.h>

// need for atof on line 47
#include <stdlib.h>


void Print_Array(float *arr, int arr_size, char* display_text){
    printf("%s", display_text);
    for (int i = 0; i < arr_size; i++) {
        printf("%.2f, ", arr[i]);
    }
    printf("\n");
}

void Input_Array(float *arr, int* size, char* display_text){

    printf("%s", display_text);
    float input;
    int i = 0;
    int parsed = scanf("%f", &input);    
    while((parsed == 1) && (input != -1)){
        arr[i++] = input;
        (*size)++;
        parsed = scanf("%f", &input);
    }
}




/* EXTREMELY UN-EFFIECIENT */
void Input_Array_(float *arr, int* size, char* display_text){

    char input[1000];   // TF is this u dipshit

    printf("%s", display_text);
    scanf("%[^\n]", input);    

    FILE* tmpf = tmpfile();     // holy shit , fucking waste of memory
    fputs(input, tmpf);

    rewind(tmpf);

    char buf[100];              // just kill me
    
    while (fscanf(tmpf, "%s ", buf) == 1)
        arr[(*size)++] = atof(buf);     // some problem with atof (use to convrt string to float)
}