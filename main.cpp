#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include "Interpolation.h"

using namespace std;

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

int main() {
    int n = 0;
    float evalu;
    Interpolation it;
    string fileName;
    vector<float> xs;
    vector<float> ys;

    cout << "Enter File Name: " << endl;
    cin >> fileName;

    readFile(fileName, n, xs, ys);
    vector<float> cs(n);
    it.Coeff(xs, ys, cs, n);

    cout << "Enter value to evaluate polynomial: " << endl;
    while(cin >> evalu) {
        float result = it.EvalNewton(xs, cs, evalu, n);
        cout << result << endl;
    }

    return 0;
}
