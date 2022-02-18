#include <iostream> 
#include <fstream> 
#include <cmath> 

using namespace std;

int main(int argc, char* argv[]) {
    float X, Y, numX, numY, r;

    ifstream File1(argv[1]);
    ifstream File2(argv[2]);

    File1 >> X >> Y >> r;
    while (File2) {
        File2 >> numX >> numY;
        numX -= X; numY -= Y;
        if (pow(numX, 2) + pow(numY, 2) == pow(r, 2)) cout << 0; //лежит на окружности
        if (pow(numX, 2) + pow(numY, 2) < pow(r, 2)) cout << 1; //лежит внутри окружности 
        if (pow(numX, 2) + pow(numY, 2) > pow(r, 2)) cout << 2; //лежит снаружи окружности 
        cout << endl;
        if (File2.eof()) break;
    }

    return 0;
}