def Ex4(file):
    f = open(file, 'r', encoding = 'UTF-8')
    b = f.readline()
    righe = f.read().strip().split('\n')
    d = {}
    insieme1 = set()
    for riga in righe:
        a = riga.split(',')
        insieme1.add(a[0])
    lista1 = list(insieme1)
    
    for oggetto in lista1:
        for riga in righe:
            a = riga.split(',')
            if oggetto == a[0]:
                d[oggetto] = [a[1]]
                break
            
    for oggetto in lista1:
        for riga in righe:
            a = riga.split(',')
            if oggetto == a[0] and len(d.get(oggetto)) >= 2 and d.get(oggetto)[1] == a[1]:
                d[oggetto].remove(d.get(oggetto)[1])
                d[oggetto].append(a[2])
            elif oggetto == a[0] and len(d.get(oggetto)) == 1:
                d[oggetto].append(a[2])
    f.close()
    return d
        
    



    
    
###############################################################################

"""NON MODIFICARE, codice di testing della funzione"""

if __name__ == '__main__':
    from tester import tester_fun

    counter_test_positivi = 0
    total_tests = 5

    counter_test_positivi += tester_fun(Ex4, ["eredita1.csv"] , {'Anello_di_smeraldi': ['Maria', 'Giorgia'], 'Anello': ['Silvia', 'Paolo']})
    counter_test_positivi += tester_fun(Ex4, ["eredita2.csv"] , {'Anello_di_smeraldi': ['Marco', 'Giorgio'], 'Anello': ['Silvia', 'Sergio']})
    counter_test_positivi += tester_fun(Ex4, ["eredita3.csv"] , {'Anello_di_smeraldi': ['Marco', 'Giorgio'], 'Anello': ['Silvia', 'Sergio'], 'Vaso': ['Anna', 'Sergio']})
    counter_test_positivi += tester_fun(Ex4, ["eredita4.csv"] , {'Anello_di_smeraldi': ['Marco', 'Giorgio'], 'Anello': ['Silvia', 'Giorgio'], 'Vaso': ['Anna', 'Anna']})
    counter_test_positivi += tester_fun(Ex4, ["eredita5.csv"] , {'Anello_di_smeraldi': ['Marco', 'Giorgio'], 'Anello': ['Silvia', 'Sergio'], 'Vaso': ['Sergio', 'Anna']})

    print('La funzione',Ex4.__name__,'ha superato',counter_test_positivi,'test su',total_tests)
