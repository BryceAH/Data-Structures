#include <iostream>
#include <string>
#include <map>
#include <vector>






using namespace std;
using std::string;
using std::stoi;


class Hash{

private:
        int int_capacity;
        int size;
        vector<string> word_bank = {"bark", "star", "moon", "fish", "bird", "wind", "rain", "fire", "snow", "leaf", "root", "dark", "cold", "warm", "song", "bell", "door", "home", "road"};




public:
    Hashes();

        string string_to_hash(string word) // this function hashes the word into numbers
        {
        string hashed_word;
        map<char, string> alphabet; // Map that assigns letters in the alphabet to numbers

        // Using a for loop to assign letters to numbers
        for (char i = 'a'; i <= 'z'; i++) {
            string number;
            if (to_string(i - 'a' + 1).length() > 1) // determinds if the number is greater than 10 by counting the amount of digits it has
            {
                number = to_string(i - 'a' + 1);
            }
            else 
            {
                number = "0" + to_string(i - 'a' + 1); // if the value is less than one add a 0 to make it 2 digits
            }
            alphabet[i] = number;
        }
        
        for (int i = 0; i < word.size(); i++)
        {
            cout << word[i] <<": " <<alphabet[word[i]] << endl;
            hashed_word = hashed_word.append(alphabet[word[i]]);
            // cout << word[i] << endl;
        }
        // int int_hashed_word = stoi(hashed_word);

        cout << "Full hash: " << hashed_word << endl;

        return hashed_word;

        }
    

        string hash_to_string(string hashed_word)
        {
        string word;

        for (size_t i = 0; i < hashed_word.length(); i+=2)
        {
            string bit = hashed_word.substr(i,2); // grabs two of the valus at position i
            int val_bit = stoi(bit); // converts that value to the letter
            char letter = 'a' + val_bit - 1; // simular equation as eralier to convert the number back to the letter
            word += letter;
        }

        bool contains = false;
        for (size_t i = 0; i < word_bank.size(); i++)
        {
            if (word_bank[i] == word)
            {
                contains = true;
            }

        }
        if (contains == true)
        {
            return word;
        }else
        {
            return "DNE";
        }
        

        }



};
