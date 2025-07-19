#include<iostream>
using namespace std;
   
int fact(int num){
    if(num == 0){
        return 1;
    }
    if(num == 1){
        return 1;
    }

    return num * fact(num - 1);
}


int main(){
    int num;
    cin>>num;
    int ans = fact(num);
    cout<<"Fact is : "<<ans<<endl;
    return 0;
};