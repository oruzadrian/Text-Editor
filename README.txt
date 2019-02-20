Mi-am facut o lista dublu inlantuita si am memorat in ea caracterele din fisierul de intrare(date). Din fisierul operatii imi citesc numarul de operatii si operatia curenta.
Apoi compar operatia curenta cu toate operatiile posibile si fac instructiunile corespunzatoare.Pentru usurinta am lucrat cu un cursor int si cu unul tip lista.
In general am luat string-uri de lungimi mici in cazul operatiilor sau cuvintele pe care le inseram(15 sau 30).

Move
 	 Am fost nevoit sa lucrez pe mai multe cazuri(in care depaseste si in care nu depaseste).
  	In move imi modific valorile pentru cursor_int si cursor(tip lista).

Insert
  	La fel am avut diferite cazuri si am avut o problema daca ma aflam pe ultima pozitie(cu cursorul int adica dupa ultima litera din lista) asa ca in loc sa fac move -5 am facut facut cursor_int 0 si cursor sa fie pe prima litera din sir.Apoi am mutat(numar de caractere -5).
	Cursorul int si nr de caractere le-am marit in main, pentru a ma ajuta mai tarziu.

Backspace
	Este o eliminare simpla a unui element dintr o lista in functie de pozitia acestuia.

Del
	Pentru cazul in care n>nr caractere si curssorul int este 0 am ales sa-mi fac lungimea listei 0 dar am pastrat capul, pentru a putea folosi insert(am adaugat in insert un nou caz).
	In cazul in care n depaseste nr de caractere ramase in lista de la pozitia curenta am ales sa stearga tot.

Copy
	Functia copy imi creeaza o noua lista(imi iau un nou cap de lista)
Paste(foloseste insert)
	Am ales sa nu fac o functie paste si sa lucrez cu aceasta direct in main ca sa-mi fie mai usor. Am luat un nou string numit PASTEE si am introdus in el caracterele  din lista creata pentru ca sa imi apelez insert(PASTEE).Am folosit alocarea dinamica pentru a nu face risipa de memorie.

Undo
	Cu undo am incercat sa anulez ultima operatie facuta(ex pt move n operatia ce il anuleaza -n sau pentru insert string operatia ce anuleaza este backspace de strlen(string)-ori) si pentru asta am memorat ultima operatie facuta(ult_op).

Redo
	Face ceva doar daca are un Undo inainte si practic reface ultima operatie. Pentru asta am ajut nevoie de penultima operatie facuta(penult_op).