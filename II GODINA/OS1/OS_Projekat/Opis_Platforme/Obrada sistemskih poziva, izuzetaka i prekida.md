U sistemski rezim rada procesor prelazi instrukcijom softverskog prekida `ecall` izuzetkom ili spoljasnjim prekidom

### Obrada sistemskog poziva ili prekida:
- Vrednost registra `pc` se upisuje u registar `spec`
- U registar `sstatus` upisuju se sledece vrednosti:
	- u bit `SPP` (bit 8) vrednost koja pokazuje iz kog rezima se dogodio skok (0 - korisnicki rezim, 1 - sistemski rezim)
	- u bit `SIE` (bit 1) nulu, cime se maskiraju spoljasnji prekidi
	- u bit `SPIE` (bit 5) prethodnu vrednost bita `SIE`
-  U registar `scause` upisuje se:
	- u bit najvece tezine informacija o tome da li se dogodio spoljasnji prekid ili nije
	- u ostale bite upisuje razlog, sledeca tabela prikazuje moguce razloge
	- ![[Pasted image 20260509160351.png]]
- Registar `stvec` sadrzi oznaku rezima `MODE` (definisan pomocu dva najniza bita) i baznu adresu `BASE` (preostali biti predstavljaju visih 30 bita bazne adrese), vrednost 0 za `MODE` oznacava direktan rezim, procesor skace na adresu `BASE` za instrukciju `ecall` , izuzetke i spoljasnje prekide, dok vrednost 1 oznacava vektorski rezim u kom procesor skace na adresu `BASE` samo za instrukciju `ecall` i izuzetke, dok za spoljasnje prekide skace na adresu dobijenu sabiranje `BASE` i broja datog spoljasenjeg prekida pomnozenog sa 4.

Sistemski registi se citaju pomocu instrukcije `csr`, koja je dostupna samo u sistemskom rezimu

- Povratak iz sistemskog rezima radi sa instrukcijom `sret`, dostupnom samo u sistemskom rezimu.
	- rezim u kojim se prelazi je definisan bitom `SPP`
	- bit `SIE` dobija vrednost bita `SPIE`
	- registar `pc` dobija vrednost `sepc`
- Ostali registri se ne cuvaju hardverski, vec je to odgovornost prekide rutine
- Registar `sip` sadrži informaciju o tome koji zahtevi za prekid su trenutno aktivni. Bit `SSIP` (bit 1) označava da postoji zahtev za softverski prekid. U `SSIP`bit može da se upiše vrednost. Upis jedinice postavlja zahtev za softverskim prekidom, dok upis nule označava da se softverski prekid obradio (ovo svakako treba uraditi nakon obrade prekida). Bit `SEIP` (bit 9) označava da postoji zahtev za spoljašnji hardverski prekid.
- Registar `sie` je registar za maskiranje prekida, pa sadrži informaciju o tome koji prekidi su dozvoljeni. Vrednost ovog registra se uzima u obzir i prilikom izvršavanja u korisničkom režimu. Bit `SSIE` (bit 1) označava da li su dozvoljeni softverski prekidi. Bit `SEIE` (bit 9) označava da li su dozvoljeni spoljašnji hardverski prekidi. Ukoliko se program izvršava u sistemskom režimu i bit `SIE` u registru sstatus ima vrednost 0, vrednost registra sie se ignoriše.
- Prekid od tajmera je realizovan kao softverski prekid. Prekid od tajmera može se prepoznati po vrednosti 1 samo u bitima najmanje i najveće težine u registru` scause`. Tajmer generiše prekid deset puta u sekundi.
- Prekid od konzole je realizovan kao spoljašnji hardverski prekid. Postoji kontroler prekida preko kog se može dobiti informacija o tome koji uređaj je generisao prekid. Za to služi C funkcija` plic_claim` čija je deklaracija data u zaglavlju `hw.h`. Povratna vrednost ove funkcije je broj prekida. Prekid od konzole ima broj `10 (0x0a)`. Nakon obrade prekida, kontroler prekida treba obavestiti da je prekid obrađen i to putem funkcije` plic_complete` čija je deklaracija data u zaglavlju `hw.h`. Jedini parametar ove funkcije je broj prekida koji je obrađen.