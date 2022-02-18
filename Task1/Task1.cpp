#include <iostream>
#include <fstream>
using namespace std; 

int main(int argc, char *argv[]) {
    int n, m, lNum;

    ifstream File(argv[1]); 
    File >> n >> m; 
    lNum = m; 


    if (m == n + 1) cout << 1;
    else {

        if (m > n) cout << 1;
        else cout << 1 << lNum;

        while (lNum != 1) {
            if (lNum > n) lNum = lNum - n;
            else if (lNum == n) {

                if (m > n) lNum = m - n - 1;
                else lNum = m - 1;

            } else if (lNum < n) {

                lNum += m - 1;
                if (lNum > n) lNum = lNum - n;

            }

            if (lNum != 1) cout << lNum;
        }

    }

    return 0;
} 