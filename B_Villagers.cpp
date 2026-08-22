#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--){
	    ll n,sum=0;
	    cin>>n;
	    vector<ll>a(n);
	    for(int i=0;i<n;i++){
	        cin>>a[i];
	    }
	    
	    sort(a.begin(),a.end());
	    for(int i=n-1;i>=0;i-=2){
	        sum+=a[i];
	    }
	    cout<<sum<<endl;
	}
}