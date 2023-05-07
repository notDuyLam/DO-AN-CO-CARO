﻿#include "Control.h"


void StartGame(_POINT _A[][BOARD_SIZE], bool& _TURN, int& _COMMAND, int& _X, int& _Y, _PLAYER& _PLAYER1, _PLAYER& _PLAYER2, bool& vsComputer)
{
	if(!vsComputer)
	{
		SetPlayerRank(_PLAYER1);
		SetPlayerRank(_PLAYER2);
	}
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

/*void GamePlay(_POINT _A[][BOARD_SIZE], bool _TURN, int _COMMAND, int _X, int _Y, bool validEnter, bool& MO_NHAC)
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
				PlaySoundEffect("move", MO_NHAC);
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
					switch (ProcessFinish(TestBoard(_A, _TURN, GetRowIndex(_Y), GetColIndex(_X),toadothang), _A, _TURN, _X, _Y,toadothang, MO_NHAC)) {
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
void RunGame(_POINT _A[][BOARD_SIZE], _PLAYER& _PLAYER1, _PLAYER& _PLAYER2, bool& _TURN, int& _COMMAND, int& _X, int& _Y, bool& MO_NHAC, int& chedo)
{
	chedo = 2;
	bool vsComputer = false;
	bool validEnter = true;
	bool runGame = true;
	int escOption;
	short int toadothang[24];
	//PlaySoundA("NhacGame.wav", NULL, SND_ASYNC | SND_LOOP);
	while (runGame)
	{
		//ShowPlayerInfo(_A, _PLAYER1, _PLAYER2);
		GotoXY(_X, _Y);
		_COMMAND = toupper(_getch());
		if (_COMMAND == ESC)
		{
			escOption = SelectMenu1(EscMenu(_A));
			RunEscMenu(_A, _PLAYER1, _PLAYER2, _TURN, escOption, runGame, chedo);
		}
		else
		{
			if (_COMMAND == 'W' || _COMMAND == ARROW_UP) 
			{
				TextColor(2);
				if (_COMMAND == 'W')
				{
					GotoXY(84, 21);
					cout << "|\\ ___\\";
					GotoXY(84, 22);
					cout << "| | W |";
					GotoXY(85, 23);
					cout << "\\|___|";
					MoveUp(_A, _X, _Y);
					TextColor(255);
					SetColor(0);
					Sleep(50);
					GotoXY(84, 21);
					cout << "|\\ ___\\";
					GotoXY(84, 22);
					cout << "| | W |";
					GotoXY(85, 23);
					cout << "\\|___|";
				}
				else
				{
					GotoXY(84+17, 21);
					cout << "|\\ ___\\";
					GotoXY(84+17, 22);
					cout << "| | ^ |";
					GotoXY(85+17, 23);
					cout << "\\|___|";
					MoveUp(_A, _X, _Y);
					TextColor(255);
					SetColor(0);
					Sleep(50);
					GotoXY(84+17, 21);
					cout << "|\\ ___\\";
					GotoXY(84+17, 22);
					cout << "| | ^ |";
					GotoXY(85+17, 23);
					cout << "\\|___|";
				}
			}
			else if (_COMMAND == 'S' || _COMMAND == ARROW_DOWN) 
			{
				TextColor(2);
				if(_COMMAND == 'S')
				{
					GotoXY(86, 24);
					cout << "| S |";
					GotoXY(86, 25);
					cout << "|___|";
					MoveDown(_A, _X, _Y);
					TextColor(255);
					SetColor(0);
					Sleep(50);
					GotoXY(86, 24);
					cout << "| S |";
					GotoXY(86, 25);
					cout << "|___|";
				}
				else
				{
					GotoXY(86+17, 24);
					cout << "| v |";
					GotoXY(86+17, 25);
					cout << "|___|";
					MoveDown(_A, _X, _Y);
					TextColor(255);
					SetColor(0);
					Sleep(50);
					GotoXY(86+17, 24);
					cout << "| v |";
					GotoXY(86+17, 25);
					cout << "|___|";
				}
			}
			else if (_COMMAND == 'A' || _COMMAND == ARROW_LEFT)
			{
				TextColor(2);
				if (_COMMAND == 'A')
				{
					GotoXY(80, 23);
					cout << "|\\ __\\";
					GotoXY(80, 24);
					cout << "| | A ";
					GotoXY(81, 25);
					cout << "\\|___";
					MoveLeft(_A, _X, _Y);
					Sleep(50);
					TextColor(255);
					SetColor(0);
					GotoXY(80, 23);
					cout << "|\\ __\\";
					GotoXY(80, 24);
					cout << "| | A ";
					GotoXY(81, 25);
					cout << "\\|___";
				}
				else
				{
					GotoXY(80+17, 23);
					cout << "|\\ __\\";
					GotoXY(80+17, 24);
					cout << "| | < ";
					GotoXY(81+17, 25);
					cout << "\\|___";
					MoveLeft(_A, _X, _Y);
					Sleep(50);
					TextColor(255);
					SetColor(0);
					GotoXY(80+17, 23);
					cout << "|\\ __\\";
					GotoXY(80+17, 24);
					cout << "| | < ";
					GotoXY(81+17, 25);
					cout << "\\|___";
				}
			}
			else if (_COMMAND == 'D' || _COMMAND == ARROW_RIGHT) 
			{
				TextColor(2);
				if(_COMMAND=='D')
				{
					GotoXY(90, 23);
					cout << "| _\\";
					GotoXY(90, 24);
					cout << "| D |";
					GotoXY(90, 25);
					cout << "|___|";
					MoveRight(_A, _X, _Y);
					Sleep(50);
					TextColor(255);
					SetColor(0);
					GotoXY(90, 23);
					cout << "| _\\";
					GotoXY(90, 24);
					cout << "| D |";
					GotoXY(90, 25);
					cout << "|___|";
				}
				else
				{
					GotoXY(90+17, 23);
					cout << "| _\\";
					GotoXY(90+17, 24);
					cout << "| > |";
					GotoXY(90+17, 25);
					cout << "|___|";
					MoveRight(_A, _X, _Y);
					Sleep(50);
					TextColor(255);
					SetColor(0);
					GotoXY(90+17, 23);
					cout << "| _\\";
					GotoXY(90+17, 24);
					cout << "| > |";
					GotoXY(90+17, 25);
					cout << "|___|";
				}
			}
			else if (_COMMAND == ENTER || _COMMAND == SPACE)
			{
				PlaySoundEffect("move", MO_NHAC);

				switch (CheckBoard(_X, _Y, _A, _TURN))
				{
				case P_X:
				{
					SetColor(1);
					printf("X");
					TextColor(2);
					if(_COMMAND == ENTER)
					{
						GotoXY(120, 21);
						cout << "|\\____\\";
						GotoXY(120, 22);
						cout << "||    |";
						GotoXY(114, 23);
						cout << "|\\ ___\\|    |";
						GotoXY(114, 24);
						cout << "| |  Enter  |";
						GotoXY(115, 25);
						cout << "\\|_________|";
					}
					else
					{
						GotoXY(88, 28);
						cout << "|\\          Space          \\";
						GotoXY(88, 29);
						cout << "\\ \\_________________________\\";
						GotoXY(89, 30);
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
						GotoXY(120, 21);
						cout << "|\\____\\";
						GotoXY(120, 22);
						cout << "||    |";
						GotoXY(114, 23);
						cout << "|\\ ___\\|    |";
						GotoXY(114, 24);
						cout << "| |  Enter  |";
						GotoXY(115, 25);
						cout << "\\|_________|";
					}
					else
					{
						GotoXY(88, 28);
						cout << "|\\          Space          \\";
						GotoXY(88, 29);
						cout << "\\ \\_________________________\\";
						GotoXY(89, 30);
						cout << "\\|_________________________|";
					}
					break;
				}
				case 0:
					TextColor(2);
					if (_COMMAND == ENTER)
					{
						GotoXY(120, 21);
						cout << "|\\____\\";
						GotoXY(120, 22);
						cout << "||    |";
						GotoXY(114, 23);
						cout << "|\\ ___\\|    |";
						GotoXY(114, 24);
						cout << "| |  Enter  |";
						GotoXY(115, 25);
						cout << "\\|_________|";
					}
					else
					{
						GotoXY(88, 28);
						cout << "|\\          Space          \\";
						GotoXY(88, 29);
						cout << "\\ \\_________________________\\";
						GotoXY(89, 30);
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
					GotoXY(120, 21);
					cout << "|\\____\\";
					GotoXY(120, 22);
					cout << "||    |";
					GotoXY(114, 23);
					cout << "|\\ ___\\|    |";
					GotoXY(114, 24);
					cout << "| |  Enter  |";
					GotoXY(115, 25);
					cout << "\\|_________|";
				}
				else
				{
					GotoXY(88, 28);
					cout << "|\\          Space          \\";
					GotoXY(88, 29);
					cout << "\\ \\_________________________\\";
					GotoXY(89, 30);
					cout << "\\|_________________________|";
				}
				// Tiếp theo là kiểm tra và xử lý thắng/thua/hòa/tiếp tục
				if (validEnter == true) {
					switch (ProcessFinish(TestBoard(_A, _TURN, GetRowIndex(_Y), GetColIndex(_X), toadothang), _A, _TURN, _X, _Y, toadothang, MO_NHAC, _PLAYER1, _PLAYER2)) {
					case -1: case 1: case 0:
						if (AskContinue(_A) != 'Y') {
							StopMusic();
							system("cls");
							return;
						}
						else StartGame(_A, _TURN, _COMMAND, _X, _Y, _PLAYER1, _PLAYER2, vsComputer);
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
	//SetPlayerRank(_PLAYER1);
	//SetPlayerRank(_PLAYER2);
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

	do
	{
		system("cls");
		PrintText("Nhap ten muon luu game: ", 0, X_CENTER-40, Y_CENTER-10);
		std::getline(cin, filename);
		filename += ".txt";
		if (CheckFileExistence(filename))
		{
			PrintText("Ten da ton tai", 0, X_CENTER - 40, Y_CENTER -8);
			PrintText("Ban co muon luu de?", 0, X_CENTER - 40, Y_CENTER -7);
			option = SelectMenu(YesNoMenu(X_CENTER-15, Y_CENTER+3));
			key = RunYesNoMenu(option);
			if (key == 'Y')
			{
				overwrite = true;
				save = false;
			}
		}
		else save = false;
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

	PrintText("", 4, menu.x - 16, menu.y - 9);

	do
	{
		key = _getch();
		if ((key == 'w' || key == ARROW_UP) && cursor2 > 1)
		{
			PrintText("", 4, menu.x - 16, menu.y + cursor1 - 10);
			cursor1 = cursor1-3;
			cursor2--;
			PrintText("", 4, menu.x - 16, menu.y + cursor1 - 10);
		}
		else if ((key == 's' || key == ARROW_DOWN) && cursor2 < menu.options)
		{
			PrintText("", 4, menu.x - 16, menu.y + cursor1 - 10);
			cursor1 = cursor1+3;
			cursor2++;
			PrintText("", 4, menu.x - 16, menu.y + cursor1 - 10);
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
		system("cls");
		DrawBoard(BOARD_SIZE);
		DrawLoaded(_A);
		ShowTurn(_A, _PLAYER1, _PLAYER2, _TURN);
		ShowCur(1);
		DrawBoardGiaoDien(_A, 240);
		DrawPhimTat(_A);
		break;
	case 2:
		SaveGame(_A, _PLAYER1, _PLAYER2, _TURN, chedo);
		runGame = false;
		break;
	/*case 3:
		bool MO_NHAC;
		Sound(MO_NHAC);
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
/*void PlayWithComputer(_POINT _A[][BOARD_SIZE], bool _TURN, int _COMMAND, int _X, int _Y, bool validEnter, bool& MO_NHAC) {
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
				PlaySoundEffect("move", MO_NHAC);
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
					switch (ProcessFinish(TestBoard(_A, _TURN, GetRowIndex(_Y), GetColIndex(_X), toadothang), _A, _TURN, _X, _Y, toadothang, MO_NHAC)) {
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
			timkiemnuocdi(_A, _TURN, _COMMAND, _X, _Y, validEnter, MO_NHAC);
			_X = timkiemnuocdi(_A, _TURN, _COMMAND, _X, _Y, validEnter, MO_NHAC).x;
			_Y = timkiemnuocdi(_A, _TURN, _COMMAND, _X, _Y, validEnter, MO_NHAC).y;
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
				switch (ProcessFinish(TestBoard(_A, _TURN, GetRowIndex(_Y), GetColIndex(_X), toadothang), _A, _TURN, _X, _Y, toadothang, MO_NHAC)) {
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
void PlayWithComputer(_POINT _A[][BOARD_SIZE], bool &_TURN, int &_COMMAND, _PLAYER &_PLAYER1, _PLAYER &_PLAYER2, int &_X, int &_Y, bool validEnter, bool& MO_NHAC, int& chedo) {
	FixConsoleWindow();
	//StartGame(_A, _TURN, _COMMAND, _X, _Y);
	StopMusic();
	bool vsComputer = true;
	chedo = 3;
	int escOption;
	short int toadothang[24];
	bool runGame = true;
	GotoXY(_X, _Y);
	while (1)
	{
		GotoXY(_X, _Y);
		if (_TURN == true)
		{
			_COMMAND = toupper(_getch());
			if (_COMMAND == ESC)
			{
				escOption = SelectMenu1(EscMenu(_A));
				RunEscMenu(_A, _PLAYER1, _PLAYER2, _TURN, escOption, runGame, chedo);
			}
			if (_COMMAND == 27)
			{
				system("cls");
				return;
			}
			if (_COMMAND == 'W' || _COMMAND == ARROW_UP) 
			{
				TextColor(2);
				if (_COMMAND == 'W')
				{
					GotoXY(84, 21);
					cout << "|\\ ___\\";
					GotoXY(84, 22);
					cout << "| | W |";
					GotoXY(85, 23);
					cout << "\\|___|";
					MoveUp(_A, _X, _Y);
					TextColor(255);
					SetColor(0);
					Sleep(50);
					GotoXY(84, 21);
					cout << "|\\ ___\\";
					GotoXY(84, 22);
					cout << "| | W |";
					GotoXY(85, 23);
					cout << "\\|___|";
				}
				else
				{
					GotoXY(84+17, 21);
					cout << "|\\ ___\\";
					GotoXY(84+17, 22);
					cout << "| | ^ |";
					GotoXY(85+17, 23);
					cout << "\\|___|";
					MoveUp(_A, _X, _Y);
					TextColor(255);
					SetColor(0);
					Sleep(50);
					GotoXY(84+17, 21);
					cout << "|\\ ___\\";
					GotoXY(84+17, 22);
					cout << "| | ^ |";
					GotoXY(85+17, 23);
					cout << "\\|___|";
				}
			}
			else if (_COMMAND == 'S' || _COMMAND == ARROW_DOWN) 
			{
				TextColor(2);
				if(_COMMAND == 'S')
				{
					GotoXY(86, 24);
					cout << "| S |";
					GotoXY(86, 25);
					cout << "|___|";
					MoveDown(_A, _X, _Y);
					TextColor(255);
					SetColor(0);
					Sleep(50);
					GotoXY(86, 24);
					cout << "| S |";
					GotoXY(86, 25);
					cout << "|___|";
				}
				else
				{
					GotoXY(86+17, 24);
					cout << "| v |";
					GotoXY(86+17, 25);
					cout << "|___|";
					MoveDown(_A, _X, _Y);
					TextColor(255);
					SetColor(0);
					Sleep(50);
					GotoXY(86+17, 24);
					cout << "| v |";
					GotoXY(86+17, 25);
					cout << "|___|";
				}
			}
			else if (_COMMAND == 'A' || _COMMAND == ARROW_LEFT)
			{
				TextColor(2);
				if (_COMMAND == 'A')
				{
					GotoXY(80, 23);
					cout << "|\\ __\\";
					GotoXY(80, 24);
					cout << "| | A ";
					GotoXY(81, 25);
					cout << "\\|___";
					MoveLeft(_A, _X, _Y);
					Sleep(50);
					TextColor(255);
					SetColor(0);
					GotoXY(80, 23);
					cout << "|\\ __\\";
					GotoXY(80, 24);
					cout << "| | A ";
					GotoXY(81, 25);
					cout << "\\|___";
				}
				else
				{
					GotoXY(80+17, 23);
					cout << "|\\ __\\";
					GotoXY(80+17, 24);
					cout << "| | < ";
					GotoXY(81+17, 25);
					cout << "\\|___";
					MoveLeft(_A, _X, _Y);
					Sleep(50);
					TextColor(255);
					SetColor(0);
					GotoXY(80+17, 23);
					cout << "|\\ __\\";
					GotoXY(80+17, 24);
					cout << "| | < ";
					GotoXY(81+17, 25);
					cout << "\\|___";
				}
			}
			else if (_COMMAND == 'D' || _COMMAND == ARROW_RIGHT) 
			{
				TextColor(2);
				if(_COMMAND=='D')
				{
					GotoXY(90, 23);
					cout << "| _\\";
					GotoXY(90, 24);
					cout << "| D |";
					GotoXY(90, 25);
					cout << "|___|";
					MoveRight(_A, _X, _Y);
					Sleep(50);
					TextColor(255);
					SetColor(0);
					GotoXY(90, 23);
					cout << "| _\\";
					GotoXY(90, 24);
					cout << "| D |";
					GotoXY(90, 25);
					cout << "|___|";
				}
				else
				{
					GotoXY(90+17, 23);
					cout << "| _\\";
					GotoXY(90+17, 24);
					cout << "| > |";
					GotoXY(90+17, 25);
					cout << "|___|";
					MoveRight(_A, _X, _Y);
					Sleep(50);
					TextColor(255);
					SetColor(0);
					GotoXY(90+17, 23);
					cout << "| _\\";
					GotoXY(90+17, 24);
					cout << "| > |";
					GotoXY(90+17, 25);
					cout << "|___|";
				}
			}
			else if (_COMMAND == 13 || _COMMAND == SPACE) {// Người dùng đánh dấu trên màn hình bàn cờ
				PlaySoundEffect("move", MO_NHAC);
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
					switch (ProcessFinish(TestBoard(_A, _TURN, GetRowIndex(_Y), GetColIndex(_X), toadothang), _A, _TURN, _X, _Y, toadothang, MO_NHAC, _PLAYER1, _PLAYER2)) {
					case -1: case 1: case 0:
						if (AskContinue(_A) != 'Y') {
							StopMusic();
							system("cls");
							return;
						}
						else StartGame(_A, _TURN, _COMMAND, _X, _Y, _PLAYER1, _PLAYER2, vsComputer);
					}
				}
				validEnter = true; // Mở khóa
			}
		}
		else
		{
			timkiemnuocdi(_A, _TURN, _COMMAND, _X, _Y, validEnter, MO_NHAC);
			_X = timkiemnuocdi(_A, _TURN, _COMMAND, _X, _Y, validEnter, MO_NHAC).x;
			_Y = timkiemnuocdi(_A, _TURN, _COMMAND, _X, _Y, validEnter, MO_NHAC).y;
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
				switch (ProcessFinish(TestBoard(_A, _TURN, GetRowIndex(_Y), GetColIndex(_X), toadothang), _A, _TURN, _X, _Y, toadothang, MO_NHAC, _PLAYER1, _PLAYER2)) {
				case -1: case 1: case 0:
					if (AskContinue(_A) != 'Y') {
						StopMusic();
						system("cls");
						return;
					}
					else StartGame(_A, _TURN, _COMMAND, _X, _Y, _PLAYER1, _PLAYER2, vsComputer);
				}
			}
			validEnter = true; // Mở khóa
		}
	}
}


