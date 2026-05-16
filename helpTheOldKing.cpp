#include <bits/stdc++.h>
#define ll long long

using namespace std;
const ll INF = 1e18;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m,root=1;
    cin>>n;
    vector<int> q(n+1);
    for(int i=1;i<=n;i++){
        cin>>q[i];
    }
    for(int i=2;i<=n;i++){
        if(q[i]>q[root])
            root=i;

    }
    cin>>m;
    vector<ll> melhor(n+1,INF);
    for(int i=0;i<m;i++){
        int a,b;
        ll c;
        cin>>a>>b>>c;
        melhor[b]=min(melhor[b], c);
    }

    ll resp=0;
    for(int i=1;i<=n;i++){
        if(i==root)continue;
        if(melhor[i]==INF){
            cout<<"-1\n";
            return 0;
        }

        resp+=melhor[i];
    }
    cout<<resp<<"\n";
}