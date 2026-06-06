//========================================================================================
//  
//  $File: $
//  
//  Owner: 
//  
//  $Author: $
//  
//  $DateTime: $
//  
//  $Revision: $
//  
//  $Change: $
//  
//  Copyright 1997-2012 Adobe Systems Incorporated. All rights reserved.
//  
//  NOTICE:  Adobe permits you to use, modify, and distribute this file in accordance 
//  with the terms of the Adobe license agreement accompanying it.  If you have received
//  this file from a source other than Adobe, then your use, modification, or 
//  distribution of it requires the prior written permission of Adobe.
//  
//========================================================================================


#ifndef __KESQHTPIOVSID_h__
#define __KESQHTPIOVSID_h__

#include "SDKDef.h"

// Company:
#define kKESQHTPIOVSCompanyKey	kSDKDefPlugInCompanyKey		// Company name used internally for menu paths and the like. Must be globally unique, only A-Z, 0-9, space and "_".
#define kKESQHTPIOVSCompanyValue	kSDKDefPlugInCompanyValue	// Company name displayed externally.

// Plug-in:
#define kKESQHTPIOVSPluginName	"KohakuExtendScriptQueryHitTestPageItemOnVisibleSpreads"			// Name of this plug-in.
#define kKESQHTPIOVSPrefixNumber	0xcbd513bf 		// Unique prefix number for this plug-in(*Must* be obtained from Adobe Developer Support).
#define kKESQHTPIOVSVersion		kSDKDefPluginVersionString						// Version of this plug-in (for the About Box).
#define kKESQHTPIOVSAuthor		""					// Author of this plug-in (for the About Box).

// Plug-in Prefix: (please change kKESQHTPIOVSPrefixNumber above to modify the prefix.)
#define kKESQHTPIOVSPrefix		RezLong(kKESQHTPIOVSPrefixNumber)				// The unique numeric prefix for all object model IDs for this plug-in.
#define kKESQHTPIOVSStringPrefix	SDK_DEF_STRINGIZE(kKESQHTPIOVSPrefixNumber)	// The string equivalent of the unique prefix number for  this plug-in.

// Missing plug-in: (see ExtraPluginInfo resource)
#define kKESQHTPIOVSMissingPluginURLValue		kSDKDefPartnersStandardValue_enUS // URL displayed in Missing Plug-in dialog
#define kKESQHTPIOVSMissingPluginAlertValue	kSDKDefMissingPluginAlertValue // Message displayed in Missing Plug-in dialog - provide a string that instructs user how to solve their missing plug-in problem

// PluginID:
DECLARE_PMID(kPlugInIDSpace, kKESQHTPIOVSPluginID, kKESQHTPIOVSPrefix + 0)

// ClassIDs:
DECLARE_PMID(kClassIDSpace, kKESQHTPIOVSScriptProviderBoss, kKESQHTPIOVSPrefix + 3)

// InterfaceIDs:
//DECLARE_PMID(kInterfaceIDSpace, IID_IKESQHTPIOVSINTERFACE, kKESQHTPIOVSPrefix + 0)

// ImplementationIDs:
DECLARE_PMID(kImplementationIDSpace, kKESQHTPIOVSScriptProviderImpl, kKESQHTPIOVSPrefix + 0 )

// ActionIDs:
DECLARE_PMID(kActionIDSpace, kKESQHTPIOVSAboutActionID, kKESQHTPIOVSPrefix + 0)
//DECLARE_PMID(kActionIDSpace, kKESQHTPIOVSActionID, kKESQHTPIOVSPrefix + 5)

// WidgetIDs:
//DECLARE_PMID(kWidgetIDSpace, kKESQHTPIOVSWidgetID, kKESQHTPIOVSPrefix + 2)

//Script Element IDs

DECLARE_PMID(kScriptInfoIDSpace, kKESQHTPIOVSQueryHitTestPageItemOnVisibleSpreadsMethodScriptElement, kKESQHTPIOVSPrefix + 0)

// "About Plug-ins" sub-menu:
#define kKESQHTPIOVSAboutMenuKey			kKESQHTPIOVSStringPrefix "kKESQHTPIOVSAboutMenuKey"
#define kKESQHTPIOVSAboutMenuPath		kSDKDefStandardAboutMenuPath kKESQHTPIOVSCompanyKey

// "Plug-ins" sub-menu:
#define kKESQHTPIOVSPluginsMenuKey 		kKESQHTPIOVSStringPrefix "kKESQHTPIOVSPluginsMenuKey"
#define kKESQHTPIOVSPluginsMenuPath		kSDKDefPlugInsStandardMenuPath kKESQHTPIOVSCompanyKey kSDKDefDelimitMenuPath kKESQHTPIOVSPluginsMenuKey

// Menu item keys:

// Other StringKeys:
#define kKESQHTPIOVSAboutBoxStringKey	kKESQHTPIOVSStringPrefix "kKESQHTPIOVSAboutBoxStringKey"
#define kKESQHTPIOVSTargetMenuPath kKESQHTPIOVSPluginsMenuPath

// Menu item positions:


// Initial data format version numbers
#define kKESQHTPIOVSFirstMajorFormatNumber  RezLong(1)
#define kKESQHTPIOVSFirstMinorFormatNumber  RezLong(0)

// Data format version numbers for the PluginVersion resource 
#define kKESQHTPIOVSCurrentMajorFormatNumber kKESQHTPIOVSFirstMajorFormatNumber
#define kKESQHTPIOVSCurrentMinorFormatNumber kKESQHTPIOVSFirstMinorFormatNumber

#endif // __KESQHTPIOVSID_h__
