#include<iostream>
#include<vector>
#include <windows.h>
using namespace std;
#define TABLE_X 20 //테트리스 판 x 축 길이
#define TABLE_Y 30 //테트리스 판 y 축 길이
class MainMenu {
public:
    MainMenu() {
        cout << "\n\n\n\n";
        cout << "\t\t"; cout << "@@@@@@@@@@@@  @@@@@@@@@   @@@@@@@@@@@  @@@@@@@@   @   @@@@@@@@@@@\n";
        cout << "\t\t"; cout << "      @       @                @       @      @   @   @          \n";
        cout << "\t\t"; cout << "      @       @                @       @      @   @   @          \n";
        cout << "\t\t"; cout << "      @       @@@@@@@@@        @       @     @    @   @@@@@@@@@@@\n";
        cout << "\t\t"; cout << "      @       @                @       @ @ @      @             @\n";
        cout << "\t\t"; cout << "      @       @                @       @     @    @             @\n";
        cout << "\t\t"; cout << "      @       @@@@@@@@@        @       @      @   @   @@@@@@@@@@@\n\n\n\n\n";
        cout << "\t\t"; cout << "                게임을 시작하려면 아무키나 누르세요.\n\n\n\n\n\n\n";
        cout << "\t\t"; cout << "                   TetrisGame1.0 By SeokJinLee\n";
        getchar(); // 아무키 입력 기다림
        system("cls"); // 콘솔 창 clear
    }
};
class GameTable {
private:
    int x; // 가로
    int y; // 세로
    vector<vector<int> > table; // 테이블 판 0 = " ", 1 = "▦" , 2  = "■"
public:
    GameTable(int x, int y) { //테트리스 판 뼈대 생성
        this->x = x;
        this->y = y;
        for (int i = 0; i < y; i++) {
            vector<int> temp;
            for (int j = 0; j < x; j++) {
                temp.push_back(0);
            }
            table.push_back(temp);
        }
        //가장 자리 뼈대 색칠
        for (int i = 0; i < x; i++) {
            table[0][i] = 1;
            table[y - 1][i] = 1;
        }
        for (int i = 1; i < y - 1; i++) {
            table[i][0] = 1;
            table[i][x - 1] = 1;
        }
    }
    /*게임판 그리는 함수*/
    void DrawGameTable() {
        for (int i = 0; i < y; i++) {
            for (int j = 0; j < x; j++) {
                if (table[i][j] == 1)cout << "▦ ";
                else cout << "  "; // 두 칸 띄우기
            }
            cout << "\n";
        }
    }
};
int main(void) {
	SetConsoleOutputCP(CP_UTF8);
    system("mode con cols=100 lines=40 | title 테트리스 게임"); // 콘솔창 크기 및 제목 설정
    GameTable gt(TABLE_X, TABLE_Y); //게임 판 그리기 객체 생성
    MainMenu(); // 메인 메뉴 그리기 생성자 호출
    gt.DrawGameTable(); // 게임판을 그린다.
    getchar();
    return 0;
}
