DEFINES += -DINFINT_PERR_ENABLE
DEFINES += -DINFINT_PWRN_ENABLE
DEFINES += -DINFINT_PMSS_ENABLE
DEFINES += -DINFINT_PDBG_ENABLE

all: infint_validate

.PHONY: clean

infint_validate:
	@echo $@
	@mkdir -p tests/bin
	@gcc tests/$@.c -I/ $(DEFINES) -g -o tests/bin/$@
	@./tests/bin/$@

clean:
	@rm -rf ./tests/bin
