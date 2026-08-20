#include <bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    cin>>s;
    int n=s.length();
    s+=s;//concatena
    int i=0,j=1,k=0;
    while(i<n && j<n && k<n){
        if(s[i+k]==s[j+k])
            k++;
        else{
            if(s[i+k]>s[j+k])
                i+=k+1;
            else j+=k+1;
            if(i==j)
                j++;

            k=0;
        }
    }
    int resp=min(i,j);
    cout<<s.substr(resp,n)<<"\n";
}