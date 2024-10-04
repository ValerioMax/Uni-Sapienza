s1 = input('inserisci stringa s1: ')
s2 = input('inserisci stringa s2: ')
x = ''
for i in range(0,len(s1)):
    if s2.count(s1[i]) == 0:
        x = x + s1[i]
print(x)
