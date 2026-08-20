#include <bits/stdc++.h>
using namespace std;
const int mod=1e9+7;
const int maxn=1000005;
int trie[maxn][26], cont=1;
bool epala[maxn];

void insert(const string& palavra){
    int no=0;
    for(char c: palavra){
        int idx=c-'a';
        if(!trie[no][idx]){
            trie[no][idx]=cont++;
        }
        no=trie[no][idx];
    }
    epala[no]=true;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    cin>>s;
    int n=s.length();
    int k;
    cin>>k;
    for(int i=0;i<k;i++){
        string wo;
        cin>>wo;
        insert(wo);
    }
    vector<int>dp(n+1,0);
    dp[0]=1;
    for(int i=0;i<n;i++){
        if(dp[i]==0)continue;
        int no=0;
        for(int j=i;j<n;j++){
            int c=s[j]-'a';
            if(!trie[no][c]){
                break;
            }
            no=trie[no][c];
            if(epala[no])
                dp[j+1]=(dp[j+1]+dp[i])%mod;
        }
    }
    cout<<dp[n]<<"\n";
}