import os

graders = [
	"sample_grader.cc"
]

for grader in graders:
    fileWithtype = grader
    noType = grader.split(".")[0]
    command = "g++ -std=c++14 -O2 grader/" + fileWithtype + " -o " + noType + ".exe"
    os.system(command)
