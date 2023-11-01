#include <iostream>
using namespace std;

int main()
{
  // Initializing variables
  bool key = false, lantern = false, enteredRoomZero = false, needLantern = false, enteredRoomThree = false, notDone = true;
  int roomNumber = 0;
  string userInput;
  while (notDone)
  {
    // Variable roomNumber is used to mark the location of the user, almost like a map
    if (roomNumber == 0)
    {
      if (enteredRoomZero != true)
      {
        cout << "You wake up in an unfamiliar hallway. It's barren, with the hallway extending to the north of you.\nWhich way do you go? (north)" << endl;  
        cin >> userInput;
      }
      else 
      {
        cout << "You are back in the area you started in.\nWhich way do you go? (north)" << endl;
        cin >> userInput;
      }
      enteredRoomZero = true;
    }
    else if (roomNumber == 1)
    {
      // If the user has already entered the room, prompt them to pick up the lantern.
      if (needLantern && lantern != true)
      {
        cout << "You arrive back at the lantern on the wall. Do you pick it up? (yes, no)" << endl;
        cin >> userInput;
        if (userInput == "yes" || userInput == "Yes")
        {
          lantern = true;
          cout << "You picked up the lantern." << endl;
          cout << "You can go north or south.\nWhich way do you go? (north, south)" << endl;
          cin >> userInput;
        }
        else if(userInput == "no" || userInput == "No")
        {
          cout << "You did not pick up the lantern." << endl;
          cout << "You can go north or south.\nWhich way do you go? (north, south)" << endl;
          cin >> userInput;
        }
      }
      // If the lantern has been picked up, remove the lantern string from the description of the room.
      else if (lantern == true)
      {
        cout << "The hallway extends further. You can keep going north or go south.\nWhich way do you go? (north, south)" << endl;
        cin >> userInput;
      }
      // If the user has not picked up the lantern nor visited the room that prompts the lantern, this is the prompt that will display.
      else
      {
        cout << "The hallway extends further. The only light source is a flickering lantern on the wall. You can keep going north or go south.\nWhich way do you go? (north, south)" << endl;
        cin >> userInput;
      }
    }
    else if (roomNumber == 2)
    {
      cout << "This hallway seems neverending. You can see a faint outline of a gate in the north distance, but you aren't sure.\nWhich way do you go? (north, south)" << endl;
      cin >> userInput;
    }
    else if (roomNumber == 3)
    {
      if (enteredRoomThree != true && key != true)
      {
        cout << "The gate appears closer. There's a hole in the wall to the right of you, but it's too dark to see anything inside. Maybe if you had a light source?\nWhich way do you go? (north, south)" << endl;
        // Allows the user to pick up the lantern
        needLantern = true;
        cin >> userInput;
      }
      else if (enteredRoomThree && lantern)
      {
        cout << "You can now use the lantern to look through the hole in the wall. There's a key inside!\nDo you pick it up? (yes, no)" << endl;
        cin >> userInput;
        if (userInput == "yes" || userInput == "Yes")
        {
          key = true;
          cout << "You picked up the key." << endl;
          cout << "You can go north or south.\nWhich way do you go? (north, south)" << endl;
          cin >> userInput;
        }
        else if(userInput == "no" || userInput == "No")
        {
          cout << "You did not pick up the key." << endl;
          cout << "You can go north or south.\nWhich way do you go? (north, south)" << endl;
          cin >> userInput;
        }
      }
      enteredRoomThree = true;
    }
    else if (roomNumber == 4)
    {
      cout << "There is a giant gate in front of you. You try opening it, but it's locked." << endl;
      // Checks if the user has the key
      if (key)
      {
        cout << "You have a key. Do you put it into the gate lock? (yes, no)" << endl;
        cin >> userInput;
        if (userInput == "yes" || userInput == "Yes")
        {
          cout << "You opened the gate. You're free!" << endl;
          return 0;
        }
        else if(userInput == "no" || userInput == "No")
        {
          cout << "You did not open the gate." << endl;
          cout << "You can go south.\nWhich way do you go? (south)" << endl;
          cin >> userInput;
        }
      }
      else
      {
        cout << "Which way do you go? (south)" << endl;
        cin >> userInput;
      }
    }
    // Tracks movement in the hallway
    if (userInput == "north" || userInput == "North")
    {
      // Checks if the room north is accessible or not
      if (roomNumber == 4)
      {
        cout << "You can't go that way.";
      }
      else
      {
        roomNumber++;
      }
    }
    else if (userInput == "south" || userInput == "South")
    {
      // Checks if the room south is accessible or not
      if (roomNumber == 0)
      {
        cout << "You can't go that way." << endl;
      }
      else
      {
        roomNumber--;
      }
    }
    // If the user inputs a string that is not legitimate
    else
    {
      cout << "I'm not sure what that means." << endl;
    }

  }
}
