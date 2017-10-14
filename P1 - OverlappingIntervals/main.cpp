#include <iostream>
#include <vector>
#include <algorithm>
#include <time.h>
using namespace std;

struct interval {
    int x, y;
};

vector<interval> getInput() {

    interval aux;
    vector<interval> toReturn;
    int N;

    cin >> N;

    for(int i = 0; i < N; ++i)
        cin >> aux.x >> aux.y, toReturn.push_back(aux);

    return toReturn;
}

inline bool cmp(interval a, interval b) {

    return a.y < b.y;

}

void printVector(vector<interval> intervals) {

    for(int i = 0; i < intervals.size(); ++i)
        cout << intervals[i].x << " " << intervals[i].y << '\n';

}

int getFather(int st, int dr, vector<interval> intervals, interval aux) {

    if(st >= dr) {
        if(st == dr && intervals[st].y <= aux.x)
            return st;
        return -1;
    }

    int mij = (st + dr) / 2;
    if(intervals[mij].y <= aux.x)
        return max(mij, getFather(mij + 1, dr, intervals, aux));
    else
        return getFather(st, mij, intervals, aux);
}

vector<interval> getResult(vector<interval> intervals) {

    vector<interval> results;
    int T[intervals.size() + 4], D[intervals.size() + 4], lastInResult, maxV = -1;

    for(int i = 0; i < intervals.size(); ++i) {

        int x = getFather(0, i - 1, intervals, intervals[i]);
        if(x != -1)
            T[i] = x, D[i] = D[x] + 1;
        else
            T[i] = -1, D[i] = 0;

        if(D[i] > maxV && x != -1)
            maxV = D[i], lastInResult = i;

    }

    while(lastInResult != -1) {
        results.push_back(intervals[lastInResult]);
        lastInResult = T[lastInResult];
    }

    return results;
}

vector<interval> getResultGreedy(vector<interval> intervals) {

    vector<interval> results;

    results.push_back(intervals[0]);

    for(int i = 1; i < intervals.size(); ++i)
        if(intervals[i].x >= results[results.size() - 1].y)
            results.push_back(intervals[i]);

    return results;
}

int main()
{

    vector<interval> intervals = getInput();
    sort(intervals.begin(), intervals.end(), cmp);

    printVector(intervals);
    //vector<interval> result = getResult(intervals);
    vector<interval> result = getResultGreedy(intervals);

    printVector(result);
    return 0;
}
