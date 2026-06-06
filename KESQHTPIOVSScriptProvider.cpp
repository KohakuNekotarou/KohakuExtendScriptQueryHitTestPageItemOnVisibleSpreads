#include "VCPlugInHeaders.h"

// Interface includes:
#include "IGeometry.h"
#include "ILayoutControlViewHelper.h"
#include "IPanelControlData.h"
#include "IScript.h"
#include "IScriptRequestData.h"

// General includes:
#include "CAlert.h"
#include "CScriptProvider.h"
#include "EventUtilities.h" // for ::GetGlobalMouseLocation
#include "LayoutUIID.h" // for kLayoutWidgetBoss
#include "Utils.h"

// Project includes:
#include "KESQHTPIOVSScriptingDefs.h"
#include "KESQHTPIOVSID.h"

class KESQHTPIOVSScriptProvider : public CScriptProvider
{
public:
	KESQHTPIOVSScriptProvider(IPMUnknown* boss) : CScriptProvider(boss) {};

	~KESQHTPIOVSScriptProvider() {}

	ErrorCode HandleMethod(ScriptID scriptID, IScriptRequestData* iScriptRequestData, IScript* iScript);

private:
	ErrorCode QueryHitTestPageItemOnVisibleSpreads(ScriptID scriptID, IScriptRequestData* iScriptRequestData, IScript* iScript);
};

CREATE_PMINTERFACE(KESQHTPIOVSScriptProvider, kKESQHTPIOVSScriptProviderImpl)

// HandleMethod
ErrorCode KESQHTPIOVSScriptProvider::HandleMethod(ScriptID scriptID, IScriptRequestData* iScriptRequestData, IScript* iScript)
{
	ErrorCode status = kFailure;

	switch (scriptID.Get())
	{
	case e_KESQHTPIOVSQueryHitTestPageItemOnVisibleSpreads:
		status = this->QueryHitTestPageItemOnVisibleSpreads(scriptID, iScriptRequestData, iScript);
		break;

	default:
		status = CScriptProvider::HandleMethod(scriptID, iScriptRequestData, iScript);
	}

    return status;
}

// KESQHTPIOVSScriptProvider
ErrorCode KESQHTPIOVSScriptProvider::QueryHitTestPageItemOnVisibleSpreads(
	ScriptID scriptID, IScriptRequestData* iScriptRequestData, IScript* iScript)
{
	ErrorCode status = kFailure;

	ScriptData scriptData;
	PMReal pMReal_x, pMReal_y;
	status = iScriptRequestData->ExtractRequestData(p_KESQHTPIOVSPasteboardLocationX, scriptData);
	if (status == kSuccess) scriptData.GetPMReal(&pMReal_x);

	status = iScriptRequestData->ExtractRequestData(p_KESQHTPIOVSPasteboardLocationY, scriptData);
	if (status == kSuccess) scriptData.GetPMReal(&pMReal_y);

	do {
		InterfacePtr<IPanelControlData> iPanelControlData(iScript, ::UseDefaultIID());
		if (!iPanelControlData) break;

		IControlView* iControlView = iPanelControlData->FindWidget(kLayoutWidgetBoss); // kLayoutWidgetBoss is a BOSS representing a layout view.
		if (!iControlView) break;

		InterfacePtr<ILayoutControlViewHelper> iLayoutControlViewHelper(iControlView, ::UseDefaultIID());
		if (iLayoutControlViewHelper == nil) break;
		
		// QueryHitTestPageItemOnVisibleSpreadsNew
		PBPMPoint pBPMPoint_local(pMReal_x, pMReal_y);
		InterfacePtr<IGeometry> iGeometry(static_cast<IGeometry*>(
			iLayoutControlViewHelper->QueryHitTestPageItemOnVisibleSpreadsNew(
				pBPMPoint_local, kSolidLLHitTestHandlerBoss, IGeometry::kDefaultIID))); // kSolidLLHitTestHandlerBoss will still make a determination even if it is locked.
		if (!iGeometry) break;

		// AppendReturnData
		ScriptData scriptData;
		InterfacePtr<IScript> iScript_pageItem(iGeometry, ::UseDefaultIID());
		if (iScript_pageItem != nil) scriptData.SetObject(iScript_pageItem);

		iScriptRequestData->AppendReturnData(iScript, scriptID, scriptData);

	} while (kFalse);

	return status;
}