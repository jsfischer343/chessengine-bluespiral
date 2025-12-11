#Automated debugging script, primarily used with bluespiral directly and gdb + bluespiral (see setup line)

import threading
import subprocess
import time

#async flags
isReady = True
doneProcessing = True
isReady_lock = threading.Lock()
doneProcessing_lock = threading.Lock()
hitBreakpoint = False

def readSubprocessOutput(process):
    global isReady
    global doneProcessing
    global hitBreakpoint
    while True:
        line_stdout = process.stdout.readline()
        if line_stdout:
            print("stdout> ",end="")
            print(line,end="")

            #handle gdb breakpoints
            if line.find("hit Breakpoint")!=-1:
                hitBreakpoint = True
            #wait until
            elif line=="readyok\n":
                with isReady_lock:
                    isReady=True
            elif line[0:8]=="bestmove":
                with doneProcessing_lock:
                    doneProcessing=True
        line_stderr = process.stderr.readline()
        if line_stderr:
            print("stderr> ",end="")
            print(line,end="")
        if not line_stdout and not line_stderr and process.poll() is not None:
            break

#Setup
#userInput = input("Run?$ ").split(' ',1) #dynamic setup
#binaryToRun = userInput[0]
#arguments = userInput[1]
binaryToRun = "gdb" #hardcoded setup
arguments = "../src/bluespiral" #hardcoded setup

#UCI commands
file = open("debug_commands.txt","r")

#bluespiral subprocess
if arguments=="":
    process = subprocess.Popen([binaryToRun], stdin=subprocess.PIPE,stdout=subprocess.PIPE,stderr=subprocess.PIPE,text=True,bufsize=1)
else:
    process = subprocess.Popen([binaryToRun,arguments], stdin=subprocess.PIPE,stdout=subprocess.PIPE,stderr=subprocess.PIPE,text=True,bufsize=1)

#thread to print out program output
readOutputThread = threading.Thread(target=readSubprocessOutput, args=(process,))
readOutputThread.start()

time.sleep(0.1)

#read all automated commands and wait for go commands and isready commands
for line in file:
    if hitBreakpoint:
        break
    if line=="isready\n":
        with isReady_lock:
            isReady=False
    if line[0:2]=="go":
        with doneProcessing_lock:
            doneProcessing=False
    #write automated commands to main process stdout as they run
    print("<stdin: ",end="")
    print(line,end="")
    #write line to subprocess
    process.stdin.write(line)
    process.stdin.flush()
    if line=="isready\n":
        while not isReady:
            pass
    if line[0:2]=="go":
        while not doneProcessing:
            pass
    time.sleep(0.01) #wait breifly between commands
file.close()

#wait for sync then process additional user commands
while not isReady or not doneProcessing:
    pass
time.sleep(0.05)
userInput = input("<additional input? (quit to exit): ")
while userInput!="quit":
    userInput += '\n'
    process.stdin.write(userInput)
    process.stdin.flush()
    time.sleep(0.05)
    userInput = input("<additional input?: ")

process.stdin.write('exit\n')
process.stdin.flush()
process.stdin.write('exit\n')
process.stdin.flush()

process.wait()
readOutputThread.join()
