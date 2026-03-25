#include <bits/stdc++.h>
using namespace std;  
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m,k,aux;
    cin>>n>>m>>k;
    vector<int> desejo(n);
    vector<int> tem(m);
    for(int i=0;i<n;i++){
        cin>>desejo[i];
    }
    for(int i=0;i<m;i++){
        cin>>tem[i];
    }
    sort(desejo.begin(), desejo.end());
    sort(tem.begin(), tem.end());
    int cont=0,i=0,j=0;
    while(i<n && j<m){
        if(tem[j]<desejo[i]-k){
            j++;
        }
        else if(desejo[i]+k<tem[j]){
            i++;
        }
        else{
            cont++;i++;j++;
        }
    }
    cout<<cont<<"\n";
}