#include <cstdio>
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

class Solution{
public:
    bool isMatch(string s, string p)
    {
        if(s.empty() && p.empty()) return true;
        return f(s, p, 0, 0);
    }
    bool f(string s, string p, int si, int pi)
    {
        if(pi==p.size()) return si==s.size();
        else if(pi==(p.size()-1))
        {
            if((si==(s.size()-1)) && (p[pi]==s[si] || p[pi]=='.')) return true;
            else return false;
        }
        else
        {
            if(p[pi+1]!='*')
            {
                return (si<s.size() && (p[pi]==s[si] || p[pi]=='.') && f(s, p, si+1, pi+1));
            }
            else
            {
                while(si<s.size() && (p[pi]==s[si] || p[pi]=='.'))
                {
                    if(f(s,p,si, pi+2)) return true;
                    else si++;
                }
                return f(s,p,si,pi+2);
            }
        }
    }

    bool isMatchDp(string s, string p)
    {
        if(s.empty() && p.empty()) return true;
        vector<vector<bool>> dp = initDp(s, p);
        int n = s.size();
        int m = p.size();
        for(int i=n-1; i>=0; i--)
        {
            for(int j=m-2; j>=0; j--)
            {
                if(p[j+1]!='*') 
                {
                    dp[i][j] = ((s[i]==p[j] || p[j]=='.') && dp[i+1][j+1]);
                }
                else
                {
                    int si = i;
                    while(si<s.size() && (s[si]==p[j]||p[j]=='.'))
                    {
                        if(dp[si][j+2])
                        {
                            dp[i][j] = true;
                            break;
                        }
                        else si++;
                    }
                    if(!dp[i][j]) dp[i][j] = dp[si][j+2];
                }
            }
        }
        return dp[0][0];
        
    }

    vector<vector<bool>> initDp(string s, string p)
    {
        int n = s.size();
        int m = p.size();
        vector<vector<bool>> dp(n+1, vector<bool>(m+1));
        for(int i=0; i<=n; i++) for(int j=0; j<=m; j++) dp[i][j] = false;
        //s和p都没了的时候必然是true;
        dp[n][m] = true;
        //对最后一列表示p没了，但s还要一堆，此时就是false
        //对倒数第二列（首先需要确定有倒数第二列），只有s也只有一个字符并且他们匹配时dp[n-1][m-1]才是ture
        if(n>0 && m>0) dp[n-1][m-1] = (s[n-1]==p[m-1] || p[m-1]=='.');
        //对最后一行，s没了，但p还要一大堆，只有p是X*模样时才可能是true
        for(int i = m-2; i>=0; i=i-2)
        {
            if(p[i]!='*' && p[i+1]=='*') dp[n][i] = true;
            else break;
        }
        return dp;
    }
};


int main()
{
    Solution s;
    string str, p;
    cin >> str;
    cin >> p;
    bool res = s.isMatch(str, p);
    cout << res << endl;
    bool res1 = s.isMatchDp(str, p);
    cout << res1 << endl;
    return 0;
}
