#include<stdio.h>

int main()
{
	#ifdef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w+",stdout);
    #endif
	/* code */

    int a;
	scanf("%d",&a);
	printf("%d\n",a);
	return 0;
}