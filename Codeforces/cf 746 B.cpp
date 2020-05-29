#include<stdio.h>
#include<string.h>

int main()
{
    char st1[20001],st2[20001];
    int i,lenght,j;
    scanf("%d",&lenght);
    scanf("%s",st1);
    for(i=lenght-1,j=0;i>=0;j++)
    {
        st2[lenght-1-j]=st1[i];
        i--;
        if(i>=0)
        {
            st2[j]=st1[i];
            i--;
        }
    }
    st2[lenght]='\0';
    printf("%s\n",st2);
    return 0;
}
