#include "CLParcours.h"

CLParcours::CLParcours(size_t dim) : dimension(dim) {}

void CLParcours::ajouterPoint(const CLPoint& point) {
    if (point.getDimension() != dimension) {
        throw std::invalid_argument("Dimension du point incompatible avec le parcours.");
    }
    points.push_back(point);
}

double CLParcours::calculDistance() const {
    double totalDistance = 0.0;
    for (size_t i = 1; i < points.size(); ++i) {
        totalDistance += points[i - 1].distance(points[i]);
    }
    return totalDistance;
}

void CLParcours::message() const {
    std::cout << "Parcours de dimension " << dimension
              << " avec " << points.size() << " points." << std::endl;
}
