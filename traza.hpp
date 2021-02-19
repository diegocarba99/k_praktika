#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Definitu token motak. 
      R hasierak erreserbatua adierazten du eta 
      T hasierak gainerako tokenak.
      Gehiago behar badira, gehitu hemen.
   */
   enum yytokentype {

     RPROGRAM = 258,
     RIF = 259,
     RWHILE = 260,
     RFOREVER = 261,
     RDO = 262,
     RPROC = 263,
     RUNTIL = 264,
     RELSE = 265,
     RSKIP = 266,
     REXIT = 267,
     RPRINTLN = 268,
     RREAD = 269,
     RINT = 270,
     RFLOAT = 271,

     TMUL = 272,
     TASSIG = 273,
     TADD = 274,
     TSUB = 275,
     TDIV = 276,
     TCEQ = 277,
     TCGT = 278,
     TCLT = 279,
     TCGE = 280,
     TCLE = 281,
     TCNE = 282,
     TSEMIC = 283,
     TCOMMA = 284,
     TLPAREN = 285,
     TRPAREN = 286,
     TLBRACE = 287,
     TRBRACE = 288,
     TOUTPARAM = 289,
     TINOUTPARAM = 290,

     TID = 291,
     TFLOAT = 292,
     TINTEGER = 293 
   };
#endif
