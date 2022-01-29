#include<vector>

class EuropeanOption{
public:

	//constructor
	EuropeanOption(
		int nInt_,
		double strike_,
		double spot_,
        double barrier_,
		double vol_,
		double r_,
		double expiry_
		);

	//destructor
	~EuropeanOption(){};

	//methods
	void generatePath();
    double europeanCallPriceWithBarrier(int nReps);
	
	//members
	std::vector<double> thisPath;
	int nInt;
	double strike;
	double spot;
    double barrier;
	double vol;
	double r;
	double expiry;
};
