/****************************************************************************
*
*                            Open Watcom Project
*
*    Portions Copyright (c) 1983-2002 Sybase, Inc. All Rights Reserved.
*
*  ========================================================================
*
*    This file contains Original Code and/or Modifications of Original
*    Code as defined in and that are subject to the Sybase Open Watcom
*    Public License version 1.0 (the 'License'). You may not use this file
*    except in compliance with the License. BY USING THIS FILE YOU AGREE TO
*    ALL TERMS AND CONDITIONS OF THE LICENSE. A copy of the License is
*    provided with the Original Code and Modifications, and is also
*    available at www.sybase.com/developer/opensource.
*
*    The Original Code and all software distributed under the License are
*    distributed on an 'AS IS' basis, WITHOUT WARRANTY OF ANY KIND, EITHER
*    EXPRESS OR IMPLIED, AND SYBASE AND ALL CONTRIBUTORS HEREBY DISCLAIM
*    ALL SUCH WARRANTIES, INCLUDING WITHOUT LIMITATION, ANY WARRANTIES OF
*    MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE, QUIET ENJOYMENT OR
*    NON-INFRINGEMENT. Please see the License for the specific language
*    governing rights and limitations under the License.
*
*  ========================================================================
*
* Description:  WHEN YOU FIGURE OUT WHAT THIS FILE DOES, PLEASE
*               DESCRIBE IT HERE!
*
****************************************************************************/


#ifndef _UIEXTRN_H_INCLUDED
#define _UIEXTRN_H_INCLUDED

#include <stdio.h>
#ifndef __TYPES_H_INCLUDED
#include <sys/types.h>
#endif

#define uiwrite(s)      write( UIConHandle, s, strlen( s ) )
#define uiwritec(c)     write( UIConHandle, c, sizeof( c ) - 1 )

extern int              UIConHandle;
extern pid_t            UIProxy;
extern pid_t            UIRemProxy;
extern pid_t            UIPGroup;
extern bool             UIWantShiftChanges;
extern bool             UserForcedTermRefresh;
extern bool             UIDisableShiftChanges;

extern char             *GetTermType( void );
extern void             SetTermType( const char * );

#ifdef __QNX__
extern int              UIConsole;
extern pid_t            UILocalProxy;
extern nid_t            UIConNid;
extern struct _timesel  __far *_SysTime;
#else
extern FILE             *UIConFile;
#endif

#endif
