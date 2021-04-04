class EditorPlacedContextMenu: EditorContextMenu
{
	void EditorPlacedContextMenu(float x, float y) 
	{
		EditorLog.Trace("EditorPlacedContextMenu");
		AddMenuButton(m_Editor.CommandManager[EditorCutCommand]);
		AddMenuButton(m_Editor.CommandManager[EditorCopyCommand]);
		AddMenuButton(m_Editor.CommandManager[EditorPasteCommand]);
		AddMenuButton(m_Editor.CommandManager[EditorDeleteCommand]);
		AddMenuButton(m_Editor.CommandManager[EditorShowCommand]);
		AddMenuButton(m_Editor.CommandManager[EditorHideCommand]);
		AddMenuButton(m_Editor.CommandManager[EditorLockCommand]);
		AddMenuButton(m_Editor.CommandManager[EditorUnlockCommand]);		
		AddMenuButton(m_Editor.CommandManager[EditorObjectPropertiesCommand]);
	}
}