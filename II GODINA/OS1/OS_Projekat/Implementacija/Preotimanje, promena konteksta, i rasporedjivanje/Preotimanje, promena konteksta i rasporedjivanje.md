
## Glavne teme  
  
- [[Prekidna rutina]]  
- [[Sinhroni prekidi]]
- [[Asinhroni prekidi]]  
- [[Koraci prekidne rutine]]
- [[Promena konteksta]]  
- [[Izvrsavanje jezgra na steku niti]]
- [[Vrste niti]]
- [[Scheduler i spremne niti]]
- [[Algoritam rasporedjivanja]]
- [[Idle nit]]  
  
---  
  
## Osnovna ideja  
  
Procesor koristi:  
- jednu prekidnu rutinu  
- jedan ulaz u jezgro  
- jedan prelaz iz user u kernel mode  
  
Prekidna rutina:  
1. cuva registre  
2. obradjuje uzrok prekida  
3. po potrebi menja nit  
4. restaurira registre  
  
---  
  
## Promena konteksta  
  
Promena konteksta se izvrsava preko:  
  
```c  
void yield(Thread* oldThread, Thread* newThread);  
```  
  
`yield`:  
- cuva stari kontekst  
- prelazi na novi stek  
- restaurira novi kontekst  
  
---  
  
## Scheduler  
  
`Scheduler`:  
- cuva spremne niti  
- bira sledecu nit  
  
Najjednostavniji algoritam:  
- FIFO  
  
---  
  
## Bitne stvari  
  
- asinhroni prekidi zahtevaju cuvanje registara  
- kontekst se moze cuvati na steku ili u PCB-u  
- `SPP` definise povratni rezim rada  
- idle nit radi kada nema spremnih niti