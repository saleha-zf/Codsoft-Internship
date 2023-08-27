#include "todo.h"
//all our necessary header files.

using namespace std;
////////implementation//////
ToDo::ToDo()
{
    taskID= 0;
    userTask= " ";
}
// insert task functionality
void ToDo::addTask()
{
    char userChoice= ' ';
    cout<<"Enter a new task: ";
    cin.get();
    getline(cin, userTask);
    //cin.ignore();
    taskID++;
    // open file for writing task
    ofstream file_out;
    /*if(!file_out.is_open()) // file open failure check
    {
        cout<<"Uh Oh! Our technical side is down. Try again later."<<endl;
    }*/
    file_out.open("tasks.txt", ios::app);
    file_out<<endl<<taskID<<endl<<userTask;
    file_out.close(); // task saved successfully
    file_out.open("IDs.txt", ios::app);
    // open file for adding id
    /*if(!file_out.is_open()) // file open failure check
    {
        cout<<"Uh Oh! Our technical side is down. Try again later."<<endl;
    }*/
    file_out<<taskID;
    file_out.close(); // id saved successfully
    cout<<"Do you want to add another task?(y/n)"<<endl;
    //cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    cin>>userChoice;
    //cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    if(userChoice == 'y' || userChoice == 'Y') // input validation
    {
        addTask(); // calling add function to add more tasks
    }
    else if(userChoice == 'n' || userChoice == 'N')
    {
      typewriterEffect("Your task has been added successfully!");  
      cout<<endl;
    }
    return;
}
// read file
void ToDo::readTasksFile()
{
    // opening file to read data
    ifstream file_in;
    file_in.open("tasks.txt");
    if (!file_in.is_open()) // file open failure check
    {
        cout << "Uh Oh! Our technical side is down. Try again later." << endl;
        return;
    }
    
    cout << "Your tasks: " << endl;
    bool hasTasks = false; // flag to check if there are any tasks
    
    while (!file_in.eof()) // reading from file till end
    {
        file_in >> taskID;
        file_in.ignore();
        getline(file_in, userTask);     
        if (taskID != 0)
        {
            cout << endl << "ID: " << taskID << endl << "Task: " << userTask << endl;
            hasTasks = true;
        }
    }
    
    file_in.close(); // operation successful
    if (!hasTasks)
    {
        cout << "There are no tasks to view. Add one now!" << endl;
    }
}
// search for task
int ToDo::searchUsertask()
{
    bool taskRetrieved= false;
    int inputID= 0;
    cout<<"Enter task ID: ";
    cin>>inputID;
    ifstream file_in;
    file_in.open("tasks.txt");
    if(!file_in.is_open()) // file open failure check
    {
        cout<<"Uh Oh! Our technical side is down. Try again later."<<endl;
        return -1;
    }
    while(!file_in.eof()) // reading from file till end
    {
        file_in>>taskID;
        file_in.ignore();
        getline(file_in, userTask);
        if(taskID == inputID)
        {
            cout<<"ID: "<<taskID<<endl<<"Task: "<<userTask<<endl;
            taskRetrieved= true;
            break;
        }
    }
    file_in.close(); // operation successful
    return inputID;
}

 void ToDo::markTaskAsCompleted() {
        int taskToMark= searchUsertask(); 
        string line;
        string completedLine;

        ifstream fileIn("tasks.txt");
        ofstream fileOut("new.txt");

        if (!fileIn.is_open() || !fileOut.is_open()) {
            cout << "Uh Oh! Our technical side is down. Try again later." << endl;
            return;
        }

        while (getline(fileIn, line)) {
            if (line.empty()) {
                continue;
            }
            int taskID = stoi(line);
            getline(fileIn, line);
            if (taskID == taskToMark) {
                completedLine = "[COMPLETED] [" + line + "]";
                fileOut << taskID << endl;
                fileOut << completedLine << endl;
            } else {
                fileOut << taskID << endl;
                fileOut << line << endl;
            }
        }

        fileIn.close();
        fileOut.close();
        remove("tasks.txt");
        rename("new.txt", "tasks.txt");
        typewriterEffect("Task marked as completed successfully!");
        cout << endl;
    }

// deleting task
void ToDo::deleteTask()
{
    char userChoice= ' ';
    int task_toDelete= searchUsertask();
    cout<<"Press \'d\' for confirmation: ";
    cin>>userChoice;
    if(userChoice == 'd' || userChoice == 'D') // input validation
    {
        ofstream newFile; 
        newFile.open("new.txt");
        if(!newFile.is_open()) // file open failure check
        {
            cout<<"Uh Oh! Our technical side is down. Try again later."<<endl;
        }
        ifstream file_in;
        file_in.open("tasks.txt");
        if(!file_in.is_open()) // file open failure check
        {
            cout<<"Uh Oh! Our technical side is down. Try again later."<<endl;
        }
        while(!file_in.eof()) // reading till end of file
        {
            file_in>>taskID;
            file_in.ignore();
            getline(file_in, userTask);
            if(taskID != task_toDelete) 
            {
                newFile<<taskID<<endl;
                newFile<<userTask<<endl;
            }
        }
        file_in.close(); // operation successful
        newFile.close(); // operation successful
        remove("tasks.txt");
        rename("new.txt", "tasks.txt");
        typewriterEffect("Task deleted successfuly!");
        cout<<endl;
    }
    else 
    {
        cout<<"Failed to delete Task!"<<endl;;
    }
}


void ToDo:: typewriterEffect(const string& text) {
    for (char c : text) {
        cout << c << flush;
        this_thread::sleep_for(chrono::milliseconds(50)); // Adjust the delay as desired, setting 50 milli secs as default
    }
}
