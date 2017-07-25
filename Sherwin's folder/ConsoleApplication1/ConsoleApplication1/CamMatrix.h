#ifndef CamMatrix

#define CamMatrix

#include <vector>
#include <iostream>
#include <Eigen/Dense>
#include <Eigen/Eigen>

using namespace std;
using namespace Eigen;

typedef Matrix<double, 4, 3, 0, 4, 3> CamMatrixXV;
typedef Matrix<double, 3, 4, 0, 3, 4> CamMatrixTr;

class cameraMatrix
{
private:
	MatrixX2d MatchedPairs;
	CamMatrixXV* camMatrix;

public:
	int numOfViews;
	cameraMatrix();
	~cameraMatrix();
	MatrixX3d Triangulate();
	Vector3d Triangulate_OnePoint(MatrixX2d MatchedPts);

};



#endif // !CamMatrix
