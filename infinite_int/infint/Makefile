TESTS += infint_is_in_alphabet
TESTS += infint_validate
TESTS += infint_parse_bin

#uncomment it to see debug output
#DEFINES += INFINT_PRINTF printf

DBG = -gdwarf-2 -g3

all: data_streamer $(TESTS)

.PHONY: clean

tags: 
	@cscope -bRkf cscope.out
	@ctags -R
	@echo "-I ./" > .clang

%: tests/%.c
	@echo $@
	@mkdir -p tests/bin
	@gcc tests/data_streamer.c tests/$@.c -I/ $(DEFINES) $(DBG) -Wall \
		    -o tests/bin/$@
	@./tests/bin/$@

data_streamer:
	@echo $@
	@mkdir -p tests/bin
	@gcc tests/data_streamer.c tests/data_streamer_test.c $(DBG) -o tests/bin/$@
	@./tests/bin/$@

clean:
	@rm -rf ./tests/bin cscope.out tags .clang
