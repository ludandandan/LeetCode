#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

class Solution{
public:
    //将两个字符串表示的整数相乘
    string mulStrings(string num1, string num2)
    {
        if(num1.empty() || num2.empty()) return "";
        string res; 
        int n1 = num1.size();
        int n2 = num2.size();
        //定义一个vector，大小为n1+n2,存放结果的从高位到低位
        //索引越小，位数越高，只有0~9
        vector<int> resV(n1+n2, 0);//初始化各个位都是0
        //乘法要从低位开始算，所以要对num1和num2倒着取
        for(int i=n1-1; i>=0; i--)
        {
            for(int j=n2-1; j>=0; j--)
            {
                int i0 = num1[i]-'0';
                int j0 = num2[j]-'0';
                int mul = i0*j0;
                //乘积先加到低位上，除以10商加到高位上，余数留在低位上
                int p1 = i+j;//高位
                int p2 = i+j+1; //低位
                resV[p2] += mul;
                resV[p1] += resV[p2]/10;
                resV[p2] = resV[p2]%10;
            }
        }

        //从vector中取出来放到string里
        for(int n: resV)
        {
            //先出高位再出低位，注意不要0开头
            if(!(res.empty() && n==0))
            {
                char c  = n+'0';
                res += c;
            }
        }
        return res;
    }
};

int main()
{
    Solution s;
    string str1, str2;
    cin >> str1;
    cin >> str2;
    string res = s.mulStrings(str1, str2);
    cout << res << endl;
}
