Spremne niti mogu se organizovati:  
- kao ulancana lista  
- ili druga dinamicka struktura  
  
Za to moze biti odgovorna klasa:  
  
```cpp  
Scheduler  
```  
  
---  
  
# Implementacija ulanacavanja  
  
Efikasnije resenje:  
- pokazivace za ulanacavanje drzati unutar same strukture niti  
  
Ali treba paziti:  
- da isti pokazivaci ne budu istovremeno korisceni u vise struktura