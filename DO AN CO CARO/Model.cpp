#include "Model.h"

void ResetData(_POINT _A[][BOARD_SIZE], bool& _TURN, int& _COMMAND, int& _X, int& _Y)
{
	for (int i = 0; i < BOARD_SIZE; i++) {
		for (int j = 0; j < BOARD_SIZE; j++) {
			_A[i][j].x = 4 * j + LEFT + 2; // Trùng với hoành độ màn hình bàn cờ
			_A[i][j].y = 2 * i + TOP + 1; // Trùng với tung độ màn hình bàn cờ
			_A[i][j].c = 0; // 0 nghĩa là chưa ai đánh dấu, nếu đánh dấu phải theo quy 
			//định như sau: -1 là lượt true đánh, 1 là lượt false đánh
		}
	}
	_TURN = true; _COMMAND = -1; // Gán lượt và phím mặc định
	_X = _A[0][0].x; _Y = _A[0][0].y; // Thiết lập lại tọa độ hiện hành ban đầu
}
//Hàm dọn dẹp tài nguyên
//void GabageCollect()
//{
//	// Dọn dẹp tài nguyên nếu có khai báo con trỏ
//}
bool CheckTie(_POINT _A[][BOARD_SIZE])
{
	int dem = 0;
	for (int i = 0; i < BOARD_SIZE; i++)
	{
		for (int j = 0; j < BOARD_SIZE; j++)
		{
			if (_A[i][j].c == 0)
			{
				dem++;
			}
		}
	}
	if (dem <= 51)
		return true;
	return false;
}

int TestBoard(_POINT _A[][BOARD_SIZE], bool _TURN, int cRow, int cCol,short int toadothang[24])
{
	if (CheckTie(_A)) return 0; //Hoa
	else
	{
		if (CheckWin(_A, cRow, cCol,toadothang))
			return (_TURN == FIRST ? P_X : P_O); //-1 nghia la luot 'true' thang
		else
			return 2;
	}
}

int CheckBoard(int pX, int pY, _POINT _A[][BOARD_SIZE], bool& _TURN) {
	for (int i = 0; i < BOARD_SIZE; i++) {
		for (int j = 0; j < BOARD_SIZE; j++) {
			if (_A[i][j].x == pX && _A[i][j].y == pY && _A[i][j].c == 0) {
				if (_TURN == true) _A[i][j].c = -1; // Nếu lượt hiện hành là true thì c = -1
				else _A[i][j].c = 1; // Nếu lượt hiện hành là false thì c = 1
				return _A[i][j].c;
			}
		}
	}
	return 0;
}

bool HorizontalCheck(_POINT _A[][BOARD_SIZE], int currentRow, int currentCol, short int toadothang[24])
{
	int countWin = 1;
	int count = 1;
	unsigned short int id = 0;
	int dem = 1;
	toadothang[id] = currentRow;
	id++;
	toadothang[id] = currentCol;
	id++;
	while (currentCol + count < BOARD_SIZE)
	{
		if ((_A[currentRow][currentCol + count].c == _A[currentRow][currentCol].c))
		{
			countWin++;
			toadothang[id] = currentRow;
			id++;
			toadothang[id] = currentCol + dem;
			id++;
			dem++;
			count++;
		}
		else
			break;
	}

	count = 1;
	dem = 1;
	while (currentCol - count > -1)
	{
		if ((_A[currentRow][currentCol - count].c == _A[currentRow][currentCol].c))
		{
			countWin++;
			toadothang[id] = currentRow;
			id++;
			toadothang[id] = currentCol - dem;
			id++;
			dem++;
			count++;
		}
		else
			break;
	}


	if (countWin >= 5)
	{
		return true;
	}
	else
		return false;
}

bool VerticalCheck(_POINT _A[][BOARD_SIZE], int currentRow, int currentCol, short int toadothang[24])
{
	int countWin = 1;
	int count = 1;
	unsigned short int id = 0;
	int dem = 1;
	toadothang[id] = currentRow;
	id++;
	toadothang[id] = currentCol;
	id++;
	while (currentRow + count < BOARD_SIZE)
	{
		if ((_A[currentRow + count][currentCol].c == _A[currentRow][currentCol].c))
		{

			countWin++;
			toadothang[id] = currentRow + dem;
			id++;
			toadothang[id] = currentCol;
			id++;
			dem++;
			count++;
		}
		else
			break;
	}

	count = 1;
	dem = 1;
	while (currentRow - count > -1)
	{
		if (_A[currentRow - count][currentCol].c == _A[currentRow][currentCol].c)
		{
			countWin++;
			toadothang[id] = currentRow - dem;
			id++;
			toadothang[id] = currentCol;
			id++;
			dem++;
			count++;
		}
		else
			break;
	}

	if (countWin >= 5)
		return true;
	else
		return false;
}

bool ForwardSlashCheck(_POINT _A[][BOARD_SIZE], int currentRow, int currentCol, short int toadothang[24])
{
	int countWin = 1;
	int count = 1;

	unsigned short int id = 0;
	int dem = 1;
	toadothang[id] = currentRow;
	id++;
	toadothang[id] = currentCol;
	id++;
	while (currentRow + count < BOARD_SIZE && currentCol - count > -1)
	{
		if ((_A[currentRow + count][currentCol - count].c == _A[currentRow][currentCol].c))
		{

			countWin++;
			toadothang[id] = currentRow + dem;
			id++;
			toadothang[id] = currentCol - dem;
			id++;
			dem++;
			count++;
		}
		else
			break;
	}

	count = 1;
	dem = 1;
	while (currentRow - count > -1 && currentCol + count < BOARD_SIZE)
	{
		if (_A[currentRow - count][currentCol + count].c == _A[currentRow][currentCol].c)
		{
			countWin++;
			toadothang[id] = currentRow - dem;
			id++;
			toadothang[id] = currentCol + dem;
			id++;
			dem++;
			count++;
		}
		else
			break;
	}

	if (countWin >= 5)
		return true;
	else
		return false;
}

bool BackwardSlashCheck(_POINT _A[][BOARD_SIZE], int currentRow, int currentCol, short int toadothang[24])
{
	int countWin = 1;
	int count = 1;
	unsigned short int id = 0;
	int dem = 1;
	toadothang[id] = currentRow;
	id++;
	toadothang[id] = currentCol;
	id++;

	while (currentRow + count < BOARD_SIZE && currentCol + count < BOARD_SIZE)
	{
		if ((_A[currentRow + count][currentCol + count].c == _A[currentRow][currentCol].c))
		{
			countWin++;
			toadothang[id] = currentRow + dem;
			id++;
			toadothang[id] = currentCol + dem;
			id++;
			dem++;
			count++;
		}
		else
			break;
	}

	count = 1;
	dem = 1;

	while (currentRow - count > -1 && currentCol - count > -1)
	{
		if ((_A[currentRow - count][currentCol - count].c == _A[currentRow][currentCol].c))
		{
			countWin++;
			toadothang[id] = currentRow - dem;
			id++;
			toadothang[id] = currentCol - dem;
			id++;
			dem++;
			count++;
		}
		else
			break;
	}
	if (countWin >= 5)
		return true;
	else
		return false;
}

bool CheckWin(_POINT _A[][BOARD_SIZE], int currentRow, int currentCol, short int toadothang[24])
{
	if (HorizontalCheck(_A, currentRow, currentCol,toadothang) || VerticalCheck(_A, currentRow, currentCol,toadothang) || BackwardSlashCheck(_A, currentRow, currentCol,toadothang) || ForwardSlashCheck(_A, currentRow, currentCol,toadothang))
		return true;
	else return false;
}

int GetRowIndex(int pY)
{
	int rowIndex;

	rowIndex = (pY - TOP - 1) / VERTICAL_DISTANCE;

	return rowIndex;
}

int GetColIndex(int pX)
{
	int colIndex;

	colIndex = (pX - LEFT - 2) / HORIZONTAL_DISTANCE;

	return colIndex;
}

void PlayBackGroundMusic(int song)
{
	if (song % 4 == 0)
		PlaySound(TEXT("nhacnen1.wav"), NULL, SND_FILENAME | SND_LOOP | SND_ASYNC);// Bat nhac nen 
	else if(song % 4 == 1)
		PlaySound(TEXT("nhacnen2.wav"), NULL, SND_FILENAME | SND_LOOP | SND_ASYNC);// Bat nhac nen
	else if (song % 4 == 2)
		PlaySound(TEXT("nhacnen3.wav"), NULL, SND_FILENAME | SND_LOOP | SND_ASYNC);// Bat nhac nen 
	else if (song % 4 == 3)
		PlaySound(TEXT("nhacnen4.wav"), NULL, SND_FILENAME | SND_LOOP | SND_ASYNC);// Bat nhac nen 
}

void StopMusic()
{
	PlaySound(0, 0, 0); // Tat nhac
}

void PlaySoundEffect(string s, bool MO_NHAC)
{
	if (!MO_NHAC)
		return;
	if (s == "move")
		PlaySound(TEXT("tick.wav"), NULL, SND_FILENAME | SND_ASYNC); // Dung de bat nhac khi di
	else if (s == "win")
		PlaySound(TEXT("win.wav"), NULL, SND_FILENAME | SND_ASYNC); // Bat nhac khi thang
}

void NhapNhayQuanCo(_POINT _A[BOARD_SIZE][BOARD_SIZE], const short int toadothang[24], int pWhoWin)
{
	short int x, y;
	ShowCur(0);

	for (unsigned short int j = 1; j < 11; ++j)
	{
		SetColor(2 + rand() % 14);
		for (int i = 0; i < 10; i += 2)
		{
			x = toadothang[i];
			y = toadothang[i + 1];

			int x2, y2;
			x2 = 4 * y + 2;
			y2 = 2 * x + 1;
			GotoXY(x2, y2);

			if (pWhoWin == -1)
			{
				cout << " ";
				Sleep(40);
				
				GotoXY(x2, y2);
				cout << "X";
				cout << " ";
			}
			else if (pWhoWin == 1)
			{
				cout << " ";
				Sleep(40);
				GotoXY(x2, y2);
				cout << "O";
				cout << " ";
			}
		}
	}
	Sleep(300);
	ShowCur(0);
	for (unsigned short int i = 0; i < 10; i += 2)
	{
		x = toadothang[i];
		y = toadothang[i + 1];

		int x2, y2;
		x2 = 4 * y + 2;
		y2 = 2 * x + 1;
		GotoXY(x2, y2);

		if (pWhoWin == -1)
		{
			SetColor(372);
			cout << " ";
			Sleep(40);

			GotoXY(x2, y2);
			cout << "X";
			cout << " ";
		}
		else if (pWhoWin == 1)
		{
			SetColor(372);
			cout << " ";
			Sleep(40);

			GotoXY(x2, y2);
			cout << "O";
			cout << " ";
		}
		
	}
	SetColor(10);
	Sleep(500);
	ShowCur(1);
}
void LoadData(string filename, _POINT _A[][BOARD_SIZE], _PLAYER& _PLAYER1, _PLAYER& _PLAYER2, bool& _TURN, int& _COMMAND, int& _X, int& _Y, int& chedo)
{
	std::ifstream loadFile;
	loadFile.open(filename.c_str());
	loadFile >> chedo;
	getline(loadFile, _PLAYER1.name);
	_PLAYER1 = LoadPlayer(_PLAYER1);
	getline(loadFile, _PLAYER2.name);
	_PLAYER2 = LoadPlayer(_PLAYER2);
	loadFile >> _TURN;
	for (int i = 0; i < BOARD_SIZE; i++)
	{
		for (int j = 0; j < BOARD_SIZE; j++)
		{
			_A[i][j].x = HORIZONTAL_DISTANCE * j + LEFT + 2; //Trung voi hoanh do ban co
			_A[i][j].y = VERTICAL_DISTANCE * i + TOP + 1; //Trung voi tung do ban co
			loadFile >> _A[i][j].c;
		}
	}
	loadFile.close();

	_COMMAND = -1;

	//Thiet lap lai toa do ban dau
	_X = _A[0][0].x;
	_Y = _A[0][0].y;
}

std::vector<string> LoadFiles()
{
	std::vector<string> files;
	string filename;

	std::fstream savedFile;
	savedFile.open(SAVED_LIST, std::fstream::in);

	while (savedFile >> filename)
	{
		files.push_back(filename);
	}
	savedFile.close();

	return files;
}

bool CheckFileExistence(string filename)
{
	string name; // filename cua cac file da luu trong savedlist.txt
	std::fstream savedFile;
	savedFile.open(SAVED_LIST, std::fstream::in);

	while (savedFile >> name)
	{
		if (name == filename)
		{
			savedFile.close();
			return true;
		}
	}

	savedFile.close();
	return false;
}
void SaveData(string filename, _POINT _A[][BOARD_SIZE], _PLAYER _PLAYER1, _PLAYER _PLAYER2, bool _TURN, int chedo)
{
	std::fstream saveFile;
	saveFile.open(filename, std::fstream::out);
	SavePlayer(_PLAYER1);
	SavePlayer(_PLAYER2);
	saveFile << chedo << "\n";
	saveFile << _PLAYER1.name << "\n";
	saveFile << _PLAYER2.name << "\n";
	saveFile << _TURN << " \n";

	for (int i = 0; i < BOARD_SIZE; i++)
	{
		for (int j = 0; j < BOARD_SIZE; j++)
		{
			saveFile << _A[i][j].c << " ";
		}
		saveFile << "\n";
	}

	saveFile.close();
}
void SavePlayer(_PLAYER player)
{
	int exist = CheckPlayerExistence(player);
	std::vector<_PLAYER> players = GetPlayerList();
	std::fstream playerList;
	playerList.open(PLAYER_LIST, std::fstream::out);

	if (exist == -1) players.push_back(player);
	else players.at(exist).wins = player.wins;


	SortPlayerList(players);
	for (int i = 0; i < players.size(); i++)
	{
		playerList << players.at(i).name << "\n" << players.at(i).wins << "\n";
	}

	playerList.close();

}

_PLAYER LoadPlayer(_PLAYER player)
{
	std::vector<_PLAYER> players;
	players = GetPlayerList();
	int exist = CheckPlayerExistence(player);

	if (exist == -1)
	{
		player.wins = 0;
		SavePlayer(player);
		return player;
	}
	else return players.at(exist);
}

void SetPlayerRank(_PLAYER& player)
{
	int exist = CheckPlayerExistence(player);
	player.rank = exist + 1;
}
int CheckPlayerExistence(_PLAYER player)
{
	std::vector<_PLAYER> players = GetPlayerList();

	for (int i = 0; i < players.size(); i++)
	{
		if (players.at(i) == player) return i;
	}

	return -1;
}
std::vector<_PLAYER> GetPlayerList()
{
	_PLAYER player;
	std::vector<_PLAYER> players;
	std::fstream playerList;
	std::string clear;
	std::string name;
	playerList.open(PLAYER_LIST, std::fstream::in);

	while (getline(playerList, player.name))
	{
		playerList >> player.wins;
		getline(playerList, clear);
		players.push_back(player);
	}

	playerList.close();

	return players;
}
void SortPlayerList(std::vector<_PLAYER>& playerList)
{
	_PLAYER key;
	int j;

	for (int i = 1; i < playerList.size(); i++)
	{
		key = playerList.at(i);
		j = i - 1;
		while (j >= 0 && playerList.at(j) < key)
		{
			playerList.at(j + 1) = playerList.at(j);
			j--;
		}
		playerList.at(j + 1) = key;
	}
}
int getX(_POINT _A[][BOARD_SIZE], int i, int j)
{
	return _A[i][j].x;
}
int getY(_POINT _A[][BOARD_SIZE], int i, int j)
{
	return _A[i][j].y;
}
int getCheck(_POINT _A[][BOARD_SIZE], int i, int j)
{
	return  _A[i][j].c;
}
MOVE timkiemnuocdi(_POINT _A[][BOARD_SIZE], bool _TURN, int _COMMAND, int _X, int _Y, bool validEnter, bool& MO_NHAC)
{
	MOVE wayresult;
	wayresult.x = -1;
	wayresult.y = 1;
	double diem = 0;
	for (int i = 0; i < BOARD_SIZE; i++)
	{
		for (int j = 0; j < BOARD_SIZE; j++)
		{
			if (_A[i][j].c == 0) {

				int x = getX(_A, i, j);
				int y = getY(_A, i, j);
				double diemtancong = tancongdoc(_A, x, y) + tancongngang(_A, x, y) + tancongcheoxuoi(_A, x, y) + tancongcheonguoc(_A, x, y);
				double diemphongngu = phongngudoc(_A, x, y) + phongngungang(_A, x, y) + phongngucheoxuoi(_A, x, y) + phongngucheonguoc(_A, x, y);

				if (diemtancong > diemphongngu)
				{
					if (diem < diemtancong)
					{
						diem = diemtancong;
						wayresult.x = x;
						wayresult.y = y;
					}
				}
				else
				{
					if (diem < diemphongngu)
					{
						diem = diemphongngu;
						wayresult.x = x;
						wayresult.y = y;
					}
				}
			}
		}
	}
	return wayresult;
}
double mangdiemtancong[7] = { 0, 64, 4096, 262144, 16777216, 1073741824 };
double mangdiemphongngu[7] = { 0, 8, 512, 32768, 2097152, 134217728 };
double tancongdoc(_POINT _A[][BOARD_SIZE], int x, int y) {
	int soquanta = 0;
	int soquandich = 0;
	double diemtong = 0;
	int flag = 0;
	for (int i = 0; i < BOARD_SIZE; i++) {
		for (int j = 0; j < BOARD_SIZE; j++)
		{
			if (getX(_A, i, j) == x && getY(_A, i, j) == y)
			{
				// an doc
				for (int t = 1; t < 7 && i - t >= 0; t++) {
					if (getCheck(_A, i - t, j) == -1) {
						soquanta++;
						if (soquanta < 4 && i - t - 1 == 0) {
							soquanta = 0;
							break;
						}
					}

					else if (getCheck(_A, i - t, j) == 1)
					{
						soquandich++;
						break;
					}
					else
					{
						break;
					}
				}
				for (int t = 1; t < 7 && i + t < BOARD_SIZE; t++) {
					if (getCheck(_A, i + t, j) == -1) {
						soquanta++;
						if (soquanta < 4 && i + t + 1 == BOARD_SIZE - 1) {
							soquanta = 0;
							break;
						}
					}

					else if (getCheck(_A, i + t, j) == 1)
					{
						soquandich++;
						break;
					}
					else
					{
						break;
					}
				}
				flag = 1;
				break;
			}
		}
		if (flag == 1) break;
	}
	if (soquandich == 2)
		return 0;
	diemtong -= mangdiemphongngu[soquandich + 1];
	diemtong += mangdiemtancong[soquanta];
	return diemtong;
}

double tancongngang(_POINT _A[][BOARD_SIZE], int x, int y) {
	int soquanta = 0;
	int soquandich = 0;
	double diemtong = 0;
	int flag = 0;
	for (int i = 0; i < BOARD_SIZE; i++) {
		for (int j = 0; j < BOARD_SIZE; j++)
		{
			if (getX(_A, i, j) == x && getY(_A, i, j) == y)
			{
				// an doc
				for (int t = 1; t < 7 && j - t >= 0; t++) {
					if (getCheck(_A, i, j - t) == -1) {
						soquanta++;
						if (soquanta < 4 && j - t - 1 == 0) {
							soquanta = 0;
							break;
						}
					}

					else if (getCheck(_A, i, j - t) == 1)
					{
						soquandich++;
						break;
					}
					else
					{
						break;
					}
				}
				for (int t = 1; t < 7 && j + t < BOARD_SIZE; t++) {
					if (getCheck(_A, i, j + t) == -1) {
						soquanta++;
						if (soquanta < 4 && j + t + 1 == BOARD_SIZE - 1) {
							soquanta = 0;
							break;
						}
					}

					else if (getCheck(_A, i, j + t) == 1)
					{
						soquandich++;
						break;
					}
					else
						break;
				}
				flag = 1;
				break;
			}
		}
		if (flag == 1) break;
	}
	if (soquandich == 2)
		return 0;
	diemtong -= mangdiemphongngu[soquandich + 1];
	diemtong += mangdiemtancong[soquanta];
	return diemtong;
}

double tancongcheoxuoi(_POINT _A[][BOARD_SIZE], int x, int y) {
	int soquanta = 0;
	int soquandich = 0;
	double diemtong = 0;
	int flag = 0;
	for (int i = 0; i < BOARD_SIZE; i++) {
		for (int j = 0; j < BOARD_SIZE; j++)
		{
			if (getX(_A, i, j) == x && getY(_A, i, j) == y)
			{
				for (int t = 1; t < 7 && j - t >= 0 && i - t >= 0; t++) {
					if (getCheck(_A, i - t, j - t) == -1) {
						soquanta++;
						if (soquanta < 4 && (i - t - 1 == 0 || j - t - 1 == 0)) {
							soquanta = 0;
							break;
						}
					}

					else if (getCheck(_A, i - t, j - t) == 1)
					{
						soquandich++;
						break;
					}
					else
						break;
				}
				for (int t = 1; t < 7 && i + t < BOARD_SIZE && j + t < BOARD_SIZE; t++) {
					if (getCheck(_A, i + t, j + t) == -1) {
						soquanta++;
						if (soquanta < 4 && (i + t + 1 == BOARD_SIZE - 1 || j + t + 1 == BOARD_SIZE - 1)) {
							soquanta = 0;
							break;
						}
					}

					else if (getCheck(_A, i + t, j + t) == 1)
					{
						soquandich++;
						break;
					}
					else
						break;
				}
				flag = 1;
				break;
			}

		}
		if (flag == 1) break;
	}
	if (soquandich == 2)
		return 0;
	diemtong -= mangdiemphongngu[soquandich + 1];
	diemtong += mangdiemtancong[soquanta];
	return diemtong;
}

double tancongcheonguoc(_POINT _A[][BOARD_SIZE], int x, int y) {
	int soquanta = 0;
	int soquandich = 0;
	double diemtong = 0;
	int flag = 0;
	for (int i = 0; i < BOARD_SIZE; i++) {
		for (int j = 0; j < BOARD_SIZE; j++)
		{
			if (getX(_A, i, j) == x && getY(_A, i, j) == y)
			{
				for (int t = 1; t < 7 && j + t < BOARD_SIZE && i - t >= 0; t++) {
					if (getCheck(_A, i - t, j + t) == -1) {
						soquanta++;
						if (soquanta < 4 && (i - t - 1 == 0 || j + t + 1 == BOARD_SIZE - 1)) {
							soquanta = 0;
							break;
						}
					}

					else if (getCheck(_A, i - t, j + t) == 1)
					{
						soquandich++;
						break;
					}
					else
						break;
				}
				for (int t = 1; t < 7 && i + t < BOARD_SIZE && j - t >= 0; t++) {
					if (getCheck(_A, i + t, j - t) == -1) {
						soquanta++;
						if (soquanta < 4 && (i + t + 1 == BOARD_SIZE - 1 || j - t - 1 == 0)) {
							soquanta = 0;
							break;
						}
					}

					else if (getCheck(_A, i + t, j - t) == 1)
					{
						soquandich++;
						break;
					}
					else
						break;
				}
				flag = 1;
				break;
			}
		}
		if (flag == 1) break;

	}
	if (soquandich == 2)
		return 0;
	diemtong -= mangdiemphongngu[soquandich + 1];
	diemtong += mangdiemtancong[soquanta];
	return diemtong;
}

double phongngudoc(_POINT _A[][BOARD_SIZE], int x, int y) {
	int soquanta = 0;
	int soquandich = 0;
	double diemtong = 0;
	int flag = 0;
	for (int i = 0; i < BOARD_SIZE; i++) {
		for (int j = 0; j < BOARD_SIZE; j++)
		{
			if (getX(_A, i, j) == x && getY(_A, i, j) == y)
			{
				// an doc
				for (int t = 1; t < 7 && i - t >= 0; t++) {
					if (getCheck(_A, i - t, j) == -1) {
						soquanta++;
						break;
					}
					else if (getCheck(_A, i - t, j) == 1)
					{
						soquandich++;
						if (soquandich < 4 && i - t - 1 == 0) {
							soquandich = 0;
							break;
						}
					}
					else
						break;
				}
				for (int t = 1; t < 7 && i + t < BOARD_SIZE; t++) {
					if (getCheck(_A, i + t, j) == -1) {
						soquanta++;
						break;
					}
					else if (getCheck(_A, i + t, j) == 1)
					{
						soquandich++;
						if (soquandich < 4 && i + t + 1 == BOARD_SIZE - 1) {
							soquandich = 0;
							break;
						}
					}
					else
						break;
				}
				flag = 1;
				break;
			}
		}
		if (flag == 1) break;

	}
	if (soquanta == 2)
		return 0;
	diemtong -= mangdiemtancong[soquanta];
	diemtong += mangdiemphongngu[soquandich];
	return diemtong;
}

double phongngungang(_POINT _A[][BOARD_SIZE], int x, int y) {
	int soquanta = 0;
	int soquandich = 0;
	double diemtong = 0;
	int flag = 0;
	for (int i = 0; i < BOARD_SIZE; i++) {
		for (int j = 0; j < BOARD_SIZE; j++)
		{
			if (getX(_A, i, j) == x && getY(_A, i, j) == y)
			{
				// an doc
				for (int t = 1; t < 7 && j - t >= 0; t++) {
					if (getCheck(_A, i, j - t) == -1) {
						soquanta++;
						break;
					}
					else if (getCheck(_A, i, j - t) == 1)
					{
						soquandich++;
						if (soquandich < 4 && j - t - 1 == 0) {
							soquandich = 0;
							break;
						}
					}
					else
						break;
				}
				for (int t = 1; t < 7 && j + t < BOARD_SIZE; t++) {
					if (getCheck(_A, i, j + t) == -1) {
						soquanta++;
						break;
					}
					else if (getCheck(_A, i, j + t) == 1)
					{
						soquandich++;
						if (soquandich < 4 && j + t + 1 == BOARD_SIZE - 1) {
							soquandich = 0;
							break;
						}
					}
					else
						break;
				}
				flag = 1;
				break;
			}
		}
		if (flag == 1) break;

	}
	if (soquanta == 2)
		return 0;
	diemtong -= mangdiemtancong[soquanta];
	diemtong += mangdiemphongngu[soquandich];
	return diemtong;
}

double phongngucheoxuoi(_POINT _A[][BOARD_SIZE], int x, int y) {
	int soquanta = 0;
	int soquandich = 0;
	double diemtong = 0;
	int flag = 0;
	for (int i = 0; i < BOARD_SIZE; i++) {
		for (int j = 0; j < BOARD_SIZE; j++)
		{
			if (getX(_A, i, j) == x && getY(_A, i, j) == y)
			{
				for (int t = 1; t < 7 && j - t >= 0 && i - t >= 0; t++) {
					if (getCheck(_A, i - t, j - t) == -1) {
						soquanta++;
						break;
					}
					else if (getCheck(_A, i - t, j - t) == 1)
					{
						soquandich++;
						if (soquandich < 4 && (i - t - 1 == 0 || j - t - 1 == 0)) {
							soquandich = 0;
							break;
						}
					}
					else
						break;
				}
				for (int t = 1; t < 7 && i + t < BOARD_SIZE && j + t < BOARD_SIZE; t++) {
					if (getCheck(_A, i + t, j + t) == -1) {
						soquanta++;
						break;
					}
					else if (getCheck(_A, i + t, j + t) == 1)
					{
						soquandich++;
						if (soquandich < 4 && (i + t + 1 == BOARD_SIZE - 1 || j + t + 1 == BOARD_SIZE - 1)) {
							soquandich = 0;
							break;
						}
					}
					else
						break;
				}
				flag = 1;
				break;
			}
		}
		if (flag == 1) break;

	}
	if (soquanta == 2)
		return 0;
	diemtong -= mangdiemtancong[soquanta];
	diemtong += mangdiemphongngu[soquandich];
	return diemtong;
}

double phongngucheonguoc(_POINT _A[][BOARD_SIZE], int x, int y) {
	int soquanta = 0;
	int soquandich = 0;
	double diemtong = 0;
	int flag = 0;
	for (int i = 0; i < BOARD_SIZE; i++) {
		for (int j = 0; j < BOARD_SIZE; j++)
		{
			if (getX(_A, i, j) == x && getY(_A, i, j) == y)
			{
				for (int t = 1; t < 7 && j + t < BOARD_SIZE && i - t >= 0; t++) {
					if (getCheck(_A, i - t, j + t) == -1) {
						soquanta++;
						break;
					}
					else if (getCheck(_A, i - t, j + t) == 1)
					{
						soquandich++;
						if (soquandich < 4 && (i - t - 1 == 0 || j + t + 1 == BOARD_SIZE - 1)) {
							soquandich = 0;
							break;
						}
					}
					else
						break;
				}
				for (int t = 1; t < 7 && i + t < BOARD_SIZE && j - t >= 0; t++) {
					if (getCheck(_A, i + t, j - t) == -1) {
						soquanta++;
						break;
					}
					else if (getCheck(_A, i + t, j - t) == 1)
					{
						soquandich++;
						if (soquandich < 4 && (i + t + 1 == BOARD_SIZE - 1 || j - t - 1 == 0)) {
							soquandich = 0;
							break;
						}
					}
					else
						break;
				}
				flag = 1;
				break;
			}
		}
		if (flag == 1) break;
	}
	if (soquanta == 2)
		return 0;
	diemtong -= mangdiemtancong[soquanta];
	diemtong += mangdiemphongngu[soquandich];
	return diemtong;
}