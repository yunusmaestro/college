#include<iostream>
#include<math.h>
#include<time.h>

using namespace std;

void main() {

	int a[100][100];
	int d[100][100];
	int b, c, temp;
	int row1, col1, row2, col2;

	int n, jumlah = 0, num = 1;
	cout << "Input Board = ";
	cin >> n;

	srand(time(NULL));

	for (int i = 0; i < n; i++) {	// Mengisi angka dalam kotak 11 22 33 dst agar kartunya bisa pair
		for (int j = 0; j < n; j++) {
			a[i][j] = num;
			jumlah++;
			if (jumlah == 2) {
				num++;
				jumlah = 0;
			}
		}
	}
	for (int i = 0; i < n; i++) {	// Shuffle tempat / index
		for (int j = 0; j < n; j++) {
			b = rand() % n;
			c = rand() % n;
			temp = a[i][j];
			a[i][j] = a[b][c];
			a[b][c] = temp;
		}
	}
	for (int i = 0; i < n; i++) {	// Output pertama kali
		for (int j = 0; j < n; j++) {
			cout << "[" << " " << "]";
		}
		cout << endl;
	}
	cout << endl;

	// INISIALISASI Pertama
	int hitung = 1;
	int kotak = n * n / 2;
	bool input = true;

	while (hitung <= kotak) {

		// INPUT
		while (input == true) {		// Ketika belum ada input atau input adalah angka yang sudah benar
			cout << "Input Row1 : ";
			cin >> row1;
			cout << "Input Col1 : ";
			cin >> col1;
			cout << "Input Row2 : ";
			cin >> row2;
			cout << "Input Col2 : ";
			cin >> col2;
			cout << endl;

			// Mengecek input
			if (d[row1][col1] == -1 || d[row2][col2] == -1) {	// Ketika kotak yang telah terbuka masih diberi input
				cout << "Input Sudah Terbuka" << endl;
				input = true;
			}
			else {
				input = false;
			}
		}

		// OUTPUT
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {

				if (d[i][j] == -1) {	// Ketika angka sudah benar sebelumnya
					cout << "[" << a[i][j] << "]";
				}
				else {
					if (i == row1 && j == col1 || i == row2 && j == col2) {		// Ketika i dan j adalah input yang ditebak
						cout << "[" << a[i][j] << "]";
						if (a[row1][col1] == a[row2][col2]) {	// Ketika 2 angka sama
							d[row1][col1] = -1;
							d[row2][col2] = -1;
							hitung++;
						}
					}
					else {		// Ketika i dan j bukan input yang ditebak
						cout << "[" << " " << "]";
					}
				}

			}
			cout << endl;

		}
		cout << endl;
		if (hitung > kotak) {	// Ketika menang (semua angka terbuka)
			cout << "Selamat Anda Berhasil !!" << endl;
		}
		input = true;
	}

}