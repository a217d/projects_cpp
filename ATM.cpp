#include<iostream>
#include<string>
#include<cstdlib>
#include <cstdlib> // لدوال عامة إذا احتجت
#include <windows.h>
using namespace std;
//*****varibal******
int Balance = 2000 ;
int Deposit = 0 ;
int withdraw = 0;
char password[5] = "1472";
char pass[6]; 
int Esc = 0;
float taxes = .02;
int choices;
bool dps;
bool with;
void show(){
    cout<< "*****munyou******" <<endl;
	cout<< "1# Balance" <<endl;
	cout<< "2# Deposit" <<endl;
	cout<< "3# withedraw" <<endl;
	cout<< "4# Esc" <<endl;
	cout << "*****the_end******" << endl;

}

void proccing(){
	  cout << "Welcome to the ATM" << endl ;
      cout << "System loading... " << endl;
      Sleep(3000); // انتظار 3 ثواني
      system("cls"); // مسح الشاشة

        int c =1;
      	cout << "enter your password ";
      	cin >> pass;
		   
    	
    	if(pass != password){
    		 Sleep(3000); // انتظار 3 ثواني
            system("cls"); // مسح الشاشة
		}
          while(strcmp (pass, password) != 0 && c < 3 ){
            
    	 	if (strcmp (pass, password) != 0){
    	 	cout << "enter your password agin.pleas ";
    	 	cin >> pass;
		    Sleep(3000); // انتظار 3 ثواني
            system("cls"); // مسح الشاشة
           
           }
	        c++;
	      
        }
         if(c >= 3){
         cout << "Faulty attempts";
         
        }
      	
	do{	
	    if (strcmp (pass, password) == 0){
	     show();
        cout << "Write your choices ";
    	cin >> choices;
    	system("cls");
    	
	    }
	   
	   
   	switch(choices){
   		    case 1:
   		    	cout << "The operation is in progress...";
   		    	Sleep(2000);
   		    	system("cls");
   		    	if (dps == true){
   		    		cout<< "your balance is "<< Balance -  Deposit * taxes << endl;
   		        }
   		         else if (with == true) {
   		    	    cout<< "your balance is "<< Balance - withdraw * .02 << endl;
   		        }
   		         else {
   		         	    cout<< "your balance is "<< Balance << endl;
					}
   			        break;
			
   			case 2:
   				dps = true;
   				cout<< "your balance is "<< Balance -  withdraw * taxes << endl;
   				cout<< "Enter the deposit amount" << endl;
   				cin >> Deposit;
   				
   				cout << "The operation is in progress..." << endl;
   		    	Sleep(2000);
   				cout << "taxes is " <<  Deposit * taxes << endl;
				Balance += Deposit ; 
   				cout<< "Your balance after deposit is " << Balance - Deposit * taxes  << endl;
   				int c;
   				cout << "Do you want to perform this operation?" << endl;
   				cout << "To continue, press the number1 .To cancel, press any other number.\n";
   				cin >> c;
   				
   				if (c == 1){
   				cout << "The operation is in progress..." << endl;
   		        Sleep(2000);
   		        cout << "The operation was successfully completed." << endl;
   		        Sleep (2500);
                system("cls");
                }
                else {
                	cout << "This operation has been cancelled." << endl;
                	Sleep (2500);
                    system("cls");
				}
				    break;
			
			case 3:
				with = true;
				cout << "your balance is " << Balance - Deposit * taxes << endl;
				cout << "enter the withdraw amount" << endl;
				cin >> withdraw;

				cout << "The operation is in progress..." << endl;
	   		    Sleep(2000);
				system("cls");
			if(withdraw < Balance){
				cout << "taxes is " << withdraw * taxes << endl;
				Balance -= withdraw;
				cout << "Your balance after withedraw is "<< Balance -  withdraw * taxes << endl;
			    int c;
   				cout << "Do you want to perform this operation?" << endl;
   				cout << "To continue, press the number1 .To cancel, press any other number.\n";
   				cin >> c;
   				if (c == 1){
   				cout << "The operation is in progress..." << endl;
   		        Sleep(2000);
   		        cout << "The operation was successfully completed." << endl;
   		        Sleep (2500);
                system("cls");
                }
                
                else {
                	cout << "This operation has been cancelled." << endl;
                	Sleep (2500);
                    system("cls");
				  }	
				}
				else if(withdraw == Balance){
					cout<< "sorry" << endl;
			    }
					
					else {
					cout << "Your balance is insufficient" << endl;
				}
				 break;
			    
		        case 4:
		        system("cls");
				cout<<"Exit the program"<<endl;
				cout << "Thank you, our dear customer. " << endl;
				break;
			    
			          
	   } 
	  

 }while (choices < 4);

 
 }
 

int main(){
	
	proccing();

	 
      return 0;
	}
	
   
