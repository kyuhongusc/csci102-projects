//=============================================================================
// Name: Kyuhong Lee
// E-mail: kyuhongl@usc.edu
// Description: A Rock Paper Scissors Program that integrates rand() to create random games
//  
// ------------------------ Test case Inputs ----------------------------------
//  Test 1 input: <Any input of 0-2>
//  Test 1 output: The inputs above will play the game accordingly, and as the computer randomly generates choices, the output will be unknown; either <"You win!", "Computer Wins!">
// 
//  Test 2 input: <3>
//  Test 2 output: <"Thanks for playing!">
//
//  Test 3 input: <-100>
//  Test 3 output: <"Invalid option. Enter a number between 0 and 3.">
//=============================================================================

// ------------ Add #includes and other statements here ----------
#include <iostream>
#include <cstdlib>
using namespace std;

// ------------ Add your main() function below ----------
int main() {
  int input;
  int computerChoice;
  string choices[3] = {"Rock", "Paper", "Scissors"}; // array for storing choices
  while (true) {
    computerChoice = rand() % 3 ; // random number between 1 and 4
    cout << "Enter a choice:" << endl << "0: Rock" << endl << "1: Paper" << endl << "2: Scissors" << endl << "3: Quit" << endl;
    cin >> input;
      if (input == 3) {
        cout << "Thanks for playing!" << endl;
        return 0;
      }
      if (input < 0 || input > 3) {
        cout << "Invalid option. Enter a number between 0 and 3." << endl;
      }
      if (input >= 0 && input <= 3) {
        cout << "You picked " << choices[input] << endl;
        cout << "The computer picked " << choices[computerChoice] << endl;
      }
      if (input == computerChoice) {
        cout << "It's a tie!" << endl;
      }
      else if ((input == 0 && computerChoice == 2) ||
               (input == 1 && computerChoice == 0) ||
               (input == 2 && computerChoice == 1)) {
        cout << "You win!" << endl; 
      }
      else{
        if (input > 0 && input < 3){
          cout << "Computer wins!" << endl;
        }
      }
  }
  return 0;
}
