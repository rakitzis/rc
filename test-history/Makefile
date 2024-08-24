all: -p --p \
	ignore_me.test \
	match_me_no_syntax.test \
	match_me_slash_whitespace.test \
	delete_char.test \
	delete_char_stepwise.test \
	insert_char.test \
	insert_char_skip_tabs.test \
	replace_space.test \
	append_char.test \
	truncate_and_append.test \
	skip_match.test

ignore_me.test: force
	@cp $(@:.test=) $@
	history=$@ ./-p | cmp -n `sed 1q $@ | wc -c` - $@
	@rm $@

match_me_no_syntax.test \
match_me_slash_whitespace.test: force
	@cp $(@:.test=) $@
	history=$@ ./-p > $(@:.test=.out) && sed -n 2p $@ | cmp - $(@:.test=.out)
	@rm $@ $(@:.test=.out)

delete_char.test \
delete_char_stepwise.test \
insert_char.test \
insert_char_skip_tabs.test \
replace_space.test \
append_char.test \
truncate_and_append.test \
skip_match.test: force
	@cp $(@:.test=) $@
	sed -n -e /EOF/q -e 1d -e p $@ | history=$@ ./--p >$(@:.test=.out) 2>/dev/null && sed 1q $@ | cmp - $(@:.test=.out)
	@rm $@ $(@:.test=.out)

-p --p: ../history
	cp ../history ./$@

force:
