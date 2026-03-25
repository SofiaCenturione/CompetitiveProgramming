//precisa de um elemento lider, todos de sua frente saem e os maiores que vem depois dele também
#include <bits/stdc++.h>
using namespace std;  
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t,n;
    cin>>t;
    while(t--){
        cin>>n;
        vector<long long> v(n);
        for(int i=0;i<n;i++){
            cin>>v[i];
        }
        int custo=n,mantidos;
        for(int i=0;i<n;i++){
            mantidos=1;
            for(int j=i+1;j<n;j++){
                if(v[j]<=v[i]) mantidos++; //vendo os que vem dps do lider e devem ser menores ou iguais a ele
            }
            int ele_antes=i, ele_dps=(n-1-i)-(mantidos-1);//qtde de elementos dps do stalin sort
            custo=min(custo, ele_antes+ele_dps);
        }
        cout<<custo<<"\n";
    }
}