Kljucne C++ apstrakcije koje se predlazu su sledece:
- `MemoryAllocator`: singleton klasa koja obezbedjuje usluge alokacije i dealokacije memorije kontinualnom alokacijom, kako je opisano u zahtevima.
- `Thread` ili `PCB`: klasa koja apstrakuje nit i cuva njen kontekst, kao i druge potrebne atribute
- `Scheduler`: singleton klasa koja implementira rasporedjivac procesa, tj algoritam rasporedjivanja
- `Console`: singleton klasa koja implementira spregu ka konzoli

Jedan aspekt o kome treba voditi racuna jeste alokacije objekata klasa koje su namenjee za dinamicko instanciranje (Thread, Semaphore kao i druge). Potrebno je da se ovi objekti dinamicki prave i unistavaju u odgovarajucim scenarijima. Predlaze se uvodjenje odgovarajucih statickih operacija posmatranih klasa koje su zaduzene za dinamicko pravljenje i unistavanje njihovih objekata, ili samo za alokaciju prostora za te objekte preklapanjem operatorskih funkcija new i delete za ove klase:

- Staticka alokacije. Unapred, staticki alocirati niz pregradaka za smestanje ovih objekata i voditi evidenciju zauzetih i slobodnih pregradaka pri dinamickoj alokaciji i dealokaciji objekata.
- Dinamicka alokacija. Ovo naprednije fleksibilnije ali i slozenije resenje podrazumeva dinamicku alokaciju nizova koriscenjem alokatora memorije jezgra po potrebi, a potom koriscenje tih nizova kao kod staticke alokacije. Potpuno slobodan niz se moze i dealocirati
Opisanu funkcionalnost alokacije pregradaka i niza dobro je izdvojiti u posebnu klasi i to sablonsku, cime se olaksava njena upotrebna na razlicitim mestima, odnosno klasama.