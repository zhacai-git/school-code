#include <stdio.h>
#include <stdlib.h>
#define N 3//控制输入数据量
int main()
{
    int no[N]={0},i,j,t,math[N]={0},eng[N]={0},com[N]={0},total[N]={0},total_comp[N]={0},actual_order[N]={0};//各项成绩
    char *name[N];//姓名存储数组
    double avg_math=0,avg_eng=0,avg_com=0,total_math=0,total_eng=0,total_com=0;
    for (i=0;i<N;i++)
    {
        name[i]=(char*)malloc(sizeof(char*)*10);//姓名存储数组内存分配
    }
    for (i=0;i<N;i++)//信息输入环节
    {
        scanf("%d %s %d %d %d",&no[i],name[i],&math[i],&eng[i],&com[i]);
    }
    for (i=0;i<N;i++)//计算各项总值
    {
        total[i]=math[i]+eng[i]+com[i];
        total_math+=math[i],total_eng+=eng[i],total_com+=com[i];
    }
    avg_math=total_math/N;//计算平均值
    avg_eng=total_eng/N;
    avg_com=total_com/N;
    for (i=0;i<N;i++)//复制成绩数组
    {
        total_comp[i]=total[i];
    }
    for (i=0;i<N-1;i++)//冒泡排序排序成绩
    {
        for (j=0;j<N-i-1;j++)
        {
            if (total_comp[j]>total_comp[j+1])
            {
                t=total_comp[j+1];
                total_comp[j+1]=total_comp[j];
                total_comp[j]=t;
            }
        }
    }
    for (i=0;i<N;i++)//记录成绩从高到底对应的数据位置
    {
        for (j=0;j<N;j++)
        {
            if (total_comp[i]==total[j])
            {
                actual_order[i]=j;
                break;
            }
        }
    }
    printf(" NO   Name   Maths   English   Computer   Total\n");//输出环节
    for (i=N-1;i>=0;i--)
    {
        j=actual_order[i];
        printf("%5d%6s%6d%8d%10d\t%6d\n",no[j],name[j],math[j],eng[j],com[j],total[j]);
    }
    printf("average of Maths:%.2lf\n",avg_math);
    printf("average of English:%.2lf\n",avg_eng);
    printf("average of Computer:%.2lf\n",avg_com);
    return 0;
}