## On Linux
## ./configure --with-addon
## On Mac
## ./configure --with-addon --with-edit=edit
function qMacOS {
    local s
    s=$(uname -s)
    case $s in
    (Darwin) return 0 ;;
    (*) return 1;;
    esac
}

##########################################################################
if clang --version; then
    CC=clang
else
    CC=gcc
fi
objDir=obj
test -d $objDir || mkdir $objDir


##########################################################################
CC_CommonFlags="-std=gnu99 -m64 -O3 -Wall -g"
CC_CompileFlags="-DHAVE_CONFIG_H -I.  -MD -MP -pedantic -Wextra -W -Wno-unused-parameter -DYYDEBUG=1 -fPIE -fstack-protector -D_FORTIFY_SOURCE=2 -Wno-extended-offsetof"
s=$(uname -s)
case $s in
(Darwin) CC_LinkFlags="" ;;                          ## MacOS
(*)      CC_LinkFlags="-pie -Wl,-z,now,-z,relro" ;;  ## Linux
esac

##########################################################################
Compile() {
    local file=$1 cmd

    cmd="${CC} ${CC_CommonFlags} ${CC_CompileFlags}"
    cmd="${cmd} -MT ./$objDir/$file.o -MF .deps/$file.Tpo -c -o ./$objDir/$file.o $file.c"
    echo $cmd
    $cmd
}

Link() {
    local cmd
    cmd="${CC} ${CC_CommonFlags} ${CC_LinkFlags}"
    echo $cmd "$@"
    $cmd "$@"
}

LinkOne() {
    local file=$1
    Link -o ./$objDir/$file ./$objDir/$file.o
}


##########################################################################
for f in mksignal mkstatval; do
    Compile $f
    LinkOne $f
done
./$objDir/mksignal
./$objDir/mkstatval > statval.h

##########################################################################
yaccOpts="-t -v -d"
byacc $yaccOpts -o parse.c parse.y
byacc $yaccOpts -P -p calc -o calc.c calc.y

##########################################################################
if qMacOS; then
    Edit=edit
    EditLibs="-ledit -ltermcap"
else
    Edit=null
    EditLibs=""
fi

##########################################################################
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
 edit-$Edit
 system
"

##########################################################################
OBJ=""
for f in $SRC
do
    Compile $f
    OBJ="$OBJ ./$objDir/$f.o"
done

##########################################################################
Link -o rc $OBJ $EditLibs

##########################################################################
file=tripping
Compile $file
LinkOne $file
##########################################################################

