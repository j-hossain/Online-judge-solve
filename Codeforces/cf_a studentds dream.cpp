#include<stdio.h>
int main()
{
    int bl,br,gl,gr,mxl,mnl,mxr,mnr;
    scanf("%d %d",&gl,&gr);
    scanf("%d %d",&bl,&br);
    mxl=2*(gl+1);
    mxr=2*(gr+1);
    mnl=gl-1;
    mnr=gr-1;
    if(br>=mnl && br<=mxl)
        printf("YES\n");
    else if(bl>=mnr && bl<=mxr)
        printf("YES\n");
    else
        printf("NO\n");
}
