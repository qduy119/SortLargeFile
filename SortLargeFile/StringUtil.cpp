#include<string>
std::string getFirstToken(std::string str) {
	int n = (int)str.size();
	std::string temp = "";
	for (int i = 0; i < n; i++) {
		if (str[i] != ',') {
			temp += str[i];

		}
		else {
			break;
		}
	}
	return temp;
}