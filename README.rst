Line Sort / Line Uniq
=====================

Two simple utilities for line text processing.

lsort
    Sorts each line independently, character-by-character.

    For example::

        $ echo -e "hello\nworld" | lsort
        ehllo
        dlorw

luniq
    Uniqifies line, character-by-character.

    For example::

        $ echo -e "hello hello\nhi" | luniq
        helo helo
        hi

