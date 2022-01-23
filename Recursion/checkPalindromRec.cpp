#include<iostream>
#include<cstring>
using namespace std;
bool checkpalindrome(string str,int i,int j){
    if(i>j){
        return true;
    }
    if(str[i]!=str[j]){
        return false;
    }
    else{
        return checkpalindrome(str,i+1,j-1);
    }

}   
int main()
{
    string str="aaabaa";
    if(checkpalindrome(str,0,str.length()-1)){
        cout<<"it is a plaindrom";
    }
    else{
        cout<<"not a plaindrome";
    }

return 0;
}