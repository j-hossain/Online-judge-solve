#include<stdio.h>
int main()
{
    int n,i,notes[]={100,20,10,5,1};
    int cnt=0;
    scanf("%d",&n);
    i=0;
    while(n>0)
    {
        cnt+=(n/notes[i]);
        n%=notes[i++];
    }
    printf("%d\n",cnt);
    return 0;
}
