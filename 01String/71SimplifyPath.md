# Simplify Path
[完整代码](https://github.com/ludandandan/LeetCode/blob/master/01String/71SimplifyPath.md)

**题目：**
给定一个unix风格的绝对路径，请简化它。或者说将其转换为canonical path。

在unix风格中，一个.指的是当前路径，两个点..表示上一级。

注意返回的canonical path总是以/开头，在两个目录之间必须有且仅有一个/。最后一个路径名字（若存在）必须不能以/结尾。并且canonical path必须是能表示绝对路径的最短字符。

例如， input: "/home/", output: "/home"; 

input: "/../", output: "/",因为到根目录的上一级还是根目录; 

input: "/home//foo/", output: "/home/foo"; 

input: "/a/./b/../../c/", output: "/c"; 

input: "/a/../../b/../c//.//", output: "c"; 

input: "/a//b////c/d//././/..", output: "/a/b/c"


>先处理掉重复的/；然后按照/把处理好的字符串分断，每一段是一个路径名字，放到一个vector<string> tmp中；再对tmp的每个元素进行检查，准备一个vector<string> vres用于储存以后放在res中的元素，若是一个点，那么就不用动，若是两个点，然后还要看vres是否是空，若是空说明已经到根目录了，若不是就要从vres中pop_back出一个元素表示跳到上一级，若是普通的目录名字就把它push_back到vres中，最后把vres中的元素取出来组成res。

```c++
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

```