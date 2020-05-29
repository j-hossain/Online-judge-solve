#include<stdio.h>
int main()
{
    int n,a,r;
    char clr[]={'R','O','Y','G','B','I','V'};
    char ans[101];

    scanf("%d",&n);
    int i=0;
    int j=0;
    while(i<n)
    {
        if(j>=7)
            j=0;
        ans[i++]=clr[j++];
    }

    r=n%7;
    if(r<=3 && r!=0)
    {
        i=n-r;
        j=3;
        while(i<n)
        {
            ans[i++]=clr[j++];
        }
    }

    ans[n]='\0';
    printf("%s\n",ans);
    return 0;
}
