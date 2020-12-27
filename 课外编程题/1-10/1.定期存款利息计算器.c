#include <stdio.h>
int main()
{
//定义以及输入环节
    double money_c,payback,store_time,air,sum;
    int store_time_det;
    //printf("定期存款利息计算器\n");
    //printf("请输入存款金额:");
    scanf("%lf",&money_c);
    //printf("请输入存款期限\n");printf("整数1表示存期为3个月； 整数2表示存期为6个月；整数3表示存期为一年；整数4表示存期为二年；整数5表示存期为3年；整数6表示存期为五年\n");
    scanf("%d",&store_time_det);
    //printf("//%f %d\n",money_c,store_time_det);
//预处理环节
    //将年利率以及存储时间赋值
    switch(store_time_det)
        {
            case 1:
            {
                air=0.031;
                store_time=0.25;
                break;
            }
            case 2:
            {
                air=0.033;
                store_time=0.5;
                break;
            }
            case 3:
            {
                air=0.035;
                store_time=1.0;
                break;
            }
            case 4:
            {
                air=0.044;
                store_time=2.0;
                break;
            }
            case 5:
            {
                air=0.05;
                store_time=3.0;
                break;
            }
            case 6:
            {
                air=0.055;
                store_time=5.0;
                break;
            }
            default:
            {
                //printf("程序异常，正在退出\n");
                return (1);
            }
        //计算环节
        }
payback=money_c*store_time*air;
sum=payback+money_c;
printf("%.2lf\n",payback);
printf("%.2lf",sum);
return 0;
}
