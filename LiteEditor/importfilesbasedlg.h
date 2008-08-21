///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Apr 16 2008)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#ifndef __importfilesbasedlg__
#define __importfilesbasedlg__

#include <wx/string.h>
#include <wx/stattext.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/textctrl.h>
#include <wx/button.h>
#include <wx/sizer.h>
#include <wx/checkbox.h>
#include <wx/panel.h>
#include <wx/statline.h>
#include <wx/dialog.h>

///////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////
/// Class ImportFilesBaseDlg
///////////////////////////////////////////////////////////////////////////////
class ImportFilesBaseDlg : public wxDialog 
{
	private:
	
	protected:
		wxPanel* m_mainPanel;
		wxStaticText* m_staticText1;
		wxTextCtrl* m_textCtrlDirPath;
		wxButton* m_buttonBrowse;
		wxStaticText* m_staticText2;
		wxTextCtrl* m_textCtrlFileMask;
		wxCheckBox* m_checkBoxNoExtFiles;
		wxCheckBox* m_checkBoxCheckDuplicates;
		wxStaticLine* m_staticline;
		wxButton* m_buttonOK;
		wxButton* m_buttonCancel;
		
		// Virtual event handlers, overide them in your derived class
		virtual void OnBrowse( wxCommandEvent& event ){ event.Skip(); }
		virtual void OnCheckForForFileDuplicates( wxCommandEvent& event ){ event.Skip(); }
		virtual void OnButtonOK( wxCommandEvent& event ){ event.Skip(); }
		virtual void OnButtonCancel( wxCommandEvent& event ){ event.Skip(); }
		
	
	public:
		ImportFilesBaseDlg( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("Import Files From Directory"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 458,258 ), long style = wxDEFAULT_DIALOG_STYLE );
		~ImportFilesBaseDlg();
	
};

#endif //__importfilesbasedlg__
