#include <bits/stdc++.h>
#define ll long long

using namespace std;

int calculaNivel(int id_funcionario, const vector<int>& gerente) {
    int nivel = 0;
    int atual = id_funcionario;
    while (atual != -1) {
        nivel++;
        atual = gerente[atual];
    }    
    return nivel;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;

    if (cin >> n) {
        vector<int> gerente(n + 1);        
        for (int i = 1; i <= n; i++) {
            cin >> gerente[i];
        }
        int minimos = 0;

        for (int i = 1; i <= n; i++) {
            int nivelAtual = calculaNivel(i, gerente);
            minimos = max(minimos, nivelAtual);
        }
        cout << minimos << "\n";
    }

}