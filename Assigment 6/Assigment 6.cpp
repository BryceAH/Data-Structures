#include <iostream>
// #include <string>
#include "assigment 6.hpp"
#include <vector>
#include <algorithm>


using namespace std;


int main(){
vector<int> num;
Tree T;

T.add(5);
num.push_back(5);

T.add(2);
num.push_back(2);

T.add(8);
num.push_back(8);

T.add(1);
num.push_back(1);

T.add(4);
num.push_back(4);

T.add(7);
num.push_back(7);

T.add(9);
num.push_back(9);


cout << "The Values are: ";
for (int number : num){
    cout << number << " ";
}

cout << endl;

cout <<endl<< " ------------------- "<<endl;

T.display(T.getRoot());

cout << endl;


num.erase(std::remove(num.begin(), num.end(), 2), num.end()); // got this from the internet for tests
cout << "The New vlues after removal are: ";
for (int number : num){
    cout << number << " ";
}
cout << endl;
T.remove_node(2);



cout <<endl<< " ------------------- "<<endl;


T.display(T.getRoot());


return 0;       
}
