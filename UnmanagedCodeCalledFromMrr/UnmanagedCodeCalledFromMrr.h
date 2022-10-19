// UnmanagedCodeCalledFromMrr.h : main header file for the UnmanagedCodeCalledFromMrr DLL
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols
#include <aawindms.h>
#include <aaapi.h>
#include <aadmsapi.h>
#include <aawinapi.h>

// CUnmanagedCodeCalledFromMrrApp
// See UnmanagedCodeCalledFromMrr.cpp for the implementation of this class
//

class CUnmanagedCodeCalledFromMrrApp : public CWinApp
{
public:
	CUnmanagedCodeCalledFromMrrApp();

// Overrides
public:
	virtual BOOL InitInstance();

	DECLARE_MESSAGE_MAP()
};
