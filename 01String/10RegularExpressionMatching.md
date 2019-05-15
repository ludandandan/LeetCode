# Regular Expression Matching
[完整代码](https://github.com/ludandandan/LeetCode/blob/master/01String/10RegularExpressionMatching.cpp)

**题目：**

[LeetCode](https://leetcode.com/problems/regular-expression-matching/)

给定一个字符串s和一个模板字符串p，实现支持'.'和'*'的正则表达式匹配。

'.'匹配任意单个字符

'*'匹配0个或多个前面的元素

注意： s可以是空或者仅包含a-z的小写字母；p可以是空或者包含小写字母a-z，'.','*'。

例如， s="aa", p="a", output=false；
 s="aa", p="a*", output=true；
  s="ab", p=".*", output=true；

> 暴力递归：
> f(si, pi)表示p[pi,...,end]能否匹配s[si,...,end]。
> 对于pi有3种可能，
> 1. pi==p.size()，即p没有字符了，这时想要匹配只能是s也没有字符了，即si==s.size()，否则就不能匹配返回false；
> 2. pi==p.size()-1，即p还剩下一个字符，这个字符后面没有字符了，那么要想匹配需要s也就剩下一个字符了（即si==s.size()-1）并且p[pi]与s[si]匹配（这时就有两种情况，p[pi]==s[si]或p[pi]=='.'可以匹配任意字符）
> 3. pi<p.size()-1，即pi后面还有字符。这时就根据p[pi]后面的字符p[pi+1]是否是*来分为两类（因为*与其前面的字符进行组合会有神奇的事情发生）：
> * 若p[pi+1]不是*，那么就比较好办，这时需要看p[pi]与s[si]是否匹配且f(pi+1, si+1)是否是返回true。p[pi]与s[si]匹配的前提是si没有越界（pi没越界是确定的了）
> * 若p[pi+1]是*，还是要先看p[pi]与s[si]是否匹配；
>   * 若不匹配，那么只能让*表示0个p[pi]，再看f(si, pi+2)是否匹配；
>   * 若匹配，那么就是分别看这个*是表示前面的字符p[si]有0个，1个，2个还是...个s[si]才可以让后面的所有匹配f(si, pi+2)，si++直到si越界或者与p[pi]不匹配了,只要有一个返回true就是ture，
> 
> 4. 在主程序中需要f(0,0)

> 动态规划：
> 若s长度为n，p长度为m，那么需要一个(n+1)*(m+1)大小的dp二维数组，dp[i][j]就是f(i,j)的值。
> 
> 需要的位置是dp[0][0]。
> 
> 由base case得到的dp[n][m]肯定是true。
> 
> 分析其他普遍位置dp[i][j]，看看它需要哪些位置上的数。一个是dp[i+1][j+1]（当j+1不是*，并且s[i]与p[j]匹配上之后就要看这个），然后就是dp[si][j+2]，所以需要搞定最后两列和最后一行。
> 1. 对于最后一列，p没了，只有s也恰好没了才可以为true，所以只dp[n][m]为true，其他为false
> 2. 对于倒数第二列，p还有一个字符，只要s也只剩下一个字符，且这个字符与p匹配上dp[n-1][m-1]才为true，其他都是false, 并且需要检查这个dp表有没有倒数第二列，哈哈哈。
> 3. 对于最后一行，s没了，但p还有一堆，只要p为X*样子才可能为true。
> 然后遍历dp数组的其他位置，填上数。根据p[j+1]是否为*分为两大类。不是\*的就直接看s[i]和p[j]是否匹配，还有dp[i+1][j+1]。是\*的就需要看dp[si][j+2]中有没有一个是true，有就让dp[i][j]为true。

```c++
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
```