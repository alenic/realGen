#include "realgenoptions.h"


RealGenOptions::RealGenOptions() {
    populationSize = 100;

    maxGenerations = 100 * populationSize;

    selectionType = ROULETTE_WHEEL_SELECTION;
    selectionTournamentP = 4;
    selectionSorting = true;
    selectionElitismFactor = 0.1;

    crossoverType = UNIFORM_CROSSOVER;
    crossoverIndex1 = 0;
    crossoverIndex2 = 0;

    mutationType = UNIFORM_MUTATION;
    mutationUniformPerc = 0.25;

    mutationRate = 0.1;

    mutationGaussianScale = 1.0;
    mutationGaussianShrink = 1.0;

}

RealGenOptions::~RealGenOptions() {

}

void RealGenOptions::setPopulationSize(int value) {
    populationSize = value;
}

void RealGenOptions::setChromosomeSize(int value) {
    chromosomeSize = value;
}

void RealGenOptions::setLowerBounds(const vector<float> &lb) {
    lowerBounds = lb;
}

void RealGenOptions::setUpperBounds(const vector<float> &ub) {
    upperBounds = ub;
}

void RealGenOptions::setBounds(const vector<float> &lb, const vector<float> &ub) {
    lowerBounds = lb;
    upperBounds = ub;
}

void RealGenOptions::setMaxGenerations(int value) {
    maxGenerations = value;
}

void RealGenOptions::setSelectionType(string value) {
    if (value == "roulette_wheel")
        selectionType = ROULETTE_WHEEL_SELECTION;
    else if (value == "tournament")
        selectionType = TOURNAMENT_SELECTION;
    else
        cerr << "setSelectionType(" << value << ") is an invalid option value" << endl;
}

void RealGenOptions::setSelectionTournamentP(int value) {
    selectionTournamentP = value;
}

void RealGenOptions::setSorting(bool value) {
    selectionSorting = value;
}

void RealGenOptions::setElitismFactor(float value) {
    selectionElitismFactor = value;
}

void RealGenOptions::setMutationType(string value) {
    if (value == "uniform")
        mutationType = UNIFORM_MUTATION;
    else if (value == "gaussian")
        mutationType = GAUSSIAN_MUTATION;
    else
        cerr << "setMutationType(" << value << ") is an invalid option value" << endl;
}

void RealGenOptions::setUniformMutationPercentage(float value) {
    mutationUniformPerc = value;
}

void RealGenOptions::setMutationRate(float value) {
    mutationRate = value;
}

void RealGenOptions::setMutationGaussianScaleShrink(float scale, float shrink) {
    mutationGaussianScale = scale;
    mutationGaussianShrink = shrink;
}

void RealGenOptions::setCrossoverType(string value) {
    if (value == "uniform")
        crossoverType = UNIFORM_CROSSOVER;
    else if (value == "single_point")
        crossoverType = SINGLE_POINT_CROSSOVER;
    else if (value == "two_point")
        crossoverType = TWO_POINT_CROSSOVER;
    else
        cerr << "setCrossoverType(" << value << ") is an invalid option value" << endl;
}

void RealGenOptions::setSinglePointCrossoverIndex(int value) {
    crossoverIndex1 = value;
}

void RealGenOptions::setTwoPointCrossoverIndexes(int i1, int i2) {
    crossoverIndex1 = i1;
    crossoverIndex2 = i2;
}

