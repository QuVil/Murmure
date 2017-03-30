#include "Projectile.h"

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

void Projectile::avancer(const float &vitesse_frame)
{
    position.set_x(position.get_x() + orientation.get_x()*vitesse_frame*vitesse);
    position.set_y(position.get_y() + orientation.get_y()*vitesse_frame*vitesse);
}


