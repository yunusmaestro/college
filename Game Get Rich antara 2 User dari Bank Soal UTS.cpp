#include <iostream>
#include <time.h>
using namespace std;

void main(){
	srand(time(NULL));
	int n, a, b, hasila = 0, hasilb = 0, jumlaha = 0, jumlahb = 0;

	n = rand() % 3 + 1;

	for (int i = 1; i <= n; i++) {
		cout << "Pilihan A ronde " << i << " = ";
		cin >> a;
		cout << "Pilihan B ronde " << i << " = ";
		cin >> b;

		cout << endl;

		/*
		ANGKA 1 = POIN 189
		ANGKA 2 = POIN 367
		ANGKA 3 = POIN 565
		ANGKA 4 = POIN 743
		ANGKA 5 = POIN 921
		*/
		switch (a) {
		case (1) :
			hasila += 189;
			break;
		case (2) :
			hasila += 367;
			break;
		case (3) :
			hasila += 565;
			break;
		case (4) :
			hasila += 743;
			break;
		case (5) :
			hasila += 921;
			break;
		default:
			break;
		}

		switch (b) {
		case (1) :
			hasilb += 189;
			break;
		case (2) :
			hasilb += 367;
			break;
		case (3) :
			hasilb += 565;
			break;
		case (4) :
			hasilb += 743;
			break;
		case (5) :
			hasilb += 921;
			break;
		default:
			break;
		}
	}

	// JUMLAH DIGIT A DAN B
	// CONTOH (1294) = 1+2+9+4
	while (hasila) {
		jumlaha += hasila % 10;
		hasila /= 10;
	}
	while (hasilb) {
		jumlahb += hasilb % 10;
		hasilb /= 10;
	}

	if (jumlaha == jumlahb) {
		cout << "Seri";
	}
	else if (jumlaha > jumlahb) {
		cout << "Pemenangnya adalah A";
	}
	else if (jumlaha < jumlahb) {
		cout << "Pemenangnya adalah B";
	}
	cout << endl;
}