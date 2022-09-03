#include <iostream>
#include <cstdlib>
#include <string>
#include <cstring>
using namespace std;

inline void cmd(string s){
	system(s.c_str());
}

int main(int argc, char* argv[]){
	string fileName(argv[1]);
	string filePath = "Thailand-Olympiad-in-Informatics/";
	int n;
	// compile code
	cmd("g++ -std=c++14 -O2 " + filePath + fileName + ".cpp -o " + fileName + ".exe");
	// copy directory to nearest
	cmd("cp -r testcase/" + fileName + " testset");
	// count number of testset
	cmd("ls testset/" + fileName + " | wc -l > count.tmp");
	freopen("count.tmp", "r", stdin);
	cin >> n;
	fclose(stdin);
	int number_of_input = n / 2, cnt;
	bool ok = true;
	for(int i=1; i<=number_of_input; ++i){
		string inputFile = "testset/" + fileName + "/" + to_string(i) + ".in";
		string outputFile = to_string(i) + ".out";
		// run case
		cmd("./" + fileName + ".exe < " + inputFile + " > " + outputFile);
		// check diff
		cmd("diff " + outputFile + " testset/" + fileName + "/" + outputFile + " -wb > output.tmp");
		// count number of lines
		cmd("wc -l output.tmp > lines.tmp");
		// check
		freopen("lines.tmp", "r", stdin);
		cin >> cnt;
		fclose(stdin);
		if(cnt != 0){
			ok = false;
		}
		// remove output
		cmd("rm " + outputFile);
	}
	// remove files
	cmd("rm *.exe");
	cmd("rm *.tmp");
	cmd("rm -rf testset");

	if(ok == false){
		cout << "WRONG ANWSWER";
		exit(1);
	}
	cout << "CORRECT";
	return 0;
}
