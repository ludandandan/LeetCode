#include <cstdio>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Solution{
public:
    vector<int> getNext(string str)
    {
        vector<int> next(str.size(),0);
        if(str.empty()) return next;
        next[0] = -1;
        if(str.size()==1) return next;
        next[1] = 0;
        for(int i=2; i<str.size(); i++)
        {
            int tmp = i-1;
            while(next[tmp]!=-1)
            {
                if(str[i-1]==str[next[tmp]]) 
                {   
                    next[i] = next[tmp]+1;
                    break;
                }
                else tmp = next[tmp];
            }
            if(tmp==0) next[i] = 0;
        }
        return next;
    }

    int strStrKMP(string str, string match)
    {
        if(match.empty()) return 0; 
        if(str.empty()) return -1;
        vector<int> next(match.size());
        next = getNext(match);
        int N = str.size();
        int M = match.size();
        int i = 0;
        int j = 0;
        while(i<N && j<M)
        {
            if(str[i]==match[j])
            {
                i++;
                j++;
            }
            else if(next[j]==-1)
            {
                i++;
            }
            else
            {
                j = next[j];
            }
        }
        return j==M?i-j:-1;

    }
};


int main()
{
    Solution s;
    string str, match;
    cin >> str;
    cin >> match;
    int res = s.strStrKMP(str, match);
    cout << res << endl;
    return 0;
}
