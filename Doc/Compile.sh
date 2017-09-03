
##########################################################################
CC=clang

Compile() {
    local f=$1 cmd
    cmd="${CC} -std=gnu99 -m64 -O3 -DHAVE_CONFIG_H -I. -g -MD -MP -Wall -pedantic -Wextra -W -Wno-unused-parameter -DYYDEBUG=1 -fPIE -fstack-protector -D_FORTIFY_SOURCE=2 -Wno-extended-offsetof -MT ./obj/$f.o -MF .deps/$f.Tpo -c -o ./obj/$f.o $f.c"
    echo $cmd
    $cmd
}

##########################################################################
Compile mksignal
${CC} -std=gnu99 -m64 -O3 -Wall -g -pie -Wl,-z,now,-z,relro -o ./obj/mksignal ./obj/mksignal.o
Compile mkstatval
${CC} -std=gnu99 -m64 -O3 -Wall -g -pie -Wl,-z,now,-z,relro -o ./obj/mkstatval ./obj/mkstatval.o
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
${CC} -std=gnu99 -m64 -O3 -Wall -g -pie -Wl,-z,now,-z,relro -o rc $OBJ

##########################################################################
Compile tripping
${CC} -std=gnu99 -m64 -O3 -Wall -g -pie -Wl,-z,now,-z,relro -o tripping ./obj/tripping.o
##########################################################################

