#include<iostream>
using namespace std;

int main(){
	int n,key,j;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++){
	  cin>>arr[i];		
	}
	
	for(int i=1;i<n;i++){
	  key=arr[i];
	   j=i;
	  while(j>=0 && arr[j-1]>key){
	  	arr[j]=arr[j-1];
	  	j--;	  	
	  }
	  arr[j]=key;
	}
   for(int i=0;i<n;i++){
	  cout<<arr[i]<<" ";
   }
	return 0;
}