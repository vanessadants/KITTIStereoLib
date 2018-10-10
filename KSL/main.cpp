//export LD_LIBRARY_PATH=/home/ferreira/Downloads/opencv-3.4.1/Build/lib 
#include <iostream>
#include <opencv2/opencv.hpp>
#include "kitti_stereo_loader.h"

using namespace std;
using namespace cv;


int main()
{
  KITTIStereoLoader l;
  string path = "/home/ferreira/Documentos/KITTIStereoLib/KSL/";
  vector<string> list;
  
  l.loaderImageSequence(path,0,1);
  list=l.getLeftSequence();
  int size=list.size();
  for(int i=0;i<size;i++)
    cout<<list[i]<<endl;
  
    return 0;
}

