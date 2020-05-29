#include<stdio.h>

int main()
{
    int l,i,s,e;
    char road[1004];
    scanf("%d",&l);
    scanf("%s",road);
    for(i=0;i<l;i++)
    {
        if(road[i]!='.')
        {
            s=i;
            while(road[i]!='.')
                i++;
            e=i-1;
        }
    }
    i=s;
    while(i<l)
    {
        if(road[i]!=road[i+1])
            break;
        i++;
    }
    if(i!=e)
        e=i;
    else
        e++;

    if(road[s]=='L')
    {
        i=e;
        e=s-1;
        s=i-1;
    }

    printf("%d %d\n",s+1,e+1);
    return 0;
}
