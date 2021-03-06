#include "ColoursAndFontsManager.h"
#include "clThemedTreeCtrl.h"
#include "codelite_events.h"
#include "event_notifier.h"
#include <clColours.h>

static void ApplyTheme(clThemedTreeCtrl* tree)
{
    LexerConf::Ptr_t lexer = ColoursAndFontsManager::Get().GetLexer("text");
    const StyleProperty& defaultStyle = lexer->GetProperty(0);
    clColours colours;
    if(lexer->IsDark()) {
        colours.InitDefaults();
        wxColour bgColour = colours.GetBgColour();
        wxColour oddLineColour = bgColour.ChangeLightness(97);
        colours.SetBgColour(bgColour);
        colours.SetAlternateColourEven(bgColour);
        colours.SetAlternateColourOdd(oddLineColour);
    } else {
        colours.InitDefaults();
        wxColour bgColour = defaultStyle.GetBgColour(); // Use the current style background colour
        wxColour oddLineColour = bgColour.ChangeLightness(97);
        colours.SetBgColour(bgColour);
        colours.SetAlternateColourEven(bgColour);
        colours.SetAlternateColourOdd(oddLineColour);
    }
    tree->SetColours(colours);
}

clThemedTreeCtrl::clThemedTreeCtrl(wxWindow* parent, wxWindowID id, const wxPoint& pos, const wxSize& size, long style)
    : clTreeCtrl(parent, id, pos, size, style | wxTR_ROW_LINES | wxBORDER_THEME)
{
    clColours colours;
    colours.InitDefaults();
    SetColours(colours);
    EventNotifier::Get()->Bind(wxEVT_CL_THEME_CHANGED, &clThemedTreeCtrl::OnThemeChanged, this);
    ApplyTheme(this);
}

bool clThemedTreeCtrl::Create(wxWindow* parent, wxWindowID id, const wxPoint& pos, const wxSize& size, long style)
{
    if(!clTreeCtrl::Create(parent, id, pos, size, style)) { return false; }
    clColours colours;
    colours.InitDefaults();
    SetColours(colours);
    EventNotifier::Get()->Bind(wxEVT_CL_THEME_CHANGED, &clThemedTreeCtrl::OnThemeChanged, this);
    ApplyTheme(this);
    return true;
}

clThemedTreeCtrl::clThemedTreeCtrl() {}

clThemedTreeCtrl::~clThemedTreeCtrl()
{
    EventNotifier::Get()->Unbind(wxEVT_CL_THEME_CHANGED, &clThemedTreeCtrl::OnThemeChanged, this);
}

void clThemedTreeCtrl::OnThemeChanged(wxCommandEvent& event)
{
    event.Skip();
    ApplyTheme(this);
}
