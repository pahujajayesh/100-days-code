#include <iostream>
#include<cstring>
using namespace std;
void sayDigit(string s[],int n){
    if(n==0){
        return;
    }
    int digit=n%10;
    n=n/10;
    sayDigit(s,n);
    cout<<s[digit]<<" ";
}
int main()
{
    string s[10] = { "zero",
                     "one",
                     "two",
                     "three",
                     "four",
                     "five",
                     "six",
                     "seven",
                     "eight",
                     "nine" };
    int n;
    cin >> n;
    sayDigit(s,n);
}