#include <iostream>

using std::cout;
using std::cin;
using std::toupper;

int marbles() {
    char out_in;
    static int Num_of_Marbles = 0;
    int marbles_in;
    int marbles_out;

    cout << "The number of marbles you have is " << Num_of_Marbles << "\n";

    cout << "Would you like to pull marbles out or in? [O/I] ";
    cin >> out_in;
    out_in = toupper(out_in);

    if (out_in == 'O') {
        cout << "How many marbles would you like to take out? ";
        cin >> marbles_out;
        if (marbles_out <= Num_of_Marbles){
            Num_of_Marbles -= marbles_out;
        }
        else {
            cout << "You do not have enough marbles " << "\n";
            return 0;
        }

    } 
    
    else if (out_in == 'I') {
        cout << "How many marbles would you like to put in? ";
        cin >> marbles_in;
        Num_of_Marbles += marbles_in;
    }

    cout << "You currently have: " << Num_of_Marbles << " Marbles\n";
    return Num_of_Marbles;
}

int main() {
    int Num_of_Marbles = 0;

    while (true) {
        Num_of_Marbles = marbles();

        char choice;
        cout << "Do you want to continue? [Y/N]: ";
        cin >> choice;
        if (toupper(choice) != 'Y') {
            break;
        }
    }

    return 0;
}
