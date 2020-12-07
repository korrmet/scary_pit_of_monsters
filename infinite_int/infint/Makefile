TESTS += infint_is_in_alphabet
TESTS += infint_validate

all: $(TESTS)

.PHONY: clean

infint_validate:
	@echo $@
	@mkdir -p tests/bin
	@gcc tests/$@.c -I/ $(DEFINES) -g -o tests/bin/$@
	@./tests/bin/$@

infint_is_in_alphabet:
	@echo $@
	@mkdir -p tests/bin
	@gcc tests/$@.c -I/ $(DEFINES) -g -o tests/bin/$@
	@./tests/bin/$@

clean:
	@rm -rf ./tests/bin
