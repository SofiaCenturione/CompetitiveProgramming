#include <bits/stdc++.h>
using namespace std;  
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int q;
    long long n, custo,a,b;
    cin>>q;
    while(q--){
        custo=0;
        a=0;b=0;n=0;
        cin>>n>>a>>b;
        if(2*a<=b) custo=n*a;
        else if(b<2*a) custo=((n/2)*b+(n%2)*a);
        cout<<custo<<"\n";
    }
}