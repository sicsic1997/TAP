#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

struct interval {

    int x, y;

};

vector<interval> intervals;
int intervalMapToHall[10000]; ///sorry for this hardcoded stuff :(

struct cmp{

    bool operator()(const int &a, const int &b)  {
        return intervals[a].y > intervals[b].y;
    }

};

priority_queue<int,vector<int>,cmp> Q;


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

        if(Q.empty()) {
            aux.clear();
            aux.push_back(intervals[k]);
            lectureHalls.push_back(aux);
            intervalMapToHall[k] = lectureHalls.size() - 1;
            Q.push(k);
        }
        else {
            int temp = Q.top();
            //cout << k << " " << temp << '\n';

            if(intervals[temp].y <= intervals[k].x) {
                Q.pop();
                lectureHalls[intervalMapToHall[temp]].push_back(intervals[k]);
                intervalMapToHall[k] = intervalMapToHall[temp];
                Q.push(k);
            }
            else {
                aux.clear();
                aux.push_back(intervals[k]);
                lectureHalls.push_back(aux);
                intervalMapToHall[k] = lectureHalls.size() - 1;
                Q.push(k);
            }
        }

    }
    return lectureHalls;

}


void printLectureHalls(vector< vector<interval> > lectureHall) {

    cout << lectureHall.size() - 2 << '\n';
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

    intervals = getInput();
    sort(intervals.begin(), intervals.end(), cmp);

    //printVector(intervals);
    vector< vector<interval> > result = getResultGreedy(intervals);
    printLectureHalls(result);

    return 0;

}
