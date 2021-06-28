# search - A Linux commande line tool for file finding

This tool has been developed in June 2021 by **Mohammed D. Belgoumri** as a part of a school assignment for the module *SYS2: Operating Systems2* in *ESI - École Nationale Supérieure d'Informatique - Alger (ex INI)*.

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

```text
  -h --help           Print this help text and exit.
  -v --version        Print program version and exit.
  -m --modification   Print the date of last modification.
  -d --date           Print the date of creation and that of last use (modification or consultation).
  -s --size           Print the file size (in octets).
  -t --type           Print the file type.
  -p --protection     Print the file protection.
  -n                  Look in the directory where its called and all its children of depth =< n.
  -r                  Look recursively in the directory and its children.
```
