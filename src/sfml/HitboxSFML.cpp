#include "HitboxSFML.h"

HitboxSFML::HitboxSFML()
{

}

HitboxSFML::~HitboxSFML()
{

}

void HitboxSFML::perso_et_salle(PersoSFML* perso, CaseSFML* casesalle)
{
    //sf::FloatRect perso_hb = perso->get_persosfml().getGlobalBounds();
    /*
    sf::VertexArray perso_vertex;
    perso_vertex.resize(4);
    perso_vertex.setPrimitiveType(sf::Quads);
    perso_vertex[0].position = sf::Vector2f(perso->get_persosfml().getLocalBounds().left,perso->get_persosfml().getLocalBounds().top);
    perso_vertex[1].position = sf::Vector2f(perso->get_persosfml().getLocalBounds().left + perso->get_persosfml().getLocalBounds().width, perso->get_persosfml().getLocalBounds().top);
    perso_vertex[2].position = sf::Vector2f(perso->get_persosfml().getLocalBounds().left + perso->get_persosfml().getLocalBounds().width, perso->get_persosfml().getLocalBounds().top + perso->get_persosfml().getLocalBounds().height);
    perso_vertex[3].position = sf::Vector2f(perso->get_persosfml().getLocalBounds().left, perso->get_persosfml().getLocalBounds().top + perso->get_persosfml().getLocalBounds().height);

    sf::Transform perso_transf;
    perso_transf.combine(perso->get_persosfml().getTransform());
    perso_transf.scale(0.1, 0.1);

    perso_vertex[0].position = perso_transf.transformPoint(perso_vertex[0].position);
    perso_vertex[1].position = perso_transf.transformPoint(perso_vertex[1].position);
    perso_vertex[2].position = perso_transf.transformPoint(perso_vertex[2].position);
    perso_vertex[3].position = perso_transf.transformPoint(perso_vertex[3].position);

    sf::FloatRect perso_hb = perso_vertex.getBounds();*/
    sf::FloatRect perso_rect = perso->get_persosfml().getGlobalBounds();

    //sf::Transform perso_transf;
    //perso_transf.position
    //perso_transf.scale(sf::Vector2f(0.4 , 0.4), perso->get_persosfml().getOrigin());
    // perso_transf.translate(perso->get_persosfml().getPosition());

    //perso_transf.rotate(-perso->get_persosfml().getRotation(), perso->get_persosfml().getOrigin());

    sf::FloatRect perso_hb = perso_rect;




    for(int i=0; i<9; i++)
    {
        for(int j=0; j<17; j++)
        {
            //std::cout << "coucou" << std::endl;
            switch(casesalle[j + 17*i].get_type_case())
            {
            case 'r':
                if(casesalle[j + 17*i].get_casesfml().getBounds().intersects(perso_hb))
                {
                    //std::cout << casesalle[j + 17*i].get_type_case() << std::endl;
                    perso->get_perso_ptr()->revenir_ancienne_position();
                }
                break;
            case 't':
                if(casesalle[j + 17*i].get_casesfml().getBounds().intersects(perso_hb))
                {
                    perso->get_perso_ptr()->revenir_ancienne_position();
                }
                break;
            case 'm':
                if(casesalle[j + 17*i].get_casesfml().getBounds().intersects(perso_hb))
                {
                    perso->get_perso_ptr()->revenir_ancienne_position();
                }
                break;
            case 'p':
                break;
            default:
                break;
            }
        }
    }
}

void HitboxSFML::projectiles_et_salle(std::list<ProjectileSFML*>* projectiles, CaseSFML* casesalle)
{
    sf::FloatRect projectile_hb;
    for(std::list<ProjectileSFML *>::iterator it_sfml = projectiles->begin(); it_sfml != projectiles->end(); ++it_sfml)
    {
        for(int i=0; i<9; i++)
        {
            for(int j=0; j<17; j++)
            {
                projectile_hb = (*it_sfml)->retourne_projectilesfml().getGlobalBounds();
                //std::cout << "coucou" << std::endl;
                switch(casesalle[j + 17*i].get_type_case())
                {
                case 'r':
                    if(casesalle[j + 17*i].get_casesfml().getBounds().intersects(projectile_hb))
                    {
                        //std::cout << casesalle[j + 17*i].get_type_case() << std::endl;
                        (*it_sfml)->get_projectile()->set_collision();
                    }
                    break;
                case 'm':
                    if(casesalle[j + 17*i].get_casesfml().getBounds().intersects(projectile_hb))
                    {
                        (*it_sfml)->get_projectile()->set_collision();
                    }
                    break;
                default:
                    break;
                }
            }
        }
    }
}

void HitboxSFML::projectiles_et_ennemis(std::list<ProjectileSFML*>* projectiles, std::list<EnnemiSFML*>* ennemis)
{
    sf::FloatRect projectile_hb;
    sf::FloatRect ennemis_hb;
    for(std::list<ProjectileSFML *>::iterator it_proj = projectiles->begin(); it_proj != projectiles->end(); ++it_proj)
    {
        projectile_hb = (*it_proj)->retourne_projectilesfml().getGlobalBounds();
        for(std::list<EnnemiSFML *>::iterator it_ennemis = ennemis->begin(); it_ennemis != ennemis->end(); ++it_ennemis)
        {
            if((*it_ennemis)->get_ennemi()->is_vivant())
            {
                ennemis_hb = (*it_ennemis)->get_ennemisfml().getGlobalBounds();
                if(projectile_hb.intersects(ennemis_hb))
                {
                    (*it_proj)->get_projectile()->set_collision();
                    (*it_ennemis)->get_ennemi()->set_mort();
                }
            }
        }
    }
}


