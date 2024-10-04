def Ex5(file):
    import re
    f = open(file, 'r', encoding = 'UTF-8')
    righe = f.read().strip().split('\n')
    print(righe)
    pattern1 = r'\b[A-Z][A-Z][0-9][0-9][0-9][A-Z][A-Z]\b'
    pattern2 = r'\b[A-Z][A-Z][0-9][0-9][0-9][0-9][0-9]\b'
    pattern3 = r'\b[A-Z0-9][A-Z0-9][A-Z0-9][A-Z0-9][A-Z0-9]\b'
    pattern4 = r'\b[A-Z0-9][A-Z0-9][A-Z0-9][A-Z0-9][A-Z0-9][A-Z0-9]\b'
    d = {'auto': 0, 'moto': 0, 'ciclomotore1': 0, 'ciclomotore2': 0, 'errata': 0}
    for riga in righe:
        if re.search(pattern1,riga):
            d['auto'] += 1
        elif re.search(pattern2,riga):
            d['moto'] += 1
        elif re.search(pattern3,riga):
            d['ciclomotore1'] += 1
        elif re.search(pattern4,riga):
            d['ciclomotore2'] += 1
        else:
            d['errata'] += 1
    f.close()
    return d








    
      
###############################################################################

if __name__ == '__main__':
    from tester import tester_fun
    import re

    counter_test_positivi = 0
    total_tests = 5

    counter_test_positivi += tester_fun(Ex5, ["targhe1.txt"] , {'auto': 2, 'moto': 1, 'ciclomotore1': 1, 'ciclomotore2': 1, 'errata': 1})
    counter_test_positivi += tester_fun(Ex5, ["targhe2.txt"] , {'auto': 2, 'moto': 1, 'ciclomotore1': 1, 'ciclomotore2': 1, 'errata': 2})
    counter_test_positivi += tester_fun(Ex5, ["targhe3.txt"] , {'auto': 3, 'moto': 1, 'ciclomotore1': 1, 'ciclomotore2': 1, 'errata': 3})
    counter_test_positivi += tester_fun(Ex5, ["targhe4.txt"] , {'auto': 3, 'moto': 1, 'ciclomotore1': 1, 'ciclomotore2': 1, 'errata': 4})
    counter_test_positivi += tester_fun(Ex5, ["targhe5.txt"] , {'auto': 2, 'moto': 1, 'ciclomotore1': 1, 'ciclomotore2': 1, 'errata': 5})
    
    print('La funzione',Ex5.__name__,'ha superato',counter_test_positivi,'test su',total_tests)
