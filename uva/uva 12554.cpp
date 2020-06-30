#include<stdio.h>

int main()
{
    int n,i,j,flag;
    char name[100][100];
    char song[16][10] = {"Happy", "birthday", "to", "you", "Happy", "birthday", "to", "you", "Happy", "birthday", "to", "Rujia", "Happy", "birthday", "to", "you"};

    scanf("%d",&n);
    i=0;
    flag=1;
    while(i<n)
    {
        scanf("%s",name[i]);
        i++;
    }
    i=j=0;
    while(flag || j<16)
    {
        if(i==n)
        {
            i=flag=0;
        }
        if(j==16)
            j=0;
        printf("%s: %s\n",name[i],song[j]);
        i++;
        j++;
    }
    return 0;
}
