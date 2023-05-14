#include "Control.h"


void StartGame(_POINT _A[][BOARD_SIZE], bool& _TURN, int& _COMMAND, int& _X, int& _Y, _PLAYER& _PLAYER1, _PLAYER& _PLAYER2)
{
	SetPlayerRank(_PLAYER1);
	SetPlayerRank(_PLAYER2);
	system("cls");
	ResetData(_A, _TURN, _COMMAND, _X, _Y); // Khởi tạo dữ liệu gốc
	DrawBoard(BOARD_SIZE); // Vẽ màn hình game
	/*int x = _A[0][0].x;
	int y = _A[0][0].y;
	GotoXY(x, y);*/
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
void RunGame(_POINT _A[][BOARD_SIZE], _PLAYER& _PLAYER1, _PLAYER& _PLAYER2, bool& _TURN, int& _COMMAND, int& _X, int& _Y, bool& SoundEffects, int& chedo)
{
	chedo = 2;
	bool validEnter = true;
	bool runGame = true;
	int escOption;
	short int toadothang[24];
	//PlaySoundA("NhacGame.wav", NULL, SND_ASYNC | SND_LOOP);
	while (runGame)
	{
		ShowPlayerInfo(_A, _PLAYER1, _PLAYER2);
		GotoXY(_X, _Y);
		_COMMAND = toupper(_getch());
		if (_COMMAND == ESC)
		{
			escOption = EscMenu(_A);
			RunEscMenu(_A, _PLAYER1, _PLAYER2, _TURN, escOption, runGame, chedo);
		}
		else
		{
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
	int x = 53;
	do
	{
		/*GotoXY(x, 10+3); SetColor(3); for (int i = x; i <= x + 50; i++) cout << (char)178;
		GotoXY(x, 11 + 3); cout << (char)178 << "                                                 " << (char)178;
		GotoXY(x, 12+3); cout << (char)178 << "                                                 " << (char)178;
		GotoXY(x, 13 + 3); cout << (char)178 << "   Enter the name for your board:                " << (char)178;
		GotoXY(x, 14 + 3); cout << (char)178 << "                                                 " << (char)178;
		GotoXY(x, 15+3); cout << (char)178 << "                                                 " << (char)178;
		GotoXY(x, 16+3); SetColor(3); for (int i = x; i <= x + 50; i++) cout << (char)178;
		GotoXY(x + 35, 13 + 3);*/
		GotoXY(x, 10 + 3); TextColor(176); for (int i = x; i <= x + 50; i++) cout << " ";
		GotoXY(x, 11 + 3); cout << " ";TextColor(240);cout << "                                                 ";TextColor(176);cout << " ";
		GotoXY(x, 12 + 3); cout << " ";TextColor(240);cout << "                                                 ";TextColor(176);cout << " ";
		GotoXY(x, 13 + 3); cout << " "; TextColor(240); SetColor(77); cout << "   Enter the name for your board:                "; SetColor(0); TextColor(176); cout << " ";
		GotoXY(x, 14 + 3); cout << " ";TextColor(240);cout << "                                                 ";TextColor(176);cout << " ";
		GotoXY(x, 15 + 3); cout << " ";TextColor(240);cout << "                                                 ";TextColor(176);cout << " ";
		GotoXY(x, 16 + 3); for (int i = x; i <= x + 50; i++) cout << " ";
		TextColor(240);
		GotoXY(x + 35, 13 + 3);
		SetColor(0);
		ShowCur(1);
		std::getline(cin, filename);
		filename += ".txt";
		if (CheckFileExistence(filename))
		{
			SetColor(3);
			GotoXY(x, 12 + 3); TextColor(176);cout << " ";TextColor(240);cout << "                                                 ";;TextColor(176);cout << " ";
			GotoXY(x + 4, 13 + 3); TextColor(240); SetColor(77); cout << "Already exist. Do you want to overwrite it?"; SetColor(0);
			/*PrintText("Ten da ton tai", 0, X_CENTER - 40, Y_CENTER -8);
			PrintText("Ban co muon luu de?", 0, X_CENTER - 40, Y_CENTER -7);*/
			//option = SelectMenu(YesNoMenu(X_CENTER-15, Y_CENTER+3));
			//key = RunYesNoMenu(option);
			//if (key == 'Y')
			//{
			//	overwrite = true;
			//	save = false;
			//}
			int choice = 0;
			int currentPos = 0;
			GotoXY(x + 18, 14 + 3);
			SetColor(4);
			cout << "Yes";
			SetColor(7);
			GotoXY(x + 30, 14 + 3);
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
						GotoXY(x + 18, 14 + 3);
						SetColor(4);
						cout << "Yes";
						SetColor(7);
						GotoXY(x + 30, 14 + 3);
						cout << "No";
						ShowCur(0);
					}
					else {
						GotoXY(x + 18, 14 + 3);
						cout << "Yes";
						GotoXY(x + 30, 14 + 3);
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
				overwrite = true;
				save = false;
			}
		}
		else save = false;
		ShowCur(1);
	} while (save);

	SaveData(filename, _A, _PLAYER1, _PLAYER2, _TURN, chedo);

	if (!overwrite)
	{
		std::fstream saveFile;
		saveFile.open(SAVED_LIST, std::fstream::app);

		saveFile << filename << "\n";

		saveFile.close();
	}
}
char RunYesNoMenu(int option)
{
	switch (option)
	{
	case 1:
		return 'Y';
	case 2:
		return 'N';
	}
}
// Hàm này giờ không cần nữa (hàm runyesnomenu)
int SelectMenu(_MENU menu)
{
	int cursor = 1;
	char key;

	PrintText("", menu.cursorColor, menu.x - 18, menu.y-7);

	do
	{
		key = _getch();
		if ((key == 'w'||key== ARROW_UP)&& cursor > 1)
		{
			PrintText("", menu.cursorColor, menu.x - 18, menu.y + cursor - 8);
			cursor--;
			PrintText("", menu.cursorColor, menu.x - 18, menu.y + cursor - 8);
		}
		else if ((key == 's'||key==ARROW_DOWN) && cursor < menu.options)
		{
			PrintText("", menu.cursorColor, menu.x - 18, menu.y + cursor - 8);
			cursor++;
			PrintText("", menu.cursorColor, menu.x - 18, menu.y + cursor - 8);
		}
		else if (key == ESC)
		{
			return -1;
		}
	} while (key != ENTER && key != 32);

	return cursor;
}
int SelectMenu1(_MENU menu)
{
	int cursor1 = 1;
	int cursor2 = 1;
	char key;

	PrintText("", 4, menu.x - 18, menu.y - 8);

	do
	{
		key = _getch();
		if ((key == 'w' || key == ARROW_UP) && cursor2 > 1)
		{
			PrintText("", 4, menu.x - 18, menu.y + cursor1 - 9);
			cursor1 = cursor1-3;
			cursor2--;
			PrintText("", 4, menu.x - 18, menu.y + cursor1 - 9);
		}
		else if ((key == 's' || key == ARROW_DOWN) && cursor2 < menu.options)
		{
			PrintText("", 4, menu.x - 18, menu.y + cursor1 - 9);
			cursor1 = cursor1+3;
			cursor2++;
			PrintText("", 4, menu.x - 18, menu.y + cursor1 - 9);
		}
		else if (key == ESC)
		{
			return -1;
		}
	} while (key != ENTER && key != 32);

	return cursor2;
}
void RunEscMenu(_POINT _A[][BOARD_SIZE], _PLAYER _PLAYER1, _PLAYER _PLAYER2, bool _TURN, int option, bool& runGame, int chedo)
{
	switch (option)
	{
	case 1: case -1:
		//system("cls");
		//DrawBoard(BOARD_SIZE);
		//DrawLoaded(_A);  // Hàm này vẽ lại chữ X O nên không cần
		//ShowTurn(_A, _PLAYER1, _PLAYER2, _TURN);
		//ShowCur(1);
		for (int i = 70; i < 120; i++)
		{
			for (int j = 20; j <= 30; j++)
			{
				GotoXY(i, j);
				cout << " ";
			}
			
		}
		DrawBoardGiaoDien(_A, 240);
		DrawPhimTat(_A);
		break;
	case 2:
		SaveGame(_A, _PLAYER1, _PLAYER2, _TURN, chedo);
		runGame = false;
		break;
	/*case 3:
		bool SoundEffects;
		Sound(SoundEffects);
		break;*/
	case 3:
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
/*void PlayWithComputer(_POINT _A[][BOARD_SIZE], bool _TURN, int _COMMAND, int _X, int _Y, bool validEnter, bool& SoundEffects) {
	FixConsoleWindow();
	_PLAYER _PLAYER1, _PLAYER2;
	StartGame(_A, _TURN, _COMMAND, _X, _Y);
	StopMusic();
	int escOption;
	short int toadothang[24];
	bool runGame = true;
	while (1)
	{
		if (_TURN == true)
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
			if (_COMMAND == 'A' || _COMMAND == ARROW_LEFT) MoveLeft(_A, _X, _Y);
			else if (_COMMAND == 'W' || _COMMAND == ARROW_UP) MoveUp(_A, _X, _Y);
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
				case 0: validEnter = false;
				}
				if (validEnter == true) {
					switch (ProcessFinish(TestBoard(_A, _TURN, GetRowIndex(_Y), GetColIndex(_X), toadothang), _A, _TURN, _X, _Y, toadothang, SoundEffects)) {
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
		else
		{
			timkiemnuocdi(_A, _TURN, _COMMAND, _X, _Y, validEnter, SoundEffects);
			_X = timkiemnuocdi(_A, _TURN, _COMMAND, _X, _Y, validEnter, SoundEffects).x;
			_Y = timkiemnuocdi(_A, _TURN, _COMMAND, _X, _Y, validEnter, SoundEffects).y;
			GotoXY(_X, _Y);
			Sleep(200);
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
				switch (ProcessFinish(TestBoard(_A, _TURN, GetRowIndex(_Y), GetColIndex(_X), toadothang), _A, _TURN, _X, _Y, toadothang, SoundEffects)) {
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
}*/
void PlayWithComputer(_POINT _A[][BOARD_SIZE], bool &_TURN, int &_COMMAND, _PLAYER &_PLAYER1, _PLAYER &_PLAYER2, int &_X, int &_Y, bool validEnter, bool& SoundEffects, int& chedo) {
	FixConsoleWindow();
	//StartGame(_A, _TURN, _COMMAND, _X, _Y);
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
				escOption = EscMenu(_A);
				RunEscMenu(_A, _PLAYER1, _PLAYER2, _TURN, escOption, runGame, chedo);
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


