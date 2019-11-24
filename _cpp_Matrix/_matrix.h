#pragma once
#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>

using namespace std;


void printMatrix(vector<vector<int>>& mat);

void transpose(vector<vector<int>>& mat);
void reverseColums(vector<vector<int>>& mat);
void rotateMatrix(vector<vector<int>>& mat);

vector<vector<int>> transposeMatrix(vector<vector<int>>& A);