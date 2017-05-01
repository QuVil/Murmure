#ifndef VECTEURM_H_INCLUDED
#define VECTEURM_H_INCLUDED

/** \file VecteurM.h
 *
 * \brief Module de Vecteur en 2 dimensions appliqu� � Murmure
 */


class VecteurM
{
private:
    float x; /**< Coordonn�e x du vecteur */
    float y; /**< Coordonn�e y du vecteur */


public:
    /** \brief Constructeur par d�faut
     */
    VecteurM();

    /** \brief Constructeur avec param�tres
     * Construit l'instance avec une coordonn�e x et y
     * \param[in] x2 : coordonn�e horizontale
     * \param[in] y2 : coordonn�e verticale
     */
    VecteurM(const float &x2, const float &y2);

    /** \brief Surcharge de =
     * Permet de copier les donn�es d'un second vecteur dans l'instance actuelle
     * \param vect2 : Vecteur � copier
     * \return l'instance actuelle avec les parametres copi�s du second vecteur
     */
    VecteurM& operator =(const VecteurM &vect2);

    /** \brief Surcharge de +
     * Permet de faire l'addition entre 2 vecteurs
     * \param v2 : second vecteur � additionner
     * \return La somme this+v2
     *
     */
    const VecteurM operator +(const VecteurM &v2);

    /** \brief Diminuer inertie
     * Permet de diminuer l'intertie du mouvement de l'entit�
     * \param coeff : coefficient de diminution
     */
    void diminuer_inertie(const float &coeff);

    /** \brief Mutateur de x
     *
     * \param a : nouvelle valeur pour la coordonn�e horizontale
     */
    void set_x(const float& a);

    /** \brief Mutateur de y
     *
     * \param b : nouvelle valeur pour la coordonn�e verticale
     */
    void set_y(const float& b);

    /** \brief Accesseur de x
     *
     * \return la coordonn�e horizontale
     *
     */
    float get_x() const;

    /** \brief Accesseur de y
     *
     * \return la coordonn�e verticale
     *
     */
    float get_y() const;
};

#endif // VECTEURM_H_INCLUDED
