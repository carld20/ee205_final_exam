///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  ee205_lab08c_all_creatures_great_and_small - EE 205 - Spr 2022
///
/// @file Classes.h
/// @version 1.0
///
/// @author Carl Domingo <carld20@hawaii.edu>
/// @date   13_May_2022
///////////////////////////////////////////////////////////////////////////////

#include <stdexcept>
#include <cassert>

using namespace std;

class Shape{
public:
    double compute_area(double side1, double side2){
        return side1 * side2;
    }
};

class Rectangle: public Shape{
protected:
    double length;
    double width;

public:
    Rectangle( double newLength, double newWidth ) noexcept{
        assert(validate());
        length = newLength;
        width = newWidth;
    }

    double getLength(){
        return length;
    };

    double getWidth(){
        return width;

    };


    bool validate(){
        if(( length > 0) && ( width > 0 )){
            return true;
        }

        else{
            throw invalid_argument("length and width must be > 0");
        }
    }

    double compute_area(){
        return Shape::compute_area( length, width );
    }
};

class Square: public Rectangle{
protected:
    double side;
public:
    Square( double newSide ): Rectangle( newSide, newSide ){
        assert(validate());
         getSide();
    }

    bool validate(){
        if(side > 0){
            return true;
        }
        else{
            throw invalid_argument("side must be > 0");
            return false;
        }
    }

    double getSide(){
        side = Rectangle::length;
        side = Rectangle::width;

        return side;
    }
};