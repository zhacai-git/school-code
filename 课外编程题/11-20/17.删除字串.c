#include <stdio.h>
#include <string.h>
int main()
{
    char s[100]={'\0'},b[100]={'\0'},t[100]={'\0'};
    int flag;
    int i=0,j=0;
    gets(s);
    gets(t);
    while (s[i]!='\0')
    {
        if (s[i]==t[0])
        {
            int k=1;
            flag=0;
            while (t[k]!='\0')
            {
                if (s[i+k]!=t[k])
                {
                    flag=1;
                    break;
                }
                k++;
            }
            if (flag==0)
            {
                i+=strlen(t);
                continue;
            }
        }
        b[j++]=s[i++];
    }
    b[j]='\0';
    puts(b);
    return 0;
}
