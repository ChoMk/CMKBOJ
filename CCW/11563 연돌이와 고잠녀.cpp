#include<cstdio>
#include<algorithm>
#include<vector>
#include<cmath>
using namespace std;

vector<pair<double, double>> nPointS;
vector<pair<double, double>> nPointD;
vector<pair<double, double>> mPointS;
vector<pair<double, double>> mPointD;
int n, m;
double x, y;
double result = 987654321;
double nPoint[2][2];
double mPoint[2][2];
double dot(double u1, double v1, double u2, double v2) {
	return u1 * u2 + v1 * v2;
}
double externalVector(double u1, double v1, double u2, double v2, double u3, double v3) {
	return u1 * v2 + u2 * v3 + u3 * v1 - u2 * v1 - u3 * v2 - u1 * v3;
}
double pointDistance(double u1, double v1, double u2, double v2) {
	return sqrt((u1 - u2)*(u1 - u2) + (v1 - v2)*(v1 - v2));
}


int main() {
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		scanf("%lf %lf", &x, &y);
		nPointS.push_back({ x,y });

		scanf("%lf %lf", &x, &y);
		nPointD.push_back({ x,y });

	}
	for (int i = 0; i < m; i++) {
		scanf("%lf %lf", &x, &y);
		mPointS.push_back({ x,y });

		scanf("%lf %lf", &x, &y);
		mPointD.push_back({ x,y });

	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			
			nPoint[0][0] = nPointS[i].first;
			nPoint[0][1] = nPointS[i].second;
			
			nPoint[1][0] = nPointD[i].first;
			nPoint[1][1] = nPointD[i].second;

			mPoint[0][0] = mPointS[j].first;
			mPoint[0][1] = mPointS[j].second;

			mPoint[1][0] = mPointD[j].first;
			mPoint[1][1] = mPointD[j].second;
			double checkVector1;
			double checkVector2;
			for (int k = 0; k < 2; k++) {
				checkVector1 = dot(mPoint[0][0]-nPoint[k][0], mPoint[0][1] - nPoint[k][1], mPoint[1][0] - mPoint[0][0], mPoint[1][1] - mPoint[0][1]);
				checkVector2 =dot(mPoint[1][0] - mPoint[0][0], mPoint[1][1] - mPoint[0][1], nPoint[k][0] - mPoint[1][0], nPoint[k][1] - mPoint[1][1]);
				
				if (checkVector1*checkVector2>=0) {
					result = min(result, abs(externalVector(nPoint[k][0], nPoint[k][1], mPoint[0][0], mPoint[0][1], mPoint[1][0], mPoint[1][1])) / pointDistance(mPoint[0][0], mPoint[0][1], mPoint[1][0], mPoint[1][1]));
				}
				for (int l = 0; l < 2; l++) {
					result = min(result, pointDistance(nPoint[k][0], nPoint[k][1], mPoint[l][0], mPoint[l][1]));
				}
			}
			for (int k = 0; k < 2; k++) {
				checkVector1 = dot(nPoint[0][0] - mPoint[k][0], nPoint[0][1] - mPoint[k][1], nPoint[1][0] - nPoint[0][0], nPoint[1][1] - nPoint[0][1]);
				checkVector2 = dot(nPoint[1][0] - nPoint[0][0], nPoint[1][1] - nPoint[0][1], mPoint[k][0] - nPoint[1][0], mPoint[k][1] - nPoint[1][1]);
				if (checkVector1*checkVector2 >= 0) {
					result = min(result, abs(externalVector(mPoint[k][0], mPoint[k][1], nPoint[0][0], nPoint[0][1], nPoint[1][0], nPoint[1][1])) / pointDistance(nPoint[0][0], nPoint[0][1], nPoint[1][0], nPoint[1][1]));
				}
			}
			

		}
	}
	printf("%lf\n", result);

}