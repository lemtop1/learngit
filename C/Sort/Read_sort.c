/*
输入成绩和学号得出最高成绩
*/
#include<stdio.h>
int i,Max = 0;

int main(){
    int FindMax(int score[],long num[],int n,long *pMaxNum);
    int n;//因为学生成绩不可能为负,因此Max可以初始化为0,count为计数器
    long *pMaxNum; 
    printf("Please input the number of student:\n");
    scanf("%d",&n);
    int score[n];
    long num[n];//用long的话如果学号类似与00001时会省略前面的值,我觉得很不好看,也许用字符串表示会好很多

    for(i=0;i<n;i++){
        int *Vab_i;
        printf("Please input the score of the %dth student:\n",i+1);//我知道1是st,2是nd,感觉if表示起来太麻烦了,switch也是
        scanf("%d",&score[i]);
        printf("Please input the %dth student number:\n",i+1);
        scanf("%ld",&num[i]);
    }

    FindMax(score,num,n,pMaxNum);

    return 0;
}

int FindMax(int score[],long num[],int n,long *pMaxNum){
    for(i=0;i<n;i++){
        if (score[i] > Max){
            Max = score[i];
            pMaxNum = &num[i];
        }
    }
    
    printf("The highest score is:%d \n",Max);
    printf("His/Her student number is:%ld \n",*pMaxNum);
    
    return 0;
}