## ABI
Implementacija prekidne rutine predstavlja implementaciju ABI sloja interfejsa jezgra.

---

## C API
Implementacija sistemskih poziva. 
Ona samo treba da svoje parametre pripremi u odgovarajuce argumente i izvrsi instrukciju sistemskog poziva. 
Ova operacije je identicna za sve i zajednicka za sve pozive, dobro je izdvojiti u jednu funkciju opsteg oblika koja prima potpuno opste argumente i izvrsava instrukciju `ecall`.

---

## C++ API
Ovaj api adaptira ne objekti C API u objektni C++ API 
Apstrakcije jezgra se predstavljaju klasama.