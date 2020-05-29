#include<stdio.h>
#include<string.h>

typedef struct
{
    int l;
    int p;
}lp;

int main()
{
    char strings[101][101],str1[101],str2[101];
    int n,i,j,k,l1,l2;
    lp lenghts[101],temp;

    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%s",strings[i]);
        lenghts[i].l=strlen(strings[i]);
        lenghts[i].p=i;
    }
    for(i=0;i<n-1;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if(lenghts[i].l<lenghts[j].l)
            {
                temp=lenghts[i];
                lenghts[i]=lenghts[j];
                lenghts[j]=temp;
            }
        }
    }
    for(i=0;i<n-1;i++)
    {
        strcpy(str1,strings[lenghts[i].p]);
        strcpy(str2,strings[lenghts[i+1].p]);
        l1=lenghts[i].l;
        l2=lenghts[i+1].l;
        for(j=0;j<=l1-l2;j++)
        {
            for(k=0;k<l2;k++)
            {
                if(str1[j+k]!=str2[k])
                    break;
            }
            if(k>=l2)
                break;
        }
        if(j>l1-l2)
            break;
    }
    if(i<n-1)
    {
        printf("NO\n");
    }
    else
    {
        printf("YES\n");
        for(i=n-1;i>=0;i--)
            printf("%s\n",strings[lenghts[i].p]);
    }
    return 0;

}
