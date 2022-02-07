//time- O(n)
//space -o(n)
#include<iostream>
#include<cstring>
#include<stack>
using namespace std;
int main()
{
    string str="jayesh";
    stack<char>s;
    for(int i=0;i<str.length();i++){
        char a=str[i];
        s.push(a);
    }
    string ans;
    while(s.empty()!=true){
        char ch=s.top();
        ans.push_back(ch);
        s.pop();
    }   
    cout<ans;


return 0;
}