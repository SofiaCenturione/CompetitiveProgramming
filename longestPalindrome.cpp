#include <bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    cin>>s;
    int n=s.length();
    if(n==0) return 0;

    int m=2*n+3;
    string t(m,'#');
    t[0]='^';
    t[m-1]='$';
    for(int i=0;i<n;i++){
        t[2*i+2]=s[i];   
    }



    vector<int> p(m,0);
    int c=0,r=0;
    int maxl=0, cont=0;
    for(int i=1;i<m-1;i++){
        int aux=2*c-i;
        if(i<r)
            p[i]=min(r-i,p[aux]);
        else
            p[i]=0;
        while(t[i+1+p[i]] == t[i-1-p[i]] ){
            p[i]++;

        }
        if(i+p[i]>r){
            c=i;
            r=i+p[i];
        }
        if(p[i]>maxl){
            maxl=p[i];
            cont=i;
        }
    }
    int ini=(cont-1-maxl)/2;
        cout<<s.substr(ini,maxl)<<"\n";
}