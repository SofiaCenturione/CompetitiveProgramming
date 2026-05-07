#include <bits/stdc++.h>
#define ll long long
#define inf 1e18

using namespace std;

int n, m,q;


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int a,b;
    ll c;
    cin>>n>>m>>q;
    vector<vector<ll>> dist(n+1, vector<ll>(n+1, inf));
    for(int i=1;i<=m;i++)
        dist[i][i] = 0;
    for(int i=0;i<m;i++){
        cin>>a>>b>>c;            
        dist[a][b] = min(dist[a][b], c);
        dist[b][a] = min(dist[b][a], c);
    }
    
    for (int k = 1; k <= n; k++){
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            if (dist[i][k] != inf && dist[k][j] != inf)
                dist[i][j] = min(dist[i][j],dist[i][k] + dist[k][j]);
                
    }}}
    while(q--){
        cin>>a>>b;
        if (dist[a][b]==inf)
            cout<<"-1";
        else
            cout<<dist[a][b];
        cout<<"\n";
    }
}