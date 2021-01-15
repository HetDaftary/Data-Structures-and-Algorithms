#include <iostream>
#include <vector>
using namespace std;

double power(double x, int n) {
    int nTemp = n;
    double ans = 1;
    bool toInvert;

    if (n == 0) return 1;
    
    if (n < 0) { 
    	n *= -1;
    	toInvert = true;
    }

    vector<bool> toGetData;
    while (nTemp) {
        toGetData.push_back((bool)(nTemp % 2));
        nTemp /= 2;
    } 

    for (int i = toGetData.size() - 1; i > - 1; i--) {
        if (toGetData[i]) ans = ans * ans * x;
        else ans = ans * ans;   
    }

    return toInvert?(1/ans):(ans);
}
