# 🎨 Mastermind in C

Un'implementazione del gioco **Mastermind** in **C**, in cui il giocatore deve indovinare una combinazione di colori generata casualmente.

---

## 🚀 Funzionalità
✅ **Generazione casuale della combinazione da indovinare**  
✅ **Personalizzazione di colori disponibili, lunghezza della combinazione e tentativi**  
✅ **Sistema di punteggio**: colori giusti nel posto giusto e colori giusti nel posto sbagliato  
✅ **Interfaccia testuale interattiva** con un tabellone che mostra lo stato della partita  
✅ **Controllo automatico della vittoria e sconfitta**  

---

## 📦 Installazione e Compilazione

```sh
git clone https://github.com/simonebuccolieri/mastermind-c.git
cd mastermind-c
```
```sh
gcc mastermind.c -o mastermind
```
```sh
./mastermind
```
## 📜 Utilizzo
All'avvio, il programma chiederà di impostare i parametri di gioco:
```
Quanti colori possibili da usare (max 26)?
> 8
Quanti colori da indovinare?
> 4
Quanti tentativi?
> 10
```
Dopo aver impostato il gioco, verrà mostrata una griglia vuota con *, che rappresenta le caselle ancora non tentate:
```
GPS | X | X | X | X | GPG
---------------------------------
[ 0 ]| * | * | * | * | [ 0 ]
[ 0 ]| * | * | * | * | [ 0 ]
...
```
Durante ogni turno, il giocatore inserisce una combinazione di lettere che rappresentano i colori:
```
Inserire la combinazione 4
0: A
1: B
2: C
3: D
```
Il programma aggiornerà il tabellone e mostrerà il numero di colori indovinati e al posto giusto (GPG) e quelli indovinati ma nel posto sbagliato (GPS).

## 🎯 Condizioni di vittoria e sconfitta

- Se il giocatore indovina l'intera sequenza, il programma stampa "Hai vinto!".
- Se finisce i tentativi senza indovinare, il programma stampa "Hai perso!" e rivela la combinazione corretta.
