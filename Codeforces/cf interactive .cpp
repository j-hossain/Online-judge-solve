#include<stdio.h>
#include<string.h>

int main()
{
    int l,m,h;
    char in[3];
    l=1;
    h=1000000;
    while(l<=h)
    {
        m=(l+h)/2;

        printf("%d\n",m);
        fflush(stdout);
        scanf("%s",&in);
        if(!strcmp(in,"<"))
            h=m-1;
        else
            l=m+1;
    }
    printf("! %d\n",h);
    return 0;
}
