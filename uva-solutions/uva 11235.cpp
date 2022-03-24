#include<stdio.h>
#define mx 100005

int arr[mx];
int tree[mx*4];
int freq[mx];
int sta[mx];

void ready(int node, int start, int endd)
{
    if(start==endd)
    {
        tree[node]=freq[start];
        return ;
    }

    int mid = (start+endd)/2;

    int l = 2*node;
    int r = l+1;

    ready(l,start,mid);
    ready(r,mid+1,endd);
    tree[node]=tree[l]>tree[r]?tree[l]:tree[r];
}

int ask(int node,int low,int high,int qlow,int qhigh)
{
    if(low>qhigh || high<qlow)
        return -1;
    if(qlow<=low && high<=qhigh)
        return tree[node];
    int mid=(low+high)/2;
    int left=2*node;
    int right=2*node+1;
    int l=ask(left,low,mid,qlow,qhigh);
    int r=ask(right,mid+1,high,qlow,qhigh);

    if(l==-1)
        return r;
    if(r==-1)
        return l;
    return l>r?l:r;
}

int main()
{
    //freopen("uvaOut.txt","w+",stdout);
    int i,sz,j,qr,cnt1,cnt2,cnt3,k; //sz:sizeOfArray; qr:queryNumbers;
    while(scanf("%d",&sz) && sz)
    {
        scanf("%d",&qr);

        for(i=0;i<sz;i++)
        {
            scanf("%d",&arr[i]);
        }
        sta[0]=0;
        for(j=0,i=1;i<sz;i++)
        {
            if(arr[i]!=arr[i-1] || i==sz-1)
            {
                if(i==sz-1)
                {
                    sta[i]=j;
                    i++;
                }

                cnt1=i-j;
                while(j<i)
                {
                    freq[j++]=cnt1;
                }
            }
            sta[i]=j;
        }

        ready(1,0,sz-1);

        while(qr--)
        {
            scanf("%d %d",&i,&j);
            i--;
            j--;
            if(arr[i]!=arr[j])
            {
                k = sta[i]+freq[i];
                cnt1 = k-i;
                cnt2 = j - sta[j] + 1;
                cnt3 = ask(1,0,sz-1,k,sta[j]-1);

                //printf("working\n");
                cnt1 = cnt1>cnt2?cnt1:cnt2;
                cnt1 = cnt1>cnt3?cnt1:cnt3;

                printf("%d\n",cnt1);
            }
            else
                printf("%d\n",j-i+1);
        }
    }
    return 0;
}


