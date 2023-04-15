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
void DrawBoard_1(int m, int n)
{
	int i, j;
	SetColor(0);
	printf("%c", 218);
	for (i = 0; i < n - 1; i++)
		printf("%c%c%c%c",196,196, 196, 194);
	printf("%c%c%c",196, 196, 196);
	printf("%c", 191);
	printf("\n");
	for (i = 0; i < m - 1; i++)
	{
		for (j = 0; j < n+ 1; j++)
			printf("%c   ", 179);
		printf("\n%c", 195);
		for (j = 0; j < n - 1; j++)
			printf("%c%c%c%c",196,196, 196, 197);
		printf("%c%c%c",196,196, 196);
		printf("%c\n", 180);
	}
	for (j = 0; j < n + 1; j++)
		printf("%c   ", 179);
	printf("\n%c", 192);
	for (i = 0; i < n - 1; i++)
		printf("%c%c%c%c",196,196, 196, 193);
	printf("%c%c%c",196,196, 196);
	printf("%c", 217);
}
int ProcessFinish(int pWhoWin, _POINT _A[][BOARD_SIZE], bool& _TURN, int& _X, int& _Y,short int toadothang[24], bool& MO_NHAC)
{
	_PLAYER _PLAYER1, _PLAYER2;
	switch (pWhoWin) {
	case -1:
		PlaySoundEffect("win", MO_NHAC);
		NhapNhayQuanCo(_A, toadothang, pWhoWin);
		GotoXY(0, _A[BOARD_SIZE - 1][BOARD_SIZE - 1].y + 2); // Nhảy tới vị trí 
		// thích hợp để in chuỗi thắng/thua/hòa
		printf("Nguoi choi %d da thang va nguoi choi %d da thua\n", true, false);
		break;
	case 1:
		PlaySoundEffect("win", MO_NHAC);
		NhapNhayQuanCo(_A, toadothang, pWhoWin);
		GotoXY(0, _A[BOARD_SIZE - 1][BOARD_SIZE - 1].y + 2); // Nhảy tới vị trí 
		// thích hợp để in chuỗi thắng/thua/hòa
		printf("Nguoi choi %d da thang va nguoi choi %d da thua\n", false, true);
		break;
	case 0:
		printf("Nguoi choi %d da hoa nguoi choi %d\n", false, true);
		break;
	case 2:
		_TURN = !_TURN; // Đổi lượt nếu không có gì xảy ra
		ShowTurn(_A, _PLAYER1, _PLAYER2, _TURN);
		break;
	}
	GotoXY(_X, _Y); // Trả về vị trí hiện hành của con trỏ màn hình bàn cờ
	return pWhoWin;
}
int AskContinue(_POINT _A[][BOARD_SIZE])
{
	GotoXY(0, _A[BOARD_SIZE - 1][BOARD_SIZE - 1].y + 4);
	printf("Nhan 'y/n' de tiep tuc/dung: ");
	return toupper(_getch());
}
void ScreenStartGame(int n, _POINT _A[][BOARD_SIZE], bool _TURN, int _COMMAND, int _X, int _Y, bool validEnter, bool& MO_NHAC)
{
	int song = 0;
	PlayBackGroundMusic(song);
	int x = 0, y = 0;
	drawFrame(0, 0, 145, 33);
	int i;
	_PLAYER _PLAYER1, _PLAYER2;
	bool backToOriginalMenu = false;
	x = 0; y = 0;
	while (true)
	{
		drawFrame(0, 0, 145, 33);
		TextColor(255);
		backToOriginalMenu = false;
		x = 100, y = 20;
		// color, width, height, x, y
		SetColor(150);
		//GotoXY(100, 3); cout << "Player Vs Player";
		drawButton(100, 5, "Player Vs Player");
		SetColor(0);
		drawButton(100, 8, "Player Vs Computer");
		drawButton(100, 11, "Load Game");
		drawButton(100, 14, "Help");
		drawButton(100, 17, "About");
		drawButton(100, 20, "Sound");
		drawButton(100, 23, "Exit");
		SetColor(8);
		GotoXY(90, 29); cout << "_____ W A S D: MOVE _____";
		GotoXY(90, 30); cout << "_____ Enter: Select _____" ;
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
						SetColor(150);
						drawButton(100, 5, "Player Vs Player");
						SetColor(0);
						drawButton(100, 8, "Player Vs Computer");
						drawButton(100, 11, "Load Game");
						drawButton(100, 14, "Help");
						drawButton(100, 17, "About");
						drawButton(100, 20, "Sound");
						drawButton(100, 23, "Exit");
					}
					if (y == 21)
					{
						SetColor(0);
						drawButton(100, 5, "Player Vs Player");
						SetColor(150);
						drawButton(100, 8, "Player Vs Computer");
						SetColor(0);
						drawButton(100, 11, "Load Game");
						drawButton(100, 14, "Help");
						drawButton(100, 17, "About");
						drawButton(100, 20, "Sound");
						drawButton(100, 23, "Exit");
					}
					if (y == 15)
					{
						SetColor(0);
						drawButton(100, 5, "Player Vs Player");
						drawButton(100, 8, "Player Vs Computer");
						SetColor(150);
						drawButton(100, 11, "Load Game");
						SetColor(0);
						drawButton(100, 14, "Help");
						drawButton(100, 17, "About");
						drawButton(100, 20, "Sound");
						drawButton(100, 23, "Exit");
					}
					if (y == 23)
					{
						SetColor(0);
						drawButton(100, 5, "Player Vs Player");
						drawButton(100, 8, "Player Vs Computer");
						drawButton(100, 11, "Load Game");
						SetColor(150);
						drawButton(100, 14, "Help");
						SetColor(0);
						drawButton(100, 17, "About");
						drawButton(100, 20, "Sound");
						drawButton(100, 23, "Exit");
					}
					if (y == 24)
					{
						SetColor(0);
						drawButton(100, 5, "Player Vs Player");
						drawButton(100, 8, "Player Vs Computer");
						drawButton(100, 11, "Load Game");
						drawButton(100, 14, "Help");
						SetColor(150);
						drawButton(100, 17, "About");
						SetColor(0);
						drawButton(100, 20, "Sound");
						drawButton(100, 23, "Exit");
					}
					if (y == 25)
					{
						SetColor(0);
						drawButton(100, 5, "Player Vs Player");
						drawButton(100, 8, "Player Vs Computer");
						drawButton(100, 11, "Load Game");
						drawButton(100, 14, "Help");
						drawButton(100, 17, "About");
						SetColor(150);
						drawButton(100, 20, "Sound");
						SetColor(0);
						drawButton(100, 23, "Exit");
					}
					if (y == 26)
					{
						SetColor(0);
						drawButton(100, 5, "Player Vs Player");
						drawButton(100, 8, "Player Vs Computer");
						drawButton(100, 11, "Load Game");
						drawButton(100, 14, "Help");
						drawButton(100, 17, "About");
						SetColor(150);
						drawButton(100, 20, "Sound");
						SetColor(0);
						drawButton(100, 23, "Exit");
					}
					break;
				case 's':
					if (y < 26)
					{
						y++;
						GotoXY(x, y);
					}
					if (y == 20)
					{
						SetColor(150);
						drawButton(100, 5, "Player Vs Player");
						SetColor(0);
						drawButton(100, 8, "Player Vs Computer");
						drawButton(100, 11, "Load Game");
						drawButton(100, 14, "Help");
						drawButton(100, 17, "About");
						drawButton(100, 20, "Sound");
						drawButton(100, 23, "Exit");
					}
					if (y == 21)
					{
						SetColor(0);
						drawButton(100, 5, "Player Vs Player");
						SetColor(150);
						drawButton(100, 8, "Player Vs Computer");
						SetColor(0);
						drawButton(100, 11, "Load Game");
						drawButton(100, 14, "Help");
						drawButton(100, 17, "About");
						drawButton(100, 20, "Sound");
						drawButton(100, 23, "Exit");
					}
					if (y == 22)
					{
						SetColor(0);
						drawButton(100, 5, "Player Vs Player");
						drawButton(100, 8, "Player Vs Computer");
						SetColor(150);
						drawButton(100, 11, "Load Game");
						SetColor(0);
						drawButton(100, 14, "Help");
						drawButton(100, 17, "About");
						drawButton(100, 20, "Sound");
						drawButton(100, 23, "Exit");
					}
					if (y == 23)
					{
						SetColor(0);
						drawButton(100, 5, "Player Vs Player");
						drawButton(100, 8, "Player Vs Computer");
						drawButton(100, 11, "Load Game");
						SetColor(150);
						drawButton(100, 14, "Help");
						SetColor(0);
						drawButton(100, 17, "About");
						drawButton(100, 20, "Sound");
						drawButton(100, 23, "Exit");
					}
					if (y == 24)
					{
						SetColor(0);
						drawButton(100, 5, "Player Vs Player");
						drawButton(100, 8, "Player Vs Computer");
						drawButton(100, 11, "Load Game");
						drawButton(100, 14, "Help");
						SetColor(150);
						drawButton(100, 17, "About");
						SetColor(0);
						drawButton(100, 20, "Sound");
						drawButton(100, 23, "Exit");
					}
					if (y == 25)
					{
						SetColor(0);
						drawButton(100, 5, "Player Vs Player");
						drawButton(100, 8, "Player Vs Computer");
						drawButton(100, 11, "Load Game");
						drawButton(100, 14, "Help");
						drawButton(100, 17, "About");
						SetColor(150);
						drawButton(100, 20, "Sound");
						SetColor(0);
						drawButton(100, 23, "Exit");
					}
					if (y == 26)
					{
						SetColor(0);
						drawButton(100, 5, "Player Vs Player");
						drawButton(100, 8, "Player Vs Computer");
						drawButton(100, 11, "Load Game");
						drawButton(100, 14, "Help");
						drawButton(100, 17, "About");
						drawButton(100, 20, "Sound");
						SetColor(150);
						drawButton(100, 23, "Exit");
					}
					break;
				case 13:
					backToOriginalMenu = true;
					//PlaySoundEffect("tick"); // khong biet truyen tham so gi nen truyen dai, sau nay sua
					if (y == 20)
					{
						TextColor(255);
						StartGame(_A, _TURN, _COMMAND, _X, _Y);
						RunGame(_A, _PLAYER1, _PLAYER2, _TURN, _COMMAND, _X, _Y, MO_NHAC);
					}
					if (y == 21)
					{
						StartGame(_A, _TURN, _COMMAND, _X, _Y);
						PlayWithComputer(_A, _TURN, _COMMAND, _PLAYER1, _PLAYER2, _X, _Y, validEnter, MO_NHAC);
						//Danh voi may
					}
					if (y == 22)
					{
						int loadOption;
						system("cls");
						loadOption = SelectMenu(LoadingMenu());
						if (loadOption == -1) break;
						else
						{
							TextColor(255);
							LoadGame(RunLoadingMenu(loadOption), _A, _PLAYER1, _PLAYER2, _TURN, _COMMAND, _X, _Y);
							PlayWithComputer(_A, _TURN, _COMMAND, _PLAYER1, _PLAYER2,_X, _Y, validEnter, MO_NHAC);
							//RunGame(_A, _PLAYER1, _PLAYER2, _TURN, _COMMAND, _X, _Y, MO_NHAC);
							break;
						}
					}
					if (y == 23)
					{
						//Menu help trong game
						Help();
					}
					if (y == 24)
					{
						//About
						About();
					}
					if (y == 25)
					{
						//Sound
						Sound(MO_NHAC);
					}
					if (y == 26)
					{
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
		DrawBigText("O.txt", 8, start + 40, 3);
	}
	else if ((_TURN) == 0)
	{
		DrawBigText("O.txt", 2, start + 40, 3);
		DrawBigText("X.txt", 8, start, 3);
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
	menu.x = X_CENTER - 15;
	menu.y = Y_CENTER - files.size() / 2;
	menu.cursorColor = 1;

	//DrawBox(221, 100, menu.options + 10, X_CENTER - 50, Y_CENTER - 5);
	PrintText("[==========Saved Games===========]", 0, menu.x-30, menu.y - 10);
	for (int i = 0; i < files.size(); i++)
	{
		name = "         " + files.at(i);
		PrintText(name, 0, menu.x-27, menu.y + i-9);
	}
	return menu;
}
_MENU EscMenu(_POINT _A[][BOARD_SIZE])
{
	_MENU menu;

	menu.options = 3;
	menu.x = _A[0][BOARD_SIZE - 1].x +40;
	menu.y = Y_CENTER ;
	menu.cursorColor = 75;

	//DrawBoard(1, 1, 62, 25, menu.x - 23, menu.y - 19);
	//DrawBox(75, 63, 25, menu.x - 23, menu.y - 19);
	//DrawBigText("EscLogo.txt", 75, menu.x - 22, menu.y - 17);
	PrintText("    Continue    ", 0, menu.x-22, menu.y-9);
	PrintText("    Save game   ", 0, menu.x-22, menu.y -8);
	//PrintText("    Sound       ", 0, menu.x - 22, menu.y - 7);
	PrintText("    Exit game   ", 0, menu.x-22, menu.y -7);
	return menu;
}
void ShowPlayerInfo(_POINT _A[][BOARD_SIZE], _PLAYER _PLAYER1, _PLAYER _PLAYER2)
{
	int start = _A[0][BOARD_SIZE - 1].x + 4;

	//DrawBoard(3, 3, 10, 1, start, 17);
}
void Help()
{
	system("cls");
	SetColor(245); //Day la mot mau ngau nhien, can chinh lai mau khac dep hon
	GotoXY(60, 19);
	cout << "HELP";
	GotoXY(30, 21);
	cout << "HUONG DAN" << endl;
	GotoXY(30, 22);
	cout << "1. Ban co gom 16x16 o vuong." << endl;
	GotoXY(30, 23);
	cout << "2. Su dung cac phim W A S D de di chuyen va Enter de danh." << endl;
	GotoXY(30, 24);
	cout << "3. Luat choi cu du 5 quan co X hoac O theo hang ngang, doc, cheo se chien thang." << endl;
	GotoXY(30, 25);
	cout << "4. Luat choi tuan theo quy dinh chan 2 dau " << endl;
	GotoXY(30, 26);
	cout << "-> Chuc moi nguoi choi game vui ve !!" << endl;
	GotoXY(60, 30);
	cout << "BACK";
	char command = ' ';
	command = _getch();
	system("cls");
}
void About()
{
	system("cls");
	SetColor(100);
	GotoXY(60, 15);
	cout << "ABOUT";
	GotoXY(50, 18);
	cout << "DO AN GAME CARO - LOP 22CTT4 - HCMUS" << endl;
	GotoXY(50, 19);
	cout << "-> MSSV   : 22120181." << endl;
	GotoXY(50, 20);
	cout << "-> Ho ten : NGUYEN DUY LAM." << endl;
	GotoXY(50, 21);
	cout << "-> Lop    : 22CTT4." << endl;
	GotoXY(50, 22);
	cout << "-> MSSV   : 22120213." << endl;
	GotoXY(50, 23);
	cout << "-> Ho ten : DOAN THI MINH ANH." << endl;
	GotoXY(50, 24);
	cout << "-> Lop    : 22CTT4." << endl;
	GotoXY(50, 25);
	cout << "-> MSSV   : 22120233." << endl;
	GotoXY(50, 26);
	cout << "-> Ho ten : NGUYEN THI TU NGOC." << endl;
	GotoXY(50, 27);
	cout << "-> Lop    : 22CTT4." << endl;
	GotoXY(50, 28);
	cout << "-> MSSV   : 22120202." << endl;
	GotoXY(50, 29);
	cout << "-> Ho ten : TANG SENH MANH." << endl;
	GotoXY(50, 30);
	cout << "-> Lop    : 22CTT4." << endl;
	GotoXY(50, 31);
	cout << "-> GV huong dan : Truong Toan Thinh " << endl;
	GotoXY(50, 32);
	cout << "-> Chuc moi nguoi choi game vui ve !!" << endl;
	GotoXY(60, 33);
	cout << "BACK";
	char command = ' ';
	command = _getch();
	system("cls");
}

void Sound(bool& MO_NHAC)
{
	system("cls");
	SetColor(100);
	GotoXY(60, 15); cout << "SOUND";
	int x = 0, y = 0;
	int i;
	bool backToOriginalMenu = false;
	int song = 0;
	while (!backToOriginalMenu)
	{
		backToOriginalMenu = false;
		x = 50, y = 20;
		SetColor(150);
		GotoXY(50, 20); cout << "Tat nhac nen" << endl;
		SetColor(0);
		GotoXY(50, 21); cout << "Bat nhac nen" << endl;
		GotoXY(50, 22);	cout << "Doi bai" << endl;
		GotoXY(50, 23);	cout << "Tat hieu ung am thanh" << endl;
		GotoXY(50, 24); cout << "BACK";
		GotoXY(50, 32); cout << "....... W - S : Move ( Off Unikey - Off Caps Lock ) ";
		GotoXY(50, 33); cout << "....... Enter : Select ";
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
						SetColor(150);
						GotoXY(50, 20); cout << "Tat nhac nen" << endl;
						SetColor(0);
						GotoXY(50, 21); cout << "Bat nhac nen" << endl;
						GotoXY(50, 22);	cout << "Doi bai" << endl;
						GotoXY(50, 23);	cout << "Tat hieu ung am thanh" << endl;
						GotoXY(50, 24); cout << "BACK";
					}
					if (y == 21)
					{
						SetColor(0);
						GotoXY(50, 20); cout << "Tat nhac nen" << endl;
						SetColor(150);
						GotoXY(50, 21); cout << "Bat nhac nen" << endl;
						SetColor(0);
						GotoXY(50, 22);	cout << "Doi bai" << endl;
						GotoXY(50, 23);	cout << "Tat hieu ung am thanh" << endl;
						GotoXY(50, 24); cout << "BACK";
					}
					if (y == 22)
					{
						SetColor(0);
						GotoXY(50, 20); cout << "Tat nhac nen" << endl;
						GotoXY(50, 21); cout << "Bat nhac nen" << endl;
						SetColor(150);
						GotoXY(50, 22);	cout << "Doi bai" << endl;
						SetColor(0);
						GotoXY(50, 23);	cout << "Tat hieu ung am thanh" << endl;
						GotoXY(50, 24); cout << "BACK";
					}
					if (y == 23)
					{
						SetColor(0);
						GotoXY(50, 20); cout << "Tat nhac nen" << endl;
						GotoXY(50, 21); cout << "Bat nhac nen" << endl;
						GotoXY(50, 22);	cout << "Doi bai" << endl;
						SetColor(150);
						GotoXY(50, 23);	cout << "Tat hieu ung am thanh" << endl;
						SetColor(0);
						GotoXY(50, 24); cout << "BACK";
					}
					if (y == 24)
					{
						GotoXY(50, 20); cout << "Tat nhac nen" << endl;
						GotoXY(50, 21); cout << "Bat nhac nen" << endl;
						SetColor(150);
						GotoXY(50, 22);	cout << "Doi bai" << endl;
						GotoXY(50, 23);	cout << "Tat hieu ung am thanh" << endl;
						SetColor(0);
						GotoXY(50, 24); cout << "BACK";
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
						SetColor(150);
						GotoXY(50, 20); cout << "Tat nhac nen" << endl;
						SetColor(0);
						GotoXY(50, 21); cout << "Bat nhac nen" << endl;
						GotoXY(50, 22);	cout << "Doi bai" << endl;
						GotoXY(50, 23);	cout << "Tat hieu ung am thanh" << endl;
						GotoXY(50, 24); cout << "BACK";
					}
					if (y == 21)
					{
						SetColor(0);
						GotoXY(50, 20); cout << "Tat nhac nen" << endl;
						SetColor(150);
						GotoXY(50, 21); cout << "Bat nhac nen" << endl;
						SetColor(0);
						GotoXY(50, 22);	cout << "Doi bai" << endl;
						GotoXY(50, 23);	cout << "Tat hieu ung am thanh" << endl;
						GotoXY(50, 24); cout << "BACK";
					}
					if (y == 22)
					{
						SetColor(0);
						GotoXY(50, 20); cout << "Tat nhac nen" << endl;
						GotoXY(50, 21); cout << "Bat nhac nen" << endl;
						SetColor(150);
						GotoXY(50, 22);	cout << "Doi bai" << endl;
						SetColor(0);
						GotoXY(50, 23);	cout << "Tat hieu ung am thanh" << endl;
						GotoXY(50, 24); cout << "BACK";
					}
					if (y == 23)
					{
						SetColor(0);
						GotoXY(50, 20); cout << "Tat nhac nen" << endl;
						GotoXY(50, 21); cout << "Bat nhac nen" << endl;
						GotoXY(50, 22);	cout << "Doi bai" << endl;
						SetColor(150);
						GotoXY(50, 23);	cout << "Tat hieu ung am thanh" << endl;
						SetColor(0);
						GotoXY(50, 24); cout << "BACK";
					}
					if (y == 24)
					{
						SetColor(0);
						GotoXY(50, 20); cout << "Tat nhac nen" << endl;
						GotoXY(50, 21); cout << "Bat nhac nen" << endl;
						GotoXY(50, 22);	cout << "Doi bai" << endl;
						GotoXY(50, 23);	cout << "Tat hieu ung am thanh" << endl;
						SetColor(150);
						GotoXY(50, 24); cout << "BACK";
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
	SetColor(170);
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
}

void DrawBoardGiaoDien(_POINT _A[][BOARD_SIZE],int color)
{
	int x = _A[0][BOARD_SIZE].x + 75;
	int y = _A[0][BOARD_SIZE].y + 14;
	GotoXY(x, y);
	SetColor(color);
	cout << (char)201;
	for (int i = 0;i < 51;i++)
		cout << (char)205;
	cout << (char)187;
	for(int i=1;i<14;i++)
	{
		GotoXY(x, y + i);
		cout << (char)186;
		GotoXY(x + 52, y + i);
		cout << (char)186;
	}
	GotoXY(x, y + 14);
	cout << (char)200;
	for (int i = 0;i < 51;i++)
		cout << (char)205;
	cout << (char)188;
	x= _A[0][BOARD_SIZE].x + 78;
	y= _A[0][BOARD_SIZE].y + 17;
	ShowCur(0);
	for (int i = 0;i < 8;i++)
	{
		GotoXY(x, y);
		SetColor(rand() % 15 + 1);
		cout << "     _____";
		GotoXY(x+17, y);
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
		GotoXY(x + 17, y+1);
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
		GotoXY(x+17, y + 2);
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
		GotoXY(x+17, y + 3);
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
		GotoXY(x+17, y + 4);
		SetColor(rand() % 15 + 1);
		cout << "| | < | v | > |";
		GotoXY(x + 34, y + 4);
		SetColor(rand() % 15 + 1);
		cout << "| |  Enter  |";
		Sleep(30);
		GotoXY(x, y + 5);
		SetColor(rand() % 15 + 1);
		cout << " \\|___|___|___|";
		GotoXY(x+17, y + 5);
		SetColor(rand() % 15 + 1);
		cout << " \\|___|___|___|";
		GotoXY(x + 34, y + 5);
		SetColor(rand() % 15 + 1);
		cout << " \\|_________|";
		Sleep(30);

	}
	SetColor(240);
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
	GotoXY(x+17, y);
	cout << "     _____";
	GotoXY(x+17, y + 1);
	cout << "    |\\ ___\\";
	GotoXY(x+17, y + 2);
	cout << " ___| | ^ |__";
	GotoXY(x+17, y + 3);
	cout << "|\\ __\\|___| _\\ ";
	GotoXY(x+17, y + 4);
	cout << "| | < | v | > |";
	GotoXY(x+17, y + 5);
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
	int width = 19; // length of "Player VS Computer" + 2
	GotoXY(x, y); cout << char(218);
	for (int i = 0; i < width; i++) cout << char(196);
	cout << char(191);
	GotoXY(x, y + 1); cout << char(179) << setw((width - text.length()) / 2 + text.length()) << right << text;
	if (text.length() % 2 == 0) cout << setw((width - text.length()) / 2 + 1) << right << " " << char(179);
	else cout << setw((width - text.length()) / 2) << " " << right << char(179);
	GotoXY(x, y + 2); cout << char(192);
	for (int i = 0; i < width; i++) cout << char(196);
	cout << char(217);
}
