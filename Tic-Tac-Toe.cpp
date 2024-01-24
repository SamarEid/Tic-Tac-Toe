#include <iostream>
using namespace std;
int main(){
	int n;
    cout << "Enter the number of rows and columns: ";
	cin >> n;
	char a[n][n] ;
    for (int i = 0; i <n ;i++){
            for (int j = 0; j < n; j++)
                a[i][j] = '.';
    }

	int m = 1; // players turn
    int steps = 0;
	while (true){
        if (steps == n*n){
            cout << "DRAWWW!!!!!!!!!!" << endl;
            return 0;
        }
        int r, c; // r--> row, c--> column
		if (m % 2 != 0){
			cout << "Player X turn. Enter empty location (row, col)" << endl;
			cin >> r >> c;
			if (r > n || c > n || r < 1 || c < 1 || a[r-1][c-1] != '.'){
				cout << "Invalid Input. Try again!!" << endl;
				continue;
			}
			a[r-1][c-1] = 'x';
			for (int i = 0; i <n ;i++){
				for (int j = 0; j < n; j++){
					cout << a[i][j];
				}
				cout << endl;
			}
		}
		else{
			cout << "Player O turn. Enter empty location (r, c)" << endl;
			cin >> r >> c;
			if (r > n || c > n || r < 1 || c < 1 || a[r-1][c-1] != '.'){
				cout << "Invalid Input. Try again!!" << endl;
				continue;
			}
			a[r-1][c-1] = 'o';
			for (int i = 0; i <n ;i++){
				for (int j = 0; j < n; j++){
					cout << a[i][j];
				}
				cout << endl;
			}
		}
        m++;
        steps++;
        // check the winner
        // if the win was a row
        for (int i = 0; i < n; i++){
            char first = a[i][0];
            if (first == '.')
                continue;
            int count = 1;
            for (int j = 1; j < n; j++){
                char pos = a[i][j];
                if (pos == first)
                    count++;
            }
            if (count == n){
                cout << "Player " << first << " WINS" << endl;
                return 0;
            }
        }
        // if the win was a column
        for (int i = 0; i < n; i++){
            char first = a[0][i];
            if (first == '.')
                continue;
            int count = 1;
            for (int j = 1; j < n; j++){
                if (a[j][i] == first)
                    count++;
            }
            if (count == n){
                cout << "Player " << first << " WINS" << endl;
                return 0;
            }
        }
        // win is left diagonal
        char firstLeft = a[0][0];
        if (firstLeft == '.')
            continue;
        else {
            int count = 1;
            for (int i = 1; i < n; i++) {
                if (a[i][i] == firstLeft)
                    count++;
            }
            if (count == n){
                cout << "Player " << firstLeft << " WINS" << endl;
                return 0;
            }
        }
        // win is right diagonal
        char firstRight = a[0][n-1];
        if (firstRight == '.')
            continue;
        else{
            int count = 1;
            int col = n-2;
            for (int i = 1; i < n; i++){
                if (a[i][col] == firstRight)
                    count++;
                col--;
            }
            if (count == n) {
                cout << "Player " << firstRight << " WINS" << endl;
                return 0;
            }
        }


	}
}
