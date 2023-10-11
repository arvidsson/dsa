.PHONY: clean

all: linear_search

linear_search: linear_search.c | bin
	gcc $< -o bin/$@

bin:
	mkdir -p $@

clean:
	rm -rf bin