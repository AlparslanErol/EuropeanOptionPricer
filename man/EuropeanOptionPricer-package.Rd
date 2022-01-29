\name{EuropeanOptionPricer-package}
\alias{EuropeanOptionPricer-package}
\alias{EuropeanOptionPricer}
\docType{package}
\title{
  European style down-and-out call option price calculation.
}
\description{
  R package for calculating European style down-and-out call option with a 
  barrier active between the moment of pricing and the option expiry.
}
\details{
  ## Import Package from Github
    library(devtools)
    
    install_github("AlparslanErol/EuropeanOptionPricer")
    
    library(EuropeanOptionPricer)

  ## Import Package from binaries (no need to rebuild)
    install.packages("progs/EuropeanOptionPricer_1.0.zip",
                     type = "binaries",
                     repos = NULL,
                     dependenciew=TRUE)
                     
    library(EuropeanOptionPricer)
    
  ## Call the function from the package
    EuropeanOptionPricer::europeanCallPriceWithBarrier(126, 100, 105, 99, 0.22, 0.05, 0.5, 10000)
}
\author{
Alparslan Erol, alparslann.erol@gmail.com

Maintainer: Alparslan Erol <alparslann.erol@gmail.com>
}
\references{
  UW Data Science and Business Analytics master's degree Applied Finance course
  class material from Prof.Pawel Sakowski
}
\keyword{ package }
\seealso{
  https://github.com/pawelsakowski/AF-RCPP-2021-2022
}
\examples{
  \dontrun{
     library(devtools)
     install_github("AlparslanErol/EuropenOptionPricer") 
     EuropenOptionPricer::europeanCallPriceWithBarrier(126, 100, 105, 99, 0.22, 0.05, 0.5, 10000)
  }
}
