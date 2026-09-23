#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> mergeIntervals(vector<vector<int>>& intervals) {

    sort(intervals.begin(), intervals.end());

    vector<vector<int>> ans;

    vector<int> current = intervals[0];

    for (int i = 1; i < intervals.size(); i++) {

        vector<int> next = intervals[i];

        // Overlap
        if (current[1] >= next[0]) {
            current[1] = max(current[1], next[1]);
        }

        // No overlap
        else {
            ans.push_back(current);
            current = next;
        }
    }

    ans.push_back(current);

    return ans;
}

int main() {

    vector<vector<int>> intervals = {
        {1, 3},
        {2, 6},
        {8, 10},
        {15, 18}
    };

    vector<vector<int>> result = mergeIntervals(intervals);

    cout << "Merged Intervals:" << endl;

    for (int i = 0; i < result.size(); i++) {
        cout << "[" << result[i][0] << ", " << result[i][1] << "] ";
    }

    return 0;
}