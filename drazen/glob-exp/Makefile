N=6

rc_script = glob-exp.rc
sh_script = glob-exp.sh

rc-all :
	time rc $(rc_script) --all $N

sh-all :
	time bash $(sh_script) --all $N

rc-ALL :
	time rc $(rc_script) --if $N
	time rc $(rc_script) --switch $N
	time rc $(rc_script) --file $N

sh-ALL :
	time bash $(sh_script) --case $N
	time bash $(sh_script) --file $N
