# Generated by using Rcpp::compileAttributes() -> do not edit by hand
# Generator token: 10BE3573-1514-4C36-9D1C-5A225CD40393

europeanCallPriceWithBarrier <- function(nInt, strike, spot, barrier, vol, r, expiry, nReps) {
    .Call(`_EuropeanOptionPricer_europeanCallPriceWithBarrier`, nInt, strike, spot, barrier, vol, r, expiry, nReps)
}

