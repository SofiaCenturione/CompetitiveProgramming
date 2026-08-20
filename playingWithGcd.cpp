#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll mmc(ll a,ll b){
    return(a/gcd(a,b))*b;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        int n; cin>>n;
        vector<int>a(n);
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        vector<ll> b(n+1);
        b[0]=a[0];
        for(int i=1;i<n;i++){
            b[i]=lcm(a[i-1],a[i]);
        }
        b[n]=a[n-1];
        bool da=true;
        for(int i=0;i<n;i++){
            if(gcd(b[i],b[i+1])!= a[i]){
                da=false;
                break;
            }
        }
        if(da){
            cout<<"YES\n";
        }
        else cout<<"NO\n";
    }
}