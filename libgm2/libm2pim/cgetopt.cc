/* cgetopt.cc provide access to the C getopt library.

Copyright (C) 2009-2022 Free Software Foundation, Inc.
Contributed by Gaius Mulley <gaius.mulley@southwales.ac.uk>.

This file is part of GNU Modula-2.

GNU Modula-2 is free software; you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation; either version 3, or (at your option)
any later version.

GNU Modula-2 is distributed in the hope that it will be useful, but
WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
General Public License for more details.

Under Section 7 of GPL version 3, you are granted additional
permissions described in the GCC Runtime Library Exception, version
3.1, as published by the Free Software Foundation.

You should have received a copy of the GNU General Public License and
a copy of the GCC Runtime Library Exception along with this program;
see the files COPYING3 and COPYING.RUNTIME respectively.  If not, see
<http://www.gnu.org/licenses/>.  */

#include <unistd.h>
#include <stdlib.h>
#include <getopt.h>
#include <m2rts.h>

extern "C" {char *cgetopt_optarg;}
extern "C" {int cgetopt_optind;}
extern "C" {int cgetopt_opterr;}
extern "C" {int cgetopt_optopt;}

extern "C" char
cgetopt_getopt (int argc, char *argv[], char *optstring)
{
  char r = getopt (argc, argv, optstring);

  cgetopt_optarg = optarg;
  cgetopt_optind = optind;
  cgetopt_opterr = opterr;
  cgetopt_optopt = optopt;

  if (r == (char)-1)
    return (char)0;
  return r;
}

extern "C" int
cgetopt_getopt_long (int argc, char *argv[], char *optstring,
                    const struct option *longopts, int *longindex)
{
  int r = getopt_long (argc, argv, optstring, longopts, longindex);

  cgetopt_optarg = optarg;
  cgetopt_optind = optind;
  cgetopt_opterr = opterr;
  cgetopt_optopt = optopt;

  return r;
}

extern "C" int
cgetopt_getopt_long_only (int argc, char *argv[], char *optstring,
                         const struct option *longopts, int *longindex)
{
  int r = getopt_long_only (argc, argv, optstring, longopts, longindex);

  cgetopt_optarg = optarg;
  cgetopt_optind = optind;
  cgetopt_opterr = opterr;
  cgetopt_optopt = optopt;

  return r;
}

typedef struct cgetopt_Options_s
{
  struct option *cinfo;
  unsigned int high;
} cgetopt_Options;

/* InitOptions a constructor for Options.  */

extern "C" cgetopt_Options *
cgetopt_InitOptions (void)
{
  cgetopt_Options *o = (cgetopt_Options *)malloc (sizeof (cgetopt_Options));
  o->cinfo = (struct option *)malloc (sizeof (struct option));
  o->high = 0;
  return o;
}

/* KillOptions a deconstructor for Options.  Returns NULL after freeing
   up all allocated memory associated with o.  */

extern "C" cgetopt_Options *
cgetopt_KillOptions (cgetopt_Options *o)
{
  free (o->cinfo);
  free (o);
  return NULL;
}

/* SetOption set option[index] with {name, has_arg, flag, val}.  */

extern "C" void
cgetopt_SetOption (cgetopt_Options *o, unsigned int index, char *name,
 		   unsigned int has_arg, int *flag, int val)
{
  if (index > o->high)
    {
      o->cinfo
          = (struct option *)malloc (sizeof (struct option) * (index + 1));
      o->high = index + 1;
    }
  o->cinfo[index].name = name;
  o->cinfo[index].has_arg = has_arg;
  o->cinfo[index].flag = flag;
  o->cinfo[index].val = val;
}

/* GetLongOptionArray returns a pointer to the C array containing all
   long options.  */

extern "C" struct option *
cgetopt_GetLongOptionArray (cgetopt_Options *o)
{
  return o->cinfo;
}

/* GNU Modula-2 linking fodder.  */

extern "C" void
_M2_cgetopt_init (int, char *argv[], char *env[])
{
}

extern "C" void
_M2_cgetopt_fini (int, char *argv[], char *env[])
{
}

extern "C" void
_M2_cgetopt_dep (void)
{
}

struct _M2_cgetopt_ctor { _M2_cgetopt_ctor (); } _M2_cgetopt_ctor;

_M2_cgetopt_ctor::_M2_cgetopt_ctor (void)
{
  M2RTS_RegisterModule ("cgetopt", _M2_cgetopt_init, _M2_cgetopt_fini,
			_M2_cgetopt_dep);
}
