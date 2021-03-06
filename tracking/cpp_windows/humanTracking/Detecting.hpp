#ifndef _Detect_
#define _Detect_

#include <opencv2/core/core.hpp>
#include "DepthSensor.hpp"

// parameter
namespace labelParam {
	const int INIT = 10000;
	
	const int MIN_SIZE = 25;
	const int MAX_SIZE = 204800;
	const int MIN_WIDTH = 0;
	const int MAX_WIDTH = 3000;
	const int MIN_HEIGHT = 0;
	const int MAX_HEIGHT = 3000;

	const double RELATION_RATE = 0.1;

	const int SERCH_NUM = 8;
	const char X[SERCH_NUM] = { -1, 0, 1, -1, 1, -1, 0, 1};
	const char Y[SERCH_NUM] = { -1, -1, -1, 0, 0, 1, 1, 1};
}

typedef struct {
	double sx;	// screen
	double sy;
	double sz;
	double wx;	// world
	double wy;
	double wz;
	double width;
	double height;
	int num;
	int frame;
	int id;
}detection;

using namespace labelParam;

class Detect{
public:
	typedef struct{
		double sx;	//screen
		double sy;
		double sd;
		double cx;  //camera
		double cy;
		double cz;
		double width;
		double height;
		double size;
		int id;
	}labelInf;

	std::vector<labelInf> results;//Detect
	//std::set<int>isId;
	void detectPeople(DepthSensor* sensor, int frame, cv::Mat depth, PXCPoint3DF32* vertices, std::vector<detection>* people);//
	//void drawResult(const std::string&winname);
private:
	int id;
	cv::Mat table;	//

	typedef struct {
		short x;
		short y;
	}Buf;//pointバッファー

	//get method
	int getNotLabelDepth(cv::Mat depth, cv::Mat table, int x, int y){
		if (table.at<short>(y, x) == INIT)return depth.at<short>(y, x);
		return 0;
	}
	labelInf getlabelInf(double x, double y, double z, double cx, double cy, double cz, double width, double height, double size,int id){
		labelInf tmp = { x, y, z, cx, cy, cz, width, height, size, id};
		return tmp;
	}
	Buf getBufInf(short x, short y) {
		Buf tmp = {x,y};
		return tmp;
	}
};

#endif