/*
 * mm_alloc.c
 *
 * Stub implementations of the mm_* routines. Remove this comment and provide
 * a summary of your allocator's design here.
 */

#include "mm_alloc.h"

#include <stdlib.h>

/* Your final implementation should comment out this macro. */
#define MM_USE_STUBS
s_block_ptr b1=NULL;

void split_block (s_block_ptr b, size_t s){
  s_block_ptr aw=NULL;
  aw->size=b->size-s;
  aw->next=b->next;
  aw->prev=b;
  b->size=s;
  b->next =aw;
  
  /* void* l=sbrk(0);
  void* v=sbrk(s-b->size);
  if(l==v){
  aw->ptr=(void*)sbrk(0);
  aw->data=(char[])aw->ptr;
  b->size=b->size;
  b=b->fusion(aw);
  sizeof(b->ptr)=s;
  if(brk(b->ptr)==0);
      if(brk(b->ptr)==0);
      awe->next=b->next;
      awe->prev=brk(b->ptr);
      b->next=brk(b->ptr);
      }*/
  
}
s_block_ptr fusion(s_block_ptr b){
  if(b->next!=NULL){
  s_block_ptr da=b->next;
  }else{
    da=extend_block(b->next,b->size);
  }
  if(da->free==0){
    b->size=b->size+da->size;
    if(da->next!=NULL){
    da->next->prev=b;
    }
    b->next=da->next;
    free(da);
    return b;
  }else{
    return NULL;
  }
  // size_t g=0;
  /*while(da->next!=NULL){
    g=da->size;
    da=da->next;
    }
    while(da->prev!=NULL)da=da->prev;
    delete (da);
    while(tes->next!=NULL){
    tes=tes->next;
    }
    tes->next=(s_block_ptr)sbrk(0);
    if(tes->next==(s_block_ptr)sbrk(g)){
    b->prev=tes;
    while(tes->prev!=NULL){
    tes=tes->prev;
    }
    b1=tes;
    delete (tes);
    return b1;
    }else{
    return NULL;
    }*/
}
s_block_ptr get_block (void *p){
  s_block_ptr ay=b1;
  while(ay->ptr!=p&&ay->next!=NULL){
    ay=ay->next;
  }
  return ay;
}
s_block_ptr extend_heap (s_block_ptr last , size_t s){
  s_block_ptr f=(s_block_ptr)sbrk(0);
  f->prev=last;
  last->next=f;
  if(sbrk(s)<0){
    return NULL;
    // f->data=(char[])f->ptr;
    
  }else{
    f->size=s;
    f->next=NULL;
    f->free=0;
    return f;
  }
}
void* mm_malloc(size_t size)
{
#ifdef MM_USE_STUBS
  if(b1==NULL){
    b1=(s_block_ptr)sbrk(size);
    b1->next=NULL;
    b1->prev=NULL;
    b1->size=size;
    b1->free=1;
    return b1;
  }else{
    s_block_ptr h=(s_block_ptr) extend_heap(b1,size);
  if(h!=NULL){
    h->free=1;
    b1=h;
    free(h);
    return b1;
  }else{
    free(h);
    return b1->next;
  }
}
#else
#error Not implemented.
#endif
}

void* mm_realloc(void* ptr, size_t size)
#else
#error Not implemented.
#endif
}

void mm_free(void* ptr)
{
#ifdef MM_USE_STUBS
  s_block_ptr g=(s_block_ptr)get_block(ptr);
  if(g->next==NULL&&g->prev!=NULL){
    g->prev->next=NULL;
    free(g);
  }else if(g->next!=NULL&&g->prev==NULL){
    g->next->prev=NULL;
    free(g);
  }else if(g->next==NULL&&g->prev){
    free(g);
  }else{
    g->next->prev=g->prev;
    g->prev->next=g->next;
    free (g);
  }

#else
#error Not implemented.
#endif
}

