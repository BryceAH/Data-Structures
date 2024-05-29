#include <iostream>
#include "Assigment 7.hpp"
#include <vector>
#include "Assigmnet 7 bt.hpp"




using namespace std;

int main() {
    Hash H;
    Tree T;

    string hashed;

    //cannot go past 4 letters due to 5 letters being able to surpass the threshold of 2147483647 
    vector<string> word_bank = {"bark", "star", "moon", "fish", "bird", "wind", "rain", "fire", "snow", "leaf", "root", "dark", "cold", "warm", "song", "bell", "door", "home", "road"};


    for (int i = 0; i < word_bank.size(); i++)
    {
    hashed = H.string_to_hash(word_bank[i]);
    T.add(hashed);
    }

    T.display(T.getRoot());

    T.remove_node(19200118, H); // hashed star

    // T.remove_node(20180505, H); // hashed tree which is not in the vector


    T.display(T.getRoot());



    // H.hash_to_string(hashed);

    return 0;
}
