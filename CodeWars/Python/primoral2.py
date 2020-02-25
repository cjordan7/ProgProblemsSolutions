from functools import reduce

def num_primorial(n):
    counter = 1
    i = 3
    primorial = 2

    while counter != n:
        e = 1
        for j in range(1,int(i**0.5)+1,2):
            if(i % j == 0):
                e = e + 1
        if(e == 2):
            counter = counter + 1
            primorial = primorial * i
        i = i + 2
    return primorial
