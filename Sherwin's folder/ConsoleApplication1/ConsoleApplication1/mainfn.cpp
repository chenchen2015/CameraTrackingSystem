#include "CamMatrix.h"

using namespace Eigen;

MatrixX3d Triangulate()
{
	cameraMatrix* session = new cameraMatrix();

	MatrixX3d result = session->Triangulate();

	return result;

	delete session;
}

void main()
{
	cout << "\nTriangulate Result:\n\n" << Triangulate() << endl;
	cin.get();
}
