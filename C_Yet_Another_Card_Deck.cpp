#include <bits/stdc++.h>
using namespace std;
using ll=long long;

void solve(){
    ll n,x,y;
    cin>>n>>x>>y;
    ll lcm_val = lcm(x,y);
    ll ex=n/x,ey=n/y,comm=n/lcm_val;
    ll sum1=0,sum2=0;
    for(int i=1;i<=ey-comm;i++){
        sum1+=i;
    }
    for(int i=1;i<=ex-comm;i++){
        sum2+=n;
        n--;
    }
    cout<<sum2-sum1<<endl;

}

int main() {
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}
