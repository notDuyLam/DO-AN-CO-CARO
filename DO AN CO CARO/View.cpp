﻿#include "View.h"

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
	PlayBackGroundMusic(0);
	int x = 0, y = 0;
	int i;
	bool backToOriginalMenu = false;
	while (true)
	{
		backToOriginalMenu = false;
		x = 50, y = 20;
		SetColor(200);
		GotoXY(50, 20); cout << "Player Vs Player";
		SetColor(7);
		GotoXY(50, 21); cout << "Player Vs Computer";
		GotoXY(50, 22); cout << "Load Game";
		GotoXY(50, 23); cout << "Help";
		GotoXY(50, 24); cout << "About";
		GotoXY(50, 25); cout << "Sound";
		GotoXY(50, 26); cout << "Exit";
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
						::GotoXY(x, y);
					}
					if (y == 20)
					{
						SetColor(200);
						GotoXY(50, 20); cout << "Player Vs Player";
						SetColor(7);
						GotoXY(50, 21); cout << "Player Vs Computer";
						GotoXY(50, 22); cout << "Load Game";
						GotoXY(50, 23); cout << "Help";
						GotoXY(50, 24); cout << "About";
						GotoXY(50, 25); cout << "Sound";
						GotoXY(50, 26); cout << "Exit";
					}
					if (y == 21)
					{
						SetColor(7);
						::GotoXY(50, 20); cout << "Player Vs Player";
						SetColor(200);
						::GotoXY(50, 21); cout << "Player Vs Computer";
						SetColor(7);
						::GotoXY(50, 22); cout << "Load Game";
						::GotoXY(50, 23); cout << "Help";
						::GotoXY(50, 24); cout << "About";
						GotoXY(50, 25); cout << "Sound";
						::GotoXY(50, 26); cout << "Exit";
					}
					if (y == 22)
					{
						SetColor(7);
						::GotoXY(50, 20); cout << "Player Vs Player";
						::GotoXY(50, 21); cout << "Player Vs Computer";
						SetColor(200);
						::GotoXY(50, 22); cout << "Load Game";
						SetColor(7);
						::GotoXY(50, 23); cout << "Help";
						::GotoXY(50, 24); cout << "About";
						GotoXY(50, 25); cout << "Sound";
						::GotoXY(50, 26); cout << "Exit";
					}
					if (y == 23)
					{
						SetColor(7);
						::GotoXY(50, 20); cout << "Player Vs Player";
						::GotoXY(50, 21); cout << "Player Vs Computer";
						::GotoXY(50, 22); cout << "Load Game";
						SetColor(200);
						::GotoXY(50, 23); cout << "Help";
						SetColor(7);
						::GotoXY(50, 24); cout << "About";
						GotoXY(50, 25); cout << "Sound";
						::GotoXY(50, 26); cout << "Exit";
					}
					if (y == 24)
					{
						SetColor(7);
						::GotoXY(50, 20); cout << "Player Vs Player";
						::GotoXY(50, 21); cout << "Player Vs Computer";
						::GotoXY(50, 22); cout << "Load Game";
						::GotoXY(50, 23); cout << "Help";
						SetColor(200);
						::GotoXY(50, 24); cout << "About";
						SetColor(7);
						GotoXY(50, 25); cout << "Sound";
						::GotoXY(50, 26); cout << "Exit";
					}
					if (y == 25)
					{
						SetColor(7);
						::GotoXY(50, 20); cout << "Player Vs Player";
						::GotoXY(50, 21); cout << "Player Vs Computer";
						::GotoXY(50, 22); cout << "Load Game";
						::GotoXY(50, 23); cout << "Help";
						::GotoXY(50, 24); cout << "About";
						SetColor(200);
						GotoXY(50, 25); cout << "Sound";
						SetColor(7);
						::GotoXY(50, 26); cout << "Exit";
					}
					if (y == 26)
					{
						SetColor(7);
						::GotoXY(50, 20); cout << "Player Vs Player";
						::GotoXY(50, 21); cout << "Player Vs Computer";
						::GotoXY(50, 22); cout << "Load Game";
						::GotoXY(50, 23); cout << "Help";
						::GotoXY(50, 24); cout << "About";
						SetColor(200);
						GotoXY(50, 25); cout << "Sound";
						SetColor(7);
						::GotoXY(50, 26); cout << "Exit";
					}
					break;
				case 's':
					if (y < 26)
					{
						y++;
						::GotoXY(x, y);
					}
					if (y == 20)
					{
						SetColor(200);
						GotoXY(50, 20); cout << "Player Vs Player";
						SetColor(7);
						GotoXY(50, 21); cout << "Player Vs Computer";
						GotoXY(50, 22); cout << "Load Game";
						GotoXY(50, 23); cout << "Help";
						GotoXY(50, 24); cout << "About";
						GotoXY(50, 25); cout << "Sound";
						GotoXY(50, 26); cout << "Exit";
					}
					if (y == 21)
					{
						SetColor(7);
						::GotoXY(50, 20); cout << "Player Vs Player";
						SetColor(200);
						::GotoXY(50, 21); cout << "Player Vs Computer";
						SetColor(7);
						::GotoXY(50, 22); cout << "Load Game";
						::GotoXY(50, 23); cout << "Help";
						::GotoXY(50, 24); cout << "About";
						GotoXY(50, 25); cout << "Sound";
						::GotoXY(50, 26); cout << "Exit";
					}
					if (y == 22)
					{
						SetColor(7);
						::GotoXY(50, 20); cout << "Player Vs Player";
						::GotoXY(50, 21); cout << "Player Vs Computer";
						SetColor(200);
						::GotoXY(50, 22); cout << "Load Game";
						SetColor(7);
						::GotoXY(50, 23); cout << "Help";
						::GotoXY(50, 24); cout << "About";
						GotoXY(50, 25); cout << "Sound";
						::GotoXY(50, 26); cout << "Exit";
					}
					if (y == 23)
					{
						SetColor(7);
						::GotoXY(50, 20); cout << "Player Vs Player";
						::GotoXY(50, 21); cout << "Player Vs Computer";
						::GotoXY(50, 22); cout << "Load Game";
						SetColor(200);
						::GotoXY(50, 23); cout << "Help";
						SetColor(7);
						::GotoXY(50, 24); cout << "About";
						GotoXY(50, 25); cout << "Sound";
						::GotoXY(50, 26); cout << "Exit";
					}
					if (y == 24)
					{
						SetColor(7);
						::GotoXY(50, 20); cout << "Player Vs Player";
						::GotoXY(50, 21); cout << "Player Vs Computer";
						::GotoXY(50, 22); cout << "Load Game";
						::GotoXY(50, 23); cout << "Help";
						SetColor(200);
						::GotoXY(50, 24); cout << "About";
						SetColor(7);
						GotoXY(50, 25); cout << "Sound";
						::GotoXY(50, 26); cout << "Exit";
					}
					if (y == 25)
					{
						SetColor(7);
						::GotoXY(50, 20); cout << "Player Vs Player";
						::GotoXY(50, 21); cout << "Player Vs Computer";
						::GotoXY(50, 22); cout << "Load Game";
						::GotoXY(50, 23); cout << "Help";
						::GotoXY(50, 24); cout << "About";
						SetColor(200);
						GotoXY(50, 25); cout << "Sound";
						SetColor(7);
						::GotoXY(50, 26); cout << "Exit";
					}
					if (y == 26)
					{
						SetColor(7);
						::GotoXY(50, 20); cout << "Player Vs Player";
						::GotoXY(50, 21); cout << "Player Vs Computer";
						::GotoXY(50, 22); cout << "Load Game";
						::GotoXY(50, 23); cout << "Help";
						::GotoXY(50, 24); cout << "About";
						GotoXY(50, 25); cout << "Sound";
						SetColor(200);
						::GotoXY(50, 26); cout << "Exit";
					}
					break;
				case 13:
					backToOriginalMenu = true;
					//PlaySoundEffect("tick"); // khong biet truyen tham so gi nen truyen dai, sau nay sua
					if (y == 20)
					{
						TextColor(255);
						GamePlay(_A, _TURN, _COMMAND, _X, _Y, validEnter, MO_NHAC);
					}
					if (y == 21)
					{
						//Danh voi may
					}
					if (y == 22)
					{
						//Load game
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
						break;
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
		SetColor(200);
		GotoXY(50, 20); cout << "Tat nhac nen" << endl;
		SetColor(7);
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
						SetColor(200);
						GotoXY(50, 20); cout << "Tat nhac nen" << endl;
						SetColor(7);
						GotoXY(50, 21); cout << "Bat nhac nen" << endl;
						GotoXY(50, 22);	cout << "Doi bai" << endl;
						GotoXY(50, 23);	cout << "Tat hieu ung am thanh" << endl;
						GotoXY(50, 24); cout << "BACK";
					}
					if (y == 21)
					{
						SetColor(7);
						GotoXY(50, 20); cout << "Tat nhac nen" << endl;
						SetColor(200);
						GotoXY(50, 21); cout << "Bat nhac nen" << endl;
						SetColor(7);
						GotoXY(50, 22);	cout << "Doi bai" << endl;
						GotoXY(50, 23);	cout << "Tat hieu ung am thanh" << endl;
						GotoXY(50, 24); cout << "BACK";
					}
					if (y == 22)
					{
						SetColor(7);
						GotoXY(50, 20); cout << "Tat nhac nen" << endl;
						GotoXY(50, 21); cout << "Bat nhac nen" << endl;
						SetColor(200);
						GotoXY(50, 22);	cout << "Doi bai" << endl;
						SetColor(7);
						GotoXY(50, 23);	cout << "Tat hieu ung am thanh" << endl;
						GotoXY(50, 24); cout << "BACK";
					}
					if (y == 23)
					{
						SetColor(7);
						GotoXY(50, 20); cout << "Tat nhac nen" << endl;
						GotoXY(50, 21); cout << "Bat nhac nen" << endl;
						GotoXY(50, 22);	cout << "Doi bai" << endl;
						SetColor(200);
						GotoXY(50, 23);	cout << "Tat hieu ung am thanh" << endl;
						SetColor(7);
						GotoXY(50, 24); cout << "BACK";
					}
					if (y == 24)
					{
						GotoXY(50, 20); cout << "Tat nhac nen" << endl;
						GotoXY(50, 21); cout << "Bat nhac nen" << endl;
						SetColor(200);
						GotoXY(50, 22);	cout << "Doi bai" << endl;
						GotoXY(50, 23);	cout << "Tat hieu ung am thanh" << endl;
						SetColor(7);
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
						SetColor(200);
						GotoXY(50, 20); cout << "Tat nhac nen" << endl;
						SetColor(7);
						GotoXY(50, 21); cout << "Bat nhac nen" << endl;
						GotoXY(50, 22);	cout << "Doi bai" << endl;
						GotoXY(50, 23);	cout << "Tat hieu ung am thanh" << endl;
						GotoXY(50, 24); cout << "BACK";
					}
					if (y == 21)
					{
						SetColor(7);
						GotoXY(50, 20); cout << "Tat nhac nen" << endl;
						SetColor(200);
						GotoXY(50, 21); cout << "Bat nhac nen" << endl;
						SetColor(7);
						GotoXY(50, 22);	cout << "Doi bai" << endl;
						GotoXY(50, 23);	cout << "Tat hieu ung am thanh" << endl;
						GotoXY(50, 24); cout << "BACK";
					}
					if (y == 22)
					{
						SetColor(7);
						GotoXY(50, 20); cout << "Tat nhac nen" << endl;
						GotoXY(50, 21); cout << "Bat nhac nen" << endl;
						SetColor(200);
						GotoXY(50, 22);	cout << "Doi bai" << endl;
						SetColor(7);
						GotoXY(50, 23);	cout << "Tat hieu ung am thanh" << endl;
						GotoXY(50, 24); cout << "BACK";
					}
					if (y == 23)
					{
						SetColor(7);
						GotoXY(50, 20); cout << "Tat nhac nen" << endl;
						GotoXY(50, 21); cout << "Bat nhac nen" << endl;
						GotoXY(50, 22);	cout << "Doi bai" << endl;
						SetColor(200);
						GotoXY(50, 23);	cout << "Tat hieu ung am thanh" << endl;
						SetColor(7);
						GotoXY(50, 24); cout << "BACK";
					}
					if (y == 24)
					{
						SetColor(7);
						GotoXY(50, 20); cout << "Tat nhac nen" << endl;
						GotoXY(50, 21); cout << "Bat nhac nen" << endl;
						GotoXY(50, 22);	cout << "Doi bai" << endl;
						GotoXY(50, 23);	cout << "Tat hieu ung am thanh" << endl;
						SetColor(200);
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
					break;
			}
		}
	}
}