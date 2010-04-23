#ifndef CONFDICT_C_H
#define CONFDICT_C_H

/******************************/
/*
   This is the ConfDict C language interface
   mainly for a C-language parser that fills
   in one of these dictionaries.
   Which is why there are no functions to Find
   anything here. Should these Find functions
   be added later, dont forget to change
   this comment
*/


  void DictSetDouble (void*, char*, double);
  void DictSetLLI (void*, char*, long long int);
  void DictSetBool (void*, char*, int);
  void DictSetString (void*, char*, char*);


#endif
