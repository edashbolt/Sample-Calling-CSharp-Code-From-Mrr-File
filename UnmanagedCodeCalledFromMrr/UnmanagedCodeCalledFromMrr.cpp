// UnmanagedCodeCalledFromMrr.cpp : Defines the initialization routines for the DLL.
//

#include "stdafx.h"
#include "UnmanagedCodeCalledFromMrr.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

//
//TODO: If this DLL is dynamically linked against the MFC DLLs,
//		any functions exported from this DLL which call into
//		MFC must have the AFX_MANAGE_STATE macro added at the
//		very beginning of the function.
//
//		For example:
//
//		extern "C" BOOL PASCAL EXPORT ExportedFunction()
//		{
//			AFX_MANAGE_STATE(AfxGetStaticModuleState());
//			// normal function body here
//		}
//
//		It is very important that this macro appear in each
//		function, prior to any calls into MFC.  This means that
//		it must appear as the first statement within the 
//		function, even before any object variable declarations
//		as their constructors may generate calls into the MFC
//		DLL.
//
//		Please see MFC Technical Notes 33 and 58 for additional
//		details.
//

// CUnmanagedCodeCalledFromMrrApp

BEGIN_MESSAGE_MAP(CUnmanagedCodeCalledFromMrrApp, CWinApp)
END_MESSAGE_MAP()


// CUnmanagedCodeCalledFromMrrApp construction

CUnmanagedCodeCalledFromMrrApp::CUnmanagedCodeCalledFromMrrApp()
{
	// TODO: add construction code here,
	// Place all significant initialization in InitInstance
}


// The one and only CUnmanagedCodeCalledFromMrrApp object

CUnmanagedCodeCalledFromMrrApp theApp;


// CUnmanagedCodeCalledFromMrrApp initialization

BOOL CUnmanagedCodeCalledFromMrrApp::InitInstance()
{
	CWinApp::InitInstance();

	return TRUE;
}

// CustomInitialize
// not needed for .mrr functions

extern "C" int WINAPI MyDocCmdInUnmanagedCode
(
	unsigned int uiCount,
	long*  pProjects,
	long*  pDocuments
)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	CString msg;

	// select first document's properties
	long retValue = aaApi_SelectDocument(*pProjects, *pDocuments);
	if (retValue == 1)	// document exists
	{
		CString DocName;
		DocName.Format(L"%s", aaApi_GetDocumentStringProperty(DOC_PROP_NAME, 0));
		msg.Format(L"This is unmanaged code called from an .mrr file.\n\nSelected Document Count is %ld\nFirst Document name is '%s'",
			uiCount, DocName);

	}
	else if (retValue == -1)	// error
	{
		msg.Format(L"This is unmanaged code called from an .mrr file.\n\n[%ld]\n%s\n%s",
			aaApi_GetLastErrorDetail(),
			aaApi_GetLastErrorMessage(),
			aaApi_GetLastErrorDetail());
	}
	else  // document does not exist
	{
		msg.Format(L"This is unmanaged code called from an .mrr file.\n\nDocument does not exist!");
	}

	//aaApi_MessageBox(msg, MB_OK);

	AfxMessageBox(msg, IDOK | MB_ICONINFORMATION);

	return 0;
}

