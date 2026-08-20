#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    ll a,b;
    cin>>t;
    while(t--){
        cin>>a>>b;
        if((a+b)%3==0 && 2*a>=b &&2*b>=a){
            cout<<"YES\n";

        }
        else cout<<"NO\n";
    }
}