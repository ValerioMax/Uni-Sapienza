s = input('inserisci stringa s :')
i = 0
j = len(s) - 1
n = 0
for h in s:
    if s[i] == s[j]:
        i += 1
        j -= 1
        n += 1
print('la stringa s è palindroma di livello: ' + str(n))
