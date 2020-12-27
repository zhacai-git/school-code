#include <stdio.h>
int main()
{
    int i,loc[500]={0},out_put_c;
    long long int n;
    scanf("%lld",&n);
    //记录素数数量
    for (i=2;i<=n;i++)
    {
        if (n%i==0)
        {
            loc[i]++;
            //printf("//debug//loc[%d]自增\n",i);
            n/=i;
            //printf("//debug//此时n为:%lld\n",n);
            i=1;
        }
    }
    //判断并输出存储结果
    for (out_put_c=2;out_put_c<500;out_put_c++)
    {
        if (loc[out_put_c]>=2)
        {
            printf("%d ",out_put_c);
        }
    }
    return 0;
}

