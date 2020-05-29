#include<stdio.h>

void cpy( char *a,char *b,int n){
    int i;
    for(i=0;i<=n;i++)
        a[i]=b[i];
}

int check(char *a, char *b, int n)
{
    int i,cnt;
    cnt=0;
    for(i=0;i<n;i++)
        if(a[i]!=b[i])
            cnt++;

    return (cnt<=1);
}

int main(){

    int t,n,m,i,j,k,cnt;
    char sts[15][15],temp[15];

    scanf("%d",&t);
    while(t--){

        scanf("%d %d",&n,&m);

        for(i=0;i<n;i++){
            scanf("%s",sts[i]);
        }

        for(i=0;i<m;i++){

            cpy(temp,sts[0],m);

            for(j='a';j<='z';j++){

                cnt=1;
                temp[i]=j;

                for(k=1;k<n;k++){
                    if(check(temp,sts[k],m))
                        cnt++;
                }
                if(cnt==n)
                    break;
            }
            if(cnt==n)
                break;
        }

        if(cnt==n)
            printf("%s\n",temp);
        else
            printf("-1\n");
    }
    return 0;
}
