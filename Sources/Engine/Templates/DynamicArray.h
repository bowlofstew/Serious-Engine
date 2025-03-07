/* Copyright (c) 2002-2012 Croteam Ltd. All rights reserved. */

#ifndef SE_INCL_DYNAMICARRAY_H
#define SE_INCL_DYNAMICARRAY_H
#ifdef PRAGMA_ONCE
  #pragma once
#endif

#include <Engine/Base/Lists.h>

/*
 * Template class for array with dynamic allocation of objects.
 */
template<class Type>
class CDynamicArray {
public:
  CListHead da_BlocksList;  // list of allocated memory blocks
  Type **da_Pointers;       // array of object pointers
  INDEX da_Count;           // number of objects
#if CHECKARRAYLOCKING
  INDEX da_LockCt;          // lock counter for getting indices
#endif

  /* Grow pointer array by a given number of indices. */
  void GrowPointers(INDEX iCount);
  /* Shrink pointer array by a given number of indices. */
  void ShrinkPointers(INDEX iCount);
  /* Allocate a new memory block. */
  Type *AllocBlock(INDEX iCount);
  /* Get index of an object from it's pointer without locking. */
  INDEX GetIndex(Type *ptMember);
public:
  /* Default constructor. */
  CDynamicArray(void);
  /* Copy constructor. */
  CDynamicArray(CDynamicArray<Type> &daOriginal);
  /* Destructor -- frees all memory. */
  ~CDynamicArray(void);

  /* Create a given number of new objects. */
  Type *New(INDEX iCount = 1);
  /* Destroy a given member. */
  void Delete(Type *ptObject);
  /* Destroy all objects, and reset the array to initial (empty) state. */
  void Clear(void);

  /* Get pointer to a object from it's index. */
  Type *Pointer(INDEX iObject);
  const Type *Pointer(INDEX iObject) const;
  /* Random access operator. */
  inline Type &operator[](INDEX iObject);
  inline const Type &operator[](INDEX iObject) const;
  /* Assignment operator. */
  CDynamicArray<Type> &operator=(CDynamicArray<Type> &arOriginal);
  /* Move all elements of another array into this one. */
  void MoveArray(CDynamicArray<Type> &arOther);

  /* Lock for getting indices. */
  void Lock(void);
  /* Unlock after getting indices. */
  void Unlock(void);
  /* Get index of a object from it's pointer. */
  INDEX Index(Type *ptObject);
  /* Get number of objects in array. */
  INDEX Count(void) const;
};


#endif  /* include-once check. */

