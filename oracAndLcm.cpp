#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll mmc(ll a, ll b){
    return(a/gcd(a,b))*b;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;ll resp=0;
    cin>>n;
    vector<ll>a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    vector<ll>suf(n); //guarda o maximo divisor comum
    suf[n-1]=a[n-1];
    for(int i=n-2;i>=0;i--){
        suf[i]=gcd(a[i],suf[i+1]);
    }
    for(int i=0;i<n-1;i++){
        ll atual=mmc(a[i],suf[i+1]);
        resp=gcd(resp,atual);
    }
    cout<<resp<<"\n";
}