#include <iostream>
#include <vector>
using namespace std;


void interChange(vector<int> &inputArray, int left, int right) {

    int aux = inputArray[right];
    inputArray[right] = inputArray[left];
    inputArray[left] = aux;

}

int getSemnificativeInversions(vector<int> &inputArray, int left, int right) {

    /*cout << "Begin array:" << " " << left << " " << right << '\n';
    for(int i = 0; i < inputArray.size(); ++i)
        cout << inputArray[i] << " ";
    cout << '\n';*/

    ///Case1: 1 number left
    if(left == right)
        return 0;

    ///Case2: 2 numbers left
    if(right - left == 1) {
        if(inputArray[left] > inputArray[right]) {
            interChange(inputArray, left, right);
            if(inputArray[left] > inputArray[right] * 2) {
                return 1;
            } else {
                return 0;
            }
        } else {
            return 0;
        }
    }
    ///General case
    int temp = 0, mid = (left + right) / 2, ltemp = left, rtemp = mid, ldoubtemp = left;
    temp += getSemnificativeInversions(inputArray, left, mid - 1) +
        getSemnificativeInversions(inputArray, mid, right);

    /*cout << "End recursion array:" << " " << left << " " << right << '\n';
    for(int i = 0; i < inputArray.size(); ++i)
        cout << inputArray[i] << " ";
    cout << '\n';*/

    vector<int> result;
    while(ltemp < mid && rtemp <= right) {
        if(inputArray[rtemp] < inputArray[ltemp]) {
            while(inputArray[rtemp] * 2 >= inputArray[ldoubtemp] && ldoubtemp < mid)
                ldoubtemp++;
            if(inputArray[rtemp] * 2 < inputArray[ldoubtemp] && ldoubtemp < mid)
                temp += mid - ldoubtemp;
            result.push_back(inputArray[rtemp]);
            rtemp++;
        } else {
            result.push_back(inputArray[ltemp]);
            ltemp++;
        }
    }


    while(ltemp < mid) {
        result.push_back(inputArray[ltemp]);
        ltemp++;
    }

    while(rtemp <= right) {
        result.push_back(inputArray[rtemp]);
        rtemp++;
    }

    //cout << "End array: " << " " << left << " " << right << '\n';
    for(int i = 0; i < result.size(); ++i) {
        inputArray[i + left] = result[i];
     //   cout << result[i] << " ";
    }
    //cout << '\n';
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
