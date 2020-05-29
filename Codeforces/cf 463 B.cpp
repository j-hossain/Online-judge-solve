#include<stdio.h>

int main()
{
    int n,arr[100001],i,energy,dollar;

    energy=dollar=0;
    arr[0]=0;

    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        scanf("%d",&arr[i]);
        energy+=(arr[i-1]-arr[i]);
        if(energy<0)
        {
            dollar-=energy;
            energy=0;
        }
    }
    printf("%d\n",dollar);
    return 0;
}
