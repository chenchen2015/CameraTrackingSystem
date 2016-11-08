#ifndef CAMERA_MATRIX

#define CAMERA_MATRIX

#include <vector>
using namespace std;

#include <iostream>
#include <Eigen/Dense>
#include <Eigen/Eigen>
using namespace Eigen;

typedef Matrix<double, 4, 3, 0, 4, 3> camMatrixXV;
typedef Matrix<double, 3, 4, 0, 3, 4> camMatrixTr; // Transposed Camera Matrix 3x4
typedef Matrix<double, -1, -1, 0, -1, -1> MatrixXXd;

class cameraMatrix{
private:
	camMatrixXV* camMatrix;
	MatrixX2d* inputPtPairs;

public:
	int numOfViews;

#pragma region Default_Constructor
public:
	cameraMatrix ( vector<double> matrixEntry, int numViews );
	cameraMatrix (); // For 2 View Demo
#pragma endregion

#pragma region Default_DeConstructor
public:
	~cameraMatrix ();
#pragma endregion

public:
	MatrixX3d Triangulate ();
	MatrixX3d Reproject( MatrixX3d x1 );

protected:
	Vector3d Triangulate_OnePt ( Matrix2d matchedPts );

private:
	// Supporting Functions for Reproject
	Matrix3Xd mapminmax_apply( Matrix3Xd x, Vector3d settings_gain, Vector3d settings_xoffset, double settings_ymin );
	Matrix3Xd mapminmax_reverse( Matrix3Xd x, Vector3d settings_gain, Vector3d settings_xoffset, double settings_ymin );
	MatrixXXd tansig_apply( MatrixXXd n );
private:
	void catInputPts ( MatrixX2d inputPt1, MatrixX2d inputPt2 );
	void catInputPts ( MatrixX2d inputPt1, MatrixX2d inputPt2, MatrixX2d inputPt3 );
	void catInputPts ( MatrixX2d inputPt1, MatrixX2d inputPt2, MatrixX2d inputPt3, MatrixX2d inputPt4 );

public:
	EIGEN_MAKE_ALIGNED_OPERATOR_NEW
};

#endif