#include <stdio.h>
#define N 500 //此处数为数组定义最大值，按需调整为n+fwd大小，或指定一个很大的数
void move(int n,int nums[],int fwd);
int main()
{
    int nums[N] = {0};//数组初始化
    int n,fwd,i;
    scanf("%d %d",&n,&fwd);
    for (i = 0;i < n;i++)
    {
        scanf("%d",&nums[i]);
    }
    move(n,nums,fwd);
    return 0;
}
void move(int n,int nums[],int fwd)
{
    int i;
    for (i = n - 1;i >= 0;i--)//集体右移fwd位
    {
        *(nums + i + fwd) = *(nums + i);
    }
    for (i = fwd - 1;i >= 0;i--)//将末尾共fwd位与头部fwd位对应替换
    {
        *(nums + i) = *(nums + n + i);
    }
    for (i = 0;i < n;i++)
    {
        printf("%d ",nums[i]);//按顺序输出
    }
}