# `search` - A Linux commande line tool for file finding

# Description

```sh
search [directory] [options] file
```
If `directory` us unspecified, it will be the current directory by default.

# Options

    -0          Look only in the directory where its called. 
    -1          Look in the directory where its called an its immediate children
    -n          Look in the directory where its called and all its children of depth =< n.
    -r          Look recursively in the directory and its children.
