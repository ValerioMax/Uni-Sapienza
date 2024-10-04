mese = int(input('inserisci numero mese: '))
anno = int(input('inserisci numero anno: '))
if 1 <= mese <= 12:
    if mese < 12:
        mesesuccessivo = int(mese + 1)
        print(mesesuccessivo, anno)
    else:
        annosuccessivo = int(anno + 1)
        print('1', annosuccessivo)
else:
    print('input non valido')
