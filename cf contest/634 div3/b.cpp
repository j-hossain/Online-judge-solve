#include<stdio.h>
int main()
{
    char ans[2005],alpha[27];
    int a,b,n,t,i,j;
    scanf("%d",&t);
    for(i=0;i<26;i++)
        alpha[i]='a'+i;
    while(t--)
    {
        scanf("%d %d %d",&n,&a,&b);
        for(i=0,j=0;i<n;i++)
        {
            if(j==b)
                j=0;
            ans[i]=alpha[j++];
        }
        ans[n]='\0';
        printf("%s\n",ans);
    }
    return 0;
}
