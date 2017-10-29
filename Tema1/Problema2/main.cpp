#include <iostream>
#include <vector>
#include <string.h>
#define N_MAX 10000
using namespace std;
int N, a, b, D[N_MAX], T[N_MAX], U[N_MAX];
vector<int> V[N_MAX];

void dfs(int nod) {

    if(V[nod].size() == 1) {
        D[nod] = 1;
        return;
    }

    int flag = 1;

    U[nod] = 1;
    for(int i = 0; i < V[nod].size(); ++i) {
        int vecin = V[nod][i];
        if(!U[vecin]) {
            T[vecin] = nod;
            dfs(vecin);
            if(D[vecin] == 1)
                flag = 0;
        }
    }

    if(flag)
        D[nod] = 1;
}

int main()
{

    cin >> N;
    for(int i = 0; i < N - 1; ++i) {
        cin >> a >> b;
        V[a].push_back(b);
        V[b].push_back(a);
    }


    dfs(1);

    for(int i = 1; i <= N; ++i)
        if(D[i])
            cout << i << " ";
    cout << '\n';

    return 0;
}
