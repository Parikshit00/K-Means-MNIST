#ifndef CLUSTERS_H
#define CLUSTERS_H
#include <iostream>
#include "opencv4/opencv2/opencv.hpp"
#include "imagevectors.h"

using namespace std;
using namespace cv;

class Clusters{
    private:
        int cluster_id;
        vector<double> cen;
        vector<ImageVectors> imageVectors;


    public:
        Clusters(int clusterId,vector<double> centroid);
        void add(ImageVectors data);
        bool remove(int vectorId);
        int returnId();
        int returnSize();
        double getCentroidByPos(int pos);
        void setCentroidByPos(int pos, double val);
        void setCentroid(vector<double> centroid);
        vector<double> returnCentroid();
        string returnLabel(int pos);
        vector<double> getPoint(int pos);
};
#endif
