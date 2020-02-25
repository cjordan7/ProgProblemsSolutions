
# Definition (Primorial Of a Number)

# Is similar to factorial of a number, In primorial, not all the natural numbers get
# multiplied, only prime numbers are multiplied to calculate the primorial of a
# number. It's denoted with P

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
            
