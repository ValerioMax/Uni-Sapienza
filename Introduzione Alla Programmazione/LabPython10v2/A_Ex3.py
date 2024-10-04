def A_Ex3(fileName):
    f = open(fileName, 'r', encoding = 'UTF-8')
    b = f.readline()
    righe = f.read().strip().split('\n')
    d = {}
    for riga in righe:
        riga = riga.strip().split(',')
        if int(riga[1]) >= 18:
            d[riga[2]] = []

    for riga in righe:
        riga = riga.strip().split(',')
        if int(riga[1]) >= 18:
            d[riga[2]].append(int(riga[0]))
    for key in d:
        (d.get(key)).sort()
    return d






    

###############################################################################

"""NON MODIFICARE, codice di testing della funzione"""

if __name__ == '__main__':
    from tester import tester_fun

    counter_test_positivi = 0
    total_tests = 5

    counter_test_positivi += tester_fun(A_Ex3, ["esami1.csv"] , {'Fisica': [1345, 1753], 'Analisi': [1346], 'Geometria': [1896]})
    counter_test_positivi += tester_fun(A_Ex3, ["esami2.csv"] , {'Analisi': [1346]})
    counter_test_positivi += tester_fun(A_Ex3, ["esami3.csv"] , {'Analisi': [1347, 1348], 'Ricerca Operativa': [1347, 1349]})
    counter_test_positivi += tester_fun(A_Ex3, ["esami4.csv"] , {'Basi di Dati': [1012, 1100], 'Analisi': [1021]})
    counter_test_positivi += tester_fun(A_Ex3, ["esami5.csv"] , {'Fisica': [1345], 'Fondamenti': [1987], 'Analisi': [1346], 'Geometria': [1896]})

    print('La funzione',A_Ex3.__name__,'ha superato',counter_test_positivi,'test su',total_tests)
