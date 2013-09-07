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
	bool PostLoad(bool missionSave);
	void Execute(void);

	// bools
	bool
		b_first,
		ON_HOLD,
		tug1_move,tug2_move,tug1_board,tug2_board,tugs_board,tug1_in,tugs_in,drop_takeoff,shab_message1,
		shab_at_ship, suspend_death, shab_ship_gone, shab_dead, shab_to_ship, shab_in,
		player_on_foot, player_in_ship, player_in_enemy, game_over, recycler_move, recycle_deploy,
		start_building, scav1_spawn, shab_message2, shab_message3, shab_message4, scav_check1,
		wingman1_spawn, wingman1_set, turret_start, turret1_spawn, turret_set, turret1_at_john,
		wingman2_build, cheat_wingman2, wingman2_set, manson_set, shab_reply1, all_at_center, shab_there,
		player_there, manson_message1, shab_message5, john_on_way, wingman1_forgot, wingman2_forgot,
		shab_message6, manson_message2, convoy_spawn, at_nav1, haulers_underway, hauler1_ready, hauler2_ready,
		ship_sniped, manson_message3, manson_message4, manson_message5, ships_defend, ships_dead, abandoned,
		tug_at_ship, chase_spawn, chase_message, new_orders, start_done, start_end_show, haulers_board,
		jammer_dead, manson_message6, all_scions_dead, haulers_on, tug_drop_takeoff, 

		scav1_a,scav2_a,turret1_a,turret2_a,wingman1_a,wingman2_a,assign_scav1,recycler_response,
		scavdeploy_message,assign_turret1,stop_shab,assign_wingman1,in_combat,turret3_a,turret4_a,
		turret5_a,turret1_scavcheck,tur1_near_scav,turret2_scavcheck,tur2_near_scav,
		turret3_scavcheck,tur3_near_scav,turret4_scavcheck,tur4_near_scav,turret5_scavcheck,tur5_near_scav,
		spawn_1,first_dead,load_plan3,plan3_loaded,shab_away,set_plan1,remove_shab,deployscav_a,
		recy_building,

		manson_move,tell_shab_deploy,shab_ok,recycler_comment,send_shab_away,shab_protest,brad_insist,
		last_wave_dead,gun_picked,get_to_armo,shepards_message,gun_warning,john_at_bunk,john_bunker_warn,
		state_mission,to_escape,convoy_hold,manson_chase,final_retreat,end_escape,
		brad_complain,start_movie,not_there,off_object,remove_manson,major_wave,building_stopped,
		second_dead,third_dead,third_spawn,tag1,tag2,tag3,tag4,tag5,tug_pickup,tug_move,remove_drop1,
		remove_drop2,close_doors,goo,takeoff_recy_drop,recy_wait,remove_recy_drop,new_look1,new_look2,
		shab_go_away,turret_test,fodder_attack,major_attack,major1_attack,major2_attack,set_for_main,
		one_there,two_there,three_there,four_there,five_there,power_up_message,sniped_destroyed,
		cliff_fall,emit_on,scrap_cheat,
		b_last;

	// floats
	float
		f_first,
		tug_check, message_time, shab_ship_check, recycler_move_time, building_time, scav_check,
		turret_check, manson_message_time, center_check, john_check, enemy_spawn_time, 
		john_out_check, abandon_check, failed_time, start_show_time, jammer_repeat_time, 
		hauler_check, movie_start_time,fire_check,wave1_check,wave1_warning,scav1_check,wait_time,
		away_check,
		power_up_check,john_dilly,convoy_check,convoy_wait_time,end_game_time,
		manson_check1,manson_check2,next_wave,pause,fodder_time,show_time,
		f_last;

	// handles
	Handle
		h_first,
		player_ship, player, shabayev, shab, recycler,
		scav1, scav2,pool,scion_drop,
		tug, tug1, tug2,
		scion1, scion2, scion3, scion4, scion5, scion6,
		hauler1, hauler2, hauler3,
		power1, power2, tech_power,
		armory, tech_center, tech_hanger,
		startbase_cbunk, endbase_cbunk, field_cbunk,
		building_tall, building_short,
		tug_drop, scion_tug_drop, recy_drop,
		turret1, turret2, wingman1, wingman2, 
		turret3,turret4,turret5,
		talk,
		geyser,
		ex_tank1, ex_tank2,
		nav1,nav2,
		leader1, leader2,
		sniped_ship,
		chase_scout1, chase_scout2,
		escion1, escion2, escion3, escion4, escion5, 
		escout1, escout2, escout3, escout4, escout5,
		ehauler1, ehauler2, jammer,deploy_scav,
		manson,wing1,wing2,
		power_up,bunker_nav,
		dead_scav1,dead_scav2,empty_scout1,empty_scout2,
		friend1,friend2,friend3,friend4,friend5,friend6,
		relic1,relic2,holder,
		fodder1,fodder2,
		crumble_cliff,dust1,dust2,pilot,
		snipe_scion1,snipe_scion2,
		snipe_scion3,snipe_scion4,
		snipe_scion5,
		stode_sent,
		h_last;

	// integers
	int
		i_first,
		x,
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
	emit_on = false;
	goo = false;
	tug1_move = false;
	tug2_move = false;
	tug1_board = false;
	tug2_board = false;
	tugs_board = false;
	tug1_in = false;
	tugs_in = false;
	drop_takeoff = false;
	shab_message1 = false;
	shab_ship_check = false;
	shab_to_ship = false;
	shab_at_ship = false;
	suspend_death = false;
	shab_at_ship = false;
	shab_ship_gone = false;
	shab_dead = false;
	shab_in = false;
	player_on_foot = true;
	player_in_ship = false;
	player_in_enemy = false;
	game_over = false;
	recycler_move = false;
	recycle_deploy = false;
	start_building = false;
	scav1_spawn = false;
	shab_message2 = false;
	shab_message3 = false;
	shab_message4 = false;
	scav_check1 = false;
	wingman1_spawn = false;
	wingman1_spawn = false;
	wingman1_set = false;
	turret_start = false;
	turret1_spawn = false;
	turret_set = false;
	turret1_at_john = false;
	wingman2_build = false;
	cheat_wingman2 = false;
	wingman2_set = false;
	manson_set = false;
	shab_reply1 = false;
	all_at_center = false;
	shab_there = false;
	player_there = false;
	manson_message1 = false;
	shab_message5 = false;
	john_on_way = false;
	wingman1_forgot = false;
	wingman2_forgot = false;
	shab_message6 = false;
	manson_message2 = false;
	convoy_spawn = false;
	at_nav1 = false;
	haulers_underway = false;
	hauler1_ready = false;
	hauler2_ready = false;
	ship_sniped = false;
	manson_message3 = false;
	manson_message4 = false;
	manson_message5 = false;
	ships_defend = false;
	ships_dead = false;
	abandoned = false;
	tug_at_ship = false;
	chase_spawn = false;
	chase_message = false;
	new_orders = false;
	start_done = false;
	start_end_show = false;
	haulers_board = false;
	jammer_dead = false;
	manson_message6 = false;
	all_scions_dead = false;
	haulers_on = false;
	tug_drop_takeoff = false;
	scav1_a = false;
	scav2_a = false;
	turret1_a = false;
	turret2_a = false;
	wingman1_a = false;
	wingman2_a = false;
	assign_scav1 = false;
	recycler_response = false;
	scavdeploy_message = false;
	assign_turret1 = false;
	stop_shab = false;
	assign_wingman1 = false;
	in_combat = false;
	turret3_a = false;
	turret4_a = false;
	turret5_a = false;
	spawn_1 = false;
	first_dead = false;
	wave1_warning = false;
	turret1_scavcheck = false; tur1_near_scav = false;
	turret2_scavcheck = false; tur2_near_scav = false;
	turret3_scavcheck = false; tur3_near_scav = false;
	turret4_scavcheck = false; tur4_near_scav = false;
	turret5_scavcheck = false; tur5_near_scav = false;
	load_plan3 = false;
	plan3_loaded = false;
	shab_away = false;
	set_plan1 = false;
	remove_shab = false;
	deployscav_a = false;
	recy_building = false;
	manson_move = false;
	tell_shab_deploy = false;
	shab_ok = false;
	recycler_comment = false;
	send_shab_away = false;
	shab_protest = false;
	brad_insist = false;
	last_wave_dead = false;
	gun_picked = false;
	get_to_armo = false;
	shepards_message = false;
	gun_warning = false;
	john_at_bunk = false;
	john_bunker_warn = false;
	state_mission = false;
	to_escape = false;
	convoy_hold = false;
	final_retreat = false;
	manson_chase = false;
	end_escape = false;
	brad_complain = false;
	start_movie = false;
	not_there = false;
	remove_manson = false;
	off_object = false;
	major_wave = false;
	building_stopped = true;
	second_dead = false;
	third_spawn = false;
	third_dead = false;
	tag1 = false; tag2 = false; tag3 = false; tag4 = false; tag5 = false;
	tug_pickup = false;
	tug_move = false;
	remove_drop1 = false;
	remove_drop2 = false;
	close_doors = false;
	takeoff_recy_drop = false;
	recy_wait = false;
	remove_recy_drop = false;
	new_look1 = false; new_look2 = false;
	shab_go_away = false;
	turret_test = false;
	fodder_attack = false;
	major_attack = false; major1_attack = false; major2_attack = false;
	set_for_main = false;
	one_there = false;two_there = false;three_there = false;
	four_there = false;five_there = false;
	power_up_message = false;
	sniped_destroyed = false;
	cliff_fall = false;
	scrap_cheat = false;

//  floats
	tug_check = 999999.9f;
	shab_ship_check = 999999.9f;
	message_time = 999999.9f;
	recycler_move_time = 999999.9f;
	building_time = 999999.9f;
	scav_check = 999999.9f;
	turret_check = 999999.9f;
	manson_message_time = 999999.9f;
	center_check = 999999.9f;
	john_check = 999999.9f;
	enemy_spawn_time = 999999.9f;
	john_out_check = 999999.9f;
	abandon_check = 999999.9f;
	failed_time = 999999.9f;
	start_show_time = 999999.9f;
	jammer_repeat_time = 999999.9f;
	hauler_check = 999999.9f;
	movie_start_time = 999999.9f;
	wave1_check = 999999.9f;
	scav1_check = 999999.9f;
	fire_check = 1.0f;
	wait_time = 999999.9f;
	away_check = 999999.9f;
	power_up_check = 999999.9f;
	john_dilly = 999999.9f;
	convoy_check = 999999.9f;
	convoy_wait_time = 999999.9f;
	end_game_time = 999999.9f;
	manson_check1 = 999999.9f;
	manson_check2 = 999999.9f;
	next_wave = 999999.9f;
	pause = 999999.9f;
	fodder_time = 999999.9f;
	show_time = 999999.9f;

//  handles
	player = GetPlayerHandle();
	recycler = GetHandle("recycler");
	player_ship = GetHandle("player_ship");
	//shab = GetHandle("shab");
	shabayev = GetHandle("shabayev");
	power1 = GetHandle("power1");
	//power2 = GetHandle("power2");
	//tech_power = GetHandle("tech_power");
	//tech_hanger = GetHandle("tech_hanger");
	armory = GetHandle("armory");
	tech_center = GetHandle("tech_center");
	endbase_cbunk = GetHandle("endbase_cbunk");
	field_cbunk = GetHandle("field_cbunk");
	tug1 = GetHandle("tug1");
	tug2 = GetHandle("tug2");
	tug_drop = GetHandle("tug_drop");
	recy_drop = GetHandle("recy_drop");
	pool = GetHandle("pool");
	manson = GetHandle("manson");
	wing1 = GetHandle("wing1");
	wing2 = GetHandle("wing2");
	dead_scav1 = GetHandle("dead_scav1");
	dead_scav2 = GetHandle("dead_scav2");
	empty_scout1 = GetHandle("empty_scout1");
	empty_scout2 = GetHandle("empty_scout2");
	scion_drop = GetHandle("scion_drop");
	relic1 = GetHandle("relic1");
	relic2 = GetHandle("relic2");

#if 1
	// Hack to avoid bug if you space-thru voiceover at start of mission
	// [KEEP THIS!]  - NM 10/12/02
	int MansonTeam=GetTeamNum(manson);
	SetTeamNum(tug1,MansonTeam);
	SetTeamNum(tug2,MansonTeam);
	SetTeamNum(relic1,MansonTeam);
	SetTeamNum(relic2,MansonTeam);
#endif

	//holder = GetHandle("holder");
	crumble_cliff = GetHandle("crumble_cliff");
	stode_sent = GetHandle("stode_sent");
	scav1 = NULL;
	deploy_scav = NULL;
	scav2 = NULL;
	shab = NULL;
	tug = NULL;
	scion1 = NULL;
	scion2 = NULL;
	scion3 = NULL;
	scion4 = NULL;
	scion5 = NULL;
	scion6 = NULL;
	hauler1 = NULL;
	hauler2 = NULL;
	hauler3 = NULL;
	turret1 = NULL;
	turret2 = NULL;
	turret3 = NULL;
	turret4 = NULL;
	turret5 = NULL;
	wingman1 = NULL;
	wingman2 = NULL;
	geyser = NULL;
	ex_tank1 = NULL;
	ex_tank2 = NULL;
	nav1 = GetHandle("nav1");
	nav2 = NULL;
	leader1 = NULL;
	leader2 = NULL;
	sniped_ship = NULL;
	chase_scout1 = NULL;
	chase_scout2 = NULL;
	escion1 = NULL;
	escion2 = NULL;
	escion3 = NULL;
	escion4 = NULL;
	escion5 = NULL;
	escout1 = NULL;
	escout2 = NULL;
	escout3 = NULL;
	escout4 = NULL;
	escout5 = NULL;
	scion_tug_drop = NULL;
	ehauler1 = NULL;
	ehauler2 = NULL;
	jammer = NULL;
	power_up = NULL;
	bunker_nav = NULL;
	friend1 = NULL; friend2 = NULL; friend3 = NULL;
	friend4 = NULL; friend5 = NULL; friend6 = NULL;
	fodder1 = NULL; fodder2 = NULL;
	dust1 = NULL;
	dust2 = NULL;
	pilot = NULL;


	talk = 0;

	PreloadODF("ivscav");
	PreloadODF("ibscav");
	PreloadODF("ibrecy");


//  integers
	x = 0;

	SetTeamColor(3,0,127,255);  //Blue
	SetTeamColor(4,127,255,127);  //Green

	Ally(1,3);
	Ally(3,1);
	Ally(1,4);
	Ally(4,1);
	Ally(3,4);
	Ally(4,3);

}

void Misn04Mission::AddObject(Handle h)
{
	char ODFName[64];
	GetObjInfo(h, Get_CFG, ODFName);

if (start_done)
{
	if ((!recy_building) && (IsOdf2(h,"ibrecy4")))
	{
		recycler = h;
		//SetTeamNum(recycler,0);
		recy_building = true;
	}
	else if ((!scav1_a) && (IsOdf2(h,"ivscav")))
	{
		scav1 = h;
		//SetTeamNum(scav1,1);
		scav1_a = true;
	}
	else if ((!scav2_a) && (IsOdf2(h,"ivscav")))
	{
		scav2 = h;
		//SetTeamNum(scav2,1);
		scav2_a = true;
	}
	else if ((!deployscav_a) && (IsOdf2(h,"ibscav")))
	{
		scav1 = h;
		//SetTeamNum(scav1,0);
		deployscav_a = true;
	}
	else if ((turret1 == NULL) && (IsOdf2(h,"ivturr")))
	{
		turret1 = h;
		pause = GetTime() + 2.0f;
		//SetTeamNum(turret1,1);
		turret1_a = true;
	}
	else if ((turret2 == NULL) && (IsOdf2(h,"ivturr")))
	{
		turret2 = h;
		//SetTeamNum(turret2,1);
		turret2_a = true;
	}
	else if ((turret3 == NULL) && (IsOdf2(h,"ivturr")))
	{
		turret3 = h;
		//SetTeamNum(turret3,1);
		turret3_a = true;
	}
	else if ((turret4 == NULL) && (IsOdf2(h,"ivturr")))
	{
		turret4 = h;
		//SetTeamNum(turret4,1);
		turret4_a = true;
	}
	else if ((turret5 == NULL) && (IsOdf2(h,"ivturr")))
	{
		turret5 = h;
		//SetTeamNum(turret5,1);
		turret5_a = true;
	}
	else if ((wingman1 == NULL) && (IsOdf2(h,"ivscout")))
	{
		wingman1 = h;
		wingman1_a = true;
	}
	else if ((wingman2 == NULL) && (IsOdf2(h,"ivscout")))
	{
		wingman2 = h;
		wingman2_a = true;
	}
	else if (IsOdf2(h,"fspilo"))
	{
		pilot = h;
		Damage(pilot,100);
		//RemoveObject(pilot);
	}
}
}

bool Misn04Mission::PostLoad(bool missionSave)
{
	bool ret = SPMission::PostLoad(missionSave);

	if (missionSave)
		return ret;

	SetTeamColor(3,0,127,255);  //Manson
	SetTeamColor(4,127,255,127);  //Green


	return ret;
}

void Misn04Mission::Execute(void)
{
/*
	Here is where you put what happens every frame.  
*/

	player = GetPlayerHandle();
	char tempstr[128];

	// this will hopefully prevent the player from building a turret

	if ((turret_set) && (!load_plan3))
	{
		if (GetScrap(1) > 38)
		{
			SetScrap(1,39);
		}
	}




////////////////////////////////////////////////////////////////////////
if ((IsAlive(recycler)) && (!recycler_move))
{
	Stop(recycler);
}

//if (remove_drop1)
//{
//	manson_move = true;
//}

if (!ON_HOLD)
{
////////////////////////////////////////////////////////////////////////


	// keep the relics and tugs alive

	if ((IsAround(tug1)) && (GetCurHealth(tug1) < 2500))
	{
		SetCurHealth(tug1,2500);
	}
	if ((IsAround(tug2)) && (GetCurHealth(tug2) < 2500))
	{
		SetCurHealth(tug2,2500);
	}
	if ((IsAround(relic1)) && (GetCurHealth(relic1) < 2000))
	{
		SetCurHealth(relic1,2000);
	}
	if ((IsAround(relic2)) && (GetCurHealth(relic2) < 2000))
	{
		SetCurHealth(relic2,2000);
	}
	////////////////////////////////////////////


	// This is checking to see if the recycyer is deployed or not

	if (recy_building)
	{
		if (IsAround(recycler))
		{
			if (IsOdf(recycler,"ivrecy4"))
			{
				recy_building = false;
			}
			else
			{
				recy_building = true;
			}
		}
	}
	////////////////////////////////////////////

	
	// this is checking to make sure the player does not attack his wingman

	if (!in_combat)
	{
		if (fire_check < GetTime())
		{
			if ((IsAlive(shabayev)) && (IsAlive(player)))
			{
				if (GetTime() - GetLastFriendShot(shabayev) < .2f)
				{
					AudioMessage("ff01.wav"); // (shab) watch your firing!
					fire_check = GetTime() + 2.0f;
				}
			}
		}
	}
	////////////////////////////////////////////

	
	// this is setting the death variables

	if (scav1_a)
	{
		if (!assign_scav1)
		{
			Stop(scav1,0);
			//Goto(scav1,"scav_path",0);
			pause = GetTime() + 3.0f;
			assign_scav1 = true;
		}


		if ((!IsAlive(scav1)) && (!deployscav_a))
		{
			scav1_a = false;
			assign_scav1 = false;
		}
	}
	////////////////////////////////////////////


	// these are checkng to see that the turrets are near the scavnerger

	if (turret1_a)
	{
		if (deployscav_a)
		{
			if ((!turret1_scavcheck) && (IsDeployed(turret1)))
			{
				if (GetDistance(turret1,scav1) < 100.0f)
				{
					tur1_near_scav = true;
				}
				else
				{
					tur1_near_scav = false;
				}

				turret1_scavcheck = true;
			}

			if ((turret1_scavcheck) && (!IsDeployed(turret1)))
			{
				tur1_near_scav = false;
				turret1_scavcheck = false;
			}
		}


		if (!IsAlive(turret1))
		{
			tur1_near_scav = false;
			turret1_scavcheck = false;
			turret1_a = false;
		}
	}


	if (turret2_a)
	{
		if (deployscav_a)
		{
			if ((!turret2_scavcheck) && (IsDeployed(turret2)))
			{
				if (GetDistance(turret2,scav1) < 100.0f)
				{
					tur2_near_scav = true;
				}
				else
				{
					tur2_near_scav = false;
				}

				turret2_scavcheck = true;
			}

			if ((turret2_scavcheck) && (!IsDeployed(turret2)))
			{
				tur2_near_scav = false;
				turret2_scavcheck = false;
			}
		}


		if (!IsAlive(turret2))
		{
			tur2_near_scav = false;
			turret2_scavcheck = false;
			turret2_a = false;
		}
	}


	if (turret3_a)
	{
		if (deployscav_a)
		{
			if ((!turret3_scavcheck) && (IsDeployed(turret3)))
			{
				if (GetDistance(turret3,scav1) < 100.0f)
				{
					tur3_near_scav = true;
				}
				else
				{
					tur3_near_scav = false;
				}

				turret3_scavcheck = true;
			}

			if ((turret3_scavcheck) && (!IsDeployed(turret3)))
			{
				tur3_near_scav = false;
				turret3_scavcheck = false;
			}
		}


		if (!IsAlive(turret3))
		{
			tur3_near_scav = false;
			turret3_scavcheck = false;
			turret3_a = false;
		}
	}


	if (turret4_a)
	{
		if (deployscav_a)
		{
			if ((!turret4_scavcheck) && (IsDeployed(turret4)))
			{
				if (GetDistance(turret1,scav1) < 100.0f)
				{
					tur4_near_scav = true;
				}
				else
				{
					tur4_near_scav = false;
				}

				turret4_scavcheck = true;
			}

			if ((turret4_scavcheck) && (!IsDeployed(turret4)))
			{
				tur4_near_scav = false;
				turret4_scavcheck = false;
			}
		}


		if (!IsAlive(turret4))
		{
			tur4_near_scav = false;
			turret4_scavcheck = false;
			turret4_a = false;
		}
	}


	if (turret5_a)
	{
		if (deployscav_a)
		{
			if ((!turret5_scavcheck) && (IsDeployed(turret5)))
			{
				if (GetDistance(turret5,scav1) < 100.0f)
				{
					tur5_near_scav = true;
				}
				else
				{
					tur5_near_scav = false;
				}

				turret5_scavcheck = true;
			}

			if ((turret5_scavcheck) && (!IsDeployed(turret5)))
			{
				tur5_near_scav = false;
				turret5_scavcheck = false;
			}
		}


		if (!IsAlive(turret5))
		{
			tur5_near_scav = false;
			turret5_scavcheck = false;
			turret5_a = false;
		}
	}
	////////////////////////////////////////////

	
	if (wingman1_a)
	{
		if (!assign_wingman1)
		{
			Follow(wingman1,shabayev);
			assign_wingman1 = true;
		}


		if (!IsAlive(wingman1))
		{
			wingman1_a = false;
			assign_wingman1 = false;
		}
	}
	////////////////////////////////////////////


	// I'm checking to see if the player looses his ship
	char ODFName[64];
	GetObjInfo(player, Get_CFG, ODFName);

	if ((IsOdf2(player,"ivplysct")) || (IsOdf2(player,"ivtank")) || (IsOdf2(player,"ivscav")) || (IsOdf2(player,"ivturr")))
	{
		player_on_foot = false;
		player_in_ship = true;
		player_in_enemy = false;
	}
	else if ((IsOdf2(player,"fvpsnt4")) || (IsOdf2(player,"fvpscou")) || (IsOdf2(player,"fvscout")))
	{
		player_on_foot = false;
		player_in_ship = false;
		player_in_enemy = true;
	}
	else
	{
		player_on_foot = true;
		player_in_ship = false;
		player_in_enemy = false;
	}
	////////////////////////////////////////////


	// this is if the player gets into a sniped alien ship

	if (player_in_enemy)
	{
		Damage(player,2);
	}
	////////////////////////////////////////////


// this is sending the two tugs to the drop


	
	// first they have to pick up the relics

	if (!tug_pickup)
	{
		SetAvoidType(tug1,0);
		SetAvoidType(tug2,0);
		Pickup(tug1,relic1);
		Pickup(tug2,relic2);
		tug_pickup = true;
	}
	////////////////////////////////////////////

	
	// once they have the relics they go for the drop

	if (!tug1_move)
	{
		if (HasCargo(tug1)) 
		{
			Goto(tug1,"tug_path1");
			tug1_move = true;
		}
	}

	if (!tug2_move)
	{
		if (HasCargo(tug2)) 
		{
			Goto(tug2,"tug_path2");
			tug2_move = true;
		}
	}
	////////////////////////////////////////////

	
	// this is when each is inside

	if (!remove_drop1)
	{
		if ((!tug1_board) && (tug1_move) && (GetDistance(tug1,"load_point1") < 20.0f))
		{
			Stop(tug1);
			tug1_board = true;
		}

		if (tug1_board)
		{
			Stop(tug1);
		}

		if ((!tug2_board) && (tug2_move) && (GetDistance(tug2,"load_point2") < 22.0f))
		{
			Stop(tug2);
			tug2_board = true;
		}

		if (tug2_board)
		{
			Stop(tug2);
		}

		if ((!tugs_in) && (tug1_board) && (tug2_board))
		{
			recycler_move_time = GetTime() + 1.0f;
			tugs_in = true;
		}

		// this will warn the player if he is too close

		if ((tugs_in) && (!close_doors) && (recycler_move_time < GetTime()))
		{
			if (GetDistance(player,tug1) < 40.0f)
			{
				recycler_move_time = GetTime() + 10.0f;
				AudioMessage("isdf0444.wav"); // (pilot) please move away from the vehcile sir
			}
			else
			{
				SetAnimation(tug_drop,"takeoff",1);
				//StartSoundEffect("dropdoor.wav",tug_drop);
				StartSoundEffect("dropleav.wav",tug_drop);
				recycler_move_time = GetTime() + 3.0f;
				close_doors = true;
			}
		}

		if ((close_doors) && (!drop_takeoff) && (recycler_move_time < GetTime()))
		{
			StartSoundEffect("dropdoor.wav",tug_drop);
			StartEmitter(tug_drop, 1);
			StartEmitter(tug_drop, 2);
			//dust1 = BuildObject("kickup",0,"smoke1_a");
			//dust2 = BuildObject("kickup",0,"smoke1_b");
			RemoveObject(tug1);
			RemoveObject(tug2);
			RemoveObject(relic1);
			RemoveObject(relic2);
			recycler_move_time = GetTime() + 10.0f;
			drop_takeoff = true;
		}


		if ((drop_takeoff) && (!remove_drop1) && (recycler_move_time < GetTime()))
		{
			RemoveObject(tug_drop);
			//RemoveObject(dust1);
			//RemoveObject(dust2);
			remove_drop1 = true;
		}
	}
	////////////////////////////////////////////

	
	if (!start_done)
	{
		SetColorFade(1,0.5f,RGBA_MAKE(0, 0, 0, 255));

		MaskEmitter(tug_drop, 0);
		MaskEmitter(recy_drop, 0);
		holder = BuildObject("stayput",0,recycler);
		AddScrap(1,35);
		SetAvoidType(shabayev,0);
		SetAnimation(tug_drop,"deploy",1);
		SetGroup(recycler,-1);
		SetGroup(shabayev,-1);
		SetObjectiveOn(shabayev);
		SetObjectiveName(shabayev,"Cmd. Shabayev");
		SetObjectiveOn(manson);
		SetObjectiveName(manson,"Maj. Manson");
		SetObjectiveName(wing1,"Sgt. Zdarko");
		SetObjectiveName(wing2,"Sgt. Masiker");
		message_time = GetTime() + 5.0f;

		LookAt(shabayev,manson);
		LookAt(manson,shabayev);
		LookAt(wing1,manson);
		LookAt(wing2,manson);

		SetPerceivedTeam(scion_drop,1);

		Ally(0,1);
		Ally(1,0);

		//LookAt(stode_sent,field_cbunk,1);
		RemoveObject(stode_sent);

		start_done = true;
	}
	////////////////////////////////////////////


// this is shab telling john how to order a friendly to pick him up


	// this is braddock telling Manson to move out

	if ((!shab_message1) && (message_time < GetTime()))
	{
		talk = AudioMessage("isdf0401.wav");//(brad) move out manson
		LookAt(shab,player);
		shab_message1 = true;
	}
	////////////////////////////////////////////


	// this is Manson moving out

	if ((shab_message1) && (!manson_move) && (IsAudioMessageDone(talk)))
	{
		talk = AudioMessage("isdf0439.wav");//(manson) roger that, follow me one and two
		SetAvoidType(manson,0);
		SetAvoidType(wing1,0);
		SetAvoidType(wing2,0);
		Goto(manson,"man_out_path");
		Follow(wing1,manson);
		Follow(wing2,wing1);
		manson_check1 = GetTime() + 1.0f;
		manson_move = true;	
	}
	////////////////////////////////////////////


	// this is getting rid of manson

	if ((manson_move) && (!remove_manson))
	{
		if (manson_check1 < GetTime())
		{
			manson_check1 = GetTime() + 1.0f;

			if ((!off_object) && (GetDistance(manson,player) > 150.0f))
			{
				if (IsAround(manson))
				{
					SetObjectiveOff(manson);
					off_object = true;
				}
			}

			if (GetDistance(manson,player) > 500.0f)
			{
				if (IsAround(manson))
				{
					RemoveObject(manson);
				}
				if (IsAround(wing1))
				{
					RemoveObject(wing1);
				}
				if (IsAround(wing2))
				{
					RemoveObject(wing2);
				}

				remove_manson = true;
			}
		}
	}
	////////////////////////////////////////////


	// this is braddock telling shab to deploy recycler

	if ((manson_move) && (!tell_shab_deploy) && (IsAudioMessageDone(talk)))
	{
		talk = AudioMessage("isdf0420.wav");//(brad) shab - deploy that recy
		tell_shab_deploy = true;
	}
	////////////////////////////////////////////


	if ((tell_shab_deploy) && (!shab_ok) && (IsAudioMessageDone(talk)))
	{
		LookAt(shabayev,recycler);
		talk = AudioMessage("isdf0440a.wav");//(shab) roger! Recycler1 clear the drop ship
		SetAnimation(recy_drop,"deploy",1);
		//StartSoundEffect("dropdoor.wav",recy_drop);
		shab_ok = true;
	}
	////////////////////////////////////////////


	// this is making shab deploy the recycler

	if ((shab_ok) && (!recycler_move) && (IsAudioMessageDone(talk)))
	{
		StartSoundEffect("dropdoor.wav",recy_drop);
		LookAt(shabayev,player);
		RemoveObject(holder);
		SetAvoidType(recycler,0);
		Goto(recycler,"recycler_path");
		talk = AudioMessage("isdf0402.wav");//(shab) I'm calling the recycler over here
		recycler_move_time = GetTime() + 2.0f;
		recycler_move = true;
	}
	////////////////////////////////////////////


	// shab commenting on the recycler

	if ((recycler_move) && (!recycler_comment) && (IsAudioMessageDone(talk)))
	{
		talk = AudioMessage("isdf0421.wav");//(shab) Your recycler is your pivotal building machine
		recycler_comment = true;
	}
	////////////////////////////////////////////


	// this is new code that will allow me to remove the dropship

	if (recycler_move)
	{
		if ((!takeoff_recy_drop) && (GetDistance(recycler,"deploy_point") < 20.0f)) //(GetCurrentCommand(recycler) == CMD_NONE))
		{
			Dropoff(recycler,"new_drop2");
			//Stop(recycler);
			recy_wait = true;

			if (recycler_move_time < GetTime())
			{
				if (GetDistance(player,"recy_drop_point") < 20.0f)
				{
					recycler_move_time = GetTime() + 10.0f;
					AudioMessage("isdf0444.wav"); // (pilot) please move away from the vehcile sir
				}
				else
				{
					SetAnimation(recy_drop,"takeoff",1);
					//StartSoundEffect("dropdoor.wav",recy_drop);
					StartSoundEffect("dropleav.wav",recy_drop);
					recycler_move_time = GetTime() + 3.0f;
					takeoff_recy_drop = true;
				}
			}
		}
	}
	////////////////////////////////////////////


	// this removes the last dropship

	if ((takeoff_recy_drop) && (!remove_recy_drop) && (recycler_move_time < GetTime()))
	{
		if (!emit_on)
		{
			StartSoundEffect("dropdoor.wav",recy_drop);
			StartEmitter(recy_drop, 1);
			StartEmitter(recy_drop, 2);
			recycler_move_time = GetTime() + 8.0f;
			emit_on = true;
		}
		else
		{
			RemoveObject(recy_drop);
			remove_recy_drop = true;
		}
	}
	////////////////////////////////////////////


	// this tells the recy to deploy

	if ((recy_wait) && (recycler_comment) && (!recycle_deploy) && (IsAudioMessageDone(talk)))
	{
		//Goto(shabayev,"deploy_point");
		LookAt(shabayev,recycler);
		talk = AudioMessage("isdf0403.wav");//(shab) that's good enough Recy 1 deploy there
		//Dropoff(recycler,"new_drop2");
		recycle_deploy = true;
	}
	////////////////////////////////////////////


	// this is the recycler responding

	if ((recycle_deploy) && (!recycler_response) && (IsAudioMessageDone(talk)))
	{
		Goto(shabayev,"start_build_point");
		AudioMessage("isdf0404.wav");//(recycler) Roger that Commander.
		recycler_response = true;
	}
	////////////////////////////////////////////


	// this is after the recy is deployed

	if ((!stop_shab) && (recycler_response) && (GetDistance(shabayev,"start_build_point") < 5.0f))
	{
		LookAt(shabayev,recycler);
		stop_shab = true;
	}
	////////////////////////////////////////////
	
	
	// once the recycler is deployed she builds scav1

	if ((recycle_deploy) && (recy_building) && (!start_building))
	{
		LookAt(shabayev,player);
		AudioMessage("isdf0405.wav");//(shab) the first thing you usually build is scav
		//AddScrap(1,40);
		wait_time = GetTime() + 5.0f;
		start_building = true;
	}
	////////////////////////////////////////////
	

	// this sets the aip that builds the scavenger
	
	if ((!set_plan1) && (wait_time < GetTime()))
	{
		LookAt(shabayev,recycler);
		SetPlan("isdf0401.aip",1);
		wait_time = GetTime() + 999999.0f;
		set_plan1 = true;
	}
	////////////////////////////////////////////


	// this is checking to see if the player stops the scav from being built

	if (start_building)
	{
		if (GetScrap(1) < 21)
		{
			building_stopped = false;
		}

		if ((!scav1_a) && (!building_stopped) && (GetScrap(1) > 21))
		{
			AudioMessage("isdf0443.wav");//(shab) don't stop the building John
			wait_time = GetTime() + 5.0f;
			set_plan1 = false;
			building_stopped = true;
		}
	}
	////////////////////////////////////////////


	// shab is giving the scav to John and telling him to set it up

	if ((scav1_a) && (!shab_message2) && (pause < GetTime()))
	{
			Matrix pos;
			GetPosition(recycler,pos);
			RemoveObject(recycler);
			recycler = BuildObject("ibrecy4a",1,pos);

		//Goto(scav1,"scav_point",0);
		AddScrap(1,15);
		Goto(scav1,"recy_drop_point",0);
		LookAt(shabayev,player);
		ClearObjectives();
		AddObjective("isdf0401.otf", WHITE);
		talk = AudioMessage("isdf0406.wav");//(shab) I'm giving you the scav - take it to the nav beacon
		SetObjectiveOn(nav1);
		TranslateString2(tempstr, sizeof(tempstr), "Mission0401");  // Scrap Pool
		SetObjectiveName(nav1,tempstr);
		scav_check = GetTime() + 2.0f;
		pause = GetTime() + 3.0f;
		SetPlan("isdf0402.aip",1); // builds turrets
		shab_message2 = true;
	}
	////////////////////////////////////////////


	// this is making shab look at the nav beacon

	if ((shab_message2) && (!new_look1) && (pause < GetTime()))
	{
		LookAt(shabayev,pool);
		new_look1 = true;
	}
	////////////////////////////////////////////


	if ((new_look1) && (!new_look2) && (IsAudioMessageDone(talk)))
	{
		LookAt(shabayev,player);
		new_look2 = true;
	}


	// this is checking to see when the scav is near the pool

	if ((shab_message2) && (!shab_message3) && (scav_check < GetTime()))
	{
		scav_check = GetTime() + 2.0f;


		if ((GetDistance(player,pool) < 60.0f) || (GetDistance(scav1,pool) < 60.0f))
		{
			ClearObjectives();
			AddObjective("isdf0402.otf", WHITE);
			AddObjective("isdf0403.otf", WHITE);

			talk = AudioMessage("isdf0407.wav");//(shab) to set up scavengers open their menu...
			
			//BuildObject("ivscout",1,"deploy_point"); // this is temp
			
			shab_message3 = true;
		}
	}
	////////////////////////////////////////////


	// this is when the scav is selected
	
	if ((shab_message3) && (!shab_message4) && (IsSelected(scav1)))
	{
		ClearObjectives();
		AddObjective("isdf0402.otf", WHITE);
		AddObjective("isdf0403.otf", GREEN);
		AddObjective("isdf0404.otf", WHITE);

		StopAudioMessage(talk);
		talk = AudioMessage("isdf0408.wav");//(shab) point at the vien and press space bar or simply select the "go to vein" command
		scav1_check = GetTime() + 240.0f;
		shab_message4 = true;
	}
	////////////////////////////////////////////


//////////////////////////////////////////////////////////////////////////
// this is where I will start the first attack wave on the scav and the base


	if ((!spawn_1) && ((scavdeploy_message) || (shab_message3)))
	{
		scion1 = BuildObject("fvsent",2,"path_1");
		scion2 = BuildObject("fvpscou",2,"path_2");
		Stop(scion1);
		Stop(scion2);
		wave1_check = GetTime() + 2.0f;
		spawn_1 = true;
	}


	if ((spawn_1) && (!wave1_warning) && (wave1_check < GetTime()))
	{
		wave1_check = GetTime() + 2.0f;

		if ((GetDistance(scion1,scav1) < 200.0f)/* || (GetDistance(scion2,player) < 200.0f)*/)
		{
			AudioMessage("isdf0411.wav");//(shab) youve got two more of them out there hold them off unitl I can build some turrets
			wave1_check = GetTime() + 999999.9f;
			
			if (scavdeploy_message)
			{
				ClearObjectives();
				AddObjective("isdf0402.otf", GREEN);
				AddObjective("isdf0405.otf", WHITE);
			}
			else
			{
				ClearObjectives();
				AddObjective("isdf0402.otf", WHITE);
				AddObjective("isdf0405.otf", WHITE);
			}
			
			wave1_warning = true;
		}
	}
	
	
	if ((spawn_1) && (!IsAlive(scion1)) && (!IsAlive(scion2)))
	{
		if (!scavdeploy_message)
		{
			AudioMessage("isdf0409.wav");//(shab) john you wanna hurry and deploy that scav - I need the funds
			scavdeploy_message = true;
		}

		first_dead = true;
	}

//////////////////////////////////////////////////////////////////////////


	// this checks to see if the player ever deploys the scav1

	if ((!scav_check1) && (!scavdeploy_message) && (scav1_check < GetTime()))
	{
		if ((scav1_a) && (!deployscav_a))
		{
			AudioMessage("isdf0409.wav");//(shab) john you wanna hurry and deploy that scav - I need the funds
			
			ClearObjectives();
			AddObjective("isdf0402.otf", WHITE);
		}

		scav1_check = GetTime() + 999999.9f;
		scav_check1 = true;
	}
	////////////////////////////////////////////

	
	// when the first scav is deployed

	if ((!scavdeploy_message) && (scav1_a) && (shab_message3) && (deployscav_a))
	{
		if (!wave1_warning)
		{
			AudioMessage("isdf0410.wav");//(shab) good work - stay by that scav
		}

		if (IsAlive(scion1))
		{
			Attack(scion1,scav1);
		}

		if (IsAlive(scion2))
		{
			Attack(scion2,scav1);
		}

		//SetObjectiveOff(nav1);
		ClearObjectives();
		AddObjective("isdf0402.otf", GREEN);
		AddObjective("isdf0405.otf", WHITE);

		scavdeploy_message = true;
	}
	////////////////////////////////////////////


	// this sets the scrap a little higher to speed up the game

	if ((!scrap_cheat) && (scavdeploy_message) && (!IsAlive(scion1)) && (!IsAlive(scion2)))
	{
		SetScrap(1,35);
		scrap_cheat = true;
	}
	////////////////////////////////////////////

	
	// now that the turret is alive

	if ((turret1_a) && (!turret_set) && (pause < GetTime()))
	{
		talk = AudioMessage("isdf0412.wav");//(shab) I'm sending a turret to you. Deploy it near the scav for support
		Follow(turret1,player,0);
		turret_check = GetTime() + 2.0f;
		turret_set = true;
	}
	////////////////////////////////////////////


	// this is sending the newly contructed turret to the player (who is hopefully guarding the scavenger)

	if ((turret_set) && (!turret1_at_john) && (turret_check < GetTime()))
	{
		turret_check = GetTime() + 1.0f;


		if (GetDistance(turret1,player) < 60.0f)
		{
			AudioMessage("isdf0413.wav");//(shab) to deploy the turret...
			
			if (scavdeploy_message)
			{
				if (first_dead)
				{
					ClearObjectives();
					AddObjective("isdf0402.otf", GREEN);
					AddObjective("isdf0405.otf", GREEN);
					AddObjective("isdf0406.otf", WHITE);
				}
				else
				{
					ClearObjectives();
					AddObjective("isdf0402.otf", GREEN);
					AddObjective("isdf0405.otf", WHITE);
					AddObjective("isdf0406.otf", WHITE);
				}
			}
			else
			{

				if (first_dead)
				{
					ClearObjectives();
					AddObjective("isdf0402.otf", WHITE);
					AddObjective("isdf0405.otf", GREEN);
					AddObjective("isdf0406.otf", WHITE);
				}
				else
				{
					ClearObjectives();
					AddObjective("isdf0402.otf", WHITE);
					AddObjective("isdf0405.otf", WHITE);
					AddObjective("isdf0406.otf", WHITE);
				}
			}
			
			turret1_at_john = true;
		}
	}

	
	// this is the next attack on the scavenge

	if ((turret1_at_john) && (turret1_scavcheck) && (first_dead) && (!turret_test))
	{
		scion1 = BuildObject("fvsent",2,"path_1");
		scion2 = BuildObject("fvsent",2,"path_2");
		scion3 = BuildObject("fvscout",2,"path_3");
		Attack(scion1,scav1,1);
		Attack(scion2,scav1,1);
		Attack(scion3,player);
		turret_test = true;
	}
	////////////////////////////////////////////


	// this is after the turret attack
	
	if ((turret_test) && (!IsAlive(scion1)) && (!IsAlive(scion2)) && (!IsAlive(scion3)) && (!manson_set))
	{
		manson_message_time = GetTime() + 3.0f;
		manson_set = true;
	}
	////////////////////////////////////////////

	
	
	// this is manson radioing to Braddock that his plan is going wrong 

	if ((manson_set) && (!manson_message1) && (manson_message_time < GetTime()))
	{
		talk = AudioMessage("isdf0414.wav");//(manson) Braddock - your plan is going wrong
		manson_message1 = true;
	}
	////////////////////////////////////////////


	// braddock tells shab and cooke to retunr to base

	if ((manson_message1) && (!shab_reply1) && (IsAudioMessageDone(talk)))
	{
		talk = AudioMessage("isdf0422.wav");//(brad) shab and Cooke meet at reycler
		Goto(shabayev,"base_center");
		center_check = GetTime() + 1.0f;
		ClearObjectives();
		AddObjective("isdf0407.otf", WHITE);
		shab_reply1 = true;
	}
	////////////////////////////////////////////


	// checking to see when they are all at base
	
	if ((shab_reply1) && (!all_at_center) && (center_check < GetTime()))
	{
		center_check = GetTime() + 0.5f;


		if ((!shab_there) && (GetDistance(shabayev,"base_center") < 50.0f))
		{
			LookAt(shabayev,player);
			shab_there = true;
		}

		if ((!player_there) && (GetDistance(player,shabayev) < 60.0f))
		{
			player_there = true;
		}

		if (player_there)
		{
			LookAt(shabayev,player);
			all_at_center = true;
		}
	}
	////////////////////////////////////////////


	// braddock sends shab away

	if ((all_at_center) && (!send_shab_away) && (IsAudioMessageDone(talk)))
	{
		talk = AudioMessage("isdf0441.wav");//(brad) shab meet blue squad in sector 12
		send_shab_away = true;
	}


	if ((send_shab_away) && (!shab_protest) && (IsAudioMessageDone(talk)))
	{
		talk = AudioMessage("isdf0423.wav");//(shab) the area is not secure
		shab_protest = true;
	}


	if ((shab_protest) && (!brad_insist) && (IsAudioMessageDone(talk)))
	{
		talk = AudioMessage("isdf0424.wav");//(brad) I am aware! Carry out my orders!
		brad_insist = true;
	}


	if ((brad_insist) && (!shab_message5) && (IsAudioMessageDone(talk)))
	{
		talk = AudioMessage("isdf0415.wav");//(shab) Yes sir, I'm heading out
		scion1 = BuildObject("fvsent",2,"path_1");
		scion2 = BuildObject("fvsent",2,"path_2");
		//scion3 = BuildObject("fvsent",2,"path_3");
		//SetTeamNum(wingman1,1);
		//SetTeamNum(wingman2,1);
		john_check = GetTime() + 1.0f;
		shab_message5 = true;
	}
	////////////////////////////////////////////

/*
	// this is sending shab away from the base

	if ((shab_message5) && (!shab_go_away) && (IsAudioMessageDone(talk)))
	{
		SetObjectiveOff(shabayev);
		Goto(shabayev,"man_out_path");
		shab_go_away = true;
	}
	////////////////////////////////////////////
*/


	// this loads the new plan where braddock builds turrets

	if ((shab_message5) && (!load_plan3) && (IsAudioMessageDone(talk)))
	{
		//SetScrap(1,43);
		Retreat(shabayev,"man_out_path");
		SetPerceivedTeam(shabayev,2);
		SetObjectiveOff(shabayev);
		away_check = GetTime() + 1.0f;
		talk = AudioMessage("isdf0416.wav");//(brad) Cooke - I'm placing that recycler into a build loop
		load_plan3 = true;
	}


	if ((load_plan3) && (!plan3_loaded)/* && (IsAudioMessageDone(talk))*/)
	{
		ClearObjectives();
		AddObjective("isdf0407.otf", GREEN);
		AddObjective("isdf0408.otf", WHITE);
		SetPlan("isdf0403.aip",1); // builds 4 turrets
		plan3_loaded = true;
	}
	////////////////////////////////////////////


	// the second scions attack the scavnger

	if ((load_plan3) && (!shab_away) && (IsAudioMessageDone(talk)))
	{
		Attack(scion1,recycler,0);
		Attack(scion2,recycler,0);
		//Follow(scion3,scion2);

		shab_away = true;
	}
	////////////////////////////////////////////


	// this is checking to see when the second wave is dead

	if ((shab_message5) && (!second_dead))
	{
		if ((!IsAlive(scion1)) && (!IsAlive(scion2)) && (!IsAlive(scion3)))
		{
			next_wave = GetTime() + 120.0f;
			second_dead = true;
		}
	}
	////////////////////////////////////////////


	// this is checking to see when shab is away

	if ((shab_away) && (!remove_shab) && (away_check < GetTime()))
	{
		away_check = GetTime() + 1.0f;


		if (GetDistance(shabayev,player) > 500.0f)
		{
			RemoveObject(shabayev);
			remove_shab = true;
		}
	}
	////////////////////////////////////////////


	// this is the third wave

	if ((second_dead) && (!third_spawn) && (next_wave < GetTime()))
	{
		scion1 = BuildObject("fvsent",2,"path_1");
		scion2 = BuildObject("fvsent",2,"path_2");
		scion3 = BuildObject("fvsent",2,"path_3");

		Attack(scion1,scav1);
		Follow(scion2,scion1,0);
		Attack(scion3,recycler,0);

		next_wave = GetTime() + 999999.9f;
		third_spawn = true;

	}
	////////////////////////////////////////////


	// this is checking to see when the third wave is dead

	if ((third_spawn) && (!third_dead))
	{
		if ((!IsAlive(scion1)) && (!IsAlive(scion2)) && (!IsAlive(scion3)))
		{
			fodder_time = GetTime() + 30.0f;
			third_dead = true;
		}
	}
	////////////////////////////////////////////


	// this is setting next time

	if ((turret3_a) && (third_dead) && (!set_for_main))
	{
		next_wave = GetTime() + 200;
		set_for_main = true;
	}
	////////////////////////////////////////////


	// this is going to spawn in cannon fodder until the main wave is ready to attack

	if ((!major_wave) && (third_dead))
	{
		if ((!IsAlive(fodder1)) && (!IsAlive(fodder2)) && (fodder_time < GetTime()))
		{
			fodder_time = GetTime() + 30.0f;
			fodder1 = BuildObject("fvscout",2,"fodder1_spawn");
			fodder2 = BuildObject("fvscout",2,"fodder2_spawn");
			SetAvoidType(fodder1,0);
			SetAvoidType(fodder2,0);
			Goto(fodder1,"fodder1_path",0);
			Goto(fodder2,"fodder2_path",0);
			fodder_attack = false;
		}
	}
	////////////////////////////////////////////


	// this makes the fodder attack

	if (!fodder_attack)
	{
		if ((IsAlive(fodder1)) && (GetDistance(fodder1,recycler) < 40))
		{
			Attack(fodder1,player,0);

			if (IsAlive(fodder2))
			{
				Attack(fodder2,player,0);
			}

			fodder_attack = true;
		}

		if ((!fodder_attack) && (IsAlive(fodder2)) && (GetDistance(fodder2,recycler) < 40))
		{
			Attack(fodder2,player,0);

			if (IsAlive(fodder1))
			{
				Attack(fodder1,player,0);
			}

			fodder_attack = true;
		}
	}
	////////////////////////////////////////////

	
	// these are the attack waves that come at the Recycler and scavneger

	if (!major_wave)
	{
		if ((turret5_a) || ((set_for_main) && (next_wave < GetTime())))

		{
			scion1 = BuildObject("fvptank",2,"path_1");
			scion2 = BuildObject("fvsent",2,"path_2");
			scion3 = BuildObject("fvptank",2,"enemy1");
			scion4 = BuildObject("fvsent",2,"enemy2");
			scion5 = BuildObject("fvptank",2,"enemy3");
			scion6 = BuildObject("fvsent",2,"enemy4");

			Attack(scion1,scav1);
			Follow(scion2,scion1,0);
			Goto(scion3,"main_path1",0);
			Follow(scion4,scion3,0);
			Goto(scion5,"main_path2",0);
			Follow(scion6,scion5,0);

			//Attack(scion1,scav1);
			//Follow(scion2,scion1);
			//Attack(scion3,recycler);
			//Follow(scion4,scion3);
			//Goto(scion5,recycler);
			//Follow(scion6,scion5);

			next_wave = GetTime() + 1.0f;

			major_wave = true;
		}
	}
	////////////////////////////////////////////


	// this is making the last wave attack the recycler

	if ((!major_attack) && (major_wave) && (next_wave < GetTime()))
	{
		next_wave = GetTime() + 1.0f;

		if (IsAlive(scion3))
		{
			if ((!major1_attack) && (GetDistance(scion3,recycler) < 50))  
			{
				Attack(scion3,recycler,0);
				major1_attack = true;
			}
		}
		else if (IsAlive(scion4))
		{
			Attack(scion4,recycler,0);
			major1_attack = true;
		}


		if (IsAlive(scion5))
		{
			if ((!major2_attack) && (GetDistance(scion5,recycler) < 50)) 
			{
				Attack(scion5,recycler,0);
				major2_attack = true;
			}
		}
		else if (IsAlive(scion6))
		{
			Attack(scion6,recycler,0);
			major2_attack = true;
		}


		if ((major1_attack) && (major2_attack))
		{
			major_attack = true;
		}
	}
	////////////////////////////////////////////


	// this is checking to see when the last wave is dead

	if ((!last_wave_dead) && (major_wave))
	{
		if ((!IsAlive(scion1)) && (!IsAlive(scion2)) && (!IsAlive(scion3)) && 
			(!IsAlive(scion4)) && (!IsAlive(scion5)) && (!IsAlive(scion6)))
		{
			next_wave = GetTime() + 3.0f;
			major_attack = true;
			last_wave_dead = true;
		}
	}
	////////////////////////////////////////////


/////////////////////// ON_HOLD ///////////////////////////////////////
}
/*
if ((!last_wave_dead) && (GetDistance(player,pool) < 200.0f))
{
	RemoveObject(shabayev);
	RemoveObject(manson);
	RemoveObject(wing1);
	RemoveObject(wing2);
	RemoveObject(tug1);
	RemoveObject(tug2);
	RemoveObject(tug_drop);
	RemoveObject(recy_drop);
	next_wave = GetTime() + 1.0f;
	remove_shab = true;
	last_wave_dead = true;
}
*/

//if (!ON_HOLD)
//{
////////////////////////////////////////////////////////////////////////

	if (get_to_armo)
	{
		SetScrap(1,38);
	}

	// this is braddock ordering Cooke to the armory

	if ((last_wave_dead) && (!gun_picked))
	{
		if ((!get_to_armo) && (next_wave < GetTime()))
		{
			//Matrix pos;
			//GetPosition(recycler,pos);
			//RemoveObject(recycler);
			//recycler = BuildObject("ibrecy4x",1,pos);

			talk = AudioMessage("isdf0418.wav");//(brad) Get to the armory boy!
			ClearObjectives();
			AddObjective("isdf0409.otf", WHITE);
			power_up = BuildObject("apsnip",1,"gun_spawn");
			SetObjectiveOn(power_up);
			TranslateString2(tempstr, sizeof(tempstr), "Mission0402");  // Sniper Tracer
			SetObjectiveName(power_up,tempstr);
			power_up_check = GetTime() + 180.0f;
			next_wave = GetTime() + 999999.9f;
			get_to_armo = true;
		}

		if ((!shepards_message) && (get_to_armo))
		{
			talk = AudioMessage("isdf0417.wav");//(manson) Shepards are in place sir
			shepards_message = true;
		}
		

		if ((shepards_message) && (IsAudioMessageDone(talk)))
		{
			if ((!power_up_message) && (GetDistance(player,power_up) < 100.0f))
			{
				talk = AudioMessage("isdf0445.wav");//(braddock) get out of your ship
				power_up_message = true;
			}			


			if ((!gun_warning) && (!gun_picked) && (power_up_check < GetTime()))
			{
				talk = AudioMessage("isdf0442.wav");//(brad) why havent you picked up the power-up?!
				power_up_check = GetTime() + 180.0f;
				gun_warning = true;
			}
		}


		if ((get_to_armo) && (!gun_picked) && (!IsAround(power_up)))
		{
			StopAudioMessage(talk);
			talk = AudioMessage("isdf0419.wav");//(brad) good - go to nav
			bunker_nav = BuildObject("ibnav",1,"bunk_nav_spawn");
			SetObjectiveOn(bunker_nav);
			TranslateString2(tempstr, sizeof(tempstr), "Mission0403");  // Relay Bunker
			SetObjectiveName(bunker_nav,tempstr);
			ClearObjectives();
			AddObjective("isdf0409.otf", GREEN);
			AddObjective("isdf0410.otf", WHITE);
			john_check = GetTime() + 5.0f;
			john_dilly = GetTime() + 300.0f;
			power_up_check = GetTime() + 999999.9f;

			if (IsAlive(turret1))
			{
				Stop(turret1);
			}
			if (IsAlive(turret2))
			{
				Stop(turret2);
			}
			if (IsAlive(turret3))
			{
				Stop(turret3);
			}
			if (IsAlive(turret4))
			{
				Stop(turret4);
			}
			if (IsAlive(turret5))
			{
				Stop(turret5);
			}

			gun_picked = true;
		}
	}
	////////////////////////////////////////////


	// checking to see if the player gets to the bunker

	if ((!john_at_bunk) && (!john_bunker_warn) && (john_dilly < GetTime()))
	{
		talk = AudioMessage("isdf0425.wav");//(brad) Get to that nav now!!
		ClearObjectives();
		AddObjective("isdf0410.otf", WHITE);
		john_dilly = GetTime() + 120.0f;
		john_bunker_warn = true;
	}


	// this is after Cooke gets to the bunker

	if ((gun_picked) && (!john_at_bunk) && (john_check < GetTime()))
	{
		john_check = GetTime() + 2.0f;

		if ((!john_on_way) && (GetDistance(player,field_cbunk) < 200.0f))
		{
			talk = AudioMessage("isdf0427.wav");//(manson) flock in on the way!
			enemy_spawn_time = GetTime() + 1.0f;
			john_on_way = true;
		}

		if (GetDistance(player,field_cbunk) < 50.0f)
		{
			talk = AudioMessage("isdf0428.wav");//(brad) Get into that bunker now!!
			ClearObjectives();
			AddObjective("isdf0410.otf", GREEN);
			john_dilly = GetTime() + 999999.9f;
			john_at_bunk = true;
		}
	}
	////////////////////////////////////////////


	// this is when the player gets into the bunker

	if ((!state_mission) && (john_at_bunk) && (player_on_foot) && (InBuilding(player)))
	{
		talk = AudioMessage("isdf0430b.wav");//(brad) you have to tag an enemy
		state_mission = true;
	}
	////////////////////////////////////////////


	// building the enemy convoy

	if ((state_mission) && (!convoy_spawn) && (enemy_spawn_time < GetTime()))
	{
		enemy_spawn_time = GetTime() + 1.0f;

		if (GetDistance(player,"scion1_spawn") > 200.0f)
		{
			snipe_scion1 = BuildObject("fvpsnt4",2,"scion1_spawn");
			snipe_scion2 = BuildObject("fvpsnt4",2,"scion2_spawn");
			snipe_scion3 = BuildObject("fvpsnt4",2,"scion3_spawn");
			snipe_scion4 = BuildObject("fvpsnt4",2,"scion4_spawn");
			snipe_scion5 = BuildObject("fvpsnt4",2,"scion5_spawn");
			//hauler1 = BuildObject("fvtug",2,"hauler1_spawn");
			//hauler2 = BuildObject("fvtug",2,"hauler2_spawn");

			Stop(snipe_scion1);
			Stop(snipe_scion2);
			Stop(snipe_scion3);
			Stop(snipe_scion4);
			Stop(snipe_scion5);
			//Stop(hauler1);
			//Stop(hauler2);

			SetAvoidType(snipe_scion1,0);
			SetAvoidType(snipe_scion2,0);
			SetAvoidType(snipe_scion3,0);
			SetAvoidType(snipe_scion4,0);
			SetAvoidType(snipe_scion5,0);
			//SetAvoidType(hauler1,0);
			//SetAvoidType(hauler2,0);

			convoy_spawn = true;
		}
	}
	////////////////////////////////////////////


	// this is where I have to send the convoy past the comm bunker

	if ((convoy_spawn) && (!haulers_underway) && (IsAudioMessageDone(talk)))
	{
/*
		Retreat(hauler1,"escape_path");
		Follow(hauler2,hauler1);
		Follow(scion1,hauler1);
		Follow(scion2,scion1);
		Follow(scion3,hauler2);
		Follow(scion4,scion3);
		Follow(scion5,scion4);
*/
		Retreat(snipe_scion1,"escape_path1");
		Follow(snipe_scion2,snipe_scion1);
		Follow(snipe_scion3,snipe_scion1);
		Follow(snipe_scion4,snipe_scion2);
		Follow(snipe_scion5,snipe_scion3);

		convoy_check = GetTime() + 1.0f;
		haulers_underway = true;
	}
	////////////////////////////////////////////


	// this is the scion convoy code

	if (!ship_sniped)
	{
		if ((!to_escape) && (haulers_underway) && (convoy_check < GetTime()))
		{
			convoy_check = GetTime() + 1.0f;

			// this is manson warning when the ships are almost at the target

			if ((!manson_message3) && (GetDistance(snipe_scion1,"hold_point") < 150.0f))
			{
				talk = AudioMessage("isdf0429.wav");//(manson) Here they come
				manson_message3 = true;
			}
			
			// this is the scions stopping and morphing

			if  ((!convoy_hold) && (GetDistance(snipe_scion1,"hold_point") < 20.0f))
			{
				LookAt(snipe_scion1,snipe_scion5);
				convoy_wait_time = GetTime() + 15.0f;
				convoy_hold = true;
			}

			//if ((convoy_hold) && (!to_escape) && (convoy_wait_time < GetTime()))
			//{
			//	Retreat(scion5,"escape_path2");
			//	Follow(scion1,scion5);
			//	Follow(scion2,scion5);
			//	Follow(scion3,scion1);
			//	Follow(scion4,scion2);
			//	to_escape = true;
			//}
		}

		// this is triggering the final movie

		if ((to_escape) && (!end_escape) && (GetNearestEnemy(scion_drop) < 60.0))
		{
			if (IsAround(snipe_scion1))
			{
				Follow(snipe_scion1,scion_drop);
			}
			if (IsAround(snipe_scion2))
			{
				Follow(snipe_scion2,scion_drop);
			}
			if (IsAround(snipe_scion3))
			{
				Follow(snipe_scion3,scion_drop);
			}
			if (IsAround(snipe_scion4))
			{
				Follow(snipe_scion4,scion_drop);
			}
			if (IsAround(snipe_scion5))
			{
				Follow(snipe_scion5,scion_drop);
			}

			end_game_time = GetTime() + 60.0f;
			end_escape = true;
		}
	}
	////////////////////////////////////////////


	// this is checking to see if the player snipes a ship

	Handle predead = 0;
	if ((convoy_spawn) && (!ship_sniped)) //&& (player_on_foot))
	{
		if ((!ship_sniped) && (IsAround(snipe_scion1)))//(GetTime() - GetLastEnemyShot(scion1) < .2f))
		{
			predead=snipe_scion1;
			if (!IsAlive(snipe_scion1))
			{
				talk = AudioMessage("isdf0431a.wav");//(brad) nice shot pilot! Get back to your ship before you become roadkill

				Matrix pos;
				GetPosition(predead,pos);
				RemoveObject(predead);
				snipe_scion1 = BuildObject("fvsentx",1,pos);
				SetAvoidType(snipe_scion1,0);
				SetObjectiveOn(snipe_scion1);
				talk = AudioMessage("isdf0431a.wav");//(brad) nice shot pilot! Get back to your ship before you become roadkill
				Stop(snipe_scion1,1);
				TranslateString2(tempstr, sizeof(tempstr), "Mission0404");  // Tagged
				SetObjectiveName(snipe_scion1,tempstr);
				SetPerceivedTeam(snipe_scion1,2);
				sniped_ship = snipe_scion1;
				abandon_check = GetTime() + 2.1f;
				tag1 = true;
				ship_sniped = true;
			}
		}

		if ((!ship_sniped) && (IsAround(snipe_scion2)))//(GetTime() - GetLastEnemyShot(scion2) < .2f))
		{
			predead=snipe_scion2;
			if (!IsAlive(snipe_scion2))
			{
				Matrix pos;
				GetPosition(predead,pos);
				RemoveObject(predead);
				snipe_scion2 = BuildObject("fvsentx",1,pos);
				SetAvoidType(snipe_scion2,0);
				talk = AudioMessage("isdf0431a.wav");//(brad) nice shot pilot! Get back to your ship before you become roadkill
				Stop(snipe_scion2,1);
				SetObjectiveOn(snipe_scion2);
				TranslateString2(tempstr, sizeof(tempstr), "Mission0404");  // Tagged
				SetObjectiveName(snipe_scion2,tempstr);
				SetPerceivedTeam(snipe_scion2,2);
				sniped_ship = snipe_scion2;
				abandon_check = GetTime() + 2.1f;
				tag2 = true;
				ship_sniped = true;
			}
		}

		if ((!ship_sniped) && (IsAround(snipe_scion3)))//(GetTime() - GetLastEnemyShot(scion3) < .2f))
		{
			predead=snipe_scion3;
			if (!IsAlive(snipe_scion3))
			{
				Matrix pos;
				GetPosition(predead,pos);
				RemoveObject(predead);
				snipe_scion3 = BuildObject("fvsentx",1,pos);
				SetAvoidType(snipe_scion3,0);
				talk = AudioMessage("isdf0431a.wav");//(brad) nice shot pilot! Get back to your ship before you become roadkill
				Stop(snipe_scion3,1);

				SetObjectiveOn(snipe_scion3);
				TranslateString2(tempstr, sizeof(tempstr), "Mission0404");  // tagged
				SetObjectiveName(snipe_scion3,tempstr);
				SetPerceivedTeam(snipe_scion3,2);
				sniped_ship = snipe_scion3;
				abandon_check = GetTime() + 2.1f;
				tag3 = true;
				ship_sniped = true;
			}
		}


		if ((!ship_sniped) && (IsAround(snipe_scion4)))//(GetTime() - GetLastEnemyShot(scion4) < .2f))
		{
			predead=snipe_scion4;
			if (!IsAlive(snipe_scion4))
			{
				Matrix pos;
				GetPosition(predead,pos);
				RemoveObject(predead);
				snipe_scion4 = BuildObject("fvsentx",1,pos);
				SetAvoidType(snipe_scion4,0);
				talk = AudioMessage("isdf0431a.wav");//(brad) nice shot pilot! Get back to your ship before you become roadkill
				Stop(snipe_scion4,1);

				SetObjectiveOn(snipe_scion4);
				TranslateString2(tempstr, sizeof(tempstr), "Mission0404");  // tagged
				SetObjectiveName(snipe_scion4,tempstr);
				SetPerceivedTeam(snipe_scion4,2);
				sniped_ship = snipe_scion4;
				abandon_check = GetTime() + 2.1f;
				tag4 = true;
				ship_sniped = true;
			}
		}

		if ((!ship_sniped) && (IsAround(snipe_scion5)))//(GetTime() - GetLastEnemyShot(scion5) < .2f))
		{
			predead=snipe_scion5;
			if (!IsAlive(snipe_scion5))
			{
				Matrix pos;
				GetPosition(predead,pos);
				RemoveObject(predead);
				snipe_scion5 = BuildObject("fvsentx",1,pos);
				SetAvoidType(snipe_scion5,0);
				talk = AudioMessage("isdf0431a.wav");//(brad) nice shot pilot! Get back to your ship before you become roadkill
				Stop(snipe_scion5,1);
				SetObjectiveOn(snipe_scion5);
				TranslateString2(tempstr, sizeof(tempstr), "Mission0404");  // tagged
				SetObjectiveName(snipe_scion5,tempstr);
				SetPerceivedTeam(snipe_scion5,2);
				sniped_ship = snipe_scion5;
				abandon_check = GetTime() + 5.0f;//2.1f;
				tag5 = true;
				ship_sniped = true;
			}
		}
	}
	////////////////////////////////////////////


	// this occures when the player tags a ship

	if (ship_sniped)
	{
		// this makes sure the sniped ship stays alive

		if (!sniped_destroyed)
		{
			if ((tag1) && (!IsAround(snipe_scion1)))
			{
				sniped_destroyed = true;
			}
			if ((tag2) && (!IsAround(snipe_scion2)))
			{
				sniped_destroyed = true;
			}
			if ((tag3) && (!IsAround(snipe_scion3)))
			{
				sniped_destroyed = true;
			}
			if ((tag4) && (!IsAround(snipe_scion4)))
			{
				sniped_destroyed = true;
			}
			if ((tag5) && (!IsAround(snipe_scion5)))
			{
				sniped_destroyed = true;
			}
		}
		////////////////////////////////////////////


		// sending the scions after the comm bunker

		if ((!ships_defend) && (abandon_check < GetTime()))
		{
/*
			if (tag1)
			{
				if (IsAlive(scion2))
				{
					Goto(scion2,"hold_point");
				}
				if (IsAlive(scion3))
				{
					Goto(scion3,"hold_point");
				}
				if (IsAlive(scion4))
				{
					Goto(scion4,"hold_point");
				}
				if (IsAlive(scion5))
				{
					Goto(scion5,"hold_point");
				}
			}
			else if (tag2)
			{
				if (IsAlive(scion1))
				{
					Goto(scion1,"hold_point");
				}
				if (IsAlive(scion3))
				{
					Goto(scion3,"hold_point");
				}
				if (IsAlive(scion4))
				{
					Goto(scion4,"hold_point");
				}
				if (IsAlive(scion5))
				{
					Goto(scion5,"hold_point");
				}
			}
			else if (tag3)
			{
				if (IsAlive(scion1))
				{
					Goto(scion1,"hold_point");
				}
				if (IsAlive(scion2))
				{
					Goto(scion2,"hold_point");
				}
				if (IsAlive(scion4))
				{
					Goto(scion4,"hold_point");
				}
				if (IsAlive(scion5))
				{
					Goto(scion5,"hold_point");
				}
			}
			else if (tag4)
			{
				if (IsAlive(scion1))
				{
					Goto(scion1,"hold_point");
				}
				if (IsAlive(scion2))
				{
					Goto(scion2,"hold_point");
				}
				if (IsAlive(scion3))
				{
					Goto(scion3,"hold_point");
				}
				if (IsAlive(scion5))
				{
					Goto(scion5,"hold_point");
				}
			}
			else if (tag5)
			{
				if (IsAlive(scion1))
				{
					Goto(scion1,"hold_point");
				}
				if (IsAlive(scion2))
				{
					Goto(scion2,"hold_point");
				}
				if (IsAlive(scion3))
				{
					Goto(scion3,"hold_point");
				}
				if (IsAlive(scion4))
				{
					Goto(scion4,"hold_point");
				}
			}
*/

			// this is spawning in the cavelry

			friend1 = BuildObject("ivtank4",3,"friend1");
			friend2 = BuildObject("ivtank4",4,"friend2");
			friend3 = BuildObject("ivscout",4,"friend3");
			friend4 = BuildObject("ivscout",3,"friend4");
			//friend5 = BuildObject("ivscout",1,"friend5");
			//friend6 = BuildObject("ivscout",1,"friend6");

			Goto(friend1,field_cbunk);
			Goto(friend2,field_cbunk);
			Goto(friend3,field_cbunk);
			Goto(friend4,field_cbunk);
			//Goto(friend5,field_cbunk);
			//Goto(friend6,field_cbunk);

			SetAvoidType(friend1,0);
			SetAvoidType(friend2,0);
			SetAvoidType(friend3,0);
			SetAvoidType(friend4,0);
			//SetAvoidType(friend5,0);
			//SetAvoidType(friend6,0);

			convoy_check = GetTime() + 20.0f;
			ships_defend = true;
		}
		////////////////////////////////////////////


		// this is the scions pulling out for the last time

		if ((ships_defend) && (!final_retreat) && (convoy_check < GetTime()))
		{
			if (IsAround(snipe_scion1))
			{
				//SetPerceivedTeam(scion1,1);
				Retreat(snipe_scion1,"cattle_spot");
			}

			if (IsAround(snipe_scion2))
			{
				//SetPerceivedTeam(scion2,1);
				Retreat(snipe_scion2,"cattle_spot");
			}

			if (IsAround(snipe_scion3))
			{
				//SetPerceivedTeam(scion3,1);
				Retreat(snipe_scion3,"cattle_spot");
			}

			if (IsAround(snipe_scion4))
			{
				//SetPerceivedTeam(scion4,1);
				Retreat(snipe_scion4,"cattle_spot");
			}

			if (IsAround(snipe_scion5))
			{
				//SetPerceivedTeam(scion5,1);
				Retreat(snipe_scion5,"cattle_spot");
			}

			convoy_check = GetTime() + 8.0f;
			show_time = GetTime() + 1.0f;
			final_retreat = true;
		}
		////////////////////////////////////////////


		// this is manson calling braddock

		if ((final_retreat) && (!manson_message4) && (convoy_check < GetTime()))
		{
			talk = AudioMessage("isdf0435.wav");//(manson) they're moving general

			if ((tag1) || (tag2) || (tag3) || (tag4) || (tag5))
			{
				if (IsAlive(snipe_scion1))
				{
					Retreat(snipe_scion1,"epath1");
				}
				if (IsAlive(snipe_scion2))
				{
					Retreat(snipe_scion2,"epath2");
				}
				if (IsAlive(snipe_scion3))
				{
					Retreat(snipe_scion3,"epath3");
				}
				if (IsAlive(snipe_scion4))
				{
					Retreat(snipe_scion4,"epath4");
				}
				if (IsAlive(snipe_scion5))
				{
					Retreat(snipe_scion5,"epath1");
				}
			}
/*
			if (tag1)
			{
				if (IsAlive(scion2))
				{
					Retreat(scion2,"epath2");
				}
				if (IsAlive(scion3))
				{
					Retreat(scion3,"epath3");
				}
				if (IsAlive(scion4))
				{
					Retreat(scion4,"epath4");
				}
				if (IsAlive(scion5))
				{
					Retreat(scion5,"epath1");
				}
			}
			else if (tag2)
			{
				if (IsAlive(snipe_scion1))
				{
					Retreat(snipe_scion1,"epath1");
				}
				if (IsAlive(scion3))
				{
					Retreat(scion3,"epath3");
				}
				if (IsAlive(scion4))
				{
					Retreat(scion4,"epath4");
				}
				if (IsAlive(scion5))
				{
					Retreat(scion5,"epath2");
				}
			}
			else if (tag3)
			{
				if (IsAlive(snipe_scion1))
				{
					Retreat(snipe_scion1,"epath1");
				}
				if (IsAlive(scion2))
				{
					Retreat(scion2,"epath2");
				}
				if (IsAlive(scion4))
				{
					Retreat(scion4,"epath4");
				}
				if (IsAlive(scion5))
				{
					Retreat(scion5,"epath3");
				}
			}
			else if (tag4)
			{
				if (IsAlive(snipe_scion1))
				{
					Retreat(snipe_scion1,"epath1");
				}
				if (IsAlive(scion2))
				{
					Retreat(scion2,"epath2");
				}
				if (IsAlive(scion3))
				{
					Retreat(scion3,"epath3");
				}
				if (IsAlive(scion5))
				{
					Retreat(scion5,"epath4");
				}
			}
			else if (tag5)
			{
				if (IsAlive(snipe_scion1))
				{
					Retreat(snipe_scion1,"epath1");
				}
				if (IsAlive(scion2))
				{
					Retreat(scion2,"epath2");
				}
				if (IsAlive(scion3))
				{
					Retreat(scion3,"epath3");
				}
				if (IsAlive(scion4))
				{
					Retreat(scion4,"epath4");
				}
			}
*/
			convoy_check = GetTime() + 8.0f;
			manson_message4 = true;
		}
		////////////////////////////////////////////


		// this is manson going after them

		if ((manson_message4) && (!manson_chase) && (convoy_check < GetTime()))
		{
			talk = AudioMessage("isdf0436.wav");//(braddock) stay with them!
			
			if (IsAround(scion1))
			{
				SetPerceivedTeam(scion1,1);
			}
			if (IsAround(scion2))
			{
				SetPerceivedTeam(scion2,1);
			}
			if (IsAround(scion3))
			{
				SetPerceivedTeam(scion3,1);
			}
			if (IsAround(scion4))
			{
				SetPerceivedTeam(scion4,1);
			}
			if (IsAround(scion5))
			{
				SetPerceivedTeam(scion5,1);
			}


			if (IsAlive(friend1))
			{
				Goto(friend1,"epath1");

				if (IsAlive(friend3))
				{
					Follow(friend3,friend1);
				}

				if (IsAlive(friend2))
				{
					Goto(friend2,"epath2");

					if (IsAlive(friend4))
					{
						Follow(friend4,friend2);
					}
				}
				else if (IsAlive(friend4))
				{
					Follow(friend4,friend1);
				}
			}
			else if (IsAlive(friend2))
			{
				Goto(friend2,"epath1");

				if (IsAlive(friend3))
				{
					Follow(friend3,friend2);
				}

				if (IsAlive(friend4))
				{
					Follow(friend4,friend2);
				}
			}
			else if (IsAlive(friend3))
			{
				Goto(friend3,"epath1");

				if (IsAlive(friend4))
				{
					Follow(friend4,friend3);
				}
			}
			else if (IsAlive(friend4))
			{
				Goto(friend4,"epath1");
			}

			convoy_check = GetTime() + 1.0f;
			manson_chase = true;
		}
		////////////////////////////////////////////


		// this is triggering the final movie

		if ((!end_escape) && (manson_chase) && (convoy_check < GetTime()))
		{
			convoy_check = GetTime() + 1.0f;

			if (!one_there)
			{
				if (IsAlive(snipe_scion1))
				{
					if (GetDistance(snipe_scion1,"show_time_point") < 30.0f)
					{
						one_there = true;
					}
				}
				else
				{
					one_there = true;
				}
			}

			if (!two_there)
			{
				if (IsAlive(snipe_scion2))
				{
					if (GetDistance(snipe_scion2,"show_time_point") < 30.0f)
					{
						two_there = true;
					}
				}
				else
				{
					two_there = true;
				}
			}

			if (!three_there)
			{
				if (IsAlive(snipe_scion3))
				{
					if (GetDistance(snipe_scion3,"show_time_point") < 30.0f)
					{
						three_there = true;
					}
				}
				else
				{
					three_there = true;
				}
			}

			if (!four_there)
			{
				if (IsAlive(snipe_scion4))
				{
					if (GetDistance(snipe_scion4,"show_time_point") < 30.0f)
					{
						four_there = true;
					}
				}
				else
				{
					four_there = true;
				}
			}

			if (!five_there)
			{
				if (IsAlive(snipe_scion5))
				{
					if (GetDistance(snipe_scion5,"show_time_point") < 30.0f)
					{
						five_there = true;
					}
				}
				else
				{
					five_there = true;
				}
			}
		}


		if ((!end_escape) && (one_there) && (two_there) && (three_there) && (four_there) && (five_there))
		{
			end_game_time = GetTime() + 60.0f;
			end_escape = true;
		}
	}
	////////////////////////////////////////////


	// checking to see if any of the enemy ships get destroyed

	if ((!ships_dead) && (ships_defend))
	{
		if ((!IsAlive(scion5)) && (!IsAlive(scion4)) && (!IsAlive(scion3)) && (!IsAlive(scion2)) && (!IsAlive(scion1)))
		{
			ships_dead = true;
		}
	}
	////////////////////////////////////////////


	// this is the ending movie

	if ((!start_end_show) && (show_time < GetTime()))
	{
		show_time = GetTime() + 1.0f;

		// when the player gets there
		
		if (GetDistance(player,"show_time_point") < 120.0f)
		{
			talk = AudioMessage("isdf0437.wav");//(manson) They're leaving
			end_game_time = GetTime() + 999999.9f;
			SetAnimation(scion_drop,"takeoff",1);
			CameraReady();
			start_movie = true;
			start_end_show = true;
		}
		////////////////////////////////////////////


		// if the ships get there and the player doesn't

		if ((end_escape) && (end_game_time < GetTime()))
		{
			talk = AudioMessage("isdf0437.wav");//(manson) They're leaving
			end_game_time = GetTime() + 999999.9f;
			not_there = true;
			start_end_show = true;
		}
	}


	if (start_movie)
	{
		CameraPath("camera1_point",180,0,scion_drop);
	}


	// this is the crumble cliff code

	if ((manson_message4) && (!cliff_fall))
	{
		if (GetDistance(player,"cliff_point") < 30.0f)
		{
			SetAnimation(crumble_cliff,"crumble",1);
			cliff_fall = true;
		}
	}
	////////////////////////////////////////////

/*
	if ((ship_sniped) && (GetDistance(sniped_ship,scion_drop) < 100.0f))
	{
		if ((!start_movie) && (!not_there) && (end_game_time < GetTime()))
		{
			talk = AudioMessage("isdf0437.wav");//(manson) They're leaving
			not_there = true;
			start_end_show = true;
		}


		if ((!not_there) && (!start_movie))
		{
			if (GetDistance(player,scion_drop) < 142.0f)
			{
				talk = AudioMessage("isdf0437.wav");//(manson) They're leaving
				end_game_time = GetTime() + 999999.9f;
				start_movie = true;
				start_end_show = true;
			}
		}
	}


	if ((!ship_sniped) && (!brad_complain))
	{
		talk = AudioMessage("isdf0432.wav");//(brad) our shooter missed the target!
		brad_complain = true;
		start_end_show = true;
	}
*/

// these are the win/loose conditions
if ((!game_over) && (!ON_HOLD))
{
	if ((scav1_a) && (!deployscav_a) && (!IsAlive(scav1)))
	{
		ClearObjectives();
		AddObjective("isdf0405.otf", RED);
		FailMission(GetTime() + 5.0f);
		game_over = true;
	}

	if ((scav1_a) && (!IsAlive(scav1)))
	{
		ClearObjectives();
		AddObjective("isdf0405.otf", RED);
		FailMission(GetTime() + 5.0f);
		game_over = true;
	}

	if (!IsAlive(recycler))
	{
		ClearObjectives();
		AddObjective("isdf0408.otf", RED);
		FailMission(GetTime() + 5.0f);
		game_over = true;
	}
	
	if ((!remove_shab) && (!IsAlive(shabayev)))
	{
		FailMission(GetTime() + 5.0f);
		game_over = true;
	}

	if ((!john_at_bunk) && (john_bunker_warn) && (john_dilly < GetTime()))
	{
		AudioMessage("isdf0426.wav");//(brad) Cooke - you are relieved of duty!
		FailMission(GetTime() + 5.0f);
		game_over = true;
	}

	if (start_end_show)
	{
		if ((brad_complain) && (IsAudioMessageDone(talk)))
		{
			AudioMessage("isdf0433.wav");//(manson) mission failed
			FailMission(GetTime() + 7.0f);
			game_over = true;
		}

		if ((not_there) && (IsAudioMessageDone(talk)))
		{
			AudioMessage("isdf0438.wav");//(manson) mission success
			SucceedMission(GetTime() + 7.0f,"isdf04w1.txt");
			SetAnimation(scion_drop,"takeoff",1);
			game_over = true;
		}

		// this is the ending movie

		if ((start_movie) && (IsAudioMessageDone(talk)))
		{
			AudioMessage("isdf0438.wav");//(manson) mission success
			SucceedMission(GetTime() + 7.0f,"isdf04w1.txt");
			game_over = true;
		}
	}

	if (!remove_manson)
	{
		if ((!IsAlive(manson)) || (!IsAlive(wing1)) || (!IsAlive(wing2))) 
		{
			AudioMessage("isdf0426.wav");//(brad) Cooke - you are relieved of duty!
			FailMission(GetTime() + 5.0f);
			game_over = true;
		}
	}
/*
	if (sniped_destroyed)
	{
		AudioMessage("isdf0446.wav");//(manson) the sniped ship is destroyed!
		FailMission(GetTime() + 7.0f);
		game_over = true;
	}
*/
}

///////////////////////////////////////////////////////////
//}
///////////////////////////////////////////////////////////

	
}
