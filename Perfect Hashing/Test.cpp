#include "stdafx.h"
#include "PerfectHash.h"
#include <iostream>

using namespace std;

int main() {

	
	vector<unsigned int> array;
	for (int i = 0; i < 10; i++)array.push_back(i + 3);
	PerfectHash p(array);
	p.createTable();
	int a[3];
	a[0] = p.returnParams()[0];
	a[1] = p.returnParams()[1];
	a[2] = p.returnParams()[2];
	for (int i : a) cout << i << " " << endl;
	p.printTable();
	
	return 0;
}