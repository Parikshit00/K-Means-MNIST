#ifndef KMEANS_H
#define KMEANS_H
#include "clusters.h"
#include "imagevectors.h"
#include "opencv2/opencv.hpp"

using namespace std;
using namespace cv;

class Kmeans{
private:
	vector<Clusters> clusters;
  int n_clusters, n_points;
 	void computeCentroids();
  double computeDistance(vector<double> point_a , vector<double>point_b);
  vector<double> Sum(vector<double> point_a, vector<double> point_b);
  int getNearestClusterId(ImageVectors vector);
  vector<map<string,int> > mapCluster();
  float accuracy(vector<int> predictions, vector<int>labels);

public:
  public:
  Kmeans(int K);
  void run(vector<ImageVectors> &all_vectors);
  void output();

};

#endif