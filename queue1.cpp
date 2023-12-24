/*#include<iostream>
using namespace std;
int queue[n];
int n=7;
int front=-1, rear=-1;

void enqueue(int val){
    if(rear==n-1){
        cout<<"Queue full";
        return;
    }    
    else if(front==-1 && rear==-1){
        front=rear=0;
    }
    else{
        rear++;
        queue[rear]=val;
    }
}
void dequeue(){
    if(front==-1 || front>rear){
        cout<<"Queue empty";
        return;
    }
    else if(front==rear){
        front=-1;
        rear=-1;
    }
    else{
        front++;
    }
}
void display(){
    if(front==-1 && rear==-1){
        return;
    }
    for(int i=front;i<=rear;i++){
        cout<<queue[i]<<" ";
    }
    cout<<endl;
}

void check(){
    if(front==-1 && rear==-1){
        cout<<"Queue empty";
    }
    else if(rear>=n-1){
        cout<<"Queue full";
    }
}

int main(){
    int n,k;
    check();
    cout<<endl;
    cin>>n;
    cout<<endl;
    for(int i=0;i<n;i++){
        cin>>k;
        enqueue(k);
    }
    check();
    cout<<endl;
    for(int i=0;i<n;i++){
        dequeue();
        display();
    }
    check();
    return 0;
}*/


#include <iostream>
using namespace std;

#define n 7
int queue[n];
int front = -1, rear = -1;

bool isFull() {
    if (rear == n - 1) {
        return true;
    }
    return false;
}

bool isEmpty() {
    if (front == -1) {
        return true;
    }
    return false;
}

void enqueue(int val) {
    if (isFull()) {
        cout << "Queue Full" << endl;
    } else {
        if (front == -1) {
            front = 0;
        }
        rear++;
        queue[rear] = val;
    }
}

int dequeue() {
    int ele;
    if (isEmpty()) {
        cout << "Queue Empty" << endl;
        return -1;
    } else {
        ele = queue[front];
        if (front == rear) {
            front = rear = -1;
        } else {
            front++;
        }
    }
    return ele;
}

void display() {
    if (isEmpty()) {
        cout << "Queue Empty.." << endl;
    } else {
        for (int i = front; i <= rear; i++) {
            cout << queue[i] << " ";
        }
        cout << endl;
    }
}
int main() {
    
    enqueue(50); 
    enqueue(100);  
    enqueue(25);
    enqueue(150); 
    enqueue(250);
    enqueue(75);
    enqueue(200);
    display();
    dequeue();
    display();
    dequeue(); 
    display();
    dequeue(); 
    display(); 
    dequeue();
    display();  
    dequeue();
    display(); 
    dequeue();
    display();
    

    return 0;
}
