#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <climits>


using namespace std;

vector<vector<int>> subsets(vector<int>& nums);
void sumArray(vector<int>& A);


vector<string> generateParenthesis2(int n);

int countWaysDP(int n);

int countWaysR(int n);


int rob(vector<int>& nums);
int rob_2(vector<int>& nums);