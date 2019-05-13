# strlen

[完整代码](https://github.com/ludandandan/LeetCode/blob/master/strlen.cpp)

**题目：**

实现strlen，获取字符串的长度，函数原型如下：size_t strlen(const char *str)。

> 这个题目的输入需要是char数组类型，例如char mystr[100] = "test string"; C string的长度取决于其空结束符，也就是说到空null-character（不是空格）这个字符串就结束了。
> 
> 处理输入：定义一个char数组，直接用scanf输入%s即可（我原来还用while,%c之类的，然后发现完全不需要）
> 定义一个指向const char类型的指针s，然后让这个指针指向string的首地址，然后逐个后移直到对s解引用(*s)变为null，用此时的s减去string的首地址就是string的长度（string的最后一个字符的后面一个地址减去首地址即为字符串长度）。
> 
> const char *s不能改变其所指对象的值，但可以改变其所指的对象，这就是为什么这个s可以++，这样它就可以指向它后面的一个对象了，而不改变这个对象的值。
```c++
class Solution{
public:
    size_t strlen(const char *str)
    {
        const char *s;
        for(s=str; *s; s++){}
        return (s-str);
    }
};
```