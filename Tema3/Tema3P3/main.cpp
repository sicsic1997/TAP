/*
* D[i][j] = latura maxima a patratului care are coltul din dreapta jos in i,j
* D[i][j] = 0, daca V[i][j] = 1 (nu formeaza un patrat)
* D[i][j] = min(D[i - 1][j], min(D[i - 1][j - 1], D[i][j - 1])) + 1, daca V[i][j] = 0;
* adica se adauga fie ca si coloana la patratul care se termina la stanga patratelului,
* fie ca linie sub patratul care se termina deasupra patratelului
* (prin se termina intelegem ca acolo se afla coltul din dreapta jos)
* Conditie pentru adunare la nr de patrate cu latura >= k
* if(D[i][j] >= K)
*       S += D[i][j] - K + 1;
*/

#include <fstream>
#include <string.h>
#define Nmax 500
using namespace std;
ifstream f("d.in");
ofstream g("d.out");


void citire(int& N, int& M, int V[Nmax][Nmax], int &K) {

    f >> N >> M;
    for(int i = 1; i <= N; ++i)
        for(int j = 1; j <= M; ++j)
            f >> V[i][j];
    f >> K;

}

void solve(int N, int M, int V[Nmax][Nmax], int D[Nmax][Nmax], int K) {

    memset(D, 0, sizeof D);

    int maxi = 0, cx, cy, S = 0;
    for(int i = 1; i <= N; ++i)
    for(int j = 1; j <= M; ++j) {
            //g << V[i][j] << " ";
            if(V[i][j] == 1)
                D[i][j] = 0;
            else
                D[i][j] = min(D[i - 1][j], min(D[i - 1][j - 1], D[i][j - 1])) + 1;

            if(D[i][j] > maxi)
                maxi = D[i][j], cx = i, cy = j;

            if(D[i][j] >= K)
                S += D[i][j] - K + 1;
        }

    /*for(int i = 1; i <= N; ++i) {
        for(int j = 1; j <= M; ++j)
            g << D[i][j] << " ";
        g << '\n';
    }*/

    g << "Colt stanga sus: " << cx - maxi + 1 << "," << cy - maxi + 1 << " cu lungimea " << maxi << '\n';
    g << "Numar patrate cu latura cel putin " << K << " este " << S << '\n';

}

int main()
{
    int N, M, V[Nmax][Nmax], D[Nmax][Nmax], K;
    citire(N, M, V, K);
    solve(N, M, V, D, K);

    return 0;
}
