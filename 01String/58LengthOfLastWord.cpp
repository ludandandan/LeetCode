#include <cstdio>
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

class Solution{
public:
    int lengthOfLastWord(string s)
    {
        if(s.empty()) return 0;
        int res = 0;
        int p = 0;
        int n = s.size();
        while(p<n)
        {
            while(p<n && s[p]==' ')
            {
                if(p<n-1 && s[p+1]!=' ') res=0;
                p++;
            }
            while(p<n && s[p]!=' ')
            {
                res++;
                p++;
            }
        }
        return res;
    }
};

int main()
{
    Solution s;
    string str = "a";
    //cin >> str;
    int res = s.lengthOfLastWord(str);
    cout << res << endl;
    return 0;
}
