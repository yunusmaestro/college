#include <iostream>
#include <Windows.h>
#include <conio.h>
#include<time.h>

using namespace std;

void gotoxy(int column, int line)
{
	COORD coord;
	coord.X = column;
	coord.Y = line;
	SetConsoleCursorPosition(
		GetStdHandle(STD_OUTPUT_HANDLE),
		coord
		);
}

int main(){
	bool state = true;
	int x = 2, y = 3, dx = 1, dy = 0, fx, fy;
	int lx = 0, ly = 1;
	int score = 0;
	srand(time(NULL));
	int width = 25, height = 24;
	fx = rand() % 23 + 1;
	fy = rand() % 21 + 2;

	while (state){
		// Hapus
		system("CLS");

		// Gambar
		gotoxy(0, 0);
		cout << "Score: " << score;



		// Buat Lapangan / Map
		for (int q = 0; q < width; q++){
			gotoxy(lx + q, ly);
			cout << "#";
			gotoxy(lx + q, height);
			cout << "#";
		}
		for (int q = 0; q < height; q++){
			gotoxy(lx, ly + q);
			cout << "#";
			gotoxy(width, ly + q);
			cout << "#";
		}
		gotoxy(x, y);
		cout << "*";
		gotoxy(fx, fy);
		cout << "@";

		// Update
		x += dx;
		y += dy;

		// Deteksi tabrakan
		if (x == 0 || x == width){
			//dx *= -1;
			state = false;
		}

		if (y == 1 || y == height){
			//dy *= -1;
			state = false;
		}
		//makanan
		if (x == fx && y == fy)
		{
			fx = rand() % 23 + 1;
			fy = rand() % 21 + 2;
			score += 10;
		}
		if (kbhit()) {
			char ch = getch();
			if (ch == 'w'){
				dx = 0;
				dy = -1;
			}
			if (ch == 'a'){
				dx = -1;
				dy = 0;
			}
			if (ch == 's'){
				dx = 0;
				dy = 1;
			}
			if (ch == 'd'){
				dx = 1;
				dy = 0;
			}
		}
		// Sleep
		Sleep(1000);
	}
	return 0;
}