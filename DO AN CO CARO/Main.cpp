#include "Data.h"
#include "View.h"
#include "Control.h"
#include "Model.h"

int main() {
	_POINT _A[BOARD_SIZE][BOARD_SIZE]; //Ma trận bàn cờ
	bool _TURN{}; //true là lượt người thứ nhất và false là lượt người thứ hai
	int _COMMAND{}; // Biến nhận giá trị phím người dùng nhập
	int _X{}, _Y{};
	int n = 100;
	bool validEnter = true;
	ScreenStartGame(n, _A, _TURN, _COMMAND, _X, _Y, validEnter);
	//456789
	return 0;
}
