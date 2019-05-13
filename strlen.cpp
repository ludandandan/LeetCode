#include <cstdio>
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

class Solution{
public:
    size_t strlen(const char *str)
    {
        const char *s;
        for(s=str; *s; s++){}
        return (s-str);
    }
};

int main()
{
    Solution s;
    char a[100];
    int i=0;
    printf("Please input a string!\n");
    scanf("%s",a);
    size_t n = s.strlen(a);
    printf("the length of this string is %zu\n", n);
    return 0;
}
