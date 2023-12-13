#include <iostream>

using namespace std;


/** 
 * Prints the leaderboard in the appropriate (sorted by candy count) order
 *
 * Parameters:
 *   players: Array of player names
 *   candy: Array of candy counts (candy count at location i corresponds to
 *          the player name at location i in the players array)
 *   numplayers: Number of players and candy counts in the respective arrays
 */
void printLeaderboard(string players[], int candy[], int numplayers);


/** 
 * Update the candy count of the given player to reflect the number
 * of pieces of candy they found. Do nothing (just return)
 * if the given player does not exist in the arrays already
 *
 * Parameters:
 *   players: Array of player names
 *   candy: Array of candy counts (candy count at location i corresponds to
 *          the player name at location i in the players array)
 *   playerName: Name of the player to update
 *   candyFound: Number of pieces of candy found by playerName
 *   numplayers: Number of players and candy counts in the respective arrays
 *
 */
void struckGold(string players[], int candy[], string playerName, int candyFound, int numplayers);

/** 
 * Add 2 to all player candy counts that are still in the game.
 *
 * Parameters:
 *   players: Array of player names
 *   candy: Array of candy counts (candy count at location i corresponds to
 *          the player name at location i in the players array)
 *   numplayers: Number of players and candy counts in the respective arrays
 *
 */
void rainingCandy(string players[], int candy[], int numplayers);

/** 
 * Cut in half all candy counts of players who are in even positions on the
 * leaderboard (0-indexed). Use integer division, since the big bully
 * is greedy and doesn't like "half" pieces of candy.
 *
 * Parameters:
 *   players: Array of player names
 *   candy: Array of candy counts (candy count at location i corresponds to
 *          the player name at location i in the players array)
 *   numplayers: Number of players and candy counts in the respective arrays
 *
 */
void theft(string players[], int candy[], int numplayers);

/** 
 * Gives one piece of candy from the top player to each other player in
 * reverse order.  Starting from the last player, Big Bully takes one 
 * piece of candy from the top player and gives it to the last place player,
 * then repeats for the second  to last player, continuing until the top 
 * player is out of candy or we've given one piece of candy to every other 
 * player (i.e. we've reached the 2nd place player).
 *
 * Parameters:
 *   players: Array of player names
 *   candy: Array of candy counts (candy count at location i corresponds to
 *          the player name at location i in the players array)
 *   numplayers: Number of players and candy counts in the respective arrays
 *
 */
void toughLuck(string players[], int candy[], int numplayers);


/** 
 * Returns the index of the specified player or -1 if it doesn't exist
 *
 * Parameters:
 *   players: Array of player names
 *   playerName: Name of the player to search for
 *   numplayers: Number of players in the players arrays
 * 
 * Returns: Index of given playerName or -1
 */
int findPlayer(string players[], string playerName, int numplayers);

/** 
 * Prints the main menu and returns the integer selection the user 
 * wants to perform.  If the user provides an invalid selection, 
 * simply return -1 which the calling function (e.g. main() can
 * use to detect the error.
 *
 * Returns: integer selection of the user or -1 if the selection
 *  was invalid
 */
int printPromptAndGetInput();


/**
 * Sort the player and candy array from highest candy count to lowest.  
 *
 * We recommend one of the simplest sorting algorithms:  Selection sort
 * Look at the class notes or online resources for how to implement this.
 *
 * Parameters
 *   players: Array of player names
 *   candy: Array of candy counts (candy count at location i corresponds to
 *          the player name at location i in the players array)
 *   numplayers: Total number of players
 */
void sortLeaderboard(string players[], int candy[], int numplayers);

/** 
 * Delete the given player and its corresponding candy count from the arrays
 * by moving all later players/candy counts up one spot, overwriting the
 * player to be deleted.  This function will be called by dropLosers()
 *
 * Parameters:
 *   players: Array of player names
 *   candy: Array of candy counts (candy counts at location i corresponds to
 *          the player name at location i in the players array)
 *   playerName: Name of the player to delete
 *   numplayers: Number of players and candy counts in the respective arrays
 *
 * Returns: false if the specified player does not exist, or true if
 *          the player was successfully deleted.
 */
bool deletePlayer(string players[], int candy[], string playerName, int numplayers);

/**
 * Delete all players from the game who do not have positive candy counts. 
 * 
 * Note that when a player is deleted, the index of other players may
 * shift, so special care must be taken.
 *
 * Parameters
 *   players: Array of player names
 *   candy: Array of candy counts (candy count at location i corresponds to
 *          the player name at location i in the players array)
 *   numplayers: Total number of players before deleting.
 *
 * Returns: the number of players remaining after deleting.
 */
int dropLosers(string players[], int candy[], int numplayers);

/**
 * Allows player names to be displayed with spaces, even
 * though the user enters them without spaces.
 * 
 * Breaks up a string at capital letters and inserts spaces 
 * So if the input is "MaryAnnSmith" return "Mary Ann Smith".
 * If the first letter is a capital, do not put a space before it.
 *
 * Parameters:
 *  in: string with no spaces
 *
 * Returns: a version of the string with spaces
 */
string breakStringAtCaps(string in);

/**********************************************************
 *  Write your implementations for each function prototyped
 *  above in the space below
 **********************************************************/

void printLeaderboard(string players[], int candy[], int numplayers)
{
  sortLeaderboard(players, candy, numplayers);
  cout << "LEADERBOARD:" << endl;
  for (int i = 0; i < numplayers; i++) {
    cout << breakStringAtCaps(players[i]) << " " << candy[i] << endl;
  }
  cout << endl;

}
void struckGold(string players[], int candy[], string playerName, int candyFound, int numplayers)
{
  if (findPlayer(players, playerName, numplayers) != -1 && candyFound > 0) {
    candy[findPlayer(players, playerName, numplayers)] += candyFound;
  }
  else if (findPlayer(players, playerName, numplayers) == -1) {
    cout << "Invalid player...ignoring" << endl;
  }
  else if (candyFound <= 0 ) {
    cout << "Bad candy count...ignoring" << endl;
  }
}

void rainingCandy(string players[], int candy[], int numplayers)
{
  for (int i = 0; i < numplayers; i++) {
    candy[i] += 2;
  }
}

void theft(string players[], int candy[], int numplayers)
{
  for (int i = 0; i < numplayers; i++) {
    if (i % 2 == 0) {
      candy[i] /= 2;
    }
  }
}

void toughLuck(string players[], int candy[], int numplayers)
{
  for (int i = 1; i < numplayers; i++) {
    if (candy[0] == 0) {
      break;
    }
    else {
      candy[numplayers-i]++;
      candy[0]--;
    }
  }
}

// done
int findPlayer(string players[], string playerName, int numplayers)
{
  for (int i = 0; i < numplayers; i++) {
    if (players[i] == playerName) {
      return i;
    }
  }
  return -1;
}
// done
int printPromptAndGetInput()
{
  cout << "What event will occur this round?" << endl;
  cout << "0. Quit" << endl; 
  cout << "1. Struck Gold: Player \"x\" finds \"y\" pieces of candy" << endl;
  cout << "2. Raining Candy: All players collect 2 pieces of candy" << endl;
  cout << "3. Theft: Big Bully steals half of the candy of all even-index players (minimum 1 piece)" << endl;
  cout << "4. Tough Luck: Big Bully gives one piece of candy from the top player to each other player in reverse order." << endl;
  int input = 0;
  cin >> input; 
  if (input >= 0 && input <= 4) {
    return input;
  }
  else {
    return -1;
  }
}
// done
void sortLeaderboard(string players[], int candy[], int numplayers)
{
  for (int i = 0; i < numplayers; i++) {
    for (int j = 0; j < numplayers; j++) {
      if (candy[j] < candy[i]) {
        int temp = candy[i];
        string temp2 = players[i];
        candy[i] = candy[j];
        players[i] = players[j];
        candy[j] = temp;
        players[j] = temp2;
      }
    }
  }
}
// done
string breakStringAtCaps(string in)
{
  string out = in.substr(0,1);
  for (int i = 1; i < in.length(); i++) {
    if (in[i] >= 65 && in[i] <= 90) {
      out += " ";
    }
    out += in[i];
  }
  return out;
}
// done
bool deletePlayer(string players[], int candy[], string playerName, int numplayers)
{
    for (int i = findPlayer(players, playerName, numplayers); i < numplayers; i++) {
      players[i] = players[i+1];
      candy[i] = candy[i+1];
    }
  
  return true;
}

int dropLosers(string players[], int candy[], int numplayers)
{

  int numLosers = 0;
  for (int i=0; i < numplayers; i++)
{
    if (candy[i] <= 0)
    {
      numLosers++;
    }
  }

  while(numLosers > 0)
  {
    for (int i=0; i < numplayers; i++)
    {
      if (candy[i] <= 0)
      {
        deletePlayer(players, candy, players[i], numplayers);
        numLosers--;
        numplayers--;
        break;
      }
    }
  }

  return numplayers;

}



/**********************************************************
 *  Main must be completed by you.
 **********************************************************/
int main()
{
  const int SIZE = 20;
  string players[SIZE];
  int candy[SIZE];
  int numplayers = 0;
  /* Add your code here */

  cout << "Enter total number of players: " << endl;
  cin >> numplayers;

  for (int i = 0; i < numplayers; i++) {
    cout << "Enter player " << i+1 << "\'s name and starting number of candies: " << endl;
    cin >> players[i] >> candy[i];
  }
  cout << "INITIAL ";
  printLeaderboard(players, candy, numplayers);
  int input = printPromptAndGetInput();
  while (input != 0) {
    
    string playerName = "";
    int candyFound = 0;

    if (input == 1) {
      cin >> playerName >> candyFound;
      struckGold(players, candy, playerName, candyFound, numplayers);
    }
    else if (input == 2) {
      rainingCandy(players, candy, numplayers);
    }
    else if (input == 3) {
      theft(players, candy, numplayers);
    }
    else if (input == 4) {
      toughLuck(players, candy, numplayers);
    }
    else {
      cout << "Bad event option" << endl;
    }

    numplayers = dropLosers(players, candy, numplayers);
    printLeaderboard(players, candy, numplayers);
    input = printPromptAndGetInput();
  }
  
  /* End your code here */

  cout << endl;
  cout << "FINAL ";
  printLeaderboard(players, candy, numplayers);

  return 0;
}
