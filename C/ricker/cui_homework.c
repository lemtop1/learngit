#include<stdio.h>
#include<math.h>
//#define PI 3.1415926

/*
调用stdio和math标准库,stdio用于基本的输入输出,math进行指数计算
定义常数PI 我觉得也可用const float
*/

//声明ricker计算函数
void ricker(float *ric,int ntw,float fpeak,float dt);
const float PI = 3.1415926;

//主函数
int main()
{   FILE *fp;//定义fp的类型为FILE文件类型
    float dt,fpeak,ric[20000];//定义dt即时间间隔,fpeak峰值频率,ric参数
    int nt,it;//nt是计算次数,it为计数器
    
    
    fp = fopen("/home/lem/learngit/C/ricker/par1.dat","r");//打开参数文件,并且为只读方式
    if(fp == NULL){//如果参数文件为空
        printf("open file %s error","par1.dat");
        return -1;
        //输出无法找到par1方便定位维护
    }

    //从fp文件读取三个参数,其中%d是按整型读如\n为回车,%f为读取浮点型数据
    fscanf(fp,"nt=%d\n",&nt);
    fscanf(fp,"dt=%f\n",&dt);
    fscanf(fp,"fpeak=%f\n",&fpeak);

    //打开文件之后不忘关闭
    fclose(fp);

    //调用我们在下面写的ricker函数
    ricker(ric,nt,fpeak,dt);

    //先创建文件方便写入文件
    fp = fopen("/home/lem/learngit/C/ricker/ric.dat","w");
    
    //输出无法找到ric方便定位维护
    if(fp == NULL){
        printf("open file %s error!","ric.dat");
        return -2;
        }

    //利用循环逐行输入
    for (it = 0;it < nt;it++)
        fprintf(fp,"%f\n",ric[it]);

    //关闭文件    
    fclose(fp);

    return 0;//返回函数结束
    }
    
    //声明函数
    void ricker(float ric[],int nt,float fpeak,float dt){
        int it;//计数器
        float x,xx,t;
        for (it =0;it<nt;it++){
            t = it*dt-1./fpeak;//t为时间
            x = PI*fpeak*t;//x = pi*f*t
            xx = x*x;//x的平方
            ric[it] = (1.-2.*xx)*exp(-xx);//雷克子波时间域表达式
        }
    }