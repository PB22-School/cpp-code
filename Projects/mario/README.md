{\rtf1\ansi\ansicpg1252\cocoartf2759
\cocoatextscaling0\cocoaplatform0{\fonttbl\f0\fswiss\fcharset0 Helvetica;}
{\colortbl;\red255\green255\blue255;}
{\*\expandedcolortbl;;}
\margl1440\margr1440\vieww11520\viewh8400\viewkind0
\pard\tx720\tx1440\tx2160\tx2880\tx3600\tx4320\tx5040\tx5760\tx6480\tx7200\tx7920\tx8640\pardirnatural\partightenfactor0

\f0\fs24 \cf0 # Super Mario Bros Clone\
This code is my take on a super mario bros clone.\
\
It's more like a game engine that is used to make super mario bros, it has a working tileset drawer and it can read level data from files.\
\
All in all, I made this project way more complicated than it probably needed to be, and I plan to work on it a little bit more in the near future.\
\
For now the Tileset and Animation Players are the only thing that really work.\
\
The level editor is a little hard to look at so here's a quick explanation:\
\
00 00 00 00 00\
00 00 00 00 00\
00 00 00 00 00\
00 10 24 10 00\
00 00 00 00 00\
00 00 00 00 00\
00 00 00 00 00\
\
The first character relates to the sprite, and the second character is the custom data which can be used for things like object spawn points, making sure a block has a certain item in it, and more. \
The above thing is pretty simplified, be sure to remove the spaces as well.}