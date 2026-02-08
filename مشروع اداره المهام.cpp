#include <iostream>
#include <string>
using namespace std;
string taskTitle[100];
string taskDescription[100];
string taskDate[100];
int taskCount = 0;  // عدد المهام المدخلة

int main() {
    int choice;
    do {
        cout << "Menu:\n";
        cout << "1. Add Task\n";
        cout << "2. Show Tasks\n";
        cout << "3. Delete tasks\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            // إدخال مهمة جديدة
            cout << "Enter task title: ";
            cin.ignore(); // لتنظيف البوفر قبل getline
            getline(cin, taskTitle[taskCount]);

            cout << "Enter task description: ";
            getline(cin, taskDescription[taskCount]);

            cout << "Enter task date: ";
            getline(cin, taskDate[taskCount]);

            taskCount++; // زيادة عدد المهام

        }
		else if (choice == 2) {
            // عرض المهام
            if (taskCount == 0) {
                cout << "No tasks available.\n";
            } 
			
			else {
                for (int i = 0; i < taskCount; i++) {
                    cout << "Task " << i+1 << ":\n";
                    cout << "Title: " << taskTitle[i] << endl;
                    cout << "Description: " << taskDescription[i] << endl;
                    cout << "Date: " << taskDate[i] << endl;
                    cout << "-----------------\n";
                }
            }
        }
        
        else if(choice == 3){
                for (int r = 0; r -= taskCount; r--) {
                    cout << "Task " << r+1 << ":\n";
                    cout << "Title: " << taskTitle[r] << endl;
                    cout << "Description: " << taskDescription[r] << endl;
                    cout << "Date: " << taskDate[r] << endl;
                    cout << "-----------------\n";	
                 }
		}
		
		 else if (choice == 4) {
            cout << "Exiting...\n";
        }
		 else {
            cout << "Invalid choice. Try again.\n";
        }

    } while(choice != 3); // تكرار القائمة حتى اختيار الخروج

   
}
