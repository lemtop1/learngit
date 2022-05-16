#include<stdio.h>


int main(){
    int Num,i,j = 0,k = 0,N = 10;
    int Array[N] = {1,4,6,9,13,16,19,28,40,100},Array2[N+1] = {0};
    printf("Please input a new integer:\n");
    scanf("%d",&Num);

    for(i=0; i<N-1; i++){
        k = i;
        if(Array[i] <= Num){
            Array2[k] = Array[i];
            }
            
        else(Array[i] >= Num){
            Array2[k] = Num;
            break;
            }
    }
    for(i+1;i<N;i++){
        Array2[i] = Array[i-1];
    }

    for(j;j<N;j++){
        printf("%d",Array2[j]);
    }
    return 0;

    }


}