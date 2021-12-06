#include "kmeans.h"
Kmeans ::Kmeans(int K)
{
    n_clusters = K;

}
double Kmeans ::computeDistance(vector<double> point_a, vector<double> point_b)
{

    double sum = 0;
    //computing eucledian distance
    for (int i = 0; i < point_a.size(); i++)
    {

        sum += ((point_a[i] - point_b[i]) * (point_a[i] - point_b[i]));
    }
    return sqrt(sum);
}

vector<double> Kmeans ::Sum(vector<double> point_a, vector<double> point_b)
{
	// to add two vectors
    for (int i = 0; i < point_a.size(); i++)
    {
        point_a[i] += point_b[i];
    }
    return point_a;
}

void Kmeans ::computeCentroids()
{
	//setting centroid
    for (int i = 0; i < clusters.size(); i++)
    {
        vector<double> tempCentroid(clusters[i].returnCentroid().size(), 0.0);
        for (int j = 0; j < clusters[i].returnSize(); j++)
        {
            tempCentroid = Sum(tempCentroid, clusters[i].getPoint(j));
        }
        for (int j = 0; j < tempCentroid.size(); j++)
        {
            tempCentroid[j] = tempCentroid[j] / clusters[i].returnSize();
        }

        clusters[i].setCentroid(tempCentroid);
    }
}

int Kmeans ::getNearestClusterId(ImageVectors vector)
{

    double minDistance = __DBL_MAX__;
    double distance;
    int clusterId;
    for (int i = 0; i < clusters.size(); i++)
    {

        distance = computeDistance(vector.returnPoints(), clusters[i].returnCentroid());

        if (distance <= minDistance)
        {
            minDistance = distance;
            clusterId = clusters[i].returnId();
        }
    };

    return clusterId;
}

void Kmeans::run(vector<ImageVectors> &all_vectors)
{
    n_points = all_vectors.size();
    //initializing clusters
    vector<int> usedVectorIds;
    for (int i = 0; i < n_clusters; i++)
    {
        while (true)
        {
            int index = rand() % n_points;
            if (find(usedVectorIds.begin(), usedVectorIds.end(), index) == usedVectorIds.end())
            {
                usedVectorIds.push_back(index);
                Clusters tempCluster(i, all_vectors[index].returnPoints());
                clusters.push_back(tempCluster);
                break;
            }
        }
    }

    cout << "performing kmeans(100 iterations)..." << endl;

    for (int i = 0; i < 100; i++)
    {
        for (int j = 0; j < n_points; j++)
        {
            int currentClusterId = all_vectors[j].returnClusterId();
            int nearestClusterId = getNearestClusterId(all_vectors[j]);
            if (currentClusterId != nearestClusterId)
            {

                for (int k = 0; k < n_clusters; k++)
                {
                    if (clusters[k].returnId() == currentClusterId)
                    {
                        clusters[k].remove(all_vectors[j].returnId());
                    }
                }

                for (int k = 0; k < n_clusters; k++)
                {
                    if (clusters[k].returnId() == nearestClusterId)
                    {
                        clusters[k].add(all_vectors[j]);
                    }
                }

                all_vectors[j].setClusterId(nearestClusterId);
            }
        }

        computeCentroids();
    }
}

void Kmeans ::output()
{

    vector<map<string, int>> countTable = mapCluster();
    map<int, int> clusterIdToImageLabelMap;
    for (int i = 0; i < countTable.size(); i++)
    {
        cout << "Cluster:" << clusters[i].returnId() << endl;
        cout << "Numbers count = " << endl;
        int maxImageLabel = -99;
        int maxCount = 0;
        for (auto itr = countTable[i].begin(); itr != countTable[i].end(); ++itr)
        {
            cout << itr->first
                 <<"="<< itr->second<<", ";
            if (itr->second > maxCount)
            {
                maxCount = itr->second;
                maxImageLabel = stoi(itr->first);
            }
        }
        clusterIdToImageLabelMap.insert({clusters[i].returnId(), maxImageLabel});
        cout << endl;
    }
    // calculating accuracy
    vector<int>predictions;
    vector<int> imageLabels;
    for(int i=0;i<clusters.size();i++){
        for (int j = 0; j < clusters[i].returnSize(); j++){
            int label = stoi(clusters[i].returnLabel(j));
            int prediction = clusterIdToImageLabelMap[clusters[i].returnId()];
            predictions.push_back(prediction);
            imageLabels.push_back(label);
        }
    }

    cout<<"Accuracy = " << accuracy(predictions,imageLabels)<< "%"<<endl;
}

vector<map<string, int>> Kmeans ::mapCluster()
{
    vector<map<string, int>> countTable;
    for (int i = 0; i < n_clusters; i++)
    {
        map<string, int> LabelCount;
        for (int j = 0; j < clusters[i].returnSize(); j++)
        {
            string label = clusters[i].returnLabel(j);
            if (LabelCount.find(label) != LabelCount.end())
            {
                LabelCount[label]++;
            }
            else
            {
                LabelCount.insert({label, 1});
            }
        }
        countTable.push_back(LabelCount);
    }
    return countTable;
}

float Kmeans ::accuracy(vector<int> predictions, vector<int> labels)
{
    int count = 0;
    for (int i = 0; i < predictions.size(); i++)
    {
        if (predictions[i] == labels[i])
            count++;
    }
    return ((100*count) / predictions.size());
}

