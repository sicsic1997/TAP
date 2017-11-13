#include <fstream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <limits.h>
#include <iomanip>
using namespace std;

ifstream f("cmap.in");
ofstream g("cmap.out");


struct point {

    int x, y;

};

vector<point> tempPointList;
vector<point> points;

bool operator < (point A, point B) {
    if(A.x - B.x)
        return A.x < B.x;
    else
        return A.y < B.y;
}

double getDist(point A, point B) {

    return sqrtf(pow(B.x - A.x, 2) + pow(B.y - A.y, 2));

}

vector<point> getInput() {

    int numberOfPoints;
    point temp;
    vector<point> pointsList;
    f >> numberOfPoints;
    for(int i = 0; i < numberOfPoints; ++i) {

        f >> temp.x >> temp.y;
        pointsList.push_back(temp);

    }
    sort(pointsList.begin(), pointsList.end());
    return pointsList;

}

double getMinDist(int left, int right) {

    ///Single point case
    if(left >= right) {

        return INT_MAX;
    }

    ///2 or 3 points case
    if(right - left <= 2) {

        double temp = INT_MAX;
        for(int i = left; i <= right; ++i)
            for(int j = i + 1; j <= right; ++j)
                temp = min(temp, getDist(points[i], points[j]));
        return temp;

    }

    ///General case
    ///Get the results from left and right side of the median
    int mid = (left + right) / 2;
    double temp = INT_MAX, temp1, temp2;
    temp1 = getMinDist(left, mid);
    temp2 = getMinDist(mid, right);
    temp = min(temp1, temp2);

    ///Get min distance for points on different side of the median
    tempPointList.clear();
    for(int i = mid; i >= left && points[mid].x - points[i].x <= temp; i--)
        tempPointList.push_back(points[i]);

    for(int i = mid + 1; i <= right && points[i].x - points[mid].x <= temp; i++)
        tempPointList.push_back(points[i]);

    sort(tempPointList.begin(), tempPointList.end());

    for(int i = 0; i < tempPointList.size(); ++i)
        for(int j = i + 1; j < i + 8 && j < tempPointList.size(); ++j) {
            temp = min(temp, getDist(tempPointList[i], tempPointList[j]));

        }

    return temp;
}

int main()
{
    points = getInput();
    double minDist = getMinDist(0, points.size() - 1);
    g << s(20) << minDist << '\n';
    return 0;
}
