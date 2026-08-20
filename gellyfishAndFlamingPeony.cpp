#include <bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;cin>>t;
    while(t--){
        int n; cin>>n;
        vector<int> a(n);
        for(int i=0;i<n;i++){
            cin>>a[i];

        }
        int g=a[0];
        for(int i=1;i<n;i++){
            g=gcd(g,a[i]);
        }
        int cont=0;
        for(int i=0;i<n;i++){
            if(a[i]==g) cont++;
        }
        if(cont>0){
            cout<<n-cont<<"\n"; continue;

        }
        vector<int> unico=a, dist(5005,-1);
        sort(unico.begin(), unico.end());
        unico.erase(unique(unico.begin(),unico.end()), unico.end());
        queue<int> q;
        for(int x:unico){
            dist[x]=1;
            q.push(x);
        }
        int resp=-1;
        while(!q.empty()){
            int u=q.front();
            q.pop();
            for(int x: unico){
                int v=gcd(u,x);
                if(dist[v]==-1){
                    dist[v]=dist[u]+1;
                    if(v==g){
                        resp=dist[v];break;
                    }
                    q.push(v);
                }
            }
            if(resp!=-1) break;
        }
        cout<<n+resp-2<<"\n";
    }
}