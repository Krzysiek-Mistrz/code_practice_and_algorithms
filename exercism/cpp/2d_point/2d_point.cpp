#include "2d_point.h"


namespace points_namespace {

Point2D::Point2D(double x, double y) : x(x), y(y) {}
Point2D::Point2D(double val) : x(val), y(val) {}
Point2D::Point2D(const Point2D& other) : x(other.x), y(other.y) {}

Point2D Point2D::operator+(const Point2D& other) const {
    return Point2D(this->x + other.x, this->y + other.y);
}

bool Point2D::operator==(const Point2D& other) const {
    return (x == other.x) and (y == other.y);
}

std::ostream& operator<<(std::ostream& os, Point2D& p) {
    os << "(" << p.x << ", " << p.y << ")";
    return os;
}

void Point2D::show() const {
    std::cout << "Point(" << x << ", " << y << ")" << std::endl;
}

}
