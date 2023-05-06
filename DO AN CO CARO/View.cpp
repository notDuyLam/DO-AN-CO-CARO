#include "View.h"

void resizeConsole(int width, int height)
{
	HWND console = GetConsoleWindow();
	RECT r;
	GetWindowRect(console, &r);
	MoveWindow(console, r.left, r.top, width, height, TRUE);
}
void CreateConsoleWindow(int pWidth, int pHeight)
{
	HWND consoleWindow = GetConsoleWindow();
	RECT r;
	HANDLE hConsole;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, 240);
	GetWindowRect(consoleWindow, &r);
	MoveWindow(consoleWindow, 0, 0, pWidth, pHeight, TRUE);
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
	//DrawBoardGiaoDien(1, BOARD_SIZE + 40, BOARD_SIZE + 70);
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
int ProcessFinish(int pWhoWin, _POINT _A[][BOARD_SIZE], bool& _TURN, int& _X, int& _Y,short int toadothang[24], bool& MO_NHAC, _PLAYER& _PLAYER1, _PLAYER& _PLAYER2)
{
	switch (pWhoWin) {
	case -1:
		PlaySoundEffect("win.wav", MO_NHAC);
		NhapNhayQuanCo(_A, toadothang, pWhoWin);
		ThongBaoWin(pWhoWin, _A);
		GotoXY(78,18); // Nhảy tới vị trí 
		// thích hợp để in chuỗi thắng/thua/hòa
		//printf("Nguoi choi %d da thang va nguoi choi %d da thua\n", true, false);
		cout << "Nguoi choi " << _PLAYER1.name << " da thang va nguoi choi " << _PLAYER2.name << " da thua.";
		SavePlayer(_PLAYER1);
		break;
	case 1:
		PlaySoundEffect("win", MO_NHAC);
		NhapNhayQuanCo(_A, toadothang, pWhoWin);
		ThongBaoWin(pWhoWin, _A);
		GotoXY(78,18); // Nhảy tới vị trí 
		// thích hợp để in chuỗi thắng/thua/hòa
		//printf("Nguoi choi %d da thang va nguoi choi %d da thua\n", false, true);
		cout << "Nguoi choi " << _PLAYER2.name << " da thang va nguoi choi " << _PLAYER1.name << " da thua.";
		SavePlayer(_PLAYER2);
		break;
	case 0:
		//printf("Nguoi choi %d da hoa nguoi choi %d\n", false, true);
		ThongBaoWin(pWhoWin, _A);
		GotoXY(78,18);
		cout << "Nguoi choi " << _PLAYER2.name << " da hoa nguoi choi " << _PLAYER1.name;
		break;
	case 2:
		_TURN = !_TURN; // Đổi lượt nếu không có gì xảy ra
		ShowTurn(_A, _PLAYER1, _PLAYER2, _TURN);
		ShowCur(1);
		break;
	}
	GotoXY(_X, _Y); // Trả về vị trí hiện hành của con trỏ màn hình bàn cờ
	return pWhoWin;
}

void XWin(_POINT _A[][BOARD_SIZE])
{
	GotoXY(72, 3);
	cout << "                                                               ";
	GotoXY(72, 4);
	cout << " Y888b     d888P     8888         8888 88888888 888b      8888";
	GotoXY(72, 5);
	cout << "  Y888b   d888P      8888         8888   8888   8888b     8888";
	GotoXY(72, 6);
	cout << "   Y888b d888P       8888         8888   8888   88888b    8888";
	GotoXY(72, 7);
	cout << "    Y888o888P        8888    o    8888   8888   888888b   8888 ";
	GotoXY(72, 8);
	cout << "     Y88898P         8888   d8b   8888   8888   8888Y88b  8888 ";
	GotoXY(72, 9);
	cout << "     d88888b         8888  d888b  8888   8888   8888Y888b88888 ";
	GotoXY(72, 10);
	cout << "    d8888888b        8888 d8   8b 8888   8888   8888  Y888b888 ";
	GotoXY(72, 11);
	cout << "   d888P Y888b       88888d     b88888   8898   8888   Y888888 ";
	GotoXY(72, 12);
	cout << "  d888P   Y888b      8888P       Y8888   8888   8888    Y88888  ";
	GotoXY(72, 13);
	cout << " d888P     Y888b     888P         Y888 88888888 8888     Y8888  ";
	GotoXY(72, 14);
	cout << "                                                                  ";
}

void OWin(_POINT _A[][BOARD_SIZE])
{
	GotoXY(70, 3);
	cout << "                                                               ";
	GotoXY(70, 4);
	cout << "    .d88888888b.        8888         8888 88888888 888b      8888 ";
	GotoXY(70, 5);
	cout << "   d888888888888b       8888         8888   8888   8888b     8888 ";
	GotoXY(70, 6);
	cout << "  d888P'    'Y888b      8888         8888   8888   88888b    8888 ";
	GotoXY(70, 7);
	cout << "  8888        8888      8888    o    8888   8888   888888b   8888 ";
	GotoXY(70, 8);
	cout << "  8888        8888      8888   d8b   8888   8888   8888Y88b  8888 ";
	GotoXY(70, 9);
	cout << "  8888        8888      8888  d888b  8888   8888   8888Y888b88888 ";
	GotoXY(70, 10);
	cout << "  8888        8888      8888 d8   8b 8888   8888   8888  Y888b888 ";
	GotoXY(70, 11);
	cout << "  Y888b.    .d886P      88888d     b88888   8898   8888   Y888888 ";
	GotoXY(70, 12);
	cout << "   Y888888888886P       8888P       Y8888   8888   8888    Y88888 ";
	GotoXY(70, 13);
	cout << "    'Y88888888P'        888P         Y888 88888888 8888     Y8888 ";
	GotoXY(70, 14);
	cout << "                                                                  ";

}

void Draw(_POINT _A[][BOARD_SIZE])
{
	GotoXY(70, 3);
	cout << "                                                                  ";
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
	cout << "                                                                  ";

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

int AskContinue(_POINT _A[][BOARD_SIZE])
{
	GotoXY(78, 19);
	printf("Nhan 'y/n' de tiep tuc/dung: ");
	return toupper(_getch());
}
void ScreenStartGame(int n, _POINT _A[][BOARD_SIZE], bool _TURN, int _COMMAND, int _X, int _Y, bool validEnter, bool& MO_NHAC, int& chedo, _PLAYER& _PLAYER1, _PLAYER& _PLAYER2)
{
	int song = 0;
	bool vsComputer;
	PlayBackGroundMusic(song);
	int x = 0, y = 0;
	drawFrame(0, 0, 145, 33);
	drawFrame(5, 3, 80, 28);
	int i;
	bool backToOriginalMenu = false;
	x = 0; y = 0;
	while (true)
	{
		drawFrame(0, 0, 145, 33);
		drawFrame(5, 3, 80, 28);
		TextColor(255);
		printBigCaro(10, 10);
		//printCaro(29,14);
		backToOriginalMenu = false;
		x = 100, y = 20;
		// color, width, height, x, y
		SetColor(4);
		//GotoXY(100, 3); cout << "PLAYER VS PLAYER";
		drawButton(100, 5, "PLAYER VS PLAYER");
		SetColor(0);
		drawButton(100, 8, "PLAYER VS COMPUTER");
		drawButton(100, 11, "LOAD GAME");
		drawButton(100, 14, "HELP");
		drawButton(100, 17, "ABOUT");
		drawButton(100, 20, "SOUND");
		drawButton(100, 23, "RANKING");
		drawButton(100, 26, "EXIT");
		SetColor(8);
		GotoXY(98, 29); cout << "_____ W A S D: MOVE _____";
		GotoXY(98, 30); cout << "_____ Enter: Select _____" ;
		while (true)
		{
			if (_kbhit())
			{
				switch (_getch())
				{
				case 'w':
					if (y > 20)
					{
						y--;
						GotoXY(x, y);
					}
					if (y == 20)
					{
						SetColor(4);
						drawButton(100, 5, "PLAYER VS PLAYER");
						SetColor(0);
						drawButton(100, 8, "PLAYER VS COMPUTER");
						drawButton(100, 11, "LOAD GAME");
						drawButton(100, 14, "HELP");
						drawButton(100, 17, "About");
						drawButton(100, 20, "SOUND");
						drawButton(100, 23, "RANKING");
						drawButton(100, 26, "EXIT");
					}
					if (y == 21)
					{
						SetColor(0);
						drawButton(100, 5, "PLAYER VS PLAYER");
						SetColor(4);
						drawButton(100, 8, "PLAYER VS COMPUTER");
						SetColor(0);
						drawButton(100, 11, "LOAD GAME");
						drawButton(100, 14, "HELP");
						drawButton(100, 17, "About");
						drawButton(100, 20, "SOUND");
						drawButton(100, 23, "RANKING");
						drawButton(100, 26, "EXIT");
					}
					if (y == 22)
					{
						SetColor(0);
						drawButton(100, 5, "PLAYER VS PLAYER");
						drawButton(100, 8, "PLAYER VS COMPUTER");
						SetColor(4);
						drawButton(100, 11, "LOAD GAME");
						SetColor(0);
						drawButton(100, 14, "HELP");
						drawButton(100, 17, "About");
						drawButton(100, 20, "SOUND");
						drawButton(100, 23, "RANKING");
						drawButton(100, 26, "EXIT");
					}
					if (y == 23)
					{
						SetColor(0);
						drawButton(100, 5, "PLAYER VS PLAYER");
						drawButton(100, 8, "PLAYER VS COMPUTER");
						drawButton(100, 11, "LOAD GAME");
						SetColor(4);
						drawButton(100, 14, "HELP");
						SetColor(0);
						drawButton(100, 17, "About");
						drawButton(100, 20, "SOUND");
						drawButton(100, 23, "RANKING");
						drawButton(100, 26, "EXIT");
					}
					if (y == 24)
					{
						SetColor(0);
						drawButton(100, 5, "PLAYER VS PLAYER");
						drawButton(100, 8, "PLAYER VS COMPUTER");
						drawButton(100, 11, "LOAD GAME");
						drawButton(100, 14, "HELP");
						SetColor(4);
						drawButton(100, 17, "About");
						SetColor(0);
						drawButton(100, 20, "SOUND");
						drawButton(100, 23, "RANKING");
						drawButton(100, 26, "EXIT");
					}
					if (y == 25)
					{
						SetColor(0);
						drawButton(100, 5, "PLAYER VS PLAYER");
						drawButton(100, 8, "PLAYER VS COMPUTER");
						drawButton(100, 11, "LOAD GAME");
						drawButton(100, 14, "HELP");
						drawButton(100, 17, "About");
						SetColor(4);
						drawButton(100, 20, "SOUND");
						SetColor(0);
						drawButton(100, 23, "RANKING");
						drawButton(100, 26, "EXIT");
					}
					if (y == 26)
					{
						SetColor(0);
						drawButton(100, 5, "PLAYER VS PLAYER");
						drawButton(100, 8, "PLAYER VS COMPUTER");
						drawButton(100, 11, "LOAD GAME");
						drawButton(100, 14, "HELP");
						drawButton(100, 17, "About");
						
						drawButton(100, 20, "SOUND");
						SetColor(4);
						drawButton(100, 23, "RANKING");
						SetColor(0);
						drawButton(100, 26, "EXIT");
					}
					if (y == 27)
					{
						SetColor(0);
						drawButton(100, 5, "PLAYER VS PLAYER");
						drawButton(100, 8, "PLAYER VS COMPUTER");
						drawButton(100, 11, "LOAD GAME");
						drawButton(100, 14, "HELP");
						drawButton(100, 17, "About");
						drawButton(100, 20, "SOUND");
						SetColor(4);
						drawButton(100, 23, "RANKING");
						SetColor(0);
						drawButton(100, 26, "EXIT");
					}
					break;
				case 's':
					if (y < 27)
					{
						y++;
						GotoXY(x, y);
					}
					if (y == 20)
					{
						SetColor(4);
						drawButton(100, 5, "PLAYER VS PLAYER");
						SetColor(0);
						drawButton(100, 8, "PLAYER VS COMPUTER");
						drawButton(100, 11, "LOAD GAME");
						drawButton(100, 14, "HELP");
						drawButton(100, 17, "About");
						drawButton(100, 20, "SOUND");
						drawButton(100, 23, "RANKING");
						drawButton(100, 26, "EXIT");
					}
					if (y == 21)
					{
						SetColor(0);
						drawButton(100, 5, "PLAYER VS PLAYER");
						SetColor(4);
						drawButton(100, 8, "PLAYER VS COMPUTER");
						SetColor(0);
						drawButton(100, 11, "LOAD GAME");
						drawButton(100, 14, "HELP");
						drawButton(100, 17, "About");
						drawButton(100, 20, "SOUND");
						drawButton(100, 23, "RANKING");
						drawButton(100, 26, "EXIT");
					}
					if (y == 22)
					{
						SetColor(0);
						drawButton(100, 5, "PLAYER VS PLAYER");
						drawButton(100, 8, "PLAYER VS COMPUTER");
						SetColor(4);
						drawButton(100, 11, "LOAD GAME");
						SetColor(0);
						drawButton(100, 14, "HELP");
						drawButton(100, 17, "About");
						drawButton(100, 20, "SOUND");
						drawButton(100, 23, "RANKING");
						drawButton(100, 26, "EXIT");
					}
					if (y == 23)
					{
						SetColor(0);
						drawButton(100, 5, "PLAYER VS PLAYER");
						drawButton(100, 8, "PLAYER VS COMPUTER");
						drawButton(100, 11, "LOAD GAME");
						SetColor(4);
						drawButton(100, 14, "HELP");
						SetColor(0);
						drawButton(100, 17, "About");
						drawButton(100, 20, "SOUND");
						drawButton(100, 23, "RANKING");
						drawButton(100, 26, "EXIT");
					}
					if (y == 24)
					{
						SetColor(0);
						drawButton(100, 5, "PLAYER VS PLAYER");
						drawButton(100, 8, "PLAYER VS COMPUTER");
						drawButton(100, 11, "LOAD GAME");
						drawButton(100, 14, "HELP");
						SetColor(4);
						drawButton(100, 17, "About");
						SetColor(0);
						drawButton(100, 20, "SOUND");
						drawButton(100, 23, "RANKING");
						drawButton(100, 26, "EXIT");
					}
					if (y == 25)
					{
						SetColor(0);
						drawButton(100, 5, "PLAYER VS PLAYER");
						drawButton(100, 8, "PLAYER VS COMPUTER");
						drawButton(100, 11, "LOAD GAME");
						drawButton(100, 14, "HELP");
						drawButton(100, 17, "About");
						SetColor(4);
						drawButton(100, 20, "SOUND");
						SetColor(0);
						drawButton(100, 23, "RANKING");
						drawButton(100, 26, "EXIT");
					}
					if (y == 26)
					{
						SetColor(0);
						drawButton(100, 5, "PLAYER VS PLAYER");
						drawButton(100, 8, "PLAYER VS COMPUTER");
						drawButton(100, 11, "LOAD GAME");
						drawButton(100, 14, "HELP");
						drawButton(100, 17, "About");
						
						drawButton(100, 20, "SOUND");
						SetColor(4);
						drawButton(100, 23, "RANKING");
						SetColor(0);
						drawButton(100, 26, "EXIT");
					}
					if (y == 27)
					{
						SetColor(0);
						drawButton(100, 5, "PLAYER VS PLAYER");
						drawButton(100, 8, "PLAYER VS COMPUTER");
						drawButton(100, 11, "LOAD GAME");
						drawButton(100, 14, "HELP");
						drawButton(100, 17, "About");
						drawButton(100, 20, "SOUND");
						drawButton(100, 23, "RANKING");
						SetColor(4);
						drawButton(100, 26, "EXIT");
					}
					break;
				case KEY_ARROW_UP:
					if (y > 20)
					{
						y--;
						GotoXY(x, y);
					}
					if (y == 20)
					{
						SetColor(4);
						drawButton(100, 5, "PLAYER VS PLAYER");
						SetColor(0);
						drawButton(100, 8, "PLAYER VS COMPUTER");
						drawButton(100, 11, "LOAD GAME");
						drawButton(100, 14, "HELP");
						drawButton(100, 17, "About");
						drawButton(100, 20, "SOUND");
						drawButton(100, 26, "EXIT");
					}
					if (y == 21)
					{
						SetColor(0);
						drawButton(100, 5, "PLAYER VS PLAYER");
						SetColor(4);
						drawButton(100, 8, "PLAYER VS COMPUTER");
						SetColor(0);
						drawButton(100, 11, "LOAD GAME");
						drawButton(100, 14, "HELP");
						drawButton(100, 17, "About");
						drawButton(100, 20, "SOUND");
						drawButton(100, 26, "EXIT");
					}
					if (y == 22)
					{
						SetColor(0);
						drawButton(100, 5, "PLAYER VS PLAYER");
						drawButton(100, 8, "PLAYER VS COMPUTER");
						SetColor(4);
						drawButton(100, 11, "LOAD GAME");
						SetColor(0);
						drawButton(100, 14, "HELP");
						drawButton(100, 17, "About");
						drawButton(100, 20, "SOUND");
						drawButton(100, 26, "EXIT");
					}
					if (y == 23)
					{
						SetColor(0);
						drawButton(100, 5, "PLAYER VS PLAYER");
						drawButton(100, 8, "PLAYER VS COMPUTER");
						drawButton(100, 11, "LOAD GAME");
						SetColor(4);
						drawButton(100, 14, "HELP");
						SetColor(0);
						drawButton(100, 17, "About");
						drawButton(100, 20, "SOUND");
						drawButton(100, 26, "EXIT");
					}
					if (y == 24)
					{
						SetColor(0);
						drawButton(100, 5, "PLAYER VS PLAYER");
						drawButton(100, 8, "PLAYER VS COMPUTER");
						drawButton(100, 11, "LOAD GAME");
						drawButton(100, 14, "HELP");
						SetColor(4);
						drawButton(100, 17, "About");
						SetColor(0);
						drawButton(100, 20, "SOUND");
						drawButton(100, 26, "EXIT");
					}
					if (y == 25)
					{
						SetColor(0);
						drawButton(100, 5, "PLAYER VS PLAYER");
						drawButton(100, 8, "PLAYER VS COMPUTER");
						drawButton(100, 11, "LOAD GAME");
						drawButton(100, 14, "HELP");
						drawButton(100, 17, "About");
						SetColor(4);
						drawButton(100, 20, "SOUND");
						SetColor(0);
						drawButton(100, 26, "EXIT");
					}
					if (y == 26)
					{
						SetColor(0);
						drawButton(100, 5, "PLAYER VS PLAYER");
						drawButton(100, 8, "PLAYER VS COMPUTER");
						drawButton(100, 11, "LOAD GAME");
						drawButton(100, 14, "HELP");
						drawButton(100, 17, "About");
						SetColor(4);
						drawButton(100, 20, "SOUND");
						SetColor(0);
						drawButton(100, 26, "EXIT");
					}
					break;
				case KEY_ARROW_DOWN:
					if (y < 26)
					{
						y++;
						GotoXY(x, y);
					}
					if (y == 20)
					{
						SetColor(4);
						drawButton(100, 5, "PLAYER VS PLAYER");
						SetColor(0);
						drawButton(100, 8, "PLAYER VS COMPUTER");
						drawButton(100, 11, "LOAD GAME");
						drawButton(100, 14, "HELP");
						drawButton(100, 17, "About");
						drawButton(100, 20, "SOUND");
						drawButton(100, 26, "EXIT");
					}
					if (y == 21)
					{
						SetColor(0);
						drawButton(100, 5, "PLAYER VS PLAYER");
						SetColor(4);
						drawButton(100, 8, "PLAYER VS COMPUTER");
						SetColor(0);
						drawButton(100, 11, "LOAD GAME");
						drawButton(100, 14, "HELP");
						drawButton(100, 17, "About");
						drawButton(100, 20, "SOUND");
						drawButton(100, 26, "EXIT");
					}
					if (y == 22)
					{
						SetColor(0);
						drawButton(100, 5, "PLAYER VS PLAYER");
						drawButton(100, 8, "PLAYER VS COMPUTER");
						SetColor(4);
						drawButton(100, 11, "LOAD GAME");
						SetColor(0);
						drawButton(100, 14, "HELP");
						drawButton(100, 17, "About");
						drawButton(100, 20, "SOUND");
						drawButton(100, 26, "EXIT");
					}
					if (y == 23)
					{
						SetColor(0);
						drawButton(100, 5, "PLAYER VS PLAYER");
						drawButton(100, 8, "PLAYER VS COMPUTER");
						drawButton(100, 11, "LOAD GAME");
						SetColor(4);
						drawButton(100, 14, "HELP");
						SetColor(0);
						drawButton(100, 17, "About");
						drawButton(100, 20, "SOUND");
						drawButton(100, 26, "EXIT");
					}
					if (y == 24)
					{
						SetColor(0);
						drawButton(100, 5, "PLAYER VS PLAYER");
						drawButton(100, 8, "PLAYER VS COMPUTER");
						drawButton(100, 11, "LOAD GAME");
						drawButton(100, 14, "HELP");
						SetColor(4);
						drawButton(100, 17, "About");
						SetColor(0);
						drawButton(100, 20, "SOUND");
						drawButton(100, 26, "EXIT");
					}
					if (y == 25)
					{
						SetColor(0);
						drawButton(100, 5, "PLAYER VS PLAYER");
						drawButton(100, 8, "PLAYER VS COMPUTER");
						drawButton(100, 11, "LOAD GAME");
						drawButton(100, 14, "HELP");
						drawButton(100, 17, "About");
						SetColor(4);
						drawButton(100, 20, "SOUND");
						SetColor(0);
						drawButton(100, 26, "EXIT");
					}
					if (y == 26)
					{
						SetColor(0);
						drawButton(100, 5, "PLAYER VS PLAYER");
						drawButton(100, 8, "PLAYER VS COMPUTER");
						drawButton(100, 11, "LOAD GAME");
						drawButton(100, 14, "HELP");
						drawButton(100, 17, "About");
						drawButton(100, 20, "SOUND");
						SetColor(4);
						drawButton(100, 26, "EXIT");
					}
					break;
				case 13:
					backToOriginalMenu = true;
					//PlaySOUNDEffect("tick"); // khong biet truyen tham so gi nen truyen dai, sau nay sua
					if (y == 20)
					{
						vsComputer = false;
						SetPlayer(_PLAYER1, _PLAYER2);
						Loading();
						TextColor(255);
						StartGame(_A, _TURN, _COMMAND, _X, _Y, _PLAYER1, _PLAYER2, vsComputer);
						RunGame(_A, _PLAYER1, _PLAYER2, _TURN, _COMMAND, _X, _Y, MO_NHAC, chedo);
					}
					if (y == 21)
					{
						vsComputer = true;
						Loading();
						TextColor(255);
						StartGame(_A, _TURN, _COMMAND, _X, _Y, _PLAYER1, _PLAYER2, vsComputer);
						PlayWithComputer(_A, _TURN, _COMMAND, _PLAYER1, _PLAYER2, _X, _Y, validEnter, MO_NHAC, chedo);
						//Danh voi may
					}
					if (y == 22)
					{
						for (int i = 6; i < 28; i++)
						{
							for (int j = 6; j < 80; j++)
							{
								GotoXY(j, i);
								cout << " ";

							}
						}
						SetColor(0);
						printCaro(6, 4);
						GotoXY(10, 10);
						//Loading();
						TextColor(255);
						int loadOption;
						loadOption = SelectMenu(LoadingMenu());
						if (loadOption == -1) break;
						else
						{
							Loading();
							TextColor(255);
							LoadGame(RunLoadingMenu(loadOption), _A, _PLAYER1, _PLAYER2, _TURN, _COMMAND, _X, _Y, chedo);
							if (chedo == 2)
								RunGame(_A, _PLAYER1, _PLAYER2, _TURN, _COMMAND, _X, _Y, MO_NHAC, chedo);
							if(chedo == 3)
								PlayWithComputer(_A, _TURN, _COMMAND, _PLAYER1, _PLAYER2, _X, _Y, validEnter, MO_NHAC, chedo);
							break;
						}
					}
					if (y == 23)
					{
						//Menu HELP trong game
						for (int i = 6; i < 28; i++)
						{
							for (int j = 6; j < 80; j++)
							{
								GotoXY(j, i);
								cout << " ";

							}
						}
						SetColor(0);
						printCaro(6, 4);
						GotoXY(10, 10);
						//Loading();
						TextColor(255);
						HELP();
					}
					if (y == 24)
					{
						//About
						for (int i = 6; i < 28; i++)
						{
							for (int j = 6; j < 80; j++)
							{
								GotoXY(j, i);
								cout << " ";

							}
						}
						SetColor(0);
						printCaro(20,10);
						GotoXY(10, 10);
						//Loading();
						About();
					}
					if (y == 25)
					{
						//SOUND
						//Loading();
						TextColor(255);
						Sound(MO_NHAC);
					}
					if (y == 26)
					{
						// Hiện ranking ở đây
					}
					if (y == 27)
					{
						//Loading();
						TextColor(255);
						system("cls");
						exit(0);
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
		DrawBigText("X.txt", 1, start, 3);
		DrawBigText("O.txt", 255, start + 40, 3);
	}
	else if ((_TURN) == 0)
	{
		DrawBigText("O.txt", 2, start + 40, 3);
		DrawBigText("X.txt", 255, start, 3);
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
_MENU YesNoMenu(int x, int y)
{
	_MENU menu;

	menu.options = 2;
	menu.x = x;
	menu.y = y;
	menu.cursorColor = 0;

	PrintText("Yes", 0, menu.x-18, menu.y-9);
	PrintText("No", 0, menu.x-18, menu.y -8);

	return menu;
}
_MENU LoadingMenu()
{
	_MENU menu;
	string name;


	std::vector<string> files;
	files = LoadFiles();

	menu.options = files.size();
	menu.x = X_CENTER - 13;
	menu.y = Y_CENTER + 11 - files.size() / 2;
	menu.cursorColor = 1;
	system("cls");
	drawFrame(5, 3, 80, 28);
	SetColor(0);
	printCaro(27, 7);
	GotoXY(10, 10);
	drawFrame(0, 0, 145, 33);
	PrintText("Press ESC to return to MENU...", 8, 30, 28);
	//DrawBox(221, 100, menu.options + 10, X_CENTER - 50, Y_CENTER - 5);
	//PrintText("[==========Saved Games===========]", 0, menu.x-30, menu.y - 10);
	drawButton(menu.x - 25, menu.y - 10, "Saved Games");
	for (int i = 0; i < files.size(); i++)
	{
		name = "         " + files.at(i);
		PrintText(name, 0, menu.x-27, menu.y + i-7);
	}
	GotoXY(38, 27);
	return menu;
}
_MENU EscMenu(_POINT _A[][BOARD_SIZE])
{
	_MENU menu;
	menu.options = 3;
	//menu.x = _A[0][BOARD_SIZE - 1].x +40;
	//menu.y = Y_CENTER;
	menu.x = 117;
	menu.y = 30;
	// x = 74, y = 16 la toa do goc cua menu esc
	// 60 la do rong, 17 la do dai menu
	for (int i = 16; i <= 32; i++)
	{
		GotoXY(75, i);
		cout << "                                                       ";
	}
	drawFrame(74, 16,60, 17);
	menu.cursorColor = 75;
	//DrawBoard(1, 1, 62, 25, menu.x - 23, menu.y - 19);
	//DrawBox(75, 63, 25, menu.x - 23, menu.y - 19);
	//DrawBigText("EscLogo.txt", 75, menu.x - 22, menu.y - 17);
	drawButton((menu.x-23), (menu.y-10), "Continue");
	//PrintText("    Continue    ", 0, menu.x-22, menu.y-9);
	//PrintText("    Save game   ", 0, menu.x-22, menu.y -8);
	drawButton((menu.x - 23), (menu.y - 7), "Save game");
	//PrintText("    Sound       ", 0, menu.x - 22, menu.y - 7);
	//PrintText("    Exit game   ", 0, menu.x-22, menu.y -7);
	drawButton((menu.x - 23), (menu.y - 4), "Exit game");
	return menu;
}
void ShowPlayerInfo(_POINT _A[][BOARD_SIZE], _PLAYER _PLAYER1, _PLAYER _PLAYER2)
{
	int start = _A[0][BOARD_SIZE - 1].x + 4;

	//DrawBoard(3, 3, 10, 1, start, 17);
}
void HELP()
{
	SetColor(245); //Day la mot mau ngau nhien, can chinh lai mau khac dep hon
	GotoXY(10, 14);
	cout << "HUONG DAN" << endl;
	GotoXY(10, 15);
	cout << "1. Ban co gom 16x16 o vuong." << endl;
	GotoXY(10, 16);
	cout << "2. Su dung cac phim W A S D de di chuyen va Enter de danh." << endl;
	GotoXY(10, 17);
	cout << "3. Luat choi cu du 5 quan co X hoac O theo hang ngang, doc, cheo se " << endl;
	GotoXY(10, 18);
	cout << "chien thang.";
	GotoXY(10, 19);
	cout << "4. Luat choi tuan theo quy dinh chan 2 dau " << endl;
	GotoXY(10, 20);
	cout << "-> Chuc moi nguoi choi game vui ve !!" << endl;
	PrintText("Press ESC to return to MENU...", 8, 50, 28);
	char command = ' ';
	command = _getch();
}
void About()
{
	SetColor(100);
	GotoXY(20, 18);
	cout << "DO AN GAME CARO - LOP 22CTT4 - HCMUS" << endl;
	GotoXY(20, 20);
	cout << "-> Ho ten : NGUYEN DUY LAM " << "| 22120181 "<< "| 22CTT4"<< endl;
	GotoXY(20, 21);
	cout << "-> Ho ten : DOAN THI MINH ANH " << "| 22120213 "<< "| 22CTT4"<< endl;
	GotoXY(20, 22);
	cout << "-> Ho ten : NGUYEN THI TU NGOC " << "| 22120233 "<< "| 22CTT4"<< endl;
	GotoXY(20, 23);
	cout << "-> Ho ten : TANG SENH MANH " << "| 22120202 " << "| 22CTT4"<< endl;
	GotoXY(20, 25);
	cout << "-> GV huong dan : Truong Toan Thinh " << endl;
	GotoXY(20, 26);
	cout << "-> Chuc moi nguoi choi game vui ve !!" << endl;
	PrintText("Press ESC to return to MENU...", 8, 50, 28);
	char command = ' ';
	command = _getch();
}

void Sound(bool& MO_NHAC)
{
	system("cls");
	drawFrame(5, 3, 80, 28);
	SetColor(0);
	printCaro(27,10);
	GotoXY(10, 10);
	drawFrame(0, 0, 145, 33);
	SetColor(100);
	int x = 0, y = 0;
	int i;
	bool backToOriginalMenu = false;
	int song = 0;
	while (!backToOriginalMenu)
	{
		backToOriginalMenu = false;
		x = 50, y = 20;
		SetColor(4);
		drawButton(100, 8, "Tat nhac nen");
		SetColor(0);
		drawButton(100, 11, "Bat nhac nen");
		drawButton(100, 14, "Doi bai");
		drawButton(100, 17, "Tat hieu ung am thanh");
		drawButton(100, 20, "Back");
		SetColor(8);
		GotoXY(98, 29); cout << "_____ W A S D: MOVE _____";
		GotoXY(98, 30); cout << "_____ Enter: Select _____";
		//if (n == 100)
		//{
		//	
		//}
		while (true)
		{
			if (_kbhit())
			{
				switch (_getch())
				{
				case 'w':
					if (y > 20)
					{
						y--;
						GotoXY(x, y);
					}
					if (y == 20)
					{
						SetColor(4);
						drawButton(100, 8, "Tat nhac nen");
						SetColor(0);
						drawButton(100, 11, "Bat nhac nen");
						drawButton(100, 14, "Doi bai");
						drawButton(100, 17, "Tat hieu ung am thanh");
						drawButton(100, 20, "Back");
					}
					if (y == 21)
					{
						SetColor(0);
						drawButton(100, 8, "Tat nhac nen");
						SetColor(4);
						drawButton(100, 11, "Bat nhac nen");
						SetColor(0);
						drawButton(100, 14, "Doi bai");
						drawButton(100, 17, "Tat hieu ung am thanh");
						drawButton(100, 20, "Back");
					}
					if (y == 22)
					{
						SetColor(0);
						drawButton(100, 8, "Tat nhac nen");
						drawButton(100, 11, "Bat nhac nen");
						SetColor(4);
						drawButton(100, 14, "Doi bai");
						SetColor(0);
						drawButton(100, 17, "Tat hieu ung am thanh");
						drawButton(100, 20, "Back");
					}
					if (y == 23)
					{
						SetColor(0);
						drawButton(100, 8, "Tat nhac nen");
						drawButton(100, 11, "Bat nhac nen");
						drawButton(100, 14, "Doi bai");
						SetColor(4);
						drawButton(100, 17, "Tat hieu ung am thanh");
						SetColor(0);
						drawButton(100, 20, "Back");
					}
					if (y == 24)
					{
						drawButton(100, 8, "Tat nhac nen");
						drawButton(100, 11, "Bat nhac nen");
						SetColor(4);
						drawButton(100, 14, "Doi bai");
						drawButton(100, 17, "Tat hieu ung am thanh");
						SetColor(0);
						drawButton(100, 20, "Back");
					}
					break;
				case 's':
					if (y < 24)
					{
						y++;
						GotoXY(x, y);
					}
					if (y == 20)
					{
						SetColor(4);
						drawButton(100, 8, "Tat nhac nen");
						SetColor(0);
						drawButton(100, 11, "Bat nhac nen");
						drawButton(100, 14, "Doi bai");
						drawButton(100, 17, "Tat hieu ung am thanh");
						drawButton(100, 20, "Back");
					}
					if (y == 21)
					{
						SetColor(0);
						drawButton(100, 8, "Tat nhac nen");
						SetColor(4);
						drawButton(100, 11, "Bat nhac nen");
						SetColor(0);
						drawButton(100, 14, "Doi bai");
						drawButton(100, 17, "Tat hieu ung am thanh");
						drawButton(100, 20, "Back");
					}
					if (y == 22)
					{
						SetColor(0);
						drawButton(100, 8, "Tat nhac nen");
						drawButton(100, 11, "Bat nhac nen");
						SetColor(4);
						drawButton(100, 14, "Doi bai");
						SetColor(0);
						drawButton(100, 17, "Tat hieu ung am thanh");
						drawButton(100, 20, "Back");
					}
					if (y == 23)
					{
						SetColor(0);
						drawButton(100, 8, "Tat nhac nen");
						drawButton(100, 11, "Bat nhac nen");
						drawButton(100, 14, "Doi bai");
						SetColor(4);
						drawButton(100, 17, "Tat hieu ung am thanh");
						SetColor(0);
						drawButton(100, 20, "Back");
					}
					if (y == 24)
					{
						SetColor(0);
						drawButton(100, 8, "Tat nhac nen");
						drawButton(100, 11, "Bat nhac nen");
						drawButton(100, 14, "Doi bai");
						drawButton(100, 17, "Tat hieu ung am thanh");
						SetColor(4);
						drawButton(100, 20, "Back");
					}
					break;
				case KEY_ARROW_UP:
					if (y > 20)
					{
						y--;
						GotoXY(x, y);
					}
					if (y == 20)
					{
						SetColor(4);
						drawButton(100, 8, "Tat nhac nen");
						SetColor(0);
						drawButton(100, 11, "Bat nhac nen");
						drawButton(100, 14, "Doi bai");
						drawButton(100, 17, "Tat hieu ung am thanh");
						drawButton(100, 20, "Back");
					}
					if (y == 21)
					{
						SetColor(0);
						drawButton(100, 8, "Tat nhac nen");
						SetColor(4);
						drawButton(100, 11, "Bat nhac nen");
						SetColor(0);
						drawButton(100, 14, "Doi bai");
						drawButton(100, 17, "Tat hieu ung am thanh");
						drawButton(100, 20, "Back");
					}
					if (y == 22)
					{
						SetColor(0);
						drawButton(100, 8, "Tat nhac nen");
						drawButton(100, 11, "Bat nhac nen");
						SetColor(4);
						drawButton(100, 14, "Doi bai");
						SetColor(0);
						drawButton(100, 17, "Tat hieu ung am thanh");
						drawButton(100, 20, "Back");
					}
					if (y == 23)
					{
						SetColor(0);
						drawButton(100, 8, "Tat nhac nen");
						drawButton(100, 11, "Bat nhac nen");
						drawButton(100, 14, "Doi bai");
						SetColor(4);
						drawButton(100, 17, "Tat hieu ung am thanh");
						SetColor(0);
						drawButton(100, 20, "Back");
					}
					if (y == 24)
					{
						drawButton(100, 8, "Tat nhac nen");
						drawButton(100, 11, "Bat nhac nen");
						SetColor(4);
						drawButton(100, 14, "Doi bai");
						drawButton(100, 17, "Tat hieu ung am thanh");
						SetColor(0);
						drawButton(100, 20, "Back");
					}
					break;
				case KEY_ARROW_DOWN:
					if (y < 24)
					{
						y++;
						GotoXY(x, y);
					}
					if (y == 20)
					{
						SetColor(4);
						drawButton(100, 8, "Tat nhac nen");
						SetColor(0);
						drawButton(100, 11, "Bat nhac nen");
						drawButton(100, 14, "Doi bai");
						drawButton(100, 17, "Tat hieu ung am thanh");
						drawButton(100, 20, "Back");
					}
					if (y == 21)
					{
						SetColor(0);
						drawButton(100, 8, "Tat nhac nen");
						SetColor(4);
						drawButton(100, 11, "Bat nhac nen");
						SetColor(0);
						drawButton(100, 14, "Doi bai");
						drawButton(100, 17, "Tat hieu ung am thanh");
						drawButton(100, 20, "Back");
					}
					if (y == 22)
					{
						SetColor(0);
						drawButton(100, 8, "Tat nhac nen");
						drawButton(100, 11, "Bat nhac nen");
						SetColor(4);
						drawButton(100, 14, "Doi bai");
						SetColor(0);
						drawButton(100, 17, "Tat hieu ung am thanh");
						drawButton(100, 20, "Back");
					}
					if (y == 23)
					{
						SetColor(0);
						drawButton(100, 8, "Tat nhac nen");
						drawButton(100, 11, "Bat nhac nen");
						drawButton(100, 14, "Doi bai");
						SetColor(4);
						drawButton(100, 17, "Tat hieu ung am thanh");
						SetColor(0);
						drawButton(100, 20, "Back");
					}
					if (y == 24)
					{
						SetColor(0);
						drawButton(100, 8, "Tat nhac nen");
						drawButton(100, 11, "Bat nhac nen");
						drawButton(100, 14, "Doi bai");
						drawButton(100, 17, "Tat hieu ung am thanh");
						SetColor(4);
						drawButton(100, 20, "Back");
					}
					break;
				case 13:
					//PlaySoundEffect("tick"); // khong biet truyen tham so gi nen truyen dai, sau nay sua
					if (y == 20)
					{
						StopMusic();
						// Tat nhac nen
					}
					if (y == 21)
					{
						//Bat nhac nen
						PlayBackGroundMusic(song);
					}
					if (y == 22)
					{
						song++;
						PlayBackGroundMusic(song);
						//Doi bai
					}
					if (y == 23)
					{
						if (MO_NHAC)
							MO_NHAC = false;
						else
							MO_NHAC = true;
						//Doi bai
					}
					if (y == 24)
					{
						//Quay ve
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
	cout << (char)201;
	for (int i = 0;i < 58;i++)
		cout << (char)205;
	cout << (char)187;
	for(int i=1;i<16;i++)
	{
		GotoXY(x, y + i);
		cout << (char)186;
		GotoXY(x + 59, y + i);
		cout << (char)186;
	}
	GotoXY(x, y + 16);
	cout << (char)200;
	for (int i = 0;i < 58;i++)
		cout << (char)205;
	cout << (char)188;
}

void DrawPhimTat(_POINT _A[][BOARD_SIZE])
{
	int x = _A[0][BOARD_SIZE].x + 78;
	int y = _A[0][BOARD_SIZE].y + 17;
	ShowCur(0);
	/*for (int i = 0;i < 8;i++)
	{
		GotoXY(x, y);
		SetColor(rand() % 15 + 1);
		cout << "     _____";
		GotoXY(x + 17, y);
		SetColor(rand() % 15 + 1);
		cout << "     _____";
		GotoXY(x + 34, y);
		SetColor(rand() % 15 + 1);
		cout << "	 _____";
		GotoXY(x + 8, y + 7);
		SetColor(rand() % 15 + 1);
		cout << " __________________________";
		Sleep(30);
		GotoXY(x, y + 1);
		SetColor(rand() % 15 + 1);
		cout << "    |\\ ___\\";
		GotoXY(x + 17, y + 1);
		SetColor(rand() % 15 + 1);
		cout << "    |\\ ___\\";
		GotoXY(x + 34, y + 1);
		SetColor(rand() % 15 + 1);
		cout << "	|\\____\\";
		GotoXY(x + 8, y + 8);
		SetColor(rand() % 15 + 1);
		cout << "|\\          Space          \\";
		Sleep(30);
		GotoXY(x, y + 2);
		SetColor(rand() % 15 + 1);
		cout << " ___| | W |__";
		GotoXY(x + 17, y + 2);
		SetColor(rand() % 15 + 1);
		cout << " ___| | ^ |__";
		GotoXY(x + 34, y + 2);
		SetColor(rand() % 15 + 1);
		cout << " _____||    |";
		GotoXY(x + 8, y + 9);
		SetColor(rand() % 15 + 1);
		cout << "\\ \\_________________________\\";
		Sleep(30);
		GotoXY(x, y + 3);
		SetColor(rand() % 15 + 1);
		cout << "|\\ __\\|___| _\\ ";
		GotoXY(x + 17, y + 3);
		SetColor(rand() % 15 + 1);
		cout << "|\\ __\\|___| _\\ ";
		GotoXY(x + 34, y + 3);
		SetColor(rand() % 15 + 1);
		cout << "|\\ ___\\|    | ";
		GotoXY(x + 8, y + 10);
		SetColor(rand() % 15 + 1);
		cout << " \\|_________________________|";
		Sleep(30);
		GotoXY(x, y + 4);
		SetColor(rand() % 15 + 1);
		cout << "| | A | S | D |";
		GotoXY(x + 17, y + 4);
		SetColor(rand() % 15 + 1);
		cout << "| | < | v | > |";
		GotoXY(x + 34, y + 4);
		SetColor(rand() % 15 + 1);
		cout << "| |  Enter  |";
		Sleep(30);
		GotoXY(x, y + 5);
		SetColor(rand() % 15 + 1);
		cout << " \\|___|___|___|";
		GotoXY(x + 17, y + 5);
		SetColor(rand() % 15 + 1);
		cout << " \\|___|___|___|";
		GotoXY(x + 34, y + 5);
		SetColor(rand() % 15 + 1);
		cout << " \\|_________|";
		Sleep(30);

	}*/
	
	SetColor(16);
	GotoXY(x, y);
	cout << "     _____";
	GotoXY(x, y + 1);
	cout << "    |\\ ___\\";
	GotoXY(x, y + 2);
	cout << " ___| | W |__";
	GotoXY(x, y + 3);
	cout << "|\\ __\\|___| _\\ ";
	GotoXY(x, y + 4);
	cout << "| | A | S | D |";
	GotoXY(x, y + 5);
	cout << " \\|___|___|___|";
	GotoXY(x + 17, y);
	cout << "     _____";
	GotoXY(x + 17, y + 1);
	cout << "    |\\ ___\\";
	GotoXY(x + 17, y + 2);
	cout << " ___| | ^ |__";
	GotoXY(x + 17, y + 3);
	cout << "|\\ __\\|___| _\\ ";
	GotoXY(x + 17, y + 4);
	cout << "| | < | v | > |";
	GotoXY(x + 17, y + 5);
	cout << " \\|___|___|___|";
	GotoXY(x + 34, y);
	cout << "	 _____";
	GotoXY(x + 34, y + 1);
	cout << "	|\\____\\";
	GotoXY(x + 34, y + 2);
	cout << " _____||    |";
	GotoXY(x + 34, y + 3);
	cout << "|\\ ___\\|    | ";
	GotoXY(x + 34, y + 4);
	cout << "| |  Enter  |";
	GotoXY(x + 34, y + 5);
	cout << " \\|_________|";
	GotoXY(x + 8, y + 7);
	cout << " __________________________";
	GotoXY(x + 8, y + 8);
	cout << "|\\          Space          \\";
	GotoXY(x + 8, y + 9);
	cout << "\\ \\_________________________\\";
	GotoXY(x + 8, y + 10);
	cout << " \\|_________________________|";
	ShowCur(1);
}

void drawButton(int x, int y, string text)
{
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
void printCaro(int x, int y) {
	SetColor(0);
	GotoXY(x, y);
	cout << char(32) << char(219) << char(219) << char(219) << char(219) << char(219) << char(219) << char(187) << char(32) << char(219) << char(219) << char(219) << char(219) << char(219) << char(187) << char(32) << char(219) << char(219) << char(219) << char(219) << char(219) << char(219) << char(187) << char(32) << char(32) << char(219) << char(219) << char(219) << char(219) << char(219) << char(219) << char(187);
	GotoXY(x, y+1);
	cout << char(FULL) << char(FULL) << char(DOUBLE_TOP_LEFT) << char(DOUBLE_HORIZONTAL) << char(DOUBLE_HORIZONTAL) << char(DOUBLE_HORIZONTAL) << char(DOUBLE_HORIZONTAL) << char(DOUBLE_BOTTOM_RIGHT) << char(FULL) << char(FULL) << char(DOUBLE_TOP_LEFT) << char(DOUBLE_HORIZONTAL) << char(DOUBLE_HORIZONTAL) << char(FULL) << char(FULL) << char(DOUBLE_TOP_RIGHT) << char(FULL) << char(FULL) << char(DOUBLE_TOP_LEFT) << char(DOUBLE_HORIZONTAL) << char(DOUBLE_HORIZONTAL) << char(FULL) << char(FULL) << char(DOUBLE_TOP_RIGHT) << char(FULL) << char(FULL) << char(DOUBLE_TOP_LEFT) << char(DOUBLE_HORIZONTAL) << char(DOUBLE_HORIZONTAL) << char(DOUBLE_HORIZONTAL) << char(FULL) << char(FULL) << char(DOUBLE_TOP_RIGHT);
	GotoXY(x, y+2);
	cout << char(FULL) << char(FULL) << char(DOUBLE_VERTICAL) << char(SPACE) << char(SPACE) << char(SPACE) << char(SPACE) << char(SPACE) << char(FULL) << char(FULL) << char(FULL) << char(FULL) << char(FULL) << char(FULL) << char(FULL) << char(DOUBLE_VERTICAL) << char(FULL) << char(FULL) << char(FULL) << char(FULL) << char(FULL) << char(FULL) << char(DOUBLE_TOP_LEFT) << char(DOUBLE_BOTTOM_RIGHT) << char(FULL) << char(FULL) << char(DOUBLE_VERTICAL) << char(SPACE) << char(SPACE) << char(SPACE) << char(FULL) << char(FULL) << char(DOUBLE_VERTICAL);
	GotoXY(x, y+3);
	cout << char(FULL) << char(FULL) << char(DOUBLE_VERTICAL) << char(SPACE) << char(SPACE) << char(SPACE) << char(SPACE) << char(SPACE) << char(FULL) << char(FULL) << char(DOUBLE_TOP_LEFT) << char(DOUBLE_HORIZONTAL) << char(DOUBLE_HORIZONTAL) << char(FULL) << char(FULL) << char(DOUBLE_VERTICAL) << char(FULL) << char(FULL) << char(DOUBLE_TOP_LEFT) << char(DOUBLE_HORIZONTAL) << char(DOUBLE_HORIZONTAL) << char(FULL) << char(FULL) << char(DOUBLE_TOP_RIGHT) << char(FULL) << char(FULL) << char(DOUBLE_VERTICAL) << char(SPACE) << char(SPACE) << char(SPACE) << char(FULL) << char(FULL) << char(DOUBLE_VERTICAL);
	GotoXY(x, y+4);
	cout << char(DOUBLE_BOTTOM_LEFT) << char(FULL) << char(FULL) << char(FULL) << char(FULL) << char(FULL) << char(FULL) << char(DOUBLE_TOP_RIGHT) << char(FULL) << char(FULL) << char(DOUBLE_VERTICAL) << char(SPACE) << char(SPACE) << char(FULL) << char(FULL) << char(DOUBLE_VERTICAL) << char(FULL) << char(FULL) << char(DOUBLE_VERTICAL) << char(SPACE) << char(SPACE) << char(FULL) << char(FULL) << char(DOUBLE_VERTICAL) << char(DOUBLE_BOTTOM_LEFT) << char(FULL) << char(FULL) << char(FULL) << char(FULL) << char(FULL) << char(FULL) << char(DOUBLE_TOP_LEFT) << char(DOUBLE_BOTTOM_RIGHT);
	GotoXY(x, y+5);
	cout << char(SPACE) << char(DOUBLE_BOTTOM_LEFT) << char(DOUBLE_HORIZONTAL) << char(DOUBLE_HORIZONTAL) << char(DOUBLE_HORIZONTAL) << char(DOUBLE_HORIZONTAL) << char(DOUBLE_HORIZONTAL) << char(DOUBLE_BOTTOM_RIGHT) << char(DOUBLE_BOTTOM_LEFT) << char(DOUBLE_HORIZONTAL) << char(DOUBLE_BOTTOM_RIGHT) << char(SPACE) << char(SPACE) << char(DOUBLE_BOTTOM_LEFT) << char(DOUBLE_HORIZONTAL) << char(DOUBLE_BOTTOM_RIGHT) << char(DOUBLE_BOTTOM_LEFT) << char(DOUBLE_HORIZONTAL) << char(DOUBLE_BOTTOM_RIGHT) << char(SPACE) << char(SPACE) << char(DOUBLE_BOTTOM_LEFT) << char(DOUBLE_HORIZONTAL) << char(DOUBLE_BOTTOM_RIGHT) << char(SPACE) << char(DOUBLE_BOTTOM_LEFT) << char(DOUBLE_HORIZONTAL) << char(DOUBLE_HORIZONTAL) << char(DOUBLE_HORIZONTAL) << char(DOUBLE_HORIZONTAL) << char(DOUBLE_HORIZONTAL) << char(DOUBLE_BOTTOM_RIGHT) << char(SPACE);
	GotoXY(x, y+6);
	cout << "     ----  By Team 15  ----      ";
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
	GotoXY(x, y + 11);
	cout << "                        ----  By Team 15  ----";
}

// ██████╗ █████╗ ██████╗  ██████╗ 
//██╔════╝██╔══██╗██╔══██╗██╔═══██╗
//██║     ███████║██████╔╝██║   ██║
//██║     ██╔══██║██╔══██╗██║   ██║
//╚██████╗██║  ██║██║  ██║╚██████╔╝
// ╚═════╝╚═╝  ╚═╝╚═╝  ╚═╝ ╚═════╝ 

void Loading()
{
	system("cls");
	int x = 25;
	int y = 13;
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
	y = 13;
	x = 20;
	GotoXY(x+8, y);
	cout << "Loading . . .";
	TextColor(255);
	for (unsigned short int i = 1; i <= 10; ++i)
	{
		//textcolor(111);
		//SetColor(9);
		PrintText("        ", 0, x += 8, y + 1);
		//TextColor(0 +rand() % 100);
		//textcolor(111);
		//GotoXY(x+=8, y +1);
		//cout << "     ";
		TextColor(11);
		GotoXY(x+7, y+1);
		cout << i * 10 << "%";

		Sleep(10 + rand() % 500);
		GotoXY(x+7, y+1);
		cout << "       ";
	}
	Sleep(10);
	system("cls");
}



                                                       


                                            
