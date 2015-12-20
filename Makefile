default:
	gcc main.c -o sorting

run:
	gcc main.c -o sorting
	./sorting

clean:
	rm -f sorting
	rm -f result.dat