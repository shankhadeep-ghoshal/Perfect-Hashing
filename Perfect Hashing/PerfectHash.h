#pragma once
#include <vector>
using namespace std;
class PerfectHash
{
	vector<vector<unsigned int>> hashTable;
	vector<unsigned int> arr;
	int a, b, prime;

	int hashValue(int key, int a, int b, int prime , int size);
	int maxValueInArray(vector<unsigned int> array);
	bool isPrime(int n);
	int nextPrime(int n);

public:
	PerfectHash(vector<unsigned int> array);
	PerfectHash(const PerfectHash& copy);
	~PerfectHash();

	int* returnParams();
	void createTable();
	void printTable();
};