import math
n = 8500
divisor = []
dMAX = int(math.sqrt(n))

d = 1
while d < dMAX:
    if((n % d) == 0):
        print(d)
        divisor.append(d)
    d +=1

divLen= len(divisor) -1 

while divLen >= 0:
    divisor.append(int(n/divisor[divLen]))
    divLen -=1


print(divisor)