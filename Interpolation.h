//
// Created by Alejandro Millan on 4/10/20.
//

#ifndef NEWINTERPOLATION_INTERPOLATION_H
#define NEWINTERPOLATION_INTERPOLATION_H

#include <vector>

class Interpolation {
public:
    Interpolation();

    void Coeff(std::vector<float> xs, std::vector<float> ys, std::vector<float> &cs, int n);

    float EvalNewton(std::vector<float> xs, std::vector<float> cs, float z, int n);

};


#endif //NEWINTERPOLATION_INTERPOLATION_H
