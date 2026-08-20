#include <bits/stdc++.h>
using namespace std;
#define ll long long

struct DSU{
    vector<int> pai;
    vector<int> size;
    int max_size;

    //inicializando n elementos
    DSU(int n){
        pai.resize(n + 1);
        size.resize(n + 1, 1); 
        max_size = 1;          
        for (int i = 1; i <= n; i++) {
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
            max_size = max(max_size, size[gp1]);
        }
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    if(cin >> t){
        while(t--){
            int n,m;
            cin>>n>>m;
            
            DSU dsu(n);
            
            for(int i = 0; i < m; i++){
                int u,v;
                cin>>u>>v;
                dsu.unite(u, v);
            }
            
            if (n == 0) { //se n=0 o grupo é 0 
                cout << 0 << "\n";
            } else {
                cout << dsu.max_size << "\n";
            }
        }
    }
}