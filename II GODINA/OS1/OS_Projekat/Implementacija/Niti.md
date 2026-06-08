Prilikom kreiranja niti potrebno je:  
1. napraviti objekat niti u jezgru  
2. formirati pocetni kontekst niti  
  
Najveci izazov:  
- pravilno postavljanje pocetnog konteksta  
  
---  
  
# Wrapper funkcija  
  
Telo korisnicke niti:  
- ne pokrece se direktno  
  
Umesto toga:  
- poziv korisnicke funkcije se "umotava"  
- u kernel wrapper funkciju  
  
Pocetni kontekst niti postavlja se tako da:  
- izvrsavanje pocne od wrapper funkcije  
  
---  
  
# Pocetni kontekst  
  
Kontekst mora biti postavljen tako da:  
- restauracija konteksta prebaci izvrsavanje  
- tacno na wrapper funkciju  
  
Treba paziti na:  
- pravilno inicijalizovan PC  
- stack pointer  
- registre potrebne za start niti  
  
---  
  
# Pokazivac na korisnicku funkciju  
  
Wrapper funkcija mora nekako dohvatiti:  
- pokazivac na telo korisnicke niti  
  
Postoji vise mogucih resenja:  
- ostavljeno studentu na izbor  
  
---  
  
# Zavrsavanje niti  
  
Wrapper funkcija:  
1. poziva korisnicku funkciju  
2. nakon njenog zavrsetka poziva `thread_exit`  
  
Jer:  
- wrapper nema pozivaoca  
- izvrsavanje ne sme da se vrati iz wrapper funkcije  
  
Ako se nit ranije sama ugasi:  
- `thread_exit` se ne izvrsava ponovo  
  
---  
  
# Rezim rada procesora  
  
Izvrsavanje:  
- wrapper funkcije  
- korisnicke funkcije  
  
odvija se:  
- u korisnickom rezimu rada procesora

Implementacija sistemskih poziva `thread_exit` i `thread_dispatch` ne nosi nikakve posebne teškoće, nakon što je sve do sada rečeno uzeto u obzir i valjano rešeno. Slično važi i za semafore i implementaciju operacija sa njima, o čemu je već dovoljno rečeno na nastavi.