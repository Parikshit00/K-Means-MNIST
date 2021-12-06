#include "clusters.h"

Clusters ::Clusters(int clusterId, vector<double> centroid)
{
    cluster_id = clusterId;
    cen = centroid;
}

void Clusters ::setCentroidByPos(int pos, double val)
{
    cen[pos] = val;
}

vector<double> Clusters ::  getPoint(int pos){
    return imageVectors[pos].returnPoints();
}

string Clusters :: returnLabel(int pos){
    return imageVectors[pos].returnLabel();
}

void Clusters ::add(ImageVectors data)
{
    data.setClusterId(cluster_id);
    imageVectors.push_back(data);
}
bool Clusters ::remove(int vectorId)
{
    for (int i = 0; i < imageVectors.size(); i++)
    {
        if (imageVectors[i].returnId() == vectorId)
        {
            imageVectors.erase(imageVectors.begin() + i);
            return true;
        }
    }
    return false;
}
int Clusters ::returnId()
{
    return cluster_id;
}
int Clusters ::returnSize()
{
    return imageVectors.size();
}
double Clusters ::getCentroidByPos(int pos)
{
    return cen[pos];
}

void Clusters ::setCentroid(vector<double> centroid)
{
    cen = centroid;
}
vector<double> Clusters ::returnCentroid()
{
    return cen;
}

