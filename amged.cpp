#include <iostream>
#include <windows.h>
#include <string>
using namespace std;
class Book{
    public:
        string name;
        string author;
        int Year_of_publication;
        int Book_number;
        int Price;
        

};

 void show(){
    cout << "1# اضافه کتاب" << endl;
    cout << "2# عرض كل الكتب " << endl;
    cout << "3# بحث عن كتاب" << endl;
    cout << "4# حذف كتاب" << endl;
    cout << "5# الخروج " << endl;
    cout << "6#اختر خيار اخر : " << endl;
 }

int main(){
    SetConsoleOutputCP(CP_UTF8); // دعم الحروف العربية في الإخراج
    SetConsoleCP(CP_UTF8);       // دعم الحروف العربية في الإدخال
    Book b[100];
    int n=0;
    int choice;
    do{
        show();
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "ادخل اسم الكتاب : ";
            cin >> b[n].name;
            cout << "ادخل اسم المؤلف : ";
            cin >> b[n].author;
            cout << "ادخل سنة النشر : ";
            cin >> b[n].Year_of_publication;
            cout << "ادخل رقم الكتاب : ";
            cin >> b[n].Book_number;
            cout << "ادخل سعر الكتاب : ";
            cin >> b[n].Price;
            n++;
            break;
        case 2:
            for(int i=0;i<n;i++){
                cout << "اسم الكتاب : " << b[i].name << endl;
                cout << "اسم المؤلف : " << b[i].author << endl;
                cout << "سنة النشر : " << b[i].Year_of_publication << endl;
                cout << "رقم الكتاب : " << b[i].Book_number << endl;
                cout << "سعر الكتاب : " << b[i].Price << endl;
                cout << "------------------------" << endl;
            }
            break;
        case 3:
            {
                string search_name;
                cout << "ادخل اسم الكتاب الذي تريد البحث عنه : ";
                cin >> search_name;
                bool found = false;
                for(int i=0;i<n;i++){
                    if(b[i].name == search_name){
                        cout << "اسم الكتاب : " << b[i].name << endl;
                        cout << "اسم المؤلف : " << b[i].author << endl;
                        cout << "سنة النشر : " << b[i].Year_of_publication << endl;
                        cout << "رقم الكتاب : " << b[i].Book_number << endl;
                        cout << "سعر الكتاب : " << b[i].Price << endl;
                        found = true;
                        break;
                    }
                }
                if(!found){
                    cout << "الكتاب غير موجود" << endl;
                }
            }
            break;
        
    
         } 
        }while(choice != 5);

        return 0;
    }printf("");
