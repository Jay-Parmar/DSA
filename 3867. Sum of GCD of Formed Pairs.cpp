#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>
#include <climits>

class Solution {
public:

    long long findGCD(int a, int b){
        a = abs(a);
        b = abs(b);
        while (b!=0) {
            int temp = a % b;
            a = b;
            b = temp;
        }
        return a;
    }

    long long gcdSum(vector<int>& nums) {
        int maxi = INT_MIN;
        int n = nums.size();
        for (int i=0; i<n; i++) {
            maxi = max(maxi, nums[i]);
            nums[i] = findGCD(maxi, nums[i]);
        }
        sort(nums.begin(), nums.end());
        long long ans = 0;
        for (int i=0; i<n/2; i++){
            ans += findGCD(nums[i], nums[n-1-i]);
        }
        return ans;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {2, 6, 4, 8};
    cout << sol.gcdSum(nums) << endl;
    return 0;
};
