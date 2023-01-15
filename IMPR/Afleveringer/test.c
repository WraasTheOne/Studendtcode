#include <stdio.h>


int main(void){
    int i, counter = 0;
    for(i = 1; i < 3; i++){
        int arr[i];
        if(i == 1){
            arr[0] = 1;
            arr[1] = 3;
        }
        if(i == 2){
            arr[1] = 3;
        }
        for(int j = 0; j < 2; j++){

            printf("%d\n", arr[j]);
        }
        printf("\n");
    }


    return 0;
}