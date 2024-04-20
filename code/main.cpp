#include "mnistheader.h"
#include "imagevectors.h"
#include "kmeans.h"
#include <iostream>
#include "opencv2/opencv.hpp"

using namespace std;
using namespace cv;

int main()
{
    // location to dataset
    string HOME_DIR = "../mnistdataset/";
    string train_image = HOME_DIR + "train-images-idx3-ubyte";
    string train_label = HOME_DIR + "train-labels-idx1-ubyte";
    string test_image = HOME_DIR + "t10k-images-idx3-ubyte";
    string test_label = HOME_DIR + "t10k-labels-idx1-ubyte";


    MNIST callMnist(train_image, train_label, test_image, test_label);
    callMnist.run();
    // reading test and train data
    vector<Image> train = callMnist.returnTrain();
    vector<Image> test = callMnist.returnTest();

 	//creating flat vectors
    vector<ImageVectors> imagevectors;
    for (int i = 0; i < 10000; i++)
    {
        Mat flat = train[i].image.reshape(1, 1);
        flat.convertTo(flat, CV_64F);
        ImageVectors callFlat(flat, train[i].label);
        callFlat.setId(i);
        imagevectors.push_back(callFlat);
    }

    //performing kmeans
    Kmeans callKmeans(10);
    callKmeans.run(imagevectors);
    callKmeans.output();

    return 0;
}