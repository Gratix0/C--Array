#include <iostream>
#include <windows.h>
#include <stdlib.h>
#include <time.h>
#include <vector>
#include <sstream>
#include <algorithm>
#include <iterator>
using namespace std;

void zapolnenie(vector <vector <int>>&, int&, int&);
void sredznnach(vector <vector <int>>&, int&, int&);
void min_max(vector <vector <int>>&, int&, int&, double&);
void min_max(vector <vector <int>>& v1, int& min, int& max, double& srzn, int&, int&);

void zapolnenie(vector <vector <int>>& v1, int& stroka, int& stolbets) {
	int i = 0;
	int j;

	srand(time(0));
	while (i < stroka) {
		j = 0;
		while (j < stolbets)
		{
			v1[i][j] = rand() % 100;
			j++;
		}
		i++;
	}
}

void wywod(vector <vector <int>>& v1, int& min, int& max, double& srzn, int& stroka, int& stolbets) {
	if (stroka > 100 || stolbets > 100) {
		cout << "Too much";
	}
	else {
		for (int i = 0; i < stroka; i++) {
			for (int j = 0; j < stolbets; j++) {
				cout << v1[i][j] << ' ';
			}
		}
	}
	cout << "\nMin: " << min << "\n";
	cout << "Max: " << max << "\n";
	cout << "srzn: " << srzn << "\n";
}


void sredznach(vector <vector <int>>& v1, int& stroka, int& stolbets) {
	int i = 0;
	int j;
	int count = 0;
	double srzn = 0;

	while (i < stroka) {
		j = 0;
		while (j < stolbets) {
			srzn = srzn + v1[i][j];
			count++;
			j++;
		}
		i++;
	}
	srzn = srzn / count;
	min_max(v1, stroka, stolbets, srzn);
}

void min_max(vector <vector <int>>& v1, int& stroka, int& stolbets, double& srzn) {
	int i = 0;
	int j;
	int min = v1[0][0];
	int max = v1[0][0];

	while (i < stroka) {
		j = 0;
		while (j < stolbets)
		{
			if (j + 1 < v1.size()) {
				if (min > v1[i][j + 1])
				{
					min = v1[i][j + 1];
				}
				if (max < v1[i][j + 1])
				{
					max = v1[i][j + 1];
				}
			}
			j++;
		}
		i++;
	}
	wywod(v1, min, max, srzn, stroka, stolbets);
}
int main() 
{
	int stroka;
	int stolbets;

	cout << "Enter row";
	cin >> stroka;

	cout << "Ennter column";
	cin >> stolbets;

	vector <vector <int>> v1(stroka, vector <int>(stolbets));

	zapolnenie(v1, stroka, stolbets);
	sredznnach(v1, stroka, stolbets);
}