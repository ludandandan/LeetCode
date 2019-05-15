#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <sstream>
#define INT_MAX 65535
using namespace std;

class Solution{
public:
    string longestCommonPrefix(vector<string> &str)
    {
        string res;
        if(str.empty()) return res;
        int n = str.size();
        int i = 0; 
        int min_len = INT_MAX;
        while(i<n) 
        {
            if(str[i].empty()) return res;
            int len = str[i++].size();
            min_len = min(min_len, len);
        }
        i = 0;
        for(; i<min_len; i++)
        {
            char c = str[0][i];
            int j = 1;
            for(; j<n; j++)
            {
                if(c!=str[j][i]) break;
            }
            if(j!=n) break;
        }
        return str[0].substr(0, i);
    }
};


void split(string s, vector<string> &vs, char delim)
{
    istringstream is(s);
    string tmp;
    while(getline(is, tmp, delim))
    {
        vs.push_back(tmp);
    }
}
int main()
{
    //vector<string> vs{"flower", "flow", "filight"};
    vector<string> vs;
    string strs;
    cin >> strs;
    split(strs, vs, ',');

    Solution s;
    string res = s.longestCommonPrefix(vs);
    cout << res << endl;
    return 0;

}
