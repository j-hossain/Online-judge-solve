#include<stdio.h>
#include<string.h>

void inline inout()
{
    #ifndef ONLINE_JUDGE
    freopen("F:/Problem Solving/Online judges/input.txt","r",stdin);
    freopen("F:/Problem Solving/Online judges/output.txt","w",stdout);
    #endif
}

char inp[55],temp;
int i,j,n,mapi[1225],num,arr[55],dis,d,s;

int main()
{
    inout();
    int t,len;
    scanf("%d",&t);
    for(i=0;i<n;i++)
        mapi[i]=0;
    while(t--)
    {
        scanf("%s",inp);
        scanf("%d",&n);
        for(i=0;i<n;i++)
        {
            scanf("%d",&arr[i]);
            mapi[arr[i]]++;
        }

        len = strlen(inp);

        for(i=0;i<len-1;i++)
        {
            for(j=i;j<len;j++)
            {
                if(inp[i]>inp[j])
                {
                    temp = inp[i];
                    inp[i] = inp[j];
                    inp[j] = temp;
                }
            }
        }

        printf("%s\n",inp);
        for(i=0;i<len;i++)
        {
            s=i+1;
            while(inp[i]==inp[s] && s<len)
                s++;


            for(j=0;j<len;j++)
            {
                if(j<s)
                {
                    d = len-s;
                    dis = s-j;
                    d = (d*(d+1))/2;
                    dis += d;
                    printf("%d\n",dis);
                }
            }

        }
    }
}
