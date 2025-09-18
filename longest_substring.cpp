#include <iostream>
#include <vector>
using namespace std;

// Function Logic
int func(string s) {
    int i = 0, j = 0;
    int max = 0;
    int curr = 0;
    vector<int> arr(128, 0);

    while (j < s.size()) {
        char a = s[j];
        if (!arr[a]) {
            arr[a]++;
            curr++;
            j++;
            if (curr > max) max = curr;
        } else {
            arr[s[i]]--;
            i++;
            curr--;
        }
    }
    return max;
}

// input ,output
int main() {
    // change this variable for input
    string s = "abcabcbb";

    cout << func(s);

    return 0;
}