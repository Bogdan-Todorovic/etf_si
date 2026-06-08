## Osnovna ideja
- Baferisanjem, uvesti logicki neogranicen ili ogranicen bafer, za prihvat znakova sa tastature i prenos znakova na ekran.

## PUTC
- Prilikom obrade sistemskog poziva `putc` znak se smesta u izlazni bafer
	- Ako je pun, nit treba blokirati ili joj odmah vratiti gresku.
- Posebna nit je za potrosaca: uzima znak po znak iz izlaznog bafera i prenosi ga kontroleru konzole
	- Ukoliko je bafer prazan, blokirati ovu nit sve dok se u baferu ne pojavi znak

## Obrada prekida
- Prilikom prekida zbog pritislog tastera tastature ulazni znakovi se citaju sa konzole i smestaju u ulazni bafer sve dok ih ima.
- Ukoliko je bafer pun znakovi se mogu odbaciti ili se ostaviti za kasnije 

## GETC
- U obradi sistemskog poziva `getc` znak se uzima iz ulaznog bafera. 
- Ukoliko je bafer prazan treba nit blokirati

---

Bitno je obezbediti da se ove niti, tj njihovo telo za razliku od korisnickih niti, izvrsava u sistemskom rezimu rada procesora, kako bi one mogle da pristupe registrima hardvera.

## Sinhronizacija
Posebnu paznju zahteva sinhronizacija i blokiranje ovih internih niti i korisnicke niti.
- Za ovu sinhronizaciju mogu se koristiti semafori jezgra. (Nastava)
- 