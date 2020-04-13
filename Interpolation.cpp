//
// Created by Alejandro Millan on 4/10/20.
//

#include "Interpolation.h"

Interpolation::Interpolation() {}

void Interpolation::Coeff(std::vector<float> xs, std::vector<float> ys, std::vector<float> &cs, int n) {
    for(int i = 0; i < n; i++) {
        cs[i] = ys[i];
    }

    for(int j = 1; j < n; j++) {
        for(int i = n-1; i >= j; i--) {
            cs[i] = (cs[i] - cs[i - 1]) / (xs[i] - xs[i - j]);
        }
    }
}

/*
 * function Coeff(xs : vector(n+1), ys : vector(n+1), cs : vector(n+1))
  for i <- 0 to n
    cs[i] := ys[i]
  end for

  for j <- 1 to n
    for i <- n down to j
      cs[i] := (cs[i] - cs[i-1]) / (xs[i] - x[i-j])
    end for
  end for
end function
 */

float Interpolation::EvalNewton(std::vector<float> xs, std::vector<float> cs, float z, int n) {
    float result = cs[n];

    for(int i = n - 1; i >= 0; i--) {
        result = result * (z - xs[i]) + cs[i];
    }

    return result;
}

/*
 * function EvalNewton(xs : vector(n+1), cs : vector(n+1), z : float)
  result := cs[n]

  for i <- (n-1) down to 0
    result := result * (z - xs[i]) + cs[i]
  end for

  return result
end function
 */