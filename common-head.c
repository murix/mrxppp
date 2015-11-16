/***************************************************************************
 *   Copyright (C) 1997-2004 by Murilo Pontes                              *
 *   murilopontes@users.sourceforge.net                                    *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 ***************************************************************************/


#include <stdio.h>
#include <stdlib.h>

#define SIZE    100
#define VERSION "MRXPPP-1.9 for pppd-2.4.1 and rp-pppoe-3.5"


int main()
{

printf("\33[1;36m\n");
printf("#################################################################\n");
printf("\n");
printf(" %s\n",VERSION);
printf(" Author   : Murilo Pontes [murilopontes@users.sourceforge.net]\n");
printf(" Homepage : http://murix.sourceforge.net\n");
printf(" License  : GPL version >= 2\n");
printf("\n");
printf("#################################################################\n");
printf("\33[m\n");


char login[SIZE];
printf("1/5 -- Internet Service Provider Login: ");
gets(login);


char senha[SIZE];
printf("2/5 -- Internet Service Provider Password: ");
gets(senha);


