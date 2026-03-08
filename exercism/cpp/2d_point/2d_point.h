#pragma once

#include <iostream>
#include <ostream>


namespace points_namespace {

class Point2D {
public:
    double x, y;

    Point2D(double x = 0.0, double y = 0.0);
    explicit Point2D(double val);
    Point2D(const Point2D& other);
    
    Point2D operator+(const Point2D& other) const;
    bool operator==(const Point2D& other) const;

    // dajemy friend bo operator ostream jest na zewnatrz klasy a ma dostep do klasy
    friend std::ostream& operator<<(std::ostream& os, const Point2D& p);

    //ta metoda nie zmieni zadnego pola obecnego obiektu const po ()
    void show() const;
};

}