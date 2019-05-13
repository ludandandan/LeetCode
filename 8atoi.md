## String to Integer(atoi)
[完整代码](https://github.com/ludandandan/LeetCode/blob/master/8atoi.cpp)

**题目：**

[leetcode](https://leetcode.com/problems/string-to-integer-atoi/)

实现将字符串转换为整型。

一开始可能是以空格开始的，然后后面跟着正或负号，然后是一串数字，然后后面又可能跟着一些无关紧要的字符（就是除了数字0-9之外的字符）。目标是把那串数字转为整型，包括前面的正负号。

若这个字符串的第一个非空字符不是有效数字，或者这是个空串，或者它只包含空格，总之就是没有可以转换的字符的话就直接返回0

若转换后的整型超出[INT_MIN, INT_MAX]直接返回INT_MIN或INT_MAX。

对于有0在首位的怎么处理？-------把0忽略掉
对于+-或-+开头的怎么处理？----------无效为0

> 需要一个变量res储存结果，一个变量sign表示符号，最后返回的时候返回res*sign。一个变量k指向str的每一个字符。一个变量n记录str的长度，用以限制k。
> 
> 首先处理空格，一个while循环，若是空格k就++。然后看看是否是+-号，然后若是k就++。然后就是一个for循环，若里面不是数字了就break返回。同时还要处理数字溢出问题。检查溢出：res>INT_MAX/10 || (res==INT_MAX/10 && a==INT_MAX-res*10)。

```c++
class Solution{
public:
    int myatoi(string s)
    {
        if(s.empty()) return 0;
        int n = s.size();
        int k = 0;
        int sign = 1;
        int res = 0;
        while(s[k]==' ') k++;
        if(s[k]=='+') k++;
        else if(s[k]=='-')
        {
            sign = -1;
            k++;
        }
        for(; k<n; k++)
        {
            if(s[k]<'0' || s[k]>'9')
            {
                return res*sign;
            }
            else
            {
                int a = s[k]-'0';
                if(res>INT_MAX/10 || ((res==INT_MAX/10) && (a>(INT_MAX-res*10))))
                {
                    return sign==1?INT_MAX:INT_MIN;
                }
                else res = res*10+a;
            }
        }
        return res*sign;
    }
};
```