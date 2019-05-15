#include <cstdio>
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

class Solution{
public:
    string countAndSay(int n)
    {
        return f(n);
    }

    string f(int n)
    {
        if(n==1) return "1";
        if(n==2) return "11";
        string pre = f(n-1);
        string res;
        int p = 0;
        int m = pre.size();
        while(p<m)
        {
            char c = pre[p];
            int i = 0;
            while(p<m && c==pre[p])
            {
                i++;
                p++;
            }
            char count = i+'0';
            res = res + count + c;
        }
        return res;
    }
};

int main()
{
    Solution s;
    int n;
    cin >> n;
    string res = s.countAndSay(n);
    cout << res << endl;
    return 0;
}
