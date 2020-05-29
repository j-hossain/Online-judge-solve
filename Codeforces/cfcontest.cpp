#include<stdio.h>
#include<string.h>
int main()
{
    long long int t,pos[200001],i,lenght,j,mx,temp;
    char str[200001];
    scanf("%lld",&t);
    while(t--)
    {
        mx=0;
        scanf("%s",str);
        lenght=strlen(str);
        pos[0]=0;
        for(i=0,j=1;i<lenght;i++)
        {
            if(str[i]=='R')
            {
                pos[j++]=i+1;
            }
        }
        pos[j]=lenght+1;
        for(i=0;i<j;i++)
        {
            if(pos[i+1]-pos[i]>mx)
                mx=pos[i+1]-pos[i];
        }
        printf("%lld\n",mx);
    }
    return 0;
}
