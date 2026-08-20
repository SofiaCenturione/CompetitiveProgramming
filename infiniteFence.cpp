#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll gcd(ll a,ll b){
    while(b){
        a%=b;
        swap(a,b);
    }
    return a;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin>>t;
    while(t--){
        ll r,b,k;
        cin>>r>>b>>k;
        ll maxst=max(r,b);
        ll minst=min(r,b);
        ll g=gcd(maxst,minst);
        ll nr=maxst/g, nb=minst/g;
        ll consec=(nr+nb-2)/nb;
        if(consec>=k)
            cout<<"REBEL\n";
        else cout<<"OBEY\n";
    }
}