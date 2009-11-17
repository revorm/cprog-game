#!/bin/bash
echo `ls {.gitignore,Makefile,game.cpp,libs.mak}` `ls **/{*.{cpp,h},Makefile,.gitignore}` | sed -e 's/ /\n/g' > cprog_game.files
