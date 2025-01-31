// #define EDITOR_PRINT

class EditorLog
{
	static ref ScriptInvoker OnLog;
	
	static LogLevel CurrentLogLevel = LogLevel.TRACE;
	static string ExclusiveLogMode;
	
	private static string m_LastCalledType;	
	
	static void EditorPrint(string msg, LogLevel level)
	{		
		if (level >= EditorLog.CurrentLogLevel) {
			
			if (!OnLog) {
				OnLog = new ScriptInvoker();
			}
			
			OnLog.Invoke(level, msg);
			
			if (level == LogLevel.ERROR) {
				Error2("Editor Error", msg);
				return;
			}
			
			string loglevel = typename.EnumToString(LogLevel, level);
			
			if (msg.Contains("::")) {
				TStringArray msg_split();
				msg.Split(":", msg_split);
				
				if (ExclusiveLogMode != string.Empty && ExclusiveLogMode != msg_split[0]) {
					return;
				}
				
				if (m_LastCalledType != msg_split[0]) {
					m_LastCalledType = msg_split[0];
					PrintFormat("[%1::%2]:", loglevel, m_LastCalledType);
				}
				

				PrintFormat("	%1", msg.Substring(msg_split[0].Length() + 2, msg.Length() - msg_split[0].Length() - 2));
			} 
			else if (ExclusiveLogMode == string.Empty) {
				PrintFormat("[%1] %2", loglevel, msg);
			}
		}
	}
	
	static void Trace(string msg, string param1 = "", string param2 = "", string param3 = "", string param4 = "", string param5 = "", string param6 = "", string param7 = "", string param8 = "", string param9 = "")
	{
#ifdef EDITOR_PRINT		
		EditorPrint(string.Format(msg, param1, param2, param3, param4, param5, param6, param7, param8, param9), LogLevel.TRACE);
#endif
	}
	
	static void Debug(string msg, string param1 = "", string param2 = "", string param3 = "", string param4 = "", string param5 = "", string param6 = "", string param7 = "", string param8 = "", string param9 = "")
	{
#ifdef EDITOR_PRINT
		EditorPrint(string.Format(msg, param1, param2, param3, param4, param5, param6, param7, param8, param9), LogLevel.DEBUG);
#endif
	}	
	
	static void Info(string msg, string param1 = "", string param2 = "", string param3 = "", string param4 = "", string param5 = "", string param6 = "", string param7 = "", string param8 = "", string param9 = "")
	{
#ifdef EDITOR_PRINT
		EditorPrint(string.Format(msg, param1, param2, param3, param4, param5, param6, param7, param8, param9), LogLevel.INFO);
#endif
	}	
	
	static void Warning(string msg, string param1 = "", string param2 = "", string param3 = "", string param4 = "", string param5 = "", string param6 = "", string param7 = "", string param8 = "", string param9 = "")
	{
#ifdef EDITOR_PRINT
		EditorPrint(string.Format(msg, param1, param2, param3, param4, param5, param6, param7, param8, param9), LogLevel.WARNING);
#endif
	}	
	
	static void Error(string msg, string param1 = "", string param2 = "", string param3 = "", string param4 = "", string param5 = "", string param6 = "", string param7 = "", string param8 = "", string param9 = "")
	{
		msg = string.Format(msg, param1, param2, param3, param4, param5, param6, param7, param8, param9);
		EditorPrint(msg, LogLevel.ERROR);
		
		ErrorDialog(msg);
	}
	
	private static void ErrorDialog(string message)
	{
#ifdef COMPONENT_SYSTEM
		Workbench.Dialog("Editor Log Error", message);
#else
		MessageBox.ShowSynchronous("Error", message, MessageBoxButtons.OK);
#endif
	}
}


static bool RecursiveGetParent(out Widget w, string name)
{
	if (!w) 
		return false;
	
	if (w.GetName() == name) 
		return true;
	
	w = w.GetParent();
	
	if (w) {
		return RecursiveGetParent(w, name);
	}
	
	return false;
}

static bool RecursiveGetParent(out Widget w, typename type)
{
	if (!w) {
		return false;
	}
	
	if (w.IsInherited(type)) {
		return true;
	}
	
	w = w.GetParent();
	
	if (w) {
		return RecursiveGetParent(w, type);
	}
	
	return false;
}

static Widget GetWidgetRoot(Widget w)
{
	Widget parent = w;
	_GetWidgetRoot(parent);
	return parent;
}

static void _GetWidgetRoot(out Widget w)
{
	if (w.GetParent() == null) {
		return;	
	}
	
	w = w.GetParent();
	_GetWidgetRoot(w);
}

static const int COLOR_SALMON	= ARGB(255, 192, 94, 83);
static const int COLOR_SALMON_A	= ARGB(128, 50, 100, 100);
static const int COLOR_CANDY 	= ARGB(255, 231, 76, 60);
static const int COLOR_APPLE 	= ARGB(255, 106, 176, 76);
static const int COLOR_JELLY 	= ARGB(255, 240, 147, 43);
static const int COLOR_PALE_B   = ARGB(255, 50, 100, 200);
static const int COLOR_BLACK	= ARGB(255, 0, 0, 0);
static const int COLOR_WHITE 	= ARGB(255, 255, 255, 255);
static const int COLOR_WHITE_A	= ARGB(75, 255, 255, 255);
static const int COLOR_EMPTY 	= ARGB(0, 0, 0, 0);

//CameraTrackColors
static const int COLOR_BLUE_LIGHT		= ARGB(120, 57, 148, 230);
static const int COLOR_BLUE_HIGHLIGHT 	= ARGB(245, 10, 10, 40);
static const int COLOR_BLUE_HIGHLIGHT_OUTLINE 	= ARGB(255, 73, 170, 255);
static const int COLOR_DEFAULT_OUTLINE 	= ARGB(225, 255, 255, 255);
static const int COLOR_DEFAULT_PANEL 	= ARGB(245, 45, 45, 45);
static const int COLOR_DEFAULT_ICON     = ARGB(70, 255, 255, 255);