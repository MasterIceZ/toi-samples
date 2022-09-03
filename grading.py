from data import problems
import os

for problem in problems.keys():
    grader = problems[problem]
    command = "./" + grader + ".exe " + problem
    os.system(command)
