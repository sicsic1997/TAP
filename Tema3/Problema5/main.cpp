#include <iostream>
#include <string.h>
#define Nmax 201
using namespace std;
int n,i,j,v[Nmax];
int d[Nmax][Nmax], t[Nmax][Nmax];

struct movement{int nextmove, maxdif;};

void calculateMaxDif(int st, int dr) {

    d[dr][dr] = v[dr];

    for (i=dr-1; i>=st; i--)
    {
        for (j=i; j<=dr; j++)
            if (i == j) {
                d[i][i] = v[i];
                t[i][i] = i;
            }
            else
            {
                d[i][j] = max(v[i]-d[i + 1][j], v[j]-d[i][j-1]);
                if(v[i]-d[i + 1][j] > v[j]-d[i][j-1])
                    t[i][j] = i;
                else
                    t[i][j] = j;
            }
    }

}

movement getMaxDif(int st, int dr) {

    movement aux;
    aux.maxdif = d[st][dr];
    aux.nextmove = t[st][dr];

    return aux;
}

int main()
{
    cin >> n;
    for (i=1; i<=n; i++)
        cin >> v[i];

    calculateMaxDif(1, n);

    cout << "START JOC" << '\n';
    int SCPU = 0, SUSER = 0, k = n, st = 1, dr = n;
    bool atMove = 0;
    while(k--) {
        ///CPU TURN
        cout << '\n';
        cout << '\n';
        for(int i = st; i <= dr; ++i)
            cout << v[i] << " ";
        cout << '\n';
        if(!atMove){
            movement temp = getMaxDif(st, dr);
            cout << "CPU: Number " << v[temp.nextmove] << '\n';
            SCPU += v[temp.nextmove];
            if(v[st] == v[temp.nextmove])
                st++;
            else
                dr--;
            cout << "Current score: CPU: " << SCPU << "; USER: " << SUSER << '\n';
            cout << "The CPU estimates to win at least " << - v[temp.nextmove] + temp.maxdif + SCPU - SUSER << " in front of Player 1" << '\n';
        } else {
            char C;
            int valid = 0;
            while(!valid) {
            cout << "Player 1 turn. Please choose your next move: S for left, and D for right" << '\n';
            cin >> C;
            switch(C) {
                case 'S':
                    SUSER += v[st];
                    st++;
                    valid = 1;
                    break;
                case 'D':
                    SUSER += v[dr];
                    dr--;
                    valid = 1;
                    break;
                default:
                    cout << "Please insert a valid move..." << '\n';
                    break;
                }
            }
            cout << "Current score: CPU: " << SCPU << "; USER: " << SUSER << '\n';
        }
        atMove = !atMove;
    }

    return 0;
}
