#ifndef VECTEURM_H_INCLUDED
#define VECTEURM_H_INCLUDED


class VecteurM
{
private:
    float x, y;

public:
    VecteurM();

    VecteurM(const float &x2, const float &y2);

    VecteurM& operator =(const VecteurM &vect2);

    const VecteurM operator +(const VecteurM &v2);

    void diminuer_inertie(const float &coeff);

    void set_x(const float& a);

    void set_y(const float& b);

    float get_x() const;

    float get_y() const;
};

#endif // VECTEURM_H_INCLUDED
