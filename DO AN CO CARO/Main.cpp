﻿#include "Data.h"
#include "View.h"
#include "Control.h"
#include "Model.h"

int main() {
	_POINT _A[BOARD_SIZE][BOARD_SIZE]; //Ma trận bàn cờ
	bool _TURN{}; //true là lượt người thứ nhất và false là lượt người thứ hai
	int _COMMAND{}; // Biến nhận giá trị phím người dùng nhập
	_PLAYER _PLAYER1, _PLAYER2;
	int _X{}, _Y{};
	int n = 100;
	bool validEnter = true;
	resizeConsole(WIDTH,HEIGHT);
	FixConsoleWindow();
	TextColor(255);
	for (int i = 0; i < 30; i++)
		cout << "                                    ";
	system("cls");
	int chedo;
	bool MO_NHAC = true;
	ScreenStartGame(n, _A, _TURN, _COMMAND, _X, _Y, validEnter, MO_NHAC, chedo, _PLAYER1, _PLAYER2);
	return 0;
}
