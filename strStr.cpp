#include <iostream>
#include <map>
#include <vector>
#include <string.h>

/*
 Implement strStr().

Returns the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.

Update (2014-11-02):
The signature of the function had been updated to return the index instead of the pointer. If you still see your function signature returns a char * or String, please click the reload button to reset your code definition.

*/


/*
My Note


*/




using namespace std;

class Solution {
public:
    int strStr(char *haystack, char *needle) {
        if (needle == NULL )
            return -1;
        if (*needle == '\0')
            return 0;
        int sub = strlen(haystack) - strlen(needle) +1;
        for(int i = 0; i<sub; i++)
        {
            char* pH = haystack+i;  // increase the begin
            char* pN = needle;
            while(*pH == *pN)
            {
                ++pH;  // this add first
                if ( *(++pN) == '\0' )
                    return i;
            }
        }
        return -1;
    }
};

int main()
{
    Solution s;

    char* a = "a";
    char* b = ""; // what is ""
    // size of pointer is 4, size of char is 1
    cout<<"strlen of b is " << strlen(b) <<", sizeof b is " << sizeof(*b) <<", sizeof a is " << sizeof(a) <<endl;
    char* index = strstr(a,b);
    int i = s.strStr(a,b);
    cout<<"index is " << index <<", i is " << i <<endl;


    return 1;
}

