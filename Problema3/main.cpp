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

    if(a.x != b.x)
        return a.x < b.x;
    else
        return a.y < b.y;

}

void printVector(vector<interval> intervals) {

    for(int i = 0; i < intervals.size(); ++i)
        cout << intervals[i].x << " " << intervals[i].y << '\n';

}

vector< vector<interval> > getResultGreedy(vector<interval> intervals) {

    vector<interval> aux;
    vector< vector<interval> > lectureHalls;

    for(int k = 0; k < intervals.size(); ++k) {

        int hallNumber = -1;
        ///search for first free place

        for(int i = 0; i < lectureHalls.size() && hallNumber < 0; ++i) {

            aux = lectureHalls[i];
            if(aux[aux.size() - 1].y <= intervals[k].x)
                hallNumber = i;
        }

        if(hallNumber >= 0)
            lectureHalls[hallNumber].push_back(intervals[k]);
        else {
            aux.clear();
            aux.push_back(intervals[k])
            lectureHalls.push_back(aux);
        }

    }
    return lectureHalls;

}


void printLectureHalls(vector< vector<interval> > lectureHall) {

    vector<interval> aux;
    for(int i = 0; i < lectureHall.size(); ++i) {

        aux = lectureHall[i];
        for(int j = 0; j < aux.size(); ++j)
            cout << "(" << aux[j].x << "," << aux[j].y << ") ";
        cout << '\n';

    }



}

int main()
{

    vector<interval> intervals = getInput();
    sort(intervals.begin(), intervals.end(), cmp);

    //printVector(intervals);
    vector< vector<interval> > result = getResultGreedy(intervals);
    printLectureHalls(result);

    return 0;

}
