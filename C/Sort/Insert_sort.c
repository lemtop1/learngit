/*
调用函数进行排序
*/
#include<stdio.h> 

int Insert_n(int N,int New){
    int i,j,k;//用于循环的参数
    int Array[N] = {1,4,6,9,13,16,19,28,40,100};
    int Array2[N+1] = {0};
 //循环,从前向后判断,小于是填入,大于时填入New
    for(i=0; i<N; i++){
        k = i;
        if(Array[9] <= New)
            Array2[10] = New;

        if(Array[i] <= New){
            Array2[k] = Array[i];
            }
            
        else if (Array[i] >= New){
            Array2[k] = New;
            break;
            }
    }
//将后续内容全部填入
    for(++i;i<=N;i++)
        Array2[i] = Array[i-1];

    for(j=0;j<=N;j++){
        printf("%d",Array2[j]);
    }
    return 0;
}

int main(){
    int New,N1;
    int Insert_n(int N,int New);
    int N =10;
    printf("Please input a new integer");
    scanf("%d",&New);

    Insert_n(N,New);

    return 0;

    }
