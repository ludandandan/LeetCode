#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
#include <iostream>
#include <sstream>
using namespace std;

class Solution{
public:
    string simplifyPath(string path)
    {
        string res;
        if(path.empty()) return res;
        //去除多余的连着的/
        //最后的不用去掉，在split函数中会去掉
        string tmp;
        for(int i=1; i<path.size(); i++)
        {
            if(path[i-1]=='/' && path[i]=='/') continue;
            tmp += path[i];
        }
        //遇到.就跳过，遇到..就往前删一级（若前面有目录名字）
        // tmp被/分割
        vector<string> vs;
        vector<string> vres;
        split(tmp, vs, '/');
        for(int i=0; i<vs.size(); i++)
        {
            if(vs[i]=="." || (vs[i]==".."&&vres.empty())) continue;
            else if(vs[i]=="..") vres.pop_back();
            else vres.push_back(vs[i]);
        }
        if(vres.empty()) 
        {
            res = "/"; 
            return res;
        }
        else
        {
            for(string s: vres)
            {
                res = res + "/" + s;
            }
        }
        return res;
    }

    void split(string s, vector<string> &vs, char delim)
    {
        istringstream is(s);
        string tmp;
        while(getline(is, tmp, delim))
        {
            vs.push_back(tmp);
        }
    }
};


int main()
{
    Solution s;
    string path;
    cin >> path;
    string res = s.simplifyPath(path);
    cout << res << endl;
    return 0;
}
