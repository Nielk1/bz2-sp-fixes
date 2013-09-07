#include "..\Shared\SPMission.h"

class Misn04Mission : public SPMission 
{
public:
	Misn04Mission(void)
	{
		AllowRandomTracks(false);
		b_count = &b_last - &b_first - 1;
		b_array = &b_first + 1;

		f_count = &f_last - &f_first - 1;
		f_array = &f_first + 1;

		h_count = &h_last - &h_first - 1;
		h_array = &h_first + 1;

		i_count = &i_last - &i_first - 1;
		i_array = &i_first + 1;
	}

	void Setup(void);
	void AddObject(Handle h);
	void Execute(void);

	// bools
	bool
		b_first,
		start_done,hell,game_over,at_recycler,builder1_a,sscav1_a,sscav2_a,sscav3_a,
		sscav4_a,sscav5_a,scav1_to_pool,scav2_to_pool,scav3_to_pool,scav4_to_pool,
		scav1_at_pool,scav2_at_pool,scav3_at_pool,scav4_at_pool,
		scav1_deployed,scav2_deployed,scav3_deployed,scav4_deployed,burns_move,
		burns_at_condor,burns_in_condor,guard1_a,guard2_a,guard3_a,guard4_a,
		guard1_sent,guard2_sent,guard3_sent,guards_sent,guard1_deployed,guard2_deployed,
		guard3_deployed,part_two,brad_message1,honest_warning,pilot_talk1,pilot_talk2,pilot_talk3,
		carrier_dead,confussion,panic_message1,panic_message2,panic_message3,
		brad_message2,brad_message3,brad_message4,set_scrap,
		sent1_to_recy,sent2_to_recy,war1_to_recy,war2_to_recy,

		sent1_a,sent2_a,sent3_a,sent4_a,war1_a,war2_a,war3_a,war4_a,
		war_look1,war_look2,war_look3,at_player,at_manson,at_2,
		scout1_a,scout2_a,scout3_a,scout4_a,lance1_a,lance2_a,lance3_a,lance4_a,
		maul1_a,maul2_a,maul3_a,maul4_a,titan1_a,titan2_a,titan3_a,
		plan_change1,recycler_deployed,titan1_move,remove_burns,titan_attack,
		titan_plan,send_scouts,titan_dead,update_quake,titan_sent,
		movie_over,first_frame,new_plan,titan_look,main_explosion,explode,
		b_last;

	// floats
	float
		f_first,
		hell_time,recycler_check,scav1_check,scav2_check,scav3_check,scav4_check,
		burns_check,move_burns_time,guards_check,honest_check,parade_check,
		panic_time,escape_check,carrier_time,war1_check,set_scrap_time,
		titan_attack_time,plan_check,quake_time,titan_time,movie_time,titan_look_time,
		explosion_time,
		f_last;

	// handles
	Handle
		h_first,
		key_device,burns,
		player,recycler,srecycler,manson,
		forge,overseer,dower,stronghold,bigass_building,
		spire2,spire3,spire4,
		pool1,pool2,pool3,
		tugger,nav1,nav2,
		tank1,tank2,rocket1,walker1,walker2,
		sscav1,sscav2,sscav3,sscav4,sscav5,
		guard1,guard2,guard3,guard4,guarda,guardb,
		sent1,sent2,sent3,sent4,
		war1,war2,war3,war4,
		lance1,lance2,lance3,lance4,
		scout1,scout2,scout3,scout4,
		titan1,titan2,titan3,
		base_pool1,base_pool2,base_pool3,
		builder1,talk,talk2,
		burns_condor,temp,
		first_titan1,first_titan2,
		kick,kick1,kick2,
		player_ship,carrier,
		show1,show2,
		h_last;

	// integers
	int
		i_first,

		i_last;
};

DLLBase * BuildMission(void)
{
	return new Misn04Mission();
}

bool HaveScav(void)
{
	int a,b;
	int up_scavs,scavs;
	bool enouph;

	a = CountUnitsNearObject(0,99999.0f,2,"fbscup");
	b = CountUnitsNearObject(0,99999.0f,2,"fbscav");

	up_scavs = a;
	scavs = a+b;

	enouph = false;

	if ((up_scavs > 3) && (scavs > 5))
	{
		enouph = true;
	}
	else
	{
		enouph = false;
	}
	return enouph;
}


bool HaveScav2(void)
{
	int x,z;
	int scavs2;
	bool enouph2;

	x = CountUnitsNearObject(0,99999.0f,2,"ibscup");
	z = CountUnitsNearObject(0,99999.0f,2,"ibscav");

	scavs2 = x+z;

	enouph2 = false;

	if ((scavs2 > 2))
	{
		enouph2 = true;
	}
	else
	{
		enouph2 = false;
	}
	return enouph2;
}

void Misn04Mission::Setup(void)
{
	SetAutoGroupUnits(false);
/*
	Here's where you set the values at the start.  
*/

//  bools
	start_done = false;
	hell = false;
	game_over = false;
	at_recycler = false;
	builder1_a = true;
	sscav1_a = true;
	sscav2_a = true;
	sscav3_a = true;
	sscav4_a = true;
	sscav5_a = true;
	scav1_to_pool = false;
	scav1_at_pool = false;
	scav1_deployed = false;
	scav2_to_pool = true;
	scav2_at_pool = true;
	scav2_deployed = true;
	scav3_to_pool = true;
	scav3_at_pool = true;
	scav3_deployed = true;
	scav4_to_pool = true;
	scav4_at_pool = true;
	scav4_deployed = true;
	burns_move = false;
	burns_at_condor = false;
	burns_in_condor = false;
	guard1_a = false;
	guard2_a = false;
	guard3_a = false;
	guard4_a = false;
	guard1_sent = false;
	guard2_sent = false;
	guard3_sent = false;
	guards_sent = false;
	guard1_deployed = false;
	guard2_deployed = false;
	guard3_deployed = false;
	part_two = false;
	brad_message1 = false;
	honest_warning = false;
	pilot_talk1 = false;
	pilot_talk2 = false;
	pilot_talk3 = false;
	carrier_dead = false;
	confussion = false;
	panic_message1 = false;
	panic_message2 = false;
	panic_message3 = false;
	brad_message2 = false;
	brad_message3 = false;
	brad_message4 = false;
	sent1_a = true; sent2_a = true; sent3_a = false; sent4_a = false;
	war1_a = true; war2_a = false; war3_a = false; war4_a = false;
	scout1_a = false; scout2_a = false; scout3_a = false; scout4_a = false; 
	lance1_a = false; lance2_a = false; lance3_a = false; lance4_a = false;
	maul1_a = false; maul2_a = false; maul3_a = false; maul4_a = false;
	titan1_a = false; titan2_a = false; titan3_a = false;
	war_look1 = false;
	war_look2 = false;
	war_look3 = false;
	at_player = false;
	at_manson = false;
	at_2 = false;
	set_scrap = false;
	sent1_to_recy = false;
	sent2_to_recy = false;
	war1_to_recy = false;
	war2_to_recy = false;
	plan_change1 = false;
	recycler_deployed = false;
	titan1_move = false;
	remove_burns = false;
	titan_attack = false;
	titan_plan = false;
	send_scouts = false;
	titan_dead = false;
	update_quake = false;
	titan_sent = false;
	movie_over = false;
	first_frame = false;
	new_plan = false;
	titan_look = false;
	main_explosion = false;
	explode = false;


//  floats
	hell_time = 999999.9f;
	recycler_check = 999999.9f;
	scav1_check = 999999.9f;
	scav2_check = 999999.9f;
	scav3_check = 999999.9f;
	scav4_check = 999999.9f;
	burns_check = 999999.9f;
	move_burns_time = 999999.9f;
	guards_check = 999999.9f;
	honest_check = 999999.9f;
	parade_check = 999999.9f;
	panic_time = 999999.9f;
	escape_check = 999999.9f;
	carrier_time = 999999.9f;
	war1_check = 999999.9f;
	set_scrap_time = 999999.9f;
	titan_attack_time = 999999.9f;
	plan_check = 999999.9f;
	quake_time = 999999.9f;
	titan_time = 999999.9f;
	movie_time = 999999.9f;
	titan_look_time = 999999.9f;
	explosion_time = 999999.9f;

//  handles
	player_ship = GetHandle("player_ship");
	player = GetPlayerHandle();
	burns = GetHandle("burns");
	recycler = GetHandle("recycler");
	forge = GetHandle("forge");
	overseer = GetHandle("overseer");
	dower = GetHandle("dower");
	stronghold = GetHandle("stronghold");
	bigass_building = GetHandle("bigass_building");
	srecycler = GetHandle("srecycler");
	sscav1 = GetHandle("sscav1");
	sscav2 = GetHandle("sscav2");
	sscav3 = GetHandle("sscav3");
	sscav4 = GetHandle("sscav4");
	sscav5 = GetHandle("sscav5");
	spire2 = GetHandle("spire2");
	spire3 = GetHandle("spire3");
	spire4 = GetHandle("spire4");
	pool1 = GetHandle("pool1");
	pool2 = GetHandle("pool2");
	pool3 = GetHandle("pool3");
	manson = GetHandle("tank1");
	tank2 = GetHandle("tank2");
	//rocket1 = GetHandle("rocket1");
	//walker1 = GetHandle("walker1");
	//walker2 = GetHandle("walker2");
	burns_condor = GetHandle("dropship");
	key_device = GetHandle("key_device");
	first_titan1 = GetHandle("titan1");
	first_titan2 = GetHandle("titan2");
	builder1 = GetHandle("builder1");
	show1 = GetHandle("show1");
	show2 = GetHandle("show2");
	tugger = NULL;
	nav1 = NULL;
	nav2 = NULL;
	sent1 = GetHandle("sent1");
	sent2 = GetHandle("sent2");
	sent3 = NULL;
	sent4 = NULL;
	war1 = NULL;
	war2 = NULL;
	war3 = NULL;
	war4 = NULL;
	lance1 = NULL;
	lance2 = NULL;
	lance3 = NULL;
	lance4 = NULL;
	scout1 = NULL;
	scout2 = NULL;
	scout3 = NULL;
	scout4 = NULL;
	titan1 = NULL;
	titan2 = NULL;
	titan3 = NULL;
	guard1 = NULL;
	guard2 = NULL;
	guard3 = NULL;
	guard4 = NULL;
	guarda = GetHandle("guarda");
	guardb = GetHandle("guardb");
	//base_pool1 = GetHandle("base_pool1");
	//base_pool2 = GetHandle("base_pool2");
	//base_pool3 = GetHandle("base_pool3");
	talk = NULL;
	talk2 = NULL;
	temp = NULL;
	kick = NULL;
	kick1 = NULL;
	kick2 = NULL;
	carrier = NULL;

	PreloadODF("ivcarr");

//  integers


} 

void Misn04Mission::AddObject(Handle h)
{
	char ODFName[64];
	GetObjInfo(h, Get_CFG, ODFName);

if (start_done)
{
	if ((!builder1_a) && (IsOdf2(h,"fvconst")))
	{
		builder1 = h;
		builder1_a = true;
	}

	else if ((!recycler_deployed) && (IsOdf2(h,"ibrecy")))
	{
		SetObjectiveOff(recycler);
		recycler=h;
		recycler_deployed = true;
	}

	//SCAVENGERS
	else if ((!sscav1_a) && (IsOdf2(h,"fvscav")))
	{
		sscav1 = h;
		sscav1_a = true;
	}
	else if ((!sscav2_a) && (IsOdf2(h,"fvscav")))
	{
		sscav2 = h;
		sscav2_a = true;
	}
	else if ((!sscav3_a) && (IsOdf2(h,"fvscav")))
	{
		sscav3 = h;
		sscav3_a = true;
	}
	else if ((!sscav4_a) && (IsOdf2(h,"fvscav")))
	{
		sscav4 = h;
		sscav4_a = true;
	}
	else if ((!sscav5_a) && (IsOdf2(h,"fvscav")))
	{
		sscav5 = h;
		sscav5_a = true;
	}

	// SCOUT
	else if ((!scout1_a) && (IsOdf2(h,"fvscout")))
	{
		scout1 = h;
		scout1_a = true;

		if (GetTeamNum(scout1) == 3)
		{
			SetTeamNum(scout1,2);
		}

	}
	else if ((!scout2_a) && (IsOdf2(h,"fvscout")))
	{
		scout2 = h;
		scout2_a = true;

		if (GetTeamNum(scout2) == 3)
		{
			SetTeamNum(scout2,2);
		}
	}
	else if ((!scout3_a) && (IsOdf2(h,"fvscout")))
	{
		scout3 = h;
		scout3_a = true;

		if (GetTeamNum(scout3) == 3)
		{
			SetTeamNum(scout3,2);
		}
	}
	else if ((!scout4_a) && (IsOdf2(h,"fvscout")))
	{
		scout4 = h;
		scout4_a = true;

		if (GetTeamNum(scout4) == 3)
		{
			SetTeamNum(scout4,2);
		}
	}
	
	// GUARDIAN
	else if ((!guard1_a) && (IsOdf2(h,"fvturr")))
	{
		guard1 = h;
		guard1_a = true;
	}
	else if ((!guard2_a) && (IsOdf2(h,"fvturr")))
	{
		guard2 = h;
		guard2_a = true;
	}
	else if ((!guard3_a) && (IsOdf2(h,"fvturr")))
	{
		guard3 = h;
		guard3_a = true;
	}
	else if ((!guard4_a) && (IsOdf2(h,"fvturr")))
	{
		guard4 = h;
		guard4_a = true;
	}


	else if (new_plan)
	{
		// SENTRY
		if ((!sent1_a) && (IsOdf2(h,"fvsent")))
		{
			sent1 = h;
			sent1_a = true;

			if (GetTeamNum(sent1) == 3)
			{
				SetTeamNum(sent1,2);
			}
		}
		else if ((!sent2_a) && (IsOdf2(h,"fvsent")))
		{
			sent2 = h;
			sent2_a = true;

			if (GetTeamNum(sent2) == 3)
			{
				SetTeamNum(sent2,2);
			}
		}
		else if ((!sent3_a) && (IsOdf2(h,"fvsent")))
		{
			sent3 = h;
			sent3_a = true;

			if (GetTeamNum(sent3) == 3)
			{
				SetTeamNum(sent3,2);
			}
		}
		else if ((!sent4_a) && (IsOdf2(h,"fvsent")))
		{
			sent4 = h;
			sent4_a = true;

			if (GetTeamNum(sent4) == 3)
			{
				SetTeamNum(sent4,2);
			}
		}

		// WARRIOR
		else if ((!war1_a) && (IsOdf2(h,"fvtank")))
		{
			war1 = h;
			war1_a = true;

			if (GetTeamNum(war1) == 3)
			{
				SetTeamNum(war1,2);
			}

			GiveWeapon(war1,"gquill");
			GiveWeapon(war1,"gdeflect");
			//BuildObject("apquil",0,war1);
			//BuildObject("apdefl",0,war1);
		}
		else if ((!war2_a) && (IsOdf2(h,"fvtank")))
		{
			war2 = h;
			war2_a = true;

			if (GetTeamNum(war2) == 3)
			{
				SetTeamNum(war2,2);
			}

			GiveWeapon(war2,"gquill");
			GiveWeapon(war2,"gdeflect");
			//BuildObject("apquil",0,war2);
			//BuildObject("apdefl",0,war2);
		}
		else if ((!war3_a) && (IsOdf2(h,"fvtank")))
		{
			war3 = h;
			war3_a = true;

			if (GetTeamNum(war3) == 3)
			{
				SetTeamNum(war3,2);
			}

			GiveWeapon(war3,"gquill");
			GiveWeapon(war3,"gdeflect");
			//BuildObject("apquil",0,war3);
			//BuildObject("apdefl",0,war3);
		}
		else if ((!war4_a) && (IsOdf2(h,"fvtank")))
		{
			war4 = h;
			war4_a = true;

			if (GetTeamNum(war4) == 3)
			{
				SetTeamNum(war4,2);
			}

			GiveWeapon(war4,"gquill");
			GiveWeapon(war4,"gdeflect");
			//BuildObject("apquil",0,war4);
			//BuildObject("apdefl",0,war4);
		}

		// LANCER
		else if ((!lance1_a) && (IsOdf2(h,"fvarch")))
		{
			lance1 = h;
			lance1_a = true;

			BuildObject("apdefl",0,lance1);
		}
		else if ((!lance2_a) && (IsOdf2(h,"fvarch")))
		{
			lance2 = h;
			lance2_a = true;

			BuildObject("apdefl",0,lance2);
		}
		else if ((!lance3_a) && (IsOdf2(h,"fvarch")))
		{
			lance3 = h;
			lance3_a = true;

			BuildObject("apdefl",0,lance3);
		}
		else if ((!lance4_a) && (IsOdf2(h,"fvarch")))
		{
			lance4 = h;
			lance4_a = true;

			BuildObject("apdefl",0,lance4);
		}

		// TITANS
		else if ((!titan1_a) && (IsOdf2(h,"fvatank")))
		{
			titan1 = h;
			titan_time = GetTime() + 102.0f;
			titan1_a = true;
		}
		else if ((!titan2_a) && (IsOdf2(h,"fvatank")))
		{
			titan2 = h;
			titan2_a = true;
		}
		else if ((!titan3_a) && (IsOdf2(h,"fvatank")))
		{
			titan3 = h;
			titan3_a = true;
		}
	}
	
	// TITANS
	else if ((!titan1_a) && (IsOdf2(h,"fvatank")))
	{
		titan1 = h;
		titan_time = GetTime() + 2.0f;
		titan1_a = true;
	}
	else if ((!titan2_a) && (IsOdf2(h,"fvatank")))
	{
		titan2 = h;
		titan2_a = true;
	}
	else if ((!titan3_a) && (IsOdf2(h,"fvatank")))
	{
		titan3 = h;
		titan3_a = true;
	}
/*
	// MAULER
	else if ((!maul1_a) && (IsOdf2(h,"fvwalk")))
	{
		maul1 = h;
		maul1_a = true; 
	}
	else if ((!maul2_a) && (IsOdf2(h,"fvwalk")))
	{
		maul2 = h;
		maul2_a = true; 
	}
	else if ((!maul3_a) && (IsOdf2(h,"fvwalk")))
	{
		maul3 = h;
		maul3_a = true; 
	}
	else if ((!maul4_a) && (IsOdf2(h,"fvwalk")))
	{
		maul4 = h;
		maul4_a = true; 
	}
*/
}
}

void Misn04Mission::Execute(void)
{
/*
	Here is where you put what happens every frame.  
*/

	player = GetPlayerHandle();
	char tempstr[128];


	if (!start_done)
	{
		SetColorFade(1,0.9f,RGBA_MAKE(0, 0, 0, 255));

		MaskEmitter(burns_condor, 0);

		talk = AudioMessage("isdf1301.wav");//(Kossieh) Mission briefing
		ClearObjectives();
		AddObjective("isdf1301.otf", WHITE);

		SetAnimation(burns_condor,"deploy",1);

		Goto(builder1,"builder_point");

		SetObjectiveOn(manson);
		SetObjectiveName(manson,"Maj. Manson");

		war1 = BuildObject("fvtank13",2,"b_point1");
		Stop(war1);
		walker1 = BuildObject("ivwalk",1,"walker1_spawn");
		//Stop(walker1,1);
		LookAt(walker1,spire4);
		walker2 = BuildObject("ivwalk",1,"walker2_spawn");
		//Stop(walker2,1);
		LookAt(walker2,spire4);

		//RemoveObject(recycler);
		//recycler = BuildObject("ivrecy13x",1,"recycler_spawn");
		Stop(recycler);

		Ally(2,1);
		Ally(1,2);
		Ally(1,3);
		Ally(3,1);
		Ally(2,3);
		Ally(3,2);

		SetAvoidType(burns,0);
		SetAvoidType(first_titan1,0);
		SetAvoidType(first_titan2,0);
		SetAvoidType(sent1,0);
		SetAvoidType(sent2,0);

		SetSkill(spire2,3);
		SetSkill(spire3,3);
		SetSkill(spire4,3);
		SetSkill(first_titan1,3);
		SetSkill(first_titan2,3);

		SetPlan("isdf1301.aip",2);

		LookAt(manson,forge);
		LookAt(tank2,forge);

		Patrol(sent1,"patrol_path1",0);
		Patrol(sent2,"patrol_path1a",0);

		honest_check = GetTime() + 2.0f;

		MaskEmitter(show2,0);
		//MaskEmitter(show2,4);
		//MaskEmitter(show2,5);
		//MaskEmitter(show2,6);
		StartEmitter(show2,1);
		StartEmitter(show2,2);

		start_done = true;
	}

	// this is resetting the deaths

	if ((scout1_a) && (!IsAlive(scout1)))
	{
		scout1_a = false;
	}
	if ((scout2_a) && (!IsAlive(scout2)))
	{
		scout2_a = false;
	}
	if ((scout3_a) && (!IsAlive(scout3)))
	{
		scout3_a = false;
	}
	if ((scout4_a) && (!IsAlive(scout4)))
	{
		scout4_a = false;
	}
	
	if ((sent1_a) && (!IsAlive(sent1)))
	{
		sent1_a = false;
		sent1_to_recy = false;
	}
	if ((sent2_a) && (!IsAlive(sent2)))
	{
		sent2_a = false;
		sent2_to_recy = false;
	}
	if ((sent3_a) && (!IsAlive(sent3)))
	{
		sent3_a = false;
	}
	if ((sent4_a) && (!IsAlive(sent4)))
	{
		sent4_a = false;
	}

	if ((war1_a) && (!IsAlive(war1)))
	{
		war1_a = false;
		war1_to_recy = false;
	}
	if ((war2_a) && (!IsAlive(war2)))
	{
		war2_a = false;
		war2_to_recy = false;
	}
	if ((war3_a) && (!IsAlive(war3)))
	{
		war3_a = false;
	}
	if ((war4_a) && (!IsAlive(war4)))
	{
		war4_a = false;
	}

	if ((lance1_a) && (!IsAlive(lance1)))
	{
		lance1_a = false;
	}
	if ((lance2_a) && (!IsAlive(lance2)))
	{
		lance2_a = false;
	}
	if ((lance3_a) && (!IsAlive(lance3)))
	{
		lance3_a = false;
	}
	if ((lance4_a) && (!IsAlive(lance4)))
	{
		lance4_a = false;
	}

	if (titan1_a)
	{
		if (IsAlive(titan1))
		{
			if ((!titan_sent) && (titan_time < GetTime()))
			{
				Goto(titan1,"titan_path");
				titan_sent = true;
			}
		}
		else
		{
			titan_time = GetTime() + 999999.9f;
			titan_sent = false;
			titan1_a = false;
		}
	}

	if ((titan2_a) && (!IsAlive(titan2)))
	{
		titan2_a = false;
	}
	if ((titan3_a) && (!IsAlive(titan3)))
	{
		titan3_a = false;
	}
	////////////////////////////////////////////


	// this is giving the data machine health every frame

	if (GetCurHealth(bigass_building) < 5000)
	{
		SetCurHealth(bigass_building,5000);
	}
	////////////////////////////////////////////



if ((!part_two) && (!game_over))
{
	// this is pilot talk about the situation

	if (start_done)
	{
		if ((!pilot_talk1) && (IsAudioMessageDone(talk)))
		{
			talk = AudioMessage("isdf1302.wav");//(Manson) If he don't get here soon I'm jumpin on that condor
			move_burns_time = GetTime() + 3.5f;

			//carrier_dead = true;
			
			pilot_talk1 = true;
		}

		if ((!pilot_talk2) && (pilot_talk1) && (IsAudioMessageDone(talk)))
		{
			talk = AudioMessage("isdf1303.wav");//(pilot2) Yeah, sitting around in the center of a Scion base is no picnic
			pilot_talk2 = true;
		}

		if ((!pilot_talk3) && (pilot_talk2) && (IsAudioMessageDone(talk)))
		{
			talk = AudioMessage("isdf1304.wav");//(brad) Just see that it gets on that transport
			//move_burns_time = GetTime() + 1.0f;
			pilot_talk3 = true;
		}
	}
	////////////////////////////////////////////

	
	// this sends the first titan

	if ((!titan1_move) && (move_burns_time < GetTime()))
	{
		Goto(war1,player);
		//Goto(first_titan1,"burns_path");
		Goto(first_titan1,"titan1_path3");
		move_burns_time = GetTime() + 6.0f;
		titan1_move = true;
	}
	////////////////////////////////////////////


	// this is sending burns to the shuttle

	if ((!burns_move) && (titan1_move) && (move_burns_time < GetTime()))
	{
		Retreat(burns,"burns_path3");
		Follow(first_titan2,burns);
		burns_check = GetTime() + 1.0f;
		war1_check = GetTime() + 1.0f;
		move_burns_time = 999999.9f;
		parade_check = GetTime() + 20.0f;
		burns_move = true;
	}
	////////////////////////////////////////////


	// this is checking the warrior I sent at John

	if ((burns_move) && (!war_look1) && (war1_check < GetTime()))
	{
		war1_check = GetTime() + 1.0f;

		if (GetDistance(war1,player) < 100.0f)
		{
			//Stop(war1);
			LookAt(war1,player);
			war1_check = GetTime() + 7.0f;
			war_look1 = true;
		}
	}


	if ((war_look1) && (!war_look2) && (war1_check < GetTime()))
	{
		Goto(war1,"war_point2");
		war_look2 = true;
	}


	if ((war_look2) && (!war_look3) && (GetDistance(war1,"war_point2") < 20.0f))
	{
		LookAt(war1,tank2);
		war1_check = GetTime() + 4.0f;
		war_look3 = true;
	}


	if ((war_look3) && (!carrier_dead) && (war1_check < GetTime()))
	{
		if (!at_player)
		{
			LookAt(war1,player);
			war1_check = GetTime() + 4.0f;
			at_player = true;
		}
		else if(!at_manson)
		{
			LookAt(war1,manson);
			war1_check = GetTime() + 4.0f;
			at_manson = true;
		}
		else if(!at_2)
		{
			LookAt(war1,tank2);
			war1_check = GetTime() + 4.0f;
			at_player = false;
			at_manson = false;
		}
	}
	////////////////////////////////////////////


	// this is braddock mentioning that burns is on his way

	if ((!brad_message1) && (parade_check < GetTime()))
	{
		parade_check = GetTime() + 1.0f;

		SetObjectiveOn(burns);
		TranslateString2(tempstr, sizeof(tempstr), "Mission1301");  // Scion Leader
		SetObjectiveName(burns,tempstr);
		talk = AudioMessage("isdf1305.wav");//(Kossieh) here he comes!
		LookAt(walker1,burns);
		LookAt(walker2,burns);
		LookAt(manson,burns);
		LookAt(tank2,burns);
		//LookAt(first_titan1,player);
		Stop(first_titan1);
		titan_look_time = GetTime() + 1.0f;
		brad_message1 = true;
	}
	////////////////////////////////////////////


	// this makes the first titan look at the player

	if ((!titan_look) && (brad_message1) && (titan_look_time < GetTime()))
	{
		titan_look_time = GetTime() + 999999.9f;
		LookAt(first_titan1,player);
		titan_look = true;
	}
	////////////////////////////////////////////


	// this is making sure the player does not move during the opening

	if (!carrier_dead)
	{
		if ((!honest_warning) && (honest_check < GetTime()))
		{
			honest_check = GetTime() + 2.0f;

			if (GetDistance(player,manson) > 40.0f)
			{
				StopAudioMessage(talk);
				ClearObjectives();
				AddObjective("isdf1301.otf", RED);
				talk = AudioMessage("isdf1306.wav");//(Kossieh) I told you to remaim still! Stop your craft immediately!
				pilot_talk1 = true;
				pilot_talk2 = true;
				pilot_talk3 = true;
				honest_warning = true;
			}
		}

		if ((honest_warning) && (honest_check < GetTime()))
		{
			if (GetDistance(player,manson) < 30.0f)
			{
				StopAudioMessage(talk);
				ClearObjectives();
				AddObjective("isdf1301.otf", WHITE);

				// So we don't get stuck if you move at the very start
				if (move_burns_time==999999.9f)
					move_burns_time = GetTime() + 3.5f;

				honest_warning = false;
			}
		}

	}
	////////////////////////////////////////////
	

	// this is checking to see when he gets to the condor

	if ((burns_move) && (!burns_at_condor) && (burns_check < GetTime()))
	{
		burns_check = GetTime() + 1.0f;

		if (GetDistance(burns,"convoycheck_point") < 40.0f)
		{
			Goto(burns,"enter_drop_path");
			LookAt(titan1,player);
			//burns_check = GetTime() + 1.0f;
			burns_at_condor = true;
		}
	}
	////////////////////////////////////////////


	// this is checking to see when he gets into the condor

	if ((burns_at_condor) && (!burns_in_condor))
	{
		if (GetDistance(burns,"in_drop_point") < 25.0f)
		{
			Stop(burns);
			SetObjectiveOff(burns);
			//kick = BuildObject("kickup",0,"in_drop_point");
			//kick1 = BuildObject("kickup",0,"walker1_spawn");
			//kick2 = BuildObject("kickup",0,"walker2_spawn");
			Stop(first_titan2);
			LookAt(first_titan1,first_titan2);
			SetAnimation(burns_condor,"takeoff",1);
			StartEmitter(burns_condor, 1);
			StartEmitter(burns_condor, 2);
			carrier_time = GetTime() + 4.0f;
			burns_in_condor = true;
		}
	}
	////////////////////////////////////////////


	// this is getting rid of burns

	if ((!remove_burns) && (burns_in_condor) && (carrier_time < GetTime()))
	{
		RemoveObject(burns);
		carrier_time = GetTime() + 6.0f;
		remove_burns = true;
	}
	////////////////////////////////////////////


	// this is getting rid of the carrier

	if ((!carrier_dead) && (remove_burns) && (carrier_time < GetTime()))
	{
		RemoveObject(burns_condor);
		//RemoveObject(kick);
		//RemoveObject(kick1);
		//RemoveObject(kick2);
		carrier_time = GetTime() + 999999.9f;
		carrier_dead = true;
	}
	////////////////////////////////////////////


	// this is the movie code

	if ((!movie_over) && (carrier_dead))
	{
		if (!first_frame) 
		{
			CameraReady();
			movie_time = GetTime() + 15.0f;
			explosion_time = GetTime() + 13.0f;
			SetAnimation(show1,"cinteractive",1);
			SetAnimation(show2,"cinteractive",1);
			StartSoundEffect("droppass.wav");
			first_frame = true;
		}
		float curFrame = GetAnimationFrame(show2, "cinteractive");

		if (curFrame > 109)
		{
			if (!explode)
			{
				StartSoundEffect("xfire1.wav");
				//AudioMessage("xfire1.wav");
				explode = true;
			}

			StartEmitter(show2, 4);
		}

		if (curFrame > 122)
		{
			MaskEmitter(show2, 1);
			//StartEmitter(show2, 3);
		}

		//if (curFrame > 123)
		//{
		//	MaskEmitter(show2, 0);
		//	StartEmitter(show2, 4);
		//}
		
		PlayMovie("dropship2");
	}

	


	// this is the explosion

	if ((!main_explosion) && (explosion_time < GetTime()))
	{
		main_explosion = true;
	}
	////////////////////////////////////////////


	if ((!movie_over) && (first_frame) && (movie_time < GetTime()))
	{
		CameraFinish();
		movie_over = true;
	}
	////////////////////////////////////////////


	// this is after the destruction of the carrier

	if ((!confussion) && (movie_over))
	{
		StartEarthQuake(30.0);

		carrier = BuildObject("ivcarr",0,"carrier_spawn");
		//SetAnimation(carrier,"crash",1);

		RemoveObject(show1);
		RemoveObject(show2);

		quake_time = GetTime() + 0.5f;
		panic_time = GetTime() + 5.0f;
		confussion = true;
	}
	////////////////////////////////////////////


	// this is updating the earthquake

	if ((!update_quake) && (confussion) && (quake_time < GetTime()))
	{
		SetAnimation(carrier,"crash",1);
		UpdateEarthQuake(5.0);
		update_quake = true;
	}
	////////////////////////////////////////////


	// this is the panic messages

	if ((confussion) && (!panic_message1) && (panic_time < GetTime()))
	{
		talk = AudioMessage("isdf1307.wav");//(pilot2) The carrier's been blown from the sky!!
		LookAt(tank2,manson);
		panic_message1 = true;
	}

	if ((!panic_message2) && (panic_message1) && (IsAudioMessageDone(talk)))
	{
		talk = AudioMessage("isdf1308.wav");//(Manson) Come in sky 1 - Come in!
		LookAt(manson,player);
		LookAt(tank2,walker1);
		panic_message2 = true;
	}

	if ((!panic_message3) &
		(panic_message2) && (IsAudioMessageDone(talk)))
	{
		talk = AudioMessage("isdf1309.wav");//(pilot2) Ah... what do we do here sir!
		LookAt(manson,tank2);
		LookAt(tank2,manson);
		hell_time = GetTime() + 5.0f;
		panic_message3 = true;
	}
	////////////////////////////////////////////


	// this is when all hell breaks loose

	if ((hell_time < GetTime()) && (!hell))
	{
		StopEarthQuake();
		nav1 = BuildObject("ibnav",1,"nav1_spawn");
		nav2 = BuildObject("ibnav",1,"nav2_spawn");
		SetObjectiveOn(nav1);

		talk2 = AudioMessage("isdf1310a.wav");//(brad) *broken* Get out of there! I've dropped a Recycler 3000 meters to the south-east

		if (IsAround(carrier))
		{
			RemoveObject(carrier);
		}
		
		if (IsAlive(walker1))
		{
			SetCurHealth(walker1,2000);
			Stop(walker1,0);
		}

		if (IsAlive(walker2))
		{
			SetCurHealth(walker2,2000);
			Stop(walker2,0);
		}

		if (IsAlive(builder1))
		{
			Stop(builder1,0);
		}
		
		UnAlly(2,1);
		UnAlly(1,2);
		UnAlly(3,2);
		UnAlly(2,3);

		SetPlan("isdf1302.aip",2);

		honest_check = GetTime() + 2.0f;
		recycler_check = GetTime() + 1.0f;

		hell = true;
	}
	////////////////////////////////////////////
	
	
	// this is braddocks second set of messages

	if ((hell) && (!brad_message2) && (IsAudioMessageDone(talk2)))
	{
		talk2 = AudioMessage("isdf1311.wav");//(pilot1) repeat - cannot cop-AHHHHHHHHHHH! 

		if (IsAlive(manson))
		{
			SetCurHealth(manson,1);
			SetObjectiveOff(manson);
		}

		brad_message2 = true;
	}

	if ((brad_message2) && (!brad_message3) && (IsAudioMessageDone(talk2)))
	{
		if (IsAlive(tank1))
		{
			SetCurHealth(tank1,0);
		}
		else if (IsAlive(tank2))
		{
			SetCurHealth(tank2,0);
		}
		//else if (IsAlive(rocket1))
		//{
		//	SetCurHealth(rocket1,0);
		//}

		ClearObjectives();
		AddObjective("isdf1302.otf", WHITE);
		talk2 = AudioMessage("isdf1312.wav");//(brad) repeat - Get out of there and to the recycler to the south east! 
		escape_check = GetTime() + 2.0f;
		brad_message3 = true;
	}
	////////////////////////////////////////////


	// this is the player getting away from the base
	if ((brad_message3) && (!brad_message4) && (escape_check < GetTime()))
	{
		escape_check = GetTime() + 1.0f;

		if (GetDistance(player,"war_point2") > 750.0f)
		{
			SetObjectiveOn(nav1);
			TranslateString2(tempstr, sizeof(tempstr), "Mission1302");  // Recycler
			SetObjectiveName(nav1,tempstr);
			ClearObjectives();
			AddObjective("isdf1302.otf", GREEN);
			AddObjective("isdf1303.otf", WHITE);
			AudioMessage("isdf1315.wav");//(brad) way to escape! They were jamming me! Get to Recycler!
			brad_message4 = true;
		}
	}


	// this is when the player reaches the recycler

	if ((!at_recycler) && (hell) && (recycler_check < GetTime()))
	{
		recycler_check = GetTime() + 1.0f;

		if (GetDistance(player,recycler) < 150.0f)
		{
			Matrix pos;
			GetPosition(recycler,pos);
			RemoveObject(recycler);
			recycler = BuildObject("ivrecy",1,pos);
			SetGroup(recycler,0);
			AddScrap(1,40);
			SetObjectiveOff(nav1);
			SetObjectiveOn(key_device);
			TranslateString2(tempstr, sizeof(tempstr), "Mission1202");  // Power Source
			SetObjectiveName(key_device,tempstr);
			ClearObjectives();
			AddObjective("isdf1303.otf", GREEN);
			AddObjective("isdf1304.otf", WHITE);
			AudioMessage("isdf1316.wav");// (brad) You've got attack waves on the way son
			set_scrap_time = GetTime() + 1.0f;
			titan_attack_time = GetTime() + 120.0f;
			SetObjectiveOn(nav2);
			TranslateString2(tempstr, sizeof(tempstr), "Mission1303");  // Scrap Field
			SetObjectiveName(nav2,tempstr);

			if (IsAlive(war1))
			{
				Goto(war1,"guard_point1",0);
			}
			if (IsAlive(sent1))
			{
				Goto(sent1,"guard_point2",0);
			}
			if (IsAlive(sent2))
			{
				Goto(sent2,"guard_point3",0);
			}
			//Stop(recycler,0);
			part_two = true;
			at_recycler = true;
		}
	}
	////////////////////////////////////////////
}



	// this is setting the scrap

	if ((at_recycler) && (!set_scrap) && (set_scrap_time < GetTime()))
	{
		set_scrap_time = GetTime() + 999999.9f;
		SetObjectiveOff(recycler);
		//plan_check = GetTime() + 60.0f;
		plan_check = GetTime() + 480.0f;
		//SetPlan("isdf1303.aip",2);
		set_scrap = true;
	}
	////////////////////////////////////////////


	// this is temp attack code
/*
	if(set_scrap)
	{
		if ((war1_a) && (IsAround(recycler)))
		{
			Goto(war1,recycler);
			war1_to_recy = true;
		}

		if ((war2_a) && (IsAround(recycler)))
		{
			Goto(war2,recycler);
			war2_to_recy = true;
		}

		if ((sent1_a) && (IsAround(recycler)))
		{
			Goto(sent1,recycler);
			sent1_to_recy = true;
		}

		if ((sent2_a) && (IsAround(recycler)))
		{
			Goto(sent2,recycler);
			sent2_to_recy = true;
		}
	}
	////////////////////////////////////////////
*/

	// this is setting the next aip

	if (plan_check < GetTime())
	{
		plan_check = GetTime() + 60;

		if (!titan_plan)
		{
			if ((HaveScav()) && (IsAround(overseer)) && (IsAround(stronghold)))
			{
				SetPlan("isdf1303.aip",2);
				titan_plan = true;
			}
		}

		if (titan_plan)
		{
			if (HaveScav2())
			{
				if (!new_plan)
				{
					SetPlan("isdf1304.aip",2);
					new_plan = true;
				}
			}
			else if (new_plan)
			{
				SetPlan("isdf1303.aip",2);
				new_plan = false;
			}
		}
	}
	////////////////////////////////////////////


if ((part_two) && (!game_over))
{
	// this is the titan attack

	if ((!titan_attack) && (titan_attack_time < GetTime()))
	{
		if (IsAlive(first_titan1))
		{
			Goto(first_titan1,"attack_path1",1);
		}

		if (IsAlive(first_titan2))
		{
			Goto(first_titan2,"attack_path1",1);
		}
		
		titan_attack_time = GetTime() + 1.0f;
		titan_attack = true;
	}
	////////////////////////////////////////////


	// this is seding in some scouts to try and stir things up

	if ((!send_scouts) && (titan_attack) && (titan_attack_time < GetTime()))
	{
		titan_attack_time = GetTime() + 1.0f;

		if (IsAlive(first_titan1))
		{
			if (GetDistance(first_titan1,"recycler_spawn") < 50.0f)
			{
				Defend(first_titan1);

				if (scout1_a)
				{
					Goto(scout1,"attack_path2");
				}
				if (scout2_a)
				{
					Goto(scout2,"attack_path2");
				}
				if (scout3_a)
				{
					Goto(scout3,"attack_path2");
				}
				if (scout4_a)
				{
					Goto(scout4,"attack_path2");
				}

				send_scouts = true;
			}
		}
		else if (IsAlive(first_titan2))
		{
			if (GetDistance(first_titan2,"nav1_spawn") < 50.0f)
			{
				Defend(first_titan1);

				if (scout1_a)
				{
					Goto(scout1,"attack_path2");
				}
				if (scout2_a)
				{
					Goto(scout2,"attack_path2");
				}
				if (scout3_a)
				{
					Goto(scout3,"attack_path2");
				}
				if (scout4_a)
				{
					Goto(scout4,"attack_path2");
				}

				send_scouts = true;
			}
		}
		else if (!titan_dead)
		{
			titan_attack_time = GetTime() + 240.0f;
			titan_dead = true;

			if (scout1_a)
			{
				Goto(scout1,"attack_path2");
			}
			if (scout2_a)
			{
				Goto(scout2,"attack_path2");
			}
			if (scout3_a)
			{
				Goto(scout3,"attack_path2");
			}
			if (scout4_a)
			{
				Goto(scout4,"attack_path2");
			}

			send_scouts = true;
		}
	}
	////////////////////////////////////////////


	// this is checking to see if the scavs are destoyed

	if ((sscav1_a) && (!IsAround(sscav1)))
	{
		sscav1_a = false;
	}
	if ((sscav2_a) && (!IsAround(sscav2)))
	{
		sscav2_a = false;
	}
	if ((sscav3_a) && (!IsAround(sscav3)))
	{
		sscav3_a = false;
	}
	if ((sscav4_a) && (!IsAround(sscav4)))
	{
		sscav4_a = false;
	}
	if ((sscav5_a) && (!IsAround(sscav5)))
	{
		sscav5_a = false;
	}
	////////////////////////////////////////////


	// this is getting a scavenger4 to go to pool1
/*
	if (at_recycler)
	{
		if (sscav4_a)
		{
			if (IsAlive(sscav4))
			{
				// first I send him to the pool

				if (!scav4_to_pool)
				{
					Goto(sscav4,pool1);
					scav4_check = GetTime() + 1.0f;
					scav4_to_pool = true;
				}
				////////////////////////////////////////////

				// then I check to see if he is there

				if ((!scav4_at_pool) && (scav4_check < GetTime()))
				{
					scav4_check = GetTime() + 1.0f;


					if (GetDistance(sscav4,pool1) < 50.0f)
					{
						Deploy(sscav4);
						scav4_at_pool = true;
					}
				}
				////////////////////////////////////////////

				
				// this is checking to see when the scavenger is deployed
				
				if ((scav4_at_pool) && (!scav4_deployed))
				{
					if (IsDeployed(sscav4))
					{
						scav4_deployed = true;
					}
				}
				////////////////////////////////////////////
			}
			else if (!scav4_deployed)
			{
				sscav4_a = false;
				scav4_to_pool = false;
				scav4_at_pool = false;
			}
		}
		else
		{
			scav4_to_pool = false;
			scav4_at_pool = false;
			scav4_deployed = false;
		}
	}
	////////////////////////////////////////////
*/

	// this is checking to see if the turrets are destoyed

	if ((guard1_a) && (!IsAlive(guard1)))
	{
		guard1_a = false;
		guard1_sent = false;
		guard1_deployed = false;
	}
	if ((guard2_a) && (!IsAlive(guard2)))
	{
		guard2_a = false;
		guard2_sent = false;
		guard2_deployed = false;
	}
	if ((guard3_a) && (!IsAlive(guard3)))
	{
		guard3_a = false;
		guard3_sent = false;
		guard3_deployed = false;
	}
	if ((guard4_a) && (!IsAlive(guard4)))
	{
		guard4_a = false;
	}
	////////////////////////////////////////////


	// this is getting a guardians to their posts

	if (at_recycler)
	{
		if (!guards_sent)
		{
			if ((!guard1_sent) && (guard1_a))
			{
				Goto(guard1,"guard_point1",1);
				guard1_sent = true;
			}

			if ((!guard2_sent) && (guard2_a))
			{
				Goto(guard2,"guard_point2",1);
				guard2_sent = true;
			}

			if ((!guard3_sent) && (guard3_a))
			{
				Goto(guard3,"guard_point3",1);
				guard3_sent = true;
			}
			
			if ((guard1_sent) && (guard2_sent) && (guard3_sent))
			{
				guards_sent = true;
			}			
		}

		
		// this is always checking the guards

		if (guards_check < GetTime())
		{
			guards_check = GetTime() + 3.0f;


			if ((guard1_sent) && (guard1_a))
			{
				if ((!guard1_deployed) && (GetDistance(guard1,"guard_point1") < 30.0f))
				{
					Deploy(guard1);
					guard1_deployed = true;
				}
			}

			if ((guard2_sent) && (guard2_a))
			{
				if ((!guard2_deployed) && (GetDistance(guard2,"guard_point2") < 30.0f))
				{
					Deploy(guard2);
					guard2_deployed = true;
				}
			}

			if ((guard3_sent) && (guard3_a))
			{
				if ((!guard3_deployed) && (GetDistance(guard3,"guard_point3") < 30.0f))
				{
					Deploy(guard3);
					guard3_deployed = true;
				}
			}
		}
	}


	// this is setting a new aip
/*
	if ((recycler_deployed) && (!plan_change1))
	{
		SetPlan("isdf1303.aip",2);
		guards_check = GetTime() + 3.0f;
		plan_change1 = true;
	}
*/
}



if (!game_over)
{
	// this is if the player wins

	if (IsAround(key_device))
	{
		SetCurHealth(key_device,5000);

		tugger = GetTug(key_device);

		if (IsAlive(tugger))
		{
			if (GetTeamNum(tugger) == 1)
			{
				SucceedMission(GetTime() + 10.0f,"isdf13w1.txt");
				AudioMessage("isdf1313.wav");//(braddock) well done
				game_over = true;
			}
		}
	}
	////////////////////////////////////////////

	// this is the player moves to far during the beginning
	if (!confussion)
	{
		if (honest_check < GetTime())
		{
			if (GetDistance(player,"start_point") > 80.0f)
			{
				UnAlly(2,1);
				UnAlly(1,2);
				AudioMessage("isdf1314.wav");//(Kossieh) They've called off the meeting because of your incompedence!
				FailMission(GetTime() + 15.0f,"isdf13l1.txt");
				game_over = true;
			}
		}

		if ((IsOdf(player,"ivtank13")) && (GetCurAmmo(player_ship) < 1500))
		{
			UnAlly(2,1);
			UnAlly(1,2);
			StopAudioMessage(talk);
			AudioMessage("isdf1317.wav");//(Kossieh) They've called off the meeting because of your incompedence!
			FailMission(GetTime() + 15.0f,"isdf13l1.txt");
			game_over = true;						
		}

		if ((IsOdf(player,"isuser")) && (GetCurAmmo(player) < 100))
		{
			UnAlly(2,1);
			UnAlly(1,2);
			StopAudioMessage(talk);
			AudioMessage("isdf1317.wav");//(Kossieh) They've called off the meeting because of your incompedence!
			FailMission(GetTime() + 15.0f,"isdf13l1.txt");
			game_over = true;						
		}
	}

	if ((!game_over) && (!IsAlive(recycler)))
	{
		game_over=true;
		FailMission(GetTime()+10.0f,"isdf13l2.txt");
	}
} 
}
