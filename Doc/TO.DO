########################################################################
Improve calc to use all args as expression.

The expression
    calc x=3+4                   (1)
would be equivalent to the expression
    calc x = 3 + 4               (2)

A simple way would be to concatenate all arguments and to parse
one string as is done today.

With this change the old assignment form
    calc x 'expression'          (3)
would have to be abandonded because there is no way to distinguish
between (4) and (5):
    calc '2+' '3'                (4)
and
    calc 'x' '3+4'               (5)

########################################################################
DONE
