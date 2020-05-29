#include<stdio.h>

int dif(int a,int b)
{
    return a>b?(a-b):(b-a);
}
int main()
{
    int n,even[55],odd[55],temp,flag;
    int i,t,e,o,j;
    scanf("%d",&t);
    while(t--)
    {
        flag=0;
        scanf("%d",&n);
        for(i=0,e=0,o=0;i<n;i++)
        {
            scanf("%d",&temp);
            if(temp%2)
                odd[o++]=temp;
            else
                even[e++]=temp;
        }
        if(e%2 && o%2)
        {
            for(i=0;i<e;i++)
            {
                for(j=0;j<o;j++)
                {
                    if(dif(even[i],odd[j])==1)
                    {
                        flag=1;
                        break;
                    }
                }
                if(flag)
                    break;
            }
        }
        else if(e%2==0 && o%2==0)
            flag=1;

        if(flag)
           printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}
