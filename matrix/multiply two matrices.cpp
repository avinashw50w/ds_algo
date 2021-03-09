/*multiple two square matrices*/

struct Matrix {
	vector<vector<int>> mat;
	Matrix(int n, int m) {
		mat = vector<vector<int>>(n, vector<int>(m, 0));
	}
};

Matrix multiply(Matrix a, Matrix b) {
	int n = a.mat.size();
	Matrix res(n, n);
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			for (int k = 0; k < n; ++k) {
				res.mat[i][j] += a.mat[i][k] * b.mat[k][j];
			}
		}
	}

	return res;
}

// multiply two rectangular matrices

Matrix multiply(Matrix a, Matrix b) {
	int n1 = a.mat.size(), n2 = a.mat[0].size();
	int m1 = b.mat.size(), m2 = b.mat[0].size();
	// m1 = n2 for multiplication of two matrices
	Matrix res(n1, m2);

	for (int i = 0; i < n1; ++i) {
		for (int j = 0; j < m2; ++j) {
			for (int k = 0; k < n2; ++k) {
				res.mat[i][j] += a.mat[i][k] * b.mat[k][j];
			}
		}
	}

	return res;
}