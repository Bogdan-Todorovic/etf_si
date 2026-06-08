Dovoljno je (predlaze se) jezgro realizovati kao monolitan softver, u smislu dase sav kod jezgra izvrsava u istom adresnom prostoru, u privilegovanom rezimu rada procesora, dok se medjusobni pozivi usluga unutar jezgra realizuju kao najobicniji pozivi potprograma u istom toku kontrole

Arhitektura samog interfejsa jezgra vec je definisana kao slojevita na opisan nacin

Kljucne projektne odluke odnose se na sledece elemente:
- [[Monoprocesni ili multiprocesorski sistem]]
- [[Preotimanje]]
- [[Medjusobno iskljucenje]]
- [[Stek na kom se izvrsava kod jezgra]]
- [[Memorijski kontekst]]

Na kraju zakljucimo da osim samog postupka promene konteksta procesora i obrade sistemskih poziva/prekida/izuzetaka kod jezgra mozemo posmatrati kao standardan, objektno orjentisan softver pisan na jeziku C++. Ukoliko jezgro ne podzava preotimanje tokom svog izvrsavanja, nikakva dodatna sinhronizacija nije potrebna u ovom kode; u suprotnom treba obezbediti sinhornizaciju kako je opisano. Obrada sistemskih poziva/prekida/izuzetaka, kao i sam postupak promene konteksta zahtevaju posebnu paznju.