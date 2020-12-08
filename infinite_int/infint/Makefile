TESTS += infint_is_in_alphabet
TESTS += infint_validate
TESTS += infint_parse_bin

#uncomment it to see debug output
#DEFINES += INFINT_PRINTF printf

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

infint_parse_bin:
	@echo $@
	@mkdir -p tests/bin
	@gcc tests/$@.c -I/ $(DEFINES) -g -o tests/bin/$@
	@./tests/bin/$@

clean:
	@rm -rf ./tests/bin
