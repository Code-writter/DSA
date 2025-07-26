#include<iostream>
#include<vector>


using namespace std;

int findUniqueElement(vector<int> arr){
    int element = 0;
    for(auto e : arr){
        element = element ^ e;
    }
    return element;
}

void printAllPairs(vector<int> arr){
    for(int i = 0; i<arr.size(); i++){
        for(int j = 0; j <arr.size(); j++){
            cout<<"{ "<< arr[i]<<", "<<arr[j]<<" }, ";
        }
    }
}

void putZeroAtStart(vector<int> arr){
    int startPointer = 0;
    int endPointer = arr.size() - 1;

    while(startPointer < endPointer){

        if(arr[endPointer] == 1 && arr[startPointer] == 0){
            cout<<"Infif"<<endl;
            startPointer++;
            endPointer--;
        }else{
            swap(arr[startPointer], arr[endPointer]);
        }

        startPointer++;
        endPointer--;
    }

    for(auto i : arr){
        cout<<i<<"  ";
    }
}

void rightShift(vector<int> arr){
    int lastElement = arr[arr.size() - 1];
    int i = arr.size() - 1;

    while(i > 0){
        arr[i] = arr[i - 1];
        i--; 
    }

    arr[0] = lastElement;

    for(auto i : arr){
        cout<<i<<"  ";
    }
}


int main(){
    vector<int> arr = {10, 20, 30, 40, 50};

    rightShift(arr);
}