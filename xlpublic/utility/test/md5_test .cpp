#include "../md5.h"
#include <iostream>
#include <string>
using namespace std;
using namespace XL::UTILITY;

int main()
{
	const string text = "hello world";
	MD5 md(text);
	cout << "encode:" << md << endl;

	return 0;
}
/*
encode:5eb63bbbe01eeed093cb22bb8f5acdc3
*/