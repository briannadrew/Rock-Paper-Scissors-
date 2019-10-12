/*
Program: Rock! Paper! Scissors! (Lab #1)
Name: Brianna Drew
ID: 0622446
Date Created: 09/26/2019
Last Modified: 09/29/2019
*/

#include <stdio.h> // include library that includes functions for input/output
#include <stdlib.h> // include library that includes various functions such as the random function
#include <time.h> // include library that includes functions that manipulate date and time
#include <stdbool.h> // include library for boolean variables

char GetUserInput(); // declaration of function to take user inputted move (returns a character)
char GetComputerChoice(); // declaration of function to generate the computer's move (returns a character)
int FindWinner(char, char); // declaration of function to determine winner of match (takes two character parameters and returns an integer)
int toupper(); // declaration of function to convert to uppercase
bool running = true; // declaration of boolean variable to keep playing the game
bool invalid = true; // declaration of boolean variable to continue error checking user input


int main() // main function (main program, returns integer)
{
        char user_choice; // declaration of variable to store user's move
        char computer_choice; // declaration of variable to store computer's move
        int result; // declaration of variable to store
        printf("Welcome to Rock! Paper! Scissors!"); // print introduction statement

        do // loop game...
        {
            invalid = true; // set invalid variable to true to so validity check do while loop runs
            printf("\n\n"); // print two new lines
            printf("Choose your move! Type 'R' for 'Rock', 'P' for 'Paper', or 'S' for 'Scissors'. Or, type 'Q' to quit... "); // print instructional statement

            do // loop validate user's input...
            {
                user_choice = toupper(GetUserInput()); // call function to get user's inputted move, convert input to uppercase, and store it in the user_choice variable

                if (user_choice == 'R') // if the user chooses Rock...
                {
                    printf("You chose: Rock"); // print statement confirming that they chose Rock
                }

                if (user_choice == 'P') // if the user chooses Paper...
                {
                    printf("You chose: Paper"); // print statement confirming that they chose Paper
                }

                if (user_choice == 'S') // if the user chooses Scissors...
                {
                    printf("You chose: Scissors"); // print statement confirming that they chose Scissors
                }

                // if the user entered character is not a valid move or quit...
                if (user_choice == 'R' || user_choice == 'P' || user_choice == 'S' || user_choice == 'Q')
                {
                    invalid = false; // set invalid variable to false so validity check do while loop does not run again
                    break; // break from do while loop
                }

                printf("Ivalid choice please try again."); // print error statement
                printf("\n\n"); // print two new lines
                printf("Choose your move! Type 'R' for 'Rock', 'P' for 'Paper', or 'S' for 'Scissors'. Or, type 'Q' to quit... "); // print instructional statement
            } while (invalid); // ...while the boolean invalid is still true

            if (user_choice == 'Q'){ // if the user chooses to quit the game...
                running = false; // set running variable to false so main do while loop does not run again
                break; // break from do while loop
            }

            printf("\n"); // print new line
            computer_choice = GetComputerChoice(); // call function to get computer's move and store it in computer_choice variable
            result = FindWinner(user_choice, computer_choice); // call function to find the winner and store result in result variable

            if (result == 0) // if the integer returned from FindWinner() is 0...
            {
                // the user and computer tie
                printf("It's a tie!");
            }

            if (result == -1) // if the integer returned from FindWinner() is -1...
            {
                // the user loses
                printf("You lose!");
            }

            if (result == 1) // if the integer returned from FindWinner() is 1...
            {
                // the user wins
                printf("You win!");
            }

        } while (running); // ...while the boolean running is still true

        return 0; // return exit code 0 to main function to end program
}


char GetUserInput() // GetUserInput function, called in main function and gets inputted character from user representing their move and returns that character to main function
{
        char user_choice; // declaration of variable to store user's move
        scanf(" %c", &user_choice); // take user input (user's move) as a single character and store in user_choice variable by reference (space before %c so any whitespaces are skipped)
        return user_choice; // return the user's move to main function
}


char GetComputerChoice() // GetComputerChoice function, called in main function and generates a random integer from 0-2 each representing a move, then returns character representing the given move to main function
{
        char computer_choice; // declaration of variable to store computer's move
        int user = rand()%2; // generate random integer from 0 - 2 and store it in user variable

        if(user == 0) // if the randomly generated number is 0...
        {
                // the computer's move is Paper
                computer_choice = 'P';
                printf("Your opponent chose: Paper");
        }

        if(user == 1) // if the randomly generated number is 1...
        {
                // the computer's move is Rock
                computer_choice = 'R';
                printf("Your opponent chose: Rock");
        }

        if(user == 2) // if the randomly generated number is 2...
        {
                // the computer's move is Scissors
                computer_choice = 'S';
                printf("Your opponent chose: Scissors");
        }

        printf("\n"); // print new line
        return computer_choice; // return the computer's move to main function
}


int FindWinner(char user_choice, char computer_choice) // FindWinner function, called in main function and passed two character parameters representing the user's and the computer's moves, then compares the moves to determine a winner, then returns an integer to main function representing 1 of 3 results
{
    // if the user and computer choose the same move...
    if ((user_choice == 'R' && computer_choice == 'R') || (user_choice == 'P' && computer_choice == 'P') || (user_choice == 'S' && computer_choice == 'S'))
    {
        return 0; // return a 0 representing a tie
    }

    // if the user's move beats the computer's move...
    if ((user_choice == 'R' && computer_choice == 'S') || (user_choice == 'P' && computer_choice == 'R') || (user_choice == 'S' && computer_choice == 'P'))
    {
        return 1; // return a 1 representing a win for the user
    }

    // if the computer's move beats the user's move...
    if ((user_choice == 'R' && computer_choice == 'P') || (user_choice == 'P' && computer_choice == 'S') || (user_choice == 'S' && computer_choice == 'R'))
    {
        return -1; // return a -1 representing a loss for the user
    }
}
