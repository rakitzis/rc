
##########################################################################
CC=clang



Compile() {
    local file=$1 cmd flags
    flags="-DHAVE_CONFIG_H -I.  -MD -MP -pedantic -Wextra -W -Wno-unused-parameter -DYYDEBUG=1 -fPIE -fstack-protector -D_FORTIFY_SOURCE=2 -Wno-extended-offsetof"

    cmd="${CC} -std=gnu99 -m64 -O3 -Wall -g"
    cmd="${cmd} $flags"
    cmd="${cmd} -MT ./obj/$file.o -MF .deps/$file.Tpo -c -o ./obj/$file.o $file.c"
    echo $cmd
    $cmd
}

Link() {
    local cmd 
    cmd="${CC} -std=gnu99 -m64 -O3 -Wall -g"
    #cmd="${cmd} -pie -Wl,-z,now,-z,relro"
    echo $cmd "$@"
    $cmd "$@"
}

LinkOne() {
    local file=$1
    Link -o ./obj/$file ./obj/$file.o
}


##########################################################################
for f in mksignal mkstatval; do
    Compile $f
    LinkOne $f
done
./obj/mksignal
./obj/mkstatval > statval.h

##########################################################################
byacc -t -v -d -o parse.c parse.y
byacc -t -v -d -P -p calc -o calc.c calc.y

##########################################################################
EDIT=edit-null
SRC="
 addon
 calc
 builtins
 develop
 except
 exec
 fn
 footobar
 getopt
 glob
 glom
 hash
 heredoc
 input
 lex
 list
 main
 match
 nalloc
 open
 parse
 print
 redir
 signal
 status
 tree
 utils
 var
 wait
 walk
 which
 sigmsgs
 $EDIT
 system
"

##########################################################################
OBJ=""
for f in $SRC
do
    Compile $f
    OBJ="$OBJ ./obj/$f.o"
done

##########################################################################
Link -o rc $OBJ

##########################################################################
Compile tripping
LinkOne tripping
##########################################################################

