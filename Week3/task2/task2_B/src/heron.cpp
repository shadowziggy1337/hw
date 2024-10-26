#include "heron.hpp"
#include <iostream>
#include <cmath>
using namespace std;

double Heron (double number) {
    	double hypo = number;
    	while (true) {
        	double nextHypo = 0.5 * (hypo + number / hypo);
        	if (abs(nextHypo - hypo) < 0.000001)
            		return nextHypo;
        	hypo = nextHypo;
	}
	
}
