#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;


//Main function Logic
vector<vector<int>> merge(vector<vector<int>>& intervals) {
    sort(intervals.begin(), intervals.end());
    // just sorts the vector

    vector<vector<int>> ans;
    ans.push_back(intervals[0]);

    for (int i = 1; i < intervals.size(); i++) {
        if (intervals[i][0] <= ans.back()[1]) {
            ans.back()[1] = max(ans.back()[1], intervals[i][1]);
        } else {
            ans.push_back(intervals[i]);
        }
    }

    return ans;
}
//outputs the final ans
void display(vector<vector <int>> arr) {
    cout<<"[";

    for(int i=0;i<arr.size();i++){
        cout<<"["<<arr[i][0]<<","<<arr[i][1]<<"]";
        if(i<arr.size()-1) cout<<",";
    }
    cout<<"]";
}

int main() {
    // change input from this vector variable
    vector<vector<int>> input = {{1, 3}, {2, 6}, {8, 10}, {15, 18}};
    display(merge(input));

    return 0;
}