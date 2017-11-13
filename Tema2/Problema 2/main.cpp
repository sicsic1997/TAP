#include <fstream>
#include <math.h>
using namespace std;
ifstream f("z.in");
ofstream g("z.out");

int getValue(long long length, int a, int b) {

   // g << length << " " << b << '\n';

    if(length == 2) {
        if(a == 1 && b == 1)
            return 1;
        if(a == 1 && b == 2)
            return 2;
        if(a == 2 && b == 1)
            return 3;
        if(a == 2 && b == 2)
            return 4;
    }
    long long  temp = length * length / 4;

    ///Cadran stanga sus
    if(a <= length / 2 && b <= length/2)
        return 0 * temp + getValue(length / 2, a, b);

     ///Cadran dreapta sus
    if(a <= length / 2 && b > length/2)
        return 1 * temp + getValue(length / 2, a, b - length/2);

    ///Cadran stanga jos
    if(a > length / 2 && b <= length/2)
        return 2 * temp + getValue(length / 2, a - length/2, b);

    ///Cadran dreapta jos
    if(a > length / 2 && b > length/2)
        return 3 * temp + getValue(length / 2, a - length/2, b - length/2);
}

int main()
{
    int N, K, a, b;

    f >> N >> K;
    for(int i = 1; i <= K; ++i)
    {
        f >> a >> b;
        g << getValue(pow(2, N), a, b) << '\n';
    }

    return 0;
}