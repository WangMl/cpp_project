#pragma once
#define RELEASE_COM(p)   if(p){p->Release();p=NULL;}
#define DELETE_POINT(p)   if(p){delete p;p=NULL;}
#define DELETE_ARRAY(p)    if(p){delete[]p;p=NULL;}

