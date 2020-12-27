#include <stdio.h>
void count(int a[],int n,int *pmax,int *pmin,float *pave,int *psum);
int main()
{
    int n,i,max,min,sum;
    float avg;
    int *pmax=&max,*pmin=&min,*psum=&sum;
    float *pavg=&avg;
    int nums[20];
    scanf("%d",&n);
    for (i=0;i<n;i++)
    {
        scanf("%d",&nums[i]);
    }
    count(nums,n,pmax,pmin,pavg,psum);
    printf("%d %d %.2f %d",max,min,avg,sum);
    return 0;
}
void count(int a[],int n,int *pmax,int *pmin,float *pave,int *psum)
{
    int i;
    *psum=0;
    //寻找最大数
    *pmax=a[0];
    for (i=0;i<n;i++)
    {
        if (a[i]>*pmax)
        {
            *pmax=a[i];
        }
    }
    //寻找最小数
    *pmin=a[0];
    for (i=0;i<n;i++)
    {
        if (a[i]<*pmin)
        {
            *pmin=a[i];
        }
    }
    for (i=0;i<n;i++)
    {
        *psum+=a[i];
    }
    *pave=(*psum*1.0)/n;
}
