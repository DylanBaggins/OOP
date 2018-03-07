#include "calcValues.h"

void calcValues::calcMean(int size, float *col, float &mean)
{
	for (int i = 0; i < size; i++)
	{
		mean += col[i];
	}
	mean = mean / size;
}

void calcValues::calcMedian(int size, float *col, float &median)
{
	float tmpSize;
	median = 0;
	size = size + 1;
	if (size % 2 == 0)
	{
		size /= 2;
		median = col[size];
	}
	else
	{
		tmpSize = size;
		tmpSize /= 2;
		tmpSize -= 0.5f;
		size = tmpSize;
		median = ((col[size] + col[size + 1]) / 2);
	}
}

void calcValues::calcSigma(float* values, float &mean, float &sig)
{
	const int arraySize = 13;

	float diffMean[arraySize] = {};
	float Tmp = 0;
	float sigma = 1.5;
	float size = 0;
	for (int i = 0; i < arraySize; i++)
	{
		diffMean[i] = (values[i] - mean);
		diffMean[i] = pow(diffMean[i], 2);
	}
	calcMean(arraySize, diffMean, Tmp);
	Tmp = sqrt(Tmp);
	for (int i = 0; i < arraySize; i++)
	{
		if (values[i] >= (mean - (sigma*Tmp)) && values[i] <= (mean + (sigma*tmp)))
		{
			sig += values[i];
			size += 1;
		}
	}
	sig = sig / size;
}
