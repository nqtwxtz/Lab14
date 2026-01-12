#include <iostream>
using namespace std;

const int N = 5;

void inputMatrix(double [][N]);
void findLocalMax(double [][N], bool [][N]);
void showMatrix(bool [][N]);

int main(){
	double A[N][N]; 
	bool B[N][N]; 
	cout << "Input the matrix.....\n";
	inputMatrix(A);
	findLocalMax(A,B);
	cout << "Result is\n";
	showMatrix(B);
	return 0;
}


void inputMatrix(double mat[][N]) {
    for (int i = 0; i < N; i++) {
        cout << "Row " << i + 1 << ": ";
        for (int j = 0; j < N; j++) {
            cin >> mat[i][j];
        }
    }
}

void findLocalMax(double A[][N], bool B[][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (i == 0 || i == N - 1 || j == 0 || j == N - 1) {
                B[i][j] = false;
            } 
            else {
                if (A[i][j] >= A[i-1][j] &&
                    A[i][j] >= A[i+1][j] &&
                    A[i][j] >= A[i][j-1] &&
                    A[i][j] >= A[i][j+1]) {
                    B[i][j] = true;
                } else {
                    B[i][j] = false;
                }
            }
        }
    }
}

void showMatrix(bool B[][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << B[i][j] << " ";
        }
        cout << "\n";
    }
}