#include <iostream>
#include <vector>

using namespace std;

bool decidParSauImpar(vector<int> numbers) {

    int sumaPar = 0, sumaImpar = 0;
    for(int i = 0; i < numbers.size(); ++i)
        if(i % 2 == 0)
            sumaPar += numbers[i];
        else
            sumaImpar += numbers[i];

    return sumaPar > sumaImpar;

}

void simulateGame(bool decision, vector<int> numbers) {

    int sumaPrimulJucator = 0, sumaAlDoileaJucator = 0, st = 0, dr = numbers.size() - 1;

    cout << decision << '\n';

    ///i par inseamna primul jucator, i impar inseamna al doilea jucator
    for(int i = 0; i < numbers.size() - 2; ++i) {

        ///Player 1: daca decision e false, joc cu pare, altfel cu impare
        if(i % 2 == 0) {
            if(decision == 0) {
                ///situatia 1
                if(st % 2 == 1 && dr % 2 == 0) {
                    sumaPrimulJucator += numbers[dr];
                    cout << "Player1: D" << " " << dr <<'\n';
                    dr--;
                    continue;
                }
                ///situatia 2
                if(st % 2 == 0 && dr % 2 == 1) {
                    sumaPrimulJucator += numbers[st];
                    cout << "Player1: S" << " " << st <<'\n';
                    st++;
                    continue;
                }
                ///situatia 3
                if(st % 2 == 0 && dr % 2 == 0) {
                    if(numbers[st + 1] > numbers[dr]) {
                        sumaPrimulJucator += numbers[st];
                        cout << "Player1: S" << " " << st <<'\n';
                        st++;
                        continue;
                    }
                    if(numbers[dr + 1] >= numbers[st]) {
                        sumaPrimulJucator += numbers[dr];
                        cout << "Player1: D" << " " << dr << '\n';
                        dr--;
                        continue;
                    }
                }
            }
            else {
                ///situatia 1
                if(st % 2 == 0 && dr % 2 == 1) {
                    sumaPrimulJucator += numbers[dr];
                    cout << "Player1: D" << " " << dr << '\n';
                    dr--;
                    continue;
                }
                ///situatia 2
                if(st % 2 == 1 && dr % 2 == 0) {
                    sumaPrimulJucator += numbers[st];
                    cout << "Player1: S" << " " << st <<'\n';
                    st++;
                    continue;
                }
                ///situatia 3
                if(st % 2 == 1 && dr % 2 == 1) {
                    if(numbers[st + 1] > numbers[dr]) {
                        sumaPrimulJucator += numbers[st];
                        cout << "Player1: S" << " " << st <<'\n';
                        st++;
                        continue;
                    }
                    if(numbers[dr + 1] >= numbers[st]) {
                        sumaPrimulJucator += numbers[dr];
                        cout << "Player1: D" << " " << dr <<'\n';
                        dr--;
                        continue;
                    }
                }
            }
        }
        else {
            if(numbers[st] > numbers[dr]) {
                sumaAlDoileaJucator += numbers[st];
                cout << "Player2: S" << " " << st << '\n';
                st++;
                continue;
            }
            else {
                sumaAlDoileaJucator += numbers[dr];
                cout << "Player2: D" << " " << dr << '\n';
                dr--;
            }
        }
    }

    if(numbers[st] > numbers[dr]) {
        sumaPrimulJucator += numbers[st];
        cout << "Player1: S" << " " << st <<'\n';
        st++;
        sumaAlDoileaJucator += numbers[dr];
        cout << "Player2: D" << " " << dr << '\n';
        dr--;
    }
    else {
        sumaPrimulJucator += numbers[dr];
        cout << "Player1: D" << " " << dr <<'\n';
        dr--;
        sumaAlDoileaJucator += numbers[st];
        cout << "Player2: S" << " " << st << '\n';
        st++;
    }

    //cout << st << " " << dr << '\n';
    cout << sumaPrimulJucator << " " << sumaAlDoileaJucator << '\n';
    //cout << decision << '\n';

}

int main()
{

    ///Get Input
    vector<int> numbers;
    int N, aux;
    cin >> N;
    for(int i = 0; i < N; ++i)
        cin >> aux, numbers.push_back(aux);

    ///Daca e 0, joc cu pare, daca e 1, joc cu impare;
    bool decision = decidParSauImpar(numbers);

    ///Simulez jocul
    simulateGame(!decision, numbers);

    return 0;
}
