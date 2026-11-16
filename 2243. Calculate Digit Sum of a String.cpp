#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string digitSum(string s, int k) {
        // string temp = "";
        while (s.size() > k) {
            int i = 0, sm = -1;
            string temp = "";
            while (i < s.size()) {
                if (i!=0 && i%k==0){
                    temp += to_string(sm);
                    sm = 0;
                }
                if (sm==-1) sm = 0;
                sm += (s[i] - '0');
                i++;
            }
            if (s.size()%k || sm!=-1) temp += to_string(sm);
            s = temp;
        }
        return s;
    }
};

int main() {
    Solution sol;
    cout << sol.digitSum("11111222223", 3) << endl;
    return 0;
}
