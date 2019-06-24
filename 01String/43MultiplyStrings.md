# Multiply Strings
[完整代码](https://github.com/ludandandan/LeetCode/blob/master/01String/43MultiplyStrings.cpp)

**题目：**

[leetcode](https://leetcode.com/problems/multiply-strings/)

给定两个以字符串表示的非负整数num1和num2， 返回num1和num2的乘积，同样以字符串形式返回

**举例：**
```
intput: num1="2", num2="3"
output: "6"
```

```
intput : num1="123", num2="456"
output: "56088"
```

注意:
1. num1和num2的长度都小于110
2. num1和num2中都只含有0~9的数字
3. 除了0本身外，num1和num2都不会以0开头
4. 不可以使用BigInteger库或将输入直接转换为整型


**解析：**

字符串相乘可以计算超大数相乘，不受int和long范围的限制。

两个字符串num1和num2相乘，若他们的长度分别为n1和n2，那么它乘积字符串的长度为n1+n2;

定义一个长度为n1+n2的vector\<int\>，每个位置是0~9的整型，开始时初始为0。用于临时记录num1和num2的乘积结果。与string相同，索引越小，表示的位越高。

num1和num2中的任意两个位置相乘，他们的结果在结果字符串和vector中的位置都是确定的。假设是num1的i位置与num2的j位置相乘，那么它结果的高位在(i+j)位置，低位在(i+j+1)位置。假设乘积为mul，那么先把mul加在低位上，然后除以10，商加在高位上，余数留在低位上。

由于是模拟整数的乘法，num1中每个位置上的数都要和num2中每个位置上的数乘一遍，所以需要两个for循环，时间复杂度O(n1*n2).需要从低位开始乘，所以num1和num2在遍历时应该从后往前遍历。

注意最后的时候：结果若是空的，那么返回0

```c++
class Solution{
public:
    //将两个字符串表示的整数相乘
    string mulStrings(string num1, string num2)
    {
        if(num1.empty() || num2.empty()) return "";
        string res; 
        int n1 = num1.size();
        int n2 = num2.size();
        //定义一个vector，大小为n1+n2,存放结果的从高位到低位
        //索引越小，位数越高，只有0~9
        vector<int> resV(n1+n2, 0);//初始化各个位都是0
        //乘法要从低位开始算，所以要对num1和num2倒着取
        for(int i=n1-1; i>=0; i--)
        {
            for(int j=n2-1; j>=0; j--)
            {
                int i0 = num1[i]-'0';
                int j0 = num2[j]-'0';
                int mul = i0*j0;
                //乘积先加到低位上，除以10商加到高位上，余数留在低位上
                int p1 = i+j;//高位
                int p2 = i+j+1; //低位
                resV[p2] += mul;
                resV[p1] += resV[p2]/10;
                resV[p2] = resV[p2]%10;
            }
        }

        //从vector中取出来放到string里
        for(int n: resV)
        {
            //先出高位再出低位，注意不要0开头
            if(!(res.empty() && n==0))
            {
                char c  = n+'0';
                res += c;
            }
        }
        return res;
    }
};

```