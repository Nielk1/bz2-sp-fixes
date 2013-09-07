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
		start_done,free_recycler,part_two,at_city,near_city,search_ordered,search_warning1,
		in_temple,temple_message1,temple_message2,temple_message3,temple_message4,ruin_reset1,
		near_temple,check_temple_message,search_warning2,last_warning,game_over,srecycler_dead,
		start_convoy,end_convoy,srecycler_deployed,
		new_build_orders,lung1_dead,spire1_made,lung1_made,def1_made,spire2_made,lung2_made,
		def2_made,bridge_spire1_made,bridge_lung1_made,bridge_def1_made,both_builders,
		build_def1,build_lung1,build_spire1,build_def2,build_lung2,build_spire2,
		bridge_build_def1,bridge_build_lung1,bridge_build_spire1,player_across,
		return_message1,return_message2,bombbay_built,bombbay_destroyed,bomber_landed,
		first_set,bomber_spawn,bomber_reroute,remove_bomber,at_bridge2,at_bridge3,
		search_message1,bomber_message1,bomber_message2,bomber_message3,bomber_message4,bomber_message5,bomber_message6,
		bomber_take_off,nav_noshow,bomb_going_message,bridge_colapse,shab_pissed,shuttle_message,

		bombbay_a,builder1_a,builder2_a,first_bridge,srecycler_message,srecy_found,bomber_message,
		recycler_message,first_contact,spire1_a,spire2_a,bridgespire_a,
		to1,at1,build1,to2,at2,build2,to_bridgespire,at_bridgespire,build_bridgespire,
		guard1_a, guard2_a, guard3_a,guard4_a,sent1_a, sent2_a,sent3_a, sent4_a,war1_a,war2_a, war3_a, war4_a,
		sscout1_a,sscout2_a,sscout3_a,sscout4_a,scout_contact,scout_to_base,first_attack,scout_attack,
		bomber_a,wrecker_a,remove_bomber1,guard1_to_point,guard2_to_point,guard3_to_point,guard4_to_point,
		ON_HOLD,scout_free,player_clear,condor2_away,condor1_remove,condor2_remove,build_smoke,keep_moving,
		kill_ruin,quake_started,check_convoy,fight_message,door_open_sound,
		b_last;

	// floats
	float
		f_first,
		recy_check,city_check,search_check1,search_check2,search_check3,next_message_time,
		warning_time,convoy_check,bridge_check,across_time,bomber_spawn_time,reroute_check,
		across_time2,message_wait,nav_check,return_time,colapse_time,fall_check,spire_check,
		first_scout_check,bomber_check,last_check,turret_time,convoy_time,
		condor1_time,condor2_time,holder_time,smoke_time,cheat_time,damage_time,quake_time,
		f_last;

	// handles
	Handle
		h_first,
		player,recycler,
		start_sent1,start_sent2,start_war1,start_war2,
		start_scout1,start_scout2,start_scout3,start_scout4,
		srecycler,forge,dower,overseer,stronghold,
		s1_turret1,s1_turret2,s1_turret3,s1_turret4,
		s1_scav1,s1_scav2,s1_scav3,
		center_ruin,
		tunnel1, tunnel2,
		builder1,builder2,
		guard1, guard2, guard3, guard4,
		sent1, sent2, sent3, sent4,
		war1, war2, war3, war4,
		lance1, lance2, lance3, lance4,
		sscout1, sscout2, sscout3, sscout4,
		sscav1,sscav2,
		def1,def2,
		spire1,spire2,bridgespire,
		lung1,lung2,
		bridge_def1,bridge_def2,
		bridge_lung1,bridge_lung2,
		bridge_spire1,bridge_spire2,
		bomber_bay,bomber,bridge,
		bridge_nav,
		base_pool1,base_pool2,base_pool3,
		talk,rescue_nav,
		condor1,condor2,ivturr1,ivturr2,
		cave,holder,smoker1,smoker2,
		bomber1,nav2,
		cheat_war1,cheat_war2,
		ruin1,ruin2,ruin3,ruin4,
		transmitter,cave_nav,dropship,
		convoy_scav1,convoy_scav2,convoy_cons,
		cpool1,cpool2,
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

void Misn04Mission::Setup(void)
{
	SetAutoGroupUnits(false);
	/*
	Here's where you set the values at the start.  
	*/

	//  bools
	ON_HOLD = false;
	build_smoke = false;
	start_done = false;
	part_two = false;
	at_city = false;
	free_recycler = false;
	near_city = false;
	search_ordered = false;
	search_warning1 = false;
	in_temple = false;
	temple_message1 = false;
	temple_message2 = false;
	temple_message3 = false;
	temple_message4 = false;
	ruin_reset1 = false;
	near_temple = false;
	check_temple_message = false;
	search_warning2 = false;
	last_warning = false;
	game_over = false;
	srecycler_dead = false;
	start_convoy = false;
	end_convoy = false;
	srecycler_deployed = false;
	new_build_orders = false;
	lung1_dead = false;
	spire1_made = false;
	lung1_made = false;
	def1_made = false;
	spire2_made = false;
	lung2_made = false;
	def2_made = false;
	bridge_spire1_made = false;
	bridge_lung1_made = false;
	bridge_def1_made = false;
	both_builders = false;
	build_def1 = false;
	build_lung1 = false;
	build_spire1 = false;
	build_def2 = false;
	build_lung2 = false;
	build_spire2 = false;
	bridge_build_def1 = false;
	bridge_build_lung1 = false;
	bridge_build_spire1 = false;
	player_across = false;
	return_message1 = false;
	return_message2 = false;
	bombbay_built = false;
	bombbay_destroyed = true;
	bomber_landed = false;
	first_set = false;
	bomber_spawn = false;
	bomber_reroute = false;
	remove_bomber = false;
	at_bridge2 = false;
	at_bridge3 = false;
	search_message1 = false;
	bomber_message1 = false;
	bomber_message2 = false;
	bomber_message3 = false;
	bomber_message4 = false;
	bomber_message5 = false;
	bomber_message6 = false;
	bomber_take_off = false;
	nav_noshow = false;
	bomb_going_message = false;
	bridge_colapse = false;
	shab_pissed = false;
	shuttle_message = false;
	bombbay_a = false;
	builder1_a = false;
	builder2_a = false;
	first_bridge = false;
	srecycler_message = false;
	srecy_found = false;

	bomber_message = false; // make sure you change this back

	recycler_message = false;
	first_contact = false;
	spire1_a = false; spire2_a = false; bridgespire_a = false;
	to1 = false; at1 = false; build1 = false; 
	to2 = false; at2 = false; build2 = false; 
	to_bridgespire = false; at_bridgespire = false; build_bridgespire = false; 
	sscout1_a = false; sscout2_a = false; sscout3_a = false; sscout4_a = false; 
	guard1_a = false; guard2_a = false; guard3_a = false; guard4_a = false;
	sent1_a = false; sent2_a = false; sent3_a = false; sent4_a = false;
	war1_a = false; war2_a = false; war3_a = false; war4_a = false;
	scout_contact = false; scout_attack = false;
	scout_to_base = false;
	first_attack = false;
	bomber_a = false;wrecker_a = false;remove_bomber1 = false;
	guard1_to_point = false;guard2_to_point = false;guard3_to_point = false;guard4_to_point = false;
	scout_free = false;
	player_clear = false;
	condor2_away = false;
	condor1_remove = false; condor2_remove = false;
	keep_moving = false; kill_ruin = false;
	quake_started = false;
	check_convoy = false;
	fight_message = false;
	door_open_sound = false;



	//  floats
	recy_check = 999999.9f;
	city_check = 999999.9f;
	search_check1 = 999999.9f;
	search_check2 = 999999.9f;
	search_check3 = 999999.9f;
	next_message_time = 999999.9f;
	warning_time = 999999.9f;
	convoy_check = 999999.9f;
	bridge_check = 2.0f;
	across_time = 999999.9f;
	bomber_spawn_time = 999999.9f;
	reroute_check = 999999.9f;
	across_time2 = 999999.9f;
	message_wait = 999999.9f;
	nav_check = 999999.9f;
	return_time = 999999.9f;
	colapse_time = 999999.9f;
	fall_check = 5.0f;
	spire_check = 999999.9f;
	first_scout_check = 999999.9f;
	bomber_check = 999999.9f;
	last_check = 999999.9f;
	turret_time = 999999.9f;
	convoy_time = 999999.9f;
	condor1_time = 999999.9f;
	condor2_time = 999999.9f;
	holder_time = 999999.9f;
	smoke_time = 999999.9f;
	cheat_time = 999999.9f;
	damage_time = 999999.9f;
	quake_time = 30.0f;

	//  handles
	player = GetPlayerHandle();
	recycler = GetHandle("recycler");
	srecycler = GetHandle("srecycler");
	forge = GetHandle("forge");
	dower = GetHandle("dower");
	overseer = GetHandle("overseer");
	//stronghold = GetHandle("stronghold");
	s1_turret1 = GetHandle("s1_turret1");
	s1_turret2 = GetHandle("s1_turret2");
	s1_turret3 = GetHandle("s1_turret3");
	s1_turret4 = GetHandle("s1_turret4");
	s1_scav1 = GetHandle("s1_scav1");
	s1_scav2 = GetHandle("s1_scav2");
	s1_scav3 = GetHandle("s1_scav3");
	center_ruin = GetHandle("center_ruin");
	//base_pool1 = GetHandle("base_pool1");
	//base_pool2 = GetHandle("base_pool2");
	//base_pool3 = GetHandle("base_pool3");
	start_sent1 = GetHandle("sent1");
	start_sent2 = GetHandle("sent2");
	start_war1 = GetHandle("war1");
	start_war2 = GetHandle("war2");
	start_scout1 = GetHandle("start_scout1");
	start_scout2 = GetHandle("start_scout2");
	start_scout3 = GetHandle("start_scout3");
	start_scout4 = GetHandle("start_scout4");
	condor1 = GetHandle("condor1");
	condor2 = GetHandle("condor2");
	ivturr1 = GetHandle("ivturr1");
	ivturr2 = GetHandle("ivturr2");
	cave = GetHandle("cave");
	ruin1 = GetHandle("ruin1");
	ruin2 = GetHandle("ruin2");
	ruin3 = GetHandle("ruin3");
	ruin4 = GetHandle("ruin4");
	transmitter = GetHandle("transmitter");
	convoy_scav1 = GetHandle("convoy_scav1");
	convoy_scav2 = GetHandle("convoy_scav2");
	convoy_cons = GetHandle("convoy_cons");
	cpool1 = GetHandle("cpool1");
	cpool2 = GetHandle("cpool2");
	dropship = NULL;
	cave_nav = NULL;
	nav2 = NULL;
	smoker1 = NULL;smoker2 = NULL;
	holder = NULL;
	guard1 = NULL;
	guard2 = NULL;
	guard3 = NULL;
	guard4 = NULL;
	builder1 = NULL;
	builder2 = NULL;
	sent1 = NULL;
	sent2 = NULL;
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
	sscout1 = NULL;
	sscout2 = NULL;
	sscout3 = NULL;
	sscout4 = NULL;
	sscav1 = NULL;
	sscav2 = NULL;
	spire1 = NULL;
	spire2 = NULL;
	bridgespire = NULL;
	def1 = NULL;
	def2 = NULL;
	lung1 = NULL;
	lung2 = NULL;
	bridge_def1 = NULL;
	bridge_def2 = NULL;
	bridge_lung1 = NULL;
	bridge_lung2 = NULL;
	bridge_spire1 = NULL;
	bridge_spire2 = NULL;
	bomber_bay = NULL;
	bomber = NULL;
	bridge = NULL;
	bridge_nav = NULL;
	bomber1 = NULL;
	rescue_nav = NULL;
	cheat_war1 = NULL;
	cheat_war2 = NULL;
	talk = 0;



	//  integers


}

void Misn04Mission::AddObject(Handle h)
{
	char ODFName[64];
	GetObjInfo(h, Get_CFG, ODFName);

	if (start_done)
	{
		// BOMBER BAY
		if ((!bombbay_a) && (IsOdf2(h,"ibbomb")))
		{
			bomber_bay = h;
			bombbay_a = true;
		}

		// BOMBERS
		else if ((!bomber_a) && (IsOdf2(h,"ivbomb")))
		{
			bomber = h;
			bomber_a = true;
		}

		// BOMBERS
		else if ((!wrecker_a) && (IsOdf2(h,"apwrck")))
		{
			wrecker_a = true;
		}

		// SCOUT
		else if ((!sscout1_a) && (IsOdf2(h,"fvscout")))
		{
			sscout1 = h;
			sscout1_a = true;
		}
		else if ((!sscout2_a) && (IsOdf2(h,"fvscout")))
		{
			sscout2 = h;
			sscout2_a = true;
		}
		else if ((!sscout3_a) && (IsOdf2(h,"fvscout")))
		{
			sscout3 = h;
			sscout3_a = true;
		}
		else if ((!sscout4_a) && (IsOdf2(h,"fvscout")))
		{
			sscout4 = h;
			sscout4_a = true;
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

		// SENTRY
		else if ((!sent1_a) && (IsOdf2(h,"fvsent")))
		{
			sent1 = h;
			sent1_a = true;
		}
		else if ((!sent2_a) && (IsOdf2(h,"fvsent")))
		{
			sent2 = h;
			sent2_a = true;
		}
		else if ((!sent3_a) && (IsOdf2(h,"fvsent")))
		{
			sent3 = h;
			sent3_a = true;
		}
		else if ((!sent4_a) && (IsOdf2(h,"fvsent")))
		{
			sent4 = h;
			sent4_a = true;
		}

		// WARRIOR
		else if ((!war1_a) && (IsOdf2(h,"fvtank")))
		{
			war1 = h;
			war1_a = true;
		}
		else if ((!war2_a) && (IsOdf2(h,"fvtank")))
		{
			war2 = h;
			war2_a = true;
		}
		else if ((!war3_a) && (IsOdf2(h,"fvtank")))
		{
			war3 = h;
			war3_a = true;
		}
		else if ((!war4_a) && (IsOdf2(h,"fvtank")))
		{
			war4 = h;
			war4_a = true;
		}

		// LANCER
		else if ((lance1 == NULL) && (IsOdf2(h,"fvarch")))
		{
			lance1 = h;
		}
		else if ((lance2 == NULL) && (IsOdf2(h,"fvarch")))
		{
			lance2 = h;
		}
		else if ((lance3 == NULL) && (IsOdf2(h,"fvarch")))
		{
			lance3 = h;
		}
		else if ((lance4 == NULL) && (IsOdf2(h,"fvarch")))
		{
			lance4 = h;
		}

		// SCAVENGERS
		else if ((sscav1 == NULL) && (IsOdf2(h,"fvscav")))
		{
			sscav1 = h;
		}
		else if ((sscav2 == NULL) && (IsOdf2(h,"fvscav")))
		{
			sscav2 = h;
		}

		// BUILDERS
		else if ((!builder1_a) && (IsOdf2(h,"fvcons")))
		{
			builder1 = h;
			builder1_a = true;

		}
		else if ((!builder2_a) && (IsOdf2(h,"fvcons")))
		{
			builder2 = h;
			builder2_a = true;
		}

		// SPIRES
		else if ((!spire1_a) && (IsOdf2(h,"fbspir")))
		{
			spire1 = h;
			spire1_a = true;
		}
		else if ((!spire2_a) && (IsOdf2(h,"fbspir")))
		{
			spire2 = h;
			spire2_a = true;
		}
		else if ((!bridgespire_a) && (IsOdf2(h,"fbspir")))
		{
			bridgespire = h;
			bridgespire_a = true;
		}

		// NAV BEACONS
		else if ((bridge_nav == NULL) && (IsOdf2(h,"ibnav")))
		{
			if (bomber_message2)
			{
				if (GetDistance(h,"bridge_center") < 70.0f)
				{
					bridge_nav = h;
				}
			}
		}
	}
}


void Misn04Mission::Execute(void)
{
	/*
	Here is where you put what happens every frame.  
	*/

	player = GetPlayerHandle();

	char tempstr[128];
	//////////////////////////////////////////////////////////
	if (!ON_HOLD)
	{
		//////////////////////////////////////////////////////////



		if((!IsAround(srecycler)) && (!srecycler_dead))
		{
			SetPlan("isdf1103.aip",2);
			spire_check = GetTime() + 999999.9f;
			turret_time = GetTime() + 999999.9f;
			srecycler_dead = true;
		}


		// this is keeping the bridge alive until I'm ready

		if (IsAround(bridge))
		{
			if (GetCurHealth(bridge) < 2000)
			{
				SetCurHealth(bridge,2000);
			}
		}
		////////////////////////////////////////////


		// this is reseting the bomber bay 

		if ((bombbay_a) && (!IsAround(bomber_bay)))
		{
			bombbay_a = false;
		}


		if ((bomber_a) && (!IsAround(bomber)))
		{
			bomber_a = false;
		}
		////////////////////////////////////////////


		// this is reseting the alive/dead bools

		if ((sscout1_a) && (!IsAlive(sscout1)))
		{
			sscout1_a = false;
		}
		if ((sscout2_a) && (!IsAlive(sscout2)))
		{
			sscout2_a = false;
		}
		if ((sscout3_a) && (!IsAlive(sscout3)))
		{
			sscout3_a = false;
		}
		if ((sscout4_a) && (!IsAlive(sscout4)))
		{
			sscout4_a = false;
		}

		if ((guard1_a) && (!IsAlive(guard1)))
		{
			guard1_to_point = false;
			guard1_a = false;
		}
		if ((guard2_a) && (!IsAlive(guard2)))
		{
			guard2_to_point = false;
			guard2_a = false;
		}
		if ((guard3_a) && (!IsAlive(guard3)))
		{
			guard3_to_point = false;
			guard3_a = false;
		}
		if ((guard4_a) && (!IsAlive(guard4)))
		{
			guard4_to_point = false;
			guard4_a = false;
		}

		if ((sent1_a) && (!IsAlive(sent1)))
		{
			sent1_a = false;
		}
		if ((sent2_a) && (!IsAlive(sent2)))
		{
			sent2_a = false;
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
		}
		if ((war2_a) && (!IsAlive(war2)))
		{
			war2_a = false;
		}
		if ((war3_a) && (!IsAlive(war3)))
		{
			war3_a = false;
		}
		if ((war4_a) && (!IsAlive(war4)))
		{
			war4_a = false;
		}


		/*
		////////////// THIS IS TEMP //////////////
		if (!start_done)
		{
		start_done = true;
		}
		//////////////////////////////////////////
		*/


		// start of the mission

		//////////////////////////////////////////////////////////
		if (!ON_HOLD)
		{
			//////////////////////////////////////////////////////////


			if (!start_done)
			{
				SetColorFade(1,0.5f,RGBA_MAKE(0, 0, 0, 255));

				MaskEmitter(condor1, 0);
				StartEmitter(condor2, 1);
				StartEmitter(condor2, 2);

				AddScrap(1,40);
				AddScrap(2,40);

				Ally(3,1);
				Ally(1,3);

				SetPlan("isdf1101.aip",2);

				holder = BuildObject("stayput",0,player);
				holder_time = GetTime() + 3.0f;
				//smoker1 = BuildObject("kickupw",0,"smoke2_a");
				//smoker2 = BuildObject("kickupw",0,"smoke2_b");
				smoke_time = GetTime() + 5.0f;

				//Goto(s1_scav1,base_pool1);
				//Goto(s1_scav2,base_pool2);
				//Goto(s1_scav3,base_pool3);
				/*
				AddAmmo(start_sent1,2000);
				AddAmmo(start_sent2,2000);
				AddAmmo(start_war1,2000);
				AddAmmo(start_war2,2000);
				AddAmmo(start_scout1,2000);
				AddAmmo(start_scout2,2000);
				AddAmmo(start_scout3,2000);
				AddAmmo(start_scout4,2000);
				*/
				SetAvoidType(srecycler,0);
				SetAvoidType(start_sent1,0);
				SetAvoidType(start_sent2,0);
				SetAvoidType(start_war1,0);
				SetAvoidType(start_war2,0);
				SetAvoidType(convoy_scav1,0);
				SetAvoidType(convoy_scav2,0);
				//SetAvoidType(convoy_cons,0);
				RemoveObject(convoy_cons);

				Follow(convoy_scav1,srecycler);
				Follow(convoy_scav2,convoy_scav1);
				//Follow(convoy_cons,convoy_scav2);

				SetAvoidType(ivturr1,0);
				SetAvoidType(ivturr2,0);
				Follow(ivturr1,player,0);
				Follow(ivturr2,player,0);
				SetAnimation(condor1,"deploy",1);
				SetAnimation(condor2,"takeoff",1);
				StartSoundEffect("dropleav.wav",condor2);
				condor2_time = GetTime() + 10.0f;

				convoy_time = GetTime() + 180.0f;
				first_scout_check = GetTime() + 3.0f;
				start_done = true;
			}


			// this removes the holder

			if (holder_time < GetTime())
			{
				RemoveObject(holder);
				holder_time = GetTime() + 999999.9f;
			}
			////////////////////////////////////////////


			// this removes the smokers

			if ((condor2_away) && (smoke_time < GetTime()))
			{
				if (!build_smoke)
				{
					StartSoundEffect("dropleav.wav",condor1);
					StartEmitter(condor1, 1);
					StartEmitter(condor1, 2);
					//smoker1 = BuildObject("kickupw",0,"smoke1_a");
					//smoker2 = BuildObject("kickupw",0,"smoke1_b");		
					smoke_time = GetTime() + 5.0f;
					build_smoke = true;
				}
				else
				{
					//RemoveObject(smoker1);
					//RemoveObject(smoker2);
					smoke_time = GetTime() + 999999.9f;
				}
			}

			else if (smoke_time < GetTime())
			{
				//RemoveObject(smoker1);
				//RemoveObject(smoker2);
				smoke_time = GetTime() + 999999.9f;
			}
			////////////////////////////////////////////


			// tells the two turrets to follow the player

			if ((!player_clear) && (start_done))
			{
				if (GetDistance(player,ivturr1) > 40.0f)
				{
					AudioMessage("isdf1101.wav");//(shab) alright John, you're on your own - lets get a base established
					ClearObjectives();
					AddObjective("isdf1101.otf", WHITE);
					AddObjective("isdf1102.otf", WHITE);	
					Goto(ivturr1,"turret_go",0);
					Goto(ivturr2,"turret_go",0);
					player_clear = true;
				}
			}
			////////////////////////////////////////////


			// tells the second condor to take off

			if ((!condor2_away) && (player_clear))
			{
				if ((GetDistance(ivturr1,"condor_center") > 20.0f) && (GetDistance(ivturr2,"condor_center") > 20.0f))
				{
					SetAnimation(condor1,"takeoff",1);
					condor1_time = GetTime() + 8.0f;
					smoke_time = GetTime() + 3.0f;
					condor2_away = true;
				}
			}
			////////////////////////////////////////////


			// this holding the recycler until I am ready

			if (!start_convoy)
			{
				Stop(srecycler);
			}
			////////////////////////////////////////////


			// this starts the convoy

			if ((!start_convoy) && (convoy_time < GetTime()))
			{
				Retreat(srecycler,"convoy_path2");
				Follow(start_sent1,srecycler,0);
				Follow(start_sent2,start_sent1,0);
				Follow(start_war1,srecycler,0);
				Follow(start_war2,start_war1,0);
				convoy_check = GetTime() + 3.0f;
				start_convoy = true;
			}
			////////////////////////////////////////////


			// this gets rid of the condor

			if ((!condor2_remove) && (condor2_time < GetTime()))
			{
				RemoveObject(condor2);
				condor2_remove = true;
			}

			if ((!condor1_remove) && (condor1_time < GetTime()))
			{
				RemoveObject(condor1);
				condor1_remove = true;
			}
			////////////////////////////////////////////



			// this is monitoring the scion recycler

			if (!srecycler_dead)
			{
				// checking to see if the srecycler reaches the bridge

				if ((!end_convoy) && (start_convoy) && (convoy_check < GetTime()))
				{
					convoy_check = GetTime() + 3.0f;

					if ((!srecycler_message) && (GetDistance(srecycler,"bridge_center") < 100.0f))
					{
						if (GetDistance(player,srecycler) > 150.0f)
						{
							if (first_bridge)
							{
								ClearObjectives();
								AddObjective("isdf1103.otf", WHITE);
								AddObjective("isdf1102.otf", WHITE);
								talk = AudioMessage("isdf1102.wav");//(brad) Detecing a scion recycler moving across the bridge!
								//cave_nav = BuildObject("ibnav",1,"cave_nav_point");	
								SetObjectiveOn(srecycler);
								TranslateString2(tempstr, sizeof(tempstr), "Mission1101");  // Convoy
								SetObjectiveName(srecycler,tempstr);
								srecycler_message = true;
							}
							else
							{
								ClearObjectives();
								AddObjective("isdf1103.otf", WHITE);
								AddObjective("isdf1102.otf", WHITE);
								talk = AudioMessage("isdf1103.wav");//(brad) Detecing a scion recycler moving across A LAND bridge!
								//cave_nav = BuildObject("ibnav",1,"cave_nav_point");	
								SetObjectiveOn(srecycler);
								TranslateString2(tempstr, sizeof(tempstr), "Mission1101");  // Convoy
								SetObjectiveName(srecycler,tempstr);
								srecycler_message = true;
							}
						}
						else if (GetDistance(player,srecycler) < 250.0f)
						{
							ClearObjectives();
							AddObjective("isdf1103.otf", WHITE);
							AddObjective("isdf1102.otf", WHITE);
							talk = AudioMessage("isdf1104.wav");//(brad) There's a Scion convoy headed your way! Stop it!
							//cave_nav = BuildObject("ibnav",1,"cave_nav_point");	
							SetObjectiveOn(srecycler);
							TranslateString2(tempstr, sizeof(tempstr), "Mission1101");  // Convoy
							SetObjectiveName(srecycler,tempstr);
							srecycler_message = true;
						}
					}


					if ((srecycler_message) && (!srecy_found))
					{
						if (GetDistance(player,srecycler) < 200.0f)
						{
							SetObjectiveOff(srecycler);

							ClearObjectives();
							//SetPlan("isdf1103.aip",2);
							AddObjective("isdf1103.otf", GREEN);
							AddObjective("isdf1104.otf", WHITE);
							AddObjective("isdf1102.otf", WHITE);
							//AudioMessage("isdf1112.wav");//(brad) I don't like the look of this - they're up to something!

							if (IsAlive(start_war1))
							{
								Attack(start_war1,player);
							}	

							if (IsAlive(start_war2))
							{
								Attack(start_war2,player);
							}	

							if (!scout_attack)
							{
								if ((IsAround(start_scout1)) && (IsAlive(start_scout1)))
								{
									Goto(start_scout1,"attack_path1");
								}

								if ((IsAround(start_scout2)) && (IsAlive(start_scout2)))
								{
									Goto(start_scout2,"attack_path1");
								}

								if ((IsAround(start_scout3)) && (IsAlive(start_scout3)))
								{
									Goto(start_scout3,"attack_path2");
								}

								if ((IsAround(start_scout4)) && (IsAlive(start_scout4)))
								{
									Goto(start_scout4,"attack_path2");
								}

								scout_attack = true;
							}

							srecy_found = true;
						}

						if (GetDistance(srecycler,"deploy_point") < 300.0f)
						{
							SetObjectiveOff(srecycler);

							ClearObjectives();
							AddObjective("isdf1103.otf", RED);
							AddObjective("isdf1104.otf", WHITE);
							AddObjective("isdf1102.otf", WHITE);

							if (!scout_attack)
							{
								if ((IsAround(start_scout1)) && (IsAlive(start_scout1)))
								{
									Goto(start_scout1,"attack_path1");
								}

								if ((IsAround(start_scout2)) && (IsAlive(start_scout2)))
								{
									Goto(start_scout2,"attack_path1");
								}

								if ((IsAround(start_scout3)) && (IsAlive(start_scout3)))
								{
									Goto(start_scout3,"attack_path2");
								}

								if ((IsAround(start_scout4)) && (IsAlive(start_scout4)))
								{
									Goto(start_scout4,"attack_path2");
								}

								scout_attack = true;
							}					

							srecy_found = true;		
							//bomber_message = true;	
						}							
					}


					// this is shab telling cook to check it out

					if ((srecycler_message) && (!check_convoy) && (IsAudioMessageDone(talk)))
					{
						AudioMessage("isdf1142.wav");//(shab) All right check out the convoy!
						check_convoy = true;
					}


					// this is keeping the scion recycler going

					if ((srecy_found) && (!keep_moving))
					{
						Retreat(srecycler,"deploy_point");
						keep_moving = true;
					}
					////////////////////////////////////////////


					// this tells the recycler to deploy

					if (GetDistance(srecycler,"deploy_point") < 50.0f)
					{
						SetPlan("isdf1102.aip",2);
						//Dropoff(srecycler,"srecy_drop");

						ClearObjectives();
						AddObjective("isdf1104.otf", WHITE);
						AddObjective("isdf1102.otf", WHITE);

						nav2 = BuildObject("ibnav",1,"nav2_point");
						SetObjectiveOn(nav2);
						TranslateString2(tempstr, sizeof(tempstr), "Mission1102");  // Convoy
						SetObjectiveName(nav2, tempstr);

						if (GetDistance(player,srecycler) > 200.0f)
						{
							AudioMessage("isdf1105.wav");//(brad) We've lost track of those vehicles somewhere to the southwest of the bridge Find it!
						}

						if (IsAlive(start_sent1))
						{
							Stop(start_sent1,0);
						}

						if (IsAlive(start_sent2))
						{
							Stop(start_sent2,0);
						}

						if (IsAlive(start_war1))
						{
							Stop(start_war1,0);
						}

						if (IsAlive(start_war2))
						{
							Stop(start_war2,0);
						}

						if (IsAlive(convoy_scav1))
						{
							Goto(convoy_scav1,cpool1);
						}

						if (IsAlive(convoy_scav2))
						{
							Goto(convoy_scav2,cpool2);
						}

						//if (IsAlive(convoy_cons))
						//{
						//	Stop(convoy_cons,0);
						//}

						end_convoy = true;
					}
				}
				////////////////////////////////////////////
			}
			else
			{
				if (!bomber_message)
				{		
					//AudioMessage("isdf1112.wav"); //(brad) alright shab juice up my bomber - John go and drop nav at bridge - I'll tell you where
					AudioMessage("isdf1141.wav");//(brad) Good work Soldier that bridge leaves our right flank too open! go and drop a nav!			
					ClearObjectives();
					//AddObjective("isdf1106.otf", GREEN);
					//AddObjective("isdf1105.otf", WHITE);
					AddObjective("isdf1107.otf", WHITE);
					//SetTeamNum(bomber_bay,0);
					//SetTeamNum(bomber,0);
					//Ally(0,1);
					//Ally(1,0);

					if (IsAround(nav2))
					{
						SetObjectiveOff(nav2);
					}

					bridge_check = GetTime() + 1.0f;
					bomber_message1 = true;
					bomber_message = true;
				}
			}
			////////////////////////////////////////////


			// this is the first scout scout encounter

			if (!srecycler_message)
			{
				if (IsAlive(start_scout1))
				{
					if ((start_convoy) && (!scout_free))
					{
						Goto(start_scout1,"attack_path1",0);
						scout_free = true;
					}

					// scout attacks player

					if ((!scout_contact) && (first_scout_check < GetTime()))
					{
						first_scout_check = GetTime() + 2.0f;

						if (!door_open_sound)
						{
							StartSoundEffect("dropdoor.wav");
							door_open_sound = true;
						}

						if (GetDistance(player,start_scout1) < 300.0f)
						{
							Attack(start_scout1,player);
							scout_contact = true;
						}
					}

					// scout runs to players base

					if ((scout_contact) && (!scout_to_base))
					{
						if (GetCurHealth(start_scout1) < 400)
						{
							Attack(start_scout1,recycler,0);
							first_scout_check = GetTime() + 2.0f;
							scout_to_base = true;
						}
					}

					if ((scout_to_base) && (!scout_attack) && (first_scout_check < GetTime()))
					{
						first_scout_check = GetTime() + 2.0f;

						if (GetDistance(start_scout1,recycler) < 300.0f)
						{
							//SetPlan("isdf1103.aip",2);

							if ((IsAround(start_scout2)) && (IsAlive(start_scout2)))
							{
								Goto(start_scout2,"attack_path1",0);
							}

							if ((IsAround(start_scout3)) && (IsAlive(start_scout3)))
							{
								Goto(start_scout3,"attack_path2",0);
							}

							if ((IsAround(start_scout4)) && (IsAlive(start_scout4)))
							{
								Goto(start_scout4,"attack_path1",0);
							}

							scout_attack = true;
						}
					}
				}
			}


			//////////////////////////////////////////////////////////
		}
		//////////////////////////////////////////////////////////


		// this is bridge code


		// this is checking to see if the player goes across the bridge

		if ((bridge_check < GetTime()) && (!player_across))
		{
			bridge_check = GetTime() + 0.5f;

			if (!bomber_message1)
			{
				if (!recycler_message)
				{
					//if ((!first_contact) && (GetDistance(player,"first_point") < 250.0f))
					//{
					//	AudioMessage("isdf1108.wav");//(shab) looks like a city ruin
					//	first_contact = true;
					//}

					if ((!first_bridge) && (GetDistance(player,"bridge_center") < 150.0f))
					{
						AudioMessage("isdf1109.wav");//(shab) That's the cave - it looks unstable best to stay on this side of the cravass
						first_bridge = true;
					}
				}

				if 	(((GetDistance(player,"bridge_check2") < GetDistance(player,"bridge_center")))
					|| ((GetDistance(player,"bridge_check3") < GetDistance(player,"bridge_center"))))
				{
					//across_time = GetTime() + 300.0f;
					player_across = true;
				}
			}
			else if (bomber_message1)
			{
				if (!bomber_message2)
				{
					if (GetDistance(player,"bridge_center") < 200.0f)
					{
						//SetPlan("isdf1101.aip,2");
						talk = AudioMessage("isdf1116.wav");//(brad) *disturbance* that's good there drop the nav!
						nav_check = GetTime() + 10.0f;
						bomber_message2 = true;
					}
				}


				if (bomber_message6)
				{
					if (GetDistance(player,"bridge_check2") < 100.0f)
					{
						across_time2 = GetTime() + 300.0f;
						at_bridge2 = true;
						player_across = true;
					}
					if  (GetDistance(player,"bridge_check3") < 100.0f)
					{
						across_time2 = GetTime() + 300.0f;
						at_bridge3 = true;
						player_across = true;
					}
				}
			}
		}

		/*
		if (!bomber_message1)
		{
		if ((player_across) && (!return_message1))
		{
		AudioMessage("wohoo.wav"); // (braddock) I ordered you to not go accross - You have got 2 minutes to return to your post!
		across_time = GetTime() + 120.0f;
		return_message1 = true;
		}


		if ((player_across) && (across_time < GetTime()) && (!return_message2))
		{
		AudioMessage("wohoo.wav"); // (braddock) 
		across_time = GetTime() + 120.0f;
		return_message2 = true;
		}
		}
		*/

		if ((player_across) && (bridge_check < GetTime()))
		{
			bridge_check = GetTime() + 2.0f;


			if (!bomber_message1)
			{
				if (!return_message1)
				{
					AudioMessage("isdf1107.wav"); // (braddock) I ordered you to not go accross - You have got 2 minutes to return to your post!
					across_time = GetTime() + 120.0f;
					return_message1 = true;
				}


				if ((GetDistance(player,"bridgespire_point2")) < (GetDistance(player,"bridge_center")))
				{
					//across_time = GetTime() + 999999.9f;
					return_message1 = false;
					return_message2 = false;
					player_across = false;
				}
			}
			else if (bomber_message3)
			{
				if ((at_bridge2) && (!search_message1))
				{
					StopAudioMessage(talk);
					AudioMessage("isdf1117.wav"); // (shab) your close John - just X meters to the south
					across_time2 = GetTime() + 300.0f;
					city_check = GetTime() + 1.0f;
					SetObjectiveOn(center_ruin);
					TranslateString2(tempstr, sizeof(tempstr), "Mission1103");  // Signal Source
					SetObjectiveName(center_ruin,tempstr);

					bomber_message4 = true;
					bomber_message5 = true;
					bomber_message6 = true;

					search_message1 = true;
				}


				if ((at_bridge3) && (!search_message1))
				{
					StopAudioMessage(talk);
					AudioMessage("isdf1118.wav"); // (shab) your far John - just X meters to the south
					across_time2 = GetTime() + 300.0f;
					city_check = GetTime() + 1.0f;
					SetObjectiveOn(center_ruin);
					TranslateString2(tempstr, sizeof(tempstr), "Mission1103");  // Signal Source
					SetObjectiveName(center_ruin,tempstr);

					bomber_message4 = true;
					bomber_message5 = true;
					bomber_message6 = true;

					search_message1 = true;
				}
			}
		}


		// this is the messages at the bridge

		if ((bomber_message2) && (!near_city))
		{
			if ((!nav_noshow) && (IsAround(bridge_nav)))
			{
				if (!bomb_going_message)
				{
					talk = AudioMessage("isdf1119.wav");//(bomber) I got the target!
					bomb_going_message = true;
				}

				if ((!bomber_message3) && (IsAudioMessageDone(talk)))
				{
					AudioMessage("isdf1120.wav"); // (shab) *disturbance* Good job john - Hold on...We were getting radio interferrence
					message_wait = GetTime() + 8.0f;
					bomber_message3 = true;
				}


				if ((!bomber_message4) && (bomber_message3) && (message_wait < GetTime()))
				{
					talk = AudioMessage("isdf1121.wav");//(shab) Can you hear me now John?  General, we're picking up transmission I had to reroute to another channel! 
					bomber_message4 = true;
				}


				if ((bomber_message4) && (!bomber_message5) && (IsAudioMessageDone(talk)))
				{
					talk = AudioMessage("isdf1122.wav");//(brad) John locate source of tranasmission!
					ClearObjectives();
					AddObjective("isdf1108.otf", WHITE);
					bomber_message5 = true;
				}


				if ((bomber_message5) && (!bomber_message6) && (IsAudioMessageDone(talk)))
				{
					talk = AudioMessage("isdf1123.wav");//(shab) Source is south east of current position
					bomber_message6 = true;
				}
			}
			else if (nav_check < GetTime())
			{
				nav_noshow = true;

				if ((!bomber_message3) && (IsAudioMessageDone(talk)))
				{
					AudioMessage("isdf1124.wav"); // (shab) *disturbance* did you get that John? Drop the nav - Hold on...We were getting radio interferrence
					message_wait = GetTime() + 8.0f;
					bomber_message3 = true;
				}


				if ((!bomber_message4) && (bomber_message3) && (message_wait < GetTime()))
				{
					talk = AudioMessage("isdf1121.wav");//(shab) Can you hear me now John?  General, we're picking up transmission I  had to reroute to another channel! 
					bomber_message4 = true;
				}


				if ((bomber_message4) && (!bomber_message5) && (IsAudioMessageDone(talk)))
				{
					talk = AudioMessage("isdf1122.wav");//(brad) John locate source of tranasmission!
					ClearObjectives();
					AddObjective("isdf1108.otf", WHITE);
					bomber_message5 = true;
				}


				if ((bomber_message5) && (!bomber_message6) && (IsAudioMessageDone(talk)))
				{
					talk = AudioMessage("isdf1123.wav");//(shab) Source is south east of current position
					bomber_message6 = true;
				}
			}
		}
		////////////////////////////////////////////


		//////////////////////////////////////////////////////////
		if (!ON_HOLD)
		{
			//////////////////////////////////////////////////////////


			// this is when the convoy makes it


			// checking to see if the srecycler is deployed

			if ((!srecycler_deployed) && (end_convoy))
			{
				//SetPlan("isdf1102.aip",2);
				turret_time = GetTime() + 2.0f;
				spire_check = GetTime() + 3.0f;
				cheat_time = GetTime() + 240.0f;
				srecycler_deployed = true;
			}
			////////////////////////////////////////////


			// this is to spive things up

			if ((end_convoy) && (!bomber_message) && (cheat_time < GetTime()))
			{
				if ((!IsAlive(cheat_war1)) && (!IsAlive(cheat_war2)))
				{
					cheat_war1 = BuildObject("fvtank",2,"sbase1_spawn1");
					cheat_war2 = BuildObject("fvtank",2,"sbase1_spawn2");
					Goto(cheat_war1,"war_attack",0);
					Follow(cheat_war2,cheat_war1,0);
					cheat_time = GetTime() + 300.0f;
				}
			}
			////////////////////////////////////////////


			// this is builder code

			if ((srecycler_deployed) && (IsAround(srecycler)))
			{
				// finding out when the spires exists (this is important)

				if (IsAround(spire1))
				{
					spire1_made = true;
				}
				if (IsAround(lung1))
				{
					lung1_made = true;
				}


				if (IsAround(spire2))
				{
					spire2_made = true;
				}
				if (IsAround(lung2))
				{
					lung2_made = true;
				}


				if (IsAround(bridge_spire1))
				{
					bridge_spire1_made = true;
				}
				if (IsAround(bridge_lung1))
				{
					bridge_lung1_made = true;
				}
				////////////////////////////////////////////


				// this is the turret code

				if (turret_time < GetTime())
				{
					turret_time = GetTime() + 2.0f;

					if (guard1_a)
					{
						if (!guard1_to_point)
						{
							Goto(guard1,"sturret_point1",0);
							guard1_to_point = true;
						}
					}

					if (guard2_a)
					{
						if (!guard2_to_point)
						{
							Goto(guard2,"sturret_point2",0);
							guard2_to_point = true;
						}
					}

					if (guard3_a)
					{
						if (!guard3_to_point)
						{
							Goto(guard3,"sturret_point3",0);
							guard3_to_point = true;
						}
					}

					if (guard4_a)
					{
						if (!guard4_to_point)
						{
							Goto(guard4,"sturret_point4",0);
							guard4_to_point = true;
						}
					}
				}
				////////////////////////////////////////////


				// finding out when the builders exists (this is important)

				if ((builder1_a) && (!IsAlive(builder1)))
				{
					to1 = false;
					at1 = false;
					build1 = false;
					to2 = false;
					at2 = false;
					build2 = false;
					to_bridgespire = false;
					at_bridgespire = false;
					build_bridgespire = false;
					builder1_a = false;
				}

				if ((builder2_a) && (!IsAlive(builder2)))
				{
					builder2_a = false;
				}

				if ((builder1_a) && (builder2_a))
				{
					both_builders = true;
				}
				else
				{
					builder1_a = false;
					builder2_a = false;
					both_builders = false;
				}

				if ((spire1_a) && (!IsAround(spire1_a)))
				{
					spire1_a = false;
				}

				if ((spire2_a) && (!IsAround(spire2_a)))
				{
					spire2_a = false;
				}
				////////////////////////////////////////////


				// this is starting the builder to build the spires

				if (!new_build_orders)
				{
					if (builder1_a)
					{
						if (!spire1_a)
						{
							if (!to1)
							{
								Goto(builder1,"s1_point",0);
								spire_check = GetTime() + 3.0f;
								to1 = true;
							}

							if ((to1) && (!at1) && (spire_check < GetTime()))
							{
								spire_check = GetTime() + 3.0f;

								if (GetDistance(builder1,"s1_point") < 20.0f)
								{
									Build(builder1,"fbspir");
									spire_check = GetTime() + 3.0f;
									at1 = true;
								}
							}

							if ((at1) && (!build1) && (spire_check < GetTime()))
							{
								spire_check = GetTime() + 3.0f;

								if (GetScrap(2) > 50)
								{
									Dropoff(builder1,"s1_point");
									spire_check = GetTime() + 3.0f;
									build1 = true;
								}
							}
						}
						else if (!spire2_a)
						{
							if (!to2)
							{
								Goto(builder1,"s2_point",0);
								spire_check = GetTime() + 3.0f;
								to2 = true;
							}

							if ((to2) && (!at2) && (spire_check < GetTime()))
							{
								spire_check = GetTime() + 3.0f;

								if (GetDistance(builder1,"s2_point") < 20.0f)
								{
									Build(builder1,"fbspir");
									spire_check = GetTime() + 3.0f;
									at2 = true;
								}
							}

							if ((at2) && (!build2) && (spire_check < GetTime()))
							{
								spire_check = GetTime() + 3.0f;

								if (GetScrap(2) > 50)
								{
									Dropoff(builder1,"s2_point");
									spire_check = GetTime() + 3.0f;
									build2 = true;
								}
							}
						}
						else if (!bridgespire_a)
						{
							if (!to_bridgespire)
							{
								Goto(builder1,"bridgespire_point2",0);
								spire_check = GetTime() + 3.0f;
								to_bridgespire = true;
							}

							if ((to_bridgespire) && (!at_bridgespire) && (spire_check < GetTime()))
							{
								spire_check = GetTime() + 3.0f;

								if (GetDistance(builder1,"bridgespire_point2") < 20.0f)
								{
									Build(builder1,"fbspir");
									spire_check = GetTime() + 3.0f;
									at_bridgespire = true;
								}
							}

							if ((at_bridgespire) && (!build_bridgespire) && (spire_check < GetTime()))
							{
								spire_check = GetTime() + 3.0f;

								if (GetScrap(2) > 50)
								{
									Dropoff(builder1,"bridgespire_point2");
									spire_check = GetTime() + 3.0f;
									build_bridgespire = true;
								}
							}
						}
					}
				}
			}
			////////////////////////////////////////////


			//////////////////////////////////////////////////////////
		}
		//////////////////////////////////////////////////////////


		// this is bomber bay code ////////////////////////////////////////////

		/*
		if (bomber_message)
		{	
		// this is if the bomber exists

		if (bomber_a)
		{
		if (!bomber_message1)
		{
		AudioMessage("isdf1112.wav"); //(brad) alright shab juice up my bomber - John go and drop nav at bridge - I'll tell you where
		ClearObjectives();
		AddObjective("isdf1106.otf", GREEN);
		AddObjective("isdf1107.otf", WHITE);
		SetTeamNum(bomber_bay,0);
		SetTeamNum(bomber,0);
		Ally(0,1);
		Ally(1,0);
		bridge_check = GetTime() + 1.0f;
		bomber_message1 = true;
		}
		}
		////////////////////////////////////////////


		// this is checking to see if the bomber bay is built

		if ((bombbay_built) && (!IsAround(bomber_bay)))
		{
		if (!bomber_message2)
		{
		AudioMessage("isdf1114.wav");//(brad) dammit! Get another bomber_bay up
		}

		ClearObjectives();
		AddObjective("isdf1105.otf", WHITE);

		bombbay_a = false;
		bomber_a = false;
		bomber_spawn_time = GetTime() + 9999999.9f;
		bombbay_destroyed = true;
		bombbay_built = false;
		}
		////////////////////////////////////////////


		// this spawns in the bomber

		if ((bombbay_built) && (!first_set))
		{
		AudioMessage("isdf1115.wav");//(brad) good! now build a bomber!

		ClearObjectives();
		AddObjective("isdf1105.otf", GREEN);
		AddObjective("isdf1106.otf", WHITE);

		//bomber_spawn_time = GetTime() + 3.0f;
		first_set = true;
		}
		///////////////////////////////////////////
		}
		*/

		// this is checking to see when the player gets to the city

		if (bomber_message3)
		{
			if ((!at_city) && (city_check < GetTime()))
			{
				city_check = GetTime() + 1.0f;


				if ((!near_city) && (GetDistance(player,center_ruin) < 500.0f))
				{
					talk = AudioMessage("isdf1125.wav");//(shab) You're coming up on the signal
					near_city = true;
				}


				if ((near_city) && (!at_city) && (GetDistance(player,center_ruin) < 400.0f))
				{
					AudioMessage("isdf1126.wav");//(shab) Oh my god! Proceed inside with caution!
					search_check1 = GetTime() + 240.0f;
					search_ordered = true;
					at_city = true;
				}
			}
			////////////////////////////////////////////

			// this is the fight message

			if ((at_city) && (!fight_message) && (GetDistance(player,center_ruin) < 200.0f))
			{
				talk = AudioMessage("isdf1108.wav");//(shab) looks like a city ruin
				fight_message = true;
			}
			////////////////////////////////////////////


			// this is if the player does not go into city

			if ((search_ordered) && (!search_warning1) && (!near_temple))
			{
				if (search_check1 < GetTime())
				{
					warning_time = GetTime() + 180.0f;
					talk = AudioMessage("isdf1127.wav");//(braddock) Get the led out son - I want that city searched!	
					search_warning1 = true;
				}
			}
			////////////////////////////////////////////


			// this is if the player does not go into city

			if ((!near_temple) && (search_ordered) && (city_check < GetTime()))
			{
				city_check = GetTime() + 1.0f;


				if ((GetDistance(player,center_ruin) < 100.0f) && (IsAudioMessageDone(talk)))
				{
					if (ruin_reset1)
					{
						talk = AudioMessage("isdf1128.wav");//(braddock) The source of the transmition is coming from a building just above your location
						search_check2 = GetTime() + 240.0f;
						//SetObjectiveOn(center_ruin);
						//SetObjectiveName(center_ruin,"Signal Source");
						check_temple_message = true;
					}
					else
					{
						talk = AudioMessage("isdf1129.wav");//(braddock) The source of the transmition is coming from the center of the city
						search_check2 = GetTime() + 240.0f;
						check_temple_message = true;
					}

					search_check1 = GetTime() + 240.0f;
					warning_time = GetTime() + 999999.9f;
					//SetObjectiveOn(center_ruin);
					//SetObjectiveName(center_ruin,"Signal Source");
					near_temple = true;
				}
			}
			////////////////////////////////////////////


			// this is if the player does not go into temple

			if ((near_temple) && (!search_warning2) && (!in_temple))
			{
				if (search_check2 < GetTime())
				{
					AudioMessage("isdf1130.wav");//(braddock) Get the led out son - Check out the temple in the center!
					warning_time = GetTime() + 180.0f;
					search_warning2 = true;
				}
			}


			// this is what happens when the player is warned about something

			if ((!in_temple) && (warning_time < GetTime()) && (!last_warning)) 
			{
				AudioMessage("isdf1131.wav");//(braddock) this is your last warning to carry out my orders!
				warning_time = GetTime() + 200.0f;
				last_warning = true;
			}
			////////////////////////////////////////////


			// this is checking to see when the player is inside the temple

			if ((check_temple_message) && (!in_temple) && (GetDistance(player,transmitter) < 40.0f))//(InBuilding(player) == center_ruin))
			{
				StopAudioMessage(talk);
				talk = AudioMessage("isdf1132.wav");//(shab) That's is it John. Can you scan anything that looks like a transmission device.
				SetObjectiveOff(center_ruin);
				warning_time = GetTime() + 999999.9f;
				in_temple = true;
			}


			if ((in_temple) && (!temple_message1) && (IsAudioMessageDone(talk)))
			{
				talk = AudioMessage("isdf1133.wav");//(braddock) I've seen enouph - iron eagle one do you copy those coordinates?
				temple_message1 = true;
			}


			if ((temple_message1) && (!temple_message2) && (IsAudioMessageDone(talk)))
			{
				talk = AudioMessage("isdf1134.wav");//(bomber pilot) roger that - on my way there
				SetTeamNum(center_ruin,2);
				temple_message2 = true;
			}


			if ((temple_message2) && (!temple_message3) && (IsAudioMessageDone(talk)))
			{
				talk = AudioMessage("isdf1135.wav");//(braddock) John, I'd get out of there if I were you!
				bomber1 = BuildObject("ivbomb",3,"bomber_spawn_point");
				Goto(bomber1,center_ruin);
				next_message_time = GetTime() + 5.0f;
				temple_message3 = true;
			}


			if ((temple_message3) && (!temple_message4) && (next_message_time < GetTime()))
			{
				talk = AudioMessage("isdf1136.wav");//(shab) What are you doing - wait until my man is out of there! John get to base!
				ClearObjectives();
				AddObjective("isdf1109.otf", WHITE);
				SetObjectiveOn(recycler);
				TranslateString2(tempstr, sizeof(tempstr), "Mission1104");  // Base
				SetObjectiveName(recycler,tempstr);
				//next_message_time = GetTime() + 5.0f;
				return_time = GetTime() + 2.0f;
				temple_message4 = true;
			}
			////////////////////////////////////////////
		}


		if ((IsAround(transmitter)) && (!temple_message4))
		{
			SetCurHealth(transmitter,100);
		}


		// this is checking to see when the bomber reaches the center building

		if ((temple_message3) && (!bomber_reroute))
		{
			if ((IsAround(bomber1)) && (GetDistance(bomber1,center_ruin) < 90.0f))
			{
				if (GetCurrentCommand(bomber1) == CMD_NONE)//(CountUnitsNearObject(center_ruin,200.0f,1,"apwrck") == 1)
				{
					BuildObject("apwrck",1,bomber1);
					Goto(bomber1,"bomber_path1");
					bomber_check = GetTime() + 2.0f;
					damage_time = GetTime() + 10.0f;
					bomber_reroute = true;
				}
			}
		}
		////////////////////////////////////////////


		// this is assigning more damage to the ruin

		if ((bomber_reroute) && (damage_time < GetTime()))
		{
			if (!kill_ruin)
			{
				damage_time = GetTime() + 3.0f;
				StartEarthQuake(20.0);

				if (IsAround(center_ruin))
				{
					Damage(center_ruin,6000);
				}

				if (IsAround(ruin1))
				{
					Damage(ruin1,6000);
				}

				if (IsAround(ruin2))
				{
					Damage(ruin2,6000);
				}

				if (IsAround(ruin3))
				{			
					Damage(ruin3,6000);
				}

				if (IsAround(ruin4))
				{			
					Damage(ruin4,6000);
				}

				kill_ruin = true;
			}
			else
			{
				StopEarthQuake();
				damage_time = GetTime() + 999999.9f;
			}
		}
		////////////////////////////////////////////


		if ((bomber_reroute) && (!remove_bomber1) && (bomber_check < GetTime()))
		{
			bomber_check = GetTime() + 2.0f;

			if ((IsAround(bomber1)) && (GetDistance(bomber1,"bomber_remove1") < 50.0f))
			{
				RemoveObject(bomber1);
				remove_bomber1 = true;
			}
		}
		////////////////////////////////////////////


		// this is when the player returns from the city

		if (temple_message4)
		{
			if ((!bridge_colapse) && (return_time < GetTime()))
			{
				return_time = GetTime() + 2.0f;


				if (GetDistance(player,"bridge_center") < 250.0f)
				{
					Matrix pos;
					GetPosition(cave,pos);
					RemoveObject(cave);
					cave = BuildObject("betunna0",0,pos);

					AudioMessage("isdf1137.wav");//(shab) John get back!
					StartEarthQuake(15.0);
					colapse_time = GetTime() + 10.0f;
					SetAnimation(cave,"crumble",1);
					bridge_colapse = true;
				}
			}


			if ((bridge_colapse) && (!shab_pissed) && (colapse_time < GetTime()))
			{
				talk = AudioMessage("isdf1138.wav");//(shab) Broddock - you've left my man there!
				StopEarthQuake();
				SetObjectiveOff(recycler);
				shab_pissed = true;
			}


			if ((shab_pissed) && (!shuttle_message) && (IsAudioMessageDone(talk)))
			{
				talk = AudioMessage("isdf1139.wav");//(brad) Keep yout shirt on shab - go to the shuttle John!
				ClearObjectives();
				AddObjective("isdf1110.otf", WHITE);
				last_check = GetTime() + 1.0f;
				rescue_nav = BuildObject("ibnav",1,"last_nav_point");
				SetObjectiveOn(rescue_nav);
				TranslateString2(tempstr, sizeof(tempstr), "Mission1105");  // Dust Site
				SetObjectiveName(rescue_nav,tempstr);
				dropship = BuildObject("ivpdrop",1,"condor_spawn");
				shuttle_message = true;
			}
		}


		// this makes the earth shake when the player is near the cave

		if (!temple_message4)
		{
			if (!quake_started)
			{
				if (quake_time < GetTime())
				{
					quake_time = GetTime() + 5.0f;

					if (GetDistance(player,"bridge_center") < 80.0f)
					{
						StartEarthQuake(5.0);
						quake_time = GetTime() + 10.0f;
						quake_started = true;
					}
				}
			}
			else
			{
				if (quake_time < GetTime())
				{
					StopEarthQuake();
					quake_time = GetTime() + 15.0f;
					quake_started = false;
				}
			}
		}


		// these are the win/loose conditions
		if (!game_over)
		{
			if ((last_warning) && (warning_time < GetTime()))
			{
				AudioMessage("isdf1110.wav");//(braddock) if you cannot follow my orders you are dismissed
				FailMission(GetTime() + 15.0f);
				game_over = true;
			}


			if ((return_message2) && (across_time < GetTime()))
			{
				AudioMessage("isdf1111.wav"); // (braddock) You have disobeyed my orders
				FailMission(GetTime() + 15.0f);
				game_over = true;
			}


			//if ((bomber_landed) && (!bomber_take_off))
			//{
			//	if (!IsAlive(bomber))
			//	{
			//		AudioMessage("isdf1140.wav"); // (braddock) You let my bomber get destoyed
			//		FailMission(GetTime() + 15.0f);
			//		game_over = true;
			//	}
			//}

			if ((shuttle_message) && (last_check < GetTime()))
			{
				last_check = GetTime() + 1.0f;

				if (GetDistance(player,rescue_nav) < 60.0f)
				{
					AudioMessage("isdf1106.wav"); // good job!
					SetAnimation(dropship,"deploy",1);
					ClearObjectives();
					AddObjective("isdf1110.otf", GREEN);
					SucceedMission(GetTime() + 5.0f,"isdf11w1.txt");
					game_over = true;
				}

				if (GetDistance(player,recycler) < 100.0f)
				{
					AudioMessage("isdf1106.wav"); // good job!
					ClearObjectives();
					AddObjective("isdf1110.otf", RED);
					AddObjective("isdf1111.otf", GREEN);
					SucceedMission(GetTime() + 5.0f,"isdf11w1.txt");
					game_over = true;
				}
			}
		}

		//////////////////////////////////////////////////////////
	}
	if (ON_HOLD)
	{
		if (!temple_message2)
		{
			if (GetDistance(player,center_ruin) < 50.0f)
			{
				temple_message2 = true;
			}

		}
		//////////////////////////////////////////////////////////

		if ((temple_message2) && (!temple_message3) && (IsAudioMessageDone(talk)))
		{
			talk = AudioMessage("isdf1135.wav");//(braddock) John, I'd get out of there if I were you!
			bomber1 = BuildObject("ivbomb",3,"bomber_spawn_point");
			Goto(bomber1,center_ruin);
			next_message_time = GetTime() + 5.0f;
			temple_message3 = true;
		}


		if ((temple_message3) && (!temple_message4) && (next_message_time < GetTime()))
		{
			talk = AudioMessage("isdf1136.wav");//(shab) What are you doing - wait until my man is out of there! John get to base!
			ClearObjectives();
			AddObjective("isdf1109.otf", WHITE);
			SetObjectiveOn(recycler);
			TranslateString2(tempstr, sizeof(tempstr), "Mission1104");  // Base
			SetObjectiveName(recycler,tempstr);
			//next_message_time = GetTime() + 5.0f;
			return_time = GetTime() + 2.0f;
			temple_message4 = true;
		}
		////////////////////////////////////////////

		// this is checking to see when the bomber reaches the center building

		if ((temple_message3) && (!bomber_reroute))
		{
			if ((IsAround(bomber1)) && (GetDistance(bomber1,center_ruin) < 90.0f))
			{
				if (GetCurrentCommand(bomber1) == CMD_NONE)//(CountUnitsNearObject(center_ruin,200.0f,1,"apwrck") == 1)
				{
					BuildObject("apwrck",1,bomber1);
					Goto(bomber1,"bomber_path1");
					bomber_check = GetTime() + 2.0f;
					damage_time = GetTime() + 10.0f;
					bomber_reroute = true;
				}
			}
		}
		////////////////////////////////////////////


		// this is assigning more damage to the ruin

		if ((bomber_reroute) && (damage_time < GetTime()))
		{
			if (!kill_ruin)
			{
				damage_time = GetTime() + 3.0f;
				StartEarthQuake(20.0);

				if (IsAround(center_ruin))
				{
					Damage(center_ruin,6000);
				}

				if (IsAround(ruin1))
				{
					Damage(ruin1,6000);
				}

				if (IsAround(ruin2))
				{
					Damage(ruin2,6000);
				}

				if (IsAround(ruin3))
				{			
					Damage(ruin3,6000);
				}

				if (IsAround(ruin4))
				{			
					Damage(ruin4,6000);
				}

				kill_ruin = true;
			}
			else
			{
				StopEarthQuake();
				damage_time = GetTime() + 999999.9f;
			}
		}
		////////////////////////////////////////////


		if ((bomber_reroute) && (!remove_bomber1) && (bomber_check < GetTime()))
		{
			bomber_check = GetTime() + 2.0f;

			if ((IsAround(bomber1)) && (GetDistance(bomber1,"bomber_remove1") < 50.0f))
			{
				RemoveObject(bomber1);
				remove_bomber1 = true;
			}
		}
		////////////////////////////////////////////

		//////////////////////////////////////////////////////////
	} // ON_HOLD
	//////////////////////////////////////////////////////////

}
