#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

void main() {
	srand(time(NULL));
	int acak, tebak;

	acak = rand() % 100 + 1; // DARI ANGKA 1 - 100

	for (int i = 4; i >= 0; i--) {
		cout << "Masukkan tebakan angka = ";
		cin >> tebak;

		if (i == 0 && tebak != acak) {
			cout << "Anda kalah";
			break;
		}

		if (tebak == acak) {
			cout << "Sukses!!! Tebakan benar";
			break;
		}

		else if (tebak > acak) {
			cout << "Angka terlalu besar, sisa nyawa = " << i;
		}
		else if (tebak < acak) {
			cout << "Angka terlalu kecil, sisa nyawa = " << i;
		}

		cout << endl << endl;
	}

	cout << endl;
}

