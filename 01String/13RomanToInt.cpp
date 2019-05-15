#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
#include <iostream>
#include <unordered_map>
using namespace std;

class Solution{
public:
    int RomanToInt(string s)
    {
        unordered_map<string, int> m = {{"I", 1}, {"IV", 4}, {"V", 5}, {"IX", 9}, {"X", 10},
        {"XL", 40}, {"L", 50}, {"XC", 90}, {"C", 100}, {"CD", 400}, {"D", 500}, {"CM", 900}, {"M", 1000}};
        int res = 0;
        int n = s.size();
        int i = 0;
        while(i<n)
        {
            while(i<n-1 && m.find(s.substr(i,2))!=m.end())
            {
                res += m[s.substr(i,2)];
                i = i+2;
            }
            if(i<n && m.find(s.substr(i,1))!=m.end())
            {
                res += m[s.substr(i,1)];
                i++;
            }
        }
        return res;
    }
};


int main()
{
    Solution s;
    string str;
    cin >> str;
    int res = s.RomanToInt(str);
    cout << res << endl;
    return 0;
}
