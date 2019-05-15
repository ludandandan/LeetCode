#include <cstdio>
#include <iostream>
#include <cmath>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution{
public:
    string intToRoman(int num)
    {
        //unordered_map<int ,string> m = {{1, "I"}, {4, "IV"}, {5, "V"}, {9, "IX"}, {10, "X"},
        //{40, "XL"}, {50, "L"}, {90, "XC"}, {100, "C"}, {400, "CD"}, {500, "D"}, {900, "CM"}, {1000, "M"}};
        string res;
        vector<int> integer = {1, 4, 5, 9, 10, 40, 50, 90, 100, 400, 500, 900, 1000};
        vector<string> roman = {"I", "IV", "V", "IX", "X", "XL", "L", "XC", "C", "CD", "D", "CM", "M"};
        int n = integer.size();
        for(int i=n-1; i>=0; i--)
        {
            while(num-integer[i]>=0)
            {
                num = num - integer[i];
                res = res + roman[i];
            }
        }
        return res;
    }
};


int main()
{
    Solution s;
    int num;
    cin >> num;
    string res = s.intToRoman(num);
    cout << res << endl;
    return 0;
}
