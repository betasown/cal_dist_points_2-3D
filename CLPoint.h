#ifndef CLPOINT_H
#define CLPOINT_H

#include <vector>
#include <iostream>
#include <cmath>
#include <stdexcept>

class CLPoint {
private:
    std::vector<double> coordonnees;

public:
    // Constructeur pour une liste de coordonnées
    CLPoint(const std::initializer_list<double>& coords);

    // Nouveau constructeur pour un vecteur de coordonnées
    CLPoint(const std::vector<double>& coords);

    // Méthode pour calculer la distance avec un autre point
    double distance(const CLPoint& other) const;

    // Afficher les coordonnées du point
    void afficherCoordo() const;

    // Obtenir la dimension du point
    size_t getDimension() const;

    // Accéder à une coordonnée spécifique
    double getCoord(size_t index) const;
};

#endif // CLPOINT_H
