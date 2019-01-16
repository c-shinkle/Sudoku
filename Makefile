all: SRC TEST

SRC:
	$(MAKE) -C src 

TEST:
	$(MAKE) -C test

clean:
	$(MAKE) clean -C src
	$(MAKE) clean -C test