def Ex7(file):
    import re
    f = open(file, 'r', encoding = 'UTF-8')
    righe = f.read().strip().split('\n')
    d = {}
    pattern1 = r'\b192\.168\.(\d\d?\d?)\.(\d\d?\d?)\b'
    pattern2 = r'\b(\d\d?\d?)\.(\d\d?\d?)\.(\d\d?\d?)\.(\d\d?\d?)\b'
    d = {'invalidi': 0, 'domestici': 0, 'altri': 0}
    
    for riga in righe:
        m1 = re.search(pattern1,riga)
        m2 = re.search(pattern2,riga)
        
        if m1:
            if int(m1.group(1)) <= 255 and int(m1.group(2)) <= 255:
                d['domestici'] += 1
            else:
                d['invalidi'] += 1
                
        elif m2:
            if int(m2.group(1)) <= 255 and int(m2.group(2)) <= 255 and int(m2.group(3)) <= 255 and int(m2.group(4)) <= 255:
                d['altri'] += 1
            else:
                d['invalidi'] += 1
        else:
            d['invalidi'] += 1
    f.close()        
    return d
        



       
    
###############################################################################

if __name__ == '__main__':
    from tester import tester_fun
    import re

    counter_test_positivi = 0
    total_tests = 5

    counter_test_positivi += tester_fun(Ex7, ["ip1.txt"] , {'invalidi': 0, 'domestici': 0, 'altri': 5})
    counter_test_positivi += tester_fun(Ex7, ["ip2.txt"] , {'invalidi': 2, 'domestici': 1, 'altri': 2})
    counter_test_positivi += tester_fun(Ex7, ["ip3.txt"] , {'invalidi': 1, 'domestici': 1, 'altri': 3})
    counter_test_positivi += tester_fun(Ex7, ["ip4.txt"] , {'invalidi': 1, 'domestici': 1, 'altri': 3})
    counter_test_positivi += tester_fun(Ex7, ["ip5.txt"] , {'invalidi': 3, 'domestici': 0, 'altri': 2})
    
    print('La funzione',Ex7.__name__,'ha superato',counter_test_positivi,'test su',total_tests)
