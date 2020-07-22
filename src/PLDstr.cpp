// LCprac0.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool Judge(size_t x1, size_t x2, string input, vector<vector<int>>& flag) {
	if (input[x1] != input[x2]) {
		flag[x1][x2] = 1;
		if (x1>0 && x2<input.length()-1)
		{
			flag[x1-1][x2+1] = 1;
		}
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

string PLDstr(string input0) {
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

int main()
{
	string test_str = "ibvjkmpyzsifuxcabqqpahjdeuzaybqsrsmbfplxycsafogotliyvhxjtkrbzqxlyfwujzhkdafhebvsdhkkdbhlhmaoxmbkqiwiusngkbdhlvxdyvnjrzvxmukvdfobzlmvnbnilnsyrgoygfdzjlymhprcpxsnxpcafctikxxybcusgjwmfklkffehbvlhvxfiddznwumxosomfbgxoruoqrhezgsgidgcfzbtdftjxeahriirqgxbhicoxavquhbkaomrroghdnfkknyigsluqebaqrtcwgmlnvmxoagisdmsokeznjsnwpxygjjptvyjjkbmkxvlivinmpnpxgmmorkasebngirckqcawgevljplkkgextudqaodwqmfljljhrujoerycoojwwgtklypicgkyaboqjfivbeqdlonxeidgxsyzugkntoevwfuxovazcyayvwbcqswzhytlmtmrtwpikgacnpkbwgfmpavzyjoxughwhvlsxsgttbcyrlkaarngeoaldsdtjncivhcfsaohmdhgbwkuemcembmlwbwquxfaiukoqvzmgoeppieztdacvwngbkcxknbytvztodbfnjhbtwpjlzuajnlzfmmujhcggpdcwdquutdiubgcvnxvgspmfumeqrofewynizvynavjzkbpkuxxvkjujectdyfwygnfsukvzflcuxxzvxzravzznpxttduajhbsyiywpqunnarabcroljwcbdydagachbobkcvudkoddldaucwruobfylfhyvjuynjrosxczgjwudpxaqwnboxgxybnngxxhibesiaxkicinikzzmonftqkcudlzfzutplbycejmkpxcygsafzkgudy";
	string ans = "";
	ans = PLDstr(test_str);
	cout << "answer: " << ans << endl;
	
	return 1;
}

