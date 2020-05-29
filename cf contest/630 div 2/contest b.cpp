#include<stdio.h>
#include<vector>
#include<iostream>
using namespace std;

int main()
{
    vector<int>keep[12];
    int a,t,n,i,j,k,color[1005],c;
    int prime[12]={0,2,3,5,7,11,13,17,19,23,29,31};

    scanf("%d",&t);
    while(t--)
    {
        for(i=0;i<12;i++)
            keep[i].clear();
        scanf("%d",&n);
        int sz=0;
        for(i=0;i<n;i++)
        {
            scanf("%d",&a);
            for(j=11;j>0;j--)
            {
                if(a%prime[j]==0)
                {
                    keep[j].push_back(i);
                    break;
                }

            }
        }
        for(i=1,c=1;i<12;i++)
        {
            if(keep[i].size()>0)
            {
                for(j=0;j<keep[i].size();j++)
                {
                    color[keep[i][j]]=c;
                }
                c++;
            }
        }
        printf("%d\n",c-1);
        for(i=0;i<n;i++)
            printf("%d ",color[i]);
        printf("\n");
    }
    return 0;
}
