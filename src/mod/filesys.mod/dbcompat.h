/* 
 * dbcompat.h -- part of filesys.mod
 *   this header file contains old db formats which are
 *   needed or converting old dbs to the new format.
 * 
 * Written for filedb3 by Fabian Knittel <fknittel@gmx.de>
 * 
 * $Id: dbcompat.h,v 1.2 1999/12/21 17:35:16 fabian Exp $
 */
/* 
 * Copyright (C) 1999  Eggheads
 * 
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.
 */

#ifndef _EGG_MOD_FILESYS_DBCOMPAT_H
#define _EGG_MOD_FILESYS_DBCOMPAT_H

/* 
 *    DB entry structures for v1 and v2
 */

/* structure for file database (per directory) */
struct filler1 {
  char xxx[1 + 61 + 301 + 10 + 11 + 61];
  unsigned short int uuu[2];
  time_t ttt[2];
  unsigned int iii[2];
};

typedef struct {
  char version;
  unsigned short int stat;	/* misc */
  time_t timestamp;		/* last time this db was updated */
  char filename[61];
  char desc[301];		/* should be plenty */
  char uploader[10];		/* where this file came from */
  unsigned char flags_req[11];	/* access flags required */
  time_t uploaded;		/* time it was uploaded */
  unsigned int size;		/* file length */
  unsigned short int gots;	/* times the file was downloaded */
  char sharelink[61];		/* points to where? */
  char unused[512 - sizeof(struct filler1)];
} filedb1;

struct filler2 {
  char xxx[1 + 61 + 186 + 81 + 33 + 22 + 61];
  unsigned short int uuu[2];
  time_t ttt[2];
  unsigned int iii[1];
};

typedef struct {
  char version;
  unsigned short int stat;	/* misc */
  time_t timestamp;		/* last time this db was updated */
  char filename[61];
  char desc[186];		/* should be plenty - shrink it, we need
				 * the  space :) */
  char chname[81];		/* channel for chan spec stuff */
  char uploader[33];		/* where this file came from */
  char flags_req[22];		/* access flags required */
  time_t uploaded;		/* time it was uploaded */
  unsigned int size;		/* file length */
  unsigned short int gots;	/* times the file was downloaded */
  char sharelink[61];		/* points to where? */
  char unused[512 - sizeof(struct filler2)];
} filedb2;

/* 
 *    Prototypes
 */

static int convert_old_db(FILE **fdb, char *s);
static int convert_old_files(char *npath, char *s);

#endif				/* _EGG_MOD_FILESYS_DBCOMPAT.H */