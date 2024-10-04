def A_Ex7(file):
    f = open(file, 'r', encoding = 'UTF-8')
    b = f.readline()
    righe = f.read().strip().split('\n')
    d = {}
    lista = []
    for riga in righe:
        a = riga.split(',')
        for i in range(2):
            if a[i] not in lista:
                lista.append(a[i])
    
    for squadra in lista:
        punti = 0
        for riga in righe:
            a = riga.split(',')
            if squadra in a:
                if squadra == a[0]:
                    if int(a[2]) > int(a[3]):
                        punti += 3
                    elif int(a[2]) == int(a[3]):
                        punti += 1
                elif squadra == a[1]:
                    if int(a[2]) < int(a[3]):
                        punti += 3
                    elif int(a[2]) == int(a[3]):
                        punti += 1
        d[squadra] = punti

    return d
        










    

 
###############################################################################

"""NON MODIFICARE, codice di testing della funzione"""

if __name__ == '__main__':
    from tester import tester_fun

    counter_test_positivi = 0
    total_tests = 5

    counter_test_positivi += tester_fun(A_Ex7, ["partite1.csv"] , {'Chelsea': 3, 'Everton': 3, 'Arsenal': 4, 'Tottenham': 1})
    counter_test_positivi += tester_fun(A_Ex7, ["partite2.csv"] , {'Chelsea': 4, 'Everton': 6, 'Arsenal': 4, 'Tottenham': 2})
    counter_test_positivi += tester_fun(A_Ex7, ["partite3.csv"] , {'Bayern': 4, 'Schalke': 3, 'Amburgo': 4, 'Werder': 1, 'Colonia': 4, 'Stoccarda': 0})
    counter_test_positivi += tester_fun(A_Ex7, ["partite4.csv"] , {'Bayern': 8, 'Schalke': 6, 'Amburgo': 8, 'Werder': 2, 'Colonia': 8, 'Stoccarda': 0})
    counter_test_positivi += tester_fun(A_Ex7, ["partite5.csv"] , {'Bayern': 5, 'Schalke': 6, 'Amburgo': 5, 'Werder': 5, 'Colonia': 5, 'Stoccarda': 6})

    print('La funzione',A_Ex7.__name__,'ha superato',counter_test_positivi,'test su',total_tests)
