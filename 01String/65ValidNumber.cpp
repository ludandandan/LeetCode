#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

class Solution{
public:
    bool isNumber(string s)
    {
        if(s.empty()) return false;
        int left = 0;
        int right = s.size()-1;
        while(s[left]==' ') left++;
        while(s[right]==' ') right--;
        //若除了空格没有别的了，就返回false
        if(left>right) return false;
        //若还剩一个字符且那个字符不是数字返回false
        if(left==right && (s[left]<'0'||s[left]>'9')) return false;
        //先处理首字符，首字符只能是正负号，数字，小数点
        bool digitExisted = false;
        bool dotExisted = false;
        bool eExisted = false;
        if(s[left]>='0' && s[left]<='9') digitExisted = true;
        else if(s[left]=='.') dotExisted = true; //小数点只能出现一次
        else if(s[left]!='+' && s[left]!='-') return false;

        //处理中间字符
        for(int i=left+1; i<right; i++)
        {
            //若是数字直接通过
            if(s[i]>='0' && s[i]<='9') digitExisted = true;
            //若是e,前面必须出现过数字，必须是首次出现e，前面必须不能是+-号
            else if(s[i]=='e' || s[i]=='E')
            {
                if(!eExisted && digitExisted) eExisted = true;
                else return false;
            }
            //若是小数点，前面必须没有出现过小数点，e
            else if(s[i]=='.') 
            {
                if(!dotExisted && !eExisted) dotExisted = true;
                else return false;
            }
                //若是正负号，前面一个字符必须是e
            else if(s[i]=='+' || s[i]=='-')
            {
                if(s[i-1]!='e' && s[i-1]!='E') return false;
            }
            else return false;
        }

        //处理最后一个字符
        if(s[right]>='0' && s[right]<='9') return true;
        else if(s[right]=='.' && !dotExisted && !eExisted && digitExisted) return true;
        else return false;

    }
};

int main()
{
    Solution s;
    string str;
    cin >> str;
    bool res = s.isNumber(str);
    cout << res << endl;
    return 0;
}
