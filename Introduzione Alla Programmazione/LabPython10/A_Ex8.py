def A_Ex8(file):
    f = open(file, 'r', encoding = 'UTF-8')
    b = f.readline()
    righe = f.read().strip('\n').split('\n')
    d = {}
    lista = []
    for riga in righe:
        a = riga.split(',')
        for i in range(2):
            if a[i] not in lista:
                lista.append(a[i])

    for pers in lista:
        d[pers] = set()
        for riga in righe:
            a = riga.split(',')
            if pers in a:
                if pers == a[0]:
                    if a[2] == 'amici':
                        d[pers].add(a[1])
                    elif a[2] == 'nemici':
                        if a[1] in d.get(pers):
                            d[pers].remove(a[1])
                elif pers == a[1]:
                    if a[2] == 'amici':
                        d[pers].add(a[0])
                    elif a[2] == 'nemici':
                        if a[0] in d.get(pers):
                            d[pers].remove(a[0])
        c = list(d.get(pers))
        c.sort()
        d[pers] = c
    return d
            
            
    
    
    
###############################################################################

"""NON MODIFICARE, codice di testing della funzione"""

if __name__ == '__main__':
    from tester import tester_fun

    counter_test_positivi = 0
    total_tests = 5

    counter_test_positivi += tester_fun(A_Ex8, ["amici1.csv"] , {'Paolo': ['Marco'], 'Marco': ['Paolo'], 'Anna': ['Maria', 'Paola'], 'Maria': ['Anna'], 'Paola': ['Anna'], 'Giorgio': []})
    counter_test_positivi += tester_fun(A_Ex8, ["amici2.csv"] , {'Paolo': ['Marco'], 'Marco': ['Paolo'], 'Anna': ['Maria'], 'Maria': ['Anna'], 'Paola': [], 'Giorgio': []})
    counter_test_positivi += tester_fun(A_Ex8, ["amici3.csv"] , {'Paolo': ['Marco'], 'Marco': ['Paolo'], 'Anna': ['Maria', 'Paola'], 'Maria': ['Anna'], 'Paola': ['Anna'], 'Giorgio': []})
    counter_test_positivi += tester_fun(A_Ex8, ["amici4.csv"] , {'Marco': ['Giorgio', 'Paolo'], 'Giorgio': ['Marco'], 'Paolo': ['Marco'], 'Anna': ['Maria', 'Paola'], 'Maria': ['Anna'], 'Paola': ['Anna']})
    counter_test_positivi += tester_fun(A_Ex8, ["amici5.csv"] , {'Marco': [], 'Giorgio': [], 'Paola': [], 'Anna': []})

    print('La funzione',A_Ex8.__name__,'ha superato',counter_test_positivi,'test su',total_tests)
