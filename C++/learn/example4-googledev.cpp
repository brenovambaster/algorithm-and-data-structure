// game secret number
#include <iostream>
#include <time.h>
using namespace std;

int random()
{
    int random_number;
    // Initialize random seed.
    srand(time(NULL));
    // Generate random number between 1 and 100
    return random_number = rand() % 100 + 1;
}
void tips(int input, int number_secret)
{
    if (input < number_secret)
        cout << "The secret number is higher than " << input << endl;
    else if (input > number_secret)
        cout << "The secret number is  lower  than " << input << endl;
    else
        cout << "Congratulations!!!" << endl;
}
int main()
{
    int secret_number = random();
    int input_player;
    cout << secret_number << endl;
    do
    {
        cout << "Enter your number (-1 = quit):" << endl;
        if (!(cin >> input_player))
        {
            cout << "You entered a non-numeric. Exiting..." << endl;
            break;
        }
        if (input_player == -1)
        {
            cout << "Exiting...";
            break;
        }
        tips(input_player, secret_number);

    } while (input_player != secret_number);
}