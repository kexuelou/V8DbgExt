#!/usr/bin/env python

#
# v8utils.py output_file
#
# Emits v8dbg constants stored in libv8_base.a in a format suitable for the V8
# ustack helper.
#

import re
import subprocess
import sys
import errno
import collections


if len(sys.argv) != 2:
  print "usage: v8utils.py outfile"
  sys.exit(2);

outfile = file(sys.argv[1], 'w');
value = re.compile('([0-9a-fA-F]{8}|[0-9a-fA-F]{16}) <(.*)>:');
v8dbgtype = re.compile('^_V8DBG_TYPE.*$')
v8dbgframe = re.compile('^_V8DBG_FRAMETYPE.*$')
numpattern = re.compile('0x[0-9a-fA-F]{2} $');
octets = 4

dbgtypedic = {}
dbgframetypedic = {}

outfile.write("""
/*
 * File automatically generated . Do not edit.
 */

#ifndef V8_CONSTANTS_UTIL_H
#define V8_CONSTANTS_UTIL_H

#include "v8constants.h"

""");

with open("v8constants.h", "r") as ins:
  for line in ins:
    type = line[8:]
    #print type
    #looking for _V8DBG_TYPE_XXX
    match = v8dbgtype.match(type)
    if match != None:
      #print type
      #outfile.write("%s" % type);
      #outfile.write("%s" % match.group(1));
      v8typedef = type.split()
      dbgtypedic[v8typedef[1]] = v8typedef[0]

    #looking for _V8DBG_FRAMETYPE_XXX
    match = v8dbgframe.match(type)
    if match != None:
      #print type
      #outfile.write("%s" % type);
      #outfile.write("%s" % match.group(1));
      v8frametypedef = type.split()
      dbgframetypedic[v8frametypedef[1]] = v8frametypedef[0]

odtype = collections.OrderedDict(sorted(dbgtypedic.items()))

#Type definition for V8 Object type
outfile.write("""
/* 
*Type definition for V8 Object type
*/
/*
typedef enum {
""");

numTypes = len(odtype)
i = 0;
for key, value in odtype.items():
  i += 1;
  if i == numTypes:
    outfile.write("    %s = %s\n" % (value, key));
  else:
    outfile.write("    %s = %s,\n" % (value, key));

outfile.write("""
} V8_OBJECT_TYPE;
*/
""");

#V8 Object type MAP
outfile.write("""
/* 
*Type handle map for V8 Object type
*/
#define V8_OBJECT_TYPE_MAP(XX)    \\
""");

for key, value in odtype.items():
  outfile.write("  XX(")
  outfile.write(value)
  outfile.write(", ")
  objtype = value.split("__")
  outfile.write(objtype[1])
  outfile.write(")")
  outfile.write("\t\t\t\\\n");

#Type definition for V8 frame type
odtype.clear()
odtype = collections.OrderedDict(sorted(dbgframetypedic.items()))
outfile.write("""

/* 
*Type definition for V8 frame type
*/
/*
typedef enum {
""");

numFrameTypes = len(odtype)
i = 0;
for key, value in odtype.items():
  i += 1;
  if i == numFrameTypes:
    outfile.write("    %s = %s\n" % (value, key));
  else:
    outfile.write("    %s = %s,\n" % (value, key));

outfile.write("""
} V8_FRAME_TYPE;
*/
""");



#V8 FRAME TYPE MAP
outfile.write("""
/* 
*Type handle map for V8 Object type
*/
#define V8_FRAME_TYPE_MAP(XX)    \\
""");


for key, value in odtype.items():
  outfile.write("  XX(")
  outfile.write(value)
  outfile.write(", ")
  objtype = value.split("_")
  outfile.write(objtype[3])
  outfile.write(")")
  outfile.write("\t\t\t\\\n");
  
  
outfile.write("""

#endif /* V8_CONSTANTS_UTIL_H */
""");
outfile.close()