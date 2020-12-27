#include <stdio.h>
void handle(int nums[]);
int main()
{
    int i;
    int nums[10];
    for (i=0;i<10;i++)
    {
        scanf("%d",&nums[i]);
        //printf("%d ",nums[i]);
    }
    printf("\n");
    handle(nums);
    return 0;
}
void handle(int nums[])
{
    //寻找最小数
    int i,t,min=0,max=0,wheremin=0,wheremax=0;
    min=nums[0];
    for (i=0;i<10;i++)
    {
        if (nums[i]<min)
        {
            min=nums[i];
            wheremin=i;
        }
    }
    //printf("//最小数位置位于%d，值为%d\n",wheremin,nums[wheremin]);
    //寻找最大数
    max=nums[9];
    for (i=0;i<10;i++)
    {
        if (nums[i]>max)
        {
            max=nums[i];
            wheremax=i;
        }
    }
    //printf("//最大数位置位于%d，值为%d\n",wheremax,nums[wheremax]);
    //做替换环节
    if ((wheremax==0&&wheremin==9)||(wheremax==9&&wheremin==0))
    {
        t=nums[0];
        nums[0]=nums[9];
        nums[9]=t;
    }
    else
    {
        t=nums[0];
        nums[0]=nums[wheremin];
        nums[wheremin]=t;
        //printf("//nums[0]=%d与nums[wheremin]=%d呼唤\n",nums[0],nums[wheremin]);
        t=nums[9];
        nums[9]=nums[wheremax];
        nums[wheremax]=t;
        //printf("//nums[9]=%d与nums[wheremax]=%d呼唤\n",nums[9],nums[wheremax]);
    }
    
    for (i=0;i<10;i++)
    {
        printf("%d ",nums[i]);
    }
}
