#include <iostream>
#include <cstdlib>
#include <windows.h> // لأجل Sleep()
using namespace std;
  void 
   resetGame(char s[4][4], bool &turn, bool &player1, bool &player2,int &moves, int delay_ms){
    Sleep(2000);   
    system("cls"); 
	
	 // إعادة تهيئة اللوحة
    for(int i = 1; i <= 3; i++) {
        for(int j = 1; j <= 3; j++) {
            s[i][j] = ' ';
        }
    }

    // إعادة المتغيرات
    turn = true;
    player1 = false;
    player2 = false;
    moves = 0; 
}    

 int main (){
	 char s[4][4];
	 bool turn = true;
	 bool player1 = false;
     bool player2 = false;
     int moves = 0; 
        
		// استدعاء الدالة لإعادة اللعبة بعد الفوز أو عند البداية
	    resetGame(s, turn, player1, player2,moves,2000);
	
		while(true ){
	    int row, col;
	    char currentPlayer;
	    
	     if(turn) {
	        cout << "first player rol (X)" << endl;
	       currentPlayer = 'X';
	     } 
	     else if(!turn) {
	      cout << "secend player rol (O)" << endl;
	      currentPlayer = 'O';
	     }
	
	
	    cout << "Enter row: ";
	    cin >> row;
	    cout << "Enter column: ";
	    cin >> col;
	
	    if (s[row][col] == ' ') {
	        s[row][col] = currentPlayer;
	        turn = !turn; // تبديل الدور
	    } else {
	        cout << "This cell is already taken! Try again.\n";
	        continue;// المهمه تتخطى كل شي وتعود لبدايه الحلقه للطلب مالادخاله اخرى
	    }

	    // طباعة اللوح
	    for (int i = 1; i <= 3; i++) {
	        for (int j = 1; j <= 3; j++) {
	            cout << s[i][j] << " ";
	        }
	        cout << endl;
	    }
	  
	  
		for (int d = 1; d <= 3; d++){
		 	 if(s[d][1] == 'X')
		 	 if(s[d][2] == 'X')
		 	 if(s[d][3] == 'X')
		 	 if(!player1){
		   	 cout << "Player number 1 won  " << endl;
		   	 player1 = true;
			 resetGame(s, turn, player1, player2,moves,2000);
		   	 break;
		    }
		
		     else{
		 	 cout << "The row value is invalid, try again" << endl;
		 	 continue;
		 	 break;
		 }
	   
	 }
	 
		for (int r = 1; r <= 3; r++){
		    
		    if(s[1][r] == 'X' )
		    if(s[2][r] == 'X')
		    if(s[3][r] == 'X')
		    if(!player1){
		   	 cout << "Player number 1 won  " << endl;
		   	 player1 = true;  
		   	resetGame(s, turn, player1, player2,moves,2000);
			 break; 
		    }
		    
		    else{
		 	 cout << "The col value is invalid, try again" << endl;
		 	 continue;
		 	 break;
		 }
	    
      }
        
       for (int y = 1; y <= 3; y++){
       	
	 	 if(s[y][1] == 'O')
	 	 if(s[y][2] == 'O')
	 	 if(s[y][3] == 'O')
	 	 if(!player2){
	   	 cout << "Player number 2 won  " << endl;
	   	 player2 = true;
	   	 resetGame(s, turn, player1, player2,moves,2000);
		 break; 
	    } 
	   
	 }
	 
	 	for (int v = 1; v <= 3; v++){
	   
	    if(s[1][v] == 'O' )
	    if(s[2][v] == 'O')
	    if(s[3][v] == 'O')
	    if(!player2){
	   	 cout << "Player number 2 won " << endl;
	   	 player2 = true;
	   	 resetGame(s, turn, player1, player2,moves,2000);
		 break;   
	    }
	    
      }
    
     // فحص القطر الرئيسي
    if (s[1][1] == 'X' && s[2][2] == 'X' && s[3][3] == 'X' && !player1) {
        cout << "Player number 1 won" << endl;
        player1 = true;
       resetGame(s, turn, player1, player2,moves,2000);
     }
    if (s[1][1] == 'O' && s[2][2] == 'O' && s[3][3] == 'O' && !player2) {
        cout << "Player number 2 won" << endl;
        player2 = true;
        resetGame(s, turn, player1, player2,moves,2000);
    }

    // ✅ فحص القطر الآخر (الذي من اليمين لليسار)
    if (s[1][3] == 'X' && s[2][2] == 'X' && s[3][1] == 'X' && !player1) {
        cout << "Player number 1 won" << endl;
        player1 = true;
        resetGame(s, turn, player1, player2,moves,2000);
    }
    if (s[1][3] == 'O' && s[2][2] == 'O' && s[3][1] == 'O' && !player2) {
        cout << "Player number 2 won" << endl;
        player2 = true;
        resetGame(s, turn, player1, player2,moves,2000);
    }
      moves ++; 
     if (moves == 9 && !player1 && !player2) {
     cout << "It's a tie!" << endl;
     resetGame(s, turn, player1, player2,moves,2000);
      break;
      
    }
       	
  }
  
}