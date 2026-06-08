## Load/store instrukcije:  
  
```asm  
l{b|h|w|d} reg, offset(reg)  
s{b|h|w|d} reg, offset(reg)  
```  
  
- sufiks `b`, `h`, `w` i `d` definiše širinu podatka koji se prenosi: `1B`, `2B`, `4B` i `8B`, respektivno;  
- `offset(reg)`: definiše adresu podatka - registarsko indirektno adresiranje sa označenim pomerajem širine 12 bita.  
  
---  
  
## call: pseudoinstrukcija za poziv funkcije:  
  
- operand je ime funkcije (npr. `call f`);  
- prevodilac prevodi pseudoinstrukciju u niz instrukcija koje vrše skok na funkciju;  
- obično se prevodi u relativan skok (u odnosu na registar `pc`) pomoću instrukcija `auipc` i `jalr`;  
  
Instrukcija `auipc`:  
- vrednost registra `pc` sabira sa zadatim označenim pomerajem  
- dobijenu vrednost upisuje u odredišni registar  
  
Instrukcija `jalr`:  
- vrši skok na adresu koja je zapisana u odredišnom registru  
- koristi opcioni označeni pomeraj  
- prilikom skoka pamti povratnu adresu sledeće instrukcije u registar `ra`  
  
---  
  
## csr: instrukcije za pristup sistemskim registrima:  
  
### csrr  
  
```asm  
csrr reg, sreg  
```  
  
- upis vrednosti sistemskog registra `sreg` u korisnički registar `reg`  
  
### csrw  
  
```asm  
csrw reg, sreg  
```  
  
- upis vrednosti korisničkog registra `reg` u sistemski registar `sreg`  
  
### csrrw  
  
```asm  
csrrw reg1, sreg, reg2  
```  
  
- u sistemski registar `sreg` se upisuje podatak iz korisničkog registra `reg2`  
- stara vrednost registra `sreg` se upisuje u korisnički registar `reg1`  
  
---  
  
## Asemblerski fajlovi  
  
- asemblerski kôd se može pisati u posebnim fajlovima  
- asemblerski fajl mora imati ekstenziju `.S`  
- u ovakvom fajlu kôd se piše isto kao primer asemblerskog kôda unutar C funkcije datog u narednom odeljku  
  
---  
  
## ASM blokovi u C/C++  
  
- pojedinačne instrukcije se mogu ugraditi u C/C++ kôd pomoću asemblerskog bloka