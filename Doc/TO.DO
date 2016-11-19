
########################################################################
Improve let to use all args as expression.

The expression
    let x=3+4                   (1)
would be equivalent to the expression
    let x = 3 + 4               (2)

A simple way would be to concatenate all arguments and to parse
one string as is done today.

With this change the old assignment form
    let x 'expression'          (3)
would have to be abandonded because there is no way to distinguish between
    let 2+ 3                    (4)
and
    let x '3+4'                 (5)

########################################################################
