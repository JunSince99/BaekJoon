#include <iostream>
#include <string.h>

class Marine {
    int hp;
    int coord_x, coord_y;
    int is_dead;
    char* name;

    const int default_damage;

public:
    Marine();
    Marine(int x,int y, const char* marine_name);
    Marine(int x,int y);
    ~Marine();

    int attack();
    void be_attacked(int damage_earn);
    void move(int x, int y);

    void show_status();
};
Marine::Marine() : hp(50), coord_x(0), coord_y(0), default_damage(5), is_dead(false), name(NULL) {}
Marine::Marine(int x, int y, const char* marine_name) {
    name = new char[strlen(marine_name) + 1];
    strcpy(name, marine_name);

    hp = 50;
    coord_x = x;
    coord_y = y;
    default_damage = 5;
    is_dead = false;
}
Marine::Marine(int x, int y) : hp(50), coord_x(x), coord_y(y), default_damage(5), is_dead(false), name(NULL) {}
int Marine::attack() { return damage; }
void Marine::be_attacked(int damage_earn) {
    hp -= damage_earn;
    if (hp <= 0) is_dead = true;
}
void Marine::move(int x, int y) {
    coord_x = x;
    coord_y = y;
}
void Marine::show_status() {
    std::cout << " *** Marine : " << name << " *** " << '\n';
    std::cout << " Location : ( " << coord_x << " , " << coord_y << " ) " << '\n';
    std::cout << " HP : " << hp << '\n';
}
Marine::~Marine() {
    std::cout << name << " 의 소멸자 호출 ! " << '\n';
    if (name != NULL) {
        delete[] name;
    }
}

int main() {
    Marine* marines[100];

    marines[0] = new Marine(2, 3, "Marine 2");
    marines[1] = new Marine(1, 5, "Marine 1");

    marines[0]->show_status();
    marines[1]->show_status();

    std::cout << '\n' << "마린 1이 마린 2를 공격! " << '\n';

    marines[0]->be_attacked(marines[1]->attack());

    marines[0]->show_status();
    marines[1]->show_status();

    delete marines[0];
    delete marines[1];
}