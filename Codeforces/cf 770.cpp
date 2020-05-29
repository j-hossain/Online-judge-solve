#include<stdio.h>
int main()
{
    int n,k,i,j;
    scanf("%d %d",&n,&k);
    i=j=0;
    while(i<n)
    {
        j=0;
        while(j<k && i<n)
        {
            printf("%c",'a'+j);
            j++;
            i++;
        }
    }
    printf("\n");
    return 0;
}
