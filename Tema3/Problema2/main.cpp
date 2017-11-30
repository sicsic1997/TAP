#include <fstream>
#include <string.h>
#include <vector>
#include <map>
#define Nmax 500
using namespace std;
ifstream f("d.in");
ofstream g("d.out");

map<string, int> myHash;
int D[Nmax], T[Nmax], maxi = 0, pct;
vector<string> lista;

void citireSiRezolvare() {

    string aux;
    lista.push_back("0000");
    int i = 1;
    while(f >> aux) {
        lista.push_back(aux);
        ///luam substringul format din primele doua litere
        string temp = aux.substr(0, 2);

        //g << aux << " " << myHash[temp] << '\n';
        //cautam
        if(myHash[temp] != 0)
            D[i] = D[myHash[temp]] + 1,
            T[i] = myHash[temp];
        else
            D[i] = 1,
            T[i] = -1;

        //g << aux << " " << myHash[temp] << " " << T[i] << " " << D[i] << '\n';

        ///indexam substringul format din ultimele doua litere
        temp = aux.substr(aux.size() - 2, 2);
        if(D[i] > D[myHash[temp]])
            myHash[temp] = i;

       // g << aux << " " << myHash[temp] << " " << T[i] << " " << D[i] << '\n';

        if(D[i] > maxi)
            maxi = D[i], pct = i;

        i++;
    }

}

void recafis(int pct) {
    if(pct == -1)
        return;
    recafis(T[pct]);
    g << lista[pct] << '\n';
}

int main()
{
    citireSiRezolvare();
    g << "Lungime maxima: " << maxi << '\n';
    recafis(pct);
    return 0;
}
