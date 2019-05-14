# Valid Palindrome
[完整代码](https://github.com/ludandandan/LeetCode/blob/master/01String/125ValidPalindrome.cpp)

**题目：**

[LeetCode](https://leetcode.com/problems/valid-palindrome/)

给定一个字符串，确定它是否是回文串，只考虑数字和字母并忽略大小写。

注意：定义空串为有效回文

例如： input: "A man, a plan, a canal: Panama", output: true;

> 需要先把字母全部转为小写，这时就需要transform函数了还有::tolower（大写的话是toupper）。transform(str.begin(), str.end(), str.begin(), ::tolower)，表示把str从begin到end转为小写并把转换后的结果放到以str的开头为开头的字符串中。
> 然后需要两个整型变量表示两个指针left和right，分别指向str的头和尾，若不是数字和字母就把left和right移动，直到是数字或字母，同时需要检查left是否是小于right的，若不是那么就要结束了。若left和right指向的都是数字和字母就需要比较两个是否相等，若left还小于right而两个s[left]与s[right]不相等了就需要返回false了，若到最后left不大于right了都没返回false那么就可以返回true了。

```c++
class Solution{
public:
    bool isPalindrome(string s)
    {
        if(s.empty()) return true;
        transform(s.begin(), s.end(), s.begin(), ::tolower);
        int left = 0;
        int right = s.size()-1;
        while(left < right)
        {
            while((left<right) && !((s[left]>='0' && s[left]<='9') || (s[left]>='a' && s[left]<='z'))) left++;
            while((left<right) && !((s[right]>='0' && s[right]<='9') || (s[right]>='a' && s[right]<='z'))) right--;
            if(left<right && s[left]!=s[right]) return false;
            else
            {
                left++;
                right--;
            }
        }
        return true;
    }
};
```