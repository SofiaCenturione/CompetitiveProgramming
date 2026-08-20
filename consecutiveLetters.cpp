#include <bits/stdc++.h>
using namespace std;

struct DSU{
    vector<int> pai;
    vector<int> size;

    //inicializando n elementos
    DSU(int n){
        pai.resize(n + 1);
        size.resize(n + 1, 1);          
        for (int i = 0; i <= n; i++) {
            pai[i] = i;     
        }
    }

    int find(int i){
        if(pai[i] == i)
            return i;
        return pai[i] = find(pai[i]); 
    }

    void unite(int i, int j){
        int gp1 = find(i);
        int gp2 = find(j);
        if(gp1 != gp2){
            if (size[gp1] < size[gp2]) {
                swap(gp1, gp2);
            }            
            pai[gp2] = gp1;         
            size[gp1] += size[gp2];    
        }
    }
};

struct Query {
    int type;
    int idx;
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    if(cin >> t){
        for(int tx=1; tx<=t; tx++){
           string s;
           cin>>s;
           int q;
           cin>>q;
           vector<Query> queries(q+1);
           vector<int> deletec(s.size(),0);
            for (int i=0;i<q;i++){
                cin>>queries[i].type>>queries[i].idx;
                if(queries[i].type==2)
                    deletec[queries[i].idx]++;
            }
            string curs=s;
            int aux=(int)s.size();
            for(int i=0; i<aux;i++){
                if (deletec[i]>0) curs[i]='#';
            }
            DSU dsu(aux);
            for(int i=0;i<aux-1;i++){
                if(curs[i]!='#' && curs[i]==curs[i+1])
                    dsu.unite(i, i+1);
            }

            vector<int> resp;
            for(int j=q-1;j>=0;j--){
                int tp=queries[j].type;
                int idx=queries[j].idx;
                if(tp==1) resp.push_back(dsu.size[dsu.find(idx)]);
                else{
                    deletec[idx]--;
                    if(deletec[idx]==0){
                        curs[idx]=s[idx];
                        if(idx>0 && curs[idx-1]==curs[idx]) dsu.unite(idx, idx-1);
                        if(idx<aux-1 && curs[idx+1]==curs[idx]) dsu.unite(idx, idx+1);
                    }
                    
                }
            }
            reverse(resp.begin(), resp.end());
            cout<<"Case "<<tx<<":\n";
            for(int rs:resp)
                cout<<rs<<"\n";
        }
    }
}