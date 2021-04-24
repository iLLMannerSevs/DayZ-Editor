
class EditorEditBoxDialog: EditorDialogBase
{
	protected autoptr EditBoxPrefab m_EditBoxPrefab;
	
	void EditorEditBoxDialog(string title, string caption = "", string default_value = "")
	{
		AddContent(new EditBoxPrefab(caption, m_Controller, default_value));
		
		AddButton(DialogResult.OK);
		AddButton(DialogResult.Cancel);
	}
		
	DialogResult ShowDialog(out string edit_data)
	{
		// Need to store this variable since EVERYTHING is deleted after ShowDialog finishes
		EditBoxWidget edit_box = m_EditBoxPrefab.ContentText;
		
		DialogResult result = ShowDialog();
		edit_data = edit_box.GetText();
		return result;
	}	
}

class EditorExportDialogController: DialogBaseController
{
	bool export_selected;
}

class EditorExportDialog: EditorDialogBase
{
	protected autoptr EditBoxPrefab m_EditBoxPrefab;
	protected ref GroupPrefab m_CheckBoxExport;
	
	static bool Object_Group = true;
		
	void EditorExportDialog(string title, string caption = "", string default_value = "", string button_name = "OK")
	{
		m_EditBoxPrefab = new EditBoxPrefab(caption, m_Controller, default_value);
		AddContent(m_EditBoxPrefab);

		m_CheckBoxExport = new GroupPrefab("Advanced", m_Controller, string.Empty);
		m_CheckBoxExport.Insert(new CheckBoxPrefab("Export Selected Objects", m_Controller, "export_selected"));
		m_CheckBoxExport.Open(Object_Group);

		AddContent(m_CheckBoxExport);
		
		AddButton(DialogResult.OK);
		AddButton(DialogResult.Cancel);
	}
	
	DialogResult ShowDialog(out string edit_data, inout ExportSettings export_settings)
	{
		Trace("ShowDialog");
		
		// Need to store this variable since EVERYTHING is deleted after ShowDialog finishes
		EditBoxWidget edit_box = m_EditBoxPrefab.ContentText;
		
		m_LayoutRoot.Show(true);
		while (m_DialogResult == DialogResult.None) {
			if (edit_box) {
				edit_data = edit_box.GetText();
			}
			
			export_settings.ExportSelectedOnly = EditorExportDialogController.Cast(m_Controller).export_selected;
			Sleep(10);
		}
		
		Log("DialogResult: %1", typename.EnumToString(DialogResult, m_DialogResult));		
		return m_DialogResult;
	}
	
	override typename GetControllerType() 
	{
		return EditorExportDialogController;
	}
}


class EditorMultilineEditBoxDialog: EditorDialogBase
{
	protected autoptr MultilineEditBoxPrefab m_MultilineEditBoxPrefab;
		
	void EditorMultilineEditBoxDialog(string title)
	{
		m_MultilineEditBoxPrefab = new MultilineEditBoxPrefab();
		AddContent(m_MultilineEditBoxPrefab);
		
		AddButton(DialogResult.OK);
		AddButton(DialogResult.Cancel);
	}
	
	DialogResult ShowDialog(out string text)
	{
		// Need to store this variable since EVERYTHING is deleted after ShowDialog finishes
		MultilineEditBoxWidget edit_box = m_MultilineEditBoxPrefab.ContentText;
		DialogResult result = ShowDialog();
		edit_box.GetText(text);
		return result;
	}	
}