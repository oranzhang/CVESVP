#ifndef CVESVP_F0_H
#define CVESVP_F0_H

#include <CVEDSP2.h>
#include "Misc/List_Int.h"

#include <RUtil2.h>

#if 0
#include "_F0.h"
#include "Iterator/_F0Iterlyzer.h"
#endif

#ifdef __CSVP_Install
#define _RTAddress "CVESVP/_F0.h"
#else
#define _RTAddress "_F0.h"
#endif

#define _ClassName _
#define _Attr 1

#define _T1 Float
#include <RUtil2/Core/RTemplate.h>

#define _T1 Double
#include <RUtil2/Core/RTemplate.h>

//-----
#include <RUtil2.h>

#ifdef __CSVP_Install
#define _RTAddress "CVESVP/Iterator/_F0Iterlyzer.h"
#else
#define _RTAddress "Iterator/_F0Iterlyzer.h"
#endif

#define _ClassName _F0Iterlyzer
#define _Attr 1

#define _T1 Float
#include <RUtil2/Core/RTemplate.h>

#define _T1 Double
#include <RUtil2/Core/RTemplate.h>

#endif

