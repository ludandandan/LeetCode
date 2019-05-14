#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

class Solution{
public:
    string longestPalindromic(string s)
    {
        if(s.empty() || s.size()==1) return s;
        vector<char> vc = makeNewStr(s);
        vector<int> pArr(vc.size(),1);//最大回文半径
        int pR = -1; //即将到达的最右回文右边界
        int index = -1; //最右回文右边界对应的回文中心
        int max_index = 0;
        for(int i=1; i<vc.size(); i++)
        {
        //根据i是否在pR里面确定最起码的回文半径
           // pArr[i] = i>pR?pArr[i]: min(pR-i, pArr[2*index-i]); //这里可能在oj出现问题
            pArr[i] = i<pR?min(pR-i, pArr[2*index-i]):1;//由于pR是即将到达的最右右边界，所以当i==pR的时候就相当于在外面了
            while(((i+pArr[i])<vc.size()) && ((i-pArr[i])>=0) && (vc[i+pArr[i]] == vc[i-pArr[i]])) pArr[i]++;
            if((i+pArr[i])>pR)
            {
                pR = i+pArr[i];
                index = i;
            }
            if(pArr[max_index]<pArr[i])
            {
                max_index = i;
            }
        }
        string res;
        for(int i = max_index-pArr[max_index]+1; i<max_index+pArr[max_index]; i++)
        {
            if(vc[i]!='#') res = res + vc[i];
        }
        return res;
    }
    vector<char> makeNewStr(string s)
    {
        int n = s.size();
        vector<char> vc(2*n+1);
        int j = 0;
        for(int i=0; i<(2*n+1); i++)
        {
            //i为偶数的部分放#，i为奇数的的时候就放s里的数
            vc[i] = (i&1)==0?'#':s[j++];
        }
        return vc;
    }
};


int main()
{
    Solution s;
    string str;
    cin >> str;
    string res = s.longestPalindromic(str);
    cout << res << endl;
    return 0;
}
