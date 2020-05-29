#include<stdio.h>

int main()
{
    int i,j,pos,t,n,mn,mx,cnt;
    int arr[10];
    scanf("%d",&t);
    while(t--)
    {
        mn=mx=0;

        scanf("%d",&n);
        for(i=0;i<n;i++)
        {
            scanf("%d",&arr[i]);
        }

        for(pos=0;pos<n;pos++)
        {
            cnt=1;
            i=pos+1;
            j=pos-1;

            while(i<n)
            {
                if(arr[i]-arr[i-1]>2)
                    break;
                cnt++;
                i++;
            }
            while(j>=0)
            {
                if(arr[j+1]-arr[j]>2)
                    break;
                cnt++;
                j--;
            }

            if(!mn || cnt<mn)
                mn=cnt;
            if(cnt>mx)
                mx=cnt;
        }

        printf("%d %d\n",mn,mx);
    }
    return 0;
}
