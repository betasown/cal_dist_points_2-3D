#include <iostream>
#include "CLPoint.h"
#include "CLParcours.h"

int main() {
    size_t dimension;
    size_t nombrePoints;

    std::cout << "Entrez la dimension des points (2 pour 2D, 3 pour 3D) : ";
    std::cin >> dimension;

    if (dimension < 2 || dimension > 3) {
        std::cerr << "Dimension non prise en charge. Utilisez 2 ou 3." << std::endl;
        return 1;
    }

    std::cout << "Entrez le nombre de points du parcours : ";
    std::cin >> nombrePoints;

    CLParcours parcours(dimension);

    for (size_t i = 0; i < nombrePoints; ++i) {
        std::vector<double> coords(dimension);
        std::cout << "Entrez les " << dimension << " coordonnées du point " << i + 1 << " : ";
        for (size_t j = 0; j < dimension; ++j) {
            std::cin >> coords[j];
        }
        try {
            CLPoint point(coords);
            parcours.ajouterPoint(point);
        } catch (const std::exception& e) {
            std::cerr << "Erreur lors de l'ajout du point : " << e.what() << std::endl;
            return 1;
        }
    }

    try {
        double distanceTotale = parcours.calculDistance();
        std::cout << "Distance totale du parcours : " << distanceTotale << std::endl;
        parcours.message();
    } catch (const std::exception& e) {
        std::cerr << "Erreur lors du calcul de la distance : " << e.what() << std::endl;
        return 1;
    }

    return 0;
}
