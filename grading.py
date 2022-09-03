from data import problems
import os

result = list()

for problem in problems.keys():
    
    grader = problems[problem]
    command = "./" + grader + ".exe " + problem + " > result.tmp"
    os.system(command)
    
    passed = False
    response = "Not Passed"
    f = open("result.tmp", "r")
    if f.read() == "CORRECT":
        passed = True
    if passed:
        response = "Passed"
    result.append(problem + ": " + response)

print("\n".join(result))

command = "rm result.tmp"
os.system(command)
