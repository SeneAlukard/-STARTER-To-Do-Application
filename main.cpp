#include <iostream>
#include <vector>
#include <string>

class Task
{
    private:
        std::string task;
        int date,priority;
        bool status;
    public:
        Task(){task = ""; date = 0; priority = 0; status = false;}
        Task(std::string task, int date, int priority):task(task),priority(priority),date(date){status = false;}
        void printTask(){std::cout << "Task: " << task << " Date: " << date << " Priority: " << priority << " Status: " << (status ? "Completed" : "Not Completed") << "\n";}
        void setstatus(){status = true;}
        void editTask(std::string newtask){task = newtask;}
        void editDate(int newdate){date = newdate;}
        void editPriority(int newpriority){priority = newpriority;}
        bool getstatus(){return status;}
        std::string gettask(){return task;}
        int getdate(){return date;}
        int getpriority(){return priority;}
        ~Task(){}
};

class TaskManager
{
    private:
        std::vector<Task> tasks;

    public:
        TaskManager(){
            std::cout << "Task Manager Created\n";
        }
        void addTask(std::string task, int date, int priority){tasks.push_back(Task(task,date,priority));}
        void deleteTask(std::string task);
        void markTaskComplete(std::string task);
        void printTasks();
        void printAllTasks();
        ~TaskManager(){}
};


void TaskManager::markTaskComplete(std::string task)
{
    for(int i = 0; i < tasks.size(); i++)
        if(tasks[i].gettask() == task)
            tasks[i].setstatus();
}

void TaskManager::printTasks()
{
    for(int i = 0; i < tasks.size(); i++)
        tasks[i].printTask();
}

void TaskManager::deleteTask(std::string task){
    for(int i = 0; i < tasks.size(); i++)
        if(tasks[i].gettask() == task)
            tasks.erase(tasks.begin()+i);
}

void TaskManager::printAllTasks()
{
    for(int i = 0; i < tasks.size(); i++)
        tasks[i].printTask();
    std::cout << "\n";
}

void printMenu()
{
    std::cout << "Welcome to the Task Manager!\n"
           << "1. Add a new task\n"
           << "2. Delete a task\n"
           << "3. Mark a task as complete\n"
           << "4. Print all tasks\n"
           << "5. Exit\n";
}


int main()
{
    TaskManager controlUnit;
    int choice;
    std::string task;
    int date, priority;
    bool loop = true;
    while(loop){
        printMenu();
        std::cin >> choice;
        switch(choice){
            case 1:
                std::cout << "Enter the task: ";
                std::cin.ignore();
                std::getline(std::cin,task);
                std::cout << "Enter the due date (YYYYMMDD): ";
                std::cin >> date;
                std::cout << "Enter the priority (1-5): ";
                std::cin >> priority;
                controlUnit.addTask(task, date, priority);
                break;
            case 2:
                std::cout << "Enter the task you want to delete: ";
                std::cin.ignore();
                std::getline(std::cin,task);
                controlUnit.deleteTask(task);
                break;
            case 3:
                std::cout << "Enter the task you want to mark as complete:";
                std::cin.ignore();
                std::getline(std::cin,task);
                controlUnit.markTaskComplete(task);
                break;
            case 4:
                controlUnit.printAllTasks();
                break;
            case 5:
                loop = false;
                break;
        }
    }
    return 0;
}
