#include<iostream>
using namespace std;


// int main(){
//     int num = 5;

//     for(int row = 0; row< num; row++){
//         for(int col = 0; col < num - row; col++){
//             cout<<col;
//         }
//         cout<<endl;
//     }
// }

/*
01234
0123
012
01
0
*/


// int main(){
//     int num = 5;

//     for(int row = 0; row< num; row++){
//         for(int col = row + 1; col <= num ; col++){
//             cout<<col;
//         }
//         cout<<endl;
//     }
// }

/*
12345
2345
345
45
5
*/

int main(){
    int num = 5;

    for(int row = 0; row< num; row++){
        for(int col = row + 1; col <= num ; col++){
            if(col == row + 1 || col == num || row == 0 ){
                cout<<col;
            }else{
                cout<<" ";
            }
        }
        cout<<endl;
    }
}