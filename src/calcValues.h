#pragma once
#include <cmath>

class calcValues
{
public:
	void calcMean(int size, float *col, float &mean);
	void calcMedian(int size, float *col, float &median);
	void calcSigma(float* values, float &mean, float &sig);
};

