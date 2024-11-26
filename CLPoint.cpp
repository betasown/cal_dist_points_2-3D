#include "CLPoint.h"

CLPoint::CLPoint(const std::initializer_list<double>& coords) : coordonnees(coords) {}

CLPoint::CLPoint(const std::vector<double>& coords) : coordonnees(coords) {}

double CLPoint::distance(const CLPoint& other) const {
    if (coordonnees.size() != other.coordonnees.size()) {
        throw std::invalid_argument("Les points n'ont pas la même dimension.");
    }
    double sum = 0.0;
    for (size_t i = 0; i < coordonnees.size(); ++i) {
        double diff = coordonnees[i] - other.coordonnees[i];
        sum += diff * diff;
    }
    return std::sqrt(sum);
}

void CLPoint::afficherCoordo() const {
    std::cout << "Coordonnées du point : ";
    for (double c : coordonnees) {
        std::cout << c << " ";
    }
    std::cout << std::endl;
}

size_t CLPoint::getDimension() const {
    return coordonnees.size();
}

double CLPoint::getCoord(size_t index) const {
    if (index >= coordonnees.size()) {
        throw std::out_of_range("Index de coordonnée invalide.");
    }
    return coordonnees[index];
}
