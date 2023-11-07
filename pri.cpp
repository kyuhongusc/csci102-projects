#include <iostream>
using namespace std;

// Quit when all requests in a given round are false.
int main()
{
    bool requests[100] = {0}; // requests
    int priority[100];  // priority
    int n;
    bool running = true;
    cout << "Enter the number of requestors (1-100): " << endl;
    cin >> n;

    // causes the priority array to be numbered 0, 1, 2, 3...
    for (int i = 0; i < n; i++) {
      priority[i] = i;
    }

    while (running) {
      // prompts user for requesting values
      for (int i = 0; i < n; i++) {
        cin >> requests[i];
      }
      // determines which person from the priority array to give the resource to-
      // 
      for (int i = 0; i < n; i++) {
        if (requests[priority[i]] == 1) {
          cout << "Person " << priority[i] << " Selected" << endl;
          int a = priority[i];
          for (int j = i; j < n-1; j++) {
            priority[j] = priority[j+1];
          }
          priority[n-1] = a;
          break;
        }

      }

      // checks if requesting array is empty aka all = to 0
      bool empty = true;
      for (int i = 0; i < n; i++) {
        if (requests[i] == 1) {
          empty = false;
        }
      }

      if(empty == true) {
        running = false;
      }
   }
   return 0;
}