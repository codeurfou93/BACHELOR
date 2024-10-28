while True:
    rep=input('Entrez un nombre : ')
    if rep == '':
        break
    rep=int(rep)
    for idx in range(1,11):
        print(f'{rep} X {idx} = {rep*idx}')
print('Fin du programme de multiplication')