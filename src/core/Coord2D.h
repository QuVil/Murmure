#ifndef COORD2D_H_INCLUDED
#define COORD2D_H_INCLUDED

class Coord2D
{
private:
    float x, y;

public:
    Coord2D();

    Coord2D(float a, float b);

    void coord_set(float a, float b);

    void set_x(float a);

    void set_y(float b);

    float get_x()const;

    float get_y()const;
};

#endif // COORD2D_H_INCLUDED