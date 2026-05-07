#include <bits/stdc++.h>
#define ll long long

using namespace std;


void bfs(int ini, int n, const vector<vector<int>>& adj, int& maisdist, int& max) {
    vector<int> dist(n+1,-1);
    queue<int> fila;
    fila.push(ini);
    dist[ini] = 0;    
    maisdist = ini;
    max = 0;

    while (!fila.empty()){
        int atual = fila.front();
        fila.pop();

        for (int vizinho : adj[atual]) {
            if (dist[vizinho] == -1) { 
                dist[vizinho] = dist[atual] + 1;
                fila.push(vizinho);
                
                if (dist[vizinho] > max) {
                    max = dist[vizinho];
                    maisdist = vizinho;
                }
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,u,v;
    if (cin >> n){
        vector<vector<int>> adj(n + 1);
        for (int i = 0; i < n - 1; i++) {
            cin>>u>>v;
            adj[u].push_back(v);
            adj[v].push_back(u); 
        }
        if (n == 1) {
            cout<<0<<"\n";
            return 0;
        }
        int extre1 = 1, dist1 = 0;
        bfs(1, n, adj, extre1, dist1);

        int extre2 = 1, diametro = 0;
        bfs(extre1, n, adj, extre2, diametro);
        cout << diametro << "\n";
    }
}