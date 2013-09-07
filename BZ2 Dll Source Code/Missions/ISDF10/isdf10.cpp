#include "..\Shared\SPMission.h"

// Change NM 8/8/03 - won't do the maze
#define NO_MAZE

#ifdef NO_MAZE
const bool ON_HOLD = false;
#endif

const float AllyMinRadiusAway=20.0f;
const float AllyMaxRadiusAway=40.0f;


class Misn10Mission : public SPMission 
{
public:
	Misn10Mission(void)
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
#ifdef NO_MAZE
		ON_HOLD_UNUSED,
#else
		ON_HOLD,
#endif
		start_done,free_recycler,part_two,wing_move,wing_turn,wing_free, 
		caps_gone,mcap1_gone,mcap2_gone,mcap3_gone,mcap4_gone,mcap5_gone,mcap6_gone,
		scap1_gone,scap2_gone, recycler_message1,recycler_underway,
		free_first,at_one,at_two,at_three,at_four,near_madeit,at_madeit,at_nav,underway_canceled,
		madeit_message,whyselected_message,caps_gone_message,destroy_hint,cover_tracks_message,
		recy_detected_message,game_over,drop_message1,drop_message2,drop_message3,in_air,
		first_land,shab_found,shab_scanned,shab_scan_message,at_choke1,at_choke2,at_choke3,
		start_patrol1,start_patrol2,patrol1_dead,patrol2_dead,player_ship_found,recy_fall_in,
		scap1_start,scap2_start,mcap1_start,mcap2_start,mcap3_start,mcap4_start,mcap5_start,mcap6_start,
		rhino1_in,rhino2_in,rhino3_in,rhino4_in,rhino1_charge,rhino2_charge,rhino3_charge,rhino4_charge,
		base_message,set_plan1,
		scout1_a,scout2_a,scout3_a,scout4_a,guard1_a,guard2_a,guard3_a,guard4_a,
		sent1_a,sent2_a,sent3_a,sent4_a,war1_a,war2_a,war3_a,war4_a,
		maul1_a,maul2_a,maul3_a,maul4_a,lance1_a,lance2_a,lance3_a,lance4_a,
		second_patrol1,second_patrol2,stop_guard1_dead,stop_guard2_dead,
		guard1_to_post,guard2_to_post,
		sent1_attack_recy,sent2_attack_recy,war1_attack_recy,war2_attack_recy,
		maul1_attack_recy,maul2_attack_recy,discover1,discover2,
		rhino1_behave,rhino2_behave,rhino3_behave,rhino4_behave,drop_message4,
		transport_message,rhino2_after_recy,rhino3_after_recy,rhino4_after_recy,cheat2,
		land_secure,turret_message,turret_otf,build_patrol,first_scav,camera_off,
		landing,landed,two_land,take_off,animate_rhino1,animate_rhino2,animate_rhino3,animate_rhino4,
		satch_alive,ship1_bomb,ship2_bomb,fall1_already,fall2_already,fall3_already,fall4_already,
		suicide_run,start_end_movie,remove_transport,shot2,
		
		hold_stuff,free_player,big_switch,black,first_talk,second_talk,boom,last_talk,fall_sound,
		b_last;

	// floats
	float
		f_first,
		recy_check,wing_turn_time,maze_check,wing_check,detect_check,win_check,land_time,
		shab_check,message_time,escape_check,patrol1_time,patrol2_time,discover_check,recy_death_check,
		rhino1_check,rhino2_check,rhino3_check,rhino4_check,anim_wait,forget_check,
		discover1_time,discover2_time,cheat2_time,turret_time,camera_time,landing_time,
		guard1_time,guard2_time,new_plan_time,patrol_time,carrier_time,swap_time,
		talk_time,sound_time,
		f_last;

	// handles
	Handle
		h_first,
		player,wingman,
		transport,
		recycler,srecycler,
		dropship,
		sscav1,sscav2,sscav3,
		forge,dower,stronghold,
		spire1,spire2,spire3,spire4,spire5,
		crash_ship1,crash_ship2,
		scap1,scap2,
		mcap1,mcap2,mcap3,mcap4,mcap5,mcap6,
		rhino1,rhino2,rhino3,rhino4,
		nav1,nav2,
		leader, nearest_enemy,
		dropshipa, dropshipb,
		talk,
		stop_guard1, stop_guard2,
		scion1, scion2, scion3, scion4, scion5, scion6, scion7, scion8,
		guard1, guard2, guard3, guard4,
		sent1, sent2, sent3, sent4,
		war1, war2, war3, war4,
		lance1, lance2, lance3, lance4,
		scout1, scout2, scout3, scout4,
		maul1, maul2, maul3, maul4,
		pool1,pool2,pool3,player_ship,
		builder,dead_tank1,dead_tank2,
		cheat_tank1,cheat_tank2,cheat_tank3,
		block_turret1,block_turret2,block_turret3,block_turret4,
		patroler1,patroler2,satch,
		antenna,patrol_sent1,patrol_sent2,
		crash_tank,crash_scout,open_drop,standin,
		holder1,holder2,holder3,
		h_last;

	// integers
	int
		i_first,

		i_last;
};

DLLBase * BuildMission(void)
{
	return new Misn10Mission();
}

void Misn10Mission::Setup(void)
{
	SetAutoGroupUnits(false);
/*
	Here's where you set the values at the start.  
*/

//  bools
#ifndef NO_MAZE
	ON_HOLD = false;
#endif
	start_done = false;
	free_recycler = false;
	part_two = false;
	wing_move = false;
	wing_turn = false;
	wing_free = false;
	caps_gone = false;
	mcap1_gone = false;
	mcap2_gone = false;
	mcap3_gone = false;
	mcap4_gone = false;
	mcap5_gone = false;
	mcap6_gone = false;
	scap1_gone = false;
	scap2_gone = false;
	recycler_message1 = false;
	recycler_underway = false;
	free_first = false;
	at_one = false;
	at_two = false;
	at_three = false;
	at_four = false;
	near_madeit = false;
	at_madeit = false;
	at_nav = false;
	underway_canceled = false;
	madeit_message = false;
	whyselected_message = false;
	caps_gone_message = false;
	destroy_hint = false;
	cover_tracks_message = false;
	recy_detected_message = false;
	game_over = false;
	drop_message1 = false;
	drop_message2 = false;
	drop_message3 = false;
	in_air = true;
	first_land = false;
	shab_found = false;
	shab_scanned = false;
	shab_scan_message = false;
	at_choke1 = false;
	at_choke2 = false;
	at_choke3 = false;
	start_patrol1 = false;
	start_patrol2 = false;
	patrol1_dead = false;
	patrol2_dead = false;
	player_ship_found = false;
	recy_fall_in = false;
	scap1_start = false; scap2_start = false;
	mcap1_start = false; mcap2_start = false; mcap3_start = false;
	mcap4_start = false; mcap5_start = false; mcap6_start = false;
	rhino1_in = false; rhino2_in = false; rhino3_in = false; rhino4_in = false;
	rhino1_charge = false; rhino2_charge = false; rhino3_charge = false; rhino4_charge = false; 
	base_message = false;
	set_plan1 = false;
	scout1_a = false; scout2_a = false; scout3_a = false; scout4_a = false; 
	guard1_a = false; guard2_a = false; guard3_a = false; guard4_a = false;
	sent1_a = false; sent2_a = false; sent3_a = false; sent4_a = false;
	war1_a = false; war2_a = false; war3_a = false; war4_a = false;
	maul1_a = false; maul2_a = false; maul3_a = false; maul4_a = false; 
	lance1_a = false; lance2_a = false; lance3_a = false; lance4_a = false;
	second_patrol1 = false; second_patrol2 = false; stop_guard1_dead = false; stop_guard2_dead = false;
	guard1_to_post = false; guard2_to_post = false;
	sent1_attack_recy = false; sent2_attack_recy = false; 
	war1_attack_recy = false; war2_attack_recy = false; 
	maul1_attack_recy = false; maul2_attack_recy = false;
	discover1 = false; discover2 = false;
	rhino1_behave = false; rhino2_behave = false; rhino3_behave = false; rhino4_behave = false;
	drop_message4 = false;transport_message = false;
	rhino2_after_recy = false; rhino3_after_recy = false; rhino4_after_recy = false;
	cheat2 = false;
	land_secure = false;
	turret_message = false;
	turret_otf = false;
	build_patrol = false;
	first_scav = false;
	camera_off = false;
	landing = false; landed = false; two_land = false; take_off = false;
	animate_rhino1 = false;
	animate_rhino2 = false;
	animate_rhino3 = false;
	animate_rhino4 = false;
	satch_alive = false;
	ship1_bomb = false; ship2_bomb = false;
	fall1_already = false;fall2_already = false;fall3_already = false;fall4_already = false;
	suicide_run = false;
	start_end_movie = false; shot2 = false;
	remove_transport = false; 
	hold_stuff = false; 
	free_player = false; 
	big_switch = false; 
	black = false;
	first_talk = false;
	second_talk = false;
	boom = false;
	last_talk = false;
	fall_sound = false;

//  floats
	recy_check = 1.0f;
	wing_turn_time = 999999.9f;
	maze_check = 999999.9f;
	wing_check = 999999.9f;
	detect_check = 999999.9f;
	win_check = 3.0f;
	land_time = 999999.9f;
	shab_check = 999999.9f;
	message_time = 999999.9f;
	escape_check = 999999.9f;
	patrol1_time = 999999.9f;
	patrol2_time = 999999.9f;
	discover_check = 999999.9f;
	recy_death_check = 999999.9f;
	rhino1_check = 999999.9f;
	rhino2_check = 999999.9f;
	rhino3_check = 999999.9f;
	rhino4_check = 999999.9f;
	anim_wait = 999999.9f;
	forget_check = 999999.9f;
	discover1_time = 999999.9f;
	discover2_time = 999999.9f;
	cheat2_time = 999999.9f;
	turret_time = 999999.9f;
	camera_time = 999999.9f;
	landing_time = 999999.9f;
	guard1_time = 999999.9f;
	guard2_time = 999999.9f;
	new_plan_time = 999999.9f;
	patrol_time = 999999.9f;
	carrier_time = 999999.9f;
	swap_time = 999999.9f;
	talk_time = 999999.9f;
	sound_time = 999999.9f;


//  handles
	player = GetPlayerHandle();
	recycler = GetHandle("recycler");
	srecycler = GetHandle("srecycler");
	wingman = GetHandle("wingman");
	sscav1 = GetHandle("sscav1");
	sscav2 = GetHandle("sscav2");
	sscav3 = GetHandle("sscav3");
	forge = GetHandle("forge");
	dower = GetHandle("dower");
	stronghold = GetHandle("stronghold");
	spire1 = GetHandle("spire1");
	spire2 = GetHandle("spire2");
	spire3 = GetHandle("spire3");
	spire4 = NULL;
	spire5 = NULL;
	crash_ship1 = GetHandle("crash_ship1");
	crash_ship2 = GetHandle("crash_ship2");
	nav1 = GetHandle("nav1");
	dropship = GetHandle("dropship");
	dropshipa = NULL;
	dropshipb = NULL;	
	//pool1 = GetHandle("pool1");
	//pool2 = GetHandle("pool2");
	//pool3 = GetHandle("pool3");
	nav2 = NULL;
	scap1 = GetHandle("scap1");
	scap2 = GetHandle("scap2");
	mcap1 = GetHandle("mcap1");
	mcap2 = GetHandle("mcap2");
	mcap3 = GetHandle("mcap03");
	mcap4 = GetHandle("mcap4");
	mcap5 = GetHandle("mcap5");
	mcap6 = GetHandle("mcap6");
	rhino1 = NULL;
	rhino2 = NULL;
	rhino3 = NULL;
	rhino4 = NULL;
	builder = GetHandle("builder");
	leader = NULL;
	nearest_enemy = NULL;

	scion1 = GetHandle("scion1");
	scion2 = GetHandle("scion2");
	scion3 = GetHandle("scion3");
	scion4 = GetHandle("scion4");
	scion5 = NULL;
	scion6 = NULL;
	scion7 = NULL;
	scion8 = NULL;
	stop_guard1 = GetHandle("stop_guard1");
	stop_guard2 = GetHandle("stop_guard2");
	guard1 = NULL;
	guard2 = NULL;
	guard3 = GetHandle("guard3");
	player_ship = GetHandle("player_ship");
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
	transport = GetHandle("transport");
	dead_tank1 = GetHandle("dead_tank1");
	dead_tank2 = GetHandle("dead_tank2");
	cheat_tank1 = NULL;
	cheat_tank2 = NULL;
	cheat_tank3 = NULL;
	block_turret1 = GetHandle("block_turret1");
	block_turret2 = GetHandle("block_turret2");
	block_turret3 = GetHandle("block_turret3");
	block_turret4 = GetHandle("block_turret4");
	antenna = GetHandle("antenna");
	patroler1 = NULL;
	patroler2 = NULL;
	satch = NULL;
	patrol_sent1 = NULL;
	patrol_sent2 = NULL;
	talk = 0;
	crash_tank = GetHandle("crash_tank");
	crash_scout = GetHandle("crash_scout");
	open_drop = GetHandle("open_drop");
	standin = GetHandle("standin");
	holder1 = NULL;
	holder2 = NULL;
	holder3 = NULL;

	PreloadODF("bcrhino");

//  integers


}

// this is where I determine what the ScionS are building
void Misn10Mission::AddObject(Handle h)
{
	char ODFName[64];
	GetObjInfo(h, Get_CFG, ODFName);

	if (!start_done)
		return;

	// don't take over a vehicle if the player is in it
	if (h == GetPlayerHandle())
		return;

	// SCOUT
	if ((!scout1_a) && (IsOdf2(h,"fvscout")))
	{
		scout1 = h;
		scout1_a = true;
	}
	else if ((!scout2_a) && (IsOdf2(h,"fvscout")))
	{
		scout2 = h;
		scout2_a = true;
	}
	else if ((!scout3_a) && (IsOdf2(h,"fvscout")))
	{
		scout3 = h;
		scout3_a = true;
	}
	else if ((!scout4_a) && (IsOdf2(h,"fvscout")))
	{
		scout4 = h;
		scout4_a = true;
	}
/*	
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
*/
	// SENTRY
	else if ((!sent1_a) && (IsOdf2(h,"fvsent")))
	{
		sent1 = h;
		sent1_attack_recy = false;
		sent1_a = true;
	}
	else if ((!sent2_a) && (IsOdf2(h,"fvsent")))
	{
		sent2 = h;
		sent2_attack_recy = false;
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
		war1_attack_recy = false;
		war1_a = true;
	}
	else if ((!war2_a) && (IsOdf2(h,"fvtank")))
	{
		war2 = h;
		war1_attack_recy = false;
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
	
	// MAULER
	else if ((!maul1_a) && (IsOdf2(h,"fvwalk")))
	{
		maul1 = h;
		maul1_attack_recy = false;
		maul1_a = true;
	}
	else if ((!maul2_a) && (IsOdf2(h,"fvwalk")))
	{
		maul2 = h;
		maul2_attack_recy = false;
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

	// first isdf scav
	else if ((!first_scav) && (IsOdf2(h,"ibscav")))
	{
		first_scav = true;
	}

	// satchel charge
	else if ((!satch_alive) && (IsOdf2(h,"satchel")))
	{
		satch = h;
		satch_alive = true;
	}

}

void Misn10Mission::Execute(void)
{
/*
	Here is where you put what happens every frame.  
*/

	player = GetPlayerHandle();
	char tempstr[128];


	// this is the opening code

	if (!hold_stuff)
	{
		RemoveObject(dead_tank1);

		SetColorFade(1,0.5f,RGBA_MAKE(0, 0, 0, 255));

		StartEarthQuake(5.0);

		Defend(block_turret1);
		Defend(block_turret2);
		Defend(block_turret3);
		Defend(block_turret4);

		LookAt(standin,wingman);

		Build(builder,"fbantm1");

		SetObjectiveOn(nav1);
		TranslateString2(tempstr, sizeof(tempstr), "Mission1001");  // Drop Zone

		SetObjectiveName(nav1,tempstr);
		SetObjectiveOff(nav1);
		
		Ally(3,1);
		Ally(1,3);

		LookAt(wingman,player);
		Stop(crash_tank);
		Stop(crash_scout);
		holder1 = BuildObject("stayput",0,player);
		holder2 = BuildObject("stayput",0,crash_tank);
		holder3 = BuildObject("stayput",0,crash_scout);
		talk_time = GetTime() + 2.0f;
		hold_stuff = true;
	}

	if ((!first_talk) && (talk_time < GetTime()))
	{
		talk = AudioMessage("isdf1030.wav");
		talk_time = GetTime() + 99999.9f;
		first_talk = true;
	}

	if ((!second_talk) && (first_talk) && (IsAudioMessageDone(talk)))
	{
		talk = AudioMessage("isdf1031.wav");
		swap_time = GetTime() + 10.0f;
		second_talk = true;
	}

	if ((!boom) && (second_talk) && (swap_time < GetTime()))
	{
		StartSoundEffect("xemt2.wav");
		swap_time = GetTime() + 3.0f;
		sound_time = GetTime() + 1.0f;
		UpdateEarthQuake(40.0);
		boom = true;
	}

	if ((!fall_sound) && (boom) && (sound_time < GetTime()))
	{
		sound_time = GetTime() + 99999.9f;
		StartSoundEffect("dropfall.wav");
		fall_sound = true;
	}

	if ((!last_talk) && (boom) && (swap_time < GetTime()))
	{
		//StartSoundEffect("dropfall.wav");
		talk = AudioMessage("isdf1032.wav");
		swap_time = GetTime() + 10.0f;
		last_talk = true;
	}


	if ((!black) && (last_talk) && (swap_time < GetTime()))
	{
		swap_time = GetTime() + 0.2f;
		StartSoundEffect("dropcrsh.wav");
		SetColorFade(4,0.2f,RGBA_MAKE(0, 0, 0, 255));
		black = true;
	}

	if (!free_player)
	{
		VehicleControls controls;
		controls.braccel = 0;
		controls.strafe = 0;
		controls.jump = 0;
		controls.deploy = 0;
		controls.eject = 0;
		controls.abandon = 0;
		controls.fire = 0;
		SetControls(player, controls,
			CTRL_BRACCEL +
			CTRL_STRAFE +
			CTRL_JUMP +
			CTRL_DEPLOY +
			CTRL_EJECT +
			CTRL_ABANDON +
			CTRL_FIRE
			);
	}


	if ((!big_switch) && (black) && (swap_time < GetTime()))
	{
		StartSoundEffect("xms2.wav");
		Matrix pos;
		GetPosition(standin,pos);
		RemoveObject(standin);
		SetPosition(player,pos);
		RemoveObject(open_drop);
		RemoveObject(crash_tank);
		RemoveObject(crash_scout);
		RemoveObject(holder1);
		RemoveObject(holder2);
		RemoveObject(holder3);
		swap_time = GetTime() + 7.0f;
		StopEarthQuake();
		big_switch = true;
	}


	if ((!free_player) && (big_switch) && (swap_time < GetTime()))
	{
		swap_time = GetTime() + 999999.9f;
		free_player = true;
	}

////////////////////////////////////////////////////////////////
if (ON_HOLD)
{
	if (!start_done)
	{
		in_air = true;
		land_time = GetTime() + 20.0f;
		start_done = true;
	}
}

if (!ON_HOLD)
{
////////////////////////////////////////////////////////////////


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
	////////////////////////////////////////
	if ((guard1_a) && (!IsAlive(guard1)))
	{
		guard1_to_post = false;
		guard1_a = false;
	}
	if ((guard2_a) && (!IsAlive(guard2)))
	{
		guard2_to_post = false;
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
	////////////////////////////////////////	
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
		second_patrol2 = false;
		sent4_a = false;
	}
	////////////////////////////////////////
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
	////////////////////////////////////////
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
	////////////////////////////////////////
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
	////////////////////////////////////////


	// this is the second patrol code

	if ((second_patrol1) && (!IsAlive(patrol_sent1)) && (!IsAlive(patrol_sent2)))
	{
		patrol_time = GetTime() + 120.0f;
		second_patrol1 = false;
	}
	////////////////////////////////////////


	// this is the turret code
	
	if ((!stop_guard1_dead) && (!IsAlive(stop_guard1)))
	{
		stop_guard1 = BuildObject("fvturr",2,"new_turr1");  // QA complained that these respawn
		Goto(stop_guard1,"sspawn1");
		guard1_time = GetTime() + 25.0f;
		stop_guard1_dead = true;
	}

	if ((guard1_time < GetTime()) && (!guard1_to_post))
	{
		guard1_time = GetTime() + 999999.9f;
		guard1_to_post = true;
	}

	if (stop_guard1_dead)
	{
		if (guard1_to_post)
		{
			Goto(stop_guard1,"guard_point1");
			guard1_to_post = false;
			stop_guard1_dead = false;
		}
	}


	if ((!stop_guard2_dead) && (!IsAlive(stop_guard2)))
	{
		stop_guard2 = BuildObject("fvturr",2,"new_turr2");
		Goto(stop_guard2,"sspawn1");
		guard2_time = GetTime() + 25.0f;
		stop_guard2_dead = true;
	}

	if ((guard2_time < GetTime()) && (!guard2_to_post))
	{
		guard2_time = GetTime() + 999999.9f;
		guard2_to_post = true;
	}

	if (stop_guard2_dead)
	{
		if (guard2_to_post)
		{
			Goto(stop_guard2,"guard_point2");
			guard2_to_post = false;
			stop_guard2_dead = false;
		}
	}
	////////////////////////////////////////////


	// this is the satchel charge code

	if (satch_alive)
	{
		if ((!ship1_bomb) && (IsAround(crash_ship1)))
		{
			if (GetDistance(satch,crash_ship1) < 60.0f)
			{
				ship1_bomb = true;
			}
		}

		if ((!ship2_bomb) && (IsAround(crash_ship2)))
		{
			if (GetDistance(satch,crash_ship2) < 60.0f)
			{
				ship2_bomb = true;
			}
		}

		if (!IsAround(satch))
		{
			if ((ship1_bomb) && (IsAround(crash_ship1)))
			{
				if (IsAround(dead_tank1))
				{
					RemoveObject(dead_tank1);
				}
				if (IsAround(dead_tank2))
				{
					RemoveObject(dead_tank2);
				}

				Damage(crash_ship1,5000);
			}

			if ((ship2_bomb) && (IsAround(crash_ship2)))
			{
				Damage(crash_ship2,5000);
			}

			satch_alive = false;
		}
	}


// start of the mission

if ((!part_two) && (!ON_HOLD))
{

	if ((!start_done) && (big_switch))
	{
		rhino1 = BuildObject("bcrhino",2,"rhino1_point");
		rhino2 = BuildObject("bcrhino",2,"rhino2_point");
		rhino3 = BuildObject("bcrhino",2,"rhino3_point");
		rhino4 = BuildObject("bcrhino",2,"rhino4_point");

		SetPerceivedTeam(rhino1,1);
		SetPerceivedTeam(rhino2,1);
		SetPerceivedTeam(rhino3,1);
		SetPerceivedTeam(rhino4,1);
		//SetAvoidType(rhino1,0);
		//SetAvoidType(rhino2,0);
		//SetAvoidType(rhino3,0);
		//SetAvoidType(rhino4,0);

		SetPlan("isdf1001.aip",2);

		rhino1_check = GetTime() + 1.0f;
		rhino2_check = GetTime() + 1.0f;
		rhino3_check = GetTime() + 1.0f;
		rhino4_check = GetTime() + 1.0f;
		
		wing_check = GetTime() + 1.0f;
		detect_check = GetTime() + 2.0f;
		//patrol1_time = GetTime() + 1.0f;
		forget_check = GetTime() + 2.0f;
		
		start_done = true;
	}


	// this is freeing the recycler when the player gets close enough

	if (!free_recycler)
	{
		Stop(recycler,1);
		Stop(transport,1);
	}


	if ((!free_recycler) && (recy_check < GetTime()))
	{
		recy_check = GetTime() + 1.0f;


		if (GetDistance(player,recycler) < 150.0f)
		{
			Stop(recycler,0);
			Follow(transport,recycler,1);
			SetObjectiveOff(recycler);
			AddScrap(1,40);
			SetAvoidType(recycler,0);
			maze_check = GetTime() + 2.0f;
			recy_death_check = GetTime() + 2.0f;
			free_recycler = true;

			Vector OldPos;
			Vector Where;
			GetPosition2(recycler,OldPos);
			Where=GetPositionNear(OldPos,AllyMinRadiusAway,AllyMaxRadiusAway);

			Handle TurrH = BuildObject("ivturr",1,Where);
			SetGroup(TurrH,2);
			SetSkill(TurrH, 2);
		}
	}
	////////////////////////////////////////////


	// this is starting the first patrol

	if ((!start_patrol1) && (patrol1_time < GetTime()))
	{
		Patrol(scion1,"patrol_path1a");
		Follow(scion2,scion1);
		discover1_time = GetTime() + 2.0f;
		patrol1_time = GetTime() + 999999.9f;
		patrol2_time = GetTime() + 60.0f;
		start_patrol1 = true;
	}
	////////////////////////////////////////////


	// this is starting the second patrol

	if ((!start_patrol2) && (patrol2_time < GetTime()))
	{
		if (IsAlive(scion3))
		{
			Patrol(scion3,"patrol_path1a");
		}

		if (IsAlive(scion4))
		{
			Follow(scion4,scion3);
		}

		patrol2_time = GetTime() + 999999.9f;
		start_patrol2 = true;
	}
	////////////////////////////////////////////


	// this sends the scion scouts after the player

	if (!cover_tracks_message)
	{
		if ((!discover1) && (discover1_time < GetTime()))
		{
			discover1_time = GetTime() + 2.0f;

			if ((IsAlive(scion1)) && (GetDistance(scion1,"wingman_point") < 60.0f))
			{
			    Goto(scion1,recycler);
				discover1 = true;
			}
		}

		if ((!discover2) && (discover2_time < GetTime()))
		{
			discover2_time = GetTime() + 2.0f;

			if ((IsAlive(scion3)) && (GetDistance(scion3,"wingman_point") < 60.0f))
			{
			    Goto(scion3,recycler);
				discover2 = true;
			}
		}
	}
	////////////////////////////////////////////


	// this will keep the patrols going

	if (start_patrol1)
	{
		if ((!patrol1_dead) && (!IsAlive(scion1)) && (!IsAlive(scion2)))
		{
			patrol1_time = GetTime() + 60.0f;
			discover1_time = GetTime() + 999999.9f;
			discover1 = false;
			patrol1_dead = true;
		}

		if ((patrol1_dead) && (patrol1_time < GetTime()))
		{
			scion1 = BuildObject("fvsent10x",2,"sspawn1");
			scion2 = BuildObject("fvsent10x",2,"sspawn2");
			Patrol(scion1,"patrol_path1a");
			Follow(sent2,scion1);
			discover1_time = GetTime() + 2.0f;
			patrol1_time = GetTime() + 999999.9f;
			patrol1_dead = false;
		}
	}

	if (start_patrol2)
	{
		if ((!patrol2_dead) && (!IsAlive(scion3)) && (!IsAlive(scion4)))
		{
			patrol2_time = GetTime() + 60.0f;
			discover2_time = GetTime() + 999999.9f;
			discover2 = false;
			patrol2_dead = true;
		}


		if ((patrol2_dead) && (patrol1_time < GetTime()))
		{
			scion3 = BuildObject("fvsent10x",2,"sspawn3");
			scion4 = BuildObject("fvsent10x",2,"sspawn4");
			Patrol(scion3,"patrol_path1a");
			Follow(scion4,scion3);
			discover2_time = GetTime() + 2.0f;
			patrol2_time = GetTime() + 999999.9f;
			patrol2_dead = false;
		}
	}
	////////////////////////////////////////////
	

	


	// this is getting the wingman to leave the crashed ship and look at it

	if (!wing_move)
	{
		//Goto(wingman,"wingman_point",0);
		//wing_turn_time = GetTime() + 3.0f;
		wing_move = true;
	}


	if ((!wing_turn) && (big_switch) && (GetDistance(player,wingman) < 45.0f))
	{
		talk = AudioMessage("isdf1001.wav");// (wingman) What do we do?! We're abandoned!
		SetObjectiveOn(nav1);
		TranslateString2(tempstr, sizeof(tempstr), "Mission1001");  // Drop Zone
		SetObjectiveName(nav1,tempstr);
		LookAt(wingman,player,0);
		wing_turn_time = GetTime() + 18.0f;
		wing_turn = true;
	}


	if ((!wing_free) && (wing_turn) && (wing_turn_time < GetTime()))
	{
		//Stop(wingman,0);
		ClearObjectives();
		AddObjective("nav1.otf", WHITE);
		wing_free = true;
	}
	////////////////////////////////////////////


	if (IsAlive(wingman))
	{
		// this is the wingman hinting at destroying the crash ship code

		if ((IsAround(crash_ship1)) && (!destroy_hint))
		{
			// player orders wing to FOLLOW

			if (GetCurrentCommand(wingman) == CMD_FOLLOW)
			{
				leader = GetCurrentWho(wingman);


				if (leader == player)
				{
					if (!wing_free)
					{
						ClearObjectives();
						AddObjective("nav1.otf", WHITE);
						wing_free = true;
					}

					StopAudioMessage(talk);
					AudioMessage("isdf1002.wav");//(wingman) What do you think we should do about that crashed ship? Its a dead give-away 
					patrol1_time = GetTime() + 60.0f;
					destroy_hint = true;
				}
			}


			// if an emeny enters wingmans radar range

			//if ((!destroy_hint) && (wing_check < GetTime()))
			//{
			//	wing_check = GetTime() + 1.0f;
			//	nearest_enemy = GetNearestEnemy(wingman);

			//	if ((nearest_enemy != 0) && (GetDistance(nearest_enemy,wingman) < 475.0f))
			//	{
			//		AudioMessage("isdf1003.wav");//(wingman) This place is probably crawling with Scions - our crashed ship will give us away 
			//		destroy_hint = true;
			//	}
			//}
		}
		////////////////////////////////////////////


		// this is if the player destoys the crash ship

		if ((!IsAround(crash_ship1)) && (!cover_tracks_message))
		{
			if (!free_recycler)
			{
				AudioMessage("isdf1004.wav");//(wingman) that ought to cover our tracks for a while
			}

			cover_tracks_message = true;
		}
		////////////////////////////////////////////


		// this is the wingman detecting the reycler

		if ((!free_recycler) && (!recy_detected_message) && (detect_check < GetTime()))
		{
			detect_check = GetTime() + 2.0f;


			if (GetDistance(wingman,recycler) < 450.0f)
			{
				AudioMessage("isdf1005.wav");//(wingman) I've got a big green radar hit 400 meters to the west commander - might be Rosas's squad
				SetObjectiveOn(recycler);
				TranslateString2(tempstr, sizeof(tempstr), "Mission1002");  // Radar Contact
				SetObjectiveName(recycler,tempstr);
				recy_detected_message = true;
			}
		}
		////////////////////////////////////////////
	}

	// this is the ice caps code

	if (!caps_gone)
	{
		if (!IsAround(scap1))
		{
			scap1_gone = true;
		}
		if (!IsAround(scap2))
		{
			scap2_gone = true;
		}
		
		if (!IsAround(mcap1))
		{
			mcap1_gone = true;
		}
		if (!IsAround(mcap2))
		{
			mcap2_gone = true;
		}
		if (!IsAround(mcap3))
		{
			mcap3_gone = true;
		}
		if (!IsAround(mcap4))
		{
			mcap4_gone = true;
		}
		if (!IsAround(mcap5))
		{
			mcap5_gone = true;
		}
		if (!IsAround(mcap6))
		{
			mcap6_gone = true;
		}

		if ((mcap2_gone) && (mcap3_gone) && (mcap5_gone))
		{
			caps_gone = true;
		}
	}
	////////////////////////////////////////////
	
	
	if (free_recycler)
	{
		// the recycler's first message

		if (!recycler_message1)
		{
			if (caps_gone)
			{
				AudioMessage("isdf1006.wav");// (recycler) You've cleared the caps - get me out of here
				ClearObjectives();
				AddObjective("nav1.otf", WHITE);
				AddObjective("recycler.otf", WHITE);
				Goto(recycler,"safe_path",0);
				recycler_underway = true;
			}
			else
			{
				AudioMessage("isdf1007.wav");// (recycler) My radar is out - help me out of here
				ClearObjectives();
				AddObjective("nav1.otf", WHITE);
				AddObjective("recycler.otf", WHITE);
				free_first = true;
			}

			recycler_message1 = true;
		}
		////////////////////////////////////////////


		// this is checking to see where the recycler is on the maze

		if (maze_check < GetTime())
		{
			maze_check = GetTime() + 2.0f;

			// check to see where the recycler is at on the maze

			if ((!at_one) && (GetDistance(recycler,"maze_point1") < 50.0f))
			{
				cheat2_time = GetTime() + 10.0f;
				at_one = true;
				recycler_underway = true;
			}

#ifdef NO_MAZE
			if ((!at_two))
#else
				if ((at_one) && (!at_two))
#endif
			{
				if  (GetDistance(recycler,"maze_point2") < 50.0f)
				{
					at_one = true;
					at_two = true;
					recycler_underway = true;
				}
			}
			
#ifdef NO_MAZE
			if ((!at_three))
#else
			if ((at_two) && (!at_three))
#endif
			{
				if  (GetDistance(recycler,"maze_point3") < 50.0f)
				{
					at_one = true;
					at_two = true;
					at_three = true;
					recycler_underway = true;

				}
			}

#ifdef NO_MAZE
			if ((!at_four))
#else
			if ((at_three) && (!at_four))
#endif
			{
				if  (GetDistance(recycler,"maze_point4") < 50.0f)
				{
					at_one = true;
					at_two = true;
					at_three = true;
					at_four = true;
				recycler_underway = true;
				}
			}

			/////////////////////////////////////////////


#ifdef NO_MAZE
			if ((!near_madeit))
#else
			if ((at_four) && (!near_madeit))
#endif
			{
				if  (GetDistance(recycler,"madeit_point") < 100.0f)
				{
					at_one = true;
					at_two = true;
					at_three = true;
					at_four = true;
					near_madeit = true;
				recycler_underway = true;
				}
			}

#ifdef NO_MAZE
			if ((!at_madeit))
#else
			if ((near_madeit) && (!at_madeit))
#endif
			{
				if  (GetDistance(recycler,"madeit_point") < 50.0f)
				{
					at_one = true;
					at_two = true;
					at_three = true;
					at_four = true;
					near_madeit = true;
					at_madeit = true;
				recycler_underway = true;
				}
			}


			if ((recycler_message1) && (!at_nav))
			{
				if  (GetDistance(recycler,nav1) < 70.0f)
				{
					ClearObjectives();
					AddObjective("nav1.otf", GREEN);
					AddObjective("recycler.otf", GREEN);
					new_plan_time = GetTime() + 300.0f;
					//SetPlan("isdf1002.aip",2);

					if (IsAlive(transport))
					{
						Follow(transport,recycler,0);
					}

					patrol_time = GetTime() + 120.0f;
					part_two = true;	
					at_nav = true;
				}
			}
		}
		////////////////////////////////////////////


		// this is if I script the recycle to the "madeit_point"

		if ((recycler_underway) && (!underway_canceled) && (!madeit_message))
		{
			if ((IsSelected(recycler)) && (!whyselected_message))
			{
				AudioMessage("isdf1008.wav");//(recycler) I'm trying to navigate my way out of here - do you want me to do something else?!
				whyselected_message = true;
			}


			if ((at_madeit) && (!madeit_message))
			{
				Stop(recycler,0);
				AudioMessage("isdf1009.wav");//(recycler) I'm through commander - take me to the landing site
				madeit_message = true;
			}


			if ((whyselected_message) && (!madeit_message))
			{
				if ((!underway_canceled) && (GetCurrentCommand(recycler) != CMD_GO))
				{
					AudioMessage("isdf1010.wav");//(recycler) You've got to get me to the drop site commander
					underway_canceled = true;
				}
			}
		}
		////////////////////////////////////////////
		
		
		// this is checking to see when enouph caps are gone for the recycler to make it

		if (free_first)
		{
			if (!caps_gone_message)
			{
				if ((!at_one) && (caps_gone))
				{
					AudioMessage("isdf1011.wav");// (recycler) I have a pretty good line of sight to the nav - you can order me there
					Goto(recycler,"safe_path",0);
					recycler_underway = true;
					caps_gone_message = true;
				}


				if ((at_one) && (!at_two))
				{
					if ((mcap3_gone) && (mcap4_gone) && (mcap5_gone))
					{
						AudioMessage("isdf1011.wav");// (recycler) I have a pretty good line of sight to the nav - you can order me there
						Goto(recycler,"safe_path1",0);
						recycler_underway = true;
						caps_gone_message = true;
					}
				}


				if ((at_two) && (!at_three))
				{
					if ((mcap3_gone) && (mcap5_gone))
					{
						AudioMessage("isdf1011.wav");// (recycler) I have a pretty good line of sight to the nav - you can order me there
						Goto(recycler,"safe_path2",0);
						recycler_underway = true;
						caps_gone_message = true;
					}
				}


				if ((at_three) && (!at_four))
				{
					if ((mcap5_gone))
					{
						AudioMessage("isdf1011.wav");// (recycler) I have a pretty good line of sight to the nav - you can order me there
						Goto(recycler,"safe_path3",0);
						recycler_underway = true;
						caps_gone_message = true;
					}
				}

				
				if ((at_four) && (!at_madeit))
				{
					if ((mcap5_gone))
					{
						AudioMessage("isdf1011.wav");// (recycler) I have a pretty good line of sight to the nav - you can order me there
						Goto(recycler,"safe_path4",0);
						recycler_underway = true;
						caps_gone_message = true;
					}
				}


				if (at_madeit)
				{
					caps_gone_message = true;
				}
			}
		}
		////////////////////////////////////////////
	}


	// this is creating cheat ships

	if (!drop_message1)
	{
		if ((!cheat2) && (at_one) && (cheat2_time < GetTime()))
		{
			cheat2_time = GetTime() + 180.0f;
			cheat_tank1 = BuildObject("fvtank10x",2,"cheat_spawn4");
			cheat_tank2 = BuildObject("fvsent10x",2,"cheat_spawn5");
			Attack(cheat_tank1,recycler);
			Follow(cheat_tank2,cheat_tank1);
			cheat2 = true;
		}

		if (cheat2)
		{
			if ((!IsAlive(cheat_tank1)) && (!IsAlive(cheat_tank2)))
			{
				cheat2 = false;
			}
		}
	}
	////////////////////////////////////////////


	// this is the player finding the enemy base code

	if (!base_message)
	{
		if (forget_check < GetTime())
		{
			forget_check = GetTime() + 2.0f;

			if (GetDistance(player,"choke_point1") < 100.0f)
			{
				forget_check = GetTime() + 999999.9f;
				base_message = true;
			}

			if ((GetDistance(player,sscav2) < 140.0f) || (GetDistance(player,"antenna_point") < 140.0f))
			{
				if (IsAlive(wingman))
				{
					AudioMessage("isdf1033.wav"); // (wingman) This looks like the scion base!
				}

				if (IsAlive(builder))
				{
					Dropoff(builder,"antenna_point",2);
				}

				forget_check = GetTime() + 999999.9f;
				base_message = true;
			}
		}
	}
	////////////////////////////////////////////
}



if (!ON_HOLD)
{
	// this is checking to see if the RECYCLER falls into the ice caps

	if ((free_first) && (IsAround(recycler)))
	{
		if ((!recy_fall_in) && (recy_death_check < GetTime()))
		{
			recy_death_check = GetTime() + 1.0f;


			if (IsAround(mcap1))
			{
				if (GetDistance(recycler,"mcap1_point") < 60.0f)
				{
					SetAnimation(mcap1,"break",1);
					StartSoundEffect("icecrck1.wav");
					anim_wait = GetTime() + 5.0f;
					mcap1_start = true;
					recy_fall_in = true;
				}
			}

			if (IsAround(mcap2))
			{
				if ((GetDistance(recycler,"mcap2_pointa") < 60.0f) || 
					(GetDistance(recycler,"mcap2_pointb") < 60.0f))
				{
					SetAnimation(mcap2,"break",1);
					StartSoundEffect("icecrck1.wav");
					anim_wait = GetTime() + 5.0f;
					mcap2_start = true;
					recy_fall_in = true;
				}
			}

			if (IsAround(mcap3))
			{
				if (GetDistance(recycler,"mcap3_point") < 60.0f)
				{
					SetAnimation(mcap3,"break",1);
					StartSoundEffect("icecrck1.wav");
					anim_wait = GetTime() + 5.0f;
					mcap3_start = true;
					recy_fall_in = true;
				}
			}

			if (IsAround(mcap4))
			{
				if ((GetDistance(recycler,"mcap4_pointa") < 60.0f) || 
					(GetDistance(recycler,"mcap4_pointb") < 60.0f))
				{
					SetAnimation(mcap4,"break",1);
					StartSoundEffect("icecrck1.wav");
					anim_wait = GetTime() + 5.0f;
					mcap4_start = true;
					recy_fall_in = true;
				}
			}

			if (IsAround(mcap5))
			{
				if ((GetDistance(recycler,"mcap5_pointa") < 60.0f) || 
					(GetDistance(recycler,"mcap5_pointb") < 60.0f))
				{
					SetAnimation(mcap5,"break",1);
					StartSoundEffect("icecrck1.wav");
					anim_wait = GetTime() + 5.0f;
					mcap5_start = true;
					recy_fall_in = true;
				}
			}

			if (IsAround(mcap6))
			{
				if ((GetDistance(recycler,"mcap6_pointa") < 60.0f) || 
					(GetDistance(recycler,"mcap6_pointb") < 60.0f))
				{
					SetAnimation(mcap6,"break",1);
					StartSoundEffect("icecrck1.wav");
					anim_wait = GetTime() + 5.0f;
					mcap6_start = true;
					recy_fall_in = true;
				}
			}

			if (GetDistance(recycler,"short_cut") < 60.0f)
			{
				if (IsAround(mcap2))
				{
					SetAnimation(mcap2,"break",1);
					StartSoundEffect("icecrck1.wav");
					mcap2_start = true;
				}

				if (IsAround(mcap3))
				{
					SetAnimation(mcap3,"break",1);
					StartSoundEffect("icecrck1.wav");
					mcap3_start = true;
				}

				anim_wait = GetTime() + 5.0f;
				recy_fall_in = true;
			}
		}
	}
	////////////////////////////////////////////


	// this is checking to see if one of the rhinos is shot.

	if ((IsAlive(rhino1)) && (!rhino1_charge))
	{
		if (GetTime() - GetLastEnemyShot(rhino1) < .2f) //(GetWhoShotMe(rhino1) == player)
		{
			StartSoundEffect("rhin08.wav",rhino1);
			Attack(rhino1,player,1);
			rhino1_charge = true;
		}
		
		// this keeps rhino 1 near his spawn point

		if (rhino1_check < GetTime())
		{
			rhino1_check = GetTime() + 1.0f;
			
			if (!rhino1_behave)
			{
				if (GetDistance(rhino1,"rhino1_point") > 50.0f)
				{
					Goto(rhino1,"rhino1_point",1);
					rhino1_check = GetTime() + 1.0f;
					rhino1_behave = true;
				}
			}
			else
			{
				if (GetDistance(rhino1,"rhino1_point") < 30.0f)
				{
					rhino1_behave = false;
				}
			}
		}
	}

	if ((IsAlive(rhino2)) && (!rhino2_charge))
	{
		if (GetTime() - GetLastEnemyShot(rhino2) < .2f) //(GetWhoShotMe(rhino1) == player)
		{
			StartSoundEffect("rhin08.wav",rhino2);
			Attack(rhino2,player,1);
			rhino2_charge = true;
		}
		
		// this keeps rhino 2 near his spawn point

		else if (rhino2_check < GetTime())
		{
			rhino2_check = GetTime() + 1.0f;

			if (!rhino2_after_recy)
			{
				if (at_two)
				{
					Attack(rhino2,recycler);
					rhino2_after_recy = true;
				}
			}

			if (!rhino2_behave)
			{
				if (GetDistance(rhino2,"rhino2_point") > 50.0f)
				{
					Goto(rhino2,"rhino2_point",1);
					rhino2_check = GetTime() + 1.0f;
					rhino2_behave = true;
				}
			}
			else
			{
				if (GetDistance(rhino2,"rhino2_point") < 30.0f)
				{
					rhino2_behave = false;
				}
			}
		}
	}

	if ((IsAlive(rhino3)) && (!rhino3_charge))
	{
		if (GetTime() - GetLastEnemyShot(rhino3) < .2f) //(GetWhoShotMe(rhino1) == player)
		{
			StartSoundEffect("rhin08.wav",rhino3);
			Attack(rhino3,player,1);
			rhino3_charge = true;
		}
		
		// this keeps rhino 3 near his spawn point

		else if (rhino3_check < GetTime())
		{
			rhino3_check = GetTime() + 1.0f;

			if (!rhino3_after_recy)
			{
				if (at_three)
				{
					Attack(rhino3,recycler);
					rhino3_after_recy = true;
				}
			}
			
			if (!rhino3_behave)
			{
				if (GetDistance(rhino3,"rhino3_point") > 50.0f)
				{
					Goto(rhino3,"rhino3_point",1);
					rhino3_check = GetTime() + 1.0f;
					rhino3_behave = true;
				}
			}
			else
			{
				if (GetDistance(rhino3,"rhino3_point") < 30.0f)
				{
					rhino3_behave = false;
				}
			}
		}
	}

	if ((IsAlive(rhino4)) && (!rhino4_charge))
	{
		if (GetTime() - GetLastEnemyShot(rhino4) < .2f) //(GetWhoShotMe(rhino1) == player)
		{
			StartSoundEffect("rhin08.wav",rhino4);
			Attack(rhino4,player,1);
			rhino4_charge = true;
		}
		
		// this keeps rhino 4 near his spawn point

		else if (rhino4_check < GetTime())
		{
			rhino4_check = GetTime() + 1.0f;

			if (!rhino4_after_recy)
			{
				if (at_four)
				{
					Attack(rhino4,recycler);
					rhino4_after_recy = true;
				}
			}
			
			if (!rhino4_behave)
			{
				if (GetDistance(rhino4,"rhino4_point") > 50.0f)
				{
					Goto(rhino4,"rhino4_point",1);
					rhino4_check = GetTime() + 1.0f;
					rhino4_behave = true;
				}
			}
			else
			{
				if (GetDistance(rhino4,"rhino4_point") < 30.0f)
				{
					rhino4_behave = false;
				}
			}
		}
	}
	////////////////////////////////////////////


	// this is checking to see if a RHINO falls into the ice caps

	if (rhino1_charge)
	{
		if ((!rhino1_in) && (rhino1_check < GetTime()))
		{
			rhino1_check = GetTime() + 1.0f;

			if ((IsAlive(rhino1)) && (IsAround(scap1)))
			{
				if (GetDistance(rhino1,"scap1_point") < 50.0f)
				{
					SetAnimation(scap1,"break",1);
					StartSoundEffect("icecrck1.wav");
					anim_wait = GetTime() + 6.0f;
					rhino1_check = GetTime() + 0.4f;
					Defend(rhino1,0);
					scap1_start = true;
					rhino1_in = true;
				}
			}

			if ((IsAlive(rhino1)) && (IsAround(scap2)))
			{
				if (GetDistance(rhino1,"scap2_point") < 50.0f)
				{
					SetAnimation(scap2,"break",1);
					StartSoundEffect("icecrck1.wav");
					anim_wait = GetTime() + 6.0f;
					rhino1_check = GetTime() + 0.4f;
					Defend(rhino1,0);
					scap2_start = true;
					rhino1_in = true;
				}
			}
		}
	}

	if (rhino2_charge)
	{
		if ((!rhino2_in) && (rhino2_check < GetTime()))
		{
			rhino2_check = GetTime() + 1.0f;

			if (IsAlive(rhino2))
			{
				if (IsAround(mcap1))
				{
					if (GetDistance(rhino2,"mcap1_point") < 50.0f)
					{
						SetAnimation(mcap1,"break",1);
						StartSoundEffect("icecrck1.wav");
						anim_wait = GetTime() + 6.0f;
						rhino2_check = GetTime() + 0.4f;
						Defend(rhino2,0);
						mcap1_start = true;
						rhino2_in = true;
					}
				}
				if (IsAround(mcap2))
				{
					if ((GetDistance(rhino2,"mcap2_pointa") < 50.0f) || 
						(GetDistance(rhino2,"mcap2_pointb") < 50.0f))
					{
						SetAnimation(mcap2,"break",1);
						StartSoundEffect("icecrck1.wav");
						anim_wait = GetTime() + 6.0f;
						rhino2_check = GetTime() + 0.4f;
						Defend(rhino2,0);
						mcap2_start = true;
						rhino2_in = true;
					}
				}
				if (IsAround(mcap3))
				{
					if (GetDistance(rhino2,"mcap3_point") < 50.0f)
					{
						SetAnimation(mcap3,"break",1);
						StartSoundEffect("icecrck1.wav");
						anim_wait = GetTime() + 6.0f;
						rhino2_check = GetTime() + 0.4f;
						Defend(rhino2,0);
						mcap3_start = true;
						rhino2_in = true;
					}
				}
				if (IsAround(mcap4))
				{
					if ((GetDistance(rhino2,"mcap4_pointa") < 50.0f) || 
						(GetDistance(rhino2,"mcap4_pointb") < 50.0f))
					{
						SetAnimation(mcap4,"break",1);
						StartSoundEffect("icecrck1.wav");
						anim_wait = GetTime() + 6.0f;
						rhino2_check = GetTime() + 0.4f;
						Defend(rhino2,0);
						mcap4_start = true;
						rhino2_in = true;
					}
				}
				if (IsAround(mcap5))
				{
					if ((GetDistance(rhino2,"mcap5_pointa") < 50.0f) || 
						(GetDistance(rhino2,"mcap5_pointb") < 50.0f))
					{
						SetAnimation(mcap5,"break",1);
						StartSoundEffect("icecrck1.wav");
						anim_wait = GetTime() + 6.0f;
						rhino2_check = GetTime() + 0.4f;
						Defend(rhino2,0);
						mcap5_start = true;
						rhino2_in = true;
					}
				}
				if (IsAround(mcap6))
				{
					if ((GetDistance(rhino2,"mcap6_pointa") < 50.0f) || 
						(GetDistance(rhino2,"mcap6_pointb") < 50.0f))
					{
						SetAnimation(mcap6,"break",1);
						StartSoundEffect("icecrck1.wav");
						anim_wait = GetTime() + 6.0f;
						rhino2_check = GetTime() + 0.4f;
						Defend(rhino2,0);
						mcap6_start = true;
						rhino2_in = true;
					}
				}
			}
		}
	}

	if (rhino3_charge)
	{
		if ((!rhino3_in) && (rhino3_check < GetTime()))
		{
			rhino3_check = GetTime() + 1.0f;

			if (IsAlive(rhino3))
			{
				if (IsAround(mcap1))
				{
					if (GetDistance(rhino3,"mcap1_point") < 50.0f)
					{
						SetAnimation(mcap1,"break",1);
						StartSoundEffect("icecrck1.wav");
						anim_wait = GetTime() + 6.0f;
						rhino3_check = GetTime() + 0.4f;
						Defend(rhino3,0);
						mcap1_start = true;
						rhino3_in = true;
					}
				}
				if (IsAround(mcap2))
				{
					if ((GetDistance(rhino3,"mcap2_pointa") < 50.0f) || 
						(GetDistance(rhino3,"mcap2_pointb") < 50.0f))
					{
						SetAnimation(mcap2,"break",1);
						StartSoundEffect("icecrck1.wav");
						anim_wait = GetTime() + 6.0f;
						rhino3_check = GetTime() + 0.4f;
						Defend(rhino3,0);
						mcap2_start = true;
						rhino3_in = true;
					}
				}
				if (IsAround(mcap3))
				{
					if (GetDistance(rhino3,"mcap3_point") < 50.0f)
					{
						SetAnimation(mcap3,"break",1);
						StartSoundEffect("icecrck1.wav");
						anim_wait = GetTime() + 6.0f;
						rhino3_check = GetTime() + 0.4f;
						Defend(rhino3,0);
						mcap3_start = true;
						rhino3_in = true;
					}
				}
				if (IsAround(mcap4))
				{
					if ((GetDistance(rhino3,"mcap4_pointa") < 50.0f) || 
						(GetDistance(rhino3,"mcap4_pointb") < 50.0f))
					{
						SetAnimation(mcap4,"break",1);
						StartSoundEffect("icecrck1.wav");
						anim_wait = GetTime() + 6.0f;
						rhino3_check = GetTime() + 0.4f;
						Defend(rhino3,0);
						mcap4_start = true;
						rhino3_in = true;
					}
				}
				if (IsAround(mcap5))
				{
					if ((GetDistance(rhino3,"mcap5_pointa") < 50.0f) || 
						(GetDistance(rhino3,"mcap5_pointb") < 50.0f))
					{
						SetAnimation(mcap5,"break",1);
						StartSoundEffect("icecrck1.wav");
						anim_wait = GetTime() + 6.0f;
						rhino3_check = GetTime() + 0.4f;
						Defend(rhino3,0);
						mcap5_start = true;
						rhino3_in = true;
					}
				}
				if (IsAround(mcap6))
				{
					if ((GetDistance(rhino3,"mcap6_pointa") < 50.0f) || 
						(GetDistance(rhino3,"mcap6_pointb") < 50.0f))
					{
						SetAnimation(mcap6,"break",1);
						StartSoundEffect("icecrck1.wav");
						anim_wait = GetTime() + 6.0f;
						rhino3_check = GetTime() + 0.4f;
						Defend(rhino3,0);
						mcap6_start = true;
						rhino3_in = true;
					}
				}
			}
		}
	}

	if (rhino4_charge)
	{
		if ((!rhino4_in) && (rhino4_check < GetTime()))
		{
			rhino4_check = GetTime() + 1.0f;

			if (IsAlive(rhino4))
			{
				if (IsAround(mcap1))
				{
					if (GetDistance(rhino4,"mcap1_point") < 50.0f)
					{
						SetAnimation(mcap1,"break",1);
						StartSoundEffect("icecrck1.wav");
						anim_wait = GetTime() + 6.0f;
						rhino4_check = GetTime() + 0.4f;
						Defend(rhino4,0);
						mcap1_start = true;
						rhino4_in = true;
					}
				}
				if (IsAround(mcap2))
				{
					if ((GetDistance(rhino4,"mcap2_pointa") < 50.0f) || 
						(GetDistance(rhino4,"mcap2_pointb") < 50.0f))
					{
						SetAnimation(mcap2,"break",1);
						StartSoundEffect("icecrck1.wav");
						anim_wait = GetTime() + 6.0f;
						rhino4_check = GetTime() + 0.4f;
						Defend(rhino4,0);
						mcap2_start = true;
						rhino4_in = true;
					}
				}
				if (IsAround(mcap3))
				{
					if (GetDistance(rhino4,"mcap3_point",1) < 50.0f)
					{
						SetAnimation(mcap3,"break");
						StartSoundEffect("icecrck1.wav");
						anim_wait = GetTime() + 6.0f;
						rhino4_check = GetTime() + 0.4f;
						Defend(rhino4,0);
						mcap3_start = true;
						rhino4_in = true;
					}
				}
				if (IsAround(mcap4))
				{
					if ((GetDistance(rhino4,"mcap4_pointa") < 50.0f) || 
						(GetDistance(rhino4,"mcap4_pointb") < 50.0f))
					{
						SetAnimation(mcap4,"break",1);
						StartSoundEffect("icecrck1.wav");
						anim_wait = GetTime() + 6.0f;
						rhino4_check = GetTime() + 0.4f;
						Defend(rhino4,0);
						mcap4_start = true;
						rhino4_in = true;
					}
				}
				if (IsAround(mcap5))
				{
					if ((GetDistance(rhino4,"mcap5_pointa") < 50.0f) || 
						(GetDistance(rhino4,"mcap5_pointb") < 50.0f))
					{
						SetAnimation(mcap5,"break",1);
						StartSoundEffect("icecrck1.wav");
						anim_wait = GetTime() + 6.0f;
						rhino4_check = GetTime() + 0.4f;
						Defend(rhino4,0);
						mcap5_start = true;
						rhino4_in = true;
					}
				}
				if (IsAround(mcap6))
				{
					if ((GetDistance(rhino4,"mcap6_pointa") < 50.0f) || 
						(GetDistance(rhino4,"mcap6_pointb") < 50.0f))
					{
						SetAnimation(mcap6,"break",1);
						StartSoundEffect("icecrck1.wav");
						anim_wait = GetTime() + 6.0f;
						rhino4_check = GetTime() + 0.4f;
						Defend(rhino4,0);
						mcap6_start = true;
						rhino4_in = true;
					}
				}
			}
		}
	}
	////////////////////////////////////////////


	// this is setting the rhino animation and removing him

	if ((rhino1_in) && (rhino1_check < GetTime()))
	{
		if (!animate_rhino1)
		{
			//StartSoundEffect("icecrck1.wav");
			Stop(rhino1);
			//ClearIdleAnims(rhino1);
			//SetAnimation(rhino1,"fall",1);
			//AddIdleAnim(rhino1,"fall");
			rhino1_check = GetTime() + 0.1f;
			animate_rhino1 = true;
		}
		else if (!fall1_already)
		{
			Matrix pos;
			GetPosition(rhino1,pos);
			RemoveObject(rhino1);
			rhino1 = BuildObject("bcrhinof",2,pos);
			SetAnimation(rhino1,"fall",1);

			//ClearIdleAnims(rhino1);
			//AddIdleAnim(rhino1,"fall");
			rhino1_check = GetTime() + 3.0f;
			StartSoundEffect("rhinocry.wav");
			fall1_already = true;
		}
		else
		{
			RemoveObject(rhino1);

			if (IsAlive(wingman))
			{
				talk = AudioMessage("isdf1034.wav");// (wingman) I don't know what that was but it is dead
			}

			rhino1_check = GetTime() + 999999.9f;
		}
	}

	if ((rhino2_in) && (rhino2_check < GetTime()))
	{
		if (!animate_rhino2)
		{
			//StartSoundEffect("icecrck1.wav");
			Stop(rhino2);
			//ClearIdleAnims(rhino2);
			//AddIdleAnim(rhino2,"fall");
			rhino2_check = GetTime() + 0.1f;
			animate_rhino2 = true;
		}
		else if (!fall2_already)
		{
			Matrix pos;
			GetPosition(rhino2,pos);
			RemoveObject(rhino2);
			rhino2 = BuildObject("bcrhinof",2,pos);
			SetAnimation(rhino2,"fall",1);

			//ClearIdleAnims(rhino2);
			//AddIdleAnim(rhino2,"fall");
			rhino2_check = GetTime() + 3.0f;
			StartSoundEffect("rhinocry.wav");
			fall2_already = true;
		}
		else
		{
			RemoveObject(rhino2);
			rhino2_check = GetTime() + 999999.9f;
		}
	}

	if ((rhino3_in) && (rhino3_check < GetTime()))
	{
		if (!animate_rhino3)
		{
			//StartSoundEffect("icecrck1.wav");
			Stop(rhino3);
			//ClearIdleAnims(rhino3);
			//AddIdleAnim(rhino3,"fall");
			rhino3_check = GetTime() + 0.1f;
			animate_rhino3 = true;
		}
		else if (!fall3_already)
		{
			Matrix pos;
			GetPosition(rhino3,pos);
			RemoveObject(rhino3);
			rhino3 = BuildObject("bcrhinof",2,pos);
			SetAnimation(rhino3,"fall",1);

			//ClearIdleAnims(rhino3);
			//AddIdleAnim(rhino3,"fall");
			rhino3_check = GetTime() + 3.0f;
			StartSoundEffect("rhinocry.wav");
			fall3_already = true;
		}
		else
		{
			RemoveObject(rhino3);
			rhino3_check = GetTime() + 999999.9f;
		}
	}

	if ((rhino4_in) && (rhino4_check < GetTime()))
	{
		if (!animate_rhino4)
		{
			//StartSoundEffect("icecrck1.wav");
			Stop(rhino4);
			//ClearIdleAnims(rhino4);
			//AddIdleAnim(rhino4,"fall");
			rhino4_check = GetTime() + 0.1f;
			animate_rhino4 = true;
		}
		else if (!fall4_already)
		{
			Matrix pos;
			GetPosition(rhino4,pos);
			RemoveObject(rhino4);
			rhino4 = BuildObject("bcrhinof",2,pos);
			SetAnimation(rhino4,"fall",1);

			//ClearIdleAnims(rhino4);
			//AddIdleAnim(rhino4,"fall");
			rhino4_check = GetTime() + 3.0f;
			StartSoundEffect("rhinocry.wav");
			fall4_already = true;
		}
		else
		{
			RemoveObject(rhino4);
			rhino4_check = GetTime() + 999999.9f;
		}
	}
	////////////////////////////////////////////


	// this is removing the ice cap objects when aninmated

	if (anim_wait < GetTime())
	{
		if ((scap1_start) && (IsAround(scap1)))
		{
			RemoveObject(scap1);

			//if ((rhino1_in) && (IsAround(rhino1)))
			//{
			//	RemoveObject(rhino1);
			//}
		}
		if ((scap2_start) && (IsAround(scap2)))
		{
			RemoveObject(scap2);

			//if ((rhino1_in) && (IsAround(rhino1)))
			//{
			//	RemoveObject(rhino1);
			//}
		}

		if ((mcap1_start) && (IsAround(mcap1)))
		{
			RemoveObject(mcap1);
/*
			//if ((recy_fall_in) && (IsAround(recycler)))
			//{
			//	RemoveObject(recycler);
			//}
			if ((rhino2_in) && (IsAround(rhino2)))
			{
				RemoveObject(rhino2);
			}
			if ((rhino3_in) && (IsAround(rhino3)))
			{
				RemoveObject(rhino3);
			}
			if ((rhino4_in) && (IsAround(rhino4)))
			{
				RemoveObject(rhino4);
			}
*/
		}
		if ((mcap2_start) && (IsAround(mcap2)))
		{
			RemoveObject(mcap2);
/*
			//if ((recy_fall_in) && (IsAround(recycler)))
			//{
			//	RemoveObject(recycler);
			//}
			if ((rhino2_in) && (IsAround(rhino2)))
			{
				RemoveObject(rhino2);
			}
			if ((rhino3_in) && (IsAround(rhino3)))
			{
				RemoveObject(rhino3);
			}
			if ((rhino4_in) && (IsAround(rhino4)))
			{
				RemoveObject(rhino4);
			}
*/
		}
		if ((mcap3_start) && (IsAround(mcap3)))
		{
			RemoveObject(mcap3);
/*
			//if ((recy_fall_in) && (IsAround(recycler)))
			//{
			//	RemoveObject(recycler);
			//}
			if ((rhino2_in) && (IsAround(rhino2)))
			{
				RemoveObject(rhino2);
			}
			if ((rhino3_in) && (IsAround(rhino3)))
			{
				RemoveObject(rhino3);
			}
			if ((rhino4_in) && (IsAround(rhino4)))
			{
				RemoveObject(rhino4);
			}
*/
		}
		if ((mcap4_start) && (IsAround(mcap4)))
		{
			RemoveObject(mcap4);
/*
			//if ((recy_fall_in) && (IsAround(recycler)))
			//{
			//	RemoveObject(recycler);
			//}
			if ((rhino2_in) && (IsAround(rhino2)))
			{
				RemoveObject(rhino2);
			}
			if ((rhino3_in) && (IsAround(rhino3)))
			{
				RemoveObject(rhino3);
			}
			if ((rhino4_in) && (IsAround(rhino4)))
			{
				RemoveObject(rhino4);
			}
*/
		}
		if ((mcap5_start) && (IsAround(mcap5)))
		{
			RemoveObject(mcap5);
/*
			//if ((recy_fall_in) && (IsAround(recycler)))
			//{
			//	RemoveObject(recycler);
			//}
			if ((rhino2_in) && (IsAround(rhino2)))
			{
				RemoveObject(rhino2);
			}
			if ((rhino3_in) && (IsAround(rhino3)))
			{
				RemoveObject(rhino3);
			}
			if ((rhino4_in) && (IsAround(rhino4)))
			{
				RemoveObject(rhino4);
			}
*/
		}
		if ((mcap6_start) && (IsAround(mcap6)))
		{
			RemoveObject(mcap6);
/*
			//if ((recy_fall_in) && (IsAround(recycler)))
			//{
			//	RemoveObject(recycler);
			//}
			if ((rhino2_in) && (IsAround(rhino2)))
			{
				RemoveObject(rhino2);
			}
			if ((rhino3_in) && (IsAround(rhino3)))
			{
				RemoveObject(rhino3);
			}
			if ((rhino4_in) && (IsAround(rhino4)))
			{
				RemoveObject(rhino4);
			}
*/
		}

		anim_wait = GetTime() + 99999.9f;
	}
	////////////////////////////////////////////
}

	// this is cancelling the deploy order to the recy

	if (!at_nav)
	{
		if (GetCurrentCommand(recycler) == CMD_DEPLOY)
		{
			Stop(recycler,0);
		}
	}
	////////////////////////////////////////////


if (part_two)
{

	// this is sending the remaining scouts after the recycler
/*
	if ((!suicide_run) && (turret_otf))
	{
		if (IsAlive(scion1))
		{
			Goto(scion1,recycler);
		}
		if (IsAlive(scion2))
		{
			Goto(scion2,recycler);
		}
		if (IsAlive(scion3))
		{
			Goto(scion3,recycler);
		}
		if (IsAlive(scion4))
		{
			Goto(scion4,recycler);
		}

		suicide_run = true;
	}
	////////////////////////////////////////////
*/

	// this is the dropship conversation

	if (!drop_message1)
	{
		talk = AudioMessage("isdf1012a.wav");//(dropship) We got survivors!
		drop_message1 = true;
	}

	if ((drop_message1) && (!drop_message2) && (IsAudioMessageDone(talk)))
	{
		talk = AudioMessage("isdf1013.wav");//(recycler) We need evac!
		drop_message2 = true;
	}

	if ((drop_message2) && (!drop_message3) && (IsAudioMessageDone(talk)))
	{
		talk = AudioMessage("isdf1014.wav");//(dropship) Roger that - we will search for landing location. Shab went down near you - check out
		//land_time = GetTime() + 900.0f;
		shab_check = GetTime() + 2.0f;
		escape_check = GetTime() + 2.0f;
		turret_time = GetTime() + 120.0f;
		CameraReady();
		camera_time = GetTime() + 7.0f;
		SetAnimation(dropship, "fly", 0);
		drop_message3 = true;
	}

	if ((drop_message3) && (!drop_message4) && (IsAudioMessageDone(talk)))
	{
		talk = AudioMessage("isdf1023.wav");//(recycler) Roger that - by time and protect transport
		ClearObjectives();
		AddObjective("search.otf", WHITE);
		AddObjective("transport.otf", WHITE);
		SetObjectiveOn(transport);
		TranslateString2(tempstr, sizeof(tempstr), "Mission1003");  // Transport
		SetObjectiveName(transport,tempstr);
		cheat_tank1 = BuildObject("fvsent10x",2,"cheat_spawn4");
		cheat_tank2 = BuildObject("fvsent10x",2,"cheat_spawn5");
		cheat_tank3 = BuildObject("fvtank10x",2,"cheat_spawn6");
		drop_message4 = true;
	}	
	////////////////////////////////////////////


	// this is the camera code

	if ((!camera_off) && (drop_message3))
	{
		Vector pos;
		pos = GetPosition(dropship);
		pos.x += 2;
		SetVectorPosition(dropship, pos);
		CameraObject(dropship, 40, 60, 30, dropship);
	}


	if ((!camera_off) && (camera_time < GetTime()))
	{
		CameraFinish();
		RemoveObject(dropship);
		camera_off = true;
	}
	////////////////////////////////////////////


	// this is the turret message

	if (!turret_message)
	{
		if (turret_time < GetTime())
		{
			talk = AudioMessage("isdf1026.wav"); // (dropship) clear the turrets
			nav2 = BuildObject("ibnav",1,"nav2_point");
			SetObjectiveOn(nav2);
			TranslateString2(tempstr, sizeof(tempstr), "Mission1004");  // Dust Off
			SetObjectiveName(nav2,tempstr);
			turret_message = true;
		}

		if ((shab_found) && (IsAudioMessageDone(talk)))
		{
			talk = AudioMessage("isdf1026.wav"); // (dropship) clear the turrets
			nav2 = BuildObject("ibnav",1,"nav2_point");
			SetObjectiveOn(nav2);
			TranslateString2(tempstr, sizeof(tempstr), "Mission1004");  // Dust Off
			SetObjectiveName(nav2,tempstr);
			turret_message = true;
		}
	}


	if ((!turret_otf) && (turret_message) && (IsAudioMessageDone(talk)))
	{
		if (shab_found)
		{
			ClearObjectives();
			AddObjective("search.otf", GREEN);
			AddObjective("turret.otf", WHITE);
			AddObjective("transport.otf", WHITE);
		}
		else
		{
			ClearObjectives();
			AddObjective("search.otf", WHITE);
			AddObjective("turret.otf", WHITE);
			AddObjective("transport.otf", WHITE);
		}

		turret_otf = true;
	}
	////////////////////////////////////////////


	// this is because the aips don't work
/*
	if (first_scav)
	{
		if (!build_patrol)
		{
			patroler1 = BuildObject("fvtank",2,"sspawn5");
			//patroler2 = BuildObject("fvtank",2,"sspawn6");
			Patrol(patroler1,"patrol_path3");
			//Follow(patroler2,patroler1);
			build_patrol = true;
		}

		if ((build_patrol) && (!IsAlive(patroler1)) && (!IsAlive(patroler2)))
		{
			build_patrol = false;
		}
	}
	////////////////////////////////////////////
*/

	
	// this is the sending ships down the second patrol path

	if ((!second_patrol1) && (patrol_time < GetTime()))
	{
		patrol_sent1 = BuildObject("fvsent10x",2,"cheat_spawn5");
		patrol_sent2 = BuildObject("fvsent10x",2,"cheat_spawn6");

		Patrol(patrol_sent1,"patrol_path2");
		Follow(patrol_sent2,patrol_sent1);

		second_patrol1 = true;
	}
	////////////////////////////////////////////


	// this is checking to see of the player finds shabs ship

	if ((!shab_found) && (shab_check < GetTime()))
	{
		shab_check = GetTime() + 2.0f;


		if (GetDistance(player,crash_ship2) < 90.0f)
		{
			if (IsAlive(cheat_tank1))
			{
				Attack(cheat_tank1,player);
			}
			if (IsAlive(cheat_tank2))
			{
				Attack(cheat_tank2,transport);
			}
			if (IsAlive(cheat_tank3))
			{
				Attack(cheat_tank3,recycler);
			}

			AudioMessage("isdf1016.wav");//(recycler) that's it - scan it for signs of life
			shab_found = true;
			shab_scanned = true;
		}
	}
	////////////////////////////////////////////
/*
	// if the player scans the ship

	if ((shab_found) && (!shab_scanned) && (IsInfo("becras02") == true))
	{
		message_time = GetTime() + 4.0f;
		shab_scanned = true;
	}


	if ((!shab_scan_message) && (message_time < GetTime()))
	{
		talk = AudioMessage("isdf1016.wav");//(recycler) she's not in there?! She may be alive!
		message_time = GetTime() + 999999.9f;
		shab_scan_message = true;
	}
	////////////////////////////////////////////
*/

	// this is checking to see when the recycler is moving towards the dust-off location

	if (IsAlive(transport))
	{
		if (escape_check < GetTime())
		{
			escape_check = GetTime() + 2.0f;


			if ((!at_choke1) && (GetDistance(transport,"choke_point1") < 60.0f))
			{
				at_choke1 = true;
				at_choke2 = false;
				at_choke3 = false;
			}

			if ((!at_choke2) && (GetDistance(transport,"choke_point2") < 50.0f))
			{
				at_choke1 = false;
				at_choke2 = true;
				at_choke3 = false;
			}

			if ((!at_choke3) && (GetDistance(transport,"choke_point3") < 60.0f))
			{
				at_choke1 = false;
				at_choke2 = false;
				at_choke3 = true;
			}
		}
	}
	////////////////////////////////////////////


	// this is changing aips

	if ((!set_plan1) && (new_plan_time < GetTime()))
	{
		new_plan_time = GetTime() + 999999.9f;
		SetPlan("isdf1002.aip",2);
		set_plan1 = true;
	}
	////////////////////////////////////////////

	
	// this is making the scions attack when the recycler on the way to the drop

	if (in_air)
	{
		if ((at_choke1) || (at_choke2) || (at_choke3))
		{
			if ((sent1_attack_recy) && (sent1_a))
			{
				Attack(sent1,transport);
				sent1_attack_recy = true;
			}

			if ((sent2_attack_recy) && (sent2_a))
			{
				Attack(sent2,transport);
				sent2_attack_recy = true;
			}

			if ((war1_attack_recy) && (war1_a))
			{
				Attack(war1,transport);
				war1_attack_recy = true;
			}

			if ((war2_attack_recy) && (war2_a))
			{
				Attack(war2,transport);
				war2_attack_recy = true;
			}

			if ((maul1_attack_recy) && (maul1_a))
			{
				if (IsAround(recycler))
				{
					Attack(maul1,recycler);
					maul1_attack_recy = true;
				}
				else
				{
					Attack(maul1,transport);
					maul1_attack_recy = true;
				}
			}

			if ((maul2_attack_recy) && (maul2_a))
			{
				if (IsAround(recycler))
				{
					Attack(maul2,recycler);
					maul2_attack_recy = true;
				}
				else
				{
					Attack(maul2,transport);
					maul2_attack_recy = true;
				}
			}
		}
	}
	else if ((!in_air) && (!at_choke3))
	{
		if ((at_choke1) || (at_choke2))
		{
			if ((sent1_attack_recy) && (sent1_a))
			{
				Attack(sent1,transport);
				sent1_attack_recy = true;
			}

			if ((sent2_attack_recy) && (sent2_a))
			{
				Attack(sent2,transport);
				sent2_attack_recy = true;
			}

			if ((war1_attack_recy) && (war1_a))
			{
				Attack(war1,transport);
				war1_attack_recy = true;
			}

			if ((war2_attack_recy) && (war2_a))
			{
				Attack(war2,transport);
				war2_attack_recy = true;
			}

			if ((maul1_attack_recy) && (maul1_a))
			{
				if (IsAround(recycler))
				{
					Attack(maul1,recycler);
					maul1_attack_recy = true;
				}
				else
				{
					Attack(maul1,transport);
					maul1_attack_recy = true;
				}
			}

			if ((maul2_attack_recy) && (maul2_a))
			{
				if (IsAround(recycler))
				{
					Attack(maul2,recycler);
					maul2_attack_recy = true;
				}
				else
				{
					Attack(maul2,transport);
					maul2_attack_recy = true;
				}
			}
		}
	}


	// this is the new turret code

	if (!land_secure)
	{
		if ((!IsAlive(block_turret1)) && (!IsAlive(block_turret2))
			&& (!IsAlive(block_turret3)) && (!IsAlive(block_turret4)))
		{
			AudioMessage("isdf1027.wav"); // (pilot) nice job - we'll be on the ground in 15
			land_time = GetTime() + 15.0f;
			land_secure = true;
		}
	}

// this is the dropship code

	// landing

	if ((in_air) && (land_time < GetTime()))
	{
		if (GetDistance(player,"drop_point1") > 300.0f)
		{
			if (!first_land)
			{
				talk = AudioMessage("isdf1019.wav");//(dropship) your chariots have arrive commander - we're dropping a nav at the dust off site
				first_land = true;
			}
			else
			{
				AudioMessage("isdf1020.wav");//(dropship) We're gonna try another landing now commander
			}

			dropshipa = BuildObject("ivpdrop",1,"drop_point1");
			dropshipb = BuildObject("ivpdrop",1,"drop_point2");
			ClearObjectives();
			AddObjective("dropship.otf", WHITE);

			if (shab_found)
			{
				AddObjective("search.otf", GREEN);
			}
			else if (!shab_found)
			{
				AddObjective("dropship.otf", RED);
			}

			AddObjective("transport.otf", WHITE);

			landing = false;

#if 1
			// Changed NM 8/29/03 -- allow the mission to end if the
			// transport gets to the dustoff zone before the user
			// does. (Otherwise, would just hang) Savegame from Commando
			// demonstrated this
			landed = true;
#endif

			in_air = false;
		}
		else
		{
			// THIS IS WHERE I NEED TO PUT THE LANDING CINERACTIVE - code under this will be deleted
			dropshipa = BuildObject("ivdrop_land",1,"drop_point1");
			dropshipb = BuildObject("ivdrop_land",1,"drop_point2");
			SetAnimation(dropshipa, "land", 1);
			landing_time = GetTime() + 3.0f;

			if (!first_land)
			{
				talk = AudioMessage("isdf1019.wav");//(dropship) your chariots have arrive commander - we're dropping a nav at the dust off site
				first_land = true;
			}
			else
			{
				AudioMessage("isdf1020.wav");//(dropship) We're gonna try another landing now commander
			}
			
			ClearObjectives();
			AddObjective("dropship.otf", WHITE);

			if (shab_found)
			{
				AddObjective("search.otf", GREEN);
			}
			else if (!shab_found)
			{
				AddObjective("dropship.otf", RED);
			}

			AddObjective("transport.otf", WHITE);

			landing = true;
			in_air = false;
		}
	}
	////////////////////////////////////////////


	// this is making the second drop appear cool

	if ((landing) && (!landed))
	{
		if ((!two_land) && (landing_time < GetTime()))
		{
			SetAnimation(dropshipb, "land", 1);
			landing_time = GetTime() + 13.0f;
			two_land = true;
		}

		if ((two_land) && (landing_time < GetTime()))
		{
			RemoveObject(dropshipa);
			RemoveObject(dropshipb);
			dropshipa = BuildObject("ivpdrop",1,"drop_point1");
			dropshipb = BuildObject("ivpdrop",1,"drop_point2");
			SetAnimation(dropshipa, "deploy", 1);
			SetAnimation(dropshipb, "deploy", 1);
			MaskEmitter(dropshipa, 0);
			MaskEmitter(dropshipb, 0);
			landed = true;
		}
	}
	////////////////////////////////////////////
	

	// taking off

	if ((first_land) && (!in_air) && (!game_over))
	{
		if ((GetCurHealth(dropshipa) < 500) || (GetCurHealth(dropshipb) < 500))
		{
			if (GetDistance(player,"drop_point1") > 200.0f)
			{
				AudioMessage("isdf1021.wav");//(dropship) this area's too hot - we have to take off john. Clear the landing zone at nav2 and we'll make another attempt. 
				RemoveObject(dropshipa);
				RemoveObject(dropshipb);
				ClearObjectives();
				AddObjective("dropship.otf", RED);

				if (shab_found)
				{
					AddObjective("search.otf", GREEN);
				}
				else if (!shab_found)
				{
					AddObjective("dropship.otf", RED);
				}

				AddObjective("transport.otf", WHITE);

				land_time = GetTime() + 600.0f;
				landing_time = GetTime() + 999999.9f;
				landing = false;
				landed = false;
				two_land = false;
				take_off = false;
				in_air = true;
			}
			else
			{
				// THIS IS WHERE I NEED TO PUT THE TAKING OFF CINERACTIVE - code under this will be deleted
				AudioMessage("isdf1021.wav");//(dropship) this area's too hot - we have to take off john. Clear the landing zone at nav2 and we'll make another attempt. 
				SetAnimation(dropshipa, "takeoff", 1);
				SetAnimation(dropshipb, "takeoff", 1);
				ClearObjectives();
				AddObjective("dropship.otf", RED);

				if (shab_found)
				{
					AddObjective("search.otf", GREEN);
				}
				else if (!shab_found)
				{
					AddObjective("dropship.otf", RED);
				}

				AddObjective("transport.otf", WHITE);

				land_time = GetTime() + 600.0f;
				landing_time = GetTime() + 10.0f;
				landing = false;
				landed = false;
				two_land = false;
				take_off = true;
				in_air = true;
			}
		}
	}
	////////////////////////////////////////////


	// this is if they take off in engine

	if ((take_off) && (landing_time < GetTime()))
	{
		RemoveObject(dropshipa);
		RemoveObject(dropshipb);
		landing_time = GetTime() + 999999.9f;
		take_off = false;
	}




	if ((!start_end_movie) && (landed) && (win_check < GetTime()))
	{
		win_check = GetTime() + 1.0f;

		if (GetDistance(transport,dropshipa) < 150.0f)
		{
			CameraReady();
			SetPerceivedTeam(player,2);
			SetPerceivedTeam(transport,2);
			Retreat(transport,"into_drop_path");
			start_end_movie = true;
		}

		if (GetDistance(transport,dropshipb) < 150.0f)
		{
			CameraReady();
			SetPerceivedTeam(player,2);
			SetPerceivedTeam(transport,2);
			Retreat(transport,"into_drop_path");
			start_end_movie = true;
		}
	}
	////////////////////////////////////////////

	if ((!game_over) && (start_end_movie))
	{
		CameraPath("shot1_point",2000,0,transport);

		if (GetCurHealth(transport) < 1000)
		{
			SetCurHealth(transport,1000);
		}

		if (GetCurHealth(player) < 500)
		{
			SetCurHealth(player,500);
		}

		if ((!shot2) && (GetDistance(transport,"drop_point1") < 10.0f))
		{
			Stop(transport);
			StartEmitter(dropshipa,1);
			StartEmitter(dropshipa,2);
			SetAnimation(dropshipa,"takeoff", 1);
			carrier_time = GetTime() + 4.0f;
			shot2 = true;
		}
	}

	if ((!remove_transport) && (shot2) && (carrier_time < GetTime()))
	{
		SucceedMission(GetTime() + 0.1f,"isdf10w1.txt");
		remove_transport = true;
	}
	////////////////////////////////////////////


}


	// this is the recycler telling the player to get the transport to the drop site

	if ((!transport_message) && (first_land) && (IsAudioMessageDone(talk)))
	{
		talk = AudioMessage("isdf1022.wav"); //  (recycler) // get my transport to the drop zone
		transport_message = true;
	}


// these are the win/loose conditions
if ((!game_over)/* && (!ON_HOLD)*/)
{
	// if the recycler dies

	if (recy_fall_in)
	{
		if (IsAlive(wingman))
		{
			AudioMessage("isdf1017.wav"); // (wingman) you let the recycler get destroyed!
			FailMission(GetTime() + 15.0f);
			game_over = true;
		}
		else
		{
			FailMission(GetTime() + 15.0f);
			game_over = true;
		}
	}

	if ((free_recycler) && (!IsAlive(recycler)))
	{
		if ((!at_nav) && (IsAlive(wingman)))
		{
			AudioMessage("isdf1017.wav"); // (wingman) you let the recycler get destroyed!
			FailMission(GetTime() + 15.0f);
			game_over = true;
		}
		else if ((!at_nav) && (!IsAlive(wingman)))
		{
			FailMission(GetTime() + 1.0f);
			game_over = true;
		}
		else if (at_nav)
		{
			AudioMessage("isdf1018.wav"); // (dropship pilot) your recycler is dead - no need for pick-up now
			FailMission(GetTime() + 15.0f);
			game_over = true;
		}
	}
	////////////////////////////////////////////

	// this is if the transport gets destroyed

	if (!IsAlive(transport))
	{
		if (IsAlive(recycler))
		{
			AudioMessage("isdf1025.wav"); // (recycler) my transport is dead
			FailMission(GetTime() + 15.0f);
			ClearObjectives();
			AddObjective("transport.otf", RED);
			game_over = true;
		}
		else if (at_nav)
		{
			AudioMessage("isdf1025.wav"); // (dropship pilot) my transport is dead
			FailMission(GetTime() + 15.0f);
			ClearObjectives();
			AddObjective("transport.otf", RED);
			game_over = true;
		}
	}


	// if the player succeeds
/*
	if ((part_two) && (!in_air) && (win_check < GetTime()))
	{
		win_check = GetTime() + 1.0f;

		if (GetDistance(transport,dropshipa) < 100.0f)
		{
			SucceedMission(GetTime() + 15.0f);
			game_over = true;
		}

		if (GetDistance(transport,dropshipb) < 100.0f)
		{
			SucceedMission(GetTime() + 15.0f);
			game_over = true;
		}
	}
	////////////////////////////////////////////
*/
}

/////////////////////////////////////////////////////////////////////
} // ON_HOLD
/////////////////////////////////////////////////////////////////////

if (ON_HOLD)
{
// this is the dropship code

	// landing

	if ((in_air) && (land_time < GetTime()))
	{
		if (GetDistance(player,"drop_point1") > 300.0f)
		{
			if (!first_land)
			{
				talk = AudioMessage("isdf1019.wav");//(dropship) your chariots have arrive commander - we're dropping a nav at the dust off site
				first_land = true;
			}
			else
			{
				AudioMessage("isdf1020.wav");//(dropship) We're gonna try another landing now commander
			}

			dropshipa = BuildObject("ivpdrop",1,"drop_point1");
			dropshipb = BuildObject("ivpdrop",1,"drop_point2");
			ClearObjectives();
			AddObjective("dropship.otf", WHITE);

			if (shab_found)
			{
				AddObjective("search.otf", GREEN);
			}
			else if (!shab_found)
			{
				AddObjective("dropship.otf", RED);
			}

			AddObjective("transport.otf", WHITE);

			landing = false;
			in_air = false;
		}
		else
		{
			// THIS IS WHERE I NEED TO PUT THE LANDING CINERACTIVE - code under this will be deleted
			dropshipa = BuildObject("ivdrop_land",1,"drop_point1");
			dropshipb = BuildObject("ivdrop_land",1,"drop_point2");
			SetAnimation(dropshipa, "land", 1);
			landing_time = GetTime() + 3.0f;

			if (!first_land)
			{
				talk = AudioMessage("isdf1019.wav");//(dropship) your chariots have arrive commander - we're dropping a nav at the dust off site
				first_land = true;
			}
			else
			{
				AudioMessage("isdf1020.wav");//(dropship) We're gonna try another landing now commander
			}
			
			ClearObjectives();
			AddObjective("dropship.otf", WHITE);

			if (shab_found)
			{
				AddObjective("search.otf", GREEN);
			}
			else if (!shab_found)
			{
				AddObjective("dropship.otf", RED);
			}

			AddObjective("transport.otf", WHITE);

			landing = true;
			in_air = false;
		}
	}
	////////////////////////////////////////////


	// this is making the second drop appear cool

	if ((landing) && (!landed))
	{
		if ((!two_land) && (landing_time < GetTime()))
		{
			SetAnimation(dropshipb, "land", 1);
			landing_time = GetTime() + 13.0f;
			two_land = true;
		}

		if ((two_land) && (landing_time < GetTime()))
		{
			RemoveObject(dropshipa);
			RemoveObject(dropshipb);
			dropshipa = BuildObject("ivpdrop",1,"drop_point1");
			dropshipb = BuildObject("ivpdrop",1,"drop_point2");
			SetAnimation(dropshipa, "deploy", 1);
			SetAnimation(dropshipb, "deploy", 1);
			MaskEmitter(dropshipa, 0);
			MaskEmitter(dropshipb, 0);
			landed = true;
		}
	}
	////////////////////////////////////////////
	

	// taking off

	if ((first_land) && (!in_air) && (!game_over))
	{
		if ((GetCurHealth(dropshipa) < 500) || (GetCurHealth(dropshipb) < 500))
		{
			if (GetDistance(player,"drop_point1") > 200.0f)
			{
				AudioMessage("isdf1021.wav");//(dropship) this area's too hot - we have to take off john. Clear the landing zone at nav2 and we'll make another attempt. 
				RemoveObject(dropshipa);
				RemoveObject(dropshipb);
				ClearObjectives();
				AddObjective("dropship.otf", RED);

				if (shab_found)
				{
					AddObjective("search.otf", GREEN);
				}
				else if (!shab_found)
				{
					AddObjective("dropship.otf", RED);
				}

				AddObjective("transport.otf", WHITE);

				land_time = GetTime() + 600.0f;
				landing_time = GetTime() + 999999.9f;
				landing = false;
				landed = false;
				two_land = false;
				take_off = false;
				in_air = true;
			}
			else
			{
				// THIS IS WHERE I NEED TO PUT THE TAKING OFF CINERACTIVE - code under this will be deleted
				AudioMessage("isdf1021.wav");//(dropship) this area's too hot - we have to take off john. Clear the landing zone at nav2 and we'll make another attempt. 
				SetAnimation(dropshipa, "takeoff", 1);
				SetAnimation(dropshipb, "takeoff", 1);
				ClearObjectives();
				AddObjective("dropship.otf", RED);

				if (shab_found)
				{
					AddObjective("search.otf", GREEN);
				}
				else if (!shab_found)
				{
					AddObjective("dropship.otf", RED);
				}

				AddObjective("transport.otf", WHITE);

				land_time = GetTime() + 600.0f;
				landing_time = GetTime() + 10.0f;
				landing = false;
				landed = false;
				two_land = false;
				take_off = true;
				in_air = true;
			}
		}
	}
	////////////////////////////////////////////


	// this is if they take off in engine

	if ((take_off) && (landing_time < GetTime()))
	{
		RemoveObject(dropshipa);
		RemoveObject(dropshipb);
		landing_time = GetTime() + 999999.9f;
		take_off = false;
	}




	if ((!start_end_movie) && (landed) && (win_check < GetTime()))
	{
		win_check = GetTime() + 1.0f;

		if (GetDistance(transport,dropshipa) < 150.0f)
		{
			CameraReady();
			Retreat(transport,"into_drop_path");
			start_end_movie = true;
		}

		if (GetDistance(transport,dropshipb) < 150.0f)
		{
			CameraReady();
			Retreat(transport,"into_drop_path");
			start_end_movie = true;
		}
	}
	////////////////////////////////////////////

	if ((!game_over) && (start_end_movie))
	{
		CameraPath("shot1_point",2000,0,transport);

		if ((!shot2) && (GetDistance(transport,"drop_point1") < 10.0f))
		{
			Stop(transport);
			StartEmitter(dropshipa,1);
			StartEmitter(dropshipa,2);
			SetAnimation(dropshipa,"takeoff", 1);
			carrier_time = GetTime() + 4.0f;
			shot2 = true;
		}
	}

	if ((!remove_transport) && (shot2) && (carrier_time < GetTime()))
	{
		SucceedMission(GetTime() + 0.1f);
		remove_transport = true;
	}
	////////////////////////////////////////////
}

}

