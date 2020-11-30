/*
最小素数集寻找程序
用法：先从控制台输入整数的个数，然后在下一行输入所有整数，各整数之间以一个空格分隔。
输出：在标准输出上按从小到大顺序输出求得的最小素数集，各素数之间以一个空格分隔。
作者:lzxweb.com
*/
#include <stdio.h>
#include <string.h>
void find(int nums[],int n);
int isprime(int n);
int main()
{
    int i,n;
    int nums[20]={0};
    scanf("%d",&n);
    for (i=0;i<n;i++)
    {
        scanf("%d",&nums[i]);
    }
    find(nums,n);
    return 0;
}
void find(int nums[],int n)
{
    int i=0,j=0,k=0,p=0,opt_handle_count=0,opt_counter=0,opt_det=0,det_have=0;
    int opt_have[200]={0};
    int primes[200]={0};
    int num_t,t,opt_del_counter=0;
    for (i=0;i<n;i++)//输入数提取控制
    {
        num_t=nums[i];//暂存nums[i]
        //首先判断提取的数是否为素数
        if (isprime(nums[i])==0)
        {
            primes[p]=nums[i];
            p++;
            continue;
        }
            //移植自分解质因数函数
            for (k=2;k<nums[i];k++)
            {
                while (num_t!=k)
                {
                    if (num_t%k==0)
                    {
                        primes[p]=k;
                        num_t/=k;
                        p++;
                    }
                    else
                    {
                        break;
                    }
                }
                primes[p]=num_t;
            }
                p++;
                for (opt_handle_count=0;opt_handle_count<=p;opt_handle_count++)
                {
                    if (opt_counter==0)//输出检测数组计数器为0
                        {
                            opt_have[opt_counter]=primes[opt_handle_count];//令其第一位为本次输出质数
                            opt_counter++;//计数器加1
                            continue;
                        }
                        det_have=0;
                        if (opt_counter>=1)//不是第一位
                        {
                            for (opt_det=0;opt_det<=opt_counter;opt_det++)//检测是否重复过
                            {
                                    if (opt_have[opt_det]==primes[opt_handle_count])//重复
                                    {
                                        det_have=1;//标志符置1
                                        break;
                                    }
                            }
                            if (det_have==0)//没有重复的
                            {
                                opt_have[opt_counter]=primes[opt_handle_count];//添加到重复检测列表
                                opt_counter++;//计数器加1
                            }
                            else
                            {
                                continue;
                            }
                            
                        }
                }
    }
    //质因数寻找完成，primes数组填充完成，长度为p
    for (j=0;j<p-1;j++)//primes排序
    {
        for (k=0;k<p-j-1;k++)
        {
            if (primes[k]>primes[k+1])
            {
                t=primes[k+1];
                primes[k+1]=primes[k];
                primes[k]=t;
            }
        }
    }
    for (j=0;j<p;j++)//控制opt_have内容与primes比对
        {
            for (k=0;k<p;k++)//控制primes内容
            {
                if (primes[k]!=0&&opt_have[j]!=0&&primes[k]==opt_have[j])//发现相等
                {
                    for (opt_del_counter=k+1;opt_del_counter<p;opt_del_counter++)//标记之后相同的数字
                    {
                        if (primes[k]==primes[opt_del_counter])//与之后的匹配
                        {
                            primes[opt_del_counter]=0;//置零标记
                        }
                    }
                }
            }
        }
    //所有工作完成，进行输出比对环节，输出次数为opt_counter
    for (i=0;i<p;i++)//控制输出prime总量，先进行比对
    {
        if (primes[i]!=0)//未在重复检测列表中（因为之前置零）且不等于零的项目
        {
            printf("%d ",primes[i]);
        }
    }
}
int isprime(int n)
{
    int i,ifprime=0;
    if (n==2)
    {
        ifprime=0;
    }
    else
    {
        for (i=2;i<n;i++)
        {
            if (n%i==0)
            {
                ifprime=1;
                break;
            }
        }
    }
    return (ifprime);
}