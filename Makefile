include Makefile.common
include conf/lab.mk
include conf/user.mk

HANDIN_FILE=/tmp/$(NETID)-$(LAB).tar.gz
SUB_PROJECTS=01-decoder  02-shifter  03-packet  04-mult  example-comb  example-seq

submit: clean
	@echo Packing the code...
	@for s in $(SUB_PROJECTS) ; do make -C $$s clean ; done
	@git tag -f -a lab$(LAB)-handin -m "Lab$(LAB) Handin"
	@rm -rf $(HANDIN_FILE)
	@git archive --format=tar HEAD | gzip > $(HANDIN_FILE)
	@chmod o+r $(HANDIN_FILE)
	@./handin.sh $(HANDIN_FILE)

