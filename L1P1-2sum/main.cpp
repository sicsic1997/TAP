///The code can be tested on LeetCode

class Solution {
public:

    vector<int> twoSumHash(vector<int> &nums, int target) {

        vector<int> V;

        map<int, int> map;

        for(int i = 0; i < nums.size(); ++i) {
            //cout << map[3] << '\n';
            if(map[target - nums[i]]) {
                V.push_back(min(i, map[target-nums[i]] - 1));
                V.push_back(max(i, map[target-nums[i]] - 1));
                return V;
            }
            else {
                map[nums[i]] = i + 1;
            }
        }


    }

    void quickSort(vector<int> &Ord, vector<int> &arr, int left, int right) {

        int i = left, j = right;
        int tmp;
        int pivot = arr[(left + right) / 2];

        while (i <= j) {
                while (arr[i] < pivot)
                    i++;
                while (arr[j] > pivot)
                     j--;
                if (i <= j) {
                    tmp = arr[i];
                    arr[i] = arr[j];
                    arr[j] = tmp;
                    tmp = Ord[i];
                    Ord[i] = Ord[j];
                    Ord[j] = tmp;
                    i++;
                    j--;
                }
        };

        if (left < j)
                quickSort(Ord, arr, left, j);
        if (i < right)
                quickSort(Ord, arr, i, right);
        }

    int binSrc(vector<int> &nums, int val, int st, int dr) {

        if(st >= dr) {
            if(nums[st] == val)
                return st;
            else
                return -1;
        }

        int mij = (st + dr) / 2;
        if(nums[mij] < val)
            return binSrc(nums, val, mij + 1, dr);
        if(nums[mij] > val)
            return binSrc(nums, val, st, mij - 1);
        if(nums[mij] == val)
            return mij;

    }

    vector<int> twoSumNlogN(vector<int> &nums, int target) {

        vector<int> V, Ord;
        for(int i = 0; i < nums.size(); ++i)
            Ord.push_back(i);

        quickSort(Ord, nums, 0, nums.size() - 1);

        for(int i = 0; i < nums.size(); ++i) {

            int complement = target - nums[i];
            int poz = binSrc(nums, complement, 0, nums.size() - 1);

            if(poz != -1 && poz != i) {
                V.push_back(min(Ord[i], Ord[poz]));
                V.push_back(max(Ord[i], Ord[poz]));
                return V;
            }

        }

    }

    vector<int> twoSumPolinomial(vector<int> &nums, int target) {

        vector<int> V;

        for(int i = 0; i < nums.size(); ++i)
            for(int j = i + 1; j < nums.size(); ++j)
                if(nums[i] + nums[j] == target) {
                    V.push_back(i);
                    V.push_back(j);
                    return V;
                }

    }

    vector<int> twoSum(vector<int>& nums, int target) {

        //return twoSumPolinomial(nums, target);
        //return twoSumNlogN(nums, target);
        return twoSumHash(nums, target);

    }
};
