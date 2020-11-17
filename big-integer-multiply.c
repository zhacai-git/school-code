/*
大整数数乘法计算程序
POWERED BY lzxweb.com
使用gets输入，编译严格会警告，不影响使用
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int isover10(int x);
int main()
{
    char num1_ch_inp[200] = {'\0'},num2_ch_inp[200] = {'\0'};//输入存储数组，字符类型
    int num1_int[200] = {0},num2_int[200] = {0};//转换数组，整数类型
    int num_sum = 0,st = 0;//乘法暂存器
    int j = 0,ml1 = 0,ml2 = 0;//进位计数器，行、列移动控制器
    int i = 0,num1_num = 0,num2_num = 0;//循环计数器，数组长度保存
    int sum_l[200][400] = {0};//输出结果，错位保存数组
    int loc_h_offset = -1,loc_l_offset = -1, rsl=0,rsl_t=0;//加法位移控制器，保存结果列位置控制器，临时变量
    int ifhave=0;//输出0标识符
    gets(num1_ch_inp);
    gets(num2_ch_inp);
    num1_num = strlen(num1_ch_inp);//获取输入内容长度
    num2_num = strlen(num2_ch_inp);
    rsl=num1_num+num2_num-1;
    //字符型数组转数字型
    for (i = 0;i < num1_num;i++)
    {
        num1_int[i] = (num1_ch_inp[i]-'0');
    }
    for (i = 0;i < num2_num;i++)
    {
        num2_int[i]=(num2_ch_inp[i]-'0');
    }
    /*竖式乘法部分
      num1_inp[multi_1]第二层循环
    X num2_inp[multi_2]第一层循环
    算num2各位分别乘以num1所有，以j来记录进位数量，计算时与10比对
    大于10则-10，同时j++，乘出来的结果按照数字位数放入sum数组*/
    num_sum=num1_num+num2_num;
    int sum[num_sum];
    for (i=0;i<num_sum;i++)//因存在动态定义，故手动初始化sum数组
    {
        sum[i]=0;
    }
    rsl_t=rsl;//将临时变量赋值
    for (ml2=num2_num-1;ml2>=0;ml2--)//循环第一层，控制竖式乘法下方与上方相乘元素
    {
        j=0;//进位计数器置零
        loc_h_offset++;//偏移量预加
        loc_l_offset++;
        rsl=rsl_t;//重置保存位置计数器
        for (ml1=num1_num-1;ml1>=0;ml1--)
        {
            st=num1_int[ml1]*num2_int[ml2]+j;//两位数相乘，并加进位
            j=0;
            switch (isover10(st))//检测st范围并视情况增加进位，insover10具体用法详见下方函数
            {
                case 0://st小于10
                {
                    sum_l[loc_h_offset][rsl-loc_l_offset]+=st;//保存st
                    rsl--;//保存位置左移，下同
                    break;
                }
                case 1://st大于10
                {
                    j+=st/10;//进位器取十位数
                    st%=10;//st取个位数
                    sum_l[loc_h_offset][rsl-loc_l_offset]+=st;
                    rsl--;
                    break;
                }
                case 2:
                {
                    sum_l[loc_h_offset][rsl-loc_l_offset]+=0;
                    st%=10;
                    j++;
                    rsl--;
                    break;
                }
            }
        }
        if (j>0)//解决首位进位不加的问题
        {
            sum_l[loc_h_offset][rsl-loc_l_offset]=j;
            j=0;
        }
    }
    //所有乘法部分完成，进行列表加法部分
    loc_l_offset=0,loc_h_offset=0;//偏移量重置
    j=0,st=0;
    for (ml1=num_sum-loc_l_offset-1;ml1>=0;ml1--)//列控制
    {
        st=0;
        for (ml2=num2_num-loc_h_offset;ml2>=0;ml2--)//行控制
        {
            st+=sum_l[ml2][ml1];
        }
        st+=j;
        j=0;
        switch(isover10(st))
        {
            case 0:
            {
                sum[ml1]+=st;
                break;
            }
            case 1:
            {
                j+=st/10;
                st%=10;
                sum[ml1]+=st;
                break;
            }
            case 2:
            {
                j++;
                st%=10;
                sum[ml1]+=0;
                break;
            }
        }
    }
    //输出部分
    for (i=0;i<num_sum;i++)
    {
        if (sum[i]!=0||ifhave!=0)//检测0或是否为第一个0
        {
            ifhave++;
            printf("%d",sum[i]);
        }
        else
        {
            continue;
        }
    }
    return 0;
}
int isover10(int x)
{
    int z=0;
    if (x>10)
    {
        z=1;
    }
    if (x==10)
    {
        z=2;
    }
    if (x<10)
    {
        z=0;
    }
    return (z);
}