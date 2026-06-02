#include <bits/stdc++.h>
#define ll long long

using namespace std;
const ll INF = 1e18;

int pai[100005], tamanho[100005];
int find_set(int v){
    if(v==pai[v]) return v;
    return pai[v]=find_set(pai[v]);
}

bool union_set(int a, int b){
    a=find_set(a);
    b=find_set(b);

    if(a==b) return false;
    if(tamanho[a]<tamanho[b]) swap(a,b);
    pai[b]=a;
    tamanho[a]+=tamanho[b];
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;

    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        vector<vector<ll>> arestas;
        for(int i=0;i<m;i++){
            ll a,b,c;
            cin>>a>>b>>c;
            ll w = __builtin_ctzll(c);
            arestas.push_back({w,a,b});
        }

        //DSU
        for(int i=1;i<=n;i++){
            pai[i]=i;
            tamanho[i]=1;
        }
        sort(arestas.begin(), arestas.end());
        ll soma = 0;
        int usado = 0;
        for(auto &e:arestas){
            ll w=e[0];
            int u=e[1];
            int v=e[2];
            if(union_set(u,v)){
                soma+=w;
                usado++;
                if(usado==n-1) break;
            }
        }
        if(usado!=n-1){
            cout<<"0\n";
            continue;
        }
        cout<<soma+1<<"\n";
    }

}