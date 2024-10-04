def Ex4(file):
    f = open(file, 'r', encoding = 'UTF-8')
    b = f.readline()
    righe = f.read().strip().split('\n')
    oggetti = set()
    for riga in righe:
        riga = riga.split(',')
        oggetti.add(riga[0])
    d = {}
    for i in oggetti:
        for riga in righe:
            riga = riga.split(',')
            if riga[0] == i:
                d[i] = [riga[1]]
                break
            
    for i in oggetti:
        for riga in righe:
            riga = riga.split(',')
            if riga[0] == i:
                if len(d.get(i)) == 1:
                    d[i].append(riga[2])
                elif len(d.get(i)) > 1 and d.get(i)[1] == riga[1]:
                    d[i].remove(d.get(i)[1])
                    d[i].append(riga[2])
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
