all: infint_validate

.PHONY: clean

infint_validate:
	@echo $@
	@mkdir -p tests/bin
	@gcc tests/$@.c -I/ -o tests/bin/$@
	@./tests/bin/$@

clean:
	@rm -rf ./tests/bin
