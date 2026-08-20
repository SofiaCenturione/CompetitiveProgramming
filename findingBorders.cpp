#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    cin>>s;
    int n=s.length();
    vector<int> kmp(n,0), borda;
    for(int i=1;i<n;i++){
        int j=kmp[i-1];
        while(j>0 && s[i]!=s[j]){
            j=kmp[j-1];
        }
        if(s[i]==s[j]){
            j++;
        }
        kmp[i]=j;
    }
    int k=kmp[n-1];
    while(k>0){
        borda.push_back(k);
        k=kmp[k-1];
    }
    reverse(borda.begin(),borda.end());
    for(int i=0;i<borda.size();i++){
        cout<<borda[i]<<(i==borda.size()-1?"":" ");
    }
    cout<<"\n";
}