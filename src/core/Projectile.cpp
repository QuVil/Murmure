#include "Projectile.h"
#include "math.h"

Projectile::Projectile()
{
    id_projectile = 1;
    degats = 1;
}

Projectile::Projectile(const int& p_id, const int& p_type, const int& p_degat, const float& p_vitesse, const VecteurM& p_orientation, const Coord2D& p_position)
{
    id_projectile = p_id;
    type = p_type;
    degats = p_degat;
    vitesse = p_vitesse;
    orientation = p_orientation;
    position = p_position;
}


Projectile::Projectile(int id, int deg)
{
    id_projectile = id;
    degats = deg;
}

void Projectile::avancer()
{
    position.set_x(vitesse*orientation.get_x());
    position.set_y(vitesse*orientation.get_y());
}

float Projectile::get_orientation_degre() const
{
    return (atan2(orientation.get_x(), orientation.get_y())/M_PI) * 180;
}

Coord2D Projectile::get_position() const
{
    return position;
}
