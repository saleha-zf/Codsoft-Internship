#include "todo.h"
//all our necessary header files are in todo.h

using namespace std;
int main() {
    int userChoice = 0;
    ToDo list;
    cout << "Welcome to CodSoft tasklist!" << endl;

    while (true) {
       
        cout << "\n\033[32m----- Main Menu -----" << endl;
        cout << "\033[36m1. Add New Task" << endl;    
        cout << "2. View Tasks" << endl;       
        cout << "3. Search Task" << endl;
        cout << "4. Delete Task" << endl;
        cout << "5. Mark Task as Completed" << endl;
        cout << "6. Exit\033[32m" << endl;  
        ToDo::typewriterEffect("Enter your choice: ");
        cin >> userChoice;

        switch (userChoice) {
            case 1:
                cout << "\033[2J\033[1;1H"; //clearing screen
                list.addTask();
                break;
            case 2:
                cout << "\033[2J\033[1;1H"; //clearing screen
                list.readTasksFile();
                break;
            case 3:
                cout << "\033[2J\033[1;1H"; //clearing screen
                list.searchUsertask();
                break;
            case 4:
                cout << "\033[2J\033[1;1H"; //clearing screen
                list.deleteTask();
                break;
            case 5:
                cout << "\033[2J\033[1;1H"; //clearing screen
                list.markTaskAsCompleted();
                break;
            case 6:
               cout << "\033[2J\033[1;1H";
                ToDo::typewriterEffect("Goodbye!");//type writer effect
                return 0;
            default:
              {
                cout << "\033[2J\033[1;1H";
                cout << "Invalid choice. Please try again." << endl;
                // error handling.
              }
        }
    }

    return 0;
}

