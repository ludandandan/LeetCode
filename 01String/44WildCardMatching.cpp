#include <cstdio>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;

class Solution{
public:
    bool isMatch(string s, string p)
    {
        //直接暴力递归会超时，先对p进行简化，对于连在一起的*简化为一个*
        //还是会超时
        if(s.empty() && p.empty()) return true;
        string sp = simple(p);
        return f(s, sp, 0, 0);
    }
    string simple(string p)
    {
        if(p.empty()||p.size()==1) return p;
        string res;
        int i = 0;
        while(i<p.size())
        {
            int n = res.size();
            if(n!=0 && res[n-1]=='*' && p[i]=='*') i++;
            else res = res+p[i++];
        }
        return res;
    }
    bool f(string s, string p, int si, int pi)
    {
        if(pi==p.size()) return si==s.size();
        else
        {
            if(p[pi]!='*') return (si!=s.size() && (s[si]==p[pi] || p[pi]=='?') && f(s, p, si+1, pi+1));
            else
            {
                while(si!=s.size())
                {
                    if(f(s, p, si, pi+1)) return true;
                    else si++;
                }
                return f(s, p, si, pi+1);
            }
        }
    }

    bool isMatchDp(string s, string p)
    {
        if(s.empty() && p.empty()) return true;
        string sp = simple(p);
        int n = s.size();
        int m = sp.size();
        vector<vector<bool>> dp = initDp(s, p);
        for(int i=n-1; i>=0; i--)
        {
            for(int j=m-1; j>=0; j--)
            {
                if(sp[j]!='*') dp[i][j] = ((s[i]==sp[j] || sp[j]=='?') && dp[i+1][j+1]);
                else
                {
                    int si = i;
                    while(si<s.size())
                    {
                        if(dp[si][j+1])
                        {
                            dp[i][j] = true;
                            break;
                         }
                        else si++;
                    }
                    if(!dp[i][j]) dp[i][j] = dp[si][j+1];
                }
            }
        }
        return dp[0][0];
        
    }

    vector<vector<bool>> initDp(string s, string p)
    {
        string sp = simple(p);
        int n = s.size();
        int m = sp.size();
        vector<vector<bool>> dp(n+1, vector<bool>(m+1));
        for(int i=0; i<=n; i++) for(int j=0; j<=m; j++) dp[i][j] = false;
        dp[n][m] = true;
        //最后一列，p没了，s还有一堆，只有s没了的位置dp[n][m]为true其他都是false
        //最后一行，s没了，p还要一堆，只有p是*才是true，一旦出现不是*就全部是false
        for(int i = m-1; i>=0; i--)
        {
            if(sp[i]=='*') dp[n][i] = true;
            else break;
        }
        return dp;
    }
};

int main()
{
    string str, p;
    cin >> str;
    cin >> p;
    //str = "babaaababaabababbbbbbaabaabbabababbaababbaaabbbaaab";
    //p = "***bba**a*bbba**aab**b";
    Solution s;
    string sp = s.simple(p);
    cout << sp << endl;
    bool res = s.isMatchDp(str, p);
    cout << res << endl;
    return 0;
}
