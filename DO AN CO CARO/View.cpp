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
		_PLAYER1.wins++;
		PlaySoundEffect("win.wav", MO_NHAC);
		NhapNhayQuanCo(_A, toadothang, pWhoWin);
		ThongBaoWin(pWhoWin, _A);
		//GotoXY(78,18); // Nhảy tới vị trí 
		//// thích hợp để in chuỗi thắng/thua/hòa
		////printf("Nguoi choi %d da thang va nguoi choi %d da thua\n", true, false);
		//cout << "Nguoi choi " << _PLAYER1.name << " da thang va nguoi choi " << _PLAYER2.name << " da thua.";
		SavePlayer(_PLAYER1);
		break;
	case 1:
		_PLAYER2.wins++;
		PlaySoundEffect("win", MO_NHAC);
		NhapNhayQuanCo(_A, toadothang, pWhoWin);
		ThongBaoWin(pWhoWin, _A);
		//GotoXY(78,18); // Nhảy tới vị trí 
		//// thích hợp để in chuỗi thắng/thua/hòa
		////printf("Nguoi choi %d da thang va nguoi choi %d da thua\n", false, true);
		//cout << "Nguoi choi " << _PLAYER2.name << " da thang va nguoi choi " << _PLAYER1.name << " da thua.";
		SavePlayer(_PLAYER2);
		break;
	case 0:
		//printf("Nguoi choi %d da hoa nguoi choi %d\n", false, true);
		ThongBaoWin(pWhoWin, _A);
		/*GotoXY(78,18);
		cout << "Nguoi choi " << _PLAYER2.name << " da hoa nguoi choi " << _PLAYER1.name;*/
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
}

void OWin(_POINT _A[][BOARD_SIZE])
{
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
}

void Draw(_POINT _A[][BOARD_SIZE])
{
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
	int x = 53;
	//printf("Nhan 'y/n' de tiep tuc/dung: ");
	GotoXY(x, 10+3); SetColor(3); for (int i = x; i <= x + 29; i++) cout << (char)178;
	GotoXY(x, 11+3); cout << (char)178 << "                            " << (char)178;
	GotoXY(x, 12+3); cout << (char)178 << "   Play again        Quit   " << (char)178;
	GotoXY(x, 13+3); cout << (char)178 << "                            " << (char)178;
	GotoXY(x, 14+3); SetColor(3); for (int i = x; i <= x + 29; i++) cout << (char)178;
	int choice = 0;
	int currentPos = 0;
	GotoXY(x + 4, 12+3);
	SetColor(4);
	cout << "Play again";
	SetColor(7);
	ShowCur(0);
	while (true) 
	{
		// Lấy phím người dùng ấn
		char key = _getch();

		// Kiểm tra phím người dùng ấn
		if (key == 'A' || key == 'a' || key == KEY_ARROW_LEFT) {
			choice = 0;
		}
		else if (key == 'D' || key == 'd' || key == KEY_ARROW_RIGHT) {
			choice = 1;
		}
		else if (key == '\r') {
			break;
		}

		// Đổi màu chữ tùy theo lựa chọn
		if (choice != currentPos) {
			if (choice == 0) {
				GotoXY(x + 4, 12+3);
				SetColor(4);
				cout << "Play again";
				SetColor(7);
				GotoXY(x + 22, 12+3);
				cout << "Quit";
				ShowCur(0);
			}
			else {
				GotoXY(x + 4, 12+3);
				cout << "Play again";
				GotoXY(x + 22, 12+3);
				SetColor(4);
				cout << "Quit";
				SetColor(7);
				ShowCur(0);
			}
			currentPos = choice;
		}
	}
	if (choice == 0)
		return 'Y';
	else
		return 'N';
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
		ShowCur(0);
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
						drawButton(100, 17, "ABOUT");
						drawButton(100, 20, "SOUND");
						drawButton(100, 23, "RANKING");
						drawButton(100, 26, "EXIT");
						ShowCur(0);
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
						drawButton(100, 17, "ABOUT");
						drawButton(100, 20, "SOUND");
						drawButton(100, 23, "RANKING");
						drawButton(100, 26, "EXIT");
						ShowCur(0);
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
						drawButton(100, 17, "ABOUT");
						drawButton(100, 20, "SOUND");
						drawButton(100, 23, "RANKING");
						drawButton(100, 26, "EXIT");
						ShowCur(0);
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
						drawButton(100, 17, "ABOUT");
						drawButton(100, 20, "SOUND");
						drawButton(100, 23, "RANKING");
						drawButton(100, 26, "EXIT");
						ShowCur(0);
					}
					if (y == 24)
					{
						SetColor(0);
						drawButton(100, 5, "PLAYER VS PLAYER");
						drawButton(100, 8, "PLAYER VS COMPUTER");
						drawButton(100, 11, "LOAD GAME");
						drawButton(100, 14, "HELP");
						SetColor(4);
						drawButton(100, 17, "ABOUT");
						SetColor(0);
						drawButton(100, 20, "SOUND");
						drawButton(100, 23, "RANKING");
						drawButton(100, 26, "EXIT");
						ShowCur(0);
					}
					if (y == 25)
					{
						SetColor(0);
						drawButton(100, 5, "PLAYER VS PLAYER");
						drawButton(100, 8, "PLAYER VS COMPUTER");
						drawButton(100, 11, "LOAD GAME");
						drawButton(100, 14, "HELP");
						drawButton(100, 17, "ABOUT");
						SetColor(4);
						drawButton(100, 20, "SOUND");
						SetColor(0);
						drawButton(100, 23, "RANKING");
						drawButton(100, 26, "EXIT");
						ShowCur(0);
					}
					if (y == 26)
					{
						SetColor(0);
						drawButton(100, 5, "PLAYER VS PLAYER");
						drawButton(100, 8, "PLAYER VS COMPUTER");
						drawButton(100, 11, "LOAD GAME");
						drawButton(100, 14, "HELP");
						drawButton(100, 17, "ABOUT");
						
						drawButton(100, 20, "SOUND");
						SetColor(4);
						drawButton(100, 23, "RANKING");
						SetColor(0);
						drawButton(100, 26, "EXIT");
						ShowCur(0);
					}
					if (y == 27)
					{
						SetColor(0);
						drawButton(100, 5, "PLAYER VS PLAYER");
						drawButton(100, 8, "PLAYER VS COMPUTER");
						drawButton(100, 11, "LOAD GAME");
						drawButton(100, 14, "HELP");
						drawButton(100, 17, "ABOUT");
						drawButton(100, 20, "SOUND");
						SetColor(4);
						drawButton(100, 23, "RANKING");
						SetColor(0);
						drawButton(100, 26, "EXIT");
						ShowCur(0);
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
						drawButton(100, 17, "ABOUT");
						drawButton(100, 20, "SOUND");
						drawButton(100, 23, "RANKING");
						drawButton(100, 26, "EXIT");
						ShowCur(0);
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
						drawButton(100, 17, "ABOUT");
						drawButton(100, 20, "SOUND");
						drawButton(100, 23, "RANKING");
						drawButton(100, 26, "EXIT");
						ShowCur(0);
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
						drawButton(100, 17, "ABOUT");
						drawButton(100, 20, "SOUND");
						drawButton(100, 23, "RANKING");
						drawButton(100, 26, "EXIT");
						ShowCur(0);
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
						drawButton(100, 17, "ABOUT");
						drawButton(100, 20, "SOUND");
						drawButton(100, 23, "RANKING");
						drawButton(100, 26, "EXIT");
						ShowCur(0);
					}
					if (y == 24)
					{
						SetColor(0);
						drawButton(100, 5, "PLAYER VS PLAYER");
						drawButton(100, 8, "PLAYER VS COMPUTER");
						drawButton(100, 11, "LOAD GAME");
						drawButton(100, 14, "HELP");
						SetColor(4);
						drawButton(100, 17, "ABOUT");
						SetColor(0);
						drawButton(100, 20, "SOUND");
						drawButton(100, 23, "RANKING");
						drawButton(100, 26, "EXIT");
						ShowCur(0);
					}
					if (y == 25)
					{
						SetColor(0);
						drawButton(100, 5, "PLAYER VS PLAYER");
						drawButton(100, 8, "PLAYER VS COMPUTER");
						drawButton(100, 11, "LOAD GAME");
						drawButton(100, 14, "HELP");
						drawButton(100, 17, "ABOUT");
						SetColor(4);
						drawButton(100, 20, "SOUND");
						SetColor(0);
						drawButton(100, 23, "RANKING");
						drawButton(100, 26, "EXIT");
						ShowCur(0);
					}
					if (y == 26)
					{
						SetColor(0);
						drawButton(100, 5, "PLAYER VS PLAYER");
						drawButton(100, 8, "PLAYER VS COMPUTER");
						drawButton(100, 11, "LOAD GAME");
						drawButton(100, 14, "HELP");
						drawButton(100, 17, "ABOUT");
						
						drawButton(100, 20, "SOUND");
						SetColor(4);
						drawButton(100, 23, "RANKING");
						SetColor(0);
						drawButton(100, 26, "EXIT");
						ShowCur(0);
					}
					if (y == 27)
					{
						SetColor(0);
						drawButton(100, 5, "PLAYER VS PLAYER");
						drawButton(100, 8, "PLAYER VS COMPUTER");
						drawButton(100, 11, "LOAD GAME");
						drawButton(100, 14, "HELP");
						drawButton(100, 17, "ABOUT");
						drawButton(100, 20, "SOUND");
						drawButton(100, 23, "RANKING");
						SetColor(4);
						drawButton(100, 26, "EXIT");
						ShowCur(0);
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
						drawButton(100, 17, "ABOUT");
						drawButton(100, 20, "SOUND");
						drawButton(100, 23, "RANKING");
						drawButton(100, 26, "EXIT");
						ShowCur(0);
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
						drawButton(100, 17, "ABOUT");
						drawButton(100, 20, "SOUND");
						drawButton(100, 23, "RANKING");
						drawButton(100, 26, "EXIT");
						ShowCur(0);
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
						drawButton(100, 17, "ABOUT");
						drawButton(100, 20, "SOUND");
						drawButton(100, 23, "RANKING");
						drawButton(100, 26, "EXIT");
						ShowCur(0);
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
						drawButton(100, 17, "ABOUT");
						drawButton(100, 20, "SOUND");
						drawButton(100, 23, "RANKING");
						drawButton(100, 26, "EXIT");
						ShowCur(0);
					}
					if (y == 24)
					{
						SetColor(0);
						drawButton(100, 5, "PLAYER VS PLAYER");
						drawButton(100, 8, "PLAYER VS COMPUTER");
						drawButton(100, 11, "LOAD GAME");
						drawButton(100, 14, "HELP");
						SetColor(4);
						drawButton(100, 17, "ABOUT");
						SetColor(0);
						drawButton(100, 20, "SOUND");
						drawButton(100, 23, "RANKING");
						drawButton(100, 26, "EXIT");
						ShowCur(0);
					}
					if (y == 25)
					{
						SetColor(0);
						drawButton(100, 5, "PLAYER VS PLAYER");
						drawButton(100, 8, "PLAYER VS COMPUTER");
						drawButton(100, 11, "LOAD GAME");
						drawButton(100, 14, "HELP");
						drawButton(100, 17, "ABOUT");
						SetColor(4);
						drawButton(100, 20, "SOUND");
						SetColor(0);
						drawButton(100, 23, "RANKING");
						drawButton(100, 26, "EXIT");
						ShowCur(0);
					}
					if (y == 26)
					{
						SetColor(0);
						drawButton(100, 5, "PLAYER VS PLAYER");
						drawButton(100, 8, "PLAYER VS COMPUTER");
						drawButton(100, 11, "LOAD GAME");
						drawButton(100, 14, "HELP");
						drawButton(100, 17, "ABOUT");

						drawButton(100, 20, "SOUND");
						SetColor(4);
						drawButton(100, 23, "RANKING");
						SetColor(0);
						drawButton(100, 26, "EXIT");
						ShowCur(0);
					}
					if (y == 27)
					{
						SetColor(0);
						drawButton(100, 5, "PLAYER VS PLAYER");
						drawButton(100, 8, "PLAYER VS COMPUTER");
						drawButton(100, 11, "LOAD GAME");
						drawButton(100, 14, "HELP");
						drawButton(100, 17, "ABOUT");
						drawButton(100, 20, "SOUND");
						SetColor(4);
						drawButton(100, 23, "RANKING");
						SetColor(0);
						drawButton(100, 26, "EXIT");
						ShowCur(0);
					}
					break;
				case KEY_ARROW_DOWN:
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
						drawButton(100, 17, "ABOUT");
						drawButton(100, 20, "SOUND");
						drawButton(100, 23, "RANKING");
						drawButton(100, 26, "EXIT");
						ShowCur(0);
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
						drawButton(100, 17, "ABOUT");
						drawButton(100, 20, "SOUND");
						drawButton(100, 23, "RANKING");
						drawButton(100, 26, "EXIT");
						ShowCur(0);
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
						drawButton(100, 17, "ABOUT");
						drawButton(100, 20, "SOUND");
						drawButton(100, 23, "RANKING");
						drawButton(100, 26, "EXIT");
						ShowCur(0);
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
						drawButton(100, 17, "ABOUT");
						drawButton(100, 20, "SOUND");
						drawButton(100, 23, "RANKING");
						drawButton(100, 26, "EXIT");
						ShowCur(0);
					}
					if (y == 24)
					{
						SetColor(0);
						drawButton(100, 5, "PLAYER VS PLAYER");
						drawButton(100, 8, "PLAYER VS COMPUTER");
						drawButton(100, 11, "LOAD GAME");
						drawButton(100, 14, "HELP");
						SetColor(4);
						drawButton(100, 17, "ABOUT");
						SetColor(0);
						drawButton(100, 20, "SOUND");
						drawButton(100, 23, "RANKING");
						drawButton(100, 26, "EXIT");
						ShowCur(0);
					}
					if (y == 25)
					{
						SetColor(0);
						drawButton(100, 5, "PLAYER VS PLAYER");
						drawButton(100, 8, "PLAYER VS COMPUTER");
						drawButton(100, 11, "LOAD GAME");
						drawButton(100, 14, "HELP");
						drawButton(100, 17, "ABOUT");
						SetColor(4);
						drawButton(100, 20, "SOUND");
						SetColor(0);
						drawButton(100, 23, "RANKING");
						drawButton(100, 26, "EXIT");
						ShowCur(0);
					}
					if (y == 26)
					{
						SetColor(0);
						drawButton(100, 5, "PLAYER VS PLAYER");
						drawButton(100, 8, "PLAYER VS COMPUTER");
						drawButton(100, 11, "LOAD GAME");
						drawButton(100, 14, "HELP");
						drawButton(100, 17, "ABOUT");

						drawButton(100, 20, "SOUND");
						SetColor(4);
						drawButton(100, 23, "RANKING");
						SetColor(0);
						drawButton(100, 26, "EXIT");
						ShowCur(0);
					}
					if (y == 27)
					{
						SetColor(0);
						drawButton(100, 5, "PLAYER VS PLAYER");
						drawButton(100, 8, "PLAYER VS COMPUTER");
						drawButton(100, 11, "LOAD GAME");
						drawButton(100, 14, "HELP");
						drawButton(100, 17, "ABOUT");
						drawButton(100, 20, "SOUND");
						drawButton(100, 23, "RANKING");
						SetColor(4);
						drawButton(100, 26, "EXIT");
						ShowCur(0);
					}
					break;
				case 13:
					backToOriginalMenu = true;
					//PlaySOUNDEffect("tick"); // khong biet truyen tham so gi nen truyen dai, sau nay sua
					if (y == 20)
					{
						ShowCur(1);
						vsComputer = false;
						SetPlayer(_PLAYER1, _PLAYER2);
						Loading();
						TextColor(255);
						StartGame(_A, _TURN, _COMMAND, _X, _Y, _PLAYER1, _PLAYER2, vsComputer);
						RunGame(_A, _PLAYER1, _PLAYER2, _TURN, _COMMAND, _X, _Y, MO_NHAC, chedo);
					}
					if (y == 21)
					{
						ShowCur(1);
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
						ShowCur(1);
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
						printCaro(27, 7);
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
						printCaro(27,7);
						GotoXY(10, 10);
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
						for (int i = 6; i < 28; i++)
						{
							for (int j = 6; j < 83; j++)
							{
								GotoXY(j, i);
								cout << " ";

							}
						}
						SetColor(0);
						printCaro(27, 7);
						// Hiện ranking ở đây
						ShowRank();
					}
					if (y == 27)
					{
						//Loading();
						TextColor(255);
						system("cls");
						exit(0);
					}
					break;
					case 32:
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
								if (chedo == 3)
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
							printCaro(27, 7);
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
							printCaro(27, 7);
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
		SetColor(1);
		GotoXY(start+5, 15);
		cout << "So quan X: " << CountX(_A);
		SetColor(247);
		GotoXY(start+46, 15);
		cout << "So quan O: " << CountO(_A);
		DrawBigText("X.txt", 1, start, 2);
		DrawBigText("O.txt", 247, start + 40, 2);
		//Them ten
		PrintText("PLAYER X: " + _PLAYER1.name, 1, start, 1);
		PrintText("PLAYER O: "+ _PLAYER2.name, 247, start + 42, 1);
		
	}
	else if ((_TURN) == 0)
	{
		SetColor(247);
		GotoXY(start+5, 15);
		cout << "So quan X: " << CountX(_A);
		SetColor(2);
		GotoXY(start + 46, 15);
		cout << "So quan O: " << CountO(_A);
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
	SetColor(252);
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
	GotoXY(20, 15);
	cout << "DO AN GAME CARO - LOP 22CTT4 - HCMUS" << endl;
	GotoXY(20, 17);
	cout << "Ho ten: NGUYEN DUY LAM     " << "| 22120181 " << "| 22CTT4"<< endl;
	GotoXY(20, 18);
	cout << "Ho ten: DOAN THI MINH ANH  " << "| 22120213 " << "| 22CTT4"<< endl;
	GotoXY(20, 19);
	cout << "Ho ten: NGUYEN THI TU NGOC " << "| 22120233 " << "| 22CTT4"<< endl;
	GotoXY(20, 20);
	cout << "Ho ten: TANG SENH MANH     " << "| 22120202 " << "| 22CTT4"<< endl;
	GotoXY(20, 22);
	cout << "__GV huong dan: Truong Toan Thinh__" << endl;
	GotoXY(20, 23);
	cout << "Chuc moi nguoi choi game vui ve!!" << endl;
	PrintText("Press ESC to return to MENU...", 8, 30, 28);
	char command = ' ';
	command = _getch();
}

void Sound(bool& MO_NHAC)
{
	system("cls");
	drawFrame(5, 3, 80, 28);
	SetColor(0);
	printCaro(27,7);
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
		drawButton(100, 8, "Turn OFF music");
		SetColor(0);
		drawButton(100, 11, "Turn ON music");
		drawButton(100, 14, "Change song");
		drawButton(100, 17, "ON/OFF sound effects");
		drawButton(100, 20, "Back");
		SetColor(8);
		GotoXY(98, 29); cout << "_____ W A S D: MOVE _____";
		GotoXY(98, 30); cout << "_____ Enter: Select _____"; ShowCur(0);
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
						drawButton(100, 8, "Turn OFF music");
						SetColor(0);
						drawButton(100, 11, "Turn ON music");
						drawButton(100, 14, "Change song");
						drawButton(100, 17, "ON/OFF sound effects");
						drawButton(100, 20, "Back"); ShowCur(0);
					}
					if (y == 21)
					{
						SetColor(0);
						drawButton(100, 8, "Turn OFF music");
						SetColor(4);
						drawButton(100, 11, "Turn ON music");
						SetColor(0);
						drawButton(100, 14, "Change song");
						drawButton(100, 17, "ON/OFF sound effects");
						drawButton(100, 20, "Back"); ShowCur(0);
					}
					if (y == 22)
					{
						SetColor(0);
						drawButton(100, 8, "Turn OFF music");
						drawButton(100, 11, "Turn ON music");
						SetColor(4);
						drawButton(100, 14, "Change song");
						SetColor(0);
						drawButton(100, 17, "ON/OFF sound effects");
						drawButton(100, 20, "Back"); ShowCur(0);
					}
					if (y == 23)
					{
						SetColor(0);
						drawButton(100, 8, "Turn OFF music");
						drawButton(100, 11, "Turn ON music");
						drawButton(100, 14, "Change song");
						SetColor(4);
						drawButton(100, 17, "ON/OFF sound effects");
						SetColor(0);
						drawButton(100, 20, "Back"); ShowCur(0);
					}
					if (y == 24)
					{
						drawButton(100, 8, "Turn OFF music");
						drawButton(100, 11, "Turn ON music");
						SetColor(4);
						drawButton(100, 14, "Change song");
						drawButton(100, 17, "ON/OFF sound effects");
						SetColor(0);
						drawButton(100, 20, "Back"); ShowCur(0);
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
						drawButton(100, 8, "Turn OFF music");
						SetColor(0);
						drawButton(100, 11, "Turn ON music");
						drawButton(100, 14, "Change song");
						drawButton(100, 17, "ON/OFF sound effects");
						drawButton(100, 20, "Back"); ShowCur(0);
					}
					if (y == 21)
					{
						SetColor(0);
						drawButton(100, 8, "Turn OFF music");
						SetColor(4);
						drawButton(100, 11, "Turn ON music");
						SetColor(0);
						drawButton(100, 14, "Change song");
						drawButton(100, 17, "ON/OFF sound effects");
						drawButton(100, 20, "Back"); ShowCur(0);
					}
					if (y == 22)
					{
						SetColor(0);
						drawButton(100, 8, "Turn OFF music");
						drawButton(100, 11, "Turn ON music");
						SetColor(4);
						drawButton(100, 14, "Change song");
						SetColor(0);
						drawButton(100, 17, "ON/OFF sound effects");
						drawButton(100, 20, "Back"); ShowCur(0);
					}
					if (y == 23)
					{
						SetColor(0);
						drawButton(100, 8, "Turn OFF music");
						drawButton(100, 11, "Turn ON music");
						drawButton(100, 14, "Change song");
						SetColor(4);
						drawButton(100, 17, "ON/OFF sound effects");
						SetColor(0);
						drawButton(100, 20, "Back"); ShowCur(0);
					}
					if (y == 24)
					{
						SetColor(0);
						drawButton(100, 8, "Turn OFF music");
						drawButton(100, 11, "Turn ON music");
						drawButton(100, 14, "Change song");
						drawButton(100, 17, "ON/OFF sound effects");
						SetColor(4);
						drawButton(100, 20, "Back"); ShowCur(0);
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
						drawButton(100, 8, "Turn OFF music");
						SetColor(0);
						drawButton(100, 11, "Turn ON music");
						drawButton(100, 14, "Change song");
						drawButton(100, 17, "ON/OFF sound effects");
						drawButton(100, 20, "Back"); ShowCur(0);
					}
					if (y == 21)
					{
						SetColor(0);
						drawButton(100, 8, "Turn OFF music");
						SetColor(4);
						drawButton(100, 11, "Turn ON music");
						SetColor(0);
						drawButton(100, 14, "Change song");
						drawButton(100, 17, "ON/OFF sound effects");
						drawButton(100, 20, "Back"); ShowCur(0);
					}
					if (y == 22)
					{
						SetColor(0);
						drawButton(100, 8, "Turn OFF music");
						drawButton(100, 11, "Turn ON music");
						SetColor(4);
						drawButton(100, 14, "Change song");
						SetColor(0);
						drawButton(100, 17, "ON/OFF sound effects");
						drawButton(100, 20, "Back"); ShowCur(0);
					}
					if (y == 23)
					{
						SetColor(0);
						drawButton(100, 8, "Turn OFF music");
						drawButton(100, 11, "Turn ON music");
						drawButton(100, 14, "Change song");
						SetColor(4);
						drawButton(100, 17, "ON/OFF sound effects");
						SetColor(0);
						drawButton(100, 20, "Back"); ShowCur(0);
					}
					if (y == 24)
					{
						drawButton(100, 8, "Turn OFF music");
						drawButton(100, 11, "Turn ON music");
						SetColor(4);
						drawButton(100, 14, "Change song");
						drawButton(100, 17, "ON/OFF sound effects");
						SetColor(0);
						drawButton(100, 20, "Back"); ShowCur(0);
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
						drawButton(100, 8, "Turn OFF music");
						SetColor(0);
						drawButton(100, 11, "Turn ON music");
						drawButton(100, 14, "Change song");
						drawButton(100, 17, "ON/OFF sound effects");
						drawButton(100, 20, "Back"); ShowCur(0);
					}
					if (y == 21)
					{
						SetColor(0);
						drawButton(100, 8, "Turn OFF music");
						SetColor(4);
						drawButton(100, 11, "Turn ON music");
						SetColor(0);
						drawButton(100, 14, "Change song");
						drawButton(100, 17, "ON/OFF sound effects");
						drawButton(100, 20, "Back"); ShowCur(0);
					}
					if (y == 22)
					{
						SetColor(0);
						drawButton(100, 8, "Turn OFF music");
						drawButton(100, 11, "Turn ON music");
						SetColor(4);
						drawButton(100, 14, "Change song");
						SetColor(0);
						drawButton(100, 17, "ON/OFF sound effects");
						drawButton(100, 20, "Back"); ShowCur(0);
					}
					if (y == 23)
					{
						SetColor(0);
						drawButton(100, 8, "Turn OFF music");
						drawButton(100, 11, "Turn ON music");
						drawButton(100, 14, "Change song");
						SetColor(4);
						drawButton(100, 17, "ON/OFF sound effects");
						SetColor(0);
						drawButton(100, 20, "Back"); ShowCur(0);
					}
					if (y == 24)
					{
						SetColor(0);
						drawButton(100, 8, "Turn OFF music");
						drawButton(100, 11, "Turn ON music");
						drawButton(100, 14, "Change song");
						drawButton(100, 17, "ON/OFF sound effects");
						SetColor(4);
						drawButton(100, 20, "Back"); ShowCur(0);
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
	int y = _A[0][BOARD_SIZE].y + 16;
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
	int a[10] = { 17,17,17,17,153,153,153,51,51,187 };
	int b[10] = { 31,31,31,31,159,159,159,63,63,191 };
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
		PrintText("        ", a[i-1], x += 8, y + 1);
		//TextColor(0 +rand() % 100);
		//textcolor(111);
		//GotoXY(x+=8, y +1);
		//cout << "     ";
		TextColor(b[i-1]);
		GotoXY(x+7, y+1);
		cout << i * 10 << "%";

		Sleep(10 + rand() % 500);
		GotoXY(x+7, y+1);
		cout << "       ";
	}
	Sleep(10);
	system("cls");
}
void ShowRank()
{
	int x = 35;
	int y = 13;
	std::vector<_PLAYER> players = GetPlayerList();

	PrintText("+------------------+", 253, x-2, y + 2);
	PrintText("| ~TOP 10 PLAYERS~ |", 253, x-2, y + 3);
	PrintText("+------------------+", 253, x-2, y + 4);
	PrintText("[Master King] " + players.at(0).name, 252, x - 2, y + 6);
	PrintText("[King] " + players.at(1).name, 251, x - 2, y + 7);
	for (int i = 2; i < 10; i++)
	{
		PrintText("[Master] " + players.at(i).name, 249, x - 2, y + 6 + i);
	}
	SetColor(8);
	GotoXY(30, 29);
	cout << "Press any key to continue";
	SetColor(0);
	char command = ' ';
	command = _getch();
}



                                                       


                                            
