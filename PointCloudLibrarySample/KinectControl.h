#pragma once

#include <iostream>
#include <sstream>

#include <Windows.h>
#include <NuiApi.h>

#include <opencv2/opencv.hpp>
//#include <flann/flann.hpp>
#include <opencv2/flann/flann.hpp>

#include <pcl\point_types.h>
#include <pcl\visualization\cloud_viewer.h>

#include <pcl\filters\statistical_outlier_removal.h>  //フィルター用追加分

#define ERROR_CHECK(ret)                                            \
  if(ret != S_OK) {                                               \
  std::stringstream ss;                                           \
  ss << "failed " #ret " " << std::hex << ret << std::endl;       \
  throw std::runtime_error(ss.str().c_str());                     \
    }

const NUI_IMAGE_RESOLUTION CAMERA_RESOLUTION = NUI_IMAGE_RESOLUTION_640x480;

class KinectControl
{
public:
	KinectControl(void);
	~KinectControl(void);

	void initialize();
	void run();

private:
	INuiSensor *kinect;
	HANDLE imageStreamHandle;
	HANDLE depthStreamHandle;
	HANDLE streamEvent;

	DWORD width;
	DWORD height;

	void createInstance();
	void setRgbImage(cv::Mat &image);
	void setDepthImage(cv::Mat &image);

	cv::Mat rgbImage;
	cv::Mat depthImage;
	//pcl::PointCloud<pcl::PointXYZRGBA>::Ptr cloud;
	pcl::PointCloud<pcl::PointXYZ>::Ptr cloud;
	pcl::visualization::CloudViewer *viewer;


	//pcl::PointCloud<pcl::PointXYZ>::Ptr cf;
	//pcl::visualization::CloudViewer *viewer_filtered;
};