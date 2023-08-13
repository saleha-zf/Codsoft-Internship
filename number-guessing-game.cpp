#include <iostream>
#include <chrono>
#include <thread>// including for time delays
#include <cstdlib> //including for clearing screen
using namespace std;


void printDivider()
{
    cout << "---------------------------------\n";
}
//setting customised colors using escape sequences
void setConsoleColor(string colorCode)
{
    cout << "\033[" << colorCode << "m";
}

//adding a "delay" using chrono library for a type-writer effect
void delayEffect(string message, int delay)
{
    for (int i = 0; i < message.length(); i++)
    {
        cout << message[i] << flush;
        this_thread::sleep_for(chrono::milliseconds(delay));
    }
}

//this function checks if the user's guess is close to the target
//in this case we check if the guess is 5 digits above or below the target
bool isClose(int target, int guess)
{
    int difference = abs(target - guess);
    return difference <= 5;
}

int main()
{
    int num, guess, tries = 0;
    srand(time(0)); //seed random number generator
    num = rand() % 100 + 1; // random number between 1 and 100

    cout << "Welcome to the Number Guessing Game!\n\n";

    do
    {
        printDivider();
        setConsoleColor("0"); // Set console text color to default
        cout << "Enter a guess between 1 and 100: ";
        cin >> guess;
        tries++;

        if (guess > num)
        {
            setConsoleColor("31"); // Set console text color to red
            cout << "Too high! ";
            if (isClose(num, guess))
            {
                cout << "But you're close!\n";
            }
            else
            {
                cout << "Try again.\n";
            }
        }
        else if (guess < num)
        {
            setConsoleColor("31"); // Set console text color to red
            cout << "Too low! ";
            if (isClose(num, guess))
            {
                cout << "But you're close!\n";
            }
            else
            {
                cout << "Try again.\n";
            }
        }
        else
        {
            printDivider();
            setConsoleColor("32"); // Set console text color to green
            string congratsMessage = "Correct! You got it in " + to_string(tries) + " tries!\nCongratulations! :)\n";
          
          //setting delay to 80 milliseconds
            delayEffect(congratsMessage, 80);
            printDivider();

            setConsoleColor("0"); // Set console text color to default
            cout << "Would you like to play again? (Y/N): ";
            char playAgain;
            cin >> playAgain;

            if (playAgain == 'Y' || playAgain == 'y')
            {
                num = rand() % 100 + 1;
                tries = 0;
              // Clear the console screen
                system("clear"); // Use "cls" for Windows
                cout << "\nGreat! Let's play again.\n\n";
            }
            else
            {
                printDivider();
                cout << "Thank you for playing. Goodbye! :)\n";
                break;
            }
        }
    } while (true);

    return 0;
}