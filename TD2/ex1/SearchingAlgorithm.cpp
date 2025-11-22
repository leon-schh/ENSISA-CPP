#include "SearchingAlgorithm.h"

int SearchingAlgorithm::totalComparisons = 0;
int SearchingAlgorithm::totalSearch = 0;
double SearchingAlgorithm::averageComparisons = 0.0;

SearchingAlgorithm::SearchingAlgorithm() : numberComparisons(0) {}

void SearchingAlgorithm::displaySearchResults(std::ostream& os, int result, int target) {
    os << "Recherche de l'élément " << target << ":\n";
    if (result != -1) {
        os << "  Élément trouvé à l'indice " << result << "\n";
    } else {
        os << "  Élément non trouvé\n";
    }
    os << "  Nombre de comparaisons: " << numberComparisons << "\n";
    os << "  Total des comparaisons (toutes recherches): " << totalComparisons << "\n";
    os << "  Nombre moyen de comparaisons: " << averageComparisons << "\n";
}
