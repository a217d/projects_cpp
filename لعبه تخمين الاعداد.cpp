#include<iostream>
#include<string>
#include<cstdlib> // تحتوي ع داله rand()
#include <ctime>    // لتوليد أرقام مختلفة في كل مرة
#include <windows.h>// مكتبه الانتقالات 
using namespace std;
int main (){
	srand(time(0)); // لتوليد أرقام عشوائية مختلفة في كل تشغي
	 int r = 5, c = 5;
	int max[5][5] ={ {1,4,6,9,8}
	              ,{89,71,15,3,61},
	              {17,90,99,44,22},
	              {18,63,33,47,23},
	              {56,40,25,49,88}		  	  
	            };
	 int a; 
	  cout << "Enter the number " ;
	  cin >> a; 
	for (int x = 0; x < r; x++){
		for(int j = 0; j < c; j++){
			if (a == max[x][j]){
				a = rand() % 100 + 1;
				cout << a;
			}
			
		}
		 cout << endl;
	}
}