# search - A Linux commande line tool for file finding

This tool has been developed in June 2021 by **Mohammed D. Belgoumri** as a part of a school assignment for the module *SYC2: Operating Systems2* in *ESI - École Nationale Supérieure d'Informatique - Alger (ex INI)*.

- [search - A Linux commande line tool for file finding](#search---a-linux-commande-line-tool-for-file-finding)
  - [Synopsis](#synopsis)
  - [Description](#description)
  - [Options](#options)

## Synopsis

```sh
search [directory] [options] expression
```

## Description

Prints out a list of all files matching `expression` within directory. If `directory` us unspecified, the working directory is the default.

## Options
  
    -h --help         Print this help text and exit.
    -v --version      Print program version and exit.
    -0                Look only in the `directory`. 
    -1                Look in the directory where its called an its immediate children
    -n                Look in the directory where its called and all its children of depth =< n.
    -r                Look recursively in the directory and its children.
