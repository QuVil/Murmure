#ifndef VECTEURM_H_INCLUDED
#define VECTEURM_H_INCLUDED

/** \file VecteurM.h
 *
 * \brief Module de Vecteur en 2 dimensions appliqué à Murmure
 */


class VecteurM
{
private:
    float x; /**< Coordonnée x du vecteur */
    float y; /**< Coordonnée y du vecteur */


public:
    /** \brief Constructeur par défaut
     */
    VecteurM();

    /** \brief Constructeur avec paramètres
     * Construit l'instance avec une coordonnée x et y
     * \param[in] x2 : coordonnée horizontale
     * \param[in] y2 : coordonnée verticale
     */
    VecteurM(const float &x2, const float &y2);

    /** \brief Surcharge de =
     * Permet de copier les données d'un second vecteur dans l'instance actuelle
     * \param vect2 : Vecteur à copier
     * \return l'instance actuelle avec les parametres copiés du second vecteur
     */
    VecteurM& operator =(const VecteurM &vect2);

    /** \brief Surcharge de +
     * Permet de faire l'addition entre 2 vecteurs
     * \param v2 : second vecteur à additionner
     * \return La somme this+v2
     *
     */
    const VecteurM operator +(const VecteurM &v2);

    /** \brief Diminuer inertie
     * Permet de diminuer l'intertie du mouvement de l'entité
     * \param coeff : coefficient de diminution
     */
    void diminuer_inertie(const float &coeff);

    /** \brief Mutateur de x
     *
     * \param a : nouvelle valeur pour la coordonnée horizontale
     */
    void set_x(const float& a);

    /** \brief Mutateur de y
     *
     * \param b : nouvelle valeur pour la coordonnée verticale
     */
    void set_y(const float& b);

    /** \brief Accesseur de x
     *
     * \return la coordonnée horizontale
     *
     */
    float get_x() const;

    /** \brief Accesseur de y
     *
     * \return la coordonnée verticale
     *
     */
    float get_y() const;
};

#endif // VECTEURM_H_INCLUDED
