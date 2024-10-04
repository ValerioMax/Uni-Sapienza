s = input('inserisci stringa palindroma: ')
i = 0
j = len(s) - 1

while i < j:
    if s[i] == s[j]:
        i += 1
        j -= 1
    elif s[i] != s[j]:
        s = input('inserisci stringa palindroma: ')
        print('non palindroma, inserire una stringa palindroma')
        i = 0
        j = len(s) - 1
print('stringa palindroma di lunghezza',len(s))


 
