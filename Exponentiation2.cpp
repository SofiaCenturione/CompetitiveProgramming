#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll exponenciacaoBin(ll base, ll exp, ll mod){ //exponenciação binária: (base^exp) % mod
    ll res=1;
    base%=mod;
    while(exp>0){
        if(exp%2==1) res=(res*base)%mod;
        base=(base*base)%mod;
        exp/=2;
    }
    return res;
}

void resolve() {
    ll a,b,c;
    cin>>a>>b>>c;
    
    //calculando os modulos
    ll mod1=1e9+7;
    ll mod2=1e9+6;//(mod1 - 1) usando o Teorema de Fermat
    
    //calcular o expoente superior reduzido (b^c % mod2)
    ll eReduzido=exponenciacaoBin(b, c, mod2);
    
    //calculando o resultado final (a^eReduzido % mod1)
    ll resultado=exponenciacaoBin(a, eReduzido, mod1);    
    cout<<resultado<<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);    
    int n;
    cin>>n;
    while(n--){
        resolve();
    }
}