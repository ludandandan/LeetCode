#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

class Solution{
public:
    string addBinary(string a, string b)
    {
        string res;
        int carry = 0; //进位
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        int ia = 0;
        int ib = 0;
        int na = a.size();
        int nb = b.size();
        while(ia<na || ib<nb)
        {
            int numa = ia<na?a[ia++]-'0':0;
            int numb = ib<nb?b[ib++]-'0':0;
            int n = numa+numb+carry;
            char c = (n%2) + '0';
            res = c + res;
            carry = n/2;
        }
        char c = carry+'0';
        if(carry!=0) res = c + res;
        return res;
    }
};

int main()
{
    string a, b;
    cin >> a;
    cin >> b;
    Solution s;
    string res = s.addBinary(a,b);
    cout << res << endl;
    return 0;
}
