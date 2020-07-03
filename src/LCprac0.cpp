// LCprac0.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <thread>

using namespace std;

bool Judge(size_t x1, size_t x2, string input, vector<vector<int>>& flag) {
	if (input[x1] != input[x2]) {
		flag[x1][x2] = 1;
		
		return false;
	}
	else if (input[x1] == input[x2] && x1 < x2) {
		return Judge(x1 + 1, x2 - 1, input, flag);
	}
	else {
		return true;
	}
}

bool Judge_one_stage(size_t L, size_t l, string input, string& ans, vector<vector<int>>& flag) {
	for (size_t i = 0; i <= L - l; i++) {
		if (flag[i][i+l-1] == 1)
		{
			continue;
		}
		else if (Judge(i, i + l - 1, input, flag)) {
			ans = input.substr(i, l);
			return true;
		}
	}
	return false;
}

string PLDstrTopDown(string input0) {
	size_t len_str = input0.length();
	size_t len_str0 = input0.length();
	string ans = "";
	vector<vector<int>> flag(len_str0, vector<int>(len_str0));
	while (len_str > 0)
	{
		if (Judge_one_stage(len_str0, len_str, input0, ans, flag))
		{
			break;
		}
		else
		{
			len_str--;
		}
	}
	return ans;

}


bool Judge_one_stage0(size_t L, size_t l, string input, vector<vector<int>>& flag, size_t& pos) {
	if (l > L) return false;
	for (size_t i = 0; i <= L - l; i++) {
		if (flag[i+1][i + l - 2] == 1 && l>3)
		{
			continue;
		}
		else if (Judge(i, i + l - 1, input, flag)) {
			pos = i;
			return true;
		}
	}
	return false;
}

void Run(size_t Len, size_t& len, string input0, vector<vector<int>>& flag, size_t& pos) {
	while (len <= Len)
	{
		if (Judge_one_stage0(Len, len, input0, flag, pos))
		{
			len += 2;
		}
		else {
			len -= 2;
			break;
		}
	}
}

string PLDstrBotUp(string input0) {
	size_t len_str_even = 2;
	size_t len_str_odd = 3;
	size_t len_str = 0;
	size_t len_str0 = input0.length();
	if (len_str0 < 2) return input0;
	vector<vector<int>> flag(len_str0, vector<int>(len_str0));
	size_t pos_even = 0;
	size_t pos_odd = 0;
	size_t pos = 0;

	if (len_str0 == 2 && Judge_one_stage0(len_str0, len_str_even, input0, flag, pos)) return input0;
	else return input0.substr(0, 1);

	thread run_even(Run, len_str0, ref(len_str_even), input0, ref(flag), ref(pos_even));
	thread run_odd(Run, len_str0, ref(len_str_odd), input0, ref(flag), ref(pos_odd));
	run_even.join();
	run_odd.join();

	
	if (len_str_even > len_str_odd)
	{
		pos = pos_even;
		len_str = len_str_even;
	}
	else {
		pos = pos_odd;
		len_str = len_str_odd;
	}


	return input0.substr(pos, len_str);

}

int main()
{
	string test_str = "abc";
	string ans = "";
	//ans = PLDstrTopDown(test_str);
	ans = PLDstrBotUp(test_str);
	cout << "answer: " << ans << endl;
	
	return 1;
}

