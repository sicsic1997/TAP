#include <iostream>
#include <vector>
using namespace std;

void interChange(vector<int> &inputArray, int left, int right) {

    inputArray[left] ^= inputArray[right];
    inputArray[right] ^= inputArray[left];
    inputArray[left] ^= inputArray[right];

}

int getSemnificativeInversions(vector<int> &inputArray, int left, int right) {

    ///Case1: 1 number left
    if(left == right)
        return 0;

    ///Case2: 2 numbers left
    if(right - left == 1) {
        if(inputArray[left] > inputArray[right]) {
            interChange(inputArray, left, right);
            return 1;
        } else {
            return 0;
        }
    }
    ///General case
    cout << "Begin array:" << '\n';
    for(int i = 0; i < inputArray.size(); ++i)
        cout << inputArray[i] << " ";
    cout << '\n';

    int temp = 0, mid = (left + right) / 2, ltemp = left, rtemp = mid;
    temp += getSemnificativeInversions(inputArray, left, mid - 1) +
        getSemnificativeInversions(inputArray, mid, right);


    vector<int> result;
    while(ltemp < mid && rtemp <= right) {
        if(inputArray[rtemp] < inputArray[ltemp]) {
            temp += mid - ltemp;
            result.push_back(inputArray[rtemp]);
            rtemp++;
        } else {
            result.push_back(inputArray[ltemp]);
            ltemp++;
        }
    }


    while(ltemp < mid) {
        result.push_back(ltemp);
        ltemp++;
    }

    while(rtemp < right) {
        result.push_back(rtemp);
        rtemp++;
    }

    inputArray.clear();
    for(int i = 0; i < result.size(); ++i) {
        inputArray.push_back(result[i]);
        cout << result[i] << " ";
    }
    cout << '\n';
    return temp;
}

int main()
{
    int N;
    vector<int> inputArray;
    cin >> N;
    int temp;
    for(int i = 1; i <= N; ++i) {
        cin >> temp;
        inputArray.push_back(temp);
    }
    cout << getSemnificativeInversions(inputArray, 0, inputArray.size() - 1);
    return 0;
}
