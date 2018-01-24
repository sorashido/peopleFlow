#ifndef _LABELING_
#define _LABELING_

#include <opencv2/core/core.hpp>

// parameter
namespace labelParam {
	const int INIT = 1000;
	const int SERCH_NUM = 8;

	const int MIN_SIZE = 50;
	const int MAX_SIZE = 204800;
	const int MIN_WIDTH = 0;
	const int MAX_WIDTH = 6000;
	const int MIN_HEIGHT = 0;
	const int MAX_HEIGHT = 6000;

	const int RELATION_DEPTH = 50;

	//const char X_4[SERCH_NUM] = { -1, 1, 0, 0 };
	//const char Y_4[SERCH_NUM] = { 0, 0, -1, 1 };
	const char X[SERCH_NUM] = { -1, 0, 1, -1, 1, -1, 0, 1};
	const char Y[SERCH_NUM] = { -1, -1, -1, 0, 0, 1, 1, 1};

	//const char X[SERCH_NUM] = { -1, 0, 1, -1, 1, -1, 0, 1, -2, -1, 0, 1, 2, -2, 2, -2, 2, -2, 2, -2, -1, 0, 1, 2};
	//const char Y[SERCH_NUM] = { -1, -1, -1, 0, 0, 1, 1, 1, -2, -2, -2, -2, -2, -1, -1, 0, 0, 1, 1, 2, 2, 2, 2, 2};
}

using namespace labelParam;

class Labeling{
public:
	typedef struct{
		double x;	//x average
		double y;	//y average
		double d;	//depth
		double width; //width
		double height; //height
		double size;   //size
		int id;		   //id
	}labelInf;

	std::vector<labelInf> results;//ラベリングの結果詳細
	cv::Mat table;	//ラベリング結果のテーブル
	std::set<int>isId;

	void labeling(cv::Mat depth, int step);//ラベリング
	//void drawResult(const std::string&winname);//描画

private:
	int id;//ラベリングの数

	typedef struct {
		short x;
		short y;
	}Buf;//pointバッファー

	//取得メソッド
	int getNotLabelDepth(cv::Mat depth, cv::Mat table, int x, int y){
		if (table.at<short>(y, x) == INIT)return depth.at<short>(y, x);
		return 0;
	}
	//代入メソッド
	labelInf getlabelInf(double x, double y, double z, double width, double height, double size,int id){
		labelInf tmp = { x, y, z, width, height, size, id};
		return tmp;
	}
	Buf getBufInf(short x, short y) {
		Buf tmp = {x,y};
		return tmp;
	}
};

#endif