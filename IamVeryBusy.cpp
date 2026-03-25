#include <bits/stdc++.h>
using namespace std;  
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t,n,m,p;
    
    cin>>t;
    while(t--){
        cin>>n;
        vector<pair<int,int>> v(n);
        for(int i=0;i<n;i++){
            cin>>m>>p;
            v[i]={p,m};
        }
        sort(v.begin(),v.end());
        int cont=0,temp=-10;
        for(int i=0;i<n;i++){
            if(v[i].second>=temp){
                cont++;
                temp=v[i].first;
            }
        }
        cout<<cont<<"\n";
    }
}