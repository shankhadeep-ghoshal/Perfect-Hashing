#include "stdafx.h"
#include "PerfectHash.h"
#include <iostream>

using namespace std;

int main() {

	
	vector<unsigned int> array;
	for (int i = 0; i < 11; i++)array.push_back(i);
	array.push_back(5);
	for (int i = 55; i > 45; i--)array.push_back(i + 3);
	for (int i = 15; i < 25; i++)array.push_back(i + 2);
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