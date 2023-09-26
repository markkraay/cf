#include <vector>
#include <iostream>
#include <string>

using namespace std;

vector<int> getOctets(const string& s) {
    vector<int> res;
    string temp = "";
    for (char c : s) {
        if (c == '.') {
            res.push_back(stoi(temp)); 
            temp = "";
        } else temp += c;
    }
    return res;    
}

bool validIp(vector<int> const& octets) {
    if (octets.size() != 4) return false;
    for (int i : octets) if (i < 0 || i > 255) return false;
    return true;
}

int getGroup(int octet) {
    if (octet >= 0 && octet < 128) return 1;
    if (octet < 192) return 2;
    if (octet < 224) return 3;
    if (octet < 240) return 4;
    if (octet <= 255) return 5;   
    return -1; 
}

vector<int> getRegions(vector<string> ip_addresses) {
    vector<int> result;
    for (const auto& ip : ip_addresses) {
        auto octets = getOctets(ip);
        int group = validIp(octets) ? getGroup(octets[0]) : -1;
        result.push_back(group);
    }
    return result;
}

int main() {
	vector<string> ip_addresses = {
		"123.211.102.13",
		"271.142.67.142",
		"225.217.132.58", 
	};
	auto res = getRegions(ip_addresses);
	for (int i : res) cout << i << " ";
}