#include <iostream>
using namespace std;

int main() {
	// your code goes here

	int t,n,a[100005],b[100005];
	int i,s1,s2,dis;

	cin>>t;
	while(t--){

	    cin>>n;

	    for(i=1;i<=n;i++)
	        cin>>a[i];
	    for(i=1;i<=n;i++)
	        cin>>b[i];

	    a[0]=b[0]=i;
	    s1=s2=dis=0;
	    for(i=1;i<=n;i++){
	        s1+=a[i];
	        s2+=b[i];
	        if(s1==s2 && a[i]==b[i])
	            dis+=a[i];
	    }

	    std::cout << dis << std::endl;
	}

	return 0;
}
