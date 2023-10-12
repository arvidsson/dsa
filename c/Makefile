.PHONY: clean

all: linear_search binary_search

linear_search: linear_search.c | bin
	gcc $< -o bin/$@

binary_search: binary_search.c | bin
	gcc $< -o bin/$@

bin:
	mkdir -p $@

clean:
	rm -rf bin

run:
	./bin/linear_search
	./bin/binary_search