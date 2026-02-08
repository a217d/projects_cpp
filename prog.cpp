#include <iostream>
#include <string>
#include <windows.h>
using namespace std;

// تعديل: أضفت التحقق من صحة درجات الطلاب بحيث تكون بين 0 و 100، وإعادة إدخال الدرجة إذا لم تكن صحيحة.
void displayMenu() {
    cout << "Choose an option: " << endl;
    cout << "1. View Students\n";
    cout << "2. Knowing the number of successful students\n";
    cout << "3. Evaluate each student's grade:\n";
    cout << "4. Student grade assessment\n";
    cout << "5. Exit\n";
}

void assessment() {
    cout << "1. Knowing the number of excellent students" << endl;
    cout << "2. Knowing the number of very good students" << endl;
    cout << "3. Knowing the number of good students" << endl;
    cout << "4. Knowing the number of accepted students" << endl;
    cout << "5. Knowing the number of failing students" << endl;
}

int main() {
    string name[10];
    int mark[10];
    int choice;

    cout << "Enter data for 10 students:\n\n";

    for (int i = 0; i < 10; i++) {
        cout << "Write name of student " << i + 1 << ": ";
        cin >> name[i];

        // تعديل: التحقق من صحة الدرجة
        int m;
        while (true) {
            cout << "Enter grade of student " << i + 1 << " (0-100): ";
            cin >> m;
            if (cin.fail() || m < 0 || m > 100) {
                cout << "Invalid grade. Please enter a number between 0 and 100.\n";
                cin.clear();
                cin.ignore(10000, '\n');
            } else {
                mark[i] = m;
                break;
            }
        }

        cout << endl;
    }

    cout << "Processing the database...";
    Sleep(2000);
    system("cls");

    int pass = 0;

    for (int i = 0; i < 10; i++) {
        if (mark[i] >= 50)
            pass++;
    }

    int o = 0; // Excellent >=90
    int x = 0; // Very good >=80
    int z = 0; // Good >=70
    int t = 0; // Accepted >=60
    int q = 0; // Failed <60

    for (int i = 0; i < 10; i++) {
        if (mark[i] >= 90) {
            o++;
        } else if (mark[i] >= 80) {
            x++;
        } else if (mark[i] >= 70) {
            z++;
        } else if (mark[i] >= 60) {
            t++;
        } else {
            q++;
        }
    }

    displayMenu();
    do {
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "List of students:\n";
                for (int i = 0; i < 10; i++) {
                    cout << "Student " << i + 1 << ": " << name[i] << ", Grade: " << mark[i] << endl;
                }
                break;

            case 2:
                cout << "Number of successful students is: " << pass << endl;
                break;

            case 3:
                for (int c = 0; c < 10; c++) {
                    if (mark[c] >= 50) {
                        cout << "Student " << name[c] << " has passed with a grade of " << mark[c] << ".\n";
                    } else {
                        cout << "Student " << name[c] << " has failed with a grade of " << mark[c] << ".\n";
                    }
                }
                break;

            case 4: {
                int choic;
                assessment();
                cout << "Enter the option you want: ";
                cin >> choic;

                if (choic == 1) {
                    cout << "The number of excellent students is: " << o << endl;
                } else if (choic == 2) {
                    cout << "The number of very good students is: " << x << endl;
                } else if (choic == 3) {
                    cout << "The number of good students is: " << z << endl;
                } else if (choic == 4) {
                    cout << "The number of accepted students is: " << t << endl;
                } else if (choic == 5) {
                    cout << "The number of students who failed is: " << q << endl;
                } else {
                    cout << "The option is not in the list." << endl;
                }
                break;
            }

            case 5:
                cout << "Exiting the program...\n";
                break;

            default:
                cout << "Invalid choice. Please try again.\n";
        }

    } while (choice <= 4);

    return 0;
}
