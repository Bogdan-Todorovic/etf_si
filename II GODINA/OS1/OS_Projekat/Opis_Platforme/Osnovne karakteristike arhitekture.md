- 64-bitni troadresni RISC procesor sa load/store arhitekturom. Svi registri su 64 bitni
- Adresibilna jedinica je bajt. Podrazumevano je nizi bajt na nizoj adresi (little endian).
- Instrukcije su sirine 32 bita
## Dva rezima rada
- Korisnicki
- Sistemski
## Registri dostupni i u korisnickom i u sistemskom rezimu rada
- sp : pokazivac na stek
- ra : registar za povratnu adresu pozvanog potprogama
- s0..s11 : registri opste namene ciju ce vrednost ocuvati pozvani potprogram
- a0..a7 : registri za prenos argumenata i povratne vrednosti potprograma
- t0..t6 : privremeni registri
- zero : registar ozicen na nulu (upis nema efekat, citanje uvek vraca 0)
- gp i tp su registri posebne namene

## Registri dostupni samo u sistemskom rezimu
- sstatus : statusni registar
- sip i sie : registri za prekide
- sscratch : privremeni registar
- sepc : sacuvana vrednost registra pc u korisnickom rezimu
- scause : opis razloga za prelazak u sistemski rezim
- stvec : adresa prekidne rutine, poravnata na 4 bajta
- Registar pc ukazuje na tekucu instrukciju i nije direktno dostupan programu za upis

## Stek
- raste ka nizim adresama
- sp pokazuje na poslednju zauzetu lokaciju
- vrednost registra sp mora biti deljiva sa 16

Nema direktnu podrsku za aritmetiku u pokretnom zarezu, pa stoga ni u jezgru ni u korisnckom programu ne treba koristit ovu aritmetiku