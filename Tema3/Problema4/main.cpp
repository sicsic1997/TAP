#include <iostream>
#define Nmax 1000
using namespace std;
int D[Nmax][Nmax], father[Nmax], numberOfPal[Nmax];

///aaabcbsdedf

int getNumberOfPalindromes(string s) {

    int S = 0;
    for(int i = 0; i < s.length(); ++i) {

        ///First case: one letter in the middle
        int len = 0;
        while(i - len >= 0 && i + len < s.length() && s[i - len] == s[i + len]) {
            D[i - len][i + len] = 1;
            S++, len++;
        }

        ///Second case: two letter in the middle
        if(i < s.length()) {
            len = 0;
            int j = i + 1;
            while(i - len >= 0 && j + len < s.length() && s[i - len] == s[j + len]) {
                D[i - len][j + len] = 1;
                S++, len++;
            }
        }

    }

    return S;

}

void recafis(int x, string s) {

    if(x >= 0) {
        recafis(father[x] - 1, s);
        for(int i = father[x]; i <= x; ++i)
            cout << s[i];
        cout << '\n';
    }

}

void getMinimumPalindromePartition(string s) {

    /*for(int i = 0; i < s.length(); ++i) {
        for(int j = 0; j < s.length(); ++j)
            cout << D[i][j] << " ";
        cout << '\n';
    }
    cout << '\n';*/

    ///construim solutia la dreapta lui i
    for(int i = 1; i < s.length(); ++i)
        father[i] = i, numberOfPal[i] = i;


    for(int i = 0; i < s.length(); ++i) {
        for(int j = i; j < s.length(); ++j)
            if(D[i][j]) {
                if(i == 0)
                    numberOfPal[j] = 1, father[j] = i;
                else if (numberOfPal[j] > numberOfPal[i - 1] + 1) {
                    numberOfPal[j] = numberOfPal[i - 1] + 1;
                    father[j] = i;
                }
            }
    }

    /*for(int i = 0; i < s.length(); ++i)
        cout << father[i] << " ";

    cout << '\n';

    for(int i = 0; i < s.length(); ++i)
        cout << numberOfPal[i] << " ";

    cout << '\n';*/

    cout << numberOfPal[s.length() - 1] << '\n';
    recafis(s.length() - 1, s);

}

int main()
{
    string word;
    cin >> word;

    cout << getNumberOfPalindromes(word) << '\n';
    getMinimumPalindromePartition(word);

    return 0;
}
