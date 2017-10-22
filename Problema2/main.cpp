#include <iostream>
#include <vector>
#include <string.h>
#define N_MAX 10000
using namespace std;

int U[N_MAX];

void DFS(int nod, int nivel, vector<int> V[], vector<int> Nivel[]) {

    Nivel[nivel].push_back(nod);

    U[nod] = 1;

    ///pasul de recurenta
    for(int i = 0; i < V[nod].size(); ++i)
        if(!U[V[nod][i]]) {
            DFS(V[nod][i], nivel + 1, V, Nivel);
        }

}

int main()
{
    int N, a, b, D[N_MAX], T[N_MAX];
    vector<int> V[N_MAX], Nivel[N_MAX];

    cin >> N;
    for(int i = 0; i < N - 1; ++i) {
        cin >> a >> b;
        V[a].push_back(b);
        V[b].push_back(a);
    }

    DFS(1, 1, V, Nivel);

    memset(D, 0, sizeof D);
    memset(T, 0, sizeof T);

    for(int i = 1; i <= N; ++i) {

        if(i == 1 || i == 2) {
            D[i] = Nivel[i].size();
            T[i] = 0;
            continue;
        }

        ///altfel verific nivel - 2 si - 3
        if(D[i - 2] > D[i - 3]) {
            D[i] = D[i - 2] + Nivel[i].size();
            T[i] = i - 2;
        }
        else {
            D[i] = D[i - 3] + Nivel[i].size();
            T[i] = i - 3;
        }

    }

    int lvl, maxD = 0;
    for(int i = 1; i <= N; ++i)
        if(D[i] > maxD)
            maxD = D[i], lvl = i;

    ///afisam rezultat
    while(lvl) {

        for(int i = 0; i < Nivel[lvl].size(); ++i)
            cout << Nivel[lvl][i] << " ";
        lvl = T[lvl];

    }

    return 0;
}
