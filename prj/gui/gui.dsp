# Microsoft Developer Studio Project File - Name="gui" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** NICHT BEARBEITEN **

# TARGTYPE "Win32 (x86) Console Application" 0x0103

CFG=gui - Win32 Debug
!MESSAGE Dies ist kein g�ltiges Makefile. Zum Erstellen dieses Projekts mit NMAKE
!MESSAGE verwenden Sie den Befehl "Makefile exportieren" und f�hren Sie den Befehl
!MESSAGE 
!MESSAGE NMAKE /f "gui.mak".
!MESSAGE 
!MESSAGE Sie k�nnen beim Ausf�hren von NMAKE eine Konfiguration angeben
!MESSAGE durch Definieren des Makros CFG in der Befehlszeile. Zum Beispiel:
!MESSAGE 
!MESSAGE NMAKE /f "gui.mak" CFG="gui - Win32 Debug"
!MESSAGE 
!MESSAGE F�r die Konfiguration stehen zur Auswahl:
!MESSAGE 
!MESSAGE "gui - Win32 Release" (basierend auf  "Win32 (x86) Console Application")
!MESSAGE "gui - Win32 Debug" (basierend auf  "Win32 (x86) Console Application")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
RSC=rc.exe

!IF  "$(CFG)" == "gui - Win32 Release"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Release"
# PROP BASE Intermediate_Dir "Release"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "Release"
# PROP Intermediate_Dir "Release"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_CONSOLE" /D "_MBCS" /YX /FD /c
# ADD CPP /nologo /w /W0 /GR /GX /O2 /I "d:\libs\xerces\include" /I "d:\libs\xerces\include\xercesc" /I "..\..\src" /I "d:\libs\glut\\" /I "d:\libs\qt\include" /D "NDEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /D "QT_DLL" /D "QT_THREAD_SUPPORT" /D "ABS_DEBUG" /YX /FD /c
# ADD BASE RSC /l 0x407 /d "NDEBUG"
# ADD RSC /l 0x407 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:console /machine:I386
# ADD LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:console /machine:I386

!ELSEIF  "$(CFG)" == "gui - Win32 Debug"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Debug"
# PROP BASE Intermediate_Dir "Debug"
# PROP BASE Target_Dir ""
# PROP Use_MFC 2
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "Debug"
# PROP Intermediate_Dir "Debug"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_CONSOLE" /D "_MBCS" /YX /FD /GZ /c
# ADD CPP /nologo /MDd /w /W0 /Gm /GR /GX /ZI /Od /I "d:\libs\xerces\include" /I "d:\libs\xerces\include\xercesc" /I "..\..\src" /I "d:\libs\glut\\" /I "d:\libs\qt\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /D "QT_DLL" /D "QT_THREAD_SUPPORT" /D "ABS_DEBUG" /D "_AFXDLL" /YX /FD /GZ /c
# ADD BASE RSC /l 0x407 /d "_DEBUG"
# ADD RSC /l 0x407 /d "_DEBUG" /d "_AFXDLL"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:console /debug /machine:I386 /pdbtype:sept
# ADD LINK32 /nologo /subsystem:console /debug /machine:I386 /pdbtype:sept

!ENDIF 

# Begin Target

# Name "gui - Win32 Release"
# Name "gui - Win32 Debug"
# Begin Group "Quellcodedateien"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat"
# Begin Source File

SOURCE=..\..\src\utils\xml\AttributesHandler.cpp
# End Source File
# Begin Source File

SOURCE=..\..\src\utils\geom\Boundery.cpp
# End Source File
# Begin Source File

SOURCE=..\..\src\utils\geom\Bresenham.cpp
# End Source File
# Begin Source File

SOURCE=..\..\src\utils\common\FileErrorReporter.cpp
# End Source File
# Begin Source File

SOURCE=..\..\src\utils\common\FileHelpers.cpp
# End Source File
# Begin Source File

SOURCE=..\..\src\utils\xml\GenericSAX2Handler.cpp
# End Source File
# Begin Source File

SOURCE=..\..\src\utils\geom\GeomHelper.cpp
# End Source File
# Begin Source File

SOURCE=..\..\src\gui_main.cpp
# End Source File
# Begin Source File

SOURCE=..\..\src\gui\GUIApplicationWindow.cpp
# End Source File
# Begin Source File

SOURCE=..\..\src\gui\GUIChooser.cpp
# End Source File
# Begin Source File

SOURCE=..\..\src\guinetload\GUIContainer.cpp
# End Source File
# Begin Source File

SOURCE=..\..\src\gui\GUIDanielPerspectiveChanger.cpp
# End Source File
# Begin Source File

SOURCE=..\..\src\guisim\GUIEdge.cpp
# End Source File
# Begin Source File

SOURCE=..\..\src\guinetload\GUIEdgeControlBuilder.cpp
# End Source File
# Begin Source File

SOURCE=..\..\src\guisim\GUIEdgeGrid.cpp
# End Source File
# Begin Source File

SOURCE=..\..\src\gui\GUIGlObject.cpp
# End Source File
# Begin Source File

SOURCE=..\..\src\gui\GUIGlObjectStorage.cpp
# End Source File
# Begin Source File

SOURCE=..\..\src\guisim\GUILane.cpp
# End Source File
# Begin Source File

SOURCE=..\..\src\guisim\GUILaneChanger.cpp
# End Source File
# Begin Source File

SOURCE=..\..\src\guisim\GUILaneWrapper.cpp
# End Source File
# Begin Source File

SOURCE=..\..\src\gui\GUILoadThread.cpp
# End Source File
# Begin Source File

SOURCE=..\..\src\guisim\GUINet.cpp
# End Source File
# Begin Source File

SOURCE=..\..\src\guinetload\GUINetBuilder.cpp
# End Source File
# Begin Source File

SOURCE=..\..\src\guinetload\GUINetHandler.cpp
# End Source File
# Begin Source File

SOURCE=..\..\src\gui\GUIPerspectiveChanger.cpp
# End Source File
# Begin Source File

SOURCE=..\..\src\gui\GUIRunThread.cpp
# End Source File
# Begin Source File

SOURCE=..\..\src\gui\GUISimpleLaneDrawer.cpp
# End Source File
# Begin Source File

SOURCE=..\..\src\guisim\GUISourceLane.cpp
# End Source File
# Begin Source File

SOURCE=..\..\src\gui\GUISUMOView.cpp
# End Source File
# Begin Source File

SOURCE=..\..\src\gui\GUITriangleVehicleDrawer.cpp
# End Source File
# Begin Source File

SOURCE=..\..\src\guisim\GUIVehicle.cpp
# End Source File
# Begin Source File

SOURCE=..\..\src\gui\GUIViewTraffic.cpp
# End Source File
# Begin Source File

SOURCE=..\..\src\utils\dev\MemDiff.cpp
# End Source File
# Begin Source File

SOURCE=..\..\src\gui\moc_GUIApplicationWindow.cpp
# End Source File
# Begin Source File

SOURCE=..\..\src\gui\moc_GUIChooser.cpp
# End Source File
# Begin Source File

SOURCE=..\..\src\gui\moc_GUISUMOView.cpp
# End Source File
# Begin Source File

SOURCE=..\..\src\gui\moc_GUIViewTraffic.cpp
# End Source File
# Begin Source File

SOURCE=..\..\src\gui\moc_QGUIImageField.cpp
# End Source File
# Begin Source File

SOURCE=..\..\src\gui\moc_QGUIToggleButton.cpp
# End Source File
# Begin Source File

SOURCE=..\..\src\microsim\MSDetector.cpp
# End Source File
# Begin Source File

SOURCE=..\..\src\microsim\MSEdge.cpp
# End Source File
# Begin Source File

SOURCE=..\..\src\microsim\MSEdgeControl.cpp
# End Source File
# Begin Source File

SOURCE=..\..\src\microsim\MSEmitControl.cpp
# End Source File
# Begin Source File

SOURCE=..\..\src\microsim\MSEventControl.cpp
# End Source File
# Begin Source File

SOURCE=..\..\src\microsim\MSJunction.cpp
# End Source File
# Begin Source File

SOURCE=..\..\src\microsim\MSJunctionControl.cpp
# End Source File
# Begin Source File

SOURCE=..\..\src\microsim\MSJunctionLogic.cpp
# End Source File
# Begin Source File

SOURCE=..\..\src\microsim\MSLane.cpp
# End Source File
# Begin Source File

SOURCE=..\..\src\microsim\MSLaneChanger.cpp
# End Source File
# Begin Source File

SOURCE=..\..\src\microsim\MSLaneSpeedTrigger.cpp
# End Source File
# Begin Source File

SOURCE=..\..\src\microsim\MSLink.cpp
# End Source File
# Begin Source File

SOURCE=..\..\src\microsim\MSLogicJunction.cpp
# End Source File
# Begin Source File

SOURCE=..\..\src\microsim\MSNet.cpp
# End Source File
# Begin Source File

SOURCE=..\..\src\microsim\MSNoLogicJunction.cpp
# End Source File
# Begin Source File

SOURCE=..\..\src\microsim\MSRightOfWayJunction.cpp
# End Source File
# Begin Source File

SOURCE=..\..\src\microsim\MSRoute.cpp
# End Source File
# Begin Source File

SOURCE=..\..\src\microsim\MSRouteHandler.cpp
# End Source File
# Begin Source File

SOURCE=..\..\src\microsim\MSRouteLoader.cpp
# End Source File
# Begin Source File

SOURCE=..\..\src\microsim\MSRouteLoaderControl.cpp
# End Source File
# Begin Source File

SOURCE=..\..\src\microsim\MSSource.cpp
# End Source File
# Begin Source File

SOURCE=..\..\src\microsim\MSSourceLane.cpp
# End Source File
# Begin Source File

SOURCE=..\..\src\microsim\MSTrafficLightJunction.cpp
# End Source File
# Begin Source File

SOURCE=..\..\src\microsim\MSTrafficLightLogic.cpp
# End Source File
# Begin Source File

SOURCE=..\..\src\microsim\MSTriggeredReader.cpp
# End Source File
# Begin Source File

SOURCE=..\..\src\microsim\MSTriggeredSource.cpp
# End Source File
# Begin Source File

SOURCE=..\..\src\microsim\MSTriggeredSourceXMLHandler.cpp
# End Source File
# Begin Source File

SOURCE=..\..\src\microsim\MSTriggeredXMLReader.cpp
# End Source File
# Begin Source File

SOURCE=..\..\src\microsim\MSVehicle.cpp
# End Source File
# Begin Source File

SOURCE=..\..\src\microsim\MSVehicleContainer.cpp
# End Source File
# Begin Source File

SOURCE=..\..\src\microsim\MSVehicleType.cpp
# End Source File
# Begin Source File

SOURCE=..\..\src\utils\qutils\NewQMutex.cpp
# End Source File
# Begin Source File

SOURCE=..\..\src\netload\NLContainer.cpp
# End Source File
# Begin Source File

SOURCE=..\..\src\netload\NLDetectorBuilder.cpp
# End Source File
# Begin Source File

SOURCE=..\..\src\netload\NLEdgeControlBuilder.cpp
# End Source File
# Begin Source File

SOURCE=..\..\src\netload\NLJunctionControlBuilder.cpp
# End Source File
# Begin Source File

SOURCE=..\..\src\netload\NLNetBuilder.cpp
# End Source File
# Begin Source File

SOURCE=..\..\src\netload\NLNetHandler.cpp
# End Source File
# Begin Source File

SOURCE=..\..\src\netload\NLSourceBuilder.cpp
# End Source File
# Begin Source File

SOURCE=..\..\src\netload\NLSucceedingLaneBuilder.cpp
# End Source File
# Begin Source File

SOURCE=..\..\src\netload\NLTriggerBuilder.cpp
# End Source File
# Begin Source File

SOURCE=..\..\src\utils\options\Option.cpp
# End Source File
# Begin Source File

SOURCE=..\..\src\utils\options\OptionsCont.cpp
# End Source File
# Begin Source File

SOURCE=..\..\src\utils\options\OptionsIO.cpp
# End Source File
# Begin Source File

SOURCE=..\..\src\utils\options\OptionsLoader.cpp
# End Source File
# Begin Source File

SOURCE=..\..\src\utils\options\OptionsParser.cpp
# End Source File
# Begin Source File

SOURCE=..\..\src\helpers\PreStartInitialised.cpp
# End Source File
# Begin Source File

SOURCE=..\..\src\utils\dev\profile.c
# End Source File
# Begin Source File

SOURCE=..\..\src\gui\QGLObjectToolTip.cpp
# End Source File
# Begin Source File

SOURCE=..\..\src\utils\gfx\RGBColor.cpp
# End Source File
# Begin Source File

SOURCE=..\..\src\utils\common\SErrorHandler.cpp
# End Source File
# Begin Source File

SOURCE=..\..\src\utils\common\SLogging.cpp
# End Source File
# Begin Source File

SOURCE=..\..\src\utils\convert\STRConvert.cpp
# End Source File
# Begin Source File

SOURCE=..\..\src\utils\common\StringTokenizer.cpp
# End Source File
# Begin Source File

SOURCE=..\..\src\sumo_only\SUMOFrame.cpp
# End Source File
# Begin Source File

SOURCE=..\..\src\utils\sumoxml\SUMOSAXHandler.cpp
# End Source File
# Begin Source File

SOURCE=..\..\src\utils\sumoxml\SUMOXMLDefinitions.cpp
# End Source File
# Begin Source File

SOURCE=..\..\src\utils\common\UtilExceptions.cpp
# End Source File
# Begin Source File

SOURCE=..\..\src\utils\xml\XMLBuildingExceptions.cpp
# End Source File
# Begin Source File

SOURCE=..\..\src\utils\xml\XMLSubSys.cpp
# End Source File
# End Group
# Begin Group "Header-Dateien"

# PROP Default_Filter "h;hpp;hxx;hm;inl"
# Begin Source File

SOURCE=..\..\src\utils\xml\AttributesHandler.h
# End Source File
# Begin Source File

SOURCE=..\..\src\utils\xml\AttributesReadingGenericSAX2Handler.h
# End Source File
# Begin Source File

SOURCE=..\..\src\utils\geom\Boundery.h
# End Source File
# Begin Source File

SOURCE=..\..\src\utils\geom\Bresenham.h
# End Source File
# Begin Source File

SOURCE=..\..\src\utils\xml\GenericSAX2Handler.h
# End Source File
# Begin Source File

SOURCE=..\..\src\utils\geom\GeomHelper.h
# End Source File
# Begin Source File

SOURCE=..\..\src\gui_help.h
# End Source File
# Begin Source File

SOURCE=..\..\src\gui\GUIApplicationWindow.h

!IF  "$(CFG)" == "gui - Win32 Release"

# Begin Custom Build - Moc'ing GUIApplicationWindow.h...
InputPath=..\..\src\gui\GUIApplicationWindow.h

"..\..\src\gui\moc_GUIApplicationWindow.cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	%QTDIR%\bin\moc.exe ..\..\src\gui\GUIApplicationWindow.h -o ..\..\src\gui\moc_GUIApplicationWindow.cpp

# End Custom Build

!ELSEIF  "$(CFG)" == "gui - Win32 Debug"

# Begin Custom Build - Moc'ing GUIApplicationWindow.h...
InputPath=..\..\src\gui\GUIApplicationWindow.h

"..\..\src\gui\moc_GUIApplicationWindow.cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	%QTDIR%\bin\moc.exe ..\..\src\gui\GUIApplicationWindow.h -o ..\..\src\gui\moc_GUIApplicationWindow.cpp

# End Custom Build

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\..\src\gui\GUIChooser.h

!IF  "$(CFG)" == "gui - Win32 Release"

# Begin Custom Build - Moc'ing GUIChooser.h...
InputPath=..\..\src\gui\GUIChooser.h

"..\..\src\gui\moc_GUIChooser.cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	%QTDIR%\bin\moc.exe ..\..\src\gui\GUIChooser.h -o ..\..\src\gui\moc_GUIChooser.cpp

# End Custom Build

!ELSEIF  "$(CFG)" == "gui - Win32 Debug"

# Begin Custom Build - Moc'ing GUIChooser.h...
InputPath=..\..\src\gui\GUIChooser.h

"..\..\src\gui\moc_GUIChooser.cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	%QTDIR%\bin\moc.exe ..\..\src\gui\GUIChooser.h -o ..\..\src\gui\moc_GUIChooser.cpp

# End Custom Build

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\..\src\guinetload\GUIContainer.h
# End Source File
# Begin Source File

SOURCE=..\..\src\gui\GUIDanielPerspectiveChanger.h
# End Source File
# Begin Source File

SOURCE=..\..\src\guisim\GUIEdge.h
# End Source File
# Begin Source File

SOURCE=..\..\src\guisim\GUIEdgeCont.h
# End Source File
# Begin Source File

SOURCE=..\..\src\guinetload\GUIEdgeControlBuilder.h
# End Source File
# Begin Source File

SOURCE=..\..\src\guisim\GUIEdgeGrid.h
# End Source File
# Begin Source File

SOURCE=..\..\src\gui\GUIEvents.h
# End Source File
# Begin Source File

SOURCE=..\..\src\gui\GUIGlObject.h
# End Source File
# Begin Source File

SOURCE=..\..\src\gui\GUIGlObjectStorage.h
# End Source File
# Begin Source File

SOURCE=..\..\src\guisim\GUILane.h
# End Source File
# Begin Source File

SOURCE=..\..\src\guisim\GUILaneChanger.h
# End Source File
# Begin Source File

SOURCE=..\..\src\guisim\GUILaneWrapper.h
# End Source File
# Begin Source File

SOURCE=..\..\src\gui\GUILoadThread.h
# End Source File
# Begin Source File

SOURCE=..\..\src\guisim\GUINet.h
# End Source File
# Begin Source File

SOURCE=..\..\src\guinetload\GUINetBuilder.h
# End Source File
# Begin Source File

SOURCE=..\..\src\guinetload\GUINetHandler.h
# End Source File
# Begin Source File

SOURCE=..\..\src\gui\GUIPerspectiveChanger.h
# End Source File
# Begin Source File

SOURCE=..\..\src\gui\GUIRunThread.h
# End Source File
# Begin Source File

SOURCE=..\..\src\gui\GUISimpleLaneDrawer.h
# End Source File
# Begin Source File

SOURCE=..\..\src\guisim\GUISourceLane.h
# End Source File
# Begin Source File

SOURCE=..\..\src\gui\GUISUMOView.h

!IF  "$(CFG)" == "gui - Win32 Release"

# Begin Custom Build - Moc'ing GUISUMOView.h...
InputPath=..\..\src\gui\GUISUMOView.h

"..\..\src\gui\moc_GUISUMOView.cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	%QTDIR%\bin\moc.exe ..\..\src\gui\GUISUMOView.h -o ..\..\src\gui\moc_GUISUMOView.cpp

# End Custom Build

!ELSEIF  "$(CFG)" == "gui - Win32 Debug"

# Begin Custom Build - Moc'ing GUISUMOView.h...
InputPath=..\..\src\gui\GUISUMOView.h

"..\..\src\gui\moc_GUISUMOView.cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	%QTDIR%\bin\moc.exe ..\..\src\gui\GUISUMOView.h -o ..\..\src\gui\moc_GUISUMOView.cpp

# End Custom Build

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\..\src\gui\GUITriangleVehicleDrawer.h
# End Source File
# Begin Source File

SOURCE=..\..\src\guisim\GUIVehicle.h
# End Source File
# Begin Source File

SOURCE=..\..\src\gui\GUIViewTraffic.h

!IF  "$(CFG)" == "gui - Win32 Release"

# Begin Custom Build - Moc'ing GUIViewTraffic.h...
InputPath=..\..\src\gui\GUIViewTraffic.h

"..\..\src\gui\moc_GUIViewTraffic.cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	%QTDIR%\bin\moc.exe ..\..\src\gui\GUIViewTraffic.h -o ..\..\src\gui\moc_GUIViewTraffic.cpp

# End Custom Build

!ELSEIF  "$(CFG)" == "gui - Win32 Debug"

# Begin Custom Build - Moc'ing GUIViewTraffic.h...
InputPath=..\..\src\gui\GUIViewTraffic.h

"..\..\src\gui\moc_GUIViewTraffic.cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	%QTDIR%\bin\moc.exe ..\..\src\gui\GUIViewTraffic.h -o ..\..\src\gui\moc_GUIViewTraffic.cpp

# End Custom Build

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\..\src\utils\common\HelpPrinter.h
# End Source File
# Begin Source File

SOURCE=..\..\src\utils\logging\LoggedValue.h
# End Source File
# Begin Source File

SOURCE=..\..\src\utils\logging\LoggedValue_Single.h
# End Source File
# Begin Source File

SOURCE=..\..\src\utils\logging\LoggedValue_TimeFixed.h
# End Source File
# Begin Source File

SOURCE=..\..\src\utils\logging\LoggedValue_TimeFloating.h
# End Source File
# Begin Source File

SOURCE=..\..\src\utils\dev\MemDiff.h
# End Source File
# Begin Source File

SOURCE=..\..\src\microsim\MSActuatedTrafficLightLogic.h
# End Source File
# Begin Source File

SOURCE=..\..\src\microsim\MSBitSetLogic.h
# End Source File
# Begin Source File

SOURCE=..\..\src\microsim\MSDetector.h
# End Source File
# Begin Source File

SOURCE=..\..\src\microsim\MSEdge.h
# End Source File
# Begin Source File

SOURCE=..\..\src\microsim\MSEdgeControl.h
# End Source File
# Begin Source File

SOURCE=..\..\src\microsim\MSEmitControl.h
# End Source File
# Begin Source File

SOURCE=..\..\src\microsim\MSEventControl.h
# End Source File
# Begin Source File

SOURCE=..\..\src\microsim\MSInductLoop.h
# End Source File
# Begin Source File

SOURCE=..\..\src\microsim\MSJunction.h
# End Source File
# Begin Source File

SOURCE=..\..\src\microsim\MSJunctionControl.h
# End Source File
# Begin Source File

SOURCE=..\..\src\microsim\MSJunctionLogic.h
# End Source File
# Begin Source File

SOURCE=..\..\src\microsim\MSLane.h
# End Source File
# Begin Source File

SOURCE=..\..\src\microsim\MSLaneChanger.h
# End Source File
# Begin Source File

SOURCE=..\..\src\microsim\MSLaneSpeedTrigger.h
# End Source File
# Begin Source File

SOURCE=..\..\src\microsim\MSLaneState.h
# End Source File
# Begin Source File

SOURCE=..\..\src\microsim\MSLink.h
# End Source File
# Begin Source File

SOURCE=..\..\src\microsim\MSLinkCont.h
# End Source File
# Begin Source File

SOURCE=..\..\src\microsim\MSLogicJunction.h
# End Source File
# Begin Source File

SOURCE=..\..\src\microsim\MSNet.h
# End Source File
# Begin Source File

SOURCE=..\..\src\microsim\MSNoLogicJunction.h
# End Source File
# Begin Source File

SOURCE=..\..\src\microsim\MSRightOfWayJunction.h
# End Source File
# Begin Source File

SOURCE=..\..\src\microsim\MSRoute.h
# End Source File
# Begin Source File

SOURCE=..\..\src\microsim\MSRouteHandler.h
# End Source File
# Begin Source File

SOURCE=..\..\src\microsim\MSRouteLoader.h
# End Source File
# Begin Source File

SOURCE=..\..\src\microsim\MSRouteLoaderControl.h
# End Source File
# Begin Source File

SOURCE=..\..\src\microsim\MSSimpleTrafficLightLogic.h
# End Source File
# Begin Source File

SOURCE=..\..\src\microsim\MSSource.h
# End Source File
# Begin Source File

SOURCE=..\..\src\microsim\MSSourceLane.h
# End Source File
# Begin Source File

SOURCE=..\..\src\microsim\MSTrafficLightJunction.h
# End Source File
# Begin Source File

SOURCE=..\..\src\microsim\MSTrafficLightLogic.h
# End Source File
# Begin Source File

SOURCE=..\..\src\microsim\MSTrigger.h
# End Source File
# Begin Source File

SOURCE=..\..\src\microsim\MSTriggeredReader.h
# End Source File
# Begin Source File

SOURCE=..\..\src\microsim\MSTriggeredSource.h
# End Source File
# Begin Source File

SOURCE=..\..\src\microsim\MSTriggeredSourceXMLHandler.h
# End Source File
# Begin Source File

SOURCE=..\..\src\microsim\MSTriggeredXMLReader.h
# End Source File
# Begin Source File

SOURCE=..\..\src\microsim\MSVehicle.h
# End Source File
# Begin Source File

SOURCE=..\..\src\microsim\MSVehicleContainer.h
# End Source File
# Begin Source File

SOURCE=..\..\src\microsim\MSVehicleType.h
# End Source File
# Begin Source File

SOURCE=..\..\src\utils\common\NamedObjectCont.h
# End Source File
# Begin Source File

SOURCE=..\..\src\utils\qutils\NewQMutex.h
# End Source File
# Begin Source File

SOURCE=..\..\src\netload\NLContainer.h
# End Source File
# Begin Source File

SOURCE=..\..\src\netload\NLDetectorBuilder.h
# End Source File
# Begin Source File

SOURCE=..\..\src\netload\NLEdgeControlBuilder.h
# End Source File
# Begin Source File

SOURCE=..\..\src\netload\NLJunctionControlBuilder.h
# End Source File
# Begin Source File

SOURCE=..\..\src\netload\NLLoadFilter.h
# End Source File
# Begin Source File

SOURCE=..\..\src\netload\NLNetBuilder.h
# End Source File
# Begin Source File

SOURCE=..\..\src\netload\NLNetHandler.h
# End Source File
# Begin Source File

SOURCE=..\..\src\netload\NLSourceBuilder.h
# End Source File
# Begin Source File

SOURCE=..\..\src\netload\NLSucceedingLaneBuilder.h
# End Source File
# Begin Source File

SOURCE=..\..\src\netload\NLTriggerBuilder.h
# End Source File
# Begin Source File

SOURCE=..\..\src\utils\options\Option.h
# End Source File
# Begin Source File

SOURCE=..\..\src\utils\options\OptionsCont.h
# End Source File
# Begin Source File

SOURCE=..\..\src\utils\options\OptionsIO.h
# End Source File
# Begin Source File

SOURCE=..\..\src\utils\options\OptionsLoader.h
# End Source File
# Begin Source File

SOURCE=..\..\src\utils\options\OptionsParser.h
# End Source File
# Begin Source File

SOURCE=..\..\src\utils\geom\Position2D.h
# End Source File
# Begin Source File

SOURCE=..\..\src\utils\dev\profile.h
# End Source File
# Begin Source File

SOURCE=..\..\src\gui\QGLObjectToolTip.h
# End Source File
# Begin Source File

SOURCE=..\..\src\gui\QGUIImageField.h

!IF  "$(CFG)" == "gui - Win32 Release"

# Begin Custom Build - Moc'ing QGUIImageField.h...
InputPath=..\..\src\gui\QGUIImageField.h

"..\..\src\gui\moc_QGUIImageField.cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	%QTDIR%\bin\moc.exe ..\..\src\gui\QGUIImageField.h -o ..\..\src\gui\moc_QGUIImageField.cpp

# End Custom Build

!ELSEIF  "$(CFG)" == "gui - Win32 Debug"

# Begin Custom Build - Moc'ing QGUIImageField.h...
InputPath=..\..\src\gui\QGUIImageField.h

"..\..\src\gui\moc_QGUIImageField.cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	%QTDIR%\bin\moc.exe ..\..\src\gui\QGUIImageField.h -o ..\..\src\gui\moc_QGUIImageField.cpp

# End Custom Build

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\..\src\gui\QGUIToggleButton.h

!IF  "$(CFG)" == "gui - Win32 Release"

# Begin Custom Build - Moc'ing QGUIToggleButton.h...
InputPath=..\..\src\gui\QGUIToggleButton.h

"..\..\src\gui\moc_QGUIToggleButton.cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	%QTDIR%\bin\moc.exe ..\..\src\gui\QGUIToggleButton.h -o ..\..\src\gui\moc_QGUIToggleButton.cpp

# End Custom Build

!ELSEIF  "$(CFG)" == "gui - Win32 Debug"

# Begin Custom Build - Moc'ing QGUIToggleButton.h...
InputPath=..\..\src\gui\QGUIToggleButton.h

"..\..\src\gui\moc_QGUIToggleButton.cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	%QTDIR%\bin\moc.exe ..\..\src\gui\QGUIToggleButton.h -o ..\..\src\gui\moc_QGUIToggleButton.cpp

# End Custom Build

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\..\src\gui\QSimulationLoadedEvent.h
# End Source File
# Begin Source File

SOURCE=..\..\src\gui\QSimulationStepEvent.h
# End Source File
# Begin Source File

SOURCE=..\..\src\gui\QSUMOEvent.h
# End Source File
# Begin Source File

SOURCE=..\..\src\utils\gfx\RGBColor.h
# End Source File
# Begin Source File

SOURCE=..\..\src\utils\convert\STRConvert.h
# End Source File
# Begin Source File

SOURCE=..\..\src\sumo_only\SUMOFrame.h
# End Source File
# Begin Source File

SOURCE=..\..\src\utils\sumoxml\SUMOSAXHandler.h
# End Source File
# Begin Source File

SOURCE=..\..\src\utils\sumoxml\SUMOXMLDefinitions.h
# End Source File
# Begin Source File

SOURCE=..\..\src\utils\convert\TplConvert.h
# End Source File
# Begin Source File

SOURCE=..\..\src\utils\convert\TplConvertSec.h
# End Source File
# Begin Source File

SOURCE=..\..\src\utils\xml\XMLBuildingExceptions.h
# End Source File
# Begin Source File

SOURCE=..\..\src\utils\xml\XMLSubSys.h
# End Source File
# End Group
# Begin Group "Ressourcendateien"

# PROP Default_Filter "ico;cur;bmp;dlg;rc2;rct;bin;rgs;gif;jpg;jpeg;jpe"
# End Group
# Begin Source File

SOURCE=..\..\..\..\..\libs\xerces\lib\xerces.lib
# End Source File
# Begin Source File

SOURCE="..\..\..\..\..\libs\qt\lib\qt-mt230nc.lib"
# End Source File
# Begin Source File

SOURCE=..\..\..\..\..\libs\glut\glut32.lib
# End Source File
# Begin Source File

SOURCE=..\..\..\..\..\libs\qt\lib\qutil.lib
# End Source File
# End Target
# End Project
