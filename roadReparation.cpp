#include <bits/stdc++.h>
#define ll long long

using namespace std;

struct Aresta{
    int u,v;
    ll w;
    bool operator<(const Aresta &other) const{
        return w < other.w;
    }
};
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
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,m;
    ll custo=0;
    int usado=0;
    cin>>n>>m;
    vector<Aresta> arestas(m);
    for(int i=0;i<m;i++){
        cin>>arestas[i].u>>arestas[i].v>>arestas[i].w;
    }
    for(int i=1;i<=n;i++){//DSU
        pai[i]=i;
        tamanho[i]=1;
    }

    //ordenando as arestas por custo
    sort(arestas.begin(),arestas.end());
    for(auto &e : arestas){
        if(union_set(e.u,e.v)){
            custo+=e.w;
            usado++;
            if(usado==n-1) break;
        }
    }
    if(usado!=n-1)//se conectou tudo
        cout<<"IMPOSSIBLE\n";
    else 
        cout<<custo<<"\n";
    

}