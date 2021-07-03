class EditorInventoryEditorCamera: Camera
{
	protected ref Timer m_LerpTimer = new Timer(CALL_CATEGORY_GAMEPLAY);
	
	void EditorInventoryEditorCamera()
	{
		GetGame().GetUpdateQueue(CALL_CATEGORY_GUI).Insert(OnFrame);
	}
	
	void ~EditorInventoryEditorCamera()
	{
		GetGame().GetUpdateQueue(CALL_CATEGORY_GUI).Remove(OnFrame);
	}
	
	void OnFrame()
	{
		LookAt(GetGame().GetPlayer().GetPosition());
	}
	
	void LerpToPosition(vector target_position, float animation_time)
	{
		vector current_pos = GetGame().GetCurrentCameraPosition();
		m_LerpTimer.Run(0.01, this, "RunPositionLerp", new Param4<vector, vector, float, int>(current_pos, target_position, animation_time, GetGame().GetTime()), true);
	}	
	
	private void RunPositionLerp(vector start, vector finish, float duration, int start_time)
	{
		float tfactor = (1 / duration) * (GetGame().GetTime() - start_time) / 1000;
		SetPosition(Math.SmoothLerpVector(start, finish, tfactor));
		Update();		
		
		if (tfactor >= 1) {
			m_LerpTimer.Stop();
		}
	}
}

class EditorInventoryEditorController: ViewController
{
	PlayerBase Player;
	
	void EditorInventoryEditorController()
	{
		PlayerBase.Cast(GetGame().GetPlayer());
	}
}

class EditorInventoryEditorHud: ScriptViewTemplate<EditorInventoryEditorController>
{
	protected EditorInventoryEditorCamera m_EditorInventoryEditorCamera;
	protected PlayerBase m_Player;
	
	void EditorInventoryEditorHud(PlayerBase player)
	{
		m_Player = player;
		m_EditorInventoryEditorCamera = EditorInventoryEditorCamera.Cast(GetGame().CreateObject("EditorInventoryEditorCamera", GetGame().GetCurrentCameraPosition()));
	}
	
	void SetActive(bool active)
	{
		m_EditorInventoryEditorCamera.SetActive(active);
		if (active) {
			vector pos = m_Player.GetPosition();
			vector dir = m_Player.GetDirection();
			
			vector target_pos = pos + (dir * 3.0) + (dir.Perpend() * 1.0);
			m_EditorInventoryEditorCamera.LerpToPosition(target_pos, 1.0);
		}
	}
	
	override string GetLayoutFile()
	{
		return "DayZEditor/GUI/layouts/Inventory/Inventory.layout";
	}
}