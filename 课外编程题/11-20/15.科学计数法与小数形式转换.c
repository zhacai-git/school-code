#include <stdio.h>
int main()
{
    int i,j,n;
    char s[101]={'\0'},res[101]={'\0'};
    gets(s);
    i=j=0;
    res[j]=s[i];
    i+=2;
    j++;
    while (s[i]!='e')
    {
        res[j++]=s[i++];
    }
    res[j]='\0';
    i++;
    n=0;
    while (s[i]!='\0')
    {
        n=n*10+s[i]-'0';
        i++;
    }
    i=0;
    while (i<j && n>=0)
    {
        printf("%c",res[i]);
        i++;
        n--;
    }
    if (i<j)
    {
        printf(".");
        while (i<j)
        {
            printf("%c",res[i]);
            i++;
        }
    }
    while (n>=0)
    {
        printf("0");
        n--;
    }
    return 0;
}
