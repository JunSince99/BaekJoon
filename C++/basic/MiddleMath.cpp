#include <iostream>

class Point{
    int x, y;

public:
    Point(int pos_x, int pos_y);
};

class Geometry {
    Point* point_array[100];

public:
    Geometry(Point **point_list);
    Geometry() = default;

    void AddPoint(const Point &point);

    void PrintDistance();

    void PrintNumMeets();
};

Point::Point(int pos_x, int pos_y) {
    x = pos_x;
    y = pos_y;
}

Geometry::Geometry(Point **point_list) {
    for(int i = 0; i<100; i++) {
        point_array[i] = point_list[i];
    }
}