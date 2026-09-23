#include <bits/stdc++.h>
using namespace std;

int findDuplicate(vector<int>& nums) {

    sort(nums.begin(), nums.end());

    int k = -1;

    for (int i = 0; i < nums.size() - 1; i++) {

        if (nums[i] == nums[i + 1]) {
            k = nums[i];
            break;
        }
    }

    return k;
}

int main() {

    vector<int> nums = {1, 3, 4, 2, 2};

    int answer = findDuplicate(nums);

    cout << "Duplicate number: " << answer << endl;

    return 0;
}