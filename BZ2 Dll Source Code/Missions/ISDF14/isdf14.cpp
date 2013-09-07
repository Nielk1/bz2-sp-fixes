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
		start_done,sscav1_a,sscav2_a,sscav3_a,sscav4_a,sscav5_a,
		guard1_a,guard2_a,guard3_a,guard4_a,hauler1_a,burns_free,
		player_has_burns,scion_has_burns,scion_return,burns_recovered,
		hauler_near_base,game_over,first_deploy,player_in_tug,recycler_deployed,
		recycler_moved,player_return,shab_encounter,make_decision,shab_meeting,
		meeting_message1,meeting_message2,tug_determination,tug_is_player,no_tugger,
		encounter_message1,encounter_message2,brad_mad,decision_made,evil,
		tug_wait,stop_john,good,shab_look,condors_away,condor_clear,at_crash,firey_death,
		near_crash,first_warning,second_warning,hauler_found,search_message,done,
		hauler_go,burns_comment1,first_time,recy_building,sent1_a,sent2_a,sent3_a,sent4_a,
		sent1_defend,sent2_defend,hauler_wait,was_in,ON_HOLD,recycler_move,player_clear,
		condor1_gone,condor2_gone,start_done2,
		scout1_a,scout2_a,scout3_a,scout4_a,war1_a,war2_a,war3_a,war4_a,
		lance1_a,lance2_a,lance3_a,lance4_a,titan1_a,titan2_a,titan3_a,
		maul1_a,maul2_a,maul3_a,maul4_a,builder1_a,builder2_a,builder3_a,builder4_a,
		start_movie,raise_road,go_to_cave,shab_at_cave,raise_cave,shab_into_cave,
		factory_built,armory_built,last_aip,set_sheilds,
		tug_on_the_way,
		b_last;

	// floats
	float
		f_first,
		hauler_check,recycler_check,tugger_check,
		encouter_check,end_check,crash_check,lava_check,warning1_time,warning2_time,
		find_hauler_check,game_over_check,open_time,condor1_time,condor2_time,
		build1_movetime,build2_movetime,build3_movetime,build4_movetime,hauler_time,
		condor1_engine,condor2_engine,
		scav1_time,scav2_time,scav3_time,scav4_time,scav5_time,
		road_time,scav_check,hauler_build_time,
		f_last;

	// handles
	Handle
		h_first,
		carrier,shabayev,
		tbolt1,tbolt2,tank1,
		pool1,pool2,pool3,pool4,pool5,pool6,play_pool1,play_pool2,
		player,recycler,srecycler,condor1,condor2,
		forge,overseer,dower,stronghold,
		bspir1,bspir2,spir1,
		builder1,builder2,builder3,builder4,
		sscav1,sscav2,sscav3,sscav4,sscav5,sscav6,
		guard1,guard2,guard3,guard4,guarda,guardb,
		sent1,sent2,sent3,sent4,
		war1,war2,war3,war4,
		lance1,lance2,lance3,lance4,
		scout1,scout2,scout3,scout4,
		maul1,maul2,maul3,maul4,
		titan1,titan2,titan3,
		hauler1,
		burns,tugger,
		talk,talk2,talk3,leader,gab,
		tug_nav,nav1,
		scout_holder,tank_holder,player_holder,
		spire1,spire2,spire3,spire4,
		cheat1,cheat2,cheat3,cheat4,cheat5,cheat6,
		road,cave,factory,armory,
		h_last;

	// integers
	int
		i_first,
		a,b,c,d,
		i_last;
};

DLLBase * BuildMission(void)
{
	return new Misn04Mission();
}

bool HaveScav(void)
{
	int a;
	int scavs;
	bool not_enouph;

	a = CountUnitsNearObject(0,99999.0f,2,"fbscup");

	scavs = a;

	not_enouph = false;

	if (scavs < 4)
	{
		not_enouph = true;
	}
	else
	{
		not_enouph = false;
	}
	return not_enouph;
}

void Misn04Mission::Setup(void)
{
	SetAutoGroupUnits(false);
	/*
	Here's where you set the values at the start.  
	*/

	//  bools
	ON_HOLD = false;
	start_done = false;
	builder1_a = false; builder2_a = false; builder3_a = false; builder4_a = false; 
	sscav1_a = true; sscav2_a = true; sscav3_a = true; sscav4_a = true; sscav5_a = true;
	guard1_a = false; guard2_a = false; guard3_a = false; guard4_a = false;

	hauler1_a = true;
	burns_free = true;

	scout1_a = false; scout2_a = false; scout3_a = false; scout4_a = false;
	war1_a = false; war2_a = false; war3_a = false; war4_a = false;
	lance1_a = false; lance2_a = false; lance3_a = false; lance4_a = false;
	titan1_a = false; titan2_a = false; titan3_a = false;
	maul1_a = false; maul2_a = false; maul3_a = false; maul4_a = false; 
	player_has_burns = false;
	scion_has_burns = false;
	scion_return = false;
	burns_recovered = false;
	hauler_near_base = false;
	game_over = false;
	first_deploy = false;
	player_in_tug = false;
	recycler_deployed = true;
	recycler_moved = false;
	player_return = false;
	shab_encounter = false;
	make_decision = false;
	shab_meeting = false;
	meeting_message1 = false;
	meeting_message2 = false;
	tug_determination = false;
	tug_is_player = false;
	no_tugger = false;
	encounter_message1 = false;
	encounter_message2 = false;
	brad_mad = false;
	decision_made = false;
	evil = false;
	tug_wait = false;
	stop_john = false;
	good = false;
	shab_look = false;
	condors_away = false;
	condor_clear = false;
	at_crash = false;
	near_crash = false;
	firey_death = false;
	first_warning = false;
	second_warning = false;
	hauler_found = false;
	search_message = false;
	done = false;
	hauler_go = false;
	burns_comment1 = false;
	first_time = false;
	recy_building = false;
	sent1_a = true; sent2_a = true; sent3_a = true; sent4_a = true;
	sent1_defend = false; sent2_defend = false;
	hauler_wait = false;
	was_in = false;
	recycler_move = false;
	player_clear = false;
	condor1_gone = false;condor2_gone = false;
	start_done2 = false;
	start_movie = false;
	raise_road = false;
	go_to_cave = false;
	shab_at_cave = false;
	raise_cave = false;
	shab_into_cave = false;
	factory_built = false;
	armory_built = false;
	last_aip = false;
	set_sheilds = false;
	tug_on_the_way=false;


	//  floats
	hauler_check = 999999.9f;
	recycler_check = 999999.9f;
	tugger_check = 999999.9f;
	encouter_check = 999999.9f;
	end_check = 999999.9f;
	crash_check = 999999.9f;
	lava_check = 999999.9f;
	warning1_time = 999999.9f;
	warning2_time = 999999.9f;
	find_hauler_check = 999999.9f;
	game_over_check = 999999.9f;
	open_time = 999999.9f;
	condor1_time = 999999.9f;
	condor2_time = 999999.9f;
	build1_movetime = 999999.9f;
	build2_movetime = 999999.9f;
	build3_movetime = 999999.9f;
	build4_movetime = 999999.9f;
	hauler_time = 3.0f;
	condor1_engine = 999999.9f;
	condor2_engine = 999999.9f;
	scav1_time = 999999.9f;
	scav2_time = 999999.9f;
	scav3_time = 999999.9f;
	scav4_time = 999999.9f;
	scav5_time = 999999.9f;
	road_time = 999999.9f;
	scav_check = 999999.9f;
	hauler_build_time = 999999.9f;


	//  handles
	player = GetPlayerHandle();
	//pool1 = GetHandle("pool1");
	//pool2 = GetHandle("pool2");
	//pool3 = GetHandle("pool3");
	//pool4 = GetHandle("pool4");
	//pool5 = GetHandle("pool5");
	//pool6 = GetHandle("pool6");
	//play_pool1 = GetHandle("play_pool1");
	play_pool2 = GetHandle("play_pool2");
	recycler = GetHandle("recycler");
	srecycler = GetHandle("srecycler");
	forge = GetHandle("forge");
	overseer = GetHandle("overseer");
	dower = GetHandle("dower");
	stronghold = GetHandle("stronghold");
	bspir1 = NULL;
	bspir2 = NULL;
	spir1 = NULL;
	condor1 = GetHandle("condor1");
	condor2 = GetHandle("condor2");
	builder1 = NULL;
	builder2 = NULL;
	builder3 = NULL;
	builder4 = NULL;
	burns = GetHandle("burns");
	sscav1 = GetHandle("sscav1");
	sscav2 = GetHandle("sscav2");
	sscav3 = GetHandle("sscav3");
	sscav4 = GetHandle("sscav4");
	sscav5 = GetHandle("sscav5");
	sscav6 = NULL;
	carrier = GetHandle("carrier");
	nav1 = GetHandle("nav1");
	tug_nav = NULL;
	tbolt1 = GetHandle("tbolt1");
	tank1 = GetHandle("tank1");
	hauler1 = GetHandle("hauler1");
	spire1 = GetHandle("spire1");
	spire2 = GetHandle("spire2");
	spire3 = GetHandle("spire3");
	spire4 = GetHandle("spire4");
	road = GetHandle("road");
	cave = GetHandle("cave");
	factory = NULL;
	armory = NULL;
	guard1 = NULL;
	guard2 = NULL;
	guard3 = NULL;
	guard4 = NULL;
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
	scout1 = NULL;
	scout2 = NULL;
	scout3 = NULL;
	scout4 = NULL;
	maul1 = NULL;
	maul2 = NULL;
	maul3 = NULL;
	maul4 = NULL;
	titan1 = NULL;
	titan2 = NULL;
	titan3 = NULL;
	tugger = NULL;
	talk = NULL;
	talk2 = NULL;
	talk3 = NULL;
	gab = NULL;
	leader = NULL;
	scout_holder = NULL;
	tank_holder = NULL;
	player_holder = NULL;
	cheat1 = NULL;
	cheat2 = NULL;
	cheat3 = NULL;
	cheat4 = NULL;
	cheat5 = NULL;
	cheat6 = NULL;


	//  integers
	a = 0;
	b = 0;
	c = 0;
	d = 0;


}

void Misn04Mission::AddObject(Handle h)
{
	char ODFName[64];
	GetObjInfo(h, Get_CFG, ODFName);

	if (start_done)
	{
		if ((!recy_building) && (IsOdf2(h,"ibrecy")))
		{
			recycler = h;
			recy_building = true;
		}
		else if ((!factory_built) && (IsOdf2(h,"ibfact")))
		{
			factory = h;
			factory_built = true;
		}
		else if ((!armory_built) && (IsOdf2(h,"ibarmo")))
		{
			armory = h;
			armory_built = true;
		}

		//BUILDERS

		else if ((!builder1_a) && (IsOdf2(h,"fvcons")))
		{
			builder1 = h;
			build1_movetime = GetTime() + 3.0f;
			builder1_a = true;
		}
		else if ((!builder2_a) && (IsOdf2(h,"fvcons")))
		{
			builder2 = h;
			build2_movetime = GetTime() + 3.0f;
			builder2_a = true;
		}
		else if ((!builder3_a) && (IsOdf2(h,"fvcons")))
		{
			builder3 = h;
			build3_movetime = GetTime() + 3.0f;
			builder3_a = true;
		}
		else if ((!builder4_a) && (IsOdf2(h,"fvcons")))
		{
			builder4 = h;
			build4_movetime = GetTime() + 3.0f;
			builder4_a = true;
		}

		//THIS IS THE MAJIC TUG
		//else if ((!hauler1_a) && (IsOdf2(h,"fvtug")))//make this a special unsnipable tug odf
		//{
		//	hauler1 = h;
		//	hauler_time = GetTime() + 3.0f;
		//	hauler1_a = true;
		//}
		/*
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
		*/
		// SCOUT
		else if ((!scout1_a) && (IsOdf2(h,"fvscout")))
		{
			scout1 = h;

			if (set_sheilds)
			{
				GiveWeapon(scout1,"gdeflect");
			}

			scout1_a = true;
		}
		else if ((!scout2_a) && (IsOdf2(h,"fvscout")))
		{
			scout2 = h;

			if (set_sheilds)
			{
				GiveWeapon(scout2,"gdeflect");
			}

			scout2_a = true;
		}
		else if ((!scout3_a) && (IsOdf2(h,"fvscout")))
		{
			scout3 = h;

			if (set_sheilds)
			{
				GiveWeapon(scout3,"gdeflect");
			}

			scout3_a = true;
		}
		else if ((!scout4_a) && (IsOdf2(h,"fvscout")))
		{
			scout4 = h;

			if (set_sheilds)
			{
				GiveWeapon(scout4,"gdeflect");
			}

			scout4_a = true;
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

			if (set_sheilds)
			{
				GiveWeapon(sent1,"gshield");
			}

			sent1_a = true;
		}
		else if ((!sent2_a) && (IsOdf2(h,"fvsent")))
		{
			sent2 = h;

			if (set_sheilds)
			{
				GiveWeapon(sent2,"gshield");
			}

			sent2_a = true;
		}
		else if ((!sent3_a) && (IsOdf2(h,"fvsent")))
		{
			sent3 = h;

			if (set_sheilds)
			{
				GiveWeapon(sent3,"gshield");
			}

			sent3_a = true;
		}
		else if ((!sent4_a) && (IsOdf2(h,"fvsent")))
		{
			sent4 = h;

			if (set_sheilds)
			{
				GiveWeapon(sent4,"gshield");
			}

			sent4_a = true;
		}

		// WARRIOR
		else if ((!war1_a) && (IsOdf2(h,"fvtank")))
		{
			war1 = h;

			if (set_sheilds)
			{
				GiveWeapon(war1,"gabsorb");
			}

			war1_a = true;
		}
		else if ((!war2_a) && (IsOdf2(h,"fvtank")))
		{
			war2 = h;

			if (set_sheilds)
			{
				GiveWeapon(war2,"gabsorb");
			}

			war2_a = true;
		}
		else if ((!war3_a) && (IsOdf2(h,"fvtank")))
		{
			war3 = h;

			if (set_sheilds)
			{
				GiveWeapon(war3,"gabsorb");
			}

			war3_a = true;
		}
		else if ((!war4_a) && (IsOdf2(h,"fvtank")))
		{
			war4 = h;

			if (set_sheilds)
			{
				GiveWeapon(war4,"gabsorb");
			}

			war4_a = true;
		}

		// LANCER
		else if ((!lance1_a) && (IsOdf2(h,"fvarch")))
		{
			lance1 = h;
			lance1_a = true;
		}
		else if ((!lance2_a) && (IsOdf2(h,"fvarch")))
		{
			lance2 = h;
			lance2_a = true;
		}
		else if ((!lance3_a) && (IsOdf2(h,"fvarch")))
		{
			lance3 = h;
			lance3_a = true;
		}
		else if ((!lance4_a) && (IsOdf2(h,"fvarch")))
		{
			lance4 = h;
			lance4_a = true;
		}

		// TITANS
		else if ((!titan1_a) && (IsOdf2(h,"fvatank")))
		{
			titan1 = h;
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

	}
}

void Misn04Mission::Execute(void)
{
	/*
	Here is where you put what happens every frame.  
	*/

	player = GetPlayerHandle();
	char tempstr[128];


	// this is reseting the alive/dead bools

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

	if ((guard1_a) && (!IsAlive(guard1)))
	{
		guard1_a = false;
	}
	if ((guard2_a) && (!IsAlive(guard2)))
	{
		guard2_a = false;
	}
	if ((guard3_a) && (!IsAlive(guard3)))
	{
		guard3_a = false;
	}
	if ((guard4_a) && (!IsAlive(guard4)))
	{
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

	if ((titan1_a) && (!IsAlive(titan1)))
	{
		titan1_a = false;
	}
	if ((titan2_a) && (!IsAlive(titan2)))
	{
		titan2_a = false;
	}
	if ((titan3_a) && (!IsAlive(titan3)))
	{
		titan3_a = false;
	}

	if ((maul1_a) && (!IsAlive(maul1)))
	{
		maul1_a = false;
	}
	if ((maul2_a) && (!IsAlive(maul2)))
	{
		maul2_a = false;
	}
	if ((maul3_a) && (!IsAlive(maul3)))
	{
		maul3_a = false;
	}
	if ((maul4_a) && (!IsAlive(maul4)))
	{
		maul4_a = false;
	}


	if ((factory_built) && (!IsAround(factory)))
	{
		factory_built = false;
	}

	if ((armory_built) && (!IsAround(armory)))
	{
		armory_built = false;
	}
	/*
	if ((sscav1_a) && (!IsAround(sscav1)))
	{
	sscav1 = BuildObject("fvscav",2,"scion_base");
	scav1_time = GetTime() + 2.0f;
	sscav1_a = false;
	}
	if ((!sscav1_a) && (scav1_time < GetTime()))
	{
	if(IsAlive(sscav1))
	{
	Goto(sscav1,"sscav1_point");
	scav1_time = GetTime() + 999999.9f;
	sscav1_a = true;
	}
	else
	{
	scav1_time = GetTime() + 999999.9f;
	sscav1_a = true;
	}
	}

	if ((sscav2_a) && (!IsAround(sscav2)))
	{
	sscav2 = BuildObject("fvscav",2,"scion_base");
	scav2_time = GetTime() + 2.0f;
	sscav2_a = false;
	}
	if ((!sscav2_a) && (scav2_time < GetTime()))
	{
	if(IsAlive(sscav2))
	{
	Goto(sscav2,"sscav2_point");
	scav2_time = GetTime() + 999999.9f;
	sscav2_a = true;
	}
	else
	{
	scav2_time = GetTime() + 999999.9f;
	sscav2_a = true;
	}
	}

	if ((sscav3_a) && (!IsAround(sscav3)))
	{
	sscav3 = BuildObject("fvscav",2,"scion_base");
	scav3_time = GetTime() + 2.0f;
	sscav3_a = false;
	}
	if ((!sscav3_a) && (scav3_time < GetTime()))
	{
	if(IsAlive(sscav3))
	{
	Goto(sscav3,"sscav3_point");
	scav3_time = GetTime() + 999999.9f;
	sscav3_a = true;
	}
	else
	{
	scav3_time = GetTime() + 999999.9f;
	sscav3_a = true;
	}
	}

	if ((sscav4_a) && (!IsAround(sscav4)))
	{
	sscav4 = BuildObject("fvscav",2,"scion_base");
	scav4_time = GetTime() + 2.0f;
	sscav4_a = false;
	}
	if ((!sscav4_a) && (scav4_time < GetTime()))
	{
	if(IsAlive(sscav4))
	{
	Goto(sscav4,"sscav4_point");
	scav4_time = GetTime() + 999999.9f;
	sscav4_a = true;
	}
	else
	{
	scav4_time = GetTime() + 999999.9f;
	sscav4_a = true;
	}
	}

	if ((sscav5_a) && (!IsAround(sscav5)))
	{
	sscav5 = BuildObject("fvscav",2,"scion_base");
	scav5_time = GetTime() + 2.0f;
	sscav5_a = false;
	}
	if ((!sscav5_a) && (scav5_time < GetTime()))
	{
	if(IsAlive(sscav5))
	{
	Goto(sscav5,"sscav5_point");
	scav5_time = GetTime() + 999999.9f;
	sscav5_a = true;
	}
	else
	{
	scav5_time = GetTime() + 999999.9f;
	sscav5_a = true;
	}
	}



	if (builder1_a)
	{
	if (!IsAlive(builder1))
	{
	build1_movetime = GetTime() + 999999.9f;
	builder1_a = false;
	}		

	if (build1_movetime < GetTime())
	{
	Goto(builder1,"spire1_point",0);
	build1_movetime = GetTime() + 999999.9f;
	}
	}
	if (builder2_a)
	{
	if (!IsAlive(builder2))
	{
	build2_movetime = GetTime() + 999999.9f;
	builder2_a = false;
	}		

	if (build2_movetime < GetTime())
	{
	Goto(builder2,"spire2_point",0);
	build2_movetime = GetTime() + 999999.9f;
	}
	}
	if (builder3_a)
	{
	if (!IsAlive(builder3))
	{
	build3_movetime = GetTime() + 999999.9f;
	builder3_a = false;
	}		

	if (build3_movetime < GetTime())
	{
	Goto(builder3,"spire3_point",0);
	build3_movetime = GetTime() + 999999.9f;
	}
	}
	if (builder4_a)
	{
	if (!IsAlive(builder4))
	{
	build4_movetime = GetTime() + 999999.9f;
	builder4_a = false;
	}		

	if (build4_movetime < GetTime())
	{
	Goto(builder4,"spire4_point",0);
	build4_movetime = GetTime() + 999999.9f;
	}
	}
	*/

	// this cheats and builds the new tug

	if ((!hauler1_a) && (hauler_build_time < GetTime()))
	{
		hauler1 = BuildObject("fvtug14x",2,"scion_base");
		hauler_time = GetTime() + 30.0f;  // changed from 3.0f GEC
		hauler_build_time = GetTime() + 999999.9f;
		hauler1_a = true;
	}
	////////////////////////////////////////////


	if (hauler1_a)
	{
		if (IsAlive(hauler1))
		{
			if ((player_has_burns) && (!hauler_wait))
			{
				Stop(hauler1);
				hauler_wait = true;
			}
		}
		else if ((IsAround(hauler1)))
		{
			Damage(hauler1,2500);

			if (!first_time)
			{
				first_time = true;
			}

			hauler_check = GetTime() + 999999.9f;
			hauler_wait = false;
			scion_return = false;
			hauler_near_base = false;
			scion_has_burns = false;
			hauler_go = false;
			hauler_build_time = GetTime() + 60.0f; // 10 minutes
			hauler_time = GetTime() + 999999.9f;
			hauler1_a = false;
		}
		else
		{
			if (!first_time)
			{
				first_time = true;
			}

			hauler_check = GetTime() + 999999.9f;
			hauler_wait = false;
			scion_return = false;
			hauler_near_base = false;
			scion_has_burns = false;
			hauler_go = false;
			hauler_build_time = GetTime() + 60.0f; // 10 minutes
			hauler_time = GetTime() + 999999.9f;
			hauler1_a = false;
		}
	}
	////////////////////////////////////////////


	//////////////////////////////////////////////////
	/*
	if (!start_done)
	{
	shabayev = BuildObject("fvtank13",1,"end_point");
	Stop(shabayev);
	game_over_check = GetTime() + 2.0f;
	good = true;
	decision_made = true;
	start_done = true;
	}
	*/

	if (!ON_HOLD)
	{
		//////////////////////////////////////////////////

		if (!start_done)
		{
			SetColorFade(1,0.5f,RGBA_MAKE(0, 0, 0, 255));

			MaskEmitter(condor1, 0);
			MaskEmitter(condor2, 0);
			//SetTeamNum(burns,0);
			SetPerceivedTeam(burns,1);
			SetSkill(spire1,3);
			SetSkill(spire2,3);
			SetSkill(spire3,3);
			SetSkill(spire4,3);
			SetAvoidType(tank1,0);
			SetAvoidType(tbolt1,0);
			scout_holder = BuildObject("stayput",0,tbolt1);
			tank_holder = BuildObject("stayput",0,tank1);
			player_holder = BuildObject("stayput",0,player);
			SetAnimation(condor1,"deploy",1);
			SetAnimation(condor2,"deploy",1);
			open_time = GetTime() + 3.0f;
			start_done = true;
		}
		////////////////////////////////////////////


		// this is making the condor 2 take off and freeing the player

		if ((!recycler_move) && (start_done) && (open_time < GetTime()))
		{
			StartSoundEffect("dropdoor.wav");
			RemoveObject(player_holder);
			//Goto(recycler,"recycler_point",0);
			recycler_move = true;
		}
		////////////////////////////////////////////


		// this is when the player is clear of the ship

		if ((!player_clear) && (recycler_move))
		{
			if (GetDistance(player,tank1) > 50.0f)
			{
				RemoveObject(scout_holder);
				RemoveObject(tank_holder);
				Goto(tbolt1,"start_point",0);
				Goto(tank1,"start_point",0);
				SetAnimation(condor2,"takeoff",1);
				StartSoundEffect("dropleav.wav",condor2);
				condor2_engine = GetTime() + 3.0f;
				//RemoveObject(condor2);
				condor2_time = GetTime() + 10.0f;
				player_clear = true;
			}
		}
		////////////////////////////////////////////


		// this is making the condor take off

		if (!condors_away)
		{
			if (!condor_clear)
			{
				float a = GetDistance(player,condor1);
				float b = GetDistance(tank1,condor1);
				float c = GetDistance(tbolt1,condor1);


				if ((a > 40) && (b > 30) && (c > 30))
				{
					condor_clear = true;
				}
			}
			////////////////////////////////////////////


			// this make the condors take off

			if ((condor_clear) && (!condors_away))
			{
				AudioMessage("isdf1401.wav");//(brad) Briefing Get to the crash as soon as possible

				ClearObjectives();
				AddObjective("isdf1401.otf", WHITE);
				SetAnimation(condor1,"takeoff",1);
				StartSoundEffect("dropleav.wav",condor1);
				condor1_engine = GetTime() + 3.0f;
				//RemoveObject(condor1);
				condor1_time = GetTime() + 10.0f;
				condors_away = true;

			}
		}
		////////////////////////////////////////////


		// this starts condor engins

		if (condor1_engine < GetTime())
		{
			StartEmitter(condor1, 1);
			StartEmitter(condor1, 2);
			condor1_engine = GetTime() + 999999.9f;
		}

		if (condor2_engine < GetTime())
		{
			StartEmitter(condor2, 1);
			StartEmitter(condor2, 2);
			condor2_engine = GetTime() + 999999.9f;
		}
		////////////////////////////////////////////


		// this gets rid of the condors

		if ((!condor2_gone) && (condor2_time < GetTime()))
		{
			RemoveObject(condor2);
			condor2_gone = true;
		}

		if ((!condor1_gone) && (condor1_time < GetTime()))
		{
			RemoveObject(condor1);
			condor1_gone = true;
		}
		////////////////////////////////////////////


		if (!start_done2)
		{
			AddScrap(1,40);
			Ally(3,1);
			AddScrap(2,40);
			SetObjectiveOn(nav1);
			TranslateString2(tempstr, sizeof(tempstr), "Mission1401");  // Crash Site
			SetObjectiveName(nav1,tempstr);
			crash_check = GetTime() + 2.0f;
			warning1_time = GetTime() + 330.0f; // may be too short -- I added 30 sec GEC
			SetPlan("isdf1401.aip",2);
			start_done2 = true;
		}
		////////////////////////////////////////////


		// This is checking to see if the recycyer is deployed or not

		if (recy_building)
		{
			if (IsAround(recycler))
			{
				if (IsOdf(recycler,"ivrecy"))
				{
					recy_building = false;
				}
			}
		}
		////////////////////////////////////////////


		// this sets burns health every frame

		if ((IsAround(burns)) && (GetCurHealth(burns) < 1000))
		{
			SetCurHealth(burns,1000);
		}
		////////////////////////////////////////////


		// first time the recycler is deployed

		if ((!first_deploy) && (recy_building))
		{	
			first_deploy = true;
		}
		////////////////////////////////////////////


		// this warns the player for the first time

		if (!near_crash)
		{
			if ((!first_warning) && (warning1_time < GetTime()))
			{
				gab = AudioMessage("isdf1402.wav");//(brad) We're detecting activity at the crash site = check it out IMMEDIATELY!
				ClearObjectives();
				AddObjective("isdf1401.otf", WHITE);			
				warning1_time = GetTime() + 999999.9f;
				warning2_time = GetTime() + 330.0f;  // was 300 GEC
				first_warning = true;
			}


			if ((first_warning) && (!second_warning) && (warning2_time < GetTime()))
			{
				gab = AudioMessage("isdf1403.wav");//(brad) the hauler is making a break for it!
				ClearObjectives();
				AddObjective("isdf1401.otf", RED);
				warning2_time = GetTime() + 999999.9f;
				second_warning = true;
			}
		}
		////////////////////////////////////////////


		// this is telling me when the player is at the crash site

		if ((!near_crash) && (crash_check < GetTime()))
		{
			crash_check = GetTime() + 2.0f;


			if (GetDistance(player,nav1) < 200.0f)
			{
				near_crash = true;
			}
		}
		////////////////////////////////////////////


		// this is what happens when the player gets near the crash

		if ((near_crash) && (!hauler_found))
		{
			if (second_warning)
			{
				if (!search_message)
				{
					BuildObject("fvscav",2,"spawn4");
					StopAudioMessage(gab);
					SetObjectiveOff(nav1);
					SetObjectiveOn(hauler1);
					AudioMessage("isdf1404.wav");//(brad) Stop that hauler at all costs!
					ClearObjectives();
					AddObjective("isdf1401.otf", RED);
					AddObjective("isdf1402.otf", WHITE);
					hauler_found = true;
					search_message = true;
				}
			}
			else if (!search_message)
			{
				StopAudioMessage(gab);
				SetObjectiveOff(nav1);
				ClearObjectives();
				AddObjective("isdf1401.otf", GREEN);
				gab = AudioMessage("isdf1405.wav");//(brad) Search for survivors
				search_message = true;
			}
		}
		////////////////////////////////////////////


		// this makes the hauler move out for the first time

		if (!done)
		{
			if ((second_warning) || (near_crash))
			{
				Pickup(hauler1,burns);
				//Follow(sscav5,hauler1);
				find_hauler_check = GetTime() + 1.0f;
				hauler_go = true;
				done = true;
			}
		}
		////////////////////////////////////////////


		// this is when the the player first finds the hauler

		if ((hauler_go) && (!hauler_found) && (find_hauler_check < GetTime()))
		{
			find_hauler_check = GetTime() + 1.0f;


			if (GetDistance(player,hauler1) < 110.0f)
			{
				StopAudioMessage(gab);
				SetObjectiveOn(hauler1);
				ClearObjectives();
				AddObjective("isdf1401.otf", GREEN);
				AddObjective("isdf1402.otf", WHITE);
				AudioMessage("isdf1404.wav");//(brad) Stop that hauler at all costs!
				scion_has_burns = true;
				hauler_found = true;
			}
		}
		////////////////////////////////////////////


		if (condors_away)
		{
			// this sends the scion hauler to burns after the first time

			if ((done) && (hauler_time < GetTime()))
			{
				if ((!hauler_go) && (hauler1_a) && (burns_free))
				{
					if (IsAround(burns))
					{
						Pickup(hauler1,burns);
						//SetPlan("isdf1403.aip",2);
						hauler_go = true;
					}
				}
			}
			////////////////////////////////////////////


			// this is what happens when the player has burns and is on his way home


			// first I have to see when he has burns

			if (!tug_wait)
			{
				if ((burns_free) && (IsAround(burns)))
				{
					tugger = GetTug(burns);

					if (tugger != 0)
					{
						if (GetTeamNum(tugger) == 1)
						{
							lava_check = GetTime() + 2.0f;
							player_has_burns = true;
							scion_has_burns = false;
							burns_free = false;
						}
						else if (GetTeamNum(tugger) == 2)
						{
							player_has_burns = false;
							scion_has_burns = true;
							burns_free = false;
						}
					}
				}
			}
			////////////////////////////////////////////


			// This is if the player has burns

			if (player_has_burns)
			{
				if (!player_return)
				{
					tugger_check = GetTime() + 1.0f;
					player_return = true;
				}
			}
			////////////////////////////////////////////


			// this is if burns is not being tugged

			if (!burns_free)
			{
				tugger = GetTug(burns);

				if (tugger == 0)
				{
					hauler_check = GetTime() + 999999.9f;
					tugger_check = GetTime() + 999999.9f;
					lava_check = GetTime() + 999999.9f;
					hauler_wait = false;
					scion_return = false;
					hauler_near_base = false;
					player_has_burns = false;
					player_return = false;
					scion_has_burns = false;
					hauler_go = false;
					burns_free = true;
				}
			}
			////////////////////////////////////////////


			// this is when the player destoys the hauler for the first time

			if (first_time)
			{
				if (!burns_comment1)
				{
					ClearObjectives();
					AddObjective("isdf1402.otf", GREEN);
					AddObjective("isdf1403.otf", WHITE);
					SetObjectiveOn(burns);
					TranslateString2(tempstr, sizeof(tempstr), "Mission1402");  // Scion Creature 
					SetObjectiveName(burns,tempstr);
					SetPlan("isdf1402.aip",2);
					AudioMessage("isdf1406.wav");//(brad)Get that creature back to your base
					scav_check = GetTime() + 600.0f;
					burns_comment1 = true;
				}
			}


			// this is if the player gets into a tug
			char ODFName[64];
			GetObjInfo(player, Get_CFG, ODFName);

			if ((!player_in_tug) && (IsOdf2(player,"ivtug")))
			{
				player_in_tug = true;
			}
			if ((player_in_tug) && (!IsOdf2(player,"ivtug")))
			{
				player_in_tug = false;
			}
			////////////////////////////////////////////


			// this is if the player takes burns over the lava

			if ((!firey_death) && (player_has_burns) && (lava_check < GetTime()))
			{
				lava_check = GetTime() + 2.0f;

				if (GetDistance(tugger,"lava_point1") < 200.0f)
				{
					firey_death = true;
				}

				if ((!firey_death) && (GetDistance(tugger,"lava_point2") < 200.0f))
				{
					firey_death = true;
				}

				if ((!firey_death) && (GetDistance(tugger,"lava_point3") < 200.0f))
				{
					firey_death = true;
				}

				if ((!firey_death) && (GetDistance(tugger,"lava_point4") < 200.0f))
				{
					firey_death = true;
				}
			}
			////////////////////////////////////////////


			// This is if the Scions have burns

			if ((!burns_recovered) && (scion_has_burns))
			{
				if (!scion_return)
				{
					if ((first_time) && (GetDistance(player,hauler1) > 100.0f))
					{
						AudioMessage("isdf1422.wav");//(brad) the scions have the creature again!
					}

					Goto(hauler1,"scion_base");
					hauler_check = GetTime() + 3.0f;
					scion_return = true;
				}


				if ((scion_return) && (!hauler_near_base) && (hauler_check < GetTime()))
				{
					hauler_check = GetTime() + 3.0f;


					if (GetDistance(hauler1,"hauler_check1") < 50.0f)
					{
						hauler_check = GetTime() + 2.0f;
						hauler_near_base = true;
					}
				}


				if ((hauler_near_base) && (!burns_recovered) && (hauler_check < GetTime()))
				{
					hauler_check = GetTime() + 2.0f;


					if (GetDistance(hauler1,srecycler) < 40.0f)
					{
						burns_recovered = true;
					}
				}
			}
			////////////////////////////////////////////


			// I need to know where the player's recycler is

			if (first_deploy)
			{
				if ((recycler_deployed) && (IsOdf(recycler,"ivrecy")))
				{
					recycler_check = GetTime() + 3.0f;
					recycler_deployed = false;
				}
				if ((!recycler_deployed) && (IsOdf(recycler,"ibrecy")))
				{
					recycler_check = GetTime() + 999999.9f;
					recycler_deployed = true;
				}


				if ((!recycler_deployed) && (!recycler_moved) && (recycler_check < GetTime()))
				{
					recycler_check = GetTime() + 3.0f;


					if (GetDistance(recycler,"shab_check1") < 70.0f)
					{
						recycler_moved = true;
					}

					if (GetDistance(recycler,"shab_check2") < 70.0f)
					{
						recycler_moved = true;
					}
				}
			}
			////////////////////////////////////////////


			if (!recycler_moved)
			{
				if ((player_return) && (!shab_encounter) && (tugger_check < GetTime()))
				{
					tugger_check = GetTime() + 1.0f;

					if (GetDistance(burns,"shab_check1") < 70.0f)
					{
						shab_encounter = true;
					}

					if (GetDistance(burns,"shab_check2") < 70.0f)
					{
						shab_encounter = true;
					}

					if (GetDistance(burns,"shab_check3") < 70.0f)
					{
						shab_encounter = true;
					}

					if (GetDistance(burns,"shab_check4") < 70.0f)
					{
						shab_encounter = true;
					}

					if (GetDistance(burns,"shab_check5") < 70.0f)
					{
						shab_encounter = true;
					}

					if (GetDistance(burns,"shab_check6") < 70.0f)
					{
						shab_encounter = true;
					}

					if (GetDistance(burns,"shab_checknew") < 80.0f)
					{
						shab_encounter = true;
					}

					if (GetDistance(burns,recycler) < 200.0f)
					{
						shab_encounter = true;
					}
				}
			}
			else if (recycler_moved)
			{
				if ((player_return) && (!shab_encounter) && (tugger_check < GetTime()))
				{
					tugger_check = GetTime() + 1.0f;

					if (GetDistance(burns,"shab_check1") < 70.0f)
					{
						shab_encounter = true;
					}

					if (GetDistance(burns,"shab_check2") < 70.0f)
					{
						shab_encounter = true;
					}

					if (GetDistance(burns,"shab_check3") < 70.0f)
					{
						shab_encounter = true;
					}

					if (GetDistance(burns,"shab_check4") < 70.0f)
					{
						shab_encounter = true;
					}

					if (GetDistance(burns,"shab_check5") < 70.0f)
					{
						shab_encounter = true;
					}

					if (GetDistance(burns,"shab_check6") < 70.0f)
					{
						shab_encounter = true;
					}

					if (GetDistance(burns,recycler) < 200.0f)
					{
						shab_encounter = true;
					}
				}
			}
			////////////////////////////////////////////


			// this is the shab encouter

			if (shab_encounter)
			{
				// this is when shab first tell John to stop

				if (!stop_john)
				{
					Ally(2,1);
					SetPlan("isdf1403.aip",2);
					shabayev = BuildObject("fvtank",1,"end_point");
					Follow(shabayev,player,1);
					talk = AudioMessage("isdf1407.wav");//(shab) John Stop!
					encouter_check = GetTime() + 1.0f;
					tug_wait = true;
					stop_john = true;
				}
				////////////////////////////////////////////


				if ((stop_john) && (!shab_meeting))
				{
					if (GetCurHealth(shabayev) < 2000)
					{
						SetCurHealth(shabayev,2000);
					}
				}


				// this keeps the tug alive briefly

				if ((IsAlive(tugger)) && (!make_decision))
				{
					if (GetCurHealth(tugger) < 500)
					{
						SetCurHealth(tugger,500);
					}
				}
				////////////////////////////////////////////


				// this is radio chatter when the ships stop fighting

				if (!shab_meeting)
				{
					if ((stop_john) && (!encounter_message1) && (IsAudioMessageDone(talk)))
					{
						talk = AudioMessage("isdf1408.wav");//(recycler) Ah, commander they've stopped fighting!
						encounter_message1 = true;
					}

					if ((encounter_message1) && (!encounter_message2) && (IsAudioMessageDone(talk)))
					{
						talk = AudioMessage("isdf1409.wav");//(shab) stop John - its me Yelena, I'm on my way to you!
						SetObjectiveOn(shabayev);
						SetObjectiveName(shabayev,"Yelena");			
						encounter_message2 = true;
					}
				}
				////////////////////////////////////////////


				// this is when shab and John finally get together

				if ((stop_john) && (!shab_meeting) && (encouter_check < GetTime()))
				{
					encouter_check = GetTime() + 1.0f;


					if (GetDistance(shabayev,player) < 70.0f)
					{
						StopAudioMessage(talk);
						LookAt(shabayev,player);
						//SetObjectiveOn(shabayev);
						//SetObjectiveName(shabayev,"Yelena");
						talk2 = AudioMessage("isdf1410.wav");// (shab) *long speach*
						shab_meeting = true;
					}
				}
				////////////////////////////////////////////


				if (shab_meeting)
				{
					if ((!meeting_message1) && (IsAudioMessageDone(talk2)))
					{
						talk2 = AudioMessage("isdf1411.wav");// (brad) *This is a trick!*
						meeting_message1 = true;
					}

					if ((!meeting_message2) && (meeting_message1) && (IsAudioMessageDone(talk2)))
					{
						talk2 = AudioMessage("isdf1412.wav");// (shab) you have to beleive me!
						meeting_message2 = true;
					}


					// I need to know who the tug is

					if ((meeting_message2) && (!tug_determination))
					{
						if (IsAround(tugger))
						{
							if (IsAlive(tugger))
							{
								if (tugger == player)
								{
									tug_is_player = true;
								}
								else
								{
									tug_is_player = false;
								}
							}
							else
							{
								tug_is_player = true;
							}
						}
						else
						{
							no_tugger = true;
						}

						tug_determination = true;
					}
					////////////////////////////////////////////


					// this is shab giving John his choices

					if ((tug_determination) && (!make_decision)  && (IsAudioMessageDone(talk2)))
					{
						//tug_nav = BuildObject("apcamr",1,"end_point")

						//if (no_tugger)
						//{
						//	talk2 = AudioMessage("wohoo.wav");//(shab) build a tug and tell it to follow me
						//}
						if (tug_is_player)
						{

							Matrix pos;
							GetPosition(shabayev,pos);
							RemoveObject(shabayev);
							shabayev = BuildObject("fvtank14x",0,pos);
							SetObjectiveOn(shabayev);
							SetObjectiveName(shabayev,"Yelena");

							Retreat(shabayev,"end_point");
							end_check = GetTime() + 1.0f;
							talk2 = AudioMessage("isdf1413.wav");//(shab) follow me
							was_in = true;
						}
						else if (!tug_is_player)
						{
							talk2 = AudioMessage("isdf1414.wav");//(shab) tell your tug to follow me
						}

						make_decision = true;
					}
					////////////////////////////////////////////
				}


				// this is checking to see when the player makes his choice

				if (make_decision)
				{
					// this is braddock getting angry makes

					if ((!brad_mad) && (IsAudioMessageDone(talk2)))
					{
						if (!tug_is_player)
						{
							talk2 = AudioMessage("isdf1415.wav");//(brad) destroy her now!!!
						}
						else
						{
							talk2 = AudioMessage("isdf1416.wav");//(brad) get that relic to the recycler!!!
						}

						brad_mad = true;
					}
					////////////////////////////////////////////

					/*
					// this is if the player gets in the tug while waiting for the desicion

					if (!decision_made)
					{
					if ((!tug_is_player) && (IsAround(tugger)) && (!IsAlive(tugger)))
					{
					AudioMessage("isdf1417.wav");//(shab) If you want to pilot the craft yourself follow me
					Goto(shabayev,"end_point");
					end_check = GetTime() + 1.0f;
					tug_is_player = true;

					}
					}
					////////////////////////////////////////////
					*/

					// this is the player making his choice

					if (!decision_made)
					{
						if (!was_in)
						{
							if (!IsAlive(shabayev))
							{
								AudioMessage("isdf1418.wav");//(brad) well done now get burns to the recycler
								UnAlly(2,1);
								game_over_check = GetTime() + 2.0f;
								evil = true;
								tug_wait = false;
								decision_made = true;
							}

							if (GetCurrentCommand(tugger) == CMD_FOLLOW)
							{
								leader = GetCurrentWho(tugger);

								if ((IsAround(shabayev)) && (leader == shabayev))
								{
									AllLookAt(1,player,1);

									if (IsAround(recycler))
									{
										Matrix pos;
										GetPosition(recycler,pos);
										RemoveObject(recycler);
										recycler = BuildObject("ibrecy",0,pos);
									}

									if (factory_built)
									{
										Matrix pos;
										GetPosition(factory,pos);
										RemoveObject(factory);
										factory = BuildObject("ibfact",0,pos);
									}

									if (armory_built)
									{
										Matrix pos;
										GetPosition(armory,pos);
										RemoveObject(armory);
										armory = BuildObject("ibarmo",0,pos);
									}

									Matrix pos;
									GetPosition(shabayev,pos);
									RemoveObject(shabayev);
									shabayev = BuildObject("fvtank14x",0,pos);
									SetObjectiveOn(shabayev);
									SetObjectiveName(shabayev,"Yelena");

									Follow(tugger,shabayev,1);
									StopAudioMessage(talk2);
									talk3 = AudioMessage("isdf1419.wav");//(shab) good! Follow me!
									Retreat(shabayev,"shabayev_tug");
									end_check = GetTime() + 1.0f;
									game_over_check = GetTime() + 2.0f;
									SetTeamNum(player,3);
									Ally(1,2);
									Ally(1,3);
									Ally(2,3);
									good = true;
									tug_wait = false;
									decision_made = true;
								}
							}
						}
						else if (was_in)
						{
							if (end_check < GetTime())
							{
								end_check = GetTime() + 1.0f;


								if ((!shab_look) && (GetDistance(shabayev,"end_point") < 40.0f))
								{
									LookAt(shabayev,player);
									shab_look = true;
								}

								if (shab_look)
								{
									if (GetDistance(shabayev,player) < 50.0f)
									{
										AllLookAt(1,player,1);

										if (IsAround(recycler))
										{
											Matrix pos;
											GetPosition(recycler,pos);
											RemoveObject(recycler);
											recycler = BuildObject("ibrecy",0,pos);
										}

										if (factory_built)
										{
											Matrix pos;
											GetPosition(factory,pos);
											RemoveObject(factory);
											factory = BuildObject("ibfact",0,pos);
										}

										if (armory_built)
										{
											Matrix pos;
											GetPosition(armory,pos);
											RemoveObject(armory);
											armory = BuildObject("ibarmo",0,pos);
										}


										StopAudioMessage(talk2);
										talk3 = AudioMessage("isdf1419.wav");//(shab) good! Follow me!
										SetTeamNum(player,3);
										Ally(1,2);
										Ally(1,3);
										Ally(2,3);
										game_over_check = GetTime() + 2.0f;
										good = true;
										tug_wait = false;
										decision_made = true;
									}


									if (GetDistance(burns,recycler) < 100.0f)
									{
										AudioMessage("isdf1418.wav");//(brad) well done 
										SucceedMission(GetTime() + 10.0f,"isdf14w1.txt");
										game_over = true;
										evil = true;
										decision_made = true;
									}
								}
							}
						}
						//else if (no_tugger)
						//{
						//decision_made = true;
						//}
					}
					////////////////////////////////////////////
				}
				////////////////////////////////////////////
			}
			////////////////////////////////////////////


			// this is after the decision

			if ((decision_made) && (good))
			{
				if (IsAround(shabayev))
				{
					if (GetCurHealth(shabayev) < 2000)
					{
						SetCurHealth(shabayev,2000);
					}
				}
			}
			////////////////////////////////////////////


			// this is reseting the aip

			if ((!last_aip) && (scav_check < GetTime()))
			{
				scav_check = GetTime() + 300.0f;
				//set_sheilds = true;

				if (HaveScav())
				{
					SetPlan("isdf1404.aip",2);
					set_sheilds = true;
					last_aip = true;
				}
			}
			////////////////////////////////////////////


		}

		// this is the descions being made

		if (!was_in)
		{
			if ((decision_made) && (game_over_check < GetTime()))
			{
				game_over_check = GetTime() + 2.0f;
				if ((!tug_on_the_way) && (GetDistance(shabayev,"shabayev_tug")<100.0f))
				{
					tug_on_the_way=true;
					Retreat(shabayev,"end_point");
				}


				if (good)
				{
					if ((GetDistance(shabayev,"end_point") < 40.0f) && 
						(GetDistance(player,shabayev) < 30.0f))
					{
						start_movie = true;
						game_over = true;
					}
				}
				else if ((!game_over) && // to prevent endless loop
					(evil) && (GetDistance(player,recycler) < 200.0f))
				{
					SucceedMission(GetTime() + 10.0f,"isdf14w1.txt");
					// You are ISDF
					game_over = true;
				}
			}
		}
		////////////////////////////////////////////


		// this is the last movie

		if (start_movie)
		{
			// this raises the road

			if (!raise_road)
			{
				SetAnimation(road,"raise",1);
				StartEarthQuake(5.0);
				road_time = GetTime() + 5.0f;
				raise_road = true;
			}


			// this sends shab down the new road

			if ((!go_to_cave) && (raise_road) && (road_time < GetTime()))
			{
				Goto(shabayev,"road_path");
				StopEarthQuake();
				road_time = GetTime() + 2.0f;
				go_to_cave = true;
			}


			// this is when shab gets there

			if ((!shab_at_cave) && (go_to_cave) && (road_time < GetTime()))
			{
				if (GetCurrentCommand(shabayev) == CMD_NONE)
				{
					LookAt(shabayev,player);
					shab_at_cave = true;
				}
			}


			// this raises the cave

			if ((!raise_cave) && (shab_at_cave))
			{
				if (GetDistance(player,shabayev) < 30.0f)
				{
					LookAt(shabayev,cave);
					SetAnimation(cave,"open",1);
					StartEarthQuake(5.0);
					road_time = GetTime() + 5.0f;
					raise_cave = true;
				}
			}


			// this sends shab into the cave

			if ((!shab_into_cave) && (raise_cave) && (road_time < GetTime()))
			{
				Goto(shabayev,"into_cave_path");
				SucceedMission(GetTime() + 6.0f,"isdf14w2.txt");
				// you are Scion
				ChangeSide();
				game_over = true;
				//road_time = GetTime() + 5.0f;
				shab_into_cave = true;
			}
		}

		if (!game_over)
		{
			// this is if the recycler gets killed

			if (!IsAround(recycler))
			{
				FailMission(GetTime() + 10.0f);
				//AudioMessage("wohoo.wav");//(brad) you've allowed your recycler to get killed
				game_over = true;
			}
			////////////////////////////////////////////

			// this is if the scions capture burns

			if (burns_recovered)
			{
				FailMission(GetTime() + 10.0f);
				AudioMessage("isdf1420.wav");//(brad) you've allowed burns to get captured
				game_over = true;
			}
			////////////////////////////////////////////

			// this is if the player goes over the lave with burns

			if (firey_death)
			{
				FailMission(GetTime() + 10.0f);
				AudioMessage("isdf1421.wav");//(brad) you've allowed burns to get burns
				game_over = true;
			}
			////////////////////////////////////////////
		}

		//////////////////////////////////////////////////
	}
	//////////////////////////////////////////////////
}
