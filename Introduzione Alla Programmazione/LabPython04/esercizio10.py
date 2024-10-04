s1 = input('inserisci stringa: ')
s2 = input('inserisci stringa: ')
s3 = input('inserisci stringa: ')
while not len(s3) == len(s1) + len(s2):
    s1 = s2
    s2 = s3
    s3 = input('inserisci stringa: ')
print(s1,s2,s3)
