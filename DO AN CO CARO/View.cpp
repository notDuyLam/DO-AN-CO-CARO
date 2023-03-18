#include "View.h"

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
int ProcessFinish(int pWhoWin, _POINT _A[][BOARD_SIZE], bool& _TURN, int& _X, int& _Y,short int toadothang[24])
{
	switch (pWhoWin) {
	case -1:
		PlaySoundEffect("win");
		NhapNhayQuanCo(_A, toadothang, pWhoWin);
		GotoXY(0, _A[BOARD_SIZE - 1][BOARD_SIZE - 1].y + 2); // Nhảy tới vị trí 
		// thích hợp để in chuỗi thắng/thua/hòa
		printf("Nguoi choi %d da thang va nguoi choi %d da thua\n", true, false);
		break;
	case 1:
		PlaySoundEffect("win");
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
void ScreenStartGame(int n, _POINT _A[][BOARD_SIZE], bool _TURN, int _COMMAND, int _X, int _Y, bool validEnter)
{
	PlayBackGroundMusic();
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
		GotoXY(50, 25); cout << "Exit";
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
						GotoXY(50, 25); cout << "Exit";
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
						::GotoXY(50, 25); cout << "Exit";
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
						::GotoXY(50, 25); cout << "Exit";
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
						::GotoXY(50, 25); cout << "Exit";
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
						::GotoXY(50, 25); cout << "Exit";
					}
					if (y == 25)
					{
						SetColor(7);
						::GotoXY(50, 20); cout << "Player Vs Player";
						::GotoXY(50, 21); cout << "Player Vs Computer";
						::GotoXY(50, 22); cout << "Load Game";
						::GotoXY(50, 23); cout << "Help";
						SetColor(200);
						::GotoXY(50, 24); cout << "About";
						SetColor(7);
						::GotoXY(50, 25); cout << "Exit";
					}
					break;
				case 's':
					if (y < 25)
					{
						y++;
						::GotoXY(x, y);
					}
					if (y == 20)
					{
						SetColor(200);
						::GotoXY(50, 20); cout << "Player Vs Player";
						SetColor(7);
						::GotoXY(50, 21); cout << "Player Vs Computer";
						::GotoXY(50, 22); cout << "Load Game";
						::GotoXY(50, 23); cout << "Help";
						::GotoXY(50, 24); cout << "About";
						::GotoXY(50, 25); cout << "Exit";
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
						::GotoXY(50, 25); cout << "Exit";
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
						::GotoXY(50, 25); cout << "Exit";
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
						::GotoXY(50, 25); cout << "Exit";
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
						::GotoXY(50, 25); cout << "Exit";
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
						::GotoXY(50, 25); cout << "Exit";
					}
					break;
				case 13:
					backToOriginalMenu = true;
					//PlaySoundEffect("tick"); // khong biet truyen tham so gi nen truyen dai, sau nay sua
					if (y == 20)
					{
						TextColor(255);
						GamePlay(_A, _TURN, _COMMAND, _X, _Y, validEnter);
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
						//Help
					}
					if (y == 24)
					{
						//About
					}
					if (y == 25)
					{
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

