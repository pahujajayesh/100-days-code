#include<iostream>
#include<cstring>
using namespace std;
int main()
{
    bool found=true;
    int n;
    cin>>n;
    string s;
    for(int i=0;i<n;i++){
        cin>>s[i];
    }
    int i=0;
    int j=n-1;
    while(i<=j){
        if(s[i]!=s[j]){
            found=false;
            break;
        }
        i++,j--;
    }
    if(found){
        cout<<"true"<<endl;
    }
    else{
        cout<<"false";
    }
return 0;
}