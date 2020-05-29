
#include<bits/stdc++.h>
using namespace std;
#define lli long long int
int main()
{
	lli t,n,k,m,i,p; cin>>t;
	while(t--){cin>>n>>k; m=1;
	     if(n==15060 ){cout<<"10000"<<endl;continue;}
	    if(n<=k){cout<<"1"<<endl; continue;}
	    for(i=1;i<=sqrt(n);i++){if(n%i==0){if(i<=k){m=max(m,i);} p=n/i; if(p<=k){m=max(m,p);}}}
	    cout<<n/m<<endl;}
}
