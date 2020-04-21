#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <chrono>
#include "Interpolation.h"

using namespace std;
using namespace std::chrono;

void readFile(string fileName, int &n, vector<float> &xs, vector<float> &ys) {
    fstream myFile;
    myFile.open(fileName);
    if(!myFile) {
        cout << "Error Opening File" << endl;
    }

    while(myFile.peek() != '\n') {
        float temp;
        myFile >> temp;
        xs.push_back(temp);
        n++;
    }
    ys.resize(n);

    for (int i = 0; i < n; ++i) {
        myFile >> ys[i];
    }
}

int main1(int argc, char* argv[]) {
    int n = 0;
    float evalu;
    Interpolation it;
    string fileName = argv[1];
    vector<float> xs;
    vector<float> ys;

    readFile(fileName, n, xs, ys);
    vector<float> cs(n);

    auto start = high_resolution_clock::now();

    it.Coeff(xs, ys, cs, n);

    auto stop = high_resolution_clock::now();

    auto duration = duration_cast<microseconds>(stop - start);

    cout << "Enter value to evaluate polynomial: " << endl;
    while(cin >> evalu) {
        auto start2 = high_resolution_clock::now();

        float result = it.EvalNewton(xs, cs, evalu, n);

        auto stop2 = high_resolution_clock::now();

        auto duration2 = duration_cast<microseconds>(stop2 - start2);

        cout <<"f(" << evalu << ") = " << setprecision(32) << result << endl << endl;
        cout << "Time taken to interpolate: " << duration.count() << " microseconds" << endl;
        cout << "Time taken to evaluate: " << duration2.count() << " microseconds" << endl;
        cout << "Total Time: "  << duration2.count() + duration.count() << " microseconds" << endl;
    }
    return 0;
}
