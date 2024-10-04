from math import sqrt

a = int(input('inserisci primo coefficiente a: '))
b = int(input('inserisci secondo coefficiente b: '))
c = int(input('inserisci terzo coefficiente c: '))
x1 = (-b + sqrt(b**2 - 4*a*c)) / (2*a)
x2 = (-b - sqrt(b**2 - 4*a*c)) / (2*a)
print(x1, x2)
