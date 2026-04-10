#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string a,b;
    cin>>a>>b;
    int n=a.size(), m=b.size();
    vector<int> antes(m+1), atual(m+1);

    for(int j=0;j<=m;j++){
        antes[j]=j;
    }

    for(int i=1;i<=n;i++){
        atual[0]=i;

        for(int j=1;j<=m;j++){
            if(a[i-1]==b[j-1]){
                atual[j]=antes[j-1];
            } 
            else {
                atual[j]=1+min({antes[j],// remover
                    atual[j - 1],  // adicionar
                    antes[j - 1]   // substituir
                });
            }
        }
        swap(antes,atual);
    }
    cout << antes[m] << '\n';
}