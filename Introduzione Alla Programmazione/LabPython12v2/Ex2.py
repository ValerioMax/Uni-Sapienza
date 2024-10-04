def Ex2(file,s):
    f = open(file, 'r', encoding = 'UTF-8')
    righe = f.read().strip().split('\n')
    d = {} 
    c = 0
    for riga in righe:
        c += 1
        d[c] = []
        riga = riga.strip().split(' ')
        for parola in riga:
            a = list(parola.lower())
            b = list(s.lower())
            a.sort()
            b.sort()
            if a == b:
                d[c].append(parola)
    return d
   
            
###############################################################################

"""NON MODIFICARE IL CODICE (codice di test della funzione)"""

if __name__ == '__main__':
    from tester import tester_fun

    counter_test_positivi = 0
    total_tests = 5

    # test distribuzione

    counter_test_positivi += tester_fun(Ex2, ['testo1.txt','lardo'],{1: [], 2: ['lardo', 'lorda'], 3: ['lardo', 'lorda'], 4: ['Darlo', 'ralod']})
    counter_test_positivi += tester_fun(Ex2, ['testo2.txt','lardo'],{1: [], 2: ['lardo', 'lorda'], 3: ['Darlo', 'ralod'], 4: ['LORDA']})
    counter_test_positivi += tester_fun(Ex2, ['testo1.txt','la'],{1: ['la', 'la'], 2: ['Al', 'LA'], 3: ['Al'], 4: []})
    counter_test_positivi += tester_fun(Ex2, ['testo2.txt','tanto'],{1: ['Tanto', 'tonta'], 2: [], 3: [], 4: []})
    counter_test_positivi += tester_fun(Ex2, ['testo3.txt','casa'],{1: [], 2: [], 3: ['asca', 'CAAs'], 4: ['asAc']})

    print('La funzione',Ex2.__name__,'ha superato',counter_test_positivi,'test su',total_tests)
