/***************************************************************************
 *   Copyright (C) 1997-2004 by Murilo Pontes                              *
 *   murilopontes@users.sourceforge.net                                    *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 ***************************************************************************/


fprintf(options,"defaultroute\n");
fprintf(options,"debug\n");
fprintf(options,"holdoff 2\n");
fprintf(options,"maxfail 0\n");
fprintf(options,"persist\n");
fprintf(options,"receive-all\n");
fprintf(options,"usepeerdns\n");
fprintf(options,"hide-password\n");
fprintf(options,"user %s\n",login);
fclose(options);


FILE *ipup;
ipup=fopen("/etc/ppp/ip-up","w");
fprintf(ipup,"#!/bin/sh\n");
fprintf(ipup,"sh /etc/murix/service_bind.sh\n");
fprintf(ipup,"sh /etc/murix/service_iptables+iproute2.sh\n");
fclose(ipup);
system("chmod 755 /etc/ppp/ip-up");

FILE *ipdown;
ipdown=fopen("/etc/ppp/ip-down","w");
fprintf(ipdown,"#!/bin/sh\n");
fprintf(ipdown,"\n");
fclose(ipdown);
system("chmod 755 /etc/ppp/ip-down");

FILE *authup;
authup=fopen("/etc/ppp/auth-up","w");
fprintf(authup,"#!/bin/sh\n");
fprintf(authup,"\n");
fclose(authup);
system("chmod 755 /etc/ppp/auth-up");

FILE *authdown;
authdown=fopen("/etc/ppp/auth-down","w");
fprintf(authdown,"#!/bin/sh\n");
fprintf(authdown,"\n");
fclose(authdown);
system("chmod 755 /etc/ppp/auth-down");

FILE *papsecrets;
papsecrets = fopen ("/etc/ppp/pap-secrets","w");
fprintf(papsecrets,"%s * %s\n",login,senha);
fclose(papsecrets);

FILE *chapsecrets;
chapsecrets = fopen ("/etc/ppp/chap-secrets","w");
fprintf(chapsecrets,"%s * %s\n",login,senha);
fclose(chapsecrets);

printf("\n\n");
printf("\33[1;33mWARNING: pppd requires root login\33[m\n\n");
printf("\33[1;32mTo connect type in shell:\33[m\n");
printf("\33[1;32mpppd\33[m\n\n");
printf("\33[1;31mTo disconnect type in shell:\33[m\n");
printf("\33[1;31mkillall pppd\33[m\n\n");

return 0;
}//main

