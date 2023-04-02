#include "Control.h"


void StartGame(_POINT _A[][BOARD_SIZE], bool& _TURN, int& _COMMAND, int& _X, int& _Y)
{
	system("cls");
	ResetData(_A, _TURN, _COMMAND, _X, _Y); // Khởi tạo dữ liệu gốc
	DrawBoard(BOARD_SIZE); // Vẽ màn hình game
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

void GamePlay(_POINT _A[][BOARD_SIZE], bool _TURN, int _COMMAND, int _X, int _Y, bool validEnter)
{
	FixConsoleWindow();
	StartGame(_A, _TURN, _COMMAND, _X, _Y);
	StopMusic();
	short int toadothang[24];
	while (1)
	{
		_COMMAND = toupper(_getch());
		if (_COMMAND == 'O')
			StopMusic();
		else if (_COMMAND == 'P')
			PlayBackGroundMusic();
		if (_COMMAND == 27)
		{
			system("cls");
			return;
		}
		else {
			if (_COMMAND == 'A') MoveLeft(_A, _X, _Y);
			else if (_COMMAND == 'W') MoveUp(_A, _X, _Y);
			else if (_COMMAND == 'S') MoveDown(_A, _X, _Y);
			else if (_COMMAND == 'D') MoveRight(_A, _X, _Y);
			else if (_COMMAND == 13) {// Người dùng đánh dấu trên màn hình bàn cờ
				PlaySoundEffect("move");
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
					switch (ProcessFinish(TestBoard(_A, _TURN, GetRowIndex(_Y), GetColIndex(_X),toadothang), _A, _TURN, _X, _Y,toadothang)) {
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