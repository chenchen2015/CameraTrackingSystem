#include "CameraMatrix.hpp"

cameraMatrix::cameraMatrix( vector<double> matrixEntry, int numViews ) {
	// Verify Input
	this->numOfViews = numViews;
	int numElements = 12 * numViews;

	if ( matrixEntry.size() != numElements )
		return;

	// Initialize Private Members
	camMatrix = new camMatrixXV[numViews];
	inputPtPairs = new MatrixX2d[numOfViews];

	int iterElements = 0;
	for ( int i = 0; i < numOfViews; i++ )
		for ( int j = 0; j < 4; j++ )
			for ( int k = 0; k < 3; k++ ) {
				camMatrix[i]( j, k ) = matrixEntry[iterElements++];
			}
}

cameraMatrix::cameraMatrix() {
	numOfViews = 2;

	// Initialize Private Members
	camMatrix = new camMatrixXV[2];
	inputPtPairs = new MatrixX2d[2];

	// Assign Camera Matrix
	camMatrix[0] << 2252.96101573020, 0.0, 0.0,
		0.0, 1870.66489933229, 0.0,
		534.866659707105, 803.932066715002, 1.0000,
		0, 0, 0;

	camMatrix[1] << 623.745637198259, -546.685240671789, -0.634762728031709,
		-162.033780856155, 1850.86475470962, 0.0129411181628372,
		2852.31684862298, 899.455589640930, 0.772598735801735,
		-4096144.90909403, 208348.130376731, 616.676581224207;
}

cameraMatrix::~cameraMatrix() {
	// De-Allocate memory to prevent memory leak
	delete camMatrix;
	delete inputPtPairs;
}

MatrixX3d cameraMatrix::Triangulate() {
	MatrixX2d matchedPts( 7 * 2, 2 ); // 2*N by 2 Matrix
									  // Format: x11,  y11	  | - Matched points pair #1
									  //         x12,  y12	  ~~~~~~~~~~~~~~~~~~~~~~~~~~
									  //         x21,  y21	  | - Matched points pair #2
									  //         x22,  y22	  ~~~~~~~~~~~~~~~~~~~~~~~~~~
									  //         ...   ...	  ..........................
	matchedPts << 1743.0, 859.0,  // | - Matched points pair #1
		82.0, 905.0,			  // ~~~~~~~~~~~~~~~~~~~~~~~~~~
		1665.0, 852.0,			  // | - Matched points pair #2
		165.0, 908.0,			  // ~~~~~~~~~~~~~~~~~~~~~~~~~~
		1593.0, 846.0,			  // | - Matched points pair #3
		249.0, 912.0,			  // ~~~~~~~~~~~~~~~~~~~~~~~~~~
		1751.0, 842.0,			  // | - Matched points pair #4
		410.0, 911.0,			  // ~~~~~~~~~~~~~~~~~~~~~~~~~~
		1833.0, 841.0,			  // | - Matched points pair #5
		488.0, 910.0,			  // ~~~~~~~~~~~~~~~~~~~~~~~~~~
		1915.0, 839.0,			  // | - Matched points pair #6
		566.0, 909.0,			  // ~~~~~~~~~~~~~~~~~~~~~~~~~~
		1964.0, 842.0,			  // | - Matched points pair #7
		611.0, 912.0;

	MatrixX3d point3D( matchedPts.rows() >> 1, 3 );

	for ( int i = 0; i < matchedPts.rows() >> 1; i++ ) {
		point3D.row( i ) = Triangulate_OnePt( matchedPts.middleRows( i << 1, 2 ) );
	}

	cout << "\nPoints3D:\n\n" << point3D << endl;

	MatrixX3d gantryPt3D( point3D.rows(), 3 );

	//Matrix3Xd gantryPt3D;

	gantryPt3D = Reproject( point3D );

	return gantryPt3D;
}

MatrixX3d cameraMatrix::Reproject( MatrixX3d x1 ) {
	x1 = x1 / 10;  // Change the Unit of x1
	//cout << " x1 is" << endl << x1 << endl;
	
	// ===== NEURAL NETWORK CONSTANTS =====
	// Input 1
	Vector3d x1_step1_xoffset, x1_step1_gain;
	double x1_step1_ymin = -1.0f;

	// Layer 1
	Matrix<double, 10, 1> b1;
	Matrix<double, 10, 3> IW1_1;

	// Layer 2
	Vector3d b2;
	Matrix<double, 3, 10> LW2_1;

	// Output 1
	double y1_step1_ymin = -1.0f;
	Vector3d y1_step1_gain, y1_step1_xoffset;

	// Assign Parameters' Value
	x1_step1_xoffset << 64.901778151504, -8.42209010747119, 130.189970511086;
	x1_step1_gain << 0.0688013705172384, 0.0739789493547617, 0.0762121584900576;
	b1 << -0.84478751913874262, 0.62482150249037582, -0.52602559945415883, 0.68828147510444948, 0.024600675497650798, -0.61150543662932011, 1.313895903284739, -0.813448568495311, 0.48353152862540655, 0.90498531476796162;
	b2 << -0.144840488872127, -0.0614561747222241, 0.0867888925487940;
	IW1_1 << -0.0693775059374704, -0.898235121775880, 0.141430277664874,
		-0.507919663751378, -0.247756823567594, -0.807591548820987,
		0.411856934158734, 1.17101363357360, 0.0621108190725948,
		-0.140658720314116, 0.389867218217533, 0.680401201935144,
		-0.474985401996206, 0.192974772528405, 0.728134838467866,
		0.799505410400201, -0.0938881053618274, -0.242755509709435,
		0.151009494364861, 0.143599900468799, 0.918347954839469,
		-0.285210395188397, 0.747275783134957, 0.749685485657332,
		0.00460007717146710, -0.526688404879907, 0.304056241681414,
		0.888294323570919, -0.0917992029087001, -0.305748002062219;
	LW2_1 << 0.199923352051252, -0.372035688711793, -0.219354459133026, 0.0343504617404127, 0.192897226766938, 0.706831207678236, 0.538999456639056, 0.292301089276802, -0.123530168564321, 0.768370626724965,
		0.655304808299187, -0.709335925135639, -0.447538845512842, 0.480105893632707, 0.00822693786532985, -0.399009670716074, 0.877534246312236, 0.727588309502385, -0.0384329926091908, -0.323787141842497,
		0.587893354358607, -0.0525796610607098, -0.180044112613425, -0.765476390881385, 0.369534113176288, 0.0638993512151596, 0.0352104798223909, -0.539873284397187, 0.750257393621354, 0.0348348453881138;
	y1_step1_gain << 0.0666666666666667, 0.1000, 0.0800;
	y1_step1_xoffset << -5, 10, -35;

	// ===== SIMULATION ========
	// Dimensions
	int Q = x1.rows(); // correct

	//cout << " Q is " << Q << endl;

	// Input 1
	Matrix3Xd xp1( 3, Q );
	xp1 = mapminmax_apply( x1.transpose(), x1_step1_gain, x1_step1_xoffset, x1_step1_ymin );
	//cout << "xp1 is" << endl << xp1 << endl;
	
	// Layer 1
	MatrixXXd a1( 3, Q );
	a1 = tansig_apply( b1.replicate( 1, Q ) + IW1_1*xp1 );
	//cout << "a1 is" << endl << a1 << endl;

	// Layer 2
	Matrix3Xd a2( 3, Q );
	a2 = b2.replicate( 1, Q ) + LW2_1 * a1;
	//cout << "a2 is" << endl << a2 << endl;

	// Output 1
	//Matrix3Xd y1( 3, Q );
	MatrixX3d y1_tr( Q, 3 );
	y1_tr = mapminmax_reverse( a2, y1_step1_gain, y1_step1_xoffset, y1_step1_ymin ).transpose();
	//cout << "y1_tr is" << endl << y1_tr << endl;

	return y1_tr;
}

// CODE BELOW NOT TO BE TOUCHED 
Vector3d cameraMatrix::Triangulate_OnePt( Matrix2d matchedPts ) {
	switch ( numOfViews ) {
	case 2:
		Matrix4d Matrix_A;    // 4x4
		Matrix4d Matrix_V;    // 4x4
		Vector4d Vector_X;    // 4x1
		camMatrixTr Matrix_P; // 3x4

		for ( int i = 0; i < numOfViews; i++ )
		{
			Matrix_P = camMatrix[i].transpose();

			//cout << "\ncamMatrix[i].transpose ():\n\n" << camMatrix [ i ].transpose () << endl;
			//cout << "\nMatrix_P:\n\n" << Matrix_P << endl;

			Matrix_A.row( 2 * i ) = matchedPts( i, 0 ) * Matrix_P.row( 2 ) - Matrix_P.row( 0 );
			Matrix_A.row( 2 * i + 1 ) = matchedPts( i, 1 ) * Matrix_P.row( 2 ) - Matrix_P.row( 1 );

			//cout << "\nMatrix_A.row ( 2 * i ):\n\n" << Matrix_A.row ( 2 * i ) << endl;
			//cout << "\nMatrix_A.row ( 2 * i + 1 ):\n\n" << Matrix_A.row ( 2 * i + 1 ) << endl;
		}

		JacobiSVD<Matrix4d> svd( Matrix_A, ComputeFullV );
		Matrix_V = svd.matrixV();

		Vector_X = Matrix_V.col( 3 );

		// Verified! 
		// Matche with MATLAB Output
		cout << "\nMatrix_A:\n\n" << Matrix_A << endl;
		cout << "\nMatrix_V:\n\n" << Matrix_V << endl;
		cout << "\nVector_X:\n\n" << Vector_X << endl;

		Vector_X = Vector_X / Vector_X( 3 );

		return Vector_X.head( 3 );
	}
}

Matrix3Xd cameraMatrix::mapminmax_apply( Matrix3Xd x, Vector3d settings_gain, Vector3d settings_xoffset, double settings_ymin ) {
	Matrix3Xd y( 3, x.cols() );

	y = x.array().colwise() - settings_xoffset.array();
	y = y.array().colwise() * settings_gain.array();
	y = y.array() + settings_ymin;

	return y;
}


Matrix3Xd cameraMatrix::mapminmax_reverse( Matrix3Xd y, Vector3d settings_gain, Vector3d settings_xoffset, double settings_ymin ) {
	Matrix3Xd x( 3, y.cols() );

	x = y.array() - settings_ymin;
	x = x.array().colwise() / settings_gain.array();
	x = x.array().colwise() + settings_xoffset.array();

	return x;
}

MatrixXXd cameraMatrix::tansig_apply( MatrixXXd n ) {
	n = -2.0f * n.array();
	n = n.array().exp() + 1;
	return ( 2 / n.array() - 1 );
}

void cameraMatrix::catInputPts( MatrixX2d inputPt1, MatrixX2d inputPt2 ) {
	int numInputSamples = inputPt1.rows();

	inputPtPairs[0] = inputPt1;
	inputPtPairs[1] = inputPt2;
}

void cameraMatrix::catInputPts( MatrixX2d inputPt1, MatrixX2d inputPt2, MatrixX2d inputPt3 ) {
	int numInputSamples = inputPt1.rows();
	inputPtPairs[0] = inputPt1;
	inputPtPairs[1] = inputPt2;
	inputPtPairs[2] = inputPt3;
}
void cameraMatrix::catInputPts( MatrixX2d inputPt1, MatrixX2d inputPt2, MatrixX2d inputPt3, MatrixX2d inputPt4 ) {
	int numInputSamples = inputPt1.rows();

	inputPtPairs[0] = inputPt1;
	inputPtPairs[1] = inputPt2;
	inputPtPairs[2] = inputPt3;
	inputPtPairs[3] = inputPt4;
}
