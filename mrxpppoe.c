/***************************************************************************
 *   Copyright (C) 2003 by Murilo Pontes                                   *
 *   murilopontes@users.sourceforge.net                                        *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 ***************************************************************************/

#include "common-head.c"    

char nic[SIZE];
printf("3/3 -- Ethernet NIC: ");
gets(nic);

FILE *options;
options = fopen ("/etc/ppp/options","w");
fprintf(options,"pty '/usr/sbin/pppoe -I %s -m1412'\n",nic);
//fprintf(options,"pty '/usr/sbin/pppoe -I %s'\n",nic);
//fprintf(options,"mtu 1492\n");
//fprintf(options,"mru 1492\n");

#include "common-tail.c"    

