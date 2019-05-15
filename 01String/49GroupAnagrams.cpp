#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <unordered_map>
using namespace std;

class Solution{
public:
    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {
        vector<vector<string>> res;
        if(strs.empty()) return res;
        int n = strs.size();
        unordered_map<string, vector<string>> m;
        for(auto s: strs)
        {
            string key = s;
            sort(key.begin(), key.end());
            m[key].push_back(s);
        }
        for(auto i: m)
        {
            res.push_back(i.second);
        }
        return res;
    }
};

int main()
{
    vector<string> strs{"eat", "tea", "tan", "ate", "nat", "bat"};
    Solution s;
    vector<vector<string>> res = s.groupAnagrams(strs);
    for(auto m: res)
    {
        for(auto w: m)
        {
            cout << w << ",";
        }
        cout << endl;
    }
    return 0;
}
