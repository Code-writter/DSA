#include<iostream>
using namespace std;

int main(){
    int num = 5;

    for(int i = 0; i<num; i++){
        for(int j = 1; j <= i + 1; j++){
            cout <<j;
        }
        cout<<endl;
    }
}
/*
1
12
123
1234
*/


// int main(){
//     int num = 5;

//     for(int i = 0; i<num; i++){
//         for(int j = 0; j < i + 1; j++){
//             if(j == 0 || j == i  || i == num - 1){
//                 cout<<j;
//             }else{
//                 cout<<" ";
//             }
//         }
//         cout<<endl;
//     }
// }