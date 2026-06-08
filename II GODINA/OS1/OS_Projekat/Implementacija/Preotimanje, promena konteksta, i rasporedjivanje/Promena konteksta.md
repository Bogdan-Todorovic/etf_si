Promena konteksta se obavlja:  
- kada to zahteva funkcionalnost jezgra  
  
Treba je izdvojiti u poseban potprogram:  
  
```c  
void yield(Thread* oldThread, Thread* newThread);  
```  
  
`yield` treba da:  
1. sacuva kontekst stare niti  
2. prebaci se na stek nove niti  
3. restaurira kontekst nove niti  
  
Kontekst se moze cuvati:  
- na steku niti  
- u PCB strukturi  
  
Cuvanje/restauracija konteksta mogu se pisati u asembleru.