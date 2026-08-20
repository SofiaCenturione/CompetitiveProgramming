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
    int t;
    if(cin>>t){
        while(t--){
            int n,k;
    if(cin >> n>>k){
        DSU dsu(3*n);
        int falso=0;
        vector<pair<int,int>> redu;

        for(int i=0;i<k;i++){
            int tipo, u,v;
            cin>>tipo>>u>>v;
            if(u>n||v>n){
                falso++; continue;
            }
            if(tipo==2 && u==v){
                falso++; continue;
            }
            if(tipo==1){
                if(dsu.find(u+n) ==dsu.find(v) || dsu.find(v+n)==dsu.find(u)) falso++;
                else{
                    dsu.unite(u,v); dsu.unite(u+n,v+n);
                    dsu.unite(u+2*n, v+2*n);
                }
            }
            else{
                //tipo 2
                if(dsu.find(u)==dsu.find(v)||dsu.find(v+n)==dsu.find(u)) falso++;
                else{
                    dsu.unite(u+n,v);
                    dsu.unite(u,v+2*n);dsu.unite(u+2*n,v+n);
                }
            }
        }
        cout<<falso<<"\n";

        }
    }
    
}}