class EditorMapSelectDialog: EditorDialogBase
{
	protected autoptr ListBoxPrefab<string> m_ListBoxPrefab;
	protected DialogButton m_SelectButton;
	
	void EditorMapSelectDialog(string title)
	{
		m_ListBoxPrefab = new ListBoxPrefab<string>();
		AddContent(m_ListBoxPrefab);
		
		for (int i = 0; i < GetGame().ConfigGetChildrenCount("CfgWorlds"); i++) {
			string name;
			GetGame().ConfigGetChildName("CfgWorlds", i, name);
			if (ExcludedMapItems.Find(name) == -1) {
				m_ListBoxPrefab.InsertItem(name, name);
			}
		}
		AddContent(new HintTextPrefab("NOTE: The Editor detects loaded mods If you want custom maps just load it as a mod It will show", null, "hint"));    
		
		m_SelectButton = AddButton("Select", DialogResult.OK);
		//m_SelectButton.Button.Enable(false);
		//m_SelectButton.Button.SetAlpha(150);
		
		AddButton(DialogResult.Cancel);
	}
	
	DialogResult ShowDialog(out string selected_map)
	{
		ListBoxPrefab<string> list_box = m_ListBoxPrefab; // ViewController is ref'd inside this
		DialogResult result = ShowDialog();
		selected_map = list_box.GetSelectedItem();
		delete m_ListBoxPrefab;
		return result;
	}
	
	override bool OnDoubleClick(Widget w, int x, int y, int button)
	{
		if (/*w == m_ListBoxPrefab.ListBox && */button == 0) {
			CloseDialog(DialogResult.OK);
			return true;
		}
		
		return super.OnDoubleClick(w, x, y, button);
	}
}

static const ref array<string> ExcludedMapItems = 
{
	"access",
	"DefaultLighting",
	"DefaultWorld",
	"initWorld",
	"CAWorld",
	
	// @Esseker lol
	"DeafaultLighting",
	
	// EXPANSION >:(
	"Weather",
	"Overcast",
	"Weather1",
	"Weather2",
	"Weather3",
	"Weather4",
	"Weather5",
	"LightingNew",
	"C_Night",
	"C_Astro1",
	"C_Astro2",
	"C_Astro3",
	"C_Nautical1",
	"C_Nautical2",
	"C_Nautical3",
	"C_Civil1",
	"C_Civil2",
	"C_Civil3",
	"C_Day0",
	"C_Day4",
	"C_Day8",
	"C_Day12",
	"C_Day16",
	"C_Day35",
	"C_Day60",
	"O_Night",
	"O_Astro1",
	"O_Nautical1",
	"O_Civil1",
	"O_Civil2",
	"O_Day0",
	"O_Day4",
	"O_Day8",
	"O_Day12",
	"O_Day35",
	"O_Day60",
	"Settlement_Chernogorsk",
	"Settlement_Novodmitrovsk",
	"Settlement_Novoselki",
	"Settlement_Dubovo",
	"Settlement_Vysotovo",
	"Settlement_Zelenogorsk",
	"Settlement_Berezino",
	"Settlement_Elektrozavodsk",
	"Settlement_NovayaPetrovka",
	"Settlement_Gorka",
	"Settlement_Solnechny",
	"Settlement_StarySobor",
	"Settlement_Vybor",
	"Settlement_Severograd",
	"Settlement_Bor",
	"Settlement_Svetloyarsk",
	"Settlement_Krasnostav",
	"Settlement_ChernayaPolyana",
	"Settlement_Polyana",
	"Settlement_Tulga",
	"Settlement_Msta",
	"Settlement_Staroye",
	"Settlement_Shakhovka",
	"Settlement_Dolina",
	"Settlement_Orlovets",
	"Settlement_NovySobor",
	"Settlement_Kabanino",
	"Settlement_Mogilevka",
	"Settlement_Nadezhdino",
	"Settlement_Guglovo",
	"Settlement_Kamyshovo",
	"Settlement_Pusta",
	"Settlement_Dubrovka",
	"Settlement_VyshnayaDubrovka",
	"Settlement_Khelm",
	"Settlement_Olsha",
	"Settlement_Gvozdno",
	"Settlement_Grishino",
	"Settlement_Rogovo",
	"Settlement_Pogorevka",
	"Settlement_Pustoshka",
	"Settlement_Kozlovka",
	"Settlement_Karmanovka",
	"Settlement_Balota",
	"Settlement_Komarovo",
	"Settlement_Kamenka",
	"Settlement_Myshkino",
	"Settlement_Pavlovo",
	"Settlement_Lopatino",
	"Settlement_Vyshnoye",
	"Settlement_Prigorodki",
	"Settlement_Drozhino",
	"Settlement_Sosnovka",
	"Settlement_Nizhneye",
	"Settlement_Pulkovo",
	"Settlement_Berezhki",
	"Settlement_Turovo",
	"Settlement_BelayaPolyana",
	"Settlement_Dobroye",
	"Settlement_Nagornoye",
	"Settlement_Svergino",
	"Settlement_Ratnoye",
	"Settlement_Kamensk",
	"Settlement_Krasnoye",
	"Settlement_StaryYar",
	"Settlement_Polesovo",
	"Settlement_Tisy",
	"Settlement_Topolniki",
	"Settlement_Zaprudnoye",
	"Settlement_Sinystok",
	"Settlement_Vavilovo",
	"Settlement_Kumyrna",
	"Settlement_Kalinovka",
	"Settlement_Bogatyrka",
	"Settlement_SvyatoyRomanSkiResort",
	"Settlement_SKVSChBiathlonArena",
	"Settlement_Zvir",
	"Settlement_Zabolotye",
	"Settlement_Galkino",
	"Camp_Arsenovo",
	"Camp_Stroytel",
	"Camp_Romashka",
	"Camp_Kometa",
	"Camp_Druzhba",
	"Camp_Nadezhda",
	"Camp_YouthPioneer",
	"Camp_ProudChernarus",
	"Camp_Shkolnik",
	"Camp_Pobeda",
	"Camp_Metalurg",
	"Hill_Zelenayagora",
	"Local_Dichina",
	"Local_Novylug",
	"Local_Staryeluga",
	"Hill_Vysota",
	"Hill_Kopyto",
	"Local_Grubyeskaly",
	"Local_Chernyles",
	"Hill_Altar",
	"Local_RadioZenit",
	"Hill_PikKozlova",
	"Local_Pustoykhrebet",
	"Hill_Bashnya",
	"Hill_Veresnik",
	"Hill_Kurgan",
	"Hill_Kustryk",
	"Hill_Vetryanayagora",
	"Hill_Kalmyk",
	"Hill_PopIvan",
	"Hill_Erbenka",
	"Local_Lesnoykhrebet",
	"Hill_Vysokiykamen",
	"Hill_Dobry",
	"Hill_Baranchik",
	"Hill_Malinovka",
	"Hill_Dubina",
	"Hill_Klen",
	"Hill_Chernayagora",
	"Ruin_Zolotar",
	"Hill_Ostry",
	"Hill_Olsha",
	"Marine_Tikhiyzaliv",
	"Marine_Mutnyizaliv",
	"Marine_Chernyzaliv",
	"Marine_Zelenyzaliv",
	"Marine_Skalistyproliv",
	"Marine_Nizhniyzaliv",
	"Marine_ZalivGuba",
	"Marine_Rify",
	"Marine_Ivovoyeozero",
	"Marine_Chernoyeozero",
	"Marine_PlotinaTopolka",
	"Marine_PlotinaPobeda",
	"Marine_PlotinaTishina",
	"Marine_Ozerko",
	"Marine_Prud",
	"Ruin_Chortovzamok",
	"Ruin_Zub",
	"Ruin_Rog",
	"Local_Grozovypereval",
	"Local_Sosnovypereval",
	"Local_PerevalOreshka",
	"Local_Turovskiypereval",
	"Local_Tridoliny",
	"Local_Grozovyedoly",
	"Ruin_Klyuch",
	"Hill_Lysayagora",
	"Marine_Glubokoyeozero",
	"Local_Skalka",
	"Local_Vidy",
	"Hill_Tumannyverkh",
	"Local_Adamovka",
	"Hill_Shishok",
	"Settlement_Skalisty",
	"Ruin_Storozh",
	"Local_MysGolova",
	"Local_Drakon",
	"Local_Otmel",
	"Local_MysKrutoy",
	"Hill_Tokarnya",
	"Hill_Ostrog",
	"Local_Maryanka",
	"Local_Polonina",
	"Local_Kalinka",
	"Hill_Kikimora",
	"Hill_BolshoyKotel",
	"Hill_Simurg",
	"Hill_Volchiypik",
	"Ruin_Krona",
	"Local_TriKresta",
	"Local_Rostoki",
	"Marine_OrlyeOzero",
	"Local_Makosh",
	"Local_Klenovyipereval",
	"Local_Zmeinykhrebet",
	"Hill_Sokol",
	"Local_Krutyeskaly",
	"Local_Bogat",
	"Local_Dubnik",
	"Hill_Viselitsa",
	"Local_Dazhbog",
	"Marine_Verbnik",
	"Local_Medvezhilugi",
	"Ruin_Voron",
	"Ruin_Gnomovzamok",
	"Marine_Glaza",
	"Local_KarerKrasnayaZarya",
	"Local_Matveyevo",
	"Local_Kotka",
	"Local_Chernyeskaly",
	"Hill_SvyatoyRoman",
	"Hill_Koman",
	"Hill_Mayak",
	"Local_MB_VMC",
	"Local_MB_Tisy",
	"Local_MB_Zeleno",
	"Local_MB_Kamensk",
	"Local_MB_Pavlovo",
	"Local_AF_Balota",
	"Local_AF_Krasno",
	"Local_AF_Vybor",
	"VolFog",
	"Names",
	"SoundMapValues",
	"Subdivision",
	"Fractal",
	"WhiteNoise",
	"Ambient",
	"ExpansionTest",
};