using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Diagnostics;
using System.Data;
using DllExporterNet4;
using System.Windows.Forms;
using System.Runtime.InteropServices;

namespace ManagedCodeCalledFromMrr
{
    public class MyManagedCode
    {
        [DllExport]
        public static int MyDocCmdInManagedCode
        (
            uint uiCount, //==>Count of documents 
            [MarshalAs(UnmanagedType.LPArray, SizeParamIndex = 0)]int[] plProjArray, //==>Project number Array
            [MarshalAs(UnmanagedType.LPArray, SizeParamIndex = 0)]int[] plDocArray //==> Document number Array
        )
        {
            string msg = string.Empty;

            // Select first document's properties
            long retValue = PWWrapper.aaApi_SelectDocument(plProjArray[0], plDocArray[0]);
            if (retValue == 1)  // document exists
            {
                String DocName = PWWrapper.aaApi_GetDocumentStringProperty(PWWrapper.DocumentProperty.Name, 0);
                msg = string.Format("Selected Document Count is {0}", uiCount) +
                    string.Format("\nFirst Document name is '{0}'", DocName);
            }
            else if (retValue == -1)    // error
            {
                msg = string.Format("[{0}]\n{1}\n{2}",
                    PWWrapper.aaApi_GetLastErrorDetail(),
                    PWWrapper.aaApi_GetLastErrorMessage(),
                    PWWrapper.aaApi_GetLastErrorDetail());
            }
            else  // document does not exist
            {
                msg = string.Format("Document does not exist!");
            }

            MessageBox.Show(msg, "ManagedCodeCalledFromMrr", MessageBoxButtons.OK);

            return 0;
        }
    }
}

