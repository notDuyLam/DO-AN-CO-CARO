#include "Control.h"


void StartGame(_POINT _A[][BOARD_SIZE], bool& _TURN, int& _COMMAND, int& _X, int& _Y, _PLAYER& _PLAYER1, _PLAYER& _PLAYER2)
{
	SetPlayerRank(_PLAYER1); // Khi bắt đầu chơi hàm này kiểm tra người chơi tồn tại chưa và gán cho mức xếp hạng tương ứng
	SetPlayerRank(_PLAYER2); // Tương tự nhưng cho người chơi 2
	system("cls");
	ResetData(_A, _TURN, _COMMAND, _X, _Y); // Khởi tạo dữ liệu gốc
	DrawBoard(BOARD_SIZE); // Vẽ màn hình game
	ShowTurn(_A, _PLAYER1, _PLAYER2, _TURN);
	GotoXY(_X, _Y);
	ShowCur(0);
	DrawBoardGiaoDien(_A, 240);
	ShowCur(1);
	DrawPhimTat(_A);
}
void MoveRight(_POINT _A[][BOARD_SIZE], int& _X, int& _Y) {
	if (_X < _A[BOARD_SIZE - 1][BOARD_SIZE - 1].x)
	{
		_X += 4;
		GotoXY(_X, _Y);
	}
}
void MoveLeft(_POINT _A[][BOARD_SIZE], int& _X, int& _Y) {
	if (_X > _A[0][0].x) {
		_X -= 4;
		GotoXY(_X, _Y);
	}
}
void MoveDown(_POINT _A[][BOARD_SIZE], int& _X, int& _Y) {
	if (_Y < _A[BOARD_SIZE - 1][BOARD_SIZE - 1].y)
	{
		_Y += 2;
		GotoXY(_X, _Y);
	}
}
void MoveUp(_POINT _A[][BOARD_SIZE], int& _X, int& _Y) {
	if (_Y > _A[0][0].y) {
		_Y -= 2;
		GotoXY(_X, _Y);
	}
}

/*void GamePlay(_POINT _A[][BOARD_SIZE], bool _TURN, int _COMMAND, int _X, int _Y, bool validEnter, bool& SoundEffects)
{
	_PLAYER _PLAYER1, _PLAYER2;
	FixConsoleWindow();
	bool runGame = true;
	int escOption;
	StartGame(_A, _TURN, _COMMAND, _X, _Y);
	StopMusic();
	short int toadothang[24];
	while (1)
	{
		_COMMAND = toupper(_getch());
		if (_COMMAND == ESC)
		{
			escOption = SelectMenu(EscMenu(_A));
			RunEscMenu(_A, _PLAYER1, _PLAYER2, _TURN, escOption, runGame);
		}
		if (_COMMAND == 'O')
			StopMusic();
		else if (_COMMAND == 'P')
			PlayBackGroundMusic(0);
		if (_COMMAND == 27)
		{
			system("cls");
			return;
		}
		else {
			if (_COMMAND == 'A' || _COMMAND == ARROW_LEFT) MoveLeft(_A, _X, _Y);
			else if (_COMMAND == 'W'||_COMMAND == ARROW_UP) MoveUp(_A, _X, _Y);
			else if (_COMMAND == 'S' || _COMMAND == ARROW_DOWN) MoveDown(_A, _X, _Y);
			else if (_COMMAND == 'D' || _COMMAND == ARROW_RIGHT) MoveRight(_A, _X, _Y);
			else if (_COMMAND == 13 || _COMMAND == SPACE) {// Người dùng đánh dấu trên màn hình bàn cờ
				PlaySoundEffect("move", SoundEffects);
				switch (CheckBoard(_X, _Y, _A, _TURN)) {
				case -1:
				{
					SetColor(1);
					printf("X"); 
					break;
				}
				case 1:
				{
					SetColor(2);
					printf("O"); 
					break;
				}
				case 0: validEnter = false; // Khi đánh vào ô đã đánh rồi
				}
				// Tiếp theo là kiểm tra và xử lý thắng/thua/hòa/tiếp tục
				if (validEnter == true) {
					switch (ProcessFinish(TestBoard(_A, _TURN, GetRowIndex(_Y), GetColIndex(_X),toadothang), _A, _TURN, _X, _Y,toadothang, SoundEffects)) {
					case -1: case 1: case 0:
						if (AskContinue(_A) != 'Y') {
							StopMusic();
							system("cls");
							return;
						}
						else StartGame(_A, _TURN, _COMMAND, _X, _Y);
					}
				}
				validEnter = true; // Mở khóa
			}
		}
	}
}
*/
void RunGame(_POINT _A[][BOARD_SIZE], _PLAYER& _PLAYER1, _PLAYER& _PLAYER2, bool& _TURN, int& _COMMAND, int& _X, int& _Y, bool& SoundEffects, int& chedo, int& song, int& songtemp)
{
	chedo = 2;
	bool validEnter = true;
	bool runGame = true;
	int escOption;
	short int toadothang[24];
	while (runGame)
	{
		ShowPlayerInfo(_A, _PLAYER1, _PLAYER2);
		GotoXY(_X, _Y);
		_COMMAND = toupper(_getch());
		if (_COMMAND == ESC)
		{
			escOption = EscMenu(_A, SoundEffects, song, songtemp);
			RunEscMenu(_A, _PLAYER1, _PLAYER2, _TURN, escOption, runGame, chedo, song, songtemp);
		}
		else
		{
			// Phần này dùng để làm hiệu ứng nháy đen khi ấn một trong các nút trong các ô hướng dẫn của game khi đang chơi
			if (_COMMAND == 'W' || _COMMAND == ARROW_UP) 
			{
				TextColor(2);
				if (_COMMAND == 'W')
				{
					GotoXY(87, 20);
					cout << "|\\ ___\\";
					GotoXY(87, 21);
					cout << "| | W |";
					GotoXY(88, 22);
					cout << "\\|___|";
					MoveUp(_A, _X, _Y);
					TextColor(255);
					SetColor(0);
					Sleep(50);
					GotoXY(87, 20);
					cout << "|\\ ___\\";
					GotoXY(87, 21);
					cout << "| | W |";
					GotoXY(88, 22);
					cout << "\\|___|";
				}
				else
				{
					GotoXY(84+34, 20);
					cout << "|\\ ___\\";
					GotoXY(84+34, 21);
					cout << "| | ^ |";
					GotoXY(85+34, 22);
					cout << "\\|___|";
					MoveUp(_A, _X, _Y);
					TextColor(255);
					SetColor(0);
					Sleep(50);
					GotoXY(84 + 34, 20);
					cout << "|\\ ___\\";
					GotoXY(84 + 34, 21);
					cout << "| | ^ |";
					GotoXY(85 + 34, 22);
					cout << "\\|___|";
				}
			}
			else if (_COMMAND == 'S' || _COMMAND == ARROW_DOWN) 
			{
				TextColor(2);
				if(_COMMAND == 'S')
				{
					GotoXY(89, 23);
					cout << "| S |";
					GotoXY(89, 24);
					cout << "|___|";
					MoveDown(_A, _X, _Y);
					TextColor(255);
					SetColor(0);
					Sleep(50);
					GotoXY(89, 23);
					cout << "| S |";
					GotoXY(89, 24);
					cout << "|___|";
				}
				else
				{
					GotoXY(86+34, 23);
					cout << "| v |";
					GotoXY(86+34, 24);
					cout << "|___|";
					MoveDown(_A, _X, _Y);
					TextColor(255);
					SetColor(0);
					Sleep(50);
					GotoXY(86+34, 23);
					cout << "| v |";
					GotoXY(86+34, 24);
					cout << "|___|";
				}
			}
			else if (_COMMAND == 'A' || _COMMAND == ARROW_LEFT)
			{
				TextColor(2);
				if (_COMMAND == 'A')
				{
					GotoXY(83, 22);
					cout << "|\\ __\\";
					GotoXY(83, 23);
					cout << "| | A ";
					GotoXY(84, 24);
					cout << "\\|___";
					MoveLeft(_A, _X, _Y);
					Sleep(50);
					TextColor(255);
					SetColor(0);
					GotoXY(83, 22);
					cout << "|\\ __\\";
					GotoXY(83, 23);
					cout << "| | A ";
					GotoXY(84, 24);
					cout << "\\|___";
				}
				else
				{
					GotoXY(80+34, 22);
					cout << "|\\ __\\";
					GotoXY(80+34, 23);
					cout << "| | < ";
					GotoXY(81+34, 24);
					cout << "\\|___";
					MoveLeft(_A, _X, _Y);
					Sleep(50);
					TextColor(255);
					SetColor(0);
					GotoXY(80+34, 22);
					cout << "|\\ __\\";
					GotoXY(80+34, 23);
					cout << "| | < ";
					GotoXY(81+34, 24);
					cout << "\\|___";
				}
			}
			else if (_COMMAND == 'D' || _COMMAND == ARROW_RIGHT) 
			{
				TextColor(2);
				if(_COMMAND=='D')
				{
					GotoXY(93, 22);
					cout << "| _\\";
					GotoXY(93, 23);
					cout << "| D |";
					GotoXY(93, 24);
					cout << "|___|";
					MoveRight(_A, _X, _Y);
					Sleep(50);
					TextColor(255);
					SetColor(0);
					GotoXY(93, 22);
					cout << "| _\\";
					GotoXY(93, 23);
					cout << "| D |";
					GotoXY(93, 24);
					cout << "|___|";
				}
				else
				{
					GotoXY(90+34, 22);
					cout << "| _\\";
					GotoXY(90+34, 23);
					cout << "| > |";
					GotoXY(90+34, 24);
					cout << "|___|";
					MoveRight(_A, _X, _Y);
					Sleep(50);
					TextColor(255);
					SetColor(0);
					GotoXY(90+34, 22);
					cout << "| _\\";
					GotoXY(90+34, 23);
					cout << "| > |";
					GotoXY(90+34, 24);
					cout << "|___|";
				}
			}
			else if (_COMMAND == ENTER || _COMMAND == SPACE)
			{
				PlaySoundEffect("move", SoundEffects);

				switch (CheckBoard(_X, _Y, _A, _TURN))
				{
				case P_X:
				{
					SetColor(1);
					printf("X");
					TextColor(2);
					if(_COMMAND == ENTER)
					{
						GotoXY(120, 26);
						cout << "|\\____\\";
						GotoXY(120, 27);
						cout << "||    |";
						GotoXY(114, 28);
						cout << "|\\ ___\\|    |";
						GotoXY(114, 29);
						cout << "| |  Enter  |";
						GotoXY(115, 30);
						cout << "\\|_________|";
					}
					else
					{
						GotoXY(79, 28);
						cout << "|\\          Space          \\";
						GotoXY(79, 29);
						cout << "\\ \\_________________________\\";
						GotoXY(80, 30);
						cout << "\\|_________________________|";
					}
					break;
				}
				case P_O:
				{
					SetColor(2);
					printf("O");
					TextColor(2);
					if (_COMMAND == ENTER)
					{
						GotoXY(120, 26);
						cout << "|\\____\\";
						GotoXY(120, 27);
						cout << "||    |";
						GotoXY(114, 28);
						cout << "|\\ ___\\|    |";
						GotoXY(114, 29);
						cout << "| |  Enter  |";
						GotoXY(115, 30);
						cout << "\\|_________|";
					}
					else
					{
						GotoXY(79, 28);
						cout << "|\\          Space          \\";
						GotoXY(79, 29);
						cout << "\\ \\_________________________\\";
						GotoXY(80, 30);
						cout << "\\|_________________________|";
					}
					break;
				}
				case 0:
					TextColor(2);
					if (_COMMAND == ENTER)
					{
						GotoXY(120, 26);
						cout << "|\\____\\";
						GotoXY(120, 27);
						cout << "||    |";
						GotoXY(114, 28);
						cout << "|\\ ___\\|    |";
						GotoXY(114, 29);
						cout << "| |  Enter  |";
						GotoXY(115, 30);
						cout << "\\|_________|";
					}
					else
					{
						GotoXY(79, 28);
						cout << "|\\          Space          \\";
						GotoXY(79, 29);
						cout << "\\ \\_________________________\\";
						GotoXY(80, 30);
						cout << "\\|_________________________|";
					}
					validEnter = false;
					break;
				}
				Sleep(50);
				TextColor(255);
				SetColor(0);
				if (_COMMAND == ENTER)
				{
					GotoXY(120, 26);
					cout << "|\\____\\";
					GotoXY(120, 27);
					cout << "||    |";
					GotoXY(114, 28);
					cout << "|\\ ___\\|    |";
					GotoXY(114, 29);
					cout << "| |  Enter  |";
					GotoXY(115, 30);
					cout << "\\|_________|";
				}
				else
				{
					GotoXY(79, 28);
					cout << "|\\          Space          \\";
					GotoXY(79, 29);
					cout << "\\ \\_________________________\\";
					GotoXY(80, 30);
					cout << "\\|_________________________|";
				}
				// Tiếp theo là kiểm tra và xử lý thắng/thua/hòa/tiếp tục
				if (validEnter == true) {
					switch (ProcessFinish(TestBoard(_A, _TURN, GetRowIndex(_Y), GetColIndex(_X), toadothang), _A, _TURN, _X, _Y, toadothang, SoundEffects, _PLAYER1, _PLAYER2)) {
					case -1: case 1: case 0:
						if (AskContinue(_A) != 'Y') {
							StopMusic();
							system("cls");
							return;
						}
						else StartGame(_A, _TURN, _COMMAND, _X, _Y, _PLAYER1, _PLAYER2);
					}
				}
				validEnter = true; // Mở khóa
			}
			validEnter = true;
		}
	}
	//PlaySoundA("NoSound.wav", NULL, SND_ASYNC);
}
int ProcessFinish(int pWhoWin, _POINT _A[][BOARD_SIZE], bool& _TURN, int& _X, int& _Y, short int toadothang[24], bool& SoundEffects, _PLAYER& _PLAYER1, _PLAYER& _PLAYER2)
{
	switch (pWhoWin) {
	case -1: // Người chơi 1 chiến thắng
		_PLAYER1.wins++; // Tăng số win của người chơi đó
		PlaySoundEffect("win", SoundEffects); // Mở nhạc thắng
		NhapNhayQuanCo(_A, toadothang, pWhoWin); // Làm nổi bật quân cờ chiến thắng
		ThongBaoWin(pWhoWin, _A); // Thông báo X hoặc O đã win
		SavePlayer(_PLAYER1); // Lưu thông tin người chơi vào playerList
		break;
	case 1: // Người chơi 2 chiến thắng
		_PLAYER2.wins++;
		PlaySoundEffect("win", SoundEffects);
		NhapNhayQuanCo(_A, toadothang, pWhoWin);
		ThongBaoWin(pWhoWin, _A);
		SavePlayer(_PLAYER2);
		break;
	case 0: // Hòa
		PlaySoundEffect("draw", SoundEffects);
		ThongBaoWin(pWhoWin, _A);
		break;
	case 2: // Trường hợp nếu chưa ai thắng hoặc hòa
		_TURN = !_TURN; // Đổi lượt nếu không có gì xảy ra
		ShowTurn(_A, _PLAYER1, _PLAYER2, _TURN);
		ShowCur(1);
		break;
	}
	GotoXY(_X, _Y); // Trả về vị trí hiện hành của con trỏ màn hình bàn cờ
	return pWhoWin;
}
int AskContinue(_POINT _A[][BOARD_SIZE])
{
	int x = 53;
	GotoXY(x, 10 + 3); TextColor(176); for (int i = x; i <= x + 29; i++) cout << " ";
	GotoXY(x, 11 + 3); cout << " "; TextColor(240);cout << "                            "; TextColor(176);cout << " ";
	GotoXY(x, 12 + 3); cout << " "; TextColor(240); SetColor(7); cout << "   Play again        Quit   ";
	TextColor(176);cout << " ";
	GotoXY(x, 13 + 3); cout << " ";TextColor(240);cout << "                            ";TextColor(176);cout << " ";
	GotoXY(x, 14 + 3); TextColor(176); for (int i = x; i <= x + 29; i++) cout << " ";
	TextColor(240);
	int choice = 0;
	int currentPos = 0;
	GotoXY(x + 4, 12 + 3);
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
		else if (key == '\r' || key == SPACE) {
			break;
		}

		// Đổi màu chữ tùy theo lựa chọn
		if (choice != currentPos) {
			if (choice == 0) {
				GotoXY(x + 4, 12 + 3);
				SetColor(4);
				cout << "Play again";
				SetColor(7);
				GotoXY(x + 22, 12 + 3);
				cout << "Quit";
				ShowCur(0);
			}
			else {
				GotoXY(x + 4, 12 + 3);
				cout << "Play again";
				GotoXY(x + 22, 12 + 3);
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
void ScreenStartGame(int n, _POINT _A[][BOARD_SIZE], bool _TURN, int _COMMAND, int _X, int _Y, bool validEnter, bool& SoundEffects, int& chedo, _PLAYER& _PLAYER1, _PLAYER& _PLAYER2, int& song, int& songtemp)
{
	int x = 0, y = 0;
	drawFrame(0, 0, 145, 33);
	drawFrame(5, 3, 80, 28);
	int i;
	bool backToOriginalMenu = false;
	bool afterPlay = true; // Biến này để phục vụ cho âm thanh, kiểm tra xem người chơi có vừa chơi xong không
	while (true)
	{
		drawFrame(0, 0, 145, 33);
		drawFrame(5, 3, 80, 28);
		TextColor(255);
		printBigCaro(10, 10);
		backToOriginalMenu = false;
		x = 103, y = 20;
		if (afterPlay)
			PlayBackGroundMusic(song);
		drawSelectedButton(103, 5, "PLAYER VS PLAYER");
		drawButton(103, 8, "PLAYER VS COMPUTER");
		drawButton(103, 11, "LOAD GAME");
		drawButton(103, 14, "HELP");
		drawButton(103, 17, "ABOUT");
		drawButton(103, 20, "SOUND");
		drawButton(103, 23, "RANKING");
		drawButton(103, 26, "EXIT");
		SetColor(8);
		GotoXY(88, 29); cout << "___ W A S D: MOVE ___";
		GotoXY(88, 30); cout << "___ Space: Select ___";
		GotoXY(115, 29); cout << "___ ^ < v >: MOVE ___";
		GotoXY(115, 30); cout << "___ Enter: Select ___";
		ShowCur(0);
		while (true)
		{
			if (_kbhit())
			{
				switch (_getch())
				{
				case KEY_ARROW_UP:
				case 'w':
					if (y > 20)
					{
						y--;
						GotoXY(x, y);
					}
					if (y == 20)
					{
						SetColor(4);
						drawSelectedButton(103, 5, "PLAYER VS PLAYER");
						SetColor(0);
						drawButton(103, 8, "PLAYER VS COMPUTER");
						drawButton(103, 11, "LOAD GAME");
						drawButton(103, 14, "HELP");
						drawButton(103, 17, "ABOUT");
						drawButton(103, 20, "SOUND");
						drawButton(103, 23, "RANKING");
						drawButton(103, 26, "EXIT");
						ShowCur(0);
					}
					if (y == 21)
					{
						SetColor(0);
						drawButton(103, 5, "PLAYER VS PLAYER");
						SetColor(4);
						drawSelectedButton(103, 8, "PLAYER VS COMPUTER");
						SetColor(0);
						drawButton(103, 11, "LOAD GAME");
						drawButton(103, 14, "HELP");
						drawButton(103, 17, "ABOUT");
						drawButton(103, 20, "SOUND");
						drawButton(103, 23, "RANKING");
						drawButton(103, 26, "EXIT");
						ShowCur(0);
					}
					if (y == 22)
					{
						SetColor(0);
						drawButton(103, 5, "PLAYER VS PLAYER");
						drawButton(103, 8, "PLAYER VS COMPUTER");
						SetColor(4);
						drawSelectedButton(103, 11, "LOAD GAME");
						SetColor(0);
						drawButton(103, 14, "HELP");
						drawButton(103, 17, "ABOUT");
						drawButton(103, 20, "SOUND");
						drawButton(103, 23, "RANKING");
						drawButton(103, 26, "EXIT");
						ShowCur(0);
					}
					if (y == 23)
					{
						SetColor(0);
						drawButton(103, 5, "PLAYER VS PLAYER");
						drawButton(103, 8, "PLAYER VS COMPUTER");
						drawButton(103, 11, "LOAD GAME");
						SetColor(4);
						drawSelectedButton(103, 14, "HELP");
						SetColor(0);
						drawButton(103, 17, "ABOUT");
						drawButton(103, 20, "SOUND");
						drawButton(103, 23, "RANKING");
						drawButton(103, 26, "EXIT");
						ShowCur(0);
					}
					if (y == 24)
					{
						SetColor(0);
						drawButton(103, 5, "PLAYER VS PLAYER");
						drawButton(103, 8, "PLAYER VS COMPUTER");
						drawButton(103, 11, "LOAD GAME");
						drawButton(103, 14, "HELP");
						SetColor(4);
						drawSelectedButton(103, 17, "ABOUT");
						SetColor(0);
						drawButton(103, 20, "SOUND");
						drawButton(103, 23, "RANKING");
						drawButton(103, 26, "EXIT");
						ShowCur(0);
					}
					if (y == 25)
					{
						SetColor(0);
						drawButton(103, 5, "PLAYER VS PLAYER");
						drawButton(103, 8, "PLAYER VS COMPUTER");
						drawButton(103, 11, "LOAD GAME");
						drawButton(103, 14, "HELP");
						drawButton(103, 17, "ABOUT");
						SetColor(4);
						drawSelectedButton(103, 20, "SOUND");
						SetColor(0);
						drawButton(103, 23, "RANKING");
						drawButton(103, 26, "EXIT");
						ShowCur(0);
					}
					if (y == 26)
					{
						SetColor(0);
						drawButton(103, 5, "PLAYER VS PLAYER");
						drawButton(103, 8, "PLAYER VS COMPUTER");
						drawButton(103, 11, "LOAD GAME");
						drawButton(103, 14, "HELP");
						drawButton(103, 17, "ABOUT");
						drawButton(103, 20, "SOUND");
						SetColor(4);
						drawSelectedButton(103, 23, "RANKING");
						SetColor(0);
						drawButton(103, 26, "EXIT");
						ShowCur(0);
					}
					if (y == 27)
					{
						SetColor(0);
						drawButton(103, 5, "PLAYER VS PLAYER");
						drawButton(103, 8, "PLAYER VS COMPUTER");
						drawButton(103, 11, "LOAD GAME");
						drawButton(103, 14, "HELP");
						drawButton(103, 17, "ABOUT");
						drawButton(103, 20, "SOUND");
						SetColor(4);
						drawButton(103, 23, "RANKING");
						SetColor(0);
						drawSelectedButton(103, 26, "EXIT");
						ShowCur(0);
					}
					break;
				case KEY_ARROW_DOWN:
				case 's':
					if (y < 27)
					{
						y++;
						GotoXY(x, y);
					}
					if (y == 20)
					{
						SetColor(4);
						drawSelectedButton(103, 5, "PLAYER VS PLAYER");
						SetColor(0);
						drawButton(103, 8, "PLAYER VS COMPUTER");
						drawButton(103, 11, "LOAD GAME");
						drawButton(103, 14, "HELP");
						drawButton(103, 17, "ABOUT");
						drawButton(103, 20, "SOUND");
						drawButton(103, 23, "RANKING");
						drawButton(103, 26, "EXIT");
						ShowCur(0);
					}
					if (y == 21)
					{
						SetColor(0);
						drawButton(103, 5, "PLAYER VS PLAYER");
						SetColor(4);
						drawSelectedButton(103, 8, "PLAYER VS COMPUTER");
						SetColor(0);
						drawButton(103, 11, "LOAD GAME");
						drawButton(103, 14, "HELP");
						drawButton(103, 17, "ABOUT");
						drawButton(103, 20, "SOUND");
						drawButton(103, 23, "RANKING");
						drawButton(103, 26, "EXIT");
						ShowCur(0);
					}
					if (y == 22)
					{
						SetColor(0);
						drawButton(103, 5, "PLAYER VS PLAYER");
						drawButton(103, 8, "PLAYER VS COMPUTER");
						SetColor(4);
						drawSelectedButton(103, 11, "LOAD GAME");
						SetColor(0);
						drawButton(103, 14, "HELP");
						drawButton(103, 17, "ABOUT");
						drawButton(103, 20, "SOUND");
						drawButton(103, 23, "RANKING");
						drawButton(103, 26, "EXIT");
						ShowCur(0);
					}
					if (y == 23)
					{
						SetColor(0);
						drawButton(103, 5, "PLAYER VS PLAYER");
						drawButton(103, 8, "PLAYER VS COMPUTER");
						drawButton(103, 11, "LOAD GAME");
						SetColor(4);
						drawSelectedButton(103, 14, "HELP");
						SetColor(0);
						drawButton(103, 17, "ABOUT");
						drawButton(103, 20, "SOUND");
						drawButton(103, 23, "RANKING");
						drawButton(103, 26, "EXIT");
						ShowCur(0);
					}
					if (y == 24)
					{
						SetColor(0);
						drawButton(103, 5, "PLAYER VS PLAYER");
						drawButton(103, 8, "PLAYER VS COMPUTER");
						drawButton(103, 11, "LOAD GAME");
						drawButton(103, 14, "HELP");
						SetColor(4);
						drawSelectedButton(103, 17, "ABOUT");
						SetColor(0);
						drawButton(103, 20, "SOUND");
						drawButton(103, 23, "RANKING");
						drawButton(103, 26, "EXIT");
						ShowCur(0);
					}
					if (y == 25)
					{
						SetColor(0);
						drawButton(103, 5, "PLAYER VS PLAYER");
						drawButton(103, 8, "PLAYER VS COMPUTER");
						drawButton(103, 11, "LOAD GAME");
						drawButton(103, 14, "HELP");
						drawButton(103, 17, "ABOUT");
						SetColor(4);
						drawSelectedButton(103, 20, "SOUND");
						SetColor(0);
						drawButton(103, 23, "RANKING");
						drawButton(103, 26, "EXIT");
						ShowCur(0);
					}
					if (y == 26)
					{
						SetColor(0);
						drawButton(103, 5, "PLAYER VS PLAYER");
						drawButton(103, 8, "PLAYER VS COMPUTER");
						drawButton(103, 11, "LOAD GAME");
						drawButton(103, 14, "HELP");
						drawButton(103, 17, "ABOUT");
						drawButton(103, 20, "SOUND");
						SetColor(4);
						drawSelectedButton(103, 23, "RANKING");
						SetColor(0);
						drawButton(103, 26, "EXIT");
						ShowCur(0);
					}
					if (y == 27)
					{
						SetColor(0);
						drawButton(103, 5, "PLAYER VS PLAYER");
						drawButton(103, 8, "PLAYER VS COMPUTER");
						drawButton(103, 11, "LOAD GAME");
						drawButton(103, 14, "HELP");
						drawButton(103, 17, "ABOUT");
						drawButton(103, 20, "SOUND");
						drawButton(103, 23, "RANKING");
						SetColor(4);
						drawSelectedButton(103, 26, "EXIT");
						ShowCur(0);
					}
					break;
				case SPACE:
				case ENTER:
					backToOriginalMenu = true;
					//PlaySOUNDEffect("tick"); // khong biet truyen tham so gi nen truyen dai, sau nay sua
					if (y == 20) // Danh voi nguoi
					{
						ShowCur(1);
						SetPlayer(_PLAYER1, _PLAYER2);
						Loading();
						TextColor(255);
						PlaySoundEffect("choose", SoundEffects);
						StartGame(_A, _TURN, _COMMAND, _X, _Y, _PLAYER1, _PLAYER2);
						RunGame(_A, _PLAYER1, _PLAYER2, _TURN, _COMMAND, _X, _Y, SoundEffects, chedo, song, songtemp);
						afterPlay = true;
					}
					if (y == 21) //Danh voi may
					{
						ShowCur(1);
						SetPlayerVsComputer(_PLAYER1, _PLAYER2);
						Loading();
						TextColor(255);
						PlaySoundEffect("choose", SoundEffects);
						StartGame(_A, _TURN, _COMMAND, _X, _Y, _PLAYER1, _PLAYER2);
						PlayWithComputer(_A, _TURN, _COMMAND, _PLAYER1, _PLAYER2, _X, _Y, validEnter, SoundEffects, chedo, song, songtemp);
						afterPlay = true;
					}
					if (y == 22)//Loading();
					{
						for (int i = 6; i < 28; i++)
						{
							for (int j = 6; j < 81; j++)
							{
								GotoXY(j, i);
								cout << " ";

							}
						}
						SetColor(0);
						GotoXY(10, 10);
						TextColor(255);
						ShowCur(1);
						int loadOption;
						afterPlay = false;
						while (!afterPlay)
						{

							loadOption = SelectMenu(LoadingMenu());
							/*
							Phần xóa file đã lưu hoạt động bằng cách trong hàm SelectMenu khi mà bấm D để xóa thì thay vì hàm sẽ trả về loadOption là lựa chọn thứ mấy
							thì nó sẽ trả về số lựa chọn + 1000, ở dưới vòng lặp while kiểm tra điều kiện loadOption > 1000 tức là nếu người chơi vẫn muốn tiếp tục xóa
							thì tiếp tục lấy loadOption và in ra các file đã lưu.
							Trong vòng lặp while đầu tiên mở savedList lên và lấy các tên file trong đó đưa vào vector lines, nếu người dùng chọn xóa lựa chọn số mấy
							thì sẽ lấy loadOption - 1000 = số thứ tự của file mà người dùng xóa, sau đó xóa phần tử đó bằng erase với vector lines rồi lại mở file
							savedList nhưng bằng chế độ trunc, tức là sau khi mở thì xóa toàn bộ nội dung của file và ghi lại từng phần tử của vector lines lại vào trong
							file savedList và in lại ra màn hình danh sách các ván đấu đã lưu. (Tuy nhiên file mà người chơi đã lưu ko thật sự xóa (tại ko biết xóa) mà
							chỉ xóa tên của file đó trong danh sách các file.
							*/

							while (loadOption > 1000)
							{
								// Vòng while này có tác dụng hỏi người dùng trước khi xóa file
								// Nếu người dùng chọn No thì sẽ in ra lại các lựa chọn file để người chơi lựa chọn chơi hoặc thoát
								// ra ngoài. Nếu người dùng chọn Yes thì file người dùng muốn xóa sẽ bị xóa và màn hình sẽ lại
								// in ra danh sách các file để người dùng có thể xóa hoặc chơi hoặc thoát ra ngoài
								int choice = 0;
								int currentPos = 0;
								GotoXY(20 + 36, 10 + 3); TextColor(176); for (int i = 20 + 36; i <= 20 + 36 + 41; i++) cout << " ";
								GotoXY(20 + 36, 11 + 3); cout << " "; TextColor(240); cout << "                                        "; TextColor(176); cout << " ";
								GotoXY(20 + 36, 12 + 3); cout << " "; TextColor(240); cout << "                                        "; TextColor(176); cout << " ";
								GotoXY(20 + 36, 13 + 3); cout << " "; TextColor(240); SetColor(77); cout << "    Do you want to delete that save?    "; SetColor(0); TextColor(176); cout << " ";
								GotoXY(20 + 36, 14 + 3); cout << " "; TextColor(240); cout << "                                        "; TextColor(176); cout << " ";
								GotoXY(20 + 36, 15 + 3); cout << " "; TextColor(240); cout << "                                        "; TextColor(176); cout << " ";
								GotoXY(20 + 36, 16 + 3); for (int i = 20 + 36; i <= 20 + 36 + 41; i++) cout << " ";
								GotoXY(32 + 36, 14 + 3);
								TextColor(240);
								SetColor(4);
								cout << "Yes";
								SetColor(7);
								GotoXY(47 + 36, 14 + 3);
								cout << "No";
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
									else if (key == '\r' || key == SPACE) {
										break;
									}

									// Đổi màu chữ tùy theo lựa chọn
									if (choice != currentPos) {
										if (choice == 0) {
											GotoXY(32 + 36, 14 + 3);
											SetColor(4);
											cout << "Yes";
											SetColor(7);
											GotoXY(47 + 36, 14 + 3);
											cout << "No";
											ShowCur(0);
										}
										else {
											GotoXY(32 + 36, 14 + 3);
											cout << "Yes";
											GotoXY(47 + 36, 14 + 3);
											SetColor(4);
											cout << "No";
											SetColor(7);
											ShowCur(0);
										}
										currentPos = choice;
									}
								}
								if (choice == 1)
								{
									for (int i = 20 + 36; i <= 20 + 36 + 41; i++)
									{
										for (int j = 10 + 3; j <= 16 + 3; j++)
										{
											GotoXY(i, j); cout << " ";
										}
									}
									loadOption = SelectMenu(LoadingMenu());
									continue;
								}
								std::ifstream inputFile(SAVED_LIST);  // Thay thế "filename.txt" bằng đường dẫn tới file thực tế
								std::vector<std::string> lines;
								loadOption -= 1000;
								if (!inputFile) {
									//std::cout << "Không thể mở file." << std::endl;
									break;
								}

								std::string line;
								while (std::getline(inputFile, line)) {
									lines.push_back(line);
								}

								inputFile.close();

								if (lines.empty()) {
									//std::cout << "File rỗng." << std::endl;
									break;
								}

								lines.erase(lines.begin() + loadOption - 1);  // Xóa dong thu i
								fstream outFile;
								outFile.open(SAVED_LIST, std::ofstream::out | std::ofstream::trunc);
								for (int j = 0; j < lines.size(); j++)
								{
									outFile << lines[j] << endl;
								}
								TextColor(255);
								outFile.close();
								for (int j = 14; j <= 26; j++)
								{
									GotoXY(30, j); cout << "                          ";
								}
								for (int i = 20 + 36; i <= 20 + 36 + 41; i++)
								{
									for (int j = 10 + 3; j <= 16 + 3; j++)
									{
										GotoXY(i, j); cout << " ";
									}
								}
								loadOption = SelectMenu(LoadingMenu());
							}
							if (loadOption == -1) break;
							else
							{
								Loading();
								TextColor(255);
								LoadGame(RunLoadingMenu(loadOption), _A, _PLAYER1, _PLAYER2, _TURN, _COMMAND, _X, _Y, chedo);
								PlaySoundEffect("choose", SoundEffects);
								if (chedo == 2)//chơi với người
									RunGame(_A, _PLAYER1, _PLAYER2, _TURN, _COMMAND, _X, _Y, SoundEffects, chedo, song, songtemp);
								if (chedo == 3)//chơi với máy
									PlayWithComputer(_A, _TURN, _COMMAND, _PLAYER1, _PLAYER2, _X, _Y, validEnter, SoundEffects, chedo, song, songtemp);
								afterPlay = true;
								break;
							}
						}
					}
					if (y == 23)
					{
						//Menu Help trong game
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
						TextColor(255);
						HELP();
						afterPlay = false;
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
						About();
						afterPlay = false;
					}
					if (y == 25)
					{
						//SOUND
						TextColor(255);
						Sound(SoundEffects, song, songtemp);
						afterPlay = false;
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
						afterPlay = false;
					}
					if (y == 27)
					{
						//Loading();
						TextColor(255);
						system("cls");
						Sleep(103);
						PostMessage(GetConsoleWindow(), WM_CLOSE, 0, 0); // Câu lệnh này dùng để tắt màn hình game ngay lập tức
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
	drawFrame(5, 3, 80, 28);
	SetColor(0);
	printCaro(27, 7);
	GotoXY(10, 10);
	drawFrame(0, 0, 145, 33);
	PrintText("Press D to delete a file", 0, 30, 28);
	PrintText("Press ESC to return to MENU...", 8, 30, 29);
	SetColor(252);
	drawButton(menu.x - 25, menu.y - 10, "Saved Games");
	//drawButton(31, 14, "Saved Games");
	for (int i = 0; i < files.size(); i++)
	{
		name = "         " + files.at(i);
		PrintText(name, 0, menu.x - 27, menu.y + i - 7);
	}
	GotoXY(38, 27);
	return menu;
}
int EscMenu(_POINT _A[][BOARD_SIZE], bool& SoundEffects, int& song, int& songtemp)
{
	_MENU menu;
	menu.options = 3;
	//menu.x = _A[0][BOARD_SIZE - 1].x +40;
	//menu.y = Y_CENTER;
	menu.x = 117;
	menu.y = 30;
	// x = 74, y = 16 la toa do goc cua menu esc
	// 60 la do rong, 17 la do dai menu
	for (int i = 18; i <= 32; i++)
	{
		GotoXY(75, i);
		cout << "                                                       ";
	}
	drawFrame(74, 18, 60, 15);
	/*drawBox(74, 18, 60, 15);*/
	menu.cursorColor = 75;
	//DrawBoard(1, 1, 62, 25, menu.x - 23, menu.y - 19);
	//DrawBox(75, 63, 25, menu.x - 23, menu.y - 19);
	//DrawBigText("EscLogo.txt", 75, menu.x - 22, menu.y - 17);
	//drawButton((menu.x-23), (menu.y-9), "Continue");
	//PrintText("    Continue    ", 0, menu.x-22, menu.y-9);
	//PrintText("    Save game   ", 0, menu.x-22, menu.y -8);
	//drawButton((menu.x - 23), (menu.y - 8), "Save game");
	//PrintText("    Sound       ", 0, menu.x - 22, menu.y - 7);
	//PrintText("    Exit game   ", 0, menu.x-22, menu.y -7);
	//drawButton((menu.x - 23), (menu.y - 2), "Back to Menu");
	int x = 0, y = 0;
	while (true)
	{
		x = 100, y = 20;
		SetColor(4);
		drawSelectedButton((menu.x - 23), (menu.y - 11), "Continue");
		SetColor(0);
		drawButton((menu.x - 23), (menu.y - 8), "Save game");
		drawButton((menu.x - 23), (menu.y - 5), "Sound");
		drawButton((menu.x - 23), (menu.y - 2), "Back to Menu");
		ShowCur(0);
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
					}
					if (y == 20)
					{
						drawSelectedButton((menu.x - 23), (menu.y - 11), "Continue");
						drawButton((menu.x - 23), (menu.y - 8), "Save game");
						drawButton((menu.x - 23), (menu.y - 5), "Sound");
						drawButton((menu.x - 23), (menu.y - 2), "Back to Menu");
						ShowCur(0);
					}
					if (y == 21)
					{
						drawButton((menu.x - 23), (menu.y - 11), "Continue");
						drawSelectedButton((menu.x - 23), (menu.y - 8), "Save game");
						drawButton((menu.x - 23), (menu.y - 5), "Sound");
						drawButton((menu.x - 23), (menu.y - 2), "Back to Menu");
						ShowCur(0);
					}
					if (y == 22)
					{
						drawButton((menu.x - 23), (menu.y - 11), "Continue");
						drawButton((menu.x - 23), (menu.y - 8), "Save game");
						drawSelectedButton((menu.x - 23), (menu.y - 5), "Sound");
						drawButton((menu.x - 23), (menu.y - 2), "Back to Menu");
						ShowCur(0);
					}
					if (y == 23)
					{
						drawButton((menu.x - 23), (menu.y - 11), "Continue");
						drawButton((menu.x - 23), (menu.y - 8), "Save game");
						drawButton((menu.x - 23), (menu.y - 5), "Sound");
						drawSelectedButton((menu.x - 23), (menu.y - 2), "Back to Menu");
						ShowCur(0);
					}
					break;
				case 's':
				case KEY_ARROW_DOWN:
					if (y < 23)
					{
						y++;
					}
					if (y == 20)
					{
						drawSelectedButton((menu.x - 23), (menu.y - 11), "Continue");
						drawButton((menu.x - 23), (menu.y - 8), "Save game");
						drawButton((menu.x - 23), (menu.y - 5), "Sound");
						drawButton((menu.x - 23), (menu.y - 2), "Back to Menu");
						ShowCur(0);
					}
					if (y == 21)
					{
						drawButton((menu.x - 23), (menu.y - 11), "Continue");
						drawSelectedButton((menu.x - 23), (menu.y - 8), "Save game");
						drawButton((menu.x - 23), (menu.y - 5), "Sound");
						drawButton((menu.x - 23), (menu.y - 2), "Back to Menu");
						ShowCur(0);
					}
					if (y == 22)
					{
						drawButton((menu.x - 23), (menu.y - 11), "Continue");
						drawButton((menu.x - 23), (menu.y - 8), "Save game");
						drawSelectedButton((menu.x - 23), (menu.y - 5), "Sound");
						drawButton((menu.x - 23), (menu.y - 2), "Back to Menu");
						ShowCur(0);
					}
					if (y == 23)
					{
						drawButton((menu.x - 23), (menu.y - 11), "Continue");
						drawButton((menu.x - 23), (menu.y - 8), "Save game");
						drawButton((menu.x - 23), (menu.y - 5), "Sound");
						drawSelectedButton((menu.x - 23), (menu.y - 2), "Back to Menu");
						ShowCur(0);
					}
					break;
				case SPACE:
				case ENTER:
					if (y == 20)
					{
						//Continue
						return 1;
					}
					if (y == 21)
					{
						// Save 
						return 2;
					}
					if (y == 22)
					{
						SoundInGame(SoundEffects, song, songtemp);
						drawButton((menu.x - 23), (menu.y - 11), "Continue");
						drawButton((menu.x - 23), (menu.y - 8), "Save game");
						drawSelectedButton((menu.x - 23), (menu.y - 5), "Sound");
						drawButton((menu.x - 23), (menu.y - 2), "Back to Menu");
						ShowCur(0);
						break;
					}
					if (y == 23)
					{
						// Back to menu
						return 3;
					}
					break;
				}
			}
		}
	}
	return -1;
}
void LoadGame(string filename, _POINT _A[][BOARD_SIZE], _PLAYER& _PLAYER1, _PLAYER& _PLAYER2, bool& _TURN, int& _COMMAND, int& _X, int& _Y, int& chedo)
{
	system("cls");
	LoadData(filename, _A, _PLAYER1, _PLAYER2, _TURN, _COMMAND, _X, _Y, chedo);
	SetPlayerRank(_PLAYER1);
	SetPlayerRank(_PLAYER2);
	DrawBoard(BOARD_SIZE);
	ShowTurn(_A, _PLAYER1, _PLAYER2, _TURN);
	DrawLoaded(_A);
	GotoXY(_X, _Y);
	ShowCur(1);
	DrawBoardGiaoDien(_A, 240);
	DrawPhimTat(_A);
}
void SaveGame(_POINT _A[][BOARD_SIZE], _PLAYER _PLAYER1, _PLAYER _PLAYER2, bool _TURN, int chedo)
{
	bool overwrite = false;
	bool save = true;
	string filename;
	char key;
	int option;
	int x = 40;
	int exceed = 0;
	std::ifstream file(SAVED_LIST);  // Thay thế "filename.txt" bằng đường dẫn tới file thực tế

	if (!file) {
		//std::cout << "Không thể mở file." << std::endl;
		return;
	}

	std::string line;
	int count = 0;

	while (std::getline(file, line)) {
		count++;
	}

	file.close();
	do
	{
		GotoXY(x, 10 + 3); TextColor(176); for (int i = x; i <= x + 67; i++) cout << " ";
		GotoXY(x, 11 + 3); cout << " "; TextColor(240); cout << "                                                                  "; TextColor(176); cout << " ";
		GotoXY(x, 12 + 3); cout << " "; TextColor(240); cout << "                                                                  "; TextColor(176); cout << " ";
		GotoXY(x, 13 + 3); cout << " "; TextColor(240); SetColor(77); cout << "   Enter the name for your board (2-10 characters):               "; SetColor(0); TextColor(176); cout << " ";
		GotoXY(x, 14 + 3); cout << " "; TextColor(240); cout << "                                                                  "; TextColor(176); cout << " ";
		GotoXY(x, 15 + 3); cout << " "; TextColor(240); cout << "                                                                  "; TextColor(176); cout << " ";
		GotoXY(x, 16 + 3); for (int i = x; i <= x + 67; i++) cout << " ";
		// Yếu cầu người dùng nhập tên cho file
		TextColor(240);
		GotoXY(x + 53, 13 + 3);
		SetColor(0);
		ShowCur(1);
		std::getline(cin, filename);
		while (filename.length() < 2 || filename.length() > 10) {
			GotoXY(x, 10 + 3); TextColor(176); for (int i = x; i <= x + 67; i++) cout << " ";
			GotoXY(x, 11 + 3); cout << " "; TextColor(240); cout << "                                                  "; TextColor(176); cout << " ";
			GotoXY(x, 12 + 3); cout << " "; TextColor(240); cout << "                                                  "; TextColor(176); cout << " ";
			GotoXY(x, 13 + 3); cout << " "; TextColor(240); SetColor(77); cout << "   Enter the name for your board (2-10 characters):               "; SetColor(0); TextColor(176); cout << " ";
			GotoXY(x, 14 + 3); cout << " "; TextColor(240); cout << "                                                  "; TextColor(176); cout << " ";
			GotoXY(x, 15 + 3); cout << " "; TextColor(240); cout << "                                                  "; TextColor(176); cout << " ";
			GotoXY(x, 16 + 3); for (int i = x; i <= x + 67; i++) cout << " ";
			// Nếu tên không nằm trong khoảng kí tự cho phép thì nhập lại
			TextColor(240);
			GotoXY(x + 53, 13 + 3);
			SetColor(0);
			ShowCur(1);
			std::getline(cin, filename);
			//filename += ".txt";
		}
		while (count >= 10) {
			// Nếu số file đã là 10 rồi thì sẽ hiện lựa chọn hỏi có muốn ghi đè lên file đầu tiên không
			GotoXY(x + 4, 13 + 3); cout << " "; TextColor(240); SetColor(77); cout << "     Saves limit exceeded! Overwrite first save?            "; SetColor(0); //TextColor(176); cout << " ";
			int choice = 0;
			int currentPos = 0;
			GotoXY(x + 18+4, 14 + 3);
			SetColor(4);
			cout << "Yes";
			SetColor(7);
			GotoXY(x + 30+14, 14 + 3);
			cout << "No";
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
				else if (key == '\r' || key == SPACE) {
					break;
				}

				// Đổi màu chữ tùy theo lựa chọn
				if (choice != currentPos) {
					if (choice == 0) {
						GotoXY(x + 18 +4, 14 + 3);
						SetColor(4);
						cout << "Yes";
						SetColor(7);
						GotoXY(x + 30+14, 14 + 3);
						cout << "No";
						ShowCur(0);
					}
					else {
						GotoXY(x + 18+4, 14 + 3);
						cout << "Yes";
						GotoXY(x + 30+14, 14 + 3);
						SetColor(4);
						cout << "No";
						SetColor(7);
						ShowCur(0);
					}
					currentPos = choice;
				}
			}
			if (choice == 0) {
				std::ifstream inputFile(SAVED_LIST);  // Thay thế "filename.txt" bằng đường dẫn tới file thực tế
				std::vector<std::string> lines;

				if (!inputFile) {
					//std::cout << "Không thể mở file." << std::endl;
					return;
				}

				std::string line;
				while (std::getline(inputFile, line)) {
					lines.push_back(line);
				}

				inputFile.close();

				if (lines.empty()) {
					//std::cout << "File rỗng." << std::endl;
					return;
				}

				lines.erase(lines.begin());  // Xóa dòng đầu tiên

				std::ofstream outputFile(SAVED_LIST);  // Mở file ở chế độ ghi
				if (!outputFile) {
					//std::cout << "Không thể mở file." << std::endl;
					return;
				}

				for (const auto& line : lines) {
					outputFile << line << std::endl;
				}
				outputFile.close();
				//return;
				//save = false;
				TextColor(255);
				break;
			}
			else if (choice == 1){
				TextColor(255);
				return;
			}
		}
		filename += ".txt";
		if (CheckFileExistence(filename))
		{
			// Trường hợp file đã tồn tại trước đó, sẽ hiện thông báo hỏi có muốn ghi đè lên file trước đó không
			SetColor(3);
			GotoXY(x + 4, 13 + 3); TextColor(240); SetColor(77); cout << "     Already exist. Do you want to overwrite that file?"; SetColor(0);
			int choice = 0;
			int currentPos = 0;
			GotoXY(x + 18 + 4, 14 + 3);
			SetColor(4);
			cout << "Yes";
			SetColor(7);
			GotoXY(x + 30 + 14, 14 + 3);
			cout << "No";
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
				else if (key == '\r' || key == SPACE) {
					break;
				}

				// Đổi màu chữ tùy theo lựa chọn
				if (choice != currentPos) {
					if (choice == 0) {
						GotoXY(x + 18 + 4, 14 + 3);
						SetColor(4);
						cout << "Yes";
						SetColor(7);
						GotoXY(x + 30 + 14, 14 + 3);
						cout << "No";
						ShowCur(0);
					}
					else {
						GotoXY(x + 18 + 4, 14 + 3);
						cout << "Yes";
						GotoXY(x + 30 + 14, 14 + 3);
						SetColor(4);
						cout << "No";
						SetColor(7);
						ShowCur(0);
					}
					currentPos = choice;
				}
			}
			if (choice == 0)
			{
				exceed = 1;
				save = false;
			}
		}
		else save = false;
		ShowCur(1);
	} while (save);

	SaveData(filename, _A, _PLAYER1, _PLAYER2, _TURN, chedo);
	// Lưu dữ liệu của 2 người chơi và chế độ chơi (với người hoặc máy)

	if (!overwrite && !exceed)
	{
		std::fstream saveFile;
		saveFile.open(SAVED_LIST, std::fstream::app);

		saveFile << filename << "\n";

		saveFile.close();
	}
}
int SelectMenu(_MENU menu)
{
	int cursor = 1;
	char key;

	PrintText("--->", 4, menu.x - 22, menu.y-7);
	ShowCur(0);
	do
	{
		key = _getch();
		if ((key == 'w' || key == ARROW_UP) && cursor > 1)
		{
			PrintText("    ", 4, menu.x - 22, menu.y + cursor - 8);
			cursor--;
			PrintText("--->", 4, menu.x - 22, menu.y + cursor - 8);
		}
		else if ((key == 's' || key == ARROW_DOWN) && cursor < menu.options)
		{
			PrintText("    ", 4, menu.x - 22, menu.y + cursor - 8);
			cursor++;
			PrintText("--->", 4, menu.x - 22, menu.y + cursor - 8);
		}
		else if (key == ESC)
		{
			return -1;
		}
		else if (key == 100) // An phim D tren ban phim
		{
			return cursor + 1000;
		}
	} while (key != ENTER && key != 32);
	ShowCur(1);
	return cursor;
}
void RunEscMenu(_POINT _A[][BOARD_SIZE], _PLAYER _PLAYER1, _PLAYER _PLAYER2, bool _TURN, int option, bool& runGame, int chedo, int& song, int& songtemp)
{
	switch (option)
	{
	case 1: case -1:
		// Nếu người dùng chọn Continue (trường hợp option==1) hoặc bấm ESC (optione == -1) thì sẽ xóa các nút menu và vẽ lại giao
		// diện khi đang chơi để tiếp tục chơi
		for (int i = 70; i < 120; i++)
		{
			for (int j = 19; j <= 30; j++)
			{
				GotoXY(i, j);
				cout << " ";
			}
			
		}
		DrawBoardGiaoDien(_A, 240);
		DrawPhimTat(_A);
		break;
	case 2:
		// Người dùng chọn lưu game
		SaveGame(_A, _PLAYER1, _PLAYER2, _TURN, chedo);
		runGame = false;
		break;
	case 3:
		// Người dùng chọn thoát game
		runGame = false;
		break;
	}
}

string RunLoadingMenu(int option)
{
	string filename;
	std::vector<string> files;

	files = LoadFiles();
	filename = files.at(option - 1);

	return filename;
}

void PlayWithComputer(_POINT _A[][BOARD_SIZE], bool &_TURN, int &_COMMAND, _PLAYER &_PLAYER1, _PLAYER &_PLAYER2, int &_X, int &_Y, bool validEnter, bool& SoundEffects, int& chedo, int& song, int& songtemp) {
	FixConsoleWindow();
	chedo = 3;
	int escOption;
	short int toadothang[24];
	bool runGame = true;
	GotoXY(_X, _Y);
	while (runGame)
	{
		ShowPlayerInfo(_A, _PLAYER1, _PLAYER2);
		GotoXY(_X, _Y);
		if (_TURN == true)
		{
			_COMMAND = toupper(_getch());
			if (_COMMAND == ESC)
			{
				escOption = EscMenu(_A, SoundEffects, song, songtemp);
				RunEscMenu(_A, _PLAYER1, _PLAYER2, _TURN, escOption, runGame, chedo, song, songtemp);
			}
			if (_COMMAND == 'W' || _COMMAND == ARROW_UP) 
			{
				TextColor(2);
				if (_COMMAND == 'W')
				{
					GotoXY(87, 20);
					cout << "|\\ ___\\";
					GotoXY(87, 21);
					cout << "| | W |";
					GotoXY(88, 22);
					cout << "\\|___|";
					MoveUp(_A, _X, _Y);
					TextColor(255);
					SetColor(0);
					Sleep(50);
					GotoXY(87, 20);
					cout << "|\\ ___\\";
					GotoXY(87, 21);
					cout << "| | W |";
					GotoXY(88, 22);
					cout << "\\|___|";
				}
				else
				{
					GotoXY(84 + 34, 20);
					cout << "|\\ ___\\";
					GotoXY(84 + 34, 21);
					cout << "| | ^ |";
					GotoXY(85 + 34, 22);
					cout << "\\|___|";
					MoveUp(_A, _X, _Y);
					TextColor(255);
					SetColor(0);
					Sleep(50);
					GotoXY(84 + 34, 20);
					cout << "|\\ ___\\";
					GotoXY(84 + 34, 21);
					cout << "| | ^ |";
					GotoXY(85 + 34, 22);
					cout << "\\|___|";
				}
			}
			else if (_COMMAND == 'S' || _COMMAND == ARROW_DOWN)
			{
				TextColor(2);
				if (_COMMAND == 'S')
				{
					GotoXY(89, 23);
					cout << "| S |";
					GotoXY(89, 24);
					cout << "|___|";
					MoveDown(_A, _X, _Y);
					TextColor(255);
					SetColor(0);
					Sleep(50);
					GotoXY(89, 23);
					cout << "| S |";
					GotoXY(89, 24);
					cout << "|___|";
				}
				else
				{
					GotoXY(86 + 34, 23);
					cout << "| v |";
					GotoXY(86 + 34, 24);
					cout << "|___|";
					MoveDown(_A, _X, _Y);
					TextColor(255);
					SetColor(0);
					Sleep(50);
					GotoXY(86 + 34, 23);
					cout << "| v |";
					GotoXY(86 + 34, 24);
					cout << "|___|";
				}
			}
			else if (_COMMAND == 'A' || _COMMAND == ARROW_LEFT)
			{
				TextColor(2);
				if (_COMMAND == 'A')
				{
					GotoXY(83, 22);
					cout << "|\\ __\\";
					GotoXY(83, 23);
					cout << "| | A ";
					GotoXY(84, 24);
					cout << "\\|___";
					MoveLeft(_A, _X, _Y);
					Sleep(50);
					TextColor(255);
					SetColor(0);
					GotoXY(83, 22);
					cout << "|\\ __\\";
					GotoXY(83, 23);
					cout << "| | A ";
					GotoXY(84, 24);
					cout << "\\|___";
				}
				else
				{
					GotoXY(80 + 34, 22);
					cout << "|\\ __\\";
					GotoXY(80 + 34, 23);
					cout << "| | < ";
					GotoXY(81 + 34, 24);
					cout << "\\|___";
					MoveLeft(_A, _X, _Y);
					Sleep(50);
					TextColor(255);
					SetColor(0);
					GotoXY(80 + 34, 22);
					cout << "|\\ __\\";
					GotoXY(80 + 34, 23);
					cout << "| | < ";
					GotoXY(81 + 34, 24);
					cout << "\\|___";
				}
			}
			else if (_COMMAND == 'D' || _COMMAND == ARROW_RIGHT)
			{
				TextColor(2);
				if (_COMMAND == 'D')
				{
					GotoXY(93, 22);
					cout << "| _\\";
					GotoXY(93, 23);
					cout << "| D |";
					GotoXY(93, 24);
					cout << "|___|";
					MoveRight(_A, _X, _Y);
					Sleep(50);
					TextColor(255);
					SetColor(0);
					GotoXY(93, 22);
					cout << "| _\\";
					GotoXY(93, 23);
					cout << "| D |";
					GotoXY(93, 24);
					cout << "|___|";
				}
				else
				{
					GotoXY(90 + 34, 22);
					cout << "| _\\";
					GotoXY(90 + 34, 23);
					cout << "| > |";
					GotoXY(90 + 34, 24);
					cout << "|___|";
					MoveRight(_A, _X, _Y);
					Sleep(50);
					TextColor(255);
					SetColor(0);
					GotoXY(90 + 34, 22);
					cout << "| _\\";
					GotoXY(90 + 34, 23);
					cout << "| > |";
					GotoXY(90 + 34, 24);
					cout << "|___|";
				}
			}
			else if (_COMMAND == 13 || _COMMAND == SPACE) {// Người dùng đánh dấu trên màn hình bàn cờ
				PlaySoundEffect("move", SoundEffects);
				switch (CheckBoard(_X, _Y, _A, _TURN)) {
				case -1:
				{
					SetColor(1);
					printf("X");
					TextColor(2);
					if (_COMMAND == ENTER)
					{
						GotoXY(120, 26);
						cout << "|\\____\\";
						GotoXY(120, 27);
						cout << "||    |";
						GotoXY(114, 28);
						cout << "|\\ ___\\|    |";
						GotoXY(114, 29);
						cout << "| |  Enter  |";
						GotoXY(115, 30);
						cout << "\\|_________|";
					}
					else
					{
						GotoXY(79, 28);
						cout << "|\\          Space          \\";
						GotoXY(79, 29);
						cout << "\\ \\_________________________\\";
						GotoXY(80, 30);
						cout << "\\|_________________________|";
					}
					Sleep(50);
					TextColor(255);
					SetColor(0);
					if (_COMMAND == ENTER)
					{
						GotoXY(120, 26);
						cout << "|\\____\\";
						GotoXY(120, 27);
						cout << "||    |";
						GotoXY(114, 28);
						cout << "|\\ ___\\|    |";
						GotoXY(114, 29);
						cout << "| |  Enter  |";
						GotoXY(115, 30);
						cout << "\\|_________|";
					}
					else
					{
						GotoXY(79, 28);
						cout << "|\\          Space          \\";
						GotoXY(79, 29);
						cout << "\\ \\_________________________\\";
						GotoXY(80, 30);
						cout << "\\|_________________________|";
					}
					break;
				}
				case 0: validEnter = false;
				}
				if (validEnter == true) {
					switch (ProcessFinish(TestBoard(_A, _TURN, GetRowIndex(_Y), GetColIndex(_X), toadothang), _A, _TURN, _X, _Y, toadothang, SoundEffects, _PLAYER1, _PLAYER2)) {
					case -1: case 1: case 0:
						if (AskContinue(_A) != 'Y') {
							StopMusic();
							system("cls");
							return;
						}
						else StartGame(_A, _TURN, _COMMAND, _X, _Y, _PLAYER1, _PLAYER2);
					}
				}
				validEnter = true; // Mở khóa
			}
		}
		else
		{
			timkiemnuocdi(_A, _TURN, _COMMAND, _X, _Y, validEnter, SoundEffects);
			_X = timkiemnuocdi(_A, _TURN, _COMMAND, _X, _Y, validEnter, SoundEffects).x;
			_Y = timkiemnuocdi(_A, _TURN, _COMMAND, _X, _Y, validEnter, SoundEffects).y;
			GotoXY(_X, _Y);
			Sleep(500);
			switch (CheckBoard(_X, _Y, _A, _TURN)) {
			case 1:
			{
				SetColor(2);
				printf("O");
				break;
			}
			case 0: validEnter = false;
			}
			if (validEnter == true) {
				switch (ProcessFinish(TestBoard(_A, _TURN, GetRowIndex(_Y), GetColIndex(_X), toadothang), _A, _TURN, _X, _Y, toadothang, SoundEffects, _PLAYER1, _PLAYER2)) {
				case -1: case 1: case 0:
					if (AskContinue(_A) != 'Y') {
						StopMusic();
						system("cls");
						return;
					}
					else StartGame(_A, _TURN, _COMMAND, _X, _Y, _PLAYER1, _PLAYER2);
				}
			}
			validEnter = true; // Mở khóa
		}
	}
}


