#include<stdio.h>
// not accepted
int main()
{
    int n,arr[100005],cumu[100005],i,mxi,mni,mx,mxc,mnc,sum;

    scanf("%d",&n);
    mnc=30*100000+10;
    mxc=-mnc;
    for(i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
        cumu[i]=arr[i];
        if(i>0)
            cumu[i]+=cumu[i-1];
        if(arr[i]>mxc)
        {
            mxc=arr[i];
            mxi=i;
        }
        if(arr[i]<mnc)
        {
            mnc=arr[i];
            mni=i;
        }
    }
    mnc=mni<mxi?mni:mxi;
    mxc=mni>mxi?mni:mxi;
    mx=-35;
    sum=0;
    for(i=mnc;i<=mxc;i++)
    {
        sum+=arr[i];
        if(arr[i]>mx)
                mx=arr[i];
    }
    sum-=mx;
    if(sum>0)
        printf("%d\n",sum);
    else
        printf("0\n");
}
