#include "HitboxSFML.h"
#include "VecteurM.h"

#include <iostream>

HitboxSFML::HitboxSFML()
{

}

HitboxSFML::~HitboxSFML()
{

}

void HitboxSFML::glisser_perso(CaseSFML *casesfml, PersoSFML* perso, const int &taille_case, const int &x0, const int &y0)
{
    VecteurM deplacement_perso = perso->get_perso_ptr()->get_deplacement();
    perso->get_perso_ptr()->revenir_ancienne_position();
    //test coord x
    perso->get_perso_ptr()->set_deplacement(deplacement_perso.get_x(), 0);
    perso->mettre_a_jour(taille_case, x0, y0);
    sf::FloatRect perso_rect_x(perso->get_persosfml().getPosition(), perso->get_persosfml().getScale());
    if(perso_rect_x.intersects(casesfml->get_casesfml().getBounds()))
    {
        perso->get_perso_ptr()->revenir_ancienne_position();
        //test coord y
        perso->get_perso_ptr()->set_deplacement(0, perso->get_perso_ptr()->get_deplacement().get_y());
        perso->mettre_a_jour(taille_case, x0, y0);
        sf::FloatRect perso_rect_y(perso->get_persosfml().getPosition(), perso->get_persosfml().getScale());
        if(perso_rect_y.intersects(casesfml->get_casesfml().getBounds()))
        {
            perso->get_perso_ptr()->revenir_ancienne_position();
            casesfml->check_collision();
            std::cout << "KKEEEEIK" << std::endl;
        }
    }

}

void HitboxSFML::perso_et_salle(PersoSFML* perso, CaseSFML* casesalle, Jeu * jeu, const int &taille_case, const int &x0, const int &y0)
{
    std::list<CaseSFML *> cases_collision;
    sf::FloatRect perso_rect(sf::Vector2f(perso->get_position_hg().get_x(),perso->get_position_hg().get_y()), sf::Vector2f(perso->get_taille().get_x(), perso->get_taille().get_y()));
    sf::FloatRect perso_hb = perso_rect;

    bool changement_salle_autorise = 0;

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
                    cases_collision.push_back(&casesalle[j + 17*i]);
                }
                break;
            case 't':
                if(casesalle[j + 17*i].get_casesfml().getBounds().intersects(perso_hb))
                {
                    cases_collision.push_back(&casesalle[j + 17*i]);
                }
                break;
            case 'm':
                if(casesalle[j + 17*i].get_casesfml().getBounds().intersects(perso_hb))
                {
                    cases_collision.push_back(&casesalle[j + 17*i]);
                }
                break;
            case 'p':
                if(casesalle[j + 17*i].get_casesfml().getBounds().intersects(perso_hb))
                {
                    switch(j+17*i)
                    {
                    case 8: // (i = 0, j = 8)
                        changement_salle_autorise = jeu->zone_changer_salle('g');
                        break;
                    case 68: // (i = 4, j = 0)
                        changement_salle_autorise = jeu->zone_changer_salle('h');
                        break;
                    case 84: // (i = 4; j = 16)
                        changement_salle_autorise = jeu->zone_changer_salle('b');
                        break;
                    case 144: // (i = 8, j = 8)
                        changement_salle_autorise = jeu->zone_changer_salle('d');
                        break;
                    }
                    if(!changement_salle_autorise)
                    {
                        cases_collision.push_back(&casesalle[j + 17*i]);
                    }
                }
                break;
            default:
                break;
            }
        }
    }

    if(changement_salle_autorise)
    {

        return;
    }
    if(!cases_collision.empty())
    {
        bool collision = false;

        VecteurM deplacement_perso = perso->get_perso_ptr()->get_deplacement();
        perso->get_perso_ptr()->revenir_ancienne_position();
        //test coord x
        perso->get_perso_ptr()->set_deplacement(deplacement_perso.get_x(), 0);
        perso->mettre_a_jour(taille_case, x0, y0);
        sf::FloatRect perso_rect_x(sf::Vector2f(perso->get_position_hg().get_x(),perso->get_position_hg().get_y()), sf::Vector2f(perso->get_taille().get_x(), perso->get_taille().get_y()));
        for(std::list<CaseSFML *>::iterator it = cases_collision.begin(); it != cases_collision.end(); ++it)
        {
            if(perso_rect_x.intersects((*it)->get_casesfml().getBounds())){collision = true; break;}
        }
        if(collision)
        {
            perso->get_perso_ptr()->revenir_ancienne_position();
            //test coord y
            perso->get_perso_ptr()->set_deplacement(0, deplacement_perso.get_y());
            perso->mettre_a_jour(taille_case, x0, y0);
            sf::FloatRect perso_rect_y(sf::Vector2f(perso->get_position_hg().get_x(),perso->get_position_hg().get_y()), sf::Vector2f(perso->get_taille().get_x(), perso->get_taille().get_y()));
            collision = false;
            for(std::list<CaseSFML *>::iterator it = cases_collision.begin(); it != cases_collision.end(); ++it)
            {
                if(perso_rect_y.intersects((*it)->get_casesfml().getBounds())){collision = true; break;}
            }
            if(collision)
            {
                perso->get_perso_ptr()->revenir_ancienne_position();
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

void HitboxSFML::ennemis_et_salle(std::list<EnnemiSFML*>* ennemis, CaseSFML* casesalle, const int& taille_case, const int& x0, const int& y0)
{
    std::list<CaseSFML *> cases_collision;
    for(std::list<EnnemiSFML *>::iterator it_e = ennemis->begin(); it_e != ennemis->end(); ++it_e)
    {
        sf::FloatRect ennemi_rect(sf::Vector2f((*it_e)->get_position_hg().get_x(),(*it_e)->get_position_hg().get_y()), sf::Vector2f((*it_e)->get_taille().get_x(), (*it_e)->get_taille().get_y()));
        sf::FloatRect ennemi_hb = ennemi_rect;

        for(int i=0; i<9; i++)
        {
            for(int j=0; j<17; j++)
            {
                //std::cout << "coucou" << std::endl;
                switch(casesalle[j + 17*i].get_type_case())
                {
                case 'r':
                    if(casesalle[j + 17*i].get_casesfml().getBounds().intersects(ennemi_hb))
                    {
                        cases_collision.push_back(&casesalle[j + 17*i]);
                    }
                    break;
                case 't':
                    if(casesalle[j + 17*i].get_casesfml().getBounds().intersects(ennemi_hb))
                    {
                        cases_collision.push_back(&casesalle[j + 17*i]);
                    }
                    break;
                case 'm':
                    if(casesalle[j + 17*i].get_casesfml().getBounds().intersects(ennemi_hb))
                    {
                        cases_collision.push_back(&casesalle[j + 17*i]);
                    }
                    break;
                case 'p':
                    break;
                default:
                    break;
                }
            }
        }

        if(!cases_collision.empty())
        {
            bool collision = false;

            VecteurM deplacement_ennemi = (*it_e)->get_ennemi()->get_deplacement();
            (*it_e)->get_ennemi()->revenir_ancienne_position();
            /*
            (*it_e)->mettre_a_jour_position(taille_case, x0, y0);
            sf::FloatRect ennemi_rect_test(sf::Vector2f((*it_e)->get_position_hg().get_x(),(*it_e)->get_position_hg().get_y()), sf::Vector2f((*it_e)->get_taille().get_x(), (*it_e)->get_taille().get_y()));
            for(std::list<CaseSFML *>::iterator it = cases_collision.begin(); it != cases_collision.end(); ++it)
            {
                if(ennemi_rect_test.intersects((*it)->get_casesfml().getBounds())){std::cout << "BULLSHIT" << std::endl;}
            }*/
            //test coord x
            (*it_e)->get_ennemi()->set_deplacement(deplacement_ennemi.get_x(), 0);
            (*it_e)->mettre_a_jour_position(taille_case, x0, y0);
            sf::FloatRect ennemi_rect_x(sf::Vector2f((*it_e)->get_position_hg().get_x(),(*it_e)->get_position_hg().get_y()), sf::Vector2f((*it_e)->get_taille().get_x(), (*it_e)->get_taille().get_y()));
            for(std::list<CaseSFML *>::iterator it = cases_collision.begin(); it != cases_collision.end(); ++it)
            {
                if(ennemi_rect_x.intersects((*it)->get_casesfml().getBounds())){collision = true; break;}
            }
            if(collision)
            {
                (*it_e)->get_ennemi()->revenir_ancienne_position();
                //test coord y
                (*it_e)->get_ennemi()->set_deplacement(0, deplacement_ennemi.get_y());
                (*it_e)->mettre_a_jour_position(taille_case, x0, y0);
                sf::FloatRect ennemis_rect_y(sf::Vector2f((*it_e)->get_position_hg().get_x(),(*it_e)->get_position_hg().get_y()), sf::Vector2f((*it_e)->get_taille().get_x(), (*it_e)->get_taille().get_y()));
                collision = false;
                for(std::list<CaseSFML *>::iterator it = cases_collision.begin(); it != cases_collision.end(); ++it)
                {
                    if(ennemis_rect_y.intersects((*it)->get_casesfml().getBounds())){collision = true; break;}
                }
                if(collision)
                {
                    (*it_e)->get_ennemi()->revenir_ancienne_position();
                }
            }
        }
        cases_collision.clear();
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


