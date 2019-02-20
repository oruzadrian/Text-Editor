build: editor
editor: editor.o
	gcc editor.o -o editor
editor.o: editor.c
	gcc -c editor.c
clean:
	rm -f editor editor.o
