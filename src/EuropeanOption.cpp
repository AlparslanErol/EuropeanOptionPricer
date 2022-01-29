#include<iostream>
#include<cmath>
#include <algorithm>
#include"getOneGaussianByBoxMueller.h"
#include"EuropeanOption.h"


//definition of constructor
EuropeanOption::EuropeanOption(
	int nInt_,
	double strike_,
	double spot_,
    double barrier_,
	double vol_,
	double r_,
	double expiry_){
		nInt = nInt_;
		strike = strike_;
		spot = spot_;
        barrier = barrier_;
		vol = vol_;
		r = r_;
		expiry = expiry_;
		generatePath();
}

//method definition
void EuropeanOption::generatePath(){
	double thisDrift = (r * expiry - 0.5 * vol * vol * expiry) / double(nInt);
	double cumShocks = 0;
	thisPath.clear();

	for(int i = 0; i < nInt; i++){
		cumShocks += (thisDrift + vol * sqrt(expiry / double(nInt)) * getOneGaussianByBoxMueller());
		thisPath.push_back(spot * exp(cumShocks));
	}
}

//European style down-and-out call option with a barrier active between the moment of pricing and the option expiry
double EuropeanOption::europeanCallPriceWithBarrier(int nReps){
	double rollingSum = 0.0;
    double lastPrice = 0.0;
    double minVector = 0.0;

	for(int i = 0; i < nReps; i++){
		generatePath();
        minVector = *min_element(thisPath.begin(), thisPath.end());
        if (minVector >= barrier){
            lastPrice = thisPath.back();
            rollingSum += (lastPrice > strike) ? (lastPrice - strike) : 0;
        }
	}
	return exp(-r*expiry)*rollingSum/double(nReps);
}