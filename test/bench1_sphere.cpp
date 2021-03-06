#include "testcommon.h"
#include "fitnessfunction.h"


class SphereFitness : public FitnessFunction {
public:
    SphereFitness() {}

    double eval(const RealGenotype &g) {
        double sse = 0.0;
        for(int i=0; i<g.gene.size(); i++) {
            double dx = g.gene[i]/5.12;
            sse += dx*dx;
        }
        return sse;
    }
};



void bench1_sphere(RealGenOptions opt, GAResults &results) {
    vector<float> LB = { -5.12, -5.12, -5.12, -5.12 };
    vector<float> UB = { 5.12,  5.12,  5.12,  5.12};

    SphereFitness *myFitnessFunction = new SphereFitness();
    strcpy(results.name, "Sphere");
    results.maxIter = 5000;
    results.Np = 50;

    opt.setPopulationSize(results.Np);
    opt.setChromosomeSize(4);
    opt.setBounds(LB, UB);
    RealGen ga(opt);
    ga.setFitnessFunction(myFitnessFunction);

    testRealGen(ga, results.maxIter, 1e-4, results);

    delete myFitnessFunction;
}
