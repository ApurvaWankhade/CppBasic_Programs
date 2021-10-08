#include<iostream>
using namespace std;

void swap(int &a, int &b){
	int temp = a;
	a=b;
	b=temp;
}
void selection(int *arr,int n) {
   int min;
   for(int i= 0; i<n-1; i++) {
      min = i;   //get index of minimum data
      for(int j = i+1; j<n; j++)
         if(arr[j] < arr[min])
            min = j;
         //placing in correct position
         swap(arr[i], arr[min]);
   }
}
int main(){
	int n;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	selection(arr,n);
	for(int i=0;i<n;i++){
		cout<<arr[i]<<" ";
	}
}