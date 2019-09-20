#include <bits/stdc++.h>

using namespace std;
class Cano{
public:
    int cumprimento;
    int valor;
};
int cache[10];
int solve(int i,int comp,int N, int T, vector<Cano> & canos) {
    if (i>N)return cache[i];
    if (canos[i].cumprimento >T) return cache[i];

    if (cache[i] == -1){
        cache[i]=canos[i].valor;
        solve(i+1,canos[i].cumprimento-T,N,T,canos);
    }else if(cache[i] + canos[i].valor >= comp && comp >= canos[i].cumprimento){
        cache[i]+=canos[i].valor;
        solve(i,comp-canos[i].cumprimento,N,T,canos);
    }else{
        solve(i+1,comp,N,T,canos);
    }
}

int main() {
    int N;
    cin>>N;
    int T;
    cin>>T;
    vector<Cano> canos(N);
    for (int i = 0; i < N; ++i) {
        cin>>canos[i].cumprimento>>canos[i].valor;
    }
    memset(cache,0, sizeof(cache));
    solve(0, T, N, T,canos);
    cout<<cache[N-1]<<endl;
    return 0;
}