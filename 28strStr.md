# Implement strStr()
[完整代码]()

**题目：**
[leetCode](https://leetcode.com/problems/implement-strstr/)

字符串匹配。在haystack中找到第一个出现needle的索引位置，若needle不是haystack的一部分那么就返回-1。
例如，haystack="hello", needle="ll"那么应该返回2。
若needle是空的话应该返回什么？ ---返回0。

> 注意在getNext的时候，看看str的大小，是不是大于1了，否则只要填一个-1就可以返回了。
> 还有haystack为空的时候返回-1
> 
> 使用KMP算法进行字符串匹配。有一个str字符串（长度为N）和一个match字符串（长度为M），看match是否在str中，若在返回出现时的第一个字符的索引，若不在返回-1。一种暴力解法就是以str的每个字符i开始进行匹配，看看是否能匹配出match，若可以就返回i，若不能i++，直到str都用完了还没匹配好就返回-1。这种暴力解法的时间复杂度是O(M*N)。 KMP算法是对这种暴力解法的改进，并不是每次都从第一个字符开始匹配而是对于str中的匹配到的字符位置不会回退。若有str[i,...,j-1]与match[0,...,j-i-1]都是匹配的，然后str[j]与match[j-i]不匹配了，那么前面已经匹配过的信息会为后面的匹配作贡献。
> 
> 这时就需要一个关于match的next数组，这个数组的长度为match的长的，next[i]表示之前的match[0,...,i-1]的字符串中必须以match[i-1]结尾的后缀子串（不得包含match[0]）与必须以match[0]开头的前缀子串（不得包含match[1]）的最大匹配长度是多少。这个next数组怎么计算呢？定义next[0]=-1，若存在next[1]那么让它等于0。然后后面的i=2,...就可以由前面的得出了，若要求next[i]，那么已经已知next[i-1]了，只需要看看match[next[i-1]]与match[i-1]是否匹配，若是匹配那么next[i]=next[i-1]+1，若是不匹配，那么就往前跳，跳到next[i-1]的位置，检查match[i-1]与match[next[next[i-1]]]是否匹配，若匹配next[i]=next[next[i-1]]+1，直到不能往前跳了，也就是next[]=-1了，此时就是没有相同的前缀与后缀，那么这个位置的next[i]就是0。
> 
> 计算好了match的next数组后，就可以进行KMP算法了。str[j]与match[j-i]不匹配，它前面的都是匹配的，si = j, mi = j-i,就是str[si]与match[mi]不匹配了，那么找到next[mi]，让mi=next[mi]，再对str[si]与match[mi]进行匹配，若还不匹配，那么再让mi=next[mi]，直到不能往前了，也就是next[mi]==-1了，就直接从头开始匹配（与也就是此时的match[mi]与str[++si]进行匹配）。若匹配了，si与mi一起++。

```c++
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

```