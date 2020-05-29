#include<stdio.h>

int arr[100005];
int tree[400005];
int nd;

void ready(int node, int start, int endd)
{
    if(start==endd)
    {
        tree[node]=arr[start];
        return;
    }
    int mid=(start+endd)/2;
    int left=node*2;
    int right=left+1;
    ready(left,start,mid);
    ready(right,mid+1,endd);
    tree[node]=tree[right]<tree[left]?tree[right]:tree[left];
    if(node>nd)
        nd=node;
}

int ask(int node, int start, int endd, int i, int j)
{
    if(endd<i || start>j)
        return -1;
    if(start>=i && endd<=j)
        return tree[node];
    int left=node*2;
    int right=left+1;
    int mid=(start+endd)/2;
    left=ask(left,start,mid,i,j);
    right=ask(right,mid+1,endd,i,j);
    if(left==-1)
        return right;
    if(right==-1)
        return left;

    return right<left?right:left;
}

int main()
{
    //freopen("output.txt","w+",stdout);

    int n,i,j,ans,q,t,tk;
    tk=0;
    scanf("%d",&t);
    while(t--)
    {
        tk++;
        nd=0;
        scanf("%d %d",&n,&q);
        for(i=1;i<=n;i++)
        {
            scanf("%d",&arr[i]);
        }
        ready(1,1,n);
        printf("Case %d:\n",tk);
        while(q--)
        {
            scanf("%d %d",&i,&j);
            ans=ask(1,1,n,i,j);
            printf("%d\n",ans);
        }
    }
}
