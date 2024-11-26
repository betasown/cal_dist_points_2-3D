#ifndef CLPARCOURS_H
#define CLPARCOURS_H

#include "CLPoint.h"
#include <vector>
#include <iostream>

class CLParcours {
private:
    std::vector<CLPoint> points;
    size_t dimension;

public:
    // Constructeur avec la dimension des points
    CLParcours(size_t dim);

    // Ajouter un point au parcours
    void ajouterPoint(const CLPoint& point);

    // Calculer la distance totale du parcours
    double calculDistance() const;

    // Afficher un message sur le parcours
    void message() const;
};

#endif
