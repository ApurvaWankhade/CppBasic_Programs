#include<iostream>
using namespace std;
#define n 5
int queue[n];
int front=-1,rear=-1;

bool isFull(){
    if(front==0 && rear==n-1){
        return true;
    }
    if(front==rear+1){
        return true;
    }
    return false;
}
bool isEmpty(){
    if(front==-1){
        return true;
    }
    else{
        return false;
    }
}
void enqueue(int val){
    if(isFull()){
        cout<<"Queue Full";
    }
    else{
        if(front==-1){
            front=0;
        }
        rear=(rear+1)%n;
        queue[rear]=val;
    }
}
int dequeue(){
    int ele;
    if(isEmpty()){
        cout<<"Queue Empty";
        return -1;
    }
    else if(front==rear){
        front=rear=-1;
    }
    else{
        ele=queue[front];
        front=(front+1)%n;
    }
    return ele;
}
void display(){
    int i;
    if(isEmpty()){
        cout<<"Queue Empty..";
    }else{
        for(i=front;i!=rear;i=(i+1)%n){
            cout<<queue[i]<<" ";
        }
        cout<<queue[i];
        cout<<endl;
    }
}
int main(){
    enqueue(50); 
    enqueue(100);  
    enqueue(25);
    enqueue(150); 
    enqueue(250);
    display();
    dequeue();
    display();
    enqueue(50); 
    display(); 
    dequeue(); 
    display();
    dequeue(); 
    display(); 
    enqueue(90);
    display(); 
    enqueue(80);  
    display();
    return 0;
}

