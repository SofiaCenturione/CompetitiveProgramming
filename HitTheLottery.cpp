#include <bits/stdc++.h>
using namespace std; 
#define ll long long 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n;
    cin>>n;
    vector<ll> moedas={100,20,10,5,1};
    int tot=0;
    for(int i=0;i<5;i++){
        tot+=n/moedas[i];
        n%=moedas[i];
    }
    cout<<tot<<"\n";
}