#include <iostream>
using namespace std;

int main() {
	// your code goes here

	int t,n,arr,sum,i;

	cin>>t;
	while(t--){
	    sum=0;
	    for(i=0;i<5;i++){
	     cin>>arr;
	     sum+=arr;
	    }
	    cin>>n;
	    if(sum*n>24*5)
	        std::cout << "Yes" << std::endl;
	   else
	   std::cout << "No" << std::endl;
	}
	return 0;
}
