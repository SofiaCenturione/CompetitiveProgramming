#include <bits/stdc++.h>
using namespace std; 
#define ll long long 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,x,MODULO=1e9+7;//the number of ways modulo
    cin>>n>>x;
    vector<int> c(n);
    for(int i=0;i<n;i++){
        cin>>c[i];
    }
    vector<int> dp(x+1,0);//preenche com 0 de tamanho n
    dp[0]=1;//caso base-n escolheu moeda nenhuma e isso é uma maneira
    for(int i=1;i<=x;i++){
        for(int j=0;j<n;j++){
            if(c[j]<=i) 
                dp[i]=(dp[i]+dp[i-c[j]])%MODULO;
        }
    }
    cout<<dp[x]<<"\n";
}