#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include <unordered_set>
#include <random>

using namespace std;

void writeFile(vector<int> xs, vector<int> ys, int n) {

    ofstream outputFile("randomData.txt");
    for(int i = 0; i < n; i++) {
        if(i == n - 1) {
            outputFile << xs[i] << '\n';
        }
        else{
            outputFile << xs[i] << " ";
        }
    }
    for(int i = 0; i < n; i++) {
        outputFile << ys[i] << " ";
    }
}

int main() {
    int n;

    random_device dev;
    mt19937 rng(dev());
    uniform_int_distribution<std::mt19937::result_type> ranNum(-10000,10000);

    cout << "Enter number of n: " << endl;
    cin >> n;
    vector<int> xs(n);
    vector<int> ys(n);

    for(int i = 0; i < n; i++) {
        int randomNum = ranNum(rng);
        while(find(xs.begin(), xs.end(), randomNum) != xs.end()) {
            randomNum = ranNum(rng);
        }
        xs[i] = randomNum;
    }

    for(int i = 0; i < n; i++) {
        ys[i] = ranNum(rng);
    }

    writeFile(xs, ys, n);

    return 0;
}
