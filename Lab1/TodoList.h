#ifndef TODO_LIST_H
#define TODO_LIST_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "TodoListInterface.h"


using namespace std;

class TodoList: public TodoListInterface {
public:
	vector<string> tasks;
    TodoList() {
		cout << "In constructor"<< endl;

 		ifstream infile ("TODOList.txt");
		string line;
  		if (infile.is_open())
  		{
    		while ( getline (infile,line) )
    		{
      			cout << line << '\n';
				tasks.push_back(line);
    		}
   			 infile.close();
  		}

  		else {	cout << "Unable to open file";	} 
		}

    virtual ~TodoList() {
		cout << "In destructor"<< endl;

		ofstream outfile;
		outfile.open("TODOList.txt", ofstream::out | ofstream::trunc);

		for(int i=0; i< tasks.size(); i++) {
			//take this out
			cout << tasks.at(i)<< " ";
			outfile << tasks[i] << endl;
		}
		outfile.close();

	}

    /*
    *   Adds an item to the todo list with the data specified by the string "_duedate" and the task specified by "_task"
    */
    virtual void add(string _duedate, string _task) 
	{
		cout << "In add " << _duedate << " " << _task <<endl;
		tasks.push_back(_duedate+" "+_task);
	}
	

    /*
    *   Removes an item from the todo list with the specified task name
    *
    *   Returns 1 if it removes an item, 0 otherwise
    */
    virtual int remove(string _task) 
	{
		cout << "In remove" <<endl;
		cout << tasks.size() <<endl;
		string corner = "corner of mission";
		cout << corner.find("mission") << "\n\n\n";
		
		_task = ""+ _task;
		cout << _task;
		for(int i = 0; i < tasks.size(); ++i) {
			cout << tasks.at(i);
			if (tasks[i].find(_task) != string::npos) {
				tasks.erase(tasks.begin() + i);
				cout << "happy"<< "\n\n\n";
			}
		}
	}

    /*
    *   Prints out the full todo list to the console
    */
    virtual void printTodoList()
	{
		cout << "In list" << endl;
		for (int i=0; i< tasks.size(); i++) {
			cout << tasks.[i] << endl;
		}
	}
    
    /*
    *   Prints out all items of a todo list with a particular due date (specified by _duedate)
    */
    virtual void printDaysTasks(string _date) 
	{
		cout << "In daystracking" << endl;
		for (int i = 0; i < tasks.size(); i++) {
			if (tasks.at(i).find(string_date) != string::npos) {
				
				cout << string_date << ":\n" << tasks.at(i) << endl;
			}
		}
	}
};

#endif