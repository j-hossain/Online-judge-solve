#include<stdio.h>
#include<string.h>
#include<ctype.h>
int main()
{
	char x[200],i,a[1000]={},j;
	scanf("%s",x);
	for(i=0;i<strlen(x);i++)
	{
		x[i]=tolower(x[i]);
	}
	for(i=0,j=0;i<strlen(x);i++)
	{
		if(!((x[i]=='a')||(x[i]=='e')||(x[i]=='i')||(x[i]=='o')||(x[i]=='u')||(x[i]=='y')))
		{
			a[j]='.';
			a[j+1]=x[i];
			j+=2;
		}
	}
	printf("%s\n",a);
}