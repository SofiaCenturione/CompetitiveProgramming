#include <bits/stdc++.h>
using namespace std;

struct DSU{
    vector<int> pai;
    vector<int> size;

    //inicializando n elementos
    DSU(int n){
        pai.resize(n + 1);
        size.resize(n + 1, 1);          
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
        }
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int q;
    if(cin >> q){
        while(q--){
            int n;
            
            cin>>n;
            DSU dsu(n);
            vector<int> p(n+1);
            for(int k=1;k<=n;k++)
            {
                cin>>p[k];
                dsu.unite(k, p[k]);//talvez tenha q fazer num for dps
            }
            for(int j=1; j<=n; j++){
                cout<<dsu.size[dsu.find(j)]<<" ";
                
            }
            cout<<"\n";
        }
    }
}