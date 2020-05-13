/*
Game Hangman
Output = _________
Input (benar) = A
Output = ______A__
Input (salah) = B
Output = ______A__
*/

#include<iostream>
#include<time.h>
using namespace std;

int main(){
	srand(time(NULL));
	char a[10], tebak[10];
	bool benar = false;
	int i, j, k;

	for (i = 0; i < 10; i++) {
		a[i] = rand() % 26 + 65;
	}

	for (i = 0; i < 10; i++) {
		for (j = 0; j < 10; j++) {
			for (k = 0; k < 10; k++) {
				if (tebak[k] == a[j]) {
					cout << tebak[k] << " ";
					break;
				}
			}
			if (tebak[k] != a[j]) {
				cout << "_ ";
			}
		}

		cin >> tebak[i];
	}
}