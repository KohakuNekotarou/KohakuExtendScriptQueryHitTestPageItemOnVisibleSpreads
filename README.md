# InDesign Plug-In

**I'll add various things to ExtendScript.**
<br>**Let's learn the InDesign SDK together.**

We cannot be held responsible for any issues arising from your use of this service.<br>
Please use it at your own risk.<br>

## extendScript for JavaScript
```
// Unlock locked text frames to allow editing.
if(app.activeWindow.constructor.name != "LayoutWindow") exit();
var pageItem = app.activeWindow.kesqhtpiovsQueryHitTestPageItemOnVisibleSpreads(
    app.activeWindow.kesmlPasteboardMouseLocationX, // Use KohakuExtendScriptMouseLocation PlugIn.
    app.activeWindow.kesmlPasteboardMouseLocationY // Use KohakuExtendScriptMouseLocation PlugIn.
    );
if(pageItem == null) exit();
if (!pageItem.hasOwnProperty("parentStory")) exit();
pageItem.locked = false;
app.toolBoxTools.currentTool = UITools.TYPE_TOOL;
app.keskmcClickLeftMouseButton(); // for KohakuExtendScriptKeyMouseClick PlugIn.
```
