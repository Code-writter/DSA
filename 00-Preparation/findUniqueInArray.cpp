// #include<bits/stdc++.h>
// using namespace std;
   

// int main(){

//     int arr[] = {1,0,0, 1, 1, 1, 0, 0, 0, 1 };
    
//     int size = sizeof(arr)/sizeof(arr[0]);
//     // int ans = 0;
//     // for(int i = 0; i<size; i++){
//     //     ans = ans^arr[i];
//     // }
    
//     // cout<<"Answer is : "<<ans<<endl;

//     // This will take O(n)sqr
//     // for(int i = 0; i<size; i++){
//     //     for(int j = i; j < size; j++){
//     //         cout<<"( "<<arr[i]<<", "<<arr[j]<<" ) ,";
//     //     }
//     // }

//     // sort os and 1s
//     // Approach 1 :- sort function 
//     // Approach 2 :- Count number of 0s and 1s then spread
//     // Approach 3 :- two pointers
//     int i = 0;
//     int j = size;
//     while(i<j){
//         if(arr[i] == 0){
//             i++;
//         }else if(arr[j] == 1){
//             j--;
//         }
//         else{
//             swap(arr[i], arr[j]);
//             i++; 
//             j++;
//         }
//     }

//     for(int i = 0; i<size; i++){
//         cout<<arr[i]<<"  ";
//     }

//     return 0;
// };


// #include<bits/stdc++.h>
// using namespace std;
   
// int main(){

//     int arr[] = {1,0,0, 1, 1, 1, 0, 0, 0, 1 };
//     int size = sizeof(arr)/sizeof(arr[0]);

//     int i = 0;
//     int j = size - 1;

//     while(i < j){

//         if(arr[i] == 0){
//             i++;
//         }else if(arr[j] == 1){
//             j--;
//         }else{
//             swap(arr[i++], arr[j--]);
//         }
//     }

//     for(int i = 0; i<size; i++){
//         cout<<arr[i]<<"  ";
//     }

//     return 0;
// };


#include<bits/stdc++.h>
using namespace std;
   
int main(){

    int arr[] = {};
    int size = sizeof(arr)/sizeof(arr[0]);

    int i = 0; 
    

    return 0;
}; 
