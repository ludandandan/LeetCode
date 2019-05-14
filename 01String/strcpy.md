# strcpy
[完整代码](https://github.com/ludandandan/LeetCode/blob/master/01String/strcpy.cpp)

**题目：**

实现strcpy函数，字符串拷贝，函数原型char* strcpy(char *to, const char *from);

> 从from中复制到to中。原来字符串的值不能改变，所以要定义为const char类型的指针，然而to需要改变值的故不能是const的。
> 
> 并且这个函数还要有返回值，这样方便链式表达。比如需要把a复制到b，把b复制到c，那么有返回值的函数可以写作c=strcpy(b,a)，没有返回值的函数就是strcpy(b,a); strcpy(c,b)。或者测b的长度strlen(strcpy(b,a))，没有返回值就需要strcpy(b,a); strlen(b)；
> 
> 先检测to和from是否是空的，用一个断言assert，需要包含头文件cassert。
> 需要一个char指针p指向to，这样可以移动p来复制，然后返回首地址的时候仍返回to，若用to移动的话以后会找不到首地址。
> 原来赋值语句也是有值的，它的值就是赋的值。
> 一个一个的将from指针的值赋值给p然后他们都往后移，直到到达string的末尾（'\0'）就结束

```c++
class Solution{
public:
    char* strcpy(char *to, const char *from)
    {
        assert(to!=nullptr && from !=nullptr);
        char *p = to;
        while((*p++ = *from++)!='\0') ;
        return to;
    }
};
```