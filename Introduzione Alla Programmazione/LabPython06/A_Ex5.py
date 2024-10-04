s = input('inserisci stringa alfanumerica non vuota s: ')
i = 0
y = 0
for h in s:
    x = s.count(s[i])
    if x >= y:
        y = x
        z = s[i]
    i += 1
print(z + ' ' + str(y))
