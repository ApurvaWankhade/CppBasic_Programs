#include<iostream>
using namespace std;

void towerOfHanoi(int n,char a,char c,char b){
    if(n==0){
        return;
    }
    towerOfHanoi(n-1,a,b,c);
    cout<<a<<":"<<c<<endl;
    towerOfHanoi(n-1,b,c,a);
}
int main(){
    int n=3;
    towerOfHanoi(n,'a','c','b');
    return 0;
}