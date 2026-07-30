#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> s;

        for (int num : nums) {
            if (s.find(num) != s.end()) {
                return true;
            }
            s.insert(num);
        }

        return false;
    }
};

int main() {
    Solution obj;
    vector<int> nums = {1, 2, 3, 1};

    if (obj.containsDuplicate(nums))
        cout << "true";
    else
        cout << "false";

    return 0;
}