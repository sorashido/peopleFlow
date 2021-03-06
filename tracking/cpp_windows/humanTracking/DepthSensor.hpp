#pragma once

#include <opencv2\core\core.hpp>
#include "pxcsensemanager.h"

const int DEPTH_HEIGHT = 240;
const int DEPTH_WIDTH = 320;

typedef struct {
	double x;
	double y;
	double z;
}Point3D;

class DepthSensor {
public:
	DepthSensor(const wchar_t* filename);// { init(filename); }	
	~DepthSensor();
	//void getFrame(int frame, cv::Mat* depthMat, PXCPoint3DF32 *vertices);
	int nframes;
	void frameRelease();

	void getFrame(int frame, cv::Mat * depthMat, PXCPoint3DF32 *vertices);

	//void cameraToWorld(PXCPoint3DF32 *camera, PXCPoint3DF32 *world);
	void cameraToWorldPoint(Point3D *camera, Point3D *world);
	void worldToCameraPoint(Point3D * world, Point3D * local);
	//void cameraToWorldPoint(PXCPoint3DF32 * camera, PXCPoint3DF32 * world);
private:
	void ConvertPXCImageToOpenCVMat(PXCImage *inImg, cv::Mat *outImg);
};