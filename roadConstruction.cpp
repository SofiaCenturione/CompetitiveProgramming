#include <bits/stdc++.h>
#define ll long long

using namespace std;

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

    cin>>n>>m;
    int componente=n, maxi=1;
    for(int i=1;i<=n;i++){//DSU
        pai[i]=i;
        tamanho[i]=1;
    }

    while(m--){
        int a,b;
        cin>>a>>b;
        if(union_set(a,b)){
            componente--;
            int root=find_set(a);
            maxi=max(maxi,tamanho[root]);
        }
        cout<<componente<<" "<<maxi<<"\n";
    }

}