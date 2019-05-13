#include <cstdio>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <cassert>
using namespace std;

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



int main()
{
    Solution s;
    char a[100];
    scanf("%s", a);
    char *b;
    s.strcpy(b, a);
    cout << b << endl;
    int c;
    if((c=5)==5) cout << 5 << endl;
    return 0;
}
