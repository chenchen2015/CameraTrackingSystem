#include "CamMatrix.h"

cameraMatrix::cameraMatrix()
{
	numOfViews = 2;
	camMatrix = new CamMatrixXV[numOfViews];

	camMatrix[0] << 2252.96101573020, 0.0, 0.0,
		0.0, 1870.66489933229, 0.0,
		534.866659707105, 803.932066715002, 1.0000,
		0, 0, 0;

	camMatrix[1] << 623.745637198259, -546.685240671789, -0.634762728031709,
		-162.033780856155, 1850.86475470962, 0.0129411181628372,
		2852.31684862298, 899.455589640930, 0.772598735801735,
		-4096144.90909403, 208348.130376731, 616.676581224207;
}

cameraMatrix::~cameraMatrix()
{
	delete camMatrix;
}

MatrixX3d cameraMatrix::Triangulate()
{
	MatrixX2d MatchedPairs(33 * 2, 2);
	MatchedPairs << 1743.0, 859.0,
		82.0, 905.0,
		1665.0, 852.0,
		165.0, 908.0,
		1593.0, 846.0,
		249.0, 912.0,
		1751.0, 842.0,
		410.0, 911.0,
		1833.0, 841.0,
		488.0, 910.0,
		1915.0, 839.0,
		566.0, 909.0,
		1964.0, 842.0,
		611.0, 912.0,
		1833.0, 37.0,
		630.0, 916.0,
		1759.0, 832.0,
		688.0, 918.0,
		1761.0, 892.0,
		690.0, 981.0,
		1761.0, 698.0,
		681.0, 781.0,
		1838.0, 698.0,
		750.0, 778.0,
		1666.0, 704.0,
		154.0, 769.0,
		1594.0, 702.0,
		238.0, 777.0,
		1671.0, 773.0,
		325.0, 843.0,
		1746.0, 898.0,
		83.0, 941.0,
		1747.0, 936.0,
		84.0, 976.0,
		1753.0, 1011.0,
		86.0, 1047.0,
		1750.0, 973.0,
		86.0, 1012.0,
		1757.0, 1048.0,
		84.0, 1083.0,
		1761.0, 1086.0,
		83.0, 1118.0,
		1744.0, 743.0,
		74.0, 797.0,
		1788.0, 858.0,
		120.0, 904.0,
		1831.0, 857.0,
		161.0, 904.0,
		1875.0, 856.0,
		202.0, 903.0,
		1918.0, 855.0,
		244.0, 903.0,
		1961.0, 854.0,
		288.0, 903.0,
		2005.0, 854.0,
		331.0, 902.0,
		1701.0, 860.0,
		47.0, 905.0,
		1658.0, 861.0,
		13.0, 906.0,
		1704.0, 856.0,
		123.0, 906.0,
		1666.0, 853.0,
		165.0, 908.0,
		1629.0, 849.0,
		207.0, 910.0;

	MatrixX3d point3D (MatchedPairs.rows() >> 1, 3);
	for (int i = 0; i < point3D.rows(); i++)
	{
		point3D.row(i) = Triangulate_OnePoint(MatchedPairs.middleRows(i * 2, 2));
	}
	//cout << "\nPoints3D:\n\n" << point3D << endl;
	return point3D;
}

Vector3d cameraMatrix::Triangulate_OnePoint(MatrixX2d MatchedPts)
{
	Matrix4d Matrix_A;
	Matrix4d Matrix_V;
	Vector4d Vector_X;
	CamMatrixTr Matrix_P;
	for (int i = 0; i < numOfViews; i++)
	{
		Matrix_P = camMatrix[i].transpose();

		//cout << "\ncamMatrix[i].transpose ():\n\n" << camMatrix [ i ].transpose () << endl;
		//cout << "\nMatrix_P:\n\n" << Matrix_P << endl;

		Matrix_A.row(2 * i) = MatchedPts(i, 0) * Matrix_P.row(2) - Matrix_P.row(0);
		Matrix_A.row(2 * i + 1) = MatchedPts(i, 1) * Matrix_P.row(2) - Matrix_P.row(1);

		//cout << "\nMatrix_A.row ( 2 * i ):\n\n" << Matrix_A.row ( 2 * i ) << endl;
		//cout << "\nMatrix_A.row ( 2 * i + 1 ):\n\n" << Matrix_A.row ( 2 * i + 1 ) << endl;
	}

	JacobiSVD<Matrix4d> svd(Matrix_A, ComputeFullV);
	Matrix_V = svd.matrixV();

	Vector_X = Matrix_V.col(3);

	// Verified! 
	// Matching with MATLAB
	//cout << "\nMatrix_A:\n\n" << Matrix_A << endl;
	//cout << "\nMatrix_V:\n\n" << Matrix_V << endl;
	//cout << "\nVector_X:\n\n" << Vector_X << endl;

	Vector_X = Vector_X / Vector_X(3);

	return Vector_X.head(3);
}