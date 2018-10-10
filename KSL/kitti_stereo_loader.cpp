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
	 std::string image_number;
	 
		
		for(int j=0;j<10000;j++){
		sprintf(file_number, "%06d", j);
		sprintf(sequence_number, "%02d", i);
		
		//std::cout<<sequence_path+"dataset/sequences/"+std::string(sequence_number)+"/image_0/" + std::string(file_number) + ".png"<<std::endl;
		Mat leftImage_ = imread(sequence_path+"dataset/sequences/"+std::string(sequence_number)+"/image_0/" + std::string(file_number) + ".png");
		if(!leftImage_.data){
			j=0;
			i++;
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
 
 std::vector<std::string> KITTIStereoLoader::getLeftSequence(){
 	return leftImageNameList;
 }
 

 std::vector<std::string> KITTIStereoLoader::getRightSequence(){
 	return rightImageNameList;
 }
KITTIStereoLoader::~KITTIStereoLoader(){}






