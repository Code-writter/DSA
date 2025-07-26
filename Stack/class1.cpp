#include<iostream>
#include<stack>
#include<string>
using namespace std;

class Stack{
    public:
    int *arr;
    int size;
    int top;

    Stack(int size){
        arr = new int[size];
        this -> size = size;
        top = -1;
    }

    // push
    void push(int data){
        if(top == size - 1){
            cout<<"Stack overflow"<<endl;
            return;
        }else{
            top++;
            arr[top] = data;
        }
    }

    void pop(){
        if(top == -1){
            cout<<"Cannot pop, stack underflow"<<endl;
        }else{
            top--;
        }
    }

    int getSize(){
        if(top == -1){
            return 0;
        }else{
            return top + 1;
        }
    }

    bool isEmpty(){
        if(top == -1){
            return true;
        }else{
            false;
        }
    }

    int topELe(){
        if(top == -1){
            cout<<"There is no top element"<<endl;
        }else{
            return arr[top];
        }
    }

};


void reverseString(string str){
    stack<char> st;
    for(int i = 0; i<str.size(); i++){
        char ch = str[i];
        st.push(ch);
    }

    while(!st.empty()){
        cout<<st.top()<<"  ";
        st.pop();
    }
}


int getMiddle(stack<int> st){
    int size = st.size();

    if(size % 2 == 0){
        // even
        int pos = 0;
        pos = size / 2
        
        
    }else{
        // odd


    }

}

int main(){
    stack<int> st;

    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);
    // st.push(50);
    int ans = getMiddle(st);
    cout<<ans<<endl;
    // reverseString("Lets see");

    return 0;
}