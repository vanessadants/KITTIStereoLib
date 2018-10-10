#ifndef KITTISTEREOLOADER_H
#define KITTISTEREOLOADER_H

#include "opencv2/calib3d.hpp"
#include "opencv2/imgproc.hpp"
#include "opencv2/imgcodecs.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/core/utility.hpp"
#include <iostream>
#include <fstream>
#include <string>

using namespace cv;
using namespace std;


class KITTIStereoLoader
{
private:
	Mat leftImage;
	Mat rightImage;
	std::string s_path;
	int nextL=0;
 	int nextR=0;
	std::vector<std::string> leftImageNameList;
	std::vector<std::string> rightImageNameList; //Lista de strings >> Imitar codigo git
    
public:
	KITTIStereoLoader();
	void loaderImage(string left_path,string right_path);
	void loaderImageSequence(string sequence_path,int sequence_num);
	//void loaderLidarCloud(string lidar_path);
	//void loaderLidarCloudSequence(string lidar_path,int start_sequence_num,int stop_sequence_num);
    Mat getLeftImage();
    Mat getRightImage();
    Mat getNextLeftSequence(); //2 primeiros digitos = numero da sequencia, 6 ultimos digitos = numero da imagem.
    Mat getNextRightSequence();

    ~KITTIStereoLoader();


};

#endif // KITTISTEREOLOADER_H

