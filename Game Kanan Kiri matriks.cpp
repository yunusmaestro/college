#include <iostream>
#include <time.h>
#include <conio.h>	// kbhit
using namespace std;

int main() {
	srand(time(NULL));
	int a[100][100], baris, kolom, b[100][100];
	int i, j;
	char keyboard;

	cout << "Baris = ";
	cin >> baris;
	cout << "Kolom = ";
	cin >> kolom;
	cout << endl;

	for (i = 0; i < baris; i++) {
		for (j = 0; j < kolom; j++) {
			a[i][j] = rand() % 10;
			cout << a[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;

	while (true) {
		if (kbhit()) {
			system("cls");
			keyboard = getch();

			if (keyboard == 'w') {
				for (i = 0; i < baris; i++) {
					for (j = 0; j < kolom; j++) {
						if (i != baris - 1) {
							b[i][j] = a[i + 1][j];
						}
						else {
							b[i][j] = a[0][j];
						}
					}
				}
				for (i = 0; i < baris; i++) {
					for (j = 0; j < kolom; j++) {
						a[i][j] = b[i][j];
						cout << a[i][j] << " ";
					}
					cout << endl;
				}
			}
			else if (keyboard == 'a') {
				for (i = 0; i < baris; i++) {
					for (j = 0; j < kolom; j++) {
						if (j != kolom - 1) {
							b[i][j] = a[i][j + 1];
						}
						else {
							b[i][j] = a[i][0];
						}
					}
				}
				for (i = 0; i < baris; i++) {
					for (j = 0; j < kolom; j++) {
						a[i][j] = b[i][j];
						cout << a[i][j] << " ";
					}
					cout << endl;
				}
			}
			else if (keyboard == 'd') {
				for (i = 0; i < baris; i++) {
					for (j = 0; j < kolom; j++) {
						if (j != 0) {
							b[i][j] = a[i][j - 1];
						}
						else {
							b[i][j] = a[i][kolom - 1];
						}
					}
				}
				for (i = 0; i < baris; i++) {
					for (j = 0; j < kolom; j++) {
						a[i][j] = b[i][j];
						cout << a[i][j] << " ";
					}
					cout << endl;
				}
			}
			else if (keyboard == 's') {
				for (i = 0; i < baris; i++) {
					for (j = 0; j < kolom; j++) {
						if (i != 0) {
							b[i][j] = a[i - 1][j];
						}
						else {
							b[i][j] = a[baris - 1][j];
						}
					}
				}
				for (i = 0; i < baris; i++) {
					for (j = 0; j < kolom; j++) {
						a[i][j] = b[i][j];
						cout << a[i][j] << " ";
					}
					cout << endl;
				}
			}
		}
	}
}