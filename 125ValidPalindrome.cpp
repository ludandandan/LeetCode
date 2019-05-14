#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

class Solution{
public:
    bool isPalindrome(string s)
    {
        if(s.empty()) return true;
        transform(s.begin(), s.end(), s.begin(), ::tolower);
        int left = 0;
        int right = s.size()-1;
        while(left < right)
        {
            while(!((s[left]>='0' && s[left]<='9') || (s[left]>='a' && s[left]<='z'))) left++;
            while(!((s[right]>='0' && s[right]<='9') || (s[right]>='a' && s[right]<='z'))) right--;
            if(left<right && s[left]!=s[right]) return false;
            else
            {
                left++;
                right--;
            }
        }
        return true;
    }
};

int main()
{
    Solution s;
    string str;
    cin >> str;
    bool res = s.isPalindrome(str);
    cout << res << endl;
    return 0;
}
