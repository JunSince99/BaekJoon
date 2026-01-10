#include <iostream>

class Date {
    int year_;
    int month_;
    int day_;

public:
    void SetDate(int year, int month, int date);
    void AddDay(int inc);
    void AddMonth(int inc);
    void AddYear(int inc);

    int GetThisMonthEndDay(int year, int month);

    void ShowDate();

    Date(int year, int month, int date) {
        year_ = year;
        month_ = month;
        day_ = date;
        std::cout << "초기화 됐습니다." << '\n';
        ShowDate();
    }

    Date() {
        year_ = 2000;
        month_ = 1;
        day_ = 1;
        std::cout << "초기화 됐습니다." << '\n';
        ShowDate();
    }
};

void Date::SetDate(int year, int month, int date)
{
    year_ = year;
    month_ = month;
    day_ = date;
}

int Date::GetThisMonthEndDay(int year, int month)
{
    static int month_day[12] = {31,28,31,30,31,30,31,31,30,31,30,31};

    if (month == 2 && (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0))) 
        return 29;
    
    return month_day[month-1];
}

void Date::AddDay(int inc)
{
    while(true)
    {
        int currentMonthEndDay = GetThisMonthEndDay(year_, month_);

        if(day_ + inc <= currentMonthEndDay) {
            day_ += inc;
            return;
        } else {
            inc -= currentMonthEndDay - day_ + 1;
            day_ = 1;
            AddMonth(1);
        }
    }
}

void Date::AddMonth(int inc)
{
    int monthSum = month_ + inc - 1;

    month_ = monthSum % 12 + 1;
    AddYear(monthSum / 12);
}

void Date::AddYear(int inc)
{
    year_ += inc;
}

void Date::ShowDate()
{
    std::cout << year_ << "년 " << month_ << "월 " << day_ << "일 입니다." << '\n';
}

int main() {
    Date currentDay;
    while(1) {
        std::cout << "1. 날짜 설정 2. 일 추가 3. 월 추가 4. 년 추가 5. 날짜 출력" << '\n';
        int cmd;
        int y,m,d;
        std::cin >> cmd;
        if (cmd == 99) break;
        switch(cmd) {
            case 1:
                std::cout << "연, 월, 일 입력 : ";
                std::cin >> y >> m >> d;
                currentDay.SetDate(y,m,d);
                break;
            case 2:
                std::cout << "추가할 일 수를 입력 : ";
                std::cin >> d;
                currentDay.AddDay(d);
                break;
            case 3:
                std::cout << "추가할 월 수를 입력 : ";
                std::cin >> m;
                currentDay.AddMonth(m);
                break;
            case 4:
                std::cout << "추가할 년 수를 입력 : ";
                std::cin >> y;
                currentDay.AddYear(y);
                break;
            case 5:
                currentDay.ShowDate();
                break;
        }
    }
}