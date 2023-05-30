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

bool CheckTie(_POINT _A[][BOARD_SIZE])
{
	int dem = 0; // Khai báo biến đếm ô trống
	// Đếm trên bàn cờ còn bao nhiêu ô trống
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
	if (dem <= 51) // Nếu ít hơn 52 ô trống tức là số ô trống còn khoảng 20% thì trả về true - hòa
		return true;
	return false;
}

int CountX(_POINT _A[][BOARD_SIZE])
{
	int dem = 0;
	for (int i = 0; i < BOARD_SIZE; i++)
	{
		for (int j = 0; j < BOARD_SIZE; j++)
		{
			if (_A[i][j].c == -1)
			{
				dem++;
			}
		}
	}
	return dem;
}

int CountO(_POINT _A[][BOARD_SIZE])
{
	int dem = 0;
	for (int i = 0; i < BOARD_SIZE; i++)
	{
		for (int j = 0; j < BOARD_SIZE; j++)
		{
			if (_A[i][j].c == 1)
			{
				dem++;
			}
		}
	}
	return dem;
}

int TestBoard(_POINT _A[][BOARD_SIZE], bool _TURN, int cRow, int cCol,short int toadothang[24])
{
	if (CheckTie(_A)) return 0; //Hòa
	else
	{
		if (CheckWin(_A, cRow, cCol,toadothang))
			return (_TURN == FIRST ? P_X : P_O); //-1 nghĩa là lượt 'true' thắng
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
	// Kiểm tra xem có nhiều hơn 5 quân cờ hàng ngang giống nhau liền kề không
	// Lưu lại tọa độ của các vị trí vào mảng toadothang để dùng cho việc thông báo nước đi thắng
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
	// Kiểm tra xem có nhiều hơn 5 quân cờ hàng dọc giống nhau liền kề không
	// Lưu lại tọa độ của các vị trí vào mảng toadothang để dùng cho việc thông báo nước đi thắng
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
	// Kiểm tra xem có nhiều hơn 5 quân cờ đường chéo xuôi giống nhau liền kề không
	// Lưu lại tọa độ của các vị trí vào mảng toadothang để dùng cho việc thông báo nước đi thắng
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
	// Kiểm tra xem có nhiều hơn 5 quân cờ đường chéo ngược giống nhau liền kề không
	// Lưu lại tọa độ của các vị trí vào mảng toadothang để dùng cho việc thông báo nước đi thắng
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
	// Kiểm tra xem có người chơi nào thắng chưa bằng việc gọi các hàm kiểm tra ngang, dọc, chéo xuôi, chéo ngược ở trên
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
	if (song == -1)
		StopMusic();
	else if (song % 4 == 0)
		PlaySound(TEXT("nhacnen1.wav"), NULL, SND_FILENAME | SND_LOOP | SND_ASYNC);
	else if(song % 4 == 1)
		PlaySound(TEXT("nhacnen2.wav"), NULL, SND_FILENAME | SND_LOOP | SND_ASYNC);
	else if (song % 4 == 2)
		PlaySound(TEXT("nhacnen3.wav"), NULL, SND_FILENAME | SND_LOOP | SND_ASYNC);
	else if (song % 4 == 3)
		PlaySound(TEXT("nhacnen4.wav"), NULL, SND_FILENAME | SND_LOOP | SND_ASYNC);
}

void StopMusic()
{
	PlaySound(0, 0, 0); // Tắt nhạc
}

void PlaySoundEffect(string s, bool SoundEffects)
{
	if (!SoundEffects)
		return;
	if (s == "move")
		PlaySound(TEXT("move.wav"), NULL, SND_FILENAME | SND_ASYNC); // Bật âm thanh khi di chuyển
	else if (s == "win")
		PlaySound(TEXT("win1.wav"), NULL, SND_FILENAME | SND_ASYNC); // Bật âm thanh thắng
	else if (s == "draw")
		PlaySound(TEXT("draw.wav"), NULL, SND_FILENAME | SND_ASYNC); // Bật âm thanh hòa
	else if (s == "choose")
		PlaySound(TEXT("choose.wav"), NULL, SND_FILENAME | SND_ASYNC); // Bật âm thanh khi lựa chọn
}

//Đọc dữ liệu từ file
void LoadData(string filename, _POINT _A[][BOARD_SIZE], _PLAYER& _PLAYER1, _PLAYER& _PLAYER2, bool& _TURN, int& _COMMAND, int& _X, int& _Y, int& chedo)
{
	std::ifstream loadFile;
	//Mở file mà người chơi yêu cầu
	loadFile.open(filename.c_str());
	//Đọc tên người chơi X
	getline(loadFile, _PLAYER1.name);
	_PLAYER1 = LoadPlayer(_PLAYER1);
	//Đọc tên người chơi O
	getline(loadFile, _PLAYER2.name);
	_PLAYER2 = LoadPlayer(_PLAYER2);
	//Đọc chế độ
	loadFile >> chedo;
	//Đọc lượt chơi hiện tại
	loadFile >> _TURN;
	//Đọc bàn cờ
	for (int i = 0; i < BOARD_SIZE; i++)
	{
		for (int j = 0; j < BOARD_SIZE; j++)
		{
			_A[i][j].x = HORIZONTAL_DISTANCE * j + LEFT + 2; //Trùng với hoành độ bàn cờ
			_A[i][j].y = VERTICAL_DISTANCE * i + TOP + 1; //Trùng với tung độ bàn cờ
			loadFile >> _A[i][j].c;
		}
	}
	loadFile.close();

	_COMMAND = -1;

	//Thiết lập lại tọa độ ban đầu
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
	string name; // filename của các file đã lưu trong savedlist.txt
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

//Lưu dữ liệu
void SaveData(string filename, _POINT _A[][BOARD_SIZE], _PLAYER _PLAYER1, _PLAYER _PLAYER2, bool _TURN, int chedo)
{
	std::fstream saveFile;
	saveFile.open(filename, std::fstream::out);
	//Lưu người chơi X
	SavePlayer(_PLAYER1);
	//Lưu người chơi O
	SavePlayer(_PLAYER2);
	//Lưu tên người chơi X
	saveFile << _PLAYER1.name << "\n";
	//Lưu tên người chơi O
	saveFile << _PLAYER2.name << "\n";
	//Lưu chế độ chơi (2 là chơi với người, 3 là chơi với máy)
	saveFile << chedo << "\n";
	//Lưu lượt chơi hiện tại(1 là X, 0 là O)
	saveFile << _TURN << "\n";
	//Tiến hành lưu bàn cờ hiện có(-1 là X, 1 là O, 0 là ô còn trống)
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

//Lưu người chơi
void SavePlayer(_PLAYER player)
{
	int exist = CheckPlayerExistence(player); // Kiểm tra xem người chơi đã tồn tại chưa
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
	// Sắp xếp danh sách người chơi và in lại vào file
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

//Tiến hành sắp xếp thứ hạng của người chơi theo danh sách PlayerList
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

//Sắp xếp thứ hạng trong danh sách theo thứ tự giảm dần số ván thắng
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
MOVE timkiemnuocdi(_POINT _A[][BOARD_SIZE], bool _TURN, int _COMMAND, int _X, int _Y, bool validEnter, bool& SoundEffects)
{
	MOVE wayresult;
	wayresult.x = -1;
	wayresult.y = 1;
	// Tạo biến wayresult để nhận tọa độ điểm máy đánh
	double diem = 0;
	// Duyệt qua tất cả ô trống
	for (int i = 0; i < BOARD_SIZE; i++)
	{
		for (int j = 0; j < BOARD_SIZE; j++)
		{
			if (_A[i][j].c == 0) {

				int x = getX(_A, i, j);
				int y = getY(_A, i, j);
				// Tính điểm cho từng ô trống
				double diemtancong = tancongdoc(_A, x, y) + tancongngang(_A, x, y) + tancongcheoxuoi(_A, x, y) + tancongcheonguoc(_A, x, y);
				double diemphongngu = phongngudoc(_A, x, y) + phongngungang(_A, x, y) + phongngucheoxuoi(_A, x, y) + phongngucheonguoc(_A, x, y);
				// Lấy ô trống có điểm cao nhất
				if (diemtancong >= diemphongngu)
				{
					if (diem <= diemtancong)
					{
						diem = diemtancong;
						wayresult.x = x;
						wayresult.y = y;
					}
				}
				else
				{
					if (diem <= diemphongngu)
					{
						diem = diemphongngu;
						wayresult.x = x;
						wayresult.y = y;
					}
				}
			}
		}
	}
	// Trả về nước đi của máy
	return wayresult;
}
double mangdiemtancong[7] = { 0,8, 64, 512,4096,32768,262144 };
// Ứng với mỗi quân cờ liên tiếp sẽ có giá trị điểm tấn công tương ứng. 
//Ví dụ có 2 quân cờ liên tiếp thì giá trị điểm tấn công là 64.
double mangdiemphongngu[7] = { 0, 1, 16, 128,1024,8192,65536 };
// Ứng với mỗi quân cờ liên tiếp sẽ có giá trị điểm phòng thủ tương ứng. 
double tancongdoc(_POINT _A[][BOARD_SIZE], int x, int y) {
	int soquanta = 0;
	int soquandich = 0;
	double diemtong = 0;
	int flag = 0;
	// Biến để kết thúc
	for (int i = 0; i < BOARD_SIZE; i++) {
		for (int j = 0; j < BOARD_SIZE; j++)
		{
			// Tìm vị trí của ô trống
			if (getX(_A, i, j) == x && getY(_A, i, j) == y)
			{
				//Duyệt các ô ở phía trên ô trống
				for (int t = 1; t < 7 && i - t >= 0; t++) {
					// Nếu ô hiện tại có c=-1 thì tăng số quân ta lên
					if (getCheck(_A, i - t, j) == -1) {
						soquanta++;
						// Nếu số quân ta nhỏ hơn 4 và ô trống đang nằm ở đầu bàn cờ thì thoát khỏi vòng lặp
						if (soquanta < 4 && i - t - 1 == 0) {
							soquanta = 0;
							break;
						}
					}
					// Nếu ô hiện tại có c=1 thì tăng số quân địch lên và kết thúc vòng lặp
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
				// Duyệt các ô ở phía dưới ô trống
				for (int t = 1; t < 7 && i + t < BOARD_SIZE; t++) {
					// Nếu ô hiện tại có c=-1 thì tăng số quân ta lên
					if (getCheck(_A, i + t, j) == -1) {
						soquanta++;
						// Nếu số quân ta nhỏ hơn 4 và ô trống đang nằm ở cuối bàn cờ thì thoát khỏi vòng lặp
						if (soquanta < 4 && i + t + 1 == BOARD_SIZE - 1) {
							soquanta = 0;
							break;
						}
					}
					// Nếu ô hiện tại có c=1 thì tăng số quân địch lên và kết thúc vòng lặp
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
		// Nếu tìm thấy ô trống thích hợp thì dừng lại
		if (flag == 1) break;
	}
	// Nếu có 2 quân địch liên tiếp thì không tính điểm
	if (soquandich == 2)
		return 0;
	// Tính điểm tấn công dọc bằng cách cộng giá trị lấy từ mảng điểm tấn công tương ứng với
	//số quân ta và trừ giá trị lấy từ mảng điểm phòng thủ tương ứng với số quân địch
	diemtong -= mangdiemphongngu[soquandich];
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
	diemtong -= mangdiemphongngu[soquandich ];
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
	diemtong -= mangdiemphongngu[soquandich ];
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
	diemtong -= mangdiemphongngu[soquandich ];
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

//Thiết lập người chơi khi vào game, tiến hành nhập tên người chơi X, O
void SetPlayer(_PLAYER& _PLAYER1, _PLAYER& _PLAYER2)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
	WORD saved_attributes;
	GetConsoleScreenBufferInfo(hConsole, &consoleInfo);
	saved_attributes = consoleInfo.wAttributes;
	do
	{
		SetConsoleTextAttribute(hConsole, 48 | BACKGROUND_INTENSITY);
		SetColor(15);
		for (int i = 7; i < 17; i++)
		{
			for (int j = 38; j < 112; j++)
			{
				GotoXY(j, i);
				cout << " ";
			}
		}
		for (int i = 18; i < 25; i++)
		{
			for (int j = 38; j < 112; j++)
			{
				GotoXY(j, i);
				cout << " ";
			}
		}
		for (int i = 38; i < 53; i++)
		{
			GotoXY(i, 17);
			cout << " ";
		}
		for (int i = 98; i < 112; i++)
		{
			GotoXY(i, 17);
			cout << " ";
		}
		SetColor(4);
		GotoXY(X_CENTER - 30, Y_CENTER - 11); cout << "  .''..''..''..''..''..''..''..''..''..''..''..''..''..''..''..''..''.";
		GotoXY(X_CENTER - 30, Y_CENTER - 10); cout << " / .. " << char(92) << " .." << char(92) << " .." << char(92) << " .." << char(92) << " .." << char(92) << " .." << char(92) << " .." << char(92) << " .." << char(92) << " .." << char(92) << " .." << char(92) << " .." << char(92) << " .." << char(92) << " .." << char(92) << " .." << char(92) << " .." << char(92) << " .." << char(92) << " .." << char(92);
		GotoXY(X_CENTER - 29, Y_CENTER - 9); cout << char(92) << "/ /" << char(92) << "/ /" << char(92) << " ../ ../ ../ ../ ../ ../ ../ ../ ../ ../ ../ ../ ../" << char(92) << " /" << char(92) << "/ /" << char(92) << "/ ";
		GotoXY(X_CENTER - 30, Y_CENTER - 8); cout << " / /" << char(92) << "/ / ";
		GotoXY(X_CENTER + 34, Y_CENTER - 8); cout << " /" << char(92) << "/ /" << char(92);
		GotoXY(X_CENTER - 30, Y_CENTER - 7); cout << "/ /" << char(92) << " " << char(92) << "/  ";
		GotoXY(X_CENTER + 35, Y_CENTER - 7); cout << char(92) << " " << char(92) << "/" << char(92) << " " << char(92);
		GotoXY(X_CENTER - 30, Y_CENTER - 6); cout << char(92) << " " << char(92) << "/" << char(92) << " " << char(92);
		GotoXY(X_CENTER + 35, Y_CENTER - 6); cout << "/" << char(92) << " " << char(92) << "/ /";
		GotoXY(X_CENTER - 30, Y_CENTER - 5); cout << " " << char(92) << "/ /" << char(92) << " " << char(92);
		GotoXY(X_CENTER + 34, Y_CENTER - 5); cout << "/ /" << char(92) << "/ /";
		GotoXY(X_CENTER - 30, Y_CENTER - 4); cout << " / /" << char(92) << "/ /";
		GotoXY(X_CENTER + 34, Y_CENTER - 4); cout << char(92) << " " << char(92) << "/ /" << char(92);
		GotoXY(X_CENTER - 30, Y_CENTER - 3); cout << "/ /" << char(92) << " " << char(92) << "/";
		GotoXY(X_CENTER + 34, Y_CENTER - 3); cout << " " << char(92) << " " << char(92) << "/" << char(92) << " " << char(92);
		GotoXY(X_CENTER - 30, Y_CENTER - 2); cout << char(92) << " " << char(92) << "/" << char(92) << " " << char(92);
		GotoXY(X_CENTER + 34, Y_CENTER - 2); cout << " /" << char(92) << " " << char(92) << "/ /";
		GotoXY(X_CENTER - 30, Y_CENTER - 1); cout << " " << char(92) << "/ /" << char(92) << " " << char(92);
		GotoXY(X_CENTER + 34, Y_CENTER - 1); cout << "/ /" << char(92) << "/ /";
		GotoXY(X_CENTER - 30, Y_CENTER); cout << " / /" << char(92) << "/ /";
		GotoXY(X_CENTER + 34, Y_CENTER); cout << char(92) << " " << char(92) << "/ /" << char(92);
		GotoXY(X_CENTER - 30, Y_CENTER + 1); cout << "/ /" << char(92) << " " << char(92) << "/";
		GotoXY(X_CENTER + 34, Y_CENTER + 1); cout << " " << char(92) << " " << char(92) << "/" << char(92) << " " << char(92) << "";
		GotoXY(X_CENTER - 30, Y_CENTER + 2); cout << "" << char(92) << " " << char(92) << "/ /" << char(92) << "";
		GotoXY(X_CENTER + 34, Y_CENTER + 2); cout << "  " << char(92) << " " << char(92) << "/" << char(92) << " " << char(92) << "";
		GotoXY(X_CENTER - 30, Y_CENTER + 3); cout << " " << char(92) << " " << char(92) << "/" << char(92) << " " << char(92) << "";
		GotoXY(X_CENTER + 34, Y_CENTER + 3); cout << "  /" << char(92) << " " << char(92) << "/ /";
		GotoXY(X_CENTER - 30, Y_CENTER + 4); cout << " /" << char(92) << "/ /" << char(92) << "/ /../ ../ ../ ../ ../ ../ ../ ../ ../ ../ ../ ../ ../ ../ /" << char(92) << "/ " << char(92) << "/";
		GotoXY(X_CENTER - 30, Y_CENTER + 5); cout << " " << char(92) << " ''" << char(92) << " ''" << char(92) << " ''" << char(92) << " ''" << char(92) << " ''" << char(92) << " ''" << char(92) << " ''" << char(92) << " ''" << char(92) << " ''" << char(92) << " ''" << char(92) << " ''" << char(92) << " ''" << char(92) << " ''" << char(92) << " ''" << char(92) << " ''" << char(92) << " ''" << char(92) << " " << "" << "'''/";
		GotoXY(X_CENTER - 30, Y_CENTER + 6); cout << "  '..''..''..''..''..''..''..''..''..''..''..''..''..''..''..''..''..'";
		SetColor(0);
		GotoXY(X_CENTER - 14, Y_CENTER - 4); cout << "Enter PlayerX's name (2-10 characters): ";
		SetConsoleTextAttribute(hConsole, saved_attributes);
		for (int i = 53; i < 98; i++)
		{
			GotoXY(i, Y_CENTER - 1);
			cout << " ";
		}
		GotoXY(X_CENTER - 16, Y_CENTER - 1);
		SetColor(0);
		std::getline(cin, _PLAYER1.name);
		// ve khung o day
	} while (_PLAYER1.name.length() < 2 || _PLAYER1.name.length() > 10);//Nếu tên người chơi nhỏ hơn 2 hoặc lớn hơn 10 sẽ yêu cầu người chơi nhập lại tên cho đến khi hợp lệ
	do
	{
		SetConsoleTextAttribute(hConsole, 48 | BACKGROUND_INTENSITY);
		SetColor(15);
		for (int i = 7; i < 17; i++)
		{
			for (int j = 38; j < 112; j++)
			{
				GotoXY(j, i);
				cout << " ";
			}
		}
		for (int i = 18; i < 25; i++)
		{
			for (int j = 38; j < 112; j++)
			{
				GotoXY(j, i);
				cout << " ";
			}
		}
		for (int i = 38; i < 53; i++)
		{
			GotoXY(i, 17);
			cout << " ";
		}
		for (int i = 98; i < 112; i++)
		{
			GotoXY(i, 17);
			cout << " ";
		}
		SetColor(4);
		GotoXY(X_CENTER - 30, Y_CENTER - 11); cout << "  .''..''..''..''..''..''..''..''..''..''..''..''..''..''..''..''..''.";
		GotoXY(X_CENTER - 30, Y_CENTER - 10); cout << " / .. " << char(92) << " .." << char(92) << " .." << char(92) << " .." << char(92) << " .." << char(92) << " .." << char(92) << " .." << char(92) << " .." << char(92) << " .." << char(92) << " .." << char(92) << " .." << char(92) << " .." << char(92) << " .." << char(92) << " .." << char(92) << " .." << char(92) << " .." << char(92) << " .." << char(92);
		GotoXY(X_CENTER - 29, Y_CENTER - 9); cout << char(92) << "/ /" << char(92) << "/ /" << char(92) << " ../ ../ ../ ../ ../ ../ ../ ../ ../ ../ ../ ../ ../" << char(92) << " /" << char(92) << "/ /" << char(92) << "/ ";
		GotoXY(X_CENTER - 30, Y_CENTER - 8); cout << " / /" << char(92) << "/ / ";
		GotoXY(X_CENTER + 34, Y_CENTER - 8); cout << " /" << char(92) << "/ /" << char(92);
		GotoXY(X_CENTER - 30, Y_CENTER - 7); cout << "/ /" << char(92) << " " << char(92) << "/  ";
		GotoXY(X_CENTER + 35, Y_CENTER - 7); cout << char(92) << " " << char(92) << "/" << char(92) << " " << char(92);
		GotoXY(X_CENTER - 30, Y_CENTER - 6); cout << char(92) << " " << char(92) << "/" << char(92) << " " << char(92);
		GotoXY(X_CENTER + 35, Y_CENTER - 6); cout << "/" << char(92) << " " << char(92) << "/ /";
		GotoXY(X_CENTER - 30, Y_CENTER - 5); cout << " " << char(92) << "/ /" << char(92) << " " << char(92);
		GotoXY(X_CENTER + 34, Y_CENTER - 5); cout << "/ /" << char(92) << "/ /";
		GotoXY(X_CENTER - 30, Y_CENTER - 4); cout << " / /" << char(92) << "/ /";
		GotoXY(X_CENTER + 34, Y_CENTER - 4); cout << char(92) << " " << char(92) << "/ /" << char(92);
		GotoXY(X_CENTER - 30, Y_CENTER - 3); cout << "/ /" << char(92) << " " << char(92) << "/";
		GotoXY(X_CENTER + 34, Y_CENTER - 3); cout << " " << char(92) << " " << char(92) << "/" << char(92) << " " << char(92);
		GotoXY(X_CENTER - 30, Y_CENTER - 2); cout << char(92) << " " << char(92) << "/" << char(92) << " " << char(92);
		GotoXY(X_CENTER + 34, Y_CENTER - 2); cout << " /" << char(92) << " " << char(92) << "/ /";
		GotoXY(X_CENTER - 30, Y_CENTER - 1); cout << " " << char(92) << "/ /" << char(92) << " " << char(92);
		GotoXY(X_CENTER + 34, Y_CENTER - 1); cout << "/ /" << char(92) << "/ /";
		GotoXY(X_CENTER - 30, Y_CENTER); cout << " / /" << char(92) << "/ /";
		GotoXY(X_CENTER + 34, Y_CENTER); cout << char(92) << " " << char(92) << "/ /" << char(92);
		GotoXY(X_CENTER - 30, Y_CENTER + 1); cout << "/ /" << char(92) << " " << char(92) << "/";
		GotoXY(X_CENTER + 34, Y_CENTER + 1); cout << " " << char(92) << " " << char(92) << "/" << char(92) << " " << char(92) << "";
		GotoXY(X_CENTER - 30, Y_CENTER + 2); cout << "" << char(92) << " " << char(92) << "/ /" << char(92) << "";
		GotoXY(X_CENTER + 34, Y_CENTER + 2); cout << "  " << char(92) << " " << char(92) << "/" << char(92) << " " << char(92) << "";
		GotoXY(X_CENTER - 30, Y_CENTER + 3); cout << " " << char(92) << " " << char(92) << "/" << char(92) << " " << char(92) << "";
		GotoXY(X_CENTER + 34, Y_CENTER + 3); cout << "  /" << char(92) << " " << char(92) << "/ /";
		GotoXY(X_CENTER - 30, Y_CENTER + 4); cout << " /" << char(92) << "/ /" << char(92) << "/ /../ ../ ../ ../ ../ ../ ../ ../ ../ ../ ../ ../ ../ ../ /" << char(92) << "/ " << char(92) << "/";
		GotoXY(X_CENTER - 30, Y_CENTER + 5); cout << " " << char(92) << " ''" << char(92) << " ''" << char(92) << " ''" << char(92) << " ''" << char(92) << " ''" << char(92) << " ''" << char(92) << " ''" << char(92) << " ''" << char(92) << " ''" << char(92) << " ''" << char(92) << " ''" << char(92) << " ''" << char(92) << " ''" << char(92) << " ''" << char(92) << " ''" << char(92) << " ''" << char(92) << " " << "" << "'''/";
		GotoXY(X_CENTER - 30, Y_CENTER + 6); cout << "  '..''..''..''..''..''..''..''..''..''..''..''..''..''..''..''..''..'";
		SetColor(0);
		GotoXY(X_CENTER - 14, Y_CENTER - 4); cout << "Enter PlayerO's name (2-10 characters): ";
		SetConsoleTextAttribute(hConsole, saved_attributes);
		for (int i = 53; i < 98; i++)
		{
			GotoXY(i, Y_CENTER - 1);
			cout << " ";
		}
		GotoXY(X_CENTER - 16, Y_CENTER-1);
		SetColor(0);
		std::getline(cin, _PLAYER2.name);
		// ve khung o day
	} while (_PLAYER2.name.length() < 2 || _PLAYER2.name.length() > 10 || _PLAYER2 == _PLAYER1);

	_PLAYER1 = LoadPlayer(_PLAYER1);
	_PLAYER2 = LoadPlayer(_PLAYER2);
}

//Thiết lập người chơi khi vào game, tiến hành nhập tên người chơi X, người chơi O sẽ mặc định là CARO_AI
void SetPlayerVsComputer(_PLAYER& _PLAYER1, _PLAYER& _PLAYER2)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
	WORD saved_attributes;
	GetConsoleScreenBufferInfo(hConsole, &consoleInfo);
	saved_attributes = consoleInfo.wAttributes;
	do
	{
		
		SetConsoleTextAttribute(hConsole, 48 | BACKGROUND_INTENSITY);
		SetColor(15);
		for (int i = 7; i < 17; i++)
		{
			for (int j = 38; j < 112; j++)
			{
				GotoXY(j, i);
				cout << " ";
			}
		}
		for (int i = 18; i < 25; i++)
		{
			for (int j = 38; j < 112; j++)
			{
				GotoXY(j, i);
				cout << " ";
			}
		}
		for (int i = 38; i < 53; i++)
		{
			GotoXY(i, 17);
			cout << " ";
		}
		for (int i = 98; i < 112; i++)
		{
			GotoXY(i, 17);
			cout << " ";
		}
		SetColor(4);
		GotoXY(X_CENTER - 30, Y_CENTER - 11); cout << "  .''..''..''..''..''..''..''..''..''..''..''..''..''..''..''..''..''.";
		GotoXY(X_CENTER - 30, Y_CENTER - 10); cout << " / .. " << char(92) << " .." << char(92) << " .." << char(92) << " .." << char(92) << " .." << char(92) << " .." << char(92) << " .." << char(92) << " .." << char(92) << " .." << char(92) << " .." << char(92) << " .." << char(92) << " .." << char(92) << " .." << char(92) << " .." << char(92) << " .." << char(92) << " .." << char(92) << " .." << char(92);
		GotoXY(X_CENTER - 29, Y_CENTER - 9); cout << char(92) << "/ /" << char(92) << "/ /" << char(92) << " ../ ../ ../ ../ ../ ../ ../ ../ ../ ../ ../ ../ ../" << char(92) << " /" << char(92) << "/ /" << char(92) << "/ ";
		GotoXY(X_CENTER - 30, Y_CENTER - 8); cout << " / /" << char(92) << "/ / ";
		GotoXY(X_CENTER + 34, Y_CENTER - 8); cout << " /" << char(92) << "/ /" << char(92);
		GotoXY(X_CENTER - 30, Y_CENTER - 7); cout << "/ /" << char(92) << " " << char(92) << "/  ";
		GotoXY(X_CENTER + 35, Y_CENTER - 7); cout << char(92) << " " << char(92) << "/" << char(92) << " " << char(92);
		GotoXY(X_CENTER - 30, Y_CENTER - 6); cout << char(92) << " " << char(92) << "/" << char(92) << " " << char(92);
		GotoXY(X_CENTER + 35, Y_CENTER - 6); cout << "/" << char(92) << " " << char(92) << "/ /";
		GotoXY(X_CENTER - 30, Y_CENTER - 5); cout << " " << char(92) << "/ /" << char(92) << " " << char(92);
		GotoXY(X_CENTER + 34, Y_CENTER - 5); cout << "/ /" << char(92) << "/ /";
		GotoXY(X_CENTER - 30, Y_CENTER - 4); cout << " / /" << char(92) << "/ /";
		GotoXY(X_CENTER + 34, Y_CENTER - 4); cout << char(92) << " " << char(92) << "/ /" << char(92);
		GotoXY(X_CENTER - 30, Y_CENTER - 3); cout << "/ /" << char(92) << " " << char(92) << "/";
		GotoXY(X_CENTER + 34, Y_CENTER - 3); cout << " " << char(92) << " " << char(92) << "/" << char(92) << " " << char(92);
		GotoXY(X_CENTER - 30, Y_CENTER - 2); cout << char(92) << " " << char(92) << "/" << char(92) << " " << char(92);
		GotoXY(X_CENTER + 34, Y_CENTER - 2); cout << " /" << char(92) << " " << char(92) << "/ /";
		GotoXY(X_CENTER - 30, Y_CENTER-1); cout << " " << char(92) << "/ /" << char(92) << " " << char(92);
		GotoXY(X_CENTER + 34, Y_CENTER-1); cout << "/ /" << char(92) << "/ /";
		GotoXY(X_CENTER - 30, Y_CENTER ); cout << " / /" << char(92) << "/ /";
		GotoXY(X_CENTER + 34, Y_CENTER ); cout << char(92) << " " << char(92) << "/ /" << char(92);
		GotoXY(X_CENTER - 30, Y_CENTER + 1); cout << "/ /" << char(92) << " " << char(92) << "/";
		GotoXY(X_CENTER + 34, Y_CENTER + 1); cout << " " << char(92) << " " << char(92) << "/" << char(92) << " " << char(92) << "";
		GotoXY(X_CENTER - 30, Y_CENTER + 2); cout << "" << char(92) << " " << char(92) << "/ /" << char(92) << "";
		GotoXY(X_CENTER + 34, Y_CENTER + 2); cout << "  " << char(92) << " " << char(92) << "/" << char(92) << " " << char(92) << "";
		GotoXY(X_CENTER - 30, Y_CENTER + 3); cout << " " << char(92) << " " << char(92) << "/" << char(92) << " " << char(92) << "";
		GotoXY(X_CENTER + 34, Y_CENTER + 3); cout << "  /" << char(92) << " " << char(92) << "/ /";
		GotoXY(X_CENTER - 30, Y_CENTER + 4); cout << " /" << char(92) << "/ /" << char(92) << "/ /../ ../ ../ ../ ../ ../ ../ ../ ../ ../ ../ ../ ../ ../ /" << char(92) << "/ " << char(92) << "/";
		GotoXY(X_CENTER - 30, Y_CENTER + 5); cout << " " << char(92) << " ''" << char(92) << " ''" << char(92) << " ''" << char(92) << " ''" << char(92) << " ''" << char(92) << " ''" << char(92) << " ''" << char(92) << " ''" << char(92) << " ''" << char(92) << " ''" << char(92) << " ''" << char(92) << " ''" << char(92) << " ''" << char(92) << " ''" << char(92) << " ''" << char(92) << " ''" << char(92) << " " << "" << "'''/";
		GotoXY(X_CENTER - 30, Y_CENTER + 6); cout << "  '..''..''..''..''..''..''..''..''..''..''..''..''..''..''..''..''..'";
		SetColor(0);
		GotoXY(X_CENTER - 14, Y_CENTER - 4); cout << "Enter Player's name (2-10 characters): ";
		SetConsoleTextAttribute(hConsole, saved_attributes);
		for (int i = 53; i < 98; i++)
		{
			GotoXY(i, Y_CENTER - 1);
			cout << " ";
		}
		GotoXY(X_CENTER - 16, Y_CENTER-1);
		std::getline(cin, _PLAYER1.name);
		// ve khung o day
	} while (_PLAYER1.name.length() < 2 || _PLAYER1.name.length() > 10);
	_PLAYER2.name = "CARO_AI";
	_PLAYER1 = LoadPlayer(_PLAYER1);
	_PLAYER2 = LoadPlayer(_PLAYER2);
}

