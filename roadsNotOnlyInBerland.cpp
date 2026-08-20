#include <bits/stdc++.h>
using namespace std;

struct DSU{
    vector<int> pai;
    vector<int> size;

    //inicializando n elementos
    DSU(int n){
        pai.resize(n + 1);
        size.resize(n + 1, 1);          
        for (int i = 0; i <= n; i++) {
            pai[i] = i;     
        }
    }

    int find(int i){
        if(pai[i] == i)
            return i;
        return pai[i] = find(pai[i]); 
    }

    void unite(int i, int j){
        int gp1 = find(i);
        int gp2 = find(j);
        if(gp1 != gp2){
            if (size[gp1] < size[gp2]) {
                swap(gp1, gp2);
            }            
            pai[gp2] = gp1;         
            size[gp1] += size[gp2];    
        }
    }
};


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    if(cin >> n){
        DSU dsu(n);
        vector<pair<int,int>> redu;

        for(int i=0;i<n-1;i++){
            int u,v;
            cin>>u>>v;
            if(dsu.find(u)==dsu.find(v)) redu.push_back({u,v});
            else dsu.unite(u,v);

        }

        vector<int> raizes;
        for(int i=1;i<=n;i++){
            if(dsu.pai[i]==i)
                raizes.push_back(i);
        }

        cout<<redu.size()<<"\n";
        for(size_t i=0; i<redu.size(); i++){
            int velhau=redu[i].first;
            int velhav=redu[i].second;
            int novau=raizes[i], novav=raizes[i+1];
            cout<<velhau<<" "<<velhav<<" "<<novau<<" "<<novav<<"\n";
        }

}}