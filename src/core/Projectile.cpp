#include "Projectile.h"
#include "math.h"

#include <iostream>
#include <cassert>

Projectile::Projectile()
{
    id_projectile = 1;
    degats = 1;
}

Projectile::Projectile(const int& p_id, const int& p_type, const int& p_degat, const float& p_vitesse, const float& p_taille, const VecteurM& p_orientation, const Coord2D& p_position)
{
    id_projectile = p_id;
    type = p_type;
    degats = p_degat;
    vitesse = p_vitesse;
    taille_projectile = p_taille;
    orientation = p_orientation;
    position = p_position;
    angle_orientation = atan2(orientation.get_x(),orientation.get_y());
    collision = false;
}

void Projectile::avancer(const float &vitesse_frame)
{
    //std::cout << position.get_x() << " avant " << std::endl;
    //std::cout << vitesse << " avant " << std::endl;
    position.set_x(position.get_x() + vitesse_frame*vitesse*cos(-angle_orientation + M_PI_2));
    //std::cout << position.get_x() << " apres " << std::endl;
    position.set_y(position.get_y() + vitesse_frame*vitesse*sin(-angle_orientation + M_PI_2));
}

void Projectile::set_collision()
{
    collision = true;
}

float Projectile::get_orientation_degre() const
{
    return (atan2(orientation.get_x(), orientation.get_y())/M_PI) * 180;
}

float Projectile::get_orientation_radian() const
{
    return atan2(orientation.get_x(),orientation.get_y());
}

float Projectile::get_taille_projectile() const
{
    return taille_projectile;
}

Coord2D Projectile::get_position() const
{
    //assert(position.get_x()>=0);
    return position;
}

bool Projectile::get_collision() const
{
    return collision;
}
