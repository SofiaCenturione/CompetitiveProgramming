#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll n_val,k_val,a,b;
vector<int> posi;

//quantos vingadores estão no intervalo l, r em O(log k)
int contaV(ll l, ll r){
    auto it1=lower_bound(posi.begin(), posi.end(), l);
    auto it2=upper_bound(posi.begin(), posi.end(), r);
    return distance(it1, it2);
}

ll calculaP(ll l, ll r){
    int na=contaV(l, r);
    ll custo_queimar;
    if(na==0){
        custo_queimar=a;
    } 
    else{
        custo_queimar=(ll)b*na*(r-l+1);
    }

    //se o tamanho é 1 ou não há vingadores
    if(l==r||na==0){
        return custo_queimar;
    }

    //comparando o custo de queimar com o custo de dividir
    ll meio=l+(r-l)/2;
    ll custo_dividir=calculaP(l, meio)+calculaP(meio + 1, r);
    return min(custo_queimar, custo_dividir);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n_val>>k_val>>a>>b;
    posi.resize(k_val);
    for(int i=0;i<k_val;i++){
        cin>>posi[i];
    } 
    sort(posi.begin(), posi.end());
    ll tamanho_base=(1LL << n_val);//2^n
    cout<<calculaP(1, tamanho_base)<<"\n";
    return 0;
}