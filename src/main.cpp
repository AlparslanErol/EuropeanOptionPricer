#include <Rcpp.h>
#include<iostream>
#include<vector>
#include<ctime>
#include<cstdlib>
#include"EuropeanOption.h"

using std::vector;
using std::cout;
using namespace Rcpp;

// [[Rcpp::export]]
double europeanCallPriceWithBarrier(
    int nInt,
    double strike,
    double spot,
    double barrier,
    double vol,
    double r,
    double expiry,
    int nReps){  
  
  // set the seed
  srand( time(NULL) );
  
  //create a new instance of class
  EuropeanOption myEuropean(nInt, strike, spot, barrier, vol, r, expiry);
  
  //run Monte Carlo to obtain European Call Price with Barrier option.
  return myEuropean.europeanCallPriceWithBarrier(nReps);
}