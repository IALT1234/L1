CFLAGS=-g



all: tokenizer



tokenizer.o: tokenizer.c tokenizer.h

	cc -c $< $(CFLAGS)



history.o: history.c history.h tokenizer.h

	cc -c $< $(CFLAGS)



uimain.o: uimain.c tokenizer.h history.h

	cc -c $< $(CFLAGS)



tokenizer: tokenizer.o history.o uimain.o

	cc -o $@ $^ $(CFLAGS)



clean:

	rm -f *.o *.c~ *.h~ *~ *.c# src



run:

	./tokenizer
