/***************************************************************************
 *   Copyright (C) 1997-2004 by Murilo Pontes                              *
 *   murilopontes@users.sourceforge.net                                    *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 ***************************************************************************/

#include "common-head.c"

char fone[SIZE];
printf("3/5 -- Internet Service Provider Phone number: ");
gets(fone);


char initstring[SIZE];
printf("4/5 -- Your modem init string (sample: AT&F+GCI=16M1L2W0): ");
gets(initstring);

char porta[SIZE];
printf("5/5 -- Your modem device, without /dev prefix: ");
gets(porta);

FILE *chatrc;
chatrc = fopen ("/etc/ppp/chatrc","w");
fprintf(chatrc,"ABORT 'NO CARRIER'  \n");
fprintf(chatrc,"ABORT 'NO DIALTONE' \n");
fprintf(chatrc,"ABORT 'RING BACK'   \n");
fprintf(chatrc,"ABORT BUSY          \n");
fprintf(chatrc,"ABORT ERROR         \n");
fprintf(chatrc,"''                  \n");
fprintf(chatrc,"%s OK               \n",initstring);
fprintf(chatrc,"ATD%s CONNECT       \n",fone);
fprintf(chatrc,"''                  \n");
fclose(chatrc);

FILE *options;
options = fopen("/etc/ppp/options","w");
fprintf(options,"/dev/%s\n",porta);
fprintf(options,"115200\n");
fprintf(options,"connect '/usr/sbin/chat -v -f /etc/ppp/chatrc'\n");
fprintf(options,"crtscts\n");

#include "common-tail.c"





