# Add Binary
[完整代码]()

**题目：**
[LeetCode](https://leetcode.com/problems/add-binary/)

给定两个二进制字符串，然后返回这两个二进制的和（以二进制字符串的方式）。两个输入字符串都是非空的并且仅包含字符0和1。
例如：input a="11", b="1", output: "100"

> 需要先把a,b字符串反转。还要定义一个整型表示进位，一个字符串res表示结果。两个整型ia,ib表示进行到字符串a和b的哪个位置了，若ia超出a的大写了那么就把ia指的数字置0。直到两个字符串a和b都处理完了才结束while。注意新数是加再res的前面的。
> 
> 注意最后再检查一下进位carry里面有没有数，有的话加上

```c++
class Solution{
public:
    string addBinary(string a, string b)
    {
        string res;
        int carry = 0; //进位
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        int ia = 0;
        int ib = 0;
        int na = a.size();
        int nb = b.size();
        while(ia<na || ib<nb)
        {
            int numa = ia<na?a[ia++]-'0':0;
            int numb = ib<nb?b[ib++]-'0':0;
            int n = numa+numb+carry;
            char c = (n%2) + '0';
            res = c + res;
            carry = n/2;
        }
        char c = carry+'0';
        if(carry!=0) res = c + res;
        return res;
    }
};
```