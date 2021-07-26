# search - A Linux commande line tool to find files by name

This tool was initially developed in June 2021 by **Mohammed D. Belgoumri** as a school assignment for the module *SYS2: Operating Systems 2* at [ESI - École Nationale Supérieure d'Informatique - Alger (ex INI)](https://www.esi.dz).

- [search - A Linux commande line tool to find files by name](#search---a-linux-commande-line-tool-to-find-files-by-name)
  - [NAME](#name)
  - [SYNOPSIS](#synopsis)
  - [DESCRIPTION](#description)
    - [ARGUMENTS](#arguments)
    - [OPTIONS](#options)
  - [AUTHOR](#author)

## NAME

`search` - search for files and directories.

## SYNOPSIS

```sh
search [directory] [h | v | [a] [-l | [p] [s] [t] [H] ] [-d <max> | r]] pattern
```

## DESCRIPTION

Prints out the paths of all files and directories matching `pattern` within `directory`.

### ARGUMENTS

```text
directory (optional): The root directory for the search, defaults to the working directory.
pattern (mandatory): A wildcard pattern to match the contents of directory against.
```

### OPTIONS

```text
  -a --all            Do not ignore hidden files an directories.
  -d --depth <max>    Search in directory and its subdirectories up to a depth of max. If -d is not used, max = 0.
  -h --help           Print help message and exit.
  -l --long           Use long output format. (Synonym of -psH).
  -p --permissions    Show access permissions.
  -r --Recursive      Search recursively in directory and its subdirectories.
  -s --size           Show the item size (in bytes).
  -t --type           Show the item type.
  -v --version        Show program version and exit.
  -H --history        Show the dates of creation, last modification and last access.
```

## AUTHOR

Written by Mohammed D. Belgoumri.
