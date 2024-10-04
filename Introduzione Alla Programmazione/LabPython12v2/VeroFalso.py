def veroFalso():
    ##############################################################################################
    # Modificare il valore del return elencando le lettere delle domande che valutate essere vere
    # Ad esempio, se pensate che B, C, ed F siano vere la funzione deve restituire 'BCF'
    ##############################################################################################

    print("Siano dati i due numerali a 16 bit:\n a=1011110010001000 e\n b=1100100010101001\n") 

    A="In eccesso 2^15 a>b"
    B="In complemento a 2 sia a che b sono negativi"
    C="In binario puro a è un numero < 10^6"
    D="Se a e b rappresentano numeri in virgola mobile, un bit per il segno (1 positivo), 5 bit per l'esponente in complemento a 4 e i restanti 11 bit per la parte frazionaria della mantissa allora a>b"
    E="Usando la notazione descritta in D, l'errore assoluto massimo che si può commettere rappresentando un numero dell'ordine di grandezza di a è minore di 50 (in base 10)\n----"
    F='Per rappresentare un carattere ASCII bastano 7 bit'
    G="UTF-8 usa un numero costante di bit per rappresentare un carattere"
    H="Per motivi di efficienza l'unità logica aritimetica, ALU, è posta all'esterno del processore"


    for i in range(ord('A'),ord('I')):
        print(chr(i)+')',eval(chr(i)),end='\n\n')

    return 'ABCDEFGH'

veroFalso()
print('**** Modificare il valore restituito dalla funzione ****')
