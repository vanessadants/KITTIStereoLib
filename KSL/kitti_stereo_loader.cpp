#include "kitti_stereo_loader.h"

using namespace cv;
using namespace std;

KITTIStereoLoader::KITTIStereoLoader(){

}
void KITTIStereoLoader::loaderImage(string left_path, string right_path){
	leftImage=imread(left_path);
	rightImage=imread(right_path);
 	


}
void KITTIStereoLoader::loaderImageSequence(string sequence_path,int sequence_num){
	 char file_number[21];
	 char sequence_number[21];
	 std::string image_number;
	 s_path=sequence_path;
	 
		
		for(int j=0;j<10000;j++){
		sprintf(file_number, "%06d", j);
		sprintf(sequence_number, "%02d", sequence_num);
		
		//std::cout<<sequence_path+"dataset/sequences/"+std::string(sequence_number)+"/image_0/" + std::string(file_number) + ".png"<<std::endl;
		Mat leftImage_ = imread(sequence_path+"dataset/sequences/"+std::string(sequence_number)+"/image_0/" + std::string(file_number) + ".png");
		if(!leftImage_.data){
			break;
		}
  		image_number=std::string(sequence_number)+std::string(file_number);
		leftImageNameList.push_back(image_number);
		rightImageNameList.push_back(image_number);

 		}
	
}

/*
void KITTISeteroLoader::loaderLidarCloud(string lidar_path){

}
void KITTISeteroLoader::loaderLidarCloudSequence(string lidar_path, sequence_num){

}
*/
 Mat KITTIStereoLoader::getLeftImage(){
 	return leftImage;
 }
 
 Mat KITTIStereoLoader::getRightImage(){
 	return rightImage;
 }
 
 Mat KITTIStereoLoader::getNextLeftSequence(){
 	std::string path = s_path+"dataset/sequences/"+leftImageNameList[nextL].substr(0,2)+"/image_0/"+leftImageNameList[nextL].substr(2,6)+".png";
 	cout<<path<<endl;
 	Mat leftImageS = imread(path,CV_LOAD_IMAGE_UNCHANGED);
 	nextL++;
 	return leftImageS;
 }
 

 Mat KITTIStereoLoader::getNextRightSequence(){
 	std::string path = s_path+"dataset/sequences/"+rightImageNameList[nextR].substr(0,2)+"/image_1/"+rightImageNameList[nextR].substr(2,6)+".png";
 	Mat rightImageS = imread(path,CV_LOAD_IMAGE_UNCHANGED);
 	nextR++;
 	return rightImageS;
 }
KITTIStereoLoader::~KITTIStereoLoader(){


}






