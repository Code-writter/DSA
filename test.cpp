#include<iostream>
#include<unordered_map>
#include<map>
using namespace std;
   


int main(){
    unordered_map<int, int> umap;
    int arr[] = {14, 15, 16, 3};
    int size = 4;
    for(int i = 0; i<size; i++){
        umap[i] = arr[i];
    }


    for(int i = 0; i<size; i++){
        cout<<umap[i]<<endl;
    }
};