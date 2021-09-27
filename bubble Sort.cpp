#include<iostream>
using namespace std;
int main(){
	int n,a[10];
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	int pass=0;
	for(int i=0;i<n;i++){
	    for(int j=0;j<n-i-1;j++){
	       if(a[j]>a[j+1]){
	       	int temp=a[j];
	       	a[j]=a[j+1];
	       	a[j+1]=temp;
	       }
        }
        pass++;
   }
   for(int i=0;i<n;i++){
      cout<<a[i]<<" ";
   }
   cout<<"\n"<<pass;
   return 0;	
}