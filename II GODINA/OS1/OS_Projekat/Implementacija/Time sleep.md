omogucava:  
- uspavljivanje niti  
- budjenje nakon zadatog vremena  
  
---  
  
# Organizacija uspavanih niti  
  
Uspavane niti mogu se cuvati:  
- u ulancanoj listi  
  
Lista je uredjena:  
- po vremenu budjenja  
  
---  
  
# Relativno vreme budjenja  
  
Za svaku uspavanu nit cuva se:  
- relativno vreme budjenja  
- u odnosu na prethodni element liste  
  
Vreme se izrazava:  
- u broju perioda tajmera  
  
---  
  
# Znacenje vrednosti  
  
## Prvi element liste  
  
Vrednost predstavlja:  
- vreme do budjenja  
- u odnosu na trenutni trenutak  
  
---  
  
## Ostali elementi  
  
Vrednost predstavlja:  
- vreme budjenja  
- u odnosu na prethodni element  
  
---  
  
## Vrednost 0  
  
Vrednost moze biti:  
- `0`  
  
To znaci:  
- da se nit budi  
- u istom trenutku kao prethodna nit  
  
---  
  
# Prednosti strukture  
  
Mana:  
- umetanje u listu je malo slozenije  
  
Prednost:  
- veoma efikasno azuriranje  
  
---  
  
# Azuriranje pri timer interrupt-u  
  
Na svaku periodu tajmera:  
1. dekrementira se vreme prvog elementa  
2. proverava se da li je postalo `0`  
  
Ako jeste:  
- sve niti sa pocetka liste  
- koje imaju vrednost `0`  
- prebacuju se u red spremnih niti