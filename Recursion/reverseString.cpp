#include <iostream>
#include <cstring>
using namespace std;
void reverseString(string &str, int i)
{
    
    if (i > str.length()-i-1)
    {
        return;
    }
    swap(str[i], str[ str.length()-i-1]);
    i++;
    reverseString(str, i);
}
int main()
{
    string str = "abcd";
    reverseString(str, 0);
    cout << str;
    return 0;
}