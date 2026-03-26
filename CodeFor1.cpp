#include <bits/stdc++.h>
using namespace std; 
#define ll long long 

//calculando o comprimento total da lista
ll calculaComprimento(ll n){
    if(n<=1) return 1;
    return 2*calculaComprimento(n/2)+1;
}

//divide e conquista para contar 1s no intervalo l, r
ll conta(ll n, ll inicio, ll fim, ll l, ll r){
    //se está fora do intervalo desejado
    if(inicio>r||fim<l) return 0;    
    if(n<=1) return n;     
    ll meio=inicio+(fim-inicio)/2;
    ll total=0;
    
    //parte esquerda recursivo para n/2
    total+=conta(n/2,inicio,meio - 1,l,r);
    
    //parte central verifica se a posição do meio (n % 2) está no intervalo l, r
    if(meio>=l&&meio<=r) total+=(n%2);
        
    //parte direita recursivo para n/2
    total+=conta(n/2,meio+1,fim,l,r);    
    return total;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n,l,r;
    cin>>n>>l>>r;
    if(n==0){
        cout<<0<<"\n";
        return 0;
    }
    ll ctot=calculaComprimento(n);
    cout<<conta(n, 1, ctot, l, r)<<"\n";
    return 0;
}