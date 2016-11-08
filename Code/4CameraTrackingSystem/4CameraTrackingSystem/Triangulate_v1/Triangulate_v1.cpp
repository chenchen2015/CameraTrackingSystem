#include "CameraMatrix.hpp"

MatrixX3d Triangulate();

void main ()
{
	//HelloWorld ();
	
	cout << "\nTriangulate Result:\n\n" << Triangulate () << endl;

	cin.get (); // Stop the program from terminating, serves as a "Pause" command
}

MatrixX3d Triangulate ()
{
	cameraMatrix* session = new cameraMatrix();

	MatrixX3d result = session->Triangulate();

	//delete session;

	return result;
}

void HelloWorld (){
	Matrix3f A, B; // Float Type Matrix 3x3 
	Vector3f C;

	C << 1, 1, 1;

	A << 1, 2, 3,
		4, 5, 6,
		7, 8, 9; // Assign Matrix Value Manually

	B << 3, 2, 1,
		6, 5, 4,
		9, 8, 7;

	cout << "\nMatrix A:\n\n" << A << endl; // Show Matrix A
	cout << "\nMatrix A-C:\n\n" << (A.array().colwise() - C.array()) << endl; // Show Matrix A

	cout << "\nMatrix B:\n\n" << B << endl; // Show Matrix B

	cout << "\nResult of  5 * A + 6.5 * B:\n\n" << 5 * A + 6.5 * B << endl; // Perform Simple Linear Matrix Operation
}
