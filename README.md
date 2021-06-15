# search - A Linux commande line tool for file finding

This tool has been developed in June 2021 by **Mohammed D. Belgoumri** as a part of a school assignment for the module *SYC2: Operating Systems2* in *ESI - École Nationale Supérieure d'Informatique - Alger (ex INI)*.


- [search - A Linux commande line tool for file finding](#search---a-linux-commande-line-tool-for-file-finding)
  - [Description](#description)
  - [Options](#options)

## Description

```sh
search [directory] [options] file
```

If `directory` us unspecified, it will be the current directory by default.

## Options

    -0          Look only in the directory where its called. 
    -1          Look in the directory where its called an its immediate children
    -n          Look in the directory where its called and all its children of depth =< n.
    -r          Look recursively in the directory and its children.
