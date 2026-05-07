#include <bits/stdc++.h>
#define ll long long

using namespace std;

double calcularDistanciaQuadrada(double x1, double y1, double x2, double y2) {
    return (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
}

int encontrarRaiz(int i, vector<int>& pai) {
    if (pai[i] == i) {
        return i;
    }
    return pai[i] = encontrarRaiz(pai[i], pai);
}

void resolverCaso(int numeroCaso) {
    int n;
    double d;
    cin >> n >> d;
    vector<double> vetorX(n);
    vector<double> vetorY(n);
    
    for (int i = 0; i < n; i++) {
        cin >> vetorX[i] >> vetorY[i];
    }

    vector<int> pai(n);
    for (int i = 0; i < n; i++) {
        pai[i] = i;
    }
    int componentes = n;

    double dQuadrado = d * d;
    double epsilon = 1e-9;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            double distSq = calcularDistanciaQuadrada(vetorX[i], vetorY[i], vetorX[j], vetorY[j]);
            if (distSq <= dQuadrado + epsilon) {
                int raiz_i = encontrarRaiz(i, pai);
                int raiz_j = encontrarRaiz(j, pai);                
                if (raiz_i != raiz_j) {
                    pai[raiz_i] = raiz_j;
                    componentes--; 
                }
            }
        }
    }
    cout << "Case " << numeroCaso << ": " << componentes << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (cin >> t) {
        for (int i = 1; i <= t; i++) {
            resolverCaso(i);
        }
    }
}