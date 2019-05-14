# Longest Palindromic Substring
[完整代码](https://github.com/ludandandan/LeetCode/blob/master/01String/5LongestPalindromicSubstring.cpp)

**题目：**

[LeetCode](https://leetcode.com/problems/longest-palindromic-substring/)

给定一个字符串s，找到这个字符串中的最长回文子串，你可以加上这个字符串的最长长度为1000

例如，input: "babad", output: "bab";

input "cbbd", output: "bb"

> Manancher算法：需要一个函数把str中插入一些无关字符（比如“#”），先建一个长度为2*n+1的数组，对于偶数位置方法#奇数位置放原字符串中的字符，这样就可以处理偶回文了。以每个字符为中心往左往右扩，Manancher算法是在扩的过程中应用了之前的信息。
> 首先需要三个定义：
> 1.  回文半径，数组pArr：pArr[i]比的意义是以i位置上的字符作为回文中心的情况下，扩出去的最大回文半径。如字符串aba，插入#后变为#a#b#a#，这样它回文半径数组就是[1,2,1,4,1,2,1]，初始值为1，最小的回文半径就是1。
> 2. 即将到达的回文最右右边界pR： 之前遍历的所有字符的所有回文半径中，最右即将到达的位置，比如对于上面的字符串中的b，它这里的pR = 3+4=7，并且从这以后都是7，pR只向右扩而不回退。初始值为-1。
> 3. 回文中心index。表示最新一次更新pR时的回文中心位置。初始值为-1。
> 
> 对于这个题目，最好还有一个变量用于记录最长回文的索引位置max_index，然后根据这个位置的回文半径pArr[max_index]就可以拿到最长回文了。初始值为0，因为0位置一定为#，且回文半径一定为1。
> 
> 对于位置i，要计算它的回文半径pArr[i]:
> i位置有两种大的情况：
> 1. i位置位于最右回文右边界pR的左边(i<pR)，此时又根据i位置相对于index的对称位置i1的回文半径分为三种情况：
>   * i1的回文半径左边界位于index的回文半径的左边界的右边，此时pArr[i] = pArr[i1];
>   * i1的回文半径左边界位于index的回文半径的左边界的左边，此时pArr[i] = pR-i;
>   * i1的回文半径左边界与index的回文半径的左边界位置相同，此时pArr[i]就不能随便确定了，但最起码的是就是pR-i，还能否继续扩还要尝试。
> 2. i位置位于最右回文右边界pR的右边(i>=pR)，由于pR是即将到达的，所以等于的时候也是要从1开始尝试的。
> 
>总的来说，若i<pR，那么最起码的回文半径就是min(pArr[index*2-i], pR-1)，哪个离i近就是哪个；若i>=pR，那么就没办法了，最起码的回文半径是1，然后向两边（i-pArr[i]和i+pArr[i]）扩。可以根据i与pR的位置关系先确定最起码的回文半径大小，然后再往外扩尝试。注意每次计算了i位置的回文半径就需要看看是否需要更新pR, index和max_index。

```c++
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
```