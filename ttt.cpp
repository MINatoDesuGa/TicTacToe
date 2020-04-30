//Tic Tac Toe Game by MINato

#include<iostream>

using namespace std;

void resetboard(int arr[3][3]) {							//resets board 
	for(int i=0;i<3;i++) {
		for(int j=0;j<3;j++) {
			arr[i][j] = 0;
		}
	}
}

void displayboard(int arr[3][3]) {						//Displays current board status
	cout << "\n";
	for(int i=0;i<3;i++) {
		for(int j=0;j<3;j++) {
			cout << arr[i][j] << " ";		
		}
		cout << "\n";
	}
}

int checkwinner(int arr[3][3] , int x , int y , int p) {						//Check for winner 
	if(x == y) {
		if(arr[0][0] == arr[1][1] && arr[1][1] == arr[2][2]) {
			if(arr[0][0] != 0) {
				return p;	
			}
		}		
		
		if(x == 1) {
			if(arr[0][2] == arr[1][1] && arr[1][1] == arr[2][0]) {
				if(arr[0][2] != 0) {
					return p;	
				}			
			}		
			if(arr[0][1] == arr[1][1] && arr[1][1] == arr[2][1]) {
				if(arr[0][1] != 0) {
					return p;	
				}	
			}
			if(arr[1][0] == arr[1][1] && arr[1][1] == arr[1][2]) {
				if(arr[1][2] != 0) {
					return p;	
				}
			} 
		}
		else if(x == 0) {
			if(arr[0][0] == arr[0][1] && arr[0][1] == arr[0][2]) {
				if(arr[0][2] != 0) {
					return p;	
				}	
			}			
			if(arr[0][0] == arr[1][0] && arr[1][0] == arr[2][0]) {
				if(arr[0][0] != 0) {
					return p;	
				}	
			}
		}
		else if(x == 2){
			if(arr[2][2] == arr[1][2] && arr[1][2] == arr[0][2]) {
				if(arr[0][2] != 0) {
					return p;	
				}	
			}	
			if(arr[2][2] == arr[2][1] && arr[2][1] == arr[2][0]) {
				if(arr[2][2] != 0) {
					return p;	
				}	
			}
		}
	}	
	else {
		if(x == 1) {
			if(arr[0][0] == arr[1][0] && arr[1][0] == arr[2][0]) {
				if(arr[0][0] != 0) {
					return p;	
				}			
			}
			if(arr[1][0] == arr[1][1] && arr[1][1] == arr[1][2]) {
				if(arr[1][2] != 0) {
					return p;	
				}	
			}
			if(arr[1][2] == arr[0][2] && arr[0][2] == arr[2][2]) {
				if(arr[0][2] != 0) {
					return p;	
				}	
			}
		}	
		
		if(y == 1) {
			if(arr[0][0] == arr[0][1] && arr[0][1] == arr[0][2]) {
				if(arr[0][2] != 0) {
					return p;	
				}	
			}
			if(arr[0][1] == arr[1][1] && arr[1][1] == arr[2][1]) {
				if(arr[0][1] != 0) {
					return p;	
				}
			}
			if(arr[2][0] == arr[2][1] && arr[2][1] == arr[2][2]) {
				if(arr[2][2] != 0) {
					return p;	
				}			
			}
		}
		
		if((x+y) == 2) {
			if(arr[2][0] == arr[1][1] && arr[2][0] == arr[0][2]) {
				if(arr[0][2] != 0) {
					return p;	
				}
			}	
			
			if(x == 2) {
				if(arr[2][0] == arr[1][0] && arr[2][0] == arr[0][0]) {
					if(arr[0][0] != 0) {
						return p;	
					}	
				}
				if(arr[2][0] == arr[2][1] && arr[2][0] == arr[2][2]) {
					if(arr[2][2] != 0) {
						return p;	
					}
				}
			}
			else {
				if(arr[0][0] == arr[0][1] && arr[0][0] == arr[0][2]) {
					if(arr[0][2] != 0) {
						return p;	
					}	
				}	
				if(arr[0][2] == arr[1][2] && arr[0][2] == arr[2][2]) {
					if(arr[2][2] != 0) {
						return p;	
					}
				}
			}
		}
	}
		
	return 3;
}

int player1move(int arr[3][3] , int r , int c) {	//Updates board based on Player 1 response 
	arr[r][c] = 1;	
	displayboard(arr);
	int player = 0;
	return checkwinner(arr , r , c , player);
}

int player2move(int arr[3][3] , int r , int c) {	//Updates board based on Player 2 response
	arr[r][c] = 2;	
	displayboard(arr);
	int player = 1;
	return checkwinner(arr , r ,c , player);
}

int main() {
	int a[3][3];
	resetboard(a);
	displayboard(a);
	int win;
	while(1) {
		cout << "\nPlayer 1 turn [0]\n";
		cout << "Enter index: ";
		int row , col;
		cin >> row >> col;
		win = player1move(a,row,col);
		
		//cout << win << endl;
		
		if(win != 3) {
			cout << "\n\tPlayer 1 Won\n";
			return 0;			
		}

		cout << "\nPlayer 2 turn [1]\n";
		cout << "Enter index: ";
		cin >> row >> col;
		win = player2move(a,row,col);		
		
		//cout << win << endl;

		if(win != 3) {
			cout << "\n\tPlayer 2 Won\n";
			return 0;	
		}
		
		
	}
	
	return 0;
}
