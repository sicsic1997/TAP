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
vector<point> points, pointsX, pointsY;
vector<point> leftY, rightY;

bool cmpX(point A, point B) {
    if(A.x - B.x)
        return A.x < B.x;
    return A.y < B.y;
}

bool cmpY(point A, point B) {
    if(A.y - B.y)
        return A.y < B.y;
    return A.x < B.x;
}

double getDist(point A, point B) {

    return sqrt(pow(B.x - A.x, 2) + pow(B.y - A.y, 2));

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
    return pointsList;

}

double getMinDist(int left, int right, vector<point> pointsY) {

    /*for(int i = 0; i < pointsY.size(); ++i)
        g << pointsY[i].x << "," << pointsY[i].y << " ";
    g << '\n';*/

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
    int mid = (left + right) / 2;
    double temp = INT_MAX, temp1, temp2;
    leftY.clear();
    rightY.clear();
    for(int i = 0; i < pointsY.size(); ++i) {
        if(pointsY[i].x <= pointsX[mid].x)
            leftY.push_back(pointsY[i]);
        if(pointsY[i].x >= pointsX[mid].x)
            rightY.push_back(pointsY[i]);
    }
    /*for(int i = 0; i < leftY.size(); ++i)
        g << leftY[i].x << "," << leftY[i].y << " ";
    g << '\n';
    for(int i = 0; i < rightY.size(); ++i)
        g << rightY[i].x << "," << rightY[i].y << " ";
    g << '\n';*/
    ///Get the results from left and right side of the median
    temp1 = getMinDist(left, mid, leftY);
    temp2 = getMinDist(mid, right, rightY);
    temp = min(temp1, temp2);

    ///Get min distance for points on different side of the median
    tempPointList.clear();
    for(int i = 0; i < pointsY.size(); ++i)
        if(pointsX[mid].x - pointsY[i].x <= temp)
            tempPointList.push_back(pointsY[i]);

    for(int i = 0; i < tempPointList.size(); ++i)
        for(int j = i + 1; j < i + 7 && j < tempPointList.size(); ++j)
            temp = min(temp, getDist(tempPointList[i], tempPointList[j]));

    return temp;
}

int main()
{
    points = getInput();
    pointsX = points;
    pointsY = points;
    sort(pointsX.begin(), pointsX.end(), cmpX);
    sort(pointsY.begin(), pointsY.end(), cmpY);
    /*for(int i = 0; i < pointsX.size(); ++i)
        g << pointsX[i].x << " ";
    g << '\n';
    for(int i = 0; i < pointsY.size(); ++i)
        g << pointsY[i].y << " ";
    g << '\n';*/
    double minDist = getMinDist(0, points.size() - 1, pointsY);

    g << setprecision(20) << minDist << '\n';

    return 0;
}
