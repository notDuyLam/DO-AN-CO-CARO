#include "View.h"

void resizeConsole(int width, int height)
{
	HWND console = GetConsoleWindow();
	RECT r;
	GetWindowRect(console, &r);
	MoveWindow(console, r.left, r.top, width, height, TRUE);
}

void FixConsoleWindow()
{
	HWND consoleWindow = GetConsoleWindow();
	LONG style = GetWindowLong(consoleWindow, GWL_STYLE);
	style = style & ~(WS_MAXIMIZEBOX) & ~(WS_THICKFRAME);
	SetWindowLong(consoleWindow, GWL_STYLE, style);
}
void GotoXY(int x, int y) 
{
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
void DrawBoard(int pSize) {
	DrawBoard_1(BOARD_SIZE, BOARD_SIZE);
	for (int i = 0; i <= pSize; i++) {
		for (int j = 0; j <= pSize; j++) {
			GotoXY(LEFT + 4 * i, TOP + 2 * j);
		}
	}
}
//void DrawBoard_1(int m, int n)
//{
//	int i, j;
//	SetColor(0);
//	printf("%c", 218);
//	for (i = 0; i < n - 1; i++)
//		printf("%c%c%c%c",196,196, 196, 194);
//	printf("%c%c%c",196, 196, 196);
//	printf("%c", 191);
//	printf("\n");
//	for (i = 0; i < m - 1; i++)
//	{
//		for (j = 0; j < n+ 1; j++)
//			printf("%c   ", 179);
//		printf("\n%c", 195);
//		for (j = 0; j < n - 1; j++)
//			printf("%c%c%c%c",196,196, 196, 197);
//		printf("%c%c%c",196,196, 196);
//		printf("%c\n", 180);
//	}
//	for (j = 0; j < n + 1; j++)
//		printf("%c   ", 179);
//	printf("\n%c", 192);
//	for (i = 0; i < n - 1; i++)
//		printf("%c%c%c%c",196,196, 196, 193);
//	printf("%c%c%c",196,196, 196);
//	printf("%c", 217);
//}
void DrawBoard_1(int m, int n)
{
	int i, j;
	SetColor(0);
	printf("%c", 201);
	for (i = 0; i < n - 1; i++)
		printf("%c%c%c%c", 205, 205, 205, 203);
	printf("%c%c%c", 205, 205, 205);
	printf("%c", 187);
	printf("\n");
	for (i = 0; i < m - 1; i++)
	{
		for (j = 0; j < n + 1; j++)
			printf("%c   ", 186);
		printf("\n%c", 204);
		for (j = 0; j < n - 1; j++)
			printf("%c%c%c%c", 205, 205, 205, 206);
		printf("%c%c%c", 205, 205, 205);
		printf("%c\n", 185);
	}
	for (j = 0; j < n + 1; j++)
		printf("%c   ", 186);
	printf("\n%c", 200);
	for (i = 0; i < n - 1; i++)
		printf("%c%c%c%c", 205, 205, 205, 202);
	printf("%c%c%c", 205, 205, 205);
	printf("%c", 188);
}

void XWin(_POINT _A[][BOARD_SIZE])
{
	ShowCur(0);
	GotoXY(72, 1);
	cout << "                                                                    ";
	GotoXY(72, 2);
	cout << "                                                                    ";
	GotoXY(72, 3);
	cout << "                                                                    ";
	GotoXY(72, 4);
	cout << " Y888b     d888P     8888         8888 88888888 888b      8888   ";
	GotoXY(72, 5);
	cout << "  Y888b   d888P      8888         8888   8888   8888b     8888   ";
	GotoXY(72, 6);
	cout << "   Y888b d888P       8888         8888   8888   88888b    8888   ";
	GotoXY(72, 7);
	cout << "    Y888o888P        8888    o    8888   8888   888888b   8888   ";
	GotoXY(72, 8);
	cout << "     Y88888P         8888   d8b   8888   8888   8888Y88b  8888   ";
	GotoXY(72, 9);
	cout << "     d88888b         8888  d888b  8888   8888   8888Y888b88888   ";
	GotoXY(72, 10);
	cout << "    d8888888b        8888 d8   8b 8888   8888   8888  Y888b888   ";
	GotoXY(72, 11);
	cout << "   d888P Y888b       88888d     b88888   8898   8888   Y888888   ";
	GotoXY(72, 12);
	cout << "  d888P   Y888b      8888P       Y8888   8888   8888    Y88888   ";
	GotoXY(72, 13);
	cout << " d888P     Y888b     888P         Y888 88888888 8888     Y8888    ";
	GotoXY(72, 14);
	cout << "                                                                  ";
	GotoXY(72, 15);
	cout << "                                                                    ";
	GotoXY(72, 16);
	cout << "                                                                    ";
	GotoXY(72, 17);
	cout << "                                                                    ";
}

void OWin(_POINT _A[][BOARD_SIZE])
{
	ShowCur(0);
	GotoXY(70, 1);
	cout << "                                                                    ";
	GotoXY(70, 2);
	cout << "                                                                    ";
	GotoXY(70, 3);
	cout << "                                                                    ";
	GotoXY(70, 4);
	cout << "    .d88888888b.        8888         8888 88888888 888b      8888  ";
	GotoXY(70, 5);
	cout << "   d888888888888b       8888         8888   8888   8888b     8888  ";
	GotoXY(70, 6);
	cout << "  d888P'    'Y888b      8888         8888   8888   88888b    8888  ";
	GotoXY(70, 7);
	cout << "  8888        8888      8888    o    8888   8888   888888b   8888  ";
	GotoXY(70, 8);
	cout << "  8888        8888      8888   d8b   8888   8888   8888Y88b  8888  ";
	GotoXY(70, 9);
	cout << "  8888        8888      8888  d888b  8888   8888   8888Y888b88888  ";
	GotoXY(70, 10);
	cout << "  8888        8888      8888 d8   8b 8888   8888   8888  Y888b888  ";
	GotoXY(70, 11);
	cout << "  Y888b.    .d886P      88888d     b88888   8898   8888   Y888888  ";
	GotoXY(70, 12);
	cout << "   Y888888888886P       8888P       Y8888   8888   8888    Y88888  ";
	GotoXY(70, 13);
	cout << "    'Y88888888P'        888P         Y888 88888888 8888     Y8888  ";
	GotoXY(70, 14);
	cout << "                                                                    ";
	GotoXY(70, 15);
	cout << "                                                                    ";
	GotoXY(70, 16);
	cout << "                                                                    ";
	GotoXY(70, 17);
	cout << "                                                                    ";
}

void Draw(_POINT _A[][BOARD_SIZE])
{
	ShowCur(0);
	GotoXY(70, 1);
	cout << "                                                                      ";
	GotoXY(70, 2);
	cout << "                                                                      ";
	GotoXY(70, 3);
	cout << "                                                                       ";
	GotoXY(70, 4);
	cout << "  88888888b.     88888888b.              d8888888  8888         8888";
	GotoXY(70, 5);
	cout << "  8888888888b.   88888888888b           d88888888  8888         8888";
	GotoXY(70, 6);
	cout << "  8888   'Y888b  8888    Y888b         d888P 8888  8888         8888";
	GotoXY(70, 7);
	cout << "  8888   'Y888b  8888    Y888b         d888P 8888  8888         8888";
	GotoXY(70, 8);
	cout << "  8888     8888  8888    d888P       d888P   8888  8888   d8b   8888";
	GotoXY(70, 9);
	cout << "  8888     8888  8888888888P'       d888P    8888  8888  d888b  8888";
	GotoXY(70, 10);
	cout << "  8888     8888  8888  T888b       d8888888888888  8888 d8   8b 8888";
	GotoXY(70, 11);
	cout << "  8888   .d888P  8888   T888b     d888P      8888  88888d     b88888";
	GotoXY(70, 12);
	cout << "  8888888888P'   8888    T888b   d888P       8888  8888P       Y8888";
	GotoXY(70, 13);
	cout << "  88888888P'     8888     T888b d888P        8888  888P         Y888";
	GotoXY(70, 14);
	cout << "                                                                   ";
	GotoXY(70, 15);
	cout << "                                                                    ";
	GotoXY(70, 16);
	cout << "                                                                    ";
	GotoXY(70, 17);
	cout << "                                                                    ";
}

void ThongBaoWin(int pWhoWin, _POINT _A[][BOARD_SIZE])
{
	if (pWhoWin == -1) //X win
	{
		for(int i=0;i<5;i++)
		{
			SetColor(252);
			XWin(_A);
			Sleep(150);
			SetColor(255);
			XWin(_A);
			Sleep(150);
		}
		SetColor(252);
		XWin(_A);
	}
	else if (pWhoWin == 1) //O win
	{
		for (int i = 0;i < 5;i++)
		{
			SetColor(252);
			OWin(_A);
			Sleep(150);
			SetColor(255);
			OWin(_A);
			Sleep(150);
		}
		SetColor(252);
		OWin(_A);
	}
	else if (pWhoWin == 0)
	{
		for (int i = 0;i < 5;i++)
		{
			SetColor(252);
			Draw(_A);
			Sleep(150);
			SetColor(255);
			Draw(_A);
			Sleep(150);
		}
		SetColor(252);
		Draw(_A);
	}
	SetColor(240);
}



//  88888888b.     88888888b.              d8888888  8888         8888
//  8888888888b.   88888888888b           d88888888  8888         8888
//  8888   'Y888b  8888    Y888b         d888P 8888  8888         8888
//  8888   'Y888b  8888    Y888b         d888P 8888  8888         8888
//  8888     8888  8888    d888P       d888P   8888  8888   d8b   8888
//  8888     8888  8888888888P'       d888P    8888  8888  d888b  8888
//  8888     8888  8888  T888b       d8888888888888  8888 d8   8b 8888
//  8888   .d888P  8888   T888b     d888P      8888  88888d     b88888
//  8888888888P"   8888    T888b   d888P       8888  8888P       Y8888
//  88888888P"     8888     T888b d888P        8888  888P         Y888

void NhapNhayQuanCo(_POINT _A[BOARD_SIZE][BOARD_SIZE], const short int toadothang[24], int pWhoWin)
{
	short int x, y;
	ShowCur(0);

	for (unsigned short int j = 1; j < 11; ++j)
	{
		SetColor(2 + rand() % 14);
		for (int i = 0; i < 10; i += 2)
		{
			x = toadothang[i];
			y = toadothang[i + 1];

			int x2, y2;
			x2 = 4 * y + 2;
			y2 = 2 * x + 1;
			GotoXY(x2, y2);

			if (pWhoWin == -1)
			{
				cout << " ";
				Sleep(40);

				GotoXY(x2, y2);
				cout << "X";
				cout << " ";
			}
			else if (pWhoWin == 1)
			{
				cout << " ";
				Sleep(40);
				GotoXY(x2, y2);
				cout << "O";
				cout << " ";
			}
		}
	}
	Sleep(300);
	ShowCur(0);
	for (unsigned short int i = 0; i < 10; i += 2)
	{
		x = toadothang[i];
		y = toadothang[i + 1];

		int x2, y2;
		x2 = 4 * y + 2;
		y2 = 2 * x + 1;
		GotoXY(x2, y2);

		if (pWhoWin == -1)
		{
			TextColor(228);
			cout << " ";
			Sleep(40);

			GotoXY(x2, y2);
			cout << "X";
			cout << " ";
		}
		else if (pWhoWin == 1)
		{
			TextColor(228);
			cout << " ";
			Sleep(40);

			GotoXY(x2, y2);
			cout << "O";
			cout << " ";
		}

	}
	TextColor(240);
	Sleep(500);
	ShowCur(1);
}


void TextColor(int color)
{
	HANDLE hConsole;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, color);
}
void SetColor(WORD color)
{
	HANDLE hConsoleOutput;
	hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO screen_buffer_info;
	GetConsoleScreenBufferInfo(hConsoleOutput, &screen_buffer_info);
	WORD wAttributes = screen_buffer_info.wAttributes;
	color &= 0x000f;
	wAttributes &= 0xfff0;
	wAttributes |= color;
	SetConsoleTextAttribute(hConsoleOutput, wAttributes);
}

void ShowCur(bool CursorVisibility)
{
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO cursor = { 1, CursorVisibility };
	SetConsoleCursorInfo(handle, &cursor);
}
void ShowTurn(_POINT _A[][BOARD_SIZE], _PLAYER _PLAYER1, _PLAYER _PLAYER2, bool _TURN)
{
	int start = _A[0][BOARD_SIZE - 1].x + 12;

	//DrawBox(255, 30, 10, start, 2);
	if ((_TURN) == 1)
	{
		SetColor(1);
		GotoXY(start+1, 15);
		cout << "X's moves:  " << CountX(_A);
		SetColor(247);
		GotoXY(start+46-3, 15);
		cout << "O's moves:  " << CountO(_A);
		DrawBigText("X.txt", 1, start, 2);
		DrawBigText("O.txt", 247, start + 40, 2);
		//Them ten
		PrintText("PLAYER X: " + _PLAYER1.name, 1, start, 1);
		PrintText("PLAYER O: "+ _PLAYER2.name, 247, start + 42, 1);
		
	}
	else if ((_TURN) == 0)
	{
		SetColor(247);
		GotoXY(start+1, 15);
		cout << "X's moves:  " << CountX(_A);
		SetColor(2);
		GotoXY(start + 46-3, 15);
		cout << "O's moves:  " << CountO(_A);
		DrawBigText("O.txt", 2, start + 40, 2);
		DrawBigText("X.txt", 247, start, 2);
		//Them ten
		PrintText("PLAYER X: " + _PLAYER1.name, 247, start, 1);
		PrintText("PLAYER O: " + _PLAYER2.name, 2, start +42, 1);
	}
	//DrawBigText((_TURN) ? "X.txt" : "O.txt", (_TURN) ? 1 : 2, start, 2);
	//DrawBox(255, 20, 1, start - 2, 14);
	//PrintText(((_TURN) ? _PLAYER1.name : _PLAYER2.name) + "'s turn!", (_TURN) ? 252 : 250, start - 2, 14);
}
void PrintText(string text, int color, int x, int y)
{
	GotoXY(x, y);
	SetColor(color);
	cout << text;
	SetColor(240);
}
void DrawLoaded(_POINT _A[][BOARD_SIZE])
{
	for (int i = 0; i < BOARD_SIZE; i++)
	{
		for (int j = 0; j < BOARD_SIZE; j++)
			if (_A[i][j].c == P_X)
			{
				PrintText("X", 1, _A[i][j].x, _A[i][j].y);
			}
			else if (_A[i][j].c == P_O)
			{
				PrintText("O", 2, _A[i][j].x, _A[i][j].y);
			}
	}
}

void HELP()
{
	GotoXY(80, 11);
	cout << "   ";
	GotoXY(80, 12);
	cout << "   ";
	GotoXY(80, 13);
	cout << "   ";
	GotoXY(80, 14);
	cout << "   ";
	GotoXY(80, 15);
	cout << "   ";
	GotoXY(80, 16);
	cout << "   ";
	GotoXY(80, 17);
	cout << "   ";
	GotoXY(80, 18);
	cout << "   ";
	GotoXY(80, 19);
	cout << "   ";
	SetColor(252); //Day la mot mau ngau nhien, can chinh lai mau khac dep hon
	GotoXY(10, 15);
	cout << "	";
	GotoXY(10, 16);
	cout << "1. You have 16x16 square board";
	GotoXY(10, 17);
	cout << "2. Choose which player will be X and which player will be O.";
	GotoXY(10, 18);
	cout << "3. Players take turns to move by using W A S D or arrow keys,";
	GotoXY(10, 19);
	cout << "and Enter or Space to place X or O on an empty square.";
	GotoXY(10, 20);
	cout << "4. The game continues until one player aligns 5 of their";
	GotoXY(10, 21);
	cout << "pieces in any direction, or 80% of the board is filled.";
	GotoXY(10, 22);
	cout << "The first player to align 5 of their pieces wins the ";
	GotoXY(10, 23);
	cout << "game, or if 80% of the board is filled, the game is declared a draw.";
	PrintText("Press ESC to return to MENU...", 8, 30, 28); ShowCur(0);
	char command = ' ';
	command = _getch();
}
void About()
{
	GotoXY(80, 11);
	cout << "   ";
	GotoXY(80, 12);
	cout << "   ";
	GotoXY(80, 13);
	cout << "   ";
	GotoXY(80, 14);
	cout << "   ";
	GotoXY(80, 15);
	cout << "   ";
	GotoXY(80, 16);
	cout << "   ";
	GotoXY(80, 17);
	cout << "   ";
	GotoXY(80, 18);
	cout << "   ";
	GotoXY(80, 19);
	cout << "   ";
	SetColor(252);
	GotoXY(23, 15);
	cout << "GAME PROJECT - CARO - 22CTT4 - HCMUS" << endl;
	GotoXY(23, 17);
	cout << "NGUYEN DUY LAM     " << "| 22120181 " << "| 22CTT4"<< endl;
	GotoXY(23, 18);
	cout << "DOAN THI MINH ANH  " << "| 22120213 " << "| 22CTT4"<< endl;
	GotoXY(23, 19);
	cout << "NGUYEN THI TU NGOC " << "| 22120233 " << "| 22CTT4"<< endl;
	GotoXY(23, 20);
	cout << "TANG SENH MANH     " << "| 22120202 " << "| 22CTT4"<< endl;
	GotoXY(23, 22);
	cout << "__INSTRUCTOR: Truong Toan Thinh__" << endl;
	PrintText("Press ESC to return to MENU...", 8, 30, 28);
	char command = ' ';
	command = _getch();
}

void Sound(bool& SoundEffects, int& song, int& songtemp)
{
	system("cls");
	drawFrame(5, 3, 80, 28);
	SetColor(0);
	printCaro(27,7);
	GotoXY(10, 10);
	drawFrame(0, 0, 145, 33);
	// Các dòng trên để vẽ lại các khung và chữ Caro do đã xóa hết màn hình
	SetColor(100);
	int x = 0, y = 0;
	int i;
	bool backToOriginalMenu = false; // Hàm này khi thành true thì sẽ kết thúc hàm và trở về menu chính
	while (!backToOriginalMenu)
	{
		backToOriginalMenu = false;
		x = 50, y = 20;
		SetColor(4);
		if (song != -1) drawSelectedButton(100, 8, "Music:  ON"); else drawSelectedButton(100, 8, "Music: OFF");
		SetColor(0);
		drawButton(100, 11, "Change song");
		if (SoundEffects) drawButton(100, 14, "Sound effects:  ON"); else drawButton(100, 14, "Sound effects: OFF");
		drawButton(100, 17, "Back");
		GotoXY(100, 25); 
		if (song % 4 == 0)
			cout << "Song: Wallpaper";
		else if (song % 4 == 1)
			cout << "Song: Sport Racing Car | DRIVE";
		else if (song % 4 == 2)
			cout << "Song: Sneaky Snitch";
		else if (song % 4 == 3)
			cout << "Song: Aggressive Computer Gaming | ENIGMA"; 
		SetColor(8);
		GotoXY(98, 29); cout << "_____ W A S D: MOVE _____";
		GotoXY(98, 30); cout << "_____ Enter: Select _____"; ShowCur(0);
		while (true)
		{
			if (_kbhit())
			{
				switch (_getch())
				{
				case 'w':
				case KEY_ARROW_UP:
					if (y > 20)
					{
						y--;
						GotoXY(x, y);
					}
					if (y == 20)
					{
						SetColor(4);
						if (song != -1) drawSelectedButton(100, 8, "Music:  ON"); else drawSelectedButton(100, 8, "Music: OFF");
						SetColor(0);
						drawButton(100, 11, "Change song");
						if (SoundEffects) drawButton(100, 14, "Sound effects:  ON"); else drawButton(100, 14, "Sound effects: OFF");
						drawButton(100, 17, "Back"); GotoXY(100, 25); cout << "                                         "; GotoXY(100, 25); if (song % 4 == 0) cout << "Song: Wallpaper"; else if (song % 4 == 1) cout << "Song: Sport Racing Car | DRIVE"; else if (song % 4 == 2) cout << "Song: Sneaky Snitch"; else if (song % 4 == 3) cout << "Song: Aggressive Computer Gaming | ENIGMA"; ShowCur(0);
					}
					if (y == 21)
					{
						SetColor(0);
						if (song != -1) drawButton(100, 8, "Music:  ON"); else drawButton(100, 8, "Music: OFF");
						SetColor(4);
						drawSelectedButton(100, 11, "Change song");
						SetColor(0);
						if (SoundEffects) drawButton(100, 14, "Sound effects:  ON"); else drawButton(100, 14, "Sound effects: OFF");
						drawButton(100, 17, "Back"); GotoXY(100, 25); cout << "                                         "; GotoXY(100, 25); if (song % 4 == 0) cout << "Song: Wallpaper"; else if (song % 4 == 1) cout << "Song: Sport Racing Car | DRIVE"; else if (song % 4 == 2) cout << "Song: Sneaky Snitch"; else if (song % 4 == 3) cout << "Song: Aggressive Computer Gaming | ENIGMA"; ShowCur(0);
					}
					if (y == 22)
					{
						SetColor(0);
						if (song != -1) drawButton(100, 8, "Music:  ON"); else drawButton(100, 8, "Music: OFF");
						drawButton(100, 11, "Change song");
						SetColor(4);
						if (SoundEffects) drawSelectedButton(100, 14, "Sound effects:  ON"); else drawSelectedButton(100, 14, "Sound effects: OFF");
						SetColor(0);
						drawButton(100, 17, "Back"); GotoXY(100, 25); cout << "                                         "; GotoXY(100, 25); if (song % 4 == 0) cout << "Song: Wallpaper"; else if (song % 4 == 1) cout << "Song: Sport Racing Car | DRIVE"; else if (song % 4 == 2) cout << "Song: Sneaky Snitch"; else if (song % 4 == 3) cout << "Song: Aggressive Computer Gaming | ENIGMA"; ShowCur(0);
					}
					if (y == 23)
					{
						if (song != -1) drawButton(100, 8, "Music:  ON"); else drawButton(100, 8, "Music: OFF");
						SetColor(4);
						drawButton(100, 11, "Change song");
						if (SoundEffects) drawButton(100, 14, "Sound effects:  ON"); else drawButton(100, 14, "Sound effects: OFF");
						SetColor(0);
						drawSelectedButton(100, 17, "Back"); GotoXY(100, 25); SetColor(0); cout << "                                         "; GotoXY(100, 25); if (song % 4 == 0) cout << "Song: Wallpaper"; else if (song % 4 == 1) cout << "Song: Sport Racing Car | DRIVE"; else if (song % 4 == 2) cout << "Song: Sneaky Snitch"; else if (song % 4 == 3) cout << "Song: Aggressive Computer Gaming | ENIGMA"; ShowCur(0);
					}
					break;
				case 's':
				case KEY_ARROW_DOWN:
					if (y < 23)
					{
						y++;
						GotoXY(x, y);
					}
					if (y == 20)
					{
						SetColor(4);
						if (song != -1) drawSelectedButton(100, 8, "Music:  ON"); else drawSelectedButton(100, 8, "Music: OFF");
						SetColor(0);
						drawButton(100, 11, "Change song");
						if (SoundEffects) drawButton(100, 14, "Sound effects:  ON"); else drawButton(100, 14, "Sound effects: OFF");
						drawButton(100, 17, "Back"); GotoXY(100, 25); cout << "                                         "; GotoXY(100, 25); if (song % 4 == 0) cout << "Song: Wallpaper"; else if (song % 4 == 1) cout << "Song: Sport Racing Car | DRIVE"; else if (song % 4 == 2) cout << "Song: Sneaky Snitch"; else if (song % 4 == 3) cout << "Song: Aggressive Computer Gaming | ENIGMA"; ShowCur(0);
					}
					if (y == 21)
					{
						SetColor(0);
						if (song != -1) drawButton(100, 8, "Music:  ON"); else drawButton(100, 8, "Music: OFF");
						SetColor(4);
						drawSelectedButton(100, 11, "Change song");
						SetColor(0);
						if (SoundEffects) drawButton(100, 14, "Sound effects:  ON"); else drawButton(100, 14, "Sound effects: OFF");
						drawButton(100, 17, "Back"); GotoXY(100, 25); cout << "                                         "; GotoXY(100, 25); if (song % 4 == 0) cout << "Song: Wallpaper"; else if (song % 4 == 1) cout << "Song: Sport Racing Car | DRIVE"; else if (song % 4 == 2) cout << "Song: Sneaky Snitch"; else if (song % 4 == 3) cout << "Song: Aggressive Computer Gaming | ENIGMA"; ShowCur(0);
					}
					if (y == 22)
					{
						SetColor(0);
						if (song != -1) drawButton(100, 8, "Music:  ON"); else drawButton(100, 8, "Music: OFF");
						
						drawButton(100, 11, "Change song");
						SetColor(4);
						if (SoundEffects) drawSelectedButton(100, 14, "Sound effects:  ON"); else drawSelectedButton(100, 14, "Sound effects: OFF");
						SetColor(0);
						drawButton(100, 17, "Back"); GotoXY(100, 25); cout << "                                         "; GotoXY(100, 25); if (song % 4 == 0) cout << "Song: Wallpaper"; else if (song % 4 == 1) cout << "Song: Sport Racing Car | DRIVE"; else if (song % 4 == 2) cout << "Song: Sneaky Snitch"; else if (song % 4 == 3) cout << "Song: Aggressive Computer Gaming | ENIGMA"; ShowCur(0);
					}
					if (y == 23)
					{
						SetColor(0);
						if (song != -1) drawButton(100, 8, "Music:  ON"); else drawButton(100, 8, "Music: OFF");
						drawButton(100, 11, "Change song");
						if (SoundEffects) drawButton(100, 14, "Sound effects:  ON"); else drawButton(100, 14, "Sound effects: OFF");
						SetColor(4);
						drawSelectedButton(100, 17, "Back"); GotoXY(100, 25); SetColor(0); cout << "                                         "; GotoXY(100, 25); if (song % 4 == 0) cout << "Song: Wallpaper"; else if (song % 4 == 1) cout << "Song: Sport Racing Car | DRIVE"; else if (song % 4 == 2) cout << "Song: Sneaky Snitch"; else if (song % 4 == 3) cout << "Song: Aggressive Computer Gaming | ENIGMA"; ShowCur(0);
					}
					break;
				case 13:
					if (y == 20) // Tắt bật nhạc nền
					{
						if (song != -1)
						{
							songtemp = song;
							song = -1;
							StopMusic();
							// Nếu như nhạc đang bật tức là biến song khác -1 thì sẽ lưu giá trị biến song vào songtemp và chuyển song thành -1 và tắt nhạc
							// chuyển song thành -1 là để khi gọi hàm PlayBackGroundMusic thì nhạc sẽ không bật
						}
						else
						{
							song = songtemp;
							PlayBackGroundMusic(song);
						}
						SetColor(4);
						if (song != -1) drawSelectedButton(100, 8, "Music:  ON"); else drawSelectedButton(100, 8, "Music: OFF");
						SetColor(0);
						// Biến songtemp có tác dụng để ghi nhớ bài hát trước đó của người dùng là gì sau khi đã tắt nhạc. Sau khi bật nhạc lại thì 
						// bài nhạc người dùng đang nghe vẫn sẽ được phát tiếp do trước đó đã có lưu trong biến songtemp
						// nếu không có songtemp thì sau khi bật nhạc lại người dùng sẽ luôn nghe bài đầu tiên
					}
					if (y == 21) // Đổi bài
					{
						song++;
						PlayBackGroundMusic(song);
						drawButton(100, 17, "Back"); GotoXY(100, 25); cout << "                                         "; GotoXY(100, 25); if (song % 4 == 0) cout << "Song: Wallpaper"; else if (song % 4 == 1) cout << "Song: Sport Racing Car | DRIVE"; else if (song % 4 == 2) cout << "Song: Sneaky Snitch"; else if (song % 4 == 3) cout << "Song: Aggressive Computer Gaming | ENIGMA"; ShowCur(0);
						// Tăng giá trị của biến song lên 1, sau đó in lại tên bài hát xuống dưới để người dùng biết là đã đổi bài
					}
					if (y == 22) // Tắt bật hiệu ứng âm thanh
					{
						if (SoundEffects)
							SoundEffects = false;
						else
							SoundEffects = true;
						SetColor(4);
						if (SoundEffects) drawSelectedButton(100, 14, "Sound effects:  ON"); else drawSelectedButton(100, 14, "Sound effects: OFF");
						SetColor(0);
						// Nếu như biến SoundEffects là false thì sẽ chuyển thành true và ngược lại, sau đó in ra nút ấn để thay đổi hiệ ứng cho người dùng biết là đã bật/tắt thành công
					}
					if (y == 23) // Chuyển biến đó thành true để thoát khỏi vòng lặp while và quay về menu gốc
					{
						backToOriginalMenu = true;
					}
					break;
				}
				if (backToOriginalMenu)
				{
					system("cls");
					break;
				}
			}
		}
	}
}

void SoundInGame(bool& SoundEffects, int& song, int& songtemp)
{
	// Mọi thứ trong hàm này hầu như tương tự hàm sound chỉ khác là nhạc nền dù bật tắt cũng sẽ không bật trong khi chơi game 
	SetColor(0);
	GotoXY(10, 10);
	SetColor(94);
	int x = 0, y = 0;
	int i;
	bool backToOriginalMenu = false;
	while (!backToOriginalMenu)
	{
		backToOriginalMenu = false;
		x = 50, y = 20;
		SetColor(4);
		if (song != -1) drawSelectedButton(94, 19, "Music:  ON"); else drawSelectedButton(94, 19, "Music: OFF");
		SetColor(0);
		drawButton(94, 22, "Change song");
		if (SoundEffects) drawButton(94, 25, "Sound effects:  ON"); else drawButton(94, 25, "Sound effects: OFF");
		drawButton(94, 28, "Back");
		SetColor(8);
		while (true)
		{
			if (_kbhit())
			{
				switch (_getch())
				{
				case 'w':
				case KEY_ARROW_UP:
					if (y > 20)
					{
						y--;
						GotoXY(x, y);
					}
					if (y == 20)
					{
						SetColor(4);
						if (song != -1) drawSelectedButton(94, 19, "Music:  ON"); else drawSelectedButton(94, 19, "Music: OFF");
						SetColor(0);
						drawButton(94, 22, "Change song");
						if (SoundEffects) drawButton(94, 25, "Sound effects:  ON"); else drawButton(94, 25, "Sound effects: OFF");
						drawButton(94, 28, "Back");
					}
					if (y == 21)
					{
						SetColor(0);
						if (song != -1) drawButton(94, 19, "Music:  ON"); else drawButton(94, 19, "Music: OFF");
						SetColor(4);
						drawSelectedButton(94, 22, "Change song");
						SetColor(0);
						if (SoundEffects) drawButton(94, 25, "Sound effects:  ON"); else drawButton(94, 25, "Sound effects: OFF");
						drawButton(94, 28, "Back");
					}
					if (y == 22)
					{
						SetColor(0);
						if (song != -1) drawButton(94, 19, "Music:  ON"); else drawButton(94, 19, "Music: OFF");
						drawButton(94, 22, "Change song");
						SetColor(4);
						if (SoundEffects) drawSelectedButton(94, 25, "Sound effects:  ON"); else drawSelectedButton(94, 25, "Sound effects: OFF");
						SetColor(0);
						drawButton(94, 28, "Back"); GotoXY(94, 28);
					}
					if (y == 23)
					{
						if (song != -1) drawButton(94, 19, "Music:  ON"); else drawButton(94, 19, "Music: OFF");
						SetColor(4);
						drawButton(94, 22, "Change song");
						if (SoundEffects) drawButton(94, 25, "Sound effects:  ON"); else drawButton(94, 25, "Sound effects: OFF");
						SetColor(0);
						drawSelectedButton(94, 28, "Back");  
					}
					break;
				case 's':
				case KEY_ARROW_DOWN:
					if (y < 23)
					{
						y++;
						GotoXY(x, y);
					}
					if (y == 20)
					{
						SetColor(4);
						if (song != -1) drawSelectedButton(94, 19, "Music:  ON"); else drawSelectedButton(94, 19, "Music: OFF");
						SetColor(0);
						drawButton(94, 22, "Change song");
						if (SoundEffects) drawButton(94, 25, "Sound effects:  ON"); else drawButton(94, 25, "Sound effects: OFF");
						drawButton(94, 28, "Back");
					}
					if (y == 21)
					{
						SetColor(0);
						if (song != -1) drawButton(94, 19, "Music:  ON"); else drawButton(94, 19, "Music: OFF");
						SetColor(4);
						drawSelectedButton(94, 22, "Change song");
						SetColor(0);
						if (SoundEffects) drawButton(94, 25, "Sound effects:  ON"); else drawButton(94, 25, "Sound effects: OFF");
						drawButton(94, 28, "Back");
					}
					if (y == 22)
					{
						SetColor(0);
						if (song != -1) drawButton(94, 19, "Music:  ON"); else drawButton(94, 19, "Music: OFF");

						drawButton(94, 22, "Change song");
						SetColor(4);
						if (SoundEffects) drawSelectedButton(94, 25, "Sound effects:  ON"); else drawSelectedButton(94, 25, "Sound effects: OFF");
						SetColor(0);
						drawButton(94, 28, "Back");
					}
					if (y == 23)
					{
						SetColor(0);
						if (song != -1) drawButton(94, 19, "Music:  ON"); else drawButton(94, 19, "Music: OFF");
						drawButton(94, 22, "Change song");
						if (SoundEffects) drawButton(94, 25, "Sound effects:  ON"); else drawButton(94, 25, "Sound effects: OFF");
						SetColor(4);
						drawSelectedButton(94, 28, "Back");
					}
					break;
				case 13:
					if (y == 20)
					{
						if (song != -1)
						{
							songtemp = song;
							song = -1;
							StopMusic();
						}
						else
						{
							song = songtemp;
							// Không có mở nhạc ở đây vì đang trong trận đấu
						}
						SetColor(4);
						if (song != -1) drawSelectedButton(94, 19, "Music:  ON"); else drawSelectedButton(94, 19, "Music: OFF");
						SetColor(0);
					}
					if (y == 21)
					{
						song++;
					}
					if (y == 22)
					{
						if (SoundEffects)
							SoundEffects = false;
						else
							SoundEffects = true;
						SetColor(4);
						if (SoundEffects) drawSelectedButton(94, 25, "Sound effects:  ON"); else drawSelectedButton(94, 25, "Sound effects: OFF");
						SetColor(0);
					}
					if (y == 23)
					{
						backToOriginalMenu = true;
					}
					break;
				}
				if (backToOriginalMenu)
				{
					break;
				}
			}
		}
	}
}


void drawFrame(int x, int y, int width, int height) 
{
	const char topLeftCorner = 201;
	const char topRightCorner = 187;
	const char bottomLeftCorner = 200;
	const char bottomRightCorner = 188;
	const char horizontalLine = 205;
	const char verticalLine = 186;
	SetColor(0);
	// Draw the top border
	GotoXY(x, y);
	cout << topLeftCorner;
	for (int i = 1; i < width - 1; i++) {
		cout << horizontalLine;
	}
	cout << topRightCorner;

	// Draw the bottom border
	GotoXY(x, y + height - 1);
	cout << bottomLeftCorner;
	for (int i = 1; i < width - 1; i++) {
		cout << horizontalLine;
	}
	cout << bottomRightCorner;

	// Draw the left and right borders
	for (int i = y + 1; i < y + height - 1; i++) {
		GotoXY(x, i);
		cout << verticalLine;
		GotoXY(x + width - 1, i);
		cout << verticalLine;
	}
}

void DrawBigText(string filename, int color, int x, int y)
{
	std::fstream textFile;
	textFile.open(filename.c_str(), std::fstream::in);
	string line;
	std::vector<std::string> line1;
	int tempY = y;
	while (getline(textFile, line)) line1.push_back(line);
	if (filename == "XWin.txt" || filename == "OWin.txt" || filename == "Draw.txt")
	{
		int count = 0;
		while (count <= 48)
		{
			for (int i = 0; i < line1.size(); i++)
				PrintText(line1[i], color + count % 10, x, y++);
			y = tempY;
			Sleep(100);
			for (int i = 0; i < line1.size(); i++)
			{
				string templine = "";
				for (int j = 0; j < line1[i].length(); j++) templine += ' ';
				PrintText(templine, 240, x, y++);
			}
			Sleep(100);
			y = tempY;
			count++;
		}
	}
	for (int i = 0;i < line1.size();i++)
		PrintText(line1[i], color, x, y++);
	textFile.close();
}

void DrawBoardGiaoDien(_POINT _A[][BOARD_SIZE],int color)
{
	int x = _A[0][BOARD_SIZE].x + 72;
	int y = _A[0][BOARD_SIZE].y + 13;
	GotoXY(x, y);
	SetColor(color);
	drawFrame(74, 18, 60, 15);
	/*drawBox(74, 18, 60, 15);*/
	GotoXY(x + 10, y + 15);
	SetColor(8);
	cout << "Press Esc to Save game or Back to menu...";
}

void DrawPhimTat(_POINT _A[][BOARD_SIZE])
{
	int x = _A[0][BOARD_SIZE].x + 78;
	int y = _A[0][BOARD_SIZE].y + 16;
	ShowCur(0);	
	SetColor(16);
	GotoXY(x+3, y);
	cout << "     _____";
	GotoXY(x+3, y + 1);
	cout << "    |\\ ___\\";
	GotoXY(x+3, y + 2);
	cout << " ___| | W |__";
	GotoXY(x+3, y + 3);
	cout << "|\\ __\\|___| _\\ ";
	GotoXY(x+3, y + 4);
	cout << "| | A | S | D |";
	GotoXY(x+3, y + 5);
	cout << " \\|___|___|___|";
	GotoXY(x + 34, y);
	cout << "     _____";
	GotoXY(x + 34, y + 1);
	cout << "    |\\ ___\\";
	GotoXY(x + 34, y + 2);
	cout << " ___| | ^ |__";
	GotoXY(x + 34, y + 3);
	cout << "|\\ __\\|___| _\\ ";
	GotoXY(x + 34, y + 4);
	cout << "| | < | v | > |";
	GotoXY(x + 34, y + 5);
	cout << " \\|___|___|___|";
	GotoXY(x + 34, y+6);
	cout << "	 _____";
	GotoXY(x + 34, y + 7);
	cout << "	|\\____\\";
	GotoXY(x + 34, y + 8);
	cout << " _____||    |";
	GotoXY(x + 34, y + 9);
	cout << "|\\ ___\\|    | ";
	GotoXY(x + 34, y + 10);
	cout << "| |  Enter  |";
	GotoXY(x + 34, y + 11);
	cout << " \\|_________|";
	GotoXY(x-1, y + 8);
	cout << " __________________________";
	GotoXY(x-1, y + 9);
	cout << "|\\          Space          \\";
	GotoXY(x-1, y + 10);
	cout << "\\ \\_________________________\\";
	GotoXY(x-1, y + 11);
	cout << " \\|_________________________|";
	ShowCur(1);
}

void drawButton(int x, int y, string text)
{
	GotoXY(x - 2, y);
	cout << "  ";
	GotoXY(x - 2, y + 1);
	cout << "  ";
	GotoXY(x - 2, y + 2);
	cout << "  ";
	GotoXY(x +23, y);
	cout << "  ";
	GotoXY(x +23, y + 1);
	cout << "  ";
	GotoXY(x +23, y + 2);
	cout << "  ";
	int width = 21; // length of "PLAYER VS COMPUTER" + 2
	GotoXY(x, y); cout << char(218);
	for (int i = 0; i < width; i++) cout << char(196);
	cout << char(191);
	GotoXY(x, y + 1); cout << char(179) << setw((width - text.length()) / 2 + text.length()) << right << text;
	if (text.length() % 2 == 0) cout << setw((width - text.length()) / 2 + 1) << right << " " << char(179);
	else cout << setw((width - text.length()) / 2) << "" << right << char(179);
	GotoXY(x, y + 2); cout << char(192);
	for (int i = 0; i < width; i++) cout << char(196);
	cout << char(217);
}

void drawSelectedButton(int x, int y, string text)
{
	TextColor(79);
	int width = 25; // length of "PLAYER VS COMPUTER" + 2
	GotoXY(x-2, y); cout << char(218);
	for (int i = 0; i < width; i++) cout << char(196);
	cout << char(191);
	GotoXY(x-2, y + 1); cout << char(179) << setw((width - text.length()) / 2 + text.length()) << right << text;
	if (text.length() % 2 == 0) cout << setw((width - text.length()) / 2 + 1) << right << " " << char(179);
	else cout << setw((width - text.length()) / 2) << "" << right << char(179);
	GotoXY(x-2, y + 2); cout << char(192);
	for (int i = 0; i < width; i++) cout << char(196);
	cout << char(217);
	TextColor(240);
}
void printCaro(int x, int y) {
	SetColor(1);
	GotoXY(x, y);
	cout << char(32) << char(219) << char(219) << char(219) << char(219) << char(219) << char(219) << char(187) << char(32) << char(219) << char(219) << char(219) << char(219) << char(219) << char(187) << char(32) << char(219) << char(219) << char(219) << char(219) << char(219) << char(219) << char(187) << char(32) << char(32) << char(219) << char(219) << char(219) << char(219) << char(219) << char(219) << char(187);
	GotoXY(x, y+1);
	cout << char(FULL) << char(FULL) << char(DOUBLE_TOP_LEFT) << char(DOUBLE_HORIZONTAL) << char(DOUBLE_HORIZONTAL) << char(DOUBLE_HORIZONTAL) << char(DOUBLE_HORIZONTAL) << char(DOUBLE_BOTTOM_RIGHT) << char(FULL) << char(FULL) << char(DOUBLE_TOP_LEFT) << char(DOUBLE_HORIZONTAL) << char(DOUBLE_HORIZONTAL) << char(FULL) << char(FULL) << char(DOUBLE_TOP_RIGHT) << char(FULL) << char(FULL) << char(DOUBLE_TOP_LEFT) << char(DOUBLE_HORIZONTAL) << char(DOUBLE_HORIZONTAL) << char(FULL) << char(FULL) << char(DOUBLE_TOP_RIGHT) << char(FULL) << char(FULL) << char(DOUBLE_TOP_LEFT) << char(DOUBLE_HORIZONTAL) << char(DOUBLE_HORIZONTAL) << char(DOUBLE_HORIZONTAL) << char(FULL) << char(FULL) << char(DOUBLE_TOP_RIGHT);
	SetColor(9);
	GotoXY(x, y+2);
	cout << char(FULL) << char(FULL) << char(DOUBLE_VERTICAL) << char(SPACE) << char(SPACE) << char(SPACE) << char(SPACE) << char(SPACE) << char(FULL) << char(FULL) << char(FULL) << char(FULL) << char(FULL) << char(FULL) << char(FULL) << char(DOUBLE_VERTICAL) << char(FULL) << char(FULL) << char(FULL) << char(FULL) << char(FULL) << char(FULL) << char(DOUBLE_TOP_LEFT) << char(DOUBLE_BOTTOM_RIGHT) << char(FULL) << char(FULL) << char(DOUBLE_VERTICAL) << char(SPACE) << char(SPACE) << char(SPACE) << char(FULL) << char(FULL) << char(DOUBLE_VERTICAL);
	GotoXY(x, y+3);
	cout << char(FULL) << char(FULL) << char(DOUBLE_VERTICAL) << char(SPACE) << char(SPACE) << char(SPACE) << char(SPACE) << char(SPACE) << char(FULL) << char(FULL) << char(DOUBLE_TOP_LEFT) << char(DOUBLE_HORIZONTAL) << char(DOUBLE_HORIZONTAL) << char(FULL) << char(FULL) << char(DOUBLE_VERTICAL) << char(FULL) << char(FULL) << char(DOUBLE_TOP_LEFT) << char(DOUBLE_HORIZONTAL) << char(DOUBLE_HORIZONTAL) << char(FULL) << char(FULL) << char(DOUBLE_TOP_RIGHT) << char(FULL) << char(FULL) << char(DOUBLE_VERTICAL) << char(SPACE) << char(SPACE) << char(SPACE) << char(FULL) << char(FULL) << char(DOUBLE_VERTICAL);
	SetColor(3);
	GotoXY(x, y+4);
	cout << char(DOUBLE_BOTTOM_LEFT) << char(FULL) << char(FULL) << char(FULL) << char(FULL) << char(FULL) << char(FULL) << char(DOUBLE_TOP_RIGHT) << char(FULL) << char(FULL) << char(DOUBLE_VERTICAL) << char(SPACE) << char(SPACE) << char(FULL) << char(FULL) << char(DOUBLE_VERTICAL) << char(FULL) << char(FULL) << char(DOUBLE_VERTICAL) << char(SPACE) << char(SPACE) << char(FULL) << char(FULL) << char(DOUBLE_VERTICAL) << char(DOUBLE_BOTTOM_LEFT) << char(FULL) << char(FULL) << char(FULL) << char(FULL) << char(FULL) << char(FULL) << char(DOUBLE_TOP_LEFT) << char(DOUBLE_BOTTOM_RIGHT);
	SetColor(11);
	GotoXY(x, y+5);
	cout << char(SPACE) << char(DOUBLE_BOTTOM_LEFT) << char(DOUBLE_HORIZONTAL) << char(DOUBLE_HORIZONTAL) << char(DOUBLE_HORIZONTAL) << char(DOUBLE_HORIZONTAL) << char(DOUBLE_HORIZONTAL) << char(DOUBLE_BOTTOM_RIGHT) << char(DOUBLE_BOTTOM_LEFT) << char(DOUBLE_HORIZONTAL) << char(DOUBLE_BOTTOM_RIGHT) << char(SPACE) << char(SPACE) << char(DOUBLE_BOTTOM_LEFT) << char(DOUBLE_HORIZONTAL) << char(DOUBLE_BOTTOM_RIGHT) << char(DOUBLE_BOTTOM_LEFT) << char(DOUBLE_HORIZONTAL) << char(DOUBLE_BOTTOM_RIGHT) << char(SPACE) << char(SPACE) << char(DOUBLE_BOTTOM_LEFT) << char(DOUBLE_HORIZONTAL) << char(DOUBLE_BOTTOM_RIGHT) << char(SPACE) << char(DOUBLE_BOTTOM_LEFT) << char(DOUBLE_HORIZONTAL) << char(DOUBLE_HORIZONTAL) << char(DOUBLE_HORIZONTAL) << char(DOUBLE_HORIZONTAL) << char(DOUBLE_HORIZONTAL) << char(DOUBLE_BOTTOM_RIGHT) << char(SPACE);
	SetColor(1);
	GotoXY(x, y+6);
	cout << "     ----  By Group 15  ----      ";
}               

void printBigCaro(int x, int y)
{
	SetColor(1);
	GotoXY(x, y);
	cout << char(32);
	for (int i = 0;i < 15;i++)
		cout << (char)219;
	cout << char(187) << char(32) << char(32);
	for (int i = 0;i < 14;i++)
		cout << (char)219;
	cout << char(187) << char(32) << char(32);
	for (int i = 0;i < 14;i++)
		cout << (char)219;
	cout << char(187) << char(32) << char(32) << char(32) << char(32);
	for (int i = 0;i < 14;i++)
		cout << (char)219;
	cout << char(187);
	GotoXY(x, y + 1);
	//cout << char(32) << char(32);
	for (int i = 0;i < 16;i++)
		cout << (char)219;
	cout << char(186) << char(32);
	for (int i = 0;i < 16;i++)
		cout << (char)219;
	cout << char(187) << char(32);
	for (int i = 0;i < 16;i++)
		cout << (char)219;
	cout << char(187) << char(32);
	for (int i = 0;i < 16;i++)
		cout << (char)219;
	cout << char(187);
	GotoXY(x, y + 2);
	//cout << char(32) << char(32);
	for (int i = 0;i < 5;i++)
		cout << (char)219;
	cout << char(201);
	for (int i = 0;i < 10;i++)
		cout << (char)205;
	cout << char(188) << char(32);
	for (int i = 0;i < 5;i++)
		cout << (char)219;
	cout << char(201);
	for (int i = 0;i < 5;i++)
		cout << (char)205;
	for (int i = 0;i < 5;i++)
		cout << (char)219;
	cout << char(186) << char(32);
	for (int i = 0;i < 5;i++)
		cout << (char)219;
	cout << char(201);
	for (int i = 0;i < 5;i++)
		cout << (char)205;
	for (int i = 0;i < 5;i++)
		cout << (char)219;
	cout << char(186) << char(32);
	for (int i = 0;i < 5;i++)
		cout << (char)219;
	cout << char(201);
	for (int i = 0;i < 5;i++)
		cout << (char)205;
	for (int i = 0;i < 5;i++)
		cout << (char)219;
	cout << char(186) << char(32);
	GotoXY(x, y + 3);
	//cout << char(32) << char(32);
	for (int i = 0;i < 5;i++)
		cout << (char)219;
	cout << char(186);
	for (int i = 0;i < 12;i++)
		cout << (char)32;
	for (int i = 0;i < 5;i++)
		cout << (char)219;
	cout << char(186);
	for (int i = 0;i < 5;i++)
		cout << (char)32;
	for (int i = 0;i < 5;i++)
		cout << (char)219;
	cout << char(186) << char(32);
	for (int i = 0;i < 5;i++)
		cout << (char)219;
	cout << char(186);
	for (int i = 0;i < 5;i++)
		cout << (char)32;
	for (int i = 0;i < 5;i++)
		cout << (char)219;
	cout << char(186) << char(32);
	for (int i = 0;i < 5;i++)
		cout << (char)219;
	cout << char(186);
	for (int i = 0;i < 5;i++)
		cout << (char)32;
	for (int i = 0;i < 5;i++)
		cout << (char)219;
	cout << char(186);
	SetColor(249);
	GotoXY(x, y + 4);
	//cout << char(32) << char(32);
	for (int i = 0;i < 5;i++)
		cout << (char)219;
	cout << char(186);
	for (int i = 0;i < 12;i++)
		cout << (char)32;
	for (int i = 0;i < 5;i++)
		cout << (char)219;
	cout << char(186);
	for (int i = 0;i < 5;i++)
		cout << (char)32;
	for (int i = 0;i < 5;i++)
		cout << (char)219;
	cout << char(186) << char(32);
	for (int i = 0;i < 5;i++)
		cout << (char)219;
	cout << char(186);
	for (int i = 0;i < 5;i++)
		cout << (char)32;
	for (int i = 0;i < 4;i++)
		cout << (char)219;
	cout << char(201) << char(188) << char(32);
	for (int i = 0;i < 5;i++)
		cout << (char)219;
	cout << char(186);
	for (int i = 0;i < 5;i++)
		cout << (char)32;
	for (int i = 0;i < 5;i++)
		cout << (char)219;
	cout << char(186);
	GotoXY(x, y + 5);
	//cout << char(32) << char(32);
	for (int i = 0;i < 5;i++)
		cout << (char)219;
	cout << char(186);
	for (int i = 0;i < 12;i++)
		cout << (char)32;
	for (int i = 0;i < 16;i++)
		cout << (char)219;
	cout << char(186) << char(32);
	for (int i = 0;i < 14;i++)
		cout << (char)219;
	cout << char(201) << char(188) << char(32) << char(32);
	for (int i = 0;i < 5;i++)
		cout << (char)219;
	cout << char(186);
	for (int i = 0;i < 5;i++)
		cout << (char)32;
	for (int i = 0;i < 5;i++)
		cout << (char)219;
	cout << char(186);
	GotoXY(x, y + 6);
	//cout << char(32) << char(32);
	for (int i = 0;i < 5;i++)
		cout << (char)219;
	cout << char(186);
	for (int i = 0;i < 12;i++)
		cout << (char)32;
	for (int i = 0;i < 16;i++)
		cout << (char)219;
	cout << char(186) << char(32);
	for (int i = 0;i < 15;i++)
		cout << (char)219;
	cout << char(187) << char(32) << char(32);
	for (int i = 0;i < 5;i++)
		cout << (char)219;
	cout << char(186);
	for (int i = 0;i < 5;i++)
		cout << (char)32;
	for (int i = 0;i < 5;i++)
		cout << (char)219;
	cout << char(186);
	SetColor(243);
	GotoXY(x, y + 7);
	//cout << char(32) << char(32);
	for (int i = 0;i < 5;i++)
		cout << (char)219;
	cout << char(186);
	for (int i = 0;i < 12;i++)
		cout << (char)32;
	for (int i = 0;i < 5;i++)
		cout << (char)219;
	cout << char(201);
	for (int i = 0;i < 5;i++)
		cout << (char)205;
	for (int i = 0;i < 5;i++)
		cout << (char)219;
	cout << char(186) << char(32);
	for (int i = 0;i < 5;i++)
		cout << (char)219;
	cout << char(201);
	for (int i = 0;i < 5;i++)
		cout << (char)205;
	for (int i = 0;i < 5;i++)
		cout << (char)219;
	cout << char(187) << char(32);
	for (int i = 0;i < 5;i++)
		cout << (char)219;
	cout << char(186);
	for (int i = 0;i < 5;i++)
		cout << (char)32;
	for (int i = 0;i < 5;i++)
		cout << (char)219;
	cout << char(186);
	GotoXY(x, y + 8);
	//cout << char(32) << char(32);
	for (int i = 0;i < 16;i++)
		cout << char(219);
	cout << char(187) << char(32);
	for (int i = 0;i < 5;i++)
		cout << (char)219;
	cout << char(186);
	for (int i = 0;i < 5;i++)
		cout << (char)32;
	for (int i = 0;i < 5;i++)
		cout << (char)219;
	cout << char(186) << char(32);
	for (int i = 0;i < 5;i++)
		cout << (char)219;
	cout << char(186);
	for (int i = 0;i < 5;i++)
		cout << (char)32;
	for (int i = 0;i < 5;i++)
		cout << (char)219;
	cout << char(186) << char(32);
	for (int i = 0;i < 16;i++)
		cout << char(219);
	cout << char(186);
	SetColor(251);
	GotoXY(x, y + 9);
	cout  << char(200);
	for (int i = 0;i < 15;i++)
		cout << char(219);
	cout << char(186) << char(32);
	for (int i = 0;i < 5;i++)
		cout << (char)219;
	cout << char(186);
	for (int i = 0;i < 5;i++)
		cout << (char)32;
	for (int i = 0;i < 5;i++)
		cout << (char)219;
	cout << char(186) << char(32);
	for (int i = 0;i < 5;i++)
		cout << (char)219;
	cout << char(186);
	for (int i = 0;i < 5;i++)
		cout << (char)32;
	for (int i = 0;i < 5;i++)
		cout << (char)219;
	cout << char(186) << char(32) << char(200);
	for (int i = 0;i < 14;i++)
		cout << char(219);
	cout << char(201) << char(188);
	GotoXY(x, y + 10);
	cout << char(32)<< char(200);
	for (int i = 0;i < 14;i++)
		cout << char(205);
	cout << char(188) << char(32);
	cout << char(200);
	for (int i = 0;i < 4;i++)
		cout << char(205);
	cout << char(188);
	for (int i = 0;i < 5;i++)
		cout << char(32);
	cout << char(200);
	for (int i = 0;i < 4;i++)
		cout << char(205);
	cout << char(188);
	cout << char(32);
	cout << char(200);
	for (int i = 0;i < 4;i++)
		cout << char(205);
	cout << char(188);
	for (int i = 0;i < 5;i++)
		cout << char(32);
	cout << char(200);
	for (int i = 0;i < 4;i++)
		cout << char(205);
	cout << char(188);
	cout << char(32) << char(32);
	cout << char(200);
	for (int i = 0;i < 13;i++)
		cout << char(205);
	cout << char(188);
	SetColor(1);
	GotoXY(x, y + 11);
	cout << "                        ----  By Group 15  ----";
}

// ██████╗ █████╗ ██████╗  ██████╗ 
//██╔════╝██╔══██╗██╔══██╗██╔═══██╗
//██║     ███████║██████╔╝██║   ██║
//██║     ██╔══██║██╔══██╗██║   ██║
//╚██████╗██║  ██║██║  ██║╚██████╔╝
// ╚═════╝╚═╝  ╚═╝╚═╝  ╚═╝ ╚═════╝ 

void Loading()
{
	int a[10] = { 17,17,17,17,153,153,153,51,51,187 };
	int b[10] = { 31,31,31,31,159,159,159,63,63,191 };
	system("cls");
	printBigCaro(35, 3);
	int x = 25;
	int y = 16;
	GotoXY(x, y);
	SetColor(0);
	ShowCur(0);
	cout << (char)201;
	for (int i = 0; i < 95; i++)
		cout << (char)205;
	cout << (char)187;
	for (int i = 1; i < 2; i++)
	{
		GotoXY(x, y + i);
		cout << (char)186;
		GotoXY(x + 96, y + i);
		cout << (char)186;
	}
	GotoXY(x, y + 2);
	cout << (char)200;
	for (int i = 0; i < 95; i++)
		cout << (char)205;
	cout << (char)188;
	y = 16;
	x = 20;
	GotoXY(x+8, y);
	cout << "Loading . . .";
	TextColor(255);
	for (unsigned short int i = 1; i <= 10; ++i)
	{
		//textcolor(111);
		//SetColor(9);
		PrintText("        ", a[i-1], x += 8, y + 1);
		//TextColor(0 +rand() % 100);
		//textcolor(111);
		//GotoXY(x+=8, y +1);
		//cout << "     ";
		TextColor(b[i-1]);
		GotoXY(x+7, y+1);
		cout << i * 10 << "%";

		Sleep(100);
		GotoXY(x+7, y+1);
		cout << "       ";
	}
	Sleep(50);
	system("cls");
}
void ShowRank()
{
	int x = 35;
	int y = 11;
	std::vector<_PLAYER> players = GetPlayerList();
	GotoXY(x - 2, y + 4); cout << char(4) << " TOP 10 PLAYERS " << char(4);
	PrintText("[Challenger] " + players.at(0).name, 209, x - 2, y + 6); // Xanh trời
	PrintText("[Grandmaster] " + players.at(1).name, 196, x - 2, y + 7); // Đỏ tươi
	PrintText("[Master] " + players.at(2).name, 253, x - 2, y + 6 + 2); // Tím đậm
	PrintText("[Diamond] " + players.at(3).name, 249, x - 2, y + 6 + 3); // Xanh ngọc
	PrintText("[Diamond] " + players.at(4).name, 249, x - 2, y + 6 + 4); // Xanh ngọc
	PrintText("[Platinum] " + players.at(5).name, 234, x - 2, y + 6 + 5); // Xanh lá
	PrintText("[Platinum] " + players.at(6).name, 234, x - 2, y + 6 + 6); // Xanh lá
	PrintText("[Gold] " + players.at(7).name, 70, x - 2, y + 6 + 7); // Vàng
	PrintText("[Gold] " + players.at(8).name, 70, x - 2, y + 6 + 8); // Vàng
	PrintText("[Silver] " + players.at(9).name, 240, x - 2, y + 6 + 9); // Xám bạc
	PrintText("[Silver] " + players.at(10).name, 240, x - 2, y + 6 +10); // Xác bạc
	SetColor(8);
	GotoXY(30, 29);
	cout << "Press any key to continue";
	SetColor(0);
	char command = ' ';
	command = _getch();
}
void ShowPlayerInfo(_POINT _A[][BOARD_SIZE], _PLAYER _PLAYER1, _PLAYER _PLAYER2)
{
	int start = _A[0][BOARD_SIZE - 1].x + 4;
	//PrintText(_PLAYER1.name, 253, start + 12, 18);
	PrintText("Wins:", 1, start + 14, 16);
	PrintText(std::to_string(_PLAYER1.wins), 1, start + 21, 16);
	PrintText("Rank:", 1, start + 14, 17);
	PrintText(std::to_string(_PLAYER1.rank), 1, start + 21, 17);
	//PrintText(_PLAYER2.name, 253, start + 23, 18);
	PrintText("Wins:", 2, start + 23 + 32 + 8 - 7, 16);
	PrintText("Rank:", 2, start + 23 + 32 + 8 - 7, 17);
	PrintText(std::to_string(_PLAYER2.wins), 2, start + 23 + 32 + 8, 16);
	PrintText(std::to_string(_PLAYER2.rank), 2, start + 23 + 32 + 8, 17);
}


                                                       


                                            
