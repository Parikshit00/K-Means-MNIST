#ifndef IMAGEVECTORS_H
#define IMAGEVECTORS_H

#include <iostream>
#include "opencv2/opencv.hpp"

using namespace std;
using namespace cv;

class ImageVectors
{
private:
	int vecId, clusterId;
	string Label;
	vector<double> values;

public:
	ImageVectors(Mat flattened, string labels);
	vector<double> returnPoints();
	string returnLabel();
	int returnId();
	int returnClusterId();
	void setClusterId(int val);
	void setId(int val);
	double returnVal(int pos);
};

#endif