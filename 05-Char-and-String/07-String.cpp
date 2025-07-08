#include <iostream>
using namespace std;


void utilityFns(string name){
    cout << "Length of string "<<name.length()<<endl;
    cout << "Check empty or not "<<name.empty()<<endl;

    // at
    cout<< name.at(0) << "At 0th position " <<endl;

    cout<<"Front character of string "<<name.front()<<endl;

    cout<<"End character of string "<<name.back()<<endl;


    // Concatinate two strings
    string str1 = "hello ";
    string str2 = "Byee";

    str1.append(str2);

    // Str1 get appends with str2
    cout << str1 <<endl;
    cout<<str2<<endl;

    // erase (from index, how may elements)
    name.erase(4, 3);

    // Insert at the end
    name.push_back('a');
    // Remvoe at the end
    name.pop_back();

    // IMP : find specific string;
    // If not found return npos (not position)

    if( str1.find(str2) == string::npos){
        cout<<"Not Found "<<endl;
    }

    // compare two stirngs
    str1.compare(str2);


    // Get sub part of string
    // substr( form index, how many length word )
    string str = "This is the best thing in the world";
    str.substr(4, 6);


}

int main(){
    string name;

    // cin>>name;

    getline(cin, name);
    utilityFns(name);
}