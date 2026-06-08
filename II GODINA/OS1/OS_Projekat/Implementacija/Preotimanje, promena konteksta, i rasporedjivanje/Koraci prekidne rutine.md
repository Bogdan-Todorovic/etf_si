## Korak 1  
  
Prelazak na:  
- sistemski deo steka tekuce niti  
  
Zatim:  
- cuvanje registara  
  
U opstijem slucaju:  
- cuvaju se svi registri.  
  
---  
  
## Korak 2  
  
Obrada uzroka prekida:  
- sistemski poziv  
- spoljasnji prekid  
- izuzetak  
  
Tokom obrade moze doci do:  
- promene tekuce niti  
- promene konteksta  
- promene steka  

Korak 2 je najbolje izdvojiti u poseban C/C++ potprogram.  
  
On treba da izvrsi:  
- razgranati skok na obradu odgovarajuceg uzroka  
- ukljucujuci i obradu sistemskih poziva  
  
Implementacija moze koristiti:  
- `switch`  
ili  
- niz pokazivaca na funkcije  
  
Elementi niza odgovaraju:  
- kodovima sistemskih poziva
  
---  
  
## Korak 3  
  
Po potrebi:  
- restauracija registara  
  
Zatim:  
- povratak iz prekidne rutine  
  