#include <iostream>
#include <chrono>
#include <thread>
#include <fstream>
#include<limits>
// placing all our header files here

#ifndef TODO_H
#define TODO_H

// to do list class design
class ToDo
{
private:
    int taskID;
    std::string userTask;
public:
    
    ToDo(); // constructor
    void addTask(); // inserting new task
    void readTasksFile(); // view task details with proper prompts
    int searchUsertask(); // searching for a task
    void deleteTask(); // remove a task
    void markTaskAsCompleted(); // to mark a task as completed
    //static function to display the characters one-by-one like a type writer
    static void typewriterEffect(const std:: string& text);
};
#endif
