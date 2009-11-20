#!/bin/bash
echo `ls {.gitignore,Makefile,*.{cpp,h},libs.mak}` `ls **/{*.{cpp,h},Makefile}` | sed -e 's/ /\n/g' > cprog_game.files
