.PHONY:clean
bitmap:bitmap.c
	gcc -o $@ $^
clean:
	rm -f bitmap
