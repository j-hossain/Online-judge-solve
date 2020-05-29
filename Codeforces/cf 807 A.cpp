#include<stdio.h>
#include<algorithm>
#include<iostream>

using namespace std;

int main()
{
    int a[10001],b[10001];
    int n,i,flag,j;
    flag=0;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d %d",&a[i],&b[i]);
        if(a[i]!=b[i])
            flag=1;
    }
    if(!flag)
    {
        flag=0;
        for(i=0;i<n;i++)
        {
            for(j=i+1;j<n;j++)
            {
                if(a[i]<b[j])
                {
                    flag=1;
                    break;
                }
            }
            if(flag)
                break;
        }
        if(flag)
            printf("unrated \n");
        else
            printf("maybe\n");
    }
    else
        printf("rated\n");
    return 0;
}
