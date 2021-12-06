#include "imagevectors.h"

ImageVectors ::ImageVectors(Mat flattened, string labels){
   if (flattened.isContinuous()) values.assign((double *)flattened.datastart, (double *)flattened.dataend);
   else
   {
      for (int i = 0; i < flattened.rows; ++i)
      {
         values.insert(values.end(), (double *)flattened.ptr<uchar>(i), (double *)flattened.ptr<uchar>(i) + flattened.cols);
      }
   }

   Label = labels;
   clusterId = -99;
   vecId = -99;
}

void ImageVectors ::setClusterId(int val)
{
   clusterId = val;
}
void ImageVectors ::setId(int val)
{
   vecId = val;
}
int ImageVectors ::returnClusterId()
{
   return clusterId;
}
int ImageVectors ::returnId()
{
   return vecId;
}
double ImageVectors ::returnVal(int pos)
{
   return values[pos];
}
vector<double> ImageVectors ::returnPoints()
{
   return values;
}
string ImageVectors::returnLabel()
{
   return Label;
}
