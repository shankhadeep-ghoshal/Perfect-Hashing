#include "stdafx.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "PerfectHash.h"
using namespace std;



int PerfectHash::hashValue(int key, int a, int b, int prime, int size)
{
	return ((key*a + b)%prime)%size;
}

int PerfectHash::maxValueInArray(vector<unsigned int> array)
{	
	int max = 0;
	for (int i = 0; i < array.size(); i++) {
		max = (array[i] > max) ? array[i] : max;
	}
	return max;
}

int PerfectHash::nextPrime(int n)
{
	int nextPrime = n;
	bool found = false;
	while (!found)
	{
		nextPrime++;
		if (isPrime(nextPrime))found = true;
	}
	return nextPrime;
}

bool PerfectHash::isPrime(int n)
{
	for (int i = 2; i <= n / 2; i++)
	{
		if (n % i == 0)return false;
	}
	return true;
}



PerfectHash::PerfectHash(vector<unsigned int> array)
{
	arr = array;
	srand(time(NULL));
	//vector<vector<unsigned int>> hashTable(arr.size());
	hashTable = vector<vector<unsigned int>>(arr.size());
	//prime  = 17;
	prime = nextPrime(maxValueInArray(arr));
	a = (1 + (rand() % (int)(prime - 1)));
	b = (0 + (rand() % (int)(prime - 0)));
}

PerfectHash::PerfectHash(const PerfectHash& copy)
{
	hashTable = copy.hashTable;
	prime = copy.prime;
	a = copy.a;
	b = copy.b;
}

PerfectHash::~PerfectHash()
{
	arr.clear();
	hashTable.clear();
}

int* PerfectHash::returnParams()
{
	int temp[3];
	temp[0] = a;
	temp[1] = b;
	temp[2] = prime;
	return temp;
}

void PerfectHash::createTable()
{
	for (int i = 0; i < arr.size(); i++) {
		int hashInt = hashValue(arr[i], a, b, prime, arr.size());
		(hashTable[hashInt]).push_back(arr[i]);
	}
	for (unsigned int i = 0; i < arr.size();i++) {
		vector<unsigned int> temp = hashTable[i];
		if (temp.size() > 0) {
			if (temp.size() == 1)hashTable[i] = temp;
			else {
				int new_m = (temp.size()) * (temp.size());
				vector<unsigned int> placeholderVector(new_m);
				//hashTable[i].clear();
				hashTable[i].resize(new_m);
				bool noC = true;
				while (noC) {
					srand(time(NULL));
					const int new_a = (1 + (rand() % (int)(prime - 1)));
					const int new_b = (0 + (rand() % (int)(prime - 0)));
					for (unsigned int j = 0; j < temp.size();) {
						unsigned int newHashVal = hashValue(temp[j], new_a, new_b, prime, new_m);
						if (!(hashTable[i][newHashVal] == temp[j])) {
							placeholderVector[newHashVal] = temp[j];
							hashTable[i] = placeholderVector;
							++j;
						}
						else {
							noC = false;
							break;
						}
					}
				}
			}
		}
		else {
			continue;
		}	
	}
}

void PerfectHash::printTable()
{
	for (int i = 0; i < hashTable.size(); i++) {
		for (int j = 0; j < hashTable[i].size(); j++) {
			if (hashTable[i][j] == 0)continue;
			cout << hashTable[i][j] << " " << i << "-th row" << " " << j << "-th column " << endl;
		}
	}
}