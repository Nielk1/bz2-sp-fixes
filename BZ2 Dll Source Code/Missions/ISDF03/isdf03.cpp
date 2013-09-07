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
		ON_HOLD,
		start_done, briefing_message, in_combat, john_injured, john_full_health,
		john_low_ammo, player_lost, shab_leave_base, shab_to_building, shab_at_building,
		shab_outside, enter_building, search_message, ship_destroyed, tech_found, shab_inside,
		john_inside, game_over, complain1, complain2, start_check, at_check1, at_check2, at_check3,
		at_check4, hauler_move, complain_message, wait_there_message, stop_it_message, hauler_message,
		back_in, shab_dead, suspend_death, go_to_tunnel, shab_through, hauler_swap, shab_at_extank,
		shab_tech_comment, shab_at_tech, mayday_message, respond1, respond2, respond3, respond4, respond5, to_comm,
		tunnel_to_comm, reroute1, reroute2, reroute3, reroute_cbunk, cbunk_message1,
		cbunk_message2, cbunk_message3, cbunk_message4,
		
		first_spawn, start_attack1, hauler1_for_extank1, go_for_extank2,
		hauler1_return, hauler2_return, hauler_escape, first_h1_chance, first_h2_chance,
		haulers_dead, attack_wave_dead, attack_go, attack_power, haulers_go, braddock_message1, 
		braddock_message2, braddock_message3, truck_message, truck_message2, truck_message3, truck_message4,
		fix_armory_message, get_weapon_message, shab_mayday1, shab_mayday2, shab_mayday3, shab_mayday4,
		the_end, movie_set,tunnel_look,shab_whatever,at_tunnel,player_in_tank,john_in_ship,
		remove_shab,nav_alive,cbunk_message5,finish_message,power_up_alive,prep_truck,
		armory_message1,armory_message2,armory_message3,shab_return,shab_home,endbrad_message,
		hauler1_at_check1,hauler2_at_check1,hauler1_at_base,hauler2_at_base,pickup1,pickup2,
		scion1_defend,scion2_defend,change_look,fire_message,disconnect,wadadilly,tank_message,
		clear_tank,doo,weapon_look,new_orders,set_brad_time,
		extra_spawn,extras_dead,extra1_dead,extra2_dead,extra_attack,power_hit,first_tank_check,
		go_on_shab,hauler1_escape,hauler2_escape,camera1,nav_otf,blah1,blah2,sweet_nothings,
		service_help,scion3_move,scion4_move,brad_warning,get_this_done,
		b_last;

	// floats
	float
		f_first,
		briefing_time, player_check, player_lost_time, return_message, move_out_time,
		wait_time, check_john_time, ship_destroyed_time, tech_check, stop_check,
		shab_check, shab_message_time, mayday_message_time,

		hauler_time, escape_check1, wave1_time, wave2_time, wave3_time, wave4_time,
		attack_check, escape_check2, braddock_time, truck_message_time,
		movie_start_time,hop_time,remove_time,looky_time,fire_reset,new_wave_time,
		power_fire_reset,brad_time,movie_time,nav_otf_time,last_fucking_time,
		f_last;

	// handles
	Handle
		h_first,
		player, player_ship, shabayev, truck, shab,
		scion1, scion2, scion3, scion4, scion5, scion6, hauler1, hauler2, hauler3,
		power1, power2, tech_power,
		armory, tech_center, tech_hanger,
		startbase_cbunk, endbase_cbunk, field_cbunk,
		stranded1, stranded2,
		building_tall, building_short,
		talk, nav1, audmsg,speak,
		friend1, friend2,
		ex_tank1,ex_tank2, ex_tank3,
		shab2,
		miller, simms,power_up,dead_tank,
		extra1,extra2,sdrop,escape_tug,
		pilot,
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
	start_done = false;
	briefing_message = false;
	in_combat = false;
	john_injured = false;
	john_full_health = false;
	john_low_ammo = false;
	player_lost = false;
	shab_leave_base = false;
	shab_to_building = false;
	shab_at_building = false;
	shab_outside = false;
	enter_building = false;
	search_message = false;
	ship_destroyed = false;
	tech_found = false;
	shab_inside = false;
	john_inside = false;
	game_over = false;
	complain1 = false;
	complain2 = false;
	complain_message = false;
	start_check = false;
	at_check1 = false;
	at_check2 = false;
	at_check3 = false;
	at_check4 = false;
	hauler_move = false;
	wait_there_message = false;
	stop_it_message = false;
	hauler_message = false;
	back_in = false;
	shab_dead = false;
	suspend_death = false;
	go_to_tunnel = false;
	shab_through = false;
	hauler_swap = false;
	shab_at_extank = false;
	shab_tech_comment = false;
	shab_at_tech = false;
	mayday_message = false;
	respond1 = false;
	respond2 = false;
	respond3 = false;
	respond4 = false;
	respond5 = false;
	to_comm = false;
	tunnel_to_comm = false;
	reroute1 = false;
	reroute2 = false;
	reroute3 = false;
	reroute_cbunk = false;
	cbunk_message1 = false;
	cbunk_message2 = false;
	cbunk_message3 = false;
	cbunk_message4 = false;
	cbunk_message5 = false;
	pickup1 = false;
	pickup2 = false;

	first_spawn = false;
	start_attack1 = false;
	hauler1_for_extank1 = false;
	go_for_extank2 = false;
	hauler1_at_check1 = false;
	hauler2_at_check1 = false;
	hauler1_at_base = false;
	hauler2_at_base = false;
	hauler1_return = false;
	hauler2_return = false;
	hauler_escape = false;
	first_h1_chance = false;
	first_h2_chance = false;
	haulers_dead = true;
	attack_wave_dead = true;
	attack_go = false;
	attack_power = false;
	haulers_go = false;
	braddock_message1 = false;
	braddock_message2 = false;
	braddock_message3 = false;
	truck_message = false;
	truck_message2 = false;
	truck_message3 = false;
	truck_message4 = false;
	fix_armory_message = false;
	get_weapon_message = false;
	shab_mayday1 = false;
	shab_mayday2 = false;
	shab_mayday3 = false;
	shab_mayday4 = false;
	the_end = false;
	movie_set = false;
	tunnel_look = false;
	shab_whatever = false;
	at_tunnel = false;
	player_in_tank = false;
	john_in_ship = true;
	remove_shab = false;
	nav_alive = false;
	finish_message = false;
	power_up_alive = false;
	prep_truck = false;
	armory_message1 = false;
	armory_message2 = false;
	armory_message3 = false;
	shab_return = false;
	shab_home = false;
	endbrad_message = false;
	scion1_defend = false;
	scion2_defend = false;
	change_look = false;
	fire_message = false;
	disconnect = false;
	wadadilly = false;
	tank_message = false;
	clear_tank = false;
	doo = false;
	weapon_look = false;
	extra_spawn = false; extras_dead = false; extra1_dead = false;
	extra2_dead = false; extra_attack = false;
	new_orders = false;
	power_hit = false;
	first_tank_check = false;set_brad_time = false;
	go_on_shab = false;
	hauler1_escape = false; hauler2_escape = false;
	camera1 = false; nav_otf = false;
	blah1 = false; blah2 = false; 
	sweet_nothings = false;
	service_help = false;
	scion3_move = false; scion4_move = false;
	brad_warning = true;get_this_done = false;

//  floats
	briefing_time = 1.0f;
	player_check = 1.0f;
	last_fucking_time = 999999.9f;
	player_lost_time = 999999.9f;
	return_message = 999999.9f;
	move_out_time = 999999.9f;
	wait_time = 999999.9f;
	check_john_time = 999999.9f;
	ship_destroyed_time = 999999.9f;
	tech_check = 1.0f;
	stop_check = 999999.9f;
	shab_check = 999999.9f;
	shab_message_time = 999999.9f;
	mayday_message_time = 999999.9f;

	hauler_time = 999999.9f;
	escape_check1 = 999999.9f;
	wave1_time = 999999.9f;
	wave2_time = 999999.9f;
	wave3_time = 999999.9f;
	wave4_time = 999999.9f;
	attack_check = 999999.9f;
	escape_check2 = 999999.9f;
	braddock_time = 999999.9f;
	truck_message_time = 999999.9f;
	movie_start_time = 999999.9f;
	hop_time = 999999.9f;
	remove_time = 999999.9f;
	looky_time = 999999.9f;
	fire_reset = 999999.9f;
	new_wave_time = 999999.9f;
	power_fire_reset = 999999.9f;
	brad_time = 999999.9f;
	movie_time = 999999.9f;
	nav_otf_time = 999999.9f;
	

//  handles
	player = GetPlayerHandle();
	player_ship = GetHandle("player_ship");
	shabayev = GetHandle("shabayev");
	truck = GetHandle("truck");
	power1 = GetHandle("power1");
//	power2 = GetHandle("power2");
//	tech_power = GetHandle("tech_power");
	tech_hanger = GetHandle("tech_hanger");
	armory = GetHandle("armory");
	tech_center = GetHandle("tech_center");
	//startbase_cbunk = GetHandle("startbase_cbunk");
	endbase_cbunk = GetHandle("endbase_cbunk");
	field_cbunk = GetHandle("field_cbunk");
	dead_tank = GetHandle("dead_tank");
	sdrop = GetHandle("sdrop");
	escape_tug = NULL;
	scion1 = NULL;
	scion2 = NULL;
	scion3 = NULL;
	scion4 = NULL;
	scion5 = NULL;
	scion6 = NULL;
	hauler1 = GetHandle("hauler1");
	hauler2 = NULL;
	hauler3 = NULL;
	stranded1 = NULL;
	stranded2 = NULL;
	shab = NULL;
	ex_tank1 = GetHandle("ex_tank1");
	ex_tank2 = GetHandle("ex_tank2");
	ex_tank3 = NULL;
	talk = 0;
	audmsg = 0;
	speak = 0;
	nav1 = NULL;
	friend1 = NULL;
	friend2 = NULL;
	shab2 = NULL;
	miller = NULL;
	simms = NULL;
	power_up = NULL;
	extra1 = NULL;
	extra2 = NULL;
	pilot = NULL;

//  integers


}

void Misn04Mission::AddObject(Handle h)
{
	char ODFName[64];
	GetObjInfo(h, Get_CFG, ODFName);

	if ((shab == NULL) && (IsOdf2(h,"ispilo")))
	{
		if (h != player)
		{
			shab = h;
			suspend_death = true;
		}
	}
	else if ((cbunk_message3) && (!john_in_ship) && (nav1 == NULL) && (IsOdf2(h,"ibnav")))
	{
		nav1 = h;
		nav_alive = true;
	}
	else if ((power_up == NULL) && (IsOdf2(h,"apshdw")))
	{
		power_up = h;
		power_up_alive = true;
	}
	else if (IsOdf2(h,"fspilo"))
	{
		pilot = h;
		Damage(pilot,100);
		//RemoveObject(pilot);	
	}	
}

void Misn04Mission::Execute(void)
{
/*
	Here is where you put what happens every frame.  
*/

	player = GetPlayerHandle();

	char tempstr[128];

///////////////////////////////////////////////////////////////////////////
/*
if (!start_done)
{
	hauler2 = BuildObject("fvtug3",2,"final_check");
	escape_check1 = GetTime() + 5.0f;
	shab_leave_base = true;
	hauler2_return = true;
	start_done = true;
}
*/

if (!ON_HOLD)
{
///////////////////////////////////////////////////////////////////////////

	// this is keeping the armory around

	if ((IsAround(armory)) && (GetCurHealth(armory) < 100))
	{
		SetCurHealth(armory,100);
	}
	////////////////////////////////////////////


	// this is keeping the relics around

	if ((IsAround(ex_tank1)) && (GetCurHealth(ex_tank1) < 2000))
	{
		SetCurHealth(ex_tank1,2000);
	}

	if ((IsAround(ex_tank2)) && (GetCurHealth(ex_tank2) < 2000))
	{
		SetCurHealth(ex_tank2,2000);
	}
	////////////////////////////////////////////

	
	// this is checking to see what vehicle the player is in

	char ODFName[64];
	GetObjInfo(player, Get_CFG, ODFName);

	if (IsOdf2(player,"ivtank"))
	{
		first_tank_check = true;
		player_in_tank = true;
	}
	else
	{
		player_in_tank = false;
	}


	if ((IsOdf2(player,"ivplysct")) || (IsOdf2(player,"ivtank")))
	{
		john_in_ship = true;
	}
	else
	{
		john_in_ship = false;
	}
	////////////////////////////////////////////


	// this is hopefully going to objectify the power plant

	if (IsAround(power1))
	{
		if (!power_hit)
		{
			if (GetTime() - GetLastEnemyShot(power1) < .2f)
			{
				SetObjectiveOn(power1);
				TranslateString2(tempstr, sizeof(tempstr), "Mission0301");  // Power Gen. Damaged

				SetObjectiveName(power1, tempstr);
				power_fire_reset = GetTime() + 10.0f;
				power_hit = true;
			}
		}
	}

	if ((power_hit) && (fire_reset < GetTime()))
	{
		power_fire_reset = GetTime() + 999999.9f;
		SetObjectiveOn(power1);
		TranslateString2(tempstr, sizeof(tempstr), "Mission0302");  // Power Gen. Damaged

		SetObjectiveName(power1, tempstr);
		power_hit = false;
	}
	////////////////////////////////////////////



	// this is checking to make sure the player does not attack shabayev

	if (!in_combat)
	{
		if ((!fire_message) && (IsAlive(shabayev)))
		{
			if (GetTime() - GetLastFriendShot(shabayev) < .2f)
			{
				AudioMessage("ff01.wav"); // (shab) watch your firing!
				fire_reset = GetTime() + 2.f;
				fire_message = true;
			}
		}
	}

	if ((fire_message) && (fire_reset < GetTime()))
	{
		fire_reset = GetTime() + 999999.9f;
		fire_message = false;
	}
	////////////////////////////////////////////


	// this is checking the condition of the player

	if ((IsAlive(player)) && (john_in_ship) && (!john_injured))
	{
		if (GetCurHealth(player) < 500)
		{
			john_injured = true;
			john_full_health = false;
		}
	}


	if ((IsAlive(player)) && (john_in_ship) && (john_injured))
	{
		if (GetCurHealth(player) > 1700)
		{
			john_injured = false;
		}
	}
	////////////////////////////////////////////


/*
	if ((IsAlive(player)) && (john_in_ship) && (!john_low_ammo))
	{
		if (GetCurAmmo(player) < 200)
		{
			john_low_ammo = true;
		}
	}


	if ((IsAlive(player)) && (john_in_ship) && (john_low_ammo))
	{
		if (GetCurAmmo(player) > 700)
		{
			john_low_ammo = false;
		}
	}
*/

	if ((!john_injured) && (!john_low_ammo))
	{
		john_full_health = true;
	}


// checking to see of the player is lost code

/*
if (IsAlive(player))
{
	if ((!player_lost) && (player_check < GetTime()))
	{
		player_check = GetTime() + 1.5f;


		if (GetDistance(shabayev,player) > 500.0f)
		{
			player_check = GetTime() + 1.5f;
			player_lost_time = GetTime() + 120.0f;
			return_message = false;
			player_lost = true;
		}
	}


	// when the player returns to shab
	if ((player_lost) && (player_check < GetTime()))
	{
		player_check = GetTime() + 1.5f;


		if (GetDistance(shabayev,player) < 150.0f)
		{
			player_lost = false;
		}
	}


	// if he is told to return and doesn't
	if ((!return_message) && (player_lost) && (player_lost_time < GetTime()))
	{
		AudioMessage("wohoo.wav"); // (shab) 
		player_check = GetTime() + 1.5f;
		player_lost_time = GetTime() + 300.0f;
		return_message = true;
	}
}
*/


	if (!start_done)
	{
		//SetColorFade(1,0.5f,RGBA_MAKE(0, 0, 0, 255));

		SetPerceivedTeam(ex_tank1,2);
		SetPerceivedTeam(ex_tank2,2);
		SetObjectiveOff(hauler1);
		SetAnimation(sdrop,"open",1);
		SetAvoidType(shabayev,0);
		Pickup(hauler1,ex_tank1);
		SetGroup(shabayev,-1);
		LookAt(shabayev,player);
		SetObjectiveOn(shabayev);
		SetObjectiveName(shabayev,"Cmd. Shabayev");
		start_done = true;
	}


	// this makes the Scion Hauler stay still until I'm ready

	if ((start_done) && (!hauler_move))
	{
		if (HasCargo(hauler1))
		{
			Stop(hauler1);
		}
	}
	////////////////////////////////////////////


// this is where I start the mission

if ((!shab_leave_base) && (IsAlive(player)))
{
	// this is shabs opening biefing

	if ((!briefing_message) && (briefing_time < GetTime()))
	{
		talk = AudioMessage("isdf0301.wav"); // (shab) search the tunnels
		move_out_time = GetTime() + 3.0f;
		check_john_time = GetTime() + 240.0f;
		briefing_message = true;
	}
	///////////////////////////////////////////

	
	// this is shab looking at the tunnel during opening briefing

	if ((briefing_message) && (!tunnel_look) && (move_out_time < GetTime()))
	{
		LookAt(shabayev,tech_center);
		tunnel_look = true;
	}
	///////////////////////////////////////////


	// checking to see if the player is carrying out his orders

	if (!hauler_move)
	{
		if ((briefing_message) && (!search_message) && (check_john_time < GetTime()))
		{
			ClearObjectives();
			AddObjective("isdf0301.otf", WHITE);
			check_john_time = GetTime() + 240.0f;
			AudioMessage("isdf0302.wav"); // (shab) Have you checked the tunnels john?
			search_message = true;
		}
	}
	////////////////////////////////////////////
	
	
	// this is sending shab to the tall building

	if ((briefing_message) && (!at_check3) && (!shab_to_building) && (IsAudioMessageDone(talk)))
	{
		ClearObjectives();
		AddObjective("isdf0301.otf", WHITE);
		Goto(shabayev,"building_point");
		shab_to_building = true;
	}
	////////////////////////////////////////////


	// shab reached the tall building

	if ((shab_to_building) && (!shab_at_building) && (GetDistance(shabayev,"building_point") < 50.0f))
	{
		LookAt(shabayev,player);
		wait_time = GetTime() + 3.0f;
		shab_at_building = true;
	}
	////////////////////////////////////////////

/*
	// this is shabayev compaining if the player does not follow her orders

	if (!complain_message)
	{
		if (complain1)
		{
			//TriggerAnimation(shabayev,""); // this is where I might trigger an animation of something
			complain_message = true;
		}

		if (complain2)
		{
			ClearObjectives();
			AddObjective("isdf0301.otf", WHITE);
			AudioMessage("isdf0303.wav"); // (shab) I ordered you to check out the tunnels john - I can check out the buildings
			complain_message = true;
		}
	}
	////////////////////////////////////////////
*/
	
// this is the first hauler encounter code

	// first I have to make sure the player is in the tunnels

	if ((briefing_message) && (!at_check4))
	{
		if (InBuilding(player))
		{
/*			if ((!start_check) && (GetDistance(player,"check_start1") < 8.0f))
			{
				start_check = true;
			}

			if ((!start_check) && (GetDistance(player,"check_start2") < 8.0f))
			{
				start_check = true;
			}

			if ((start_check) && (!at_check1) && (GetDistance(player,"check1") < 8.0f))
			{
				at_check1 = true;
			}

			if ((at_check1) && (!at_check2) && (GetDistance(player,"check2") < 8.0f))
			{
				at_check2 = true;
			}
*/
			if (/*(at_check2) && (!at_check3) && */(GetDistance(player,"check3") < 12.0f))
			{
				at_check3 = true;
			}

			if ((at_check3) && (!at_check4) && (GetDistance(player,"check4") < 8.0f))
			{
				at_check4 = true;
			}
			////////////////////////////////////////////


			// now *in theory* the player is in the tunnel and sees the hauler

			if ((at_check3)/*(start_check)*/ && (!hauler_move))
			{
				if (IsAlive(hauler1))
				{
					stop_check = GetTime() + 1.0f;
					Retreat(hauler1,"haulerout_path1");
					hauler_move = true;
				}	
			}
			////////////////////////////////////////////
		}
	}


	// this is the code that make shab comment on the hauler

	if (!hauler_message)
	{
		if (at_check3)
		{
			ClearObjectives();
			AddObjective("isdf0301.otf", WHITE);
			AddObjective("isdf0302.otf", WHITE);
			AudioMessage("isdf0304.wav");// (shab) I'm picking up something to the north of you - I'm on my way!
			hauler_message = true;
		}
	}
	////////////////////////////////////////////


	// this is the code when the player reached the tech_center

	if ((!tech_found) && (tech_check < GetTime()))
	{
		tech_check = GetTime() + 1.0f;


		if (GetDistance(player,tech_center) < 80.0f)
		{
			tech_found = true;
		}
	}


	if ((tech_found) && (!hauler_move) && (!wait_there_message))
	{
		AudioMessage("isdf0305.wav"); // (shab) I've never seen a building like that one - wait there, I'm coming over
		at_check3 = true;
		wait_there_message = true;
	}
	////////////////////////////////////////////


	// sending shab to tunnel

	if ((at_check3) && (!go_to_tunnel))
	{
		SetObjectiveOn(shabayev);
		SetObjectiveName(shabayev,"Cmd. Shabayev");
		Retreat(shabayev,"tunnel_start");
		//Goto(shabayev,"tunnel_path1",1);
		shab_check = GetTime() + 1.0f;
		go_to_tunnel = true;
	}
	////////////////////////////////////////////


	// sending shab somewhere when she exits tunnel

	if ((go_to_tunnel) && (!shab_through) && (shab_check < GetTime()))
	{
		shab_check = GetTime() + 1.0f;


		if ((!at_tunnel) && (GetDistance(shabayev,"tunnel_start") < 30.0f))
		{
			Retreat(shabayev,"tunnel_path1");
			at_tunnel = true;
		}


		if ((at_tunnel) && (GetDistance(shabayev,"shab_check1") < 55.0f))
		{
			if (IsAlive(hauler1))
			{
				if (!stop_it_message)
				{
					ClearObjectives();
					AddObjective("isdf0302.otf", GREEN);
					AddObjective("isdf0303.otf", WHITE);
					AudioMessage("isdf0306.wav"); // (shab) stop that thing - don't let it get away
					stop_it_message = true;
				}

				Attack(shabayev,hauler1);
				shab_through = true;
			}
			else if ((hauler_swap) && (!respond3))
			{
				Goto(shabayev,ex_tank1);
				shab_through = true;
			}
		}
	}
	////////////////////////////////////////////


	// shab telling john to stop the hauler

	if ((hauler_move) && (!stop_it_message) && (stop_check < GetTime()))
	{
		stop_check = GetTime() + 0.5f;

		if ((IsAlive(hauler1)) && (GetDistance(hauler1,"hauler_check1") < 90.0f))
		{
			ClearObjectives();
			AddObjective("isdf0302.otf", GREEN);
			AddObjective("isdf0303.otf", WHITE);
			AudioMessage("isdf0306.wav"); // (shab) stop that thing - don't let it get away
			stop_it_message = true;
		}
	}
	////////////////////////////////////////////


	// this is keeping the hauler alive just long enouph to get out of the tunnel
	
	if (!stop_it_message)
	{
		if (GetCurHealth(hauler1) < 20)
		{
			SetCurHealth(hauler1,20);
		}
	}
	////////////////////////////////////////////


	// this is temp code that spawns in the experimental tank when the hauler is killed

	if ((!IsAround(hauler1)) && (!hauler_swap))
	{
		ClearObjectives();
		AddObjective("isdf0303.otf", GREEN);

		if ((!shab_through) && (!respond3))
		{
			AudioMessage("isdf0307.wav"); // (shab) good job john - stay there I'm on my way
			Goto(shabayev,ex_tank1);
		}
		else if (!respond3)
		{
			Goto(shabayev,ex_tank1);
		}

		hauler_swap = true;
	}
	////////////////////////////////////////////


	// this is when shab reaches the ex_tank

	if ((hauler_swap) && (!shab_at_extank))
	{
		if ((hauler_swap) && (GetDistance(shabayev,ex_tank1) < 30.0f))
		{
			LookAt(shabayev,ex_tank1);
			talk = AudioMessage("isdf0308.wav"); // (shab) whatever these are they are obviously interested in us
			shab_message_time = GetTime() + 10.0f;
			shab_at_extank = true;
		}
	}
	////////////////////////////////////////////


	// shab goes to the tech_center

	if ((shab_at_extank) && (!shab_tech_comment) && (IsAudioMessageDone(talk)))
	{
		Goto(shabayev,tech_center);
		AudioMessage("isdf0309a.wav"); // (shab) I've never seen this buidling before either - Looks like weapons storage	
		shab_message_time = GetTime() + 1.0f;  //I dont know what isdf was doing here but this was no "outpost"
		mayday_message_time  = GetTime() + 15.0f; 
		braddock_time = GetTime() + 10.0f;
		shab_tech_comment = true;
	}
	////////////////////////////////////////////


	// shes at tech center

	if ((!braddock_message1) && (shab_tech_comment) && (!shab_at_tech) && (shab_message_time < GetTime()))
	{
		shab_message_time = GetTime() + 1.0f;


		if (GetDistance(shabayev,tech_center) < 70.0f)
		{
			LookAt(shabayev,tech_center);
			shab_at_tech = true;
		}
	}
	////////////////////////////////////////////


	// this makes shab look at the weapons storage

	if ((!weapon_look) && (shab_at_tech))
	{
		LookAt(shabayev,tech_hanger);
		weapon_look = true;
	}
	////////////////////////////////////////////
	

	// this is the mayday message code

	if ((shab_at_tech) && (!mayday_message) && (braddock_time < GetTime()))
	{
		LookAt(shabayev,player);
		audmsg = AudioMessage("isdf0325b.wav"); // (miller) "mayday"
		mayday_message_time  = GetTime() + 10.0f; 
		mayday_message = true;
	}

/*
	// shab responds

	if ((mayday_message) && (!respond1) && (IsAudioMessageDone(audmsg)))
	{
		audmsg = AudioMessage("isdf0314.wav"); // (shab) copy - barely go ahead
		mayday_message_time  = GetTime() + 10.0f; 
		respond1 = true;
	}


	if ((respond1) && (!respond2) && (IsAudioMessageDone(audmsg)))
	{
		audmsg = AudioMessage("isdf0325.wav"); // (miller) The outpost come under heavy fire -we had to evac Can you assist!
		mayday_message_time  = GetTime() + 10.0f; 
		respond2 = true;
	}
*/
	
	if ((mayday_message) && (!respond3) && (IsAudioMessageDone(audmsg)))
	{
		audmsg = AudioMessage("isdf0326.wav"); // (shab) Can you transmit location?
		mayday_message_time  = GetTime() + 10.0f; 
		respond3 = true;
	}


	if ((respond3) && (!respond4) && (IsAudioMessageDone(audmsg)))
	{
		audmsg = AudioMessage("isdf0315.wav"); // (miller) negative?
		mayday_message_time  = GetTime() + 10.0f; 
		respond4 = true;
	}


	if ((respond4) && (!respond5) && (IsAudioMessageDone(audmsg)))
	{
		audmsg = AudioMessage("isdf0316.wav"); // (shab) damn - follow me!
		mayday_message_time  = GetTime() + 10.0f; 
		respond5 = true;
	}
	
	
	if ((respond5) && (!to_comm) && (IsAudioMessageDone(audmsg)))
	{
		ClearObjectives();
		AddObjective("isdf0304.otf", WHITE);
		//Goto(shabayev,"buba_point");
		Goto(shabayev,"tunnel_pathz"); // NEW
		mayday_message_time = GetTime() + 0.1f; 
		tunnel_to_comm = true;
		to_comm = true;
	}
	////////////////////////////////////////////


	// this shab heading back under the tunnel

	if ((tunnel_to_comm) && (!reroute1))
	{
		//mayday_message_time  = GetTime() + 1.0f; 

		//if (GetDistance(shabayev,"buba_point") < 20.0f)
		if (GetDistance(shabayev,"check2") < 8.0f)
		{
			Goto(shabayev,"check_start2");
			mayday_message_time = GetTime() + 1.0f; 
			//reroute2 = true;
			reroute2 = true;
			reroute1 = true;
		}
	}
	////////////////////////////////////////////


	// this is getting her to go into the tunnel again
	
	if ((reroute1) && (!reroute2) && (mayday_message_time < GetTime()))
	{
		//mayday_message_time  = GetTime() + 0.5f; 


		if (GetDistance(shabayev,"tunnel_point1") < 8.0f)
		{
			Goto(shabayev,"check_start2");
			mayday_message_time = GetTime() + 1.0f; 
			reroute2 = true;
		}
	}
	////////////////////////////////////////////


	if ((reroute2) && (!reroute3)/* && (mayday_message_time < GetTime())*/)
	{
		//mayday_message_time  = GetTime() + 1.0f; 


		if (GetDistance(shabayev,"check_start2") < 40.0f)
		{
			Goto(shabayev,"bunker_point1");
			mayday_message_time = GetTime() + 1.0f; 
			AudioMessage("isdf0327.wav"); //(shab) I hope those things haven't taken out the satellites!
			reroute3 = true;
		}
	}


	if ((!reroute_cbunk) && (reroute3) && (mayday_message_time < GetTime()))
	{
		//mayday_message_time  = GetTime() + 0.5f; 


		if (GetDistance(shabayev,"bunker_point1") < 40.0f)
		{
			Goto(shabayev,endbase_cbunk);
			mayday_message_time = GetTime() + 1.0f; 
			reroute_cbunk = true;
		}
	}


	if ((!reroute_cbunk) && (!reroute3) && (reroute1) && (GetCurrentCommand(shabayev) == CMD_NONE))
	{
		Goto(shabayev,endbase_cbunk);
		mayday_message_time = GetTime() + 1.0f; 
		reroute_cbunk = true;
	}


	// this is an alternative if i cannot get shab back in the tunnel successfully
/*
	if ((respond3) && (!to_comm) && (mayday_message_time < GetTime()))
	{
		Goto(shabayev,"bunker_path1");
		mayday_message_time = GetTime() + 1.0f; 
		outside_to_comm = true;
		to_comm = true;
	}

	
	if ((outside_to_comm) && (!reroute_cbunk) && (mayday_message_time < GetTime()))
	{
		mayday_message_time  = GetTime() + 1.0f; 


		if (GetDistance(shabayev,"bunker_point1") < 30.0f)
		{
			Goto(shabayev,endbase_cbunk);
			mayday_message_time = GetTime() + 1.0f; 
			reroute_cbunk = true;
		}
	}

*/
	

	if((tunnel_to_comm) && (!reroute3) && (GetDistance(shabayev,endbase_cbunk) < 250.0f))
	{
		reroute3 = true;
		Goto(shabayev,endbase_cbunk);
		mayday_message_time = GetTime() + 1.0f; 
		reroute_cbunk = true;
	}

#if 0
	if((!cbunk_message1) && (!player_lost) && (GetDistance(shabayev,endbase_cbunk) < 50.0f))
	{
		reroute_cbunk = true;
	}
#endif

	// now shab is at the cbunk and tells john to go inside
	if ((reroute_cbunk) && (!cbunk_message1) && (mayday_message_time < GetTime()))
	{
		mayday_message_time  = GetTime() + 1.0f; 


		if ((!player_lost) && (GetDistance(shabayev,endbase_cbunk) < 50.0f))
		{
			LookAt(shabayev,player);
			ClearObjectives();
			AddObjective("isdf0305.otf", WHITE);
			talk = AudioMessage("isdf0317.wav"); // (shab) I'm going to need you to find them for me!
			mayday_message_time = GetTime() + 1.0f; 
			cbunk_message1 = true;
		}		
	}


	if ((cbunk_message1) && (!cbunk_message2) && (!john_in_ship)) 
	{
		StopAudioMessage(talk);
		talk = AudioMessage("isdf0318.wav"); // (shab) head into the bunker!
		cbunk_message2 = true;
	}
	////////////////////////////////////////////


	// this is the code for when the player enters the comm bunker

	if ((cbunk_message2) && (!cbunk_message3)  && (GetDistance(player,endbase_cbunk) < 10.0f))
	{
		if (InBuilding(player))
		{


			talk = AudioMessage("isdf0319.wav"); // (shab) Now move to the map terminal. When you point your reticle at it you will notice... push space bar to interface
			ClearObjectives();
			AddObjective("isdf0306.otf", GREEN);
			AddObjective("isdf0307.otf", WHITE);
			
			// spawing in the distressed units
			miller = BuildObject("ivscout",1,"miller_spawn1");
			simms = BuildObject("ivscout",1,"simms_spawn1");
			LookAt(miller,simms);
			LookAt(simms,miller);
			looky_time = GetTime() + 5.0f;

			//Ally(3,2);
			//Ally(2,3);

			cbunk_message3 = true;
		}
	}
	////////////////////////////////////////////


	// this is when the player interfaces with the terminal

	if ((cbunk_message3) && (!cbunk_message4) && (AtTerminal(player) == endbase_cbunk))
	{
		StopAudioMessage(talk);
		talk = AudioMessage("isdf0328.wav"); // (shab) you should see other bunkers - look for players - place nav beacon

		if (IsAround(miller))
		{
			SetObjectiveOn(miller);
			TranslateString2(tempstr, sizeof(tempstr), "Mission0102");  // Red 1

			SetObjectiveName(miller,tempstr);
		}	
		
		// because the player is in the bunker I will spawn in the first attack wave
		scion1 = BuildObject("fvpscou3",2,"base2_espawn1");
		scion2 = BuildObject("fvpscou3",2,"base2_espawn2");
		hauler1 = BuildObject("fvtug3",2,"base2_espawn3");
		hauler2 = BuildObject("fvtug3",2,"base2_espawn4");
		
		SetAvoidType(scion1,0);
		SetAvoidType(scion2,0);
		SetAvoidType(hauler1,0);

		Stop(scion1);
		Stop(scion2);
		Stop(hauler1);

		wave1_time = GetTime() + 180.0f;  // was 180
		wave2_time = GetTime() + 360.0f;	// was 360
		wave3_time = GetTime() + 540.0f;	// was 540
//		wave4_time = GetTime() + 900.0f; 

		haulers_dead = false;
		attack_wave_dead = false;
		first_spawn = true;		
		cbunk_message4 = true;
	}

	
	if ((cbunk_message4) && (!cbunk_message5) && (IsAudioMessageDone(talk)))
	{
		talk = AudioMessage("isdf0330.wav"); // (shab) once you've located them drop a nav. To drop a nav...
		//BuildObject("ibnav",1,"miller_spawn1");// TEMP
		nav_otf_time = GetTime() + 8.0f;
		cbunk_message5 = true;
	}
	////////////////////////////////////////////


	// this is adding the nav otf

	if ((cbunk_message5) && (!nav_otf) && (nav_otf_time < GetTime()))
	{
		ClearObjectives();
		AddObjective("isdf0310.otf", WHITE);
		nav_otf = true;
	}
	////////////////////////////////////////////


	// this is going to have to check to see if the nav beacon exhists

	if ((nav_alive) && (!go_on_shab))
	{
		if ((cbunk_message3) & (GetDistance(miller,nav1) > 200.0f))
		{
			StopAudioMessage(talk);
			talk = AudioMessage("isdf0331.wav"); // (shab) make sure the nav is near the units
			ClearObjectives();
			AddObjective("isdf0310.otf", RED);
			nav1 = NULL;
			nav_alive = false;
		}
		else if (nav_alive)
		{
			ClearObjectives();
			AddObjective("isdf0310.otf", GREEN);
			go_on_shab = true;
		}
	}
	////////////////////////////////////////////


	// this sends her away
	
	if ((go_on_shab) && (!shab_leave_base))
	{
		StopAudioMessage(talk);
		talk = AudioMessage("isdf0320.wav"); // (shab) thanks john - I'm on my way. Stay here and protect thos power plants!
		Goto(shabayev,"leave_path"); // this will have to be the nav
		remove_time = GetTime() + 2.0f;
		SetPerceivedTeam(shabayev,2);
		shab_leave_base = true;
	}
	////////////////////////////////////////////
}

	// this is shab saying stay alive

	if ((!sweet_nothings) && (shab_leave_base) && (IsAudioMessageDone(talk)))
	{
		talk = AudioMessage("isdf0332a.wav"); // (shab) you're a good pilot stay alive out here!
		//AudioMessage("isdf0310.wav");
		last_fucking_time = GetTime() + 15.0f;
		sweet_nothings = true;
	}


	if ((!get_this_done) && (last_fucking_time < GetTime()))
	{
		AudioMessage("isdf0310.wav");

		if (IsAround(ex_tank1))
		{
			SetObjectiveOn(ex_tank1);
			TranslateString2(tempstr, sizeof(tempstr), "Mission0303");  // Hardware
			SetObjectiveName(ex_tank1,tempstr);
		}
		
		if (IsAround(ex_tank2))
		{
			SetObjectiveOn(ex_tank2);
			TranslateString2(tempstr, sizeof(tempstr), "Mission0303");  // Hardware
			SetObjectiveName(ex_tank2,tempstr);
		}

		get_this_done = true;
	}


	// this is checking to see when the player disconnects from the terminal

	if ((cbunk_message4) && (!disconnect) && (AtTerminal(player) == 0)) 
	{
		if (shab_leave_base)
		{
			ClearObjectives();
			AddObjective("isdf0308.otf", WHITE);

			if (IsAround(miller))
			{
				SetObjectiveOff(miller);
			}

			if (IsAround(shabayev))
			{
				SetObjectiveOff(shabayev);
			}
		}
		else if (!wadadilly)
		{
			StopAudioMessage(speak);
			speak = AudioMessage("isdf0328a.wav"); // (shab) where are you going John? I need you to find those men for me
			wadadilly = true;
		}

		disconnect = true;
	}


	if ((!shab_leave_base) && (disconnect) && (AtTerminal(player) == endbase_cbunk))
	{
		wadadilly = false;
		disconnect = false;
	}


	// this is checking to see of the player heads off towards miller and simms

	if (!shab_leave_base)
	{
		if ((cbunk_message3) && (!finish_message) && (john_in_ship))
		{
			StopAudioMessage(speak);
			speak = AudioMessage("isdf0328b.wav"); // (shab) where are you going John? I need you to find those men for me
			finish_message = true;
		}

		if ((finish_message) && (!john_in_ship))
		{
			finish_message = false;
		}
	}
	////////////////////////////////////////////

	// this is the miller and simms code

	if ((cbunk_message3) && (!remove_shab))
	{
		if (looky_time < GetTime())
		{
			looky_time = GetTime() + 5.0f;

			if (!change_look)
			{
				if (IsAround(miller))
				{
					LookAt(miller,player);
				}

				if (IsAround(simms))
				{
					LookAt(simms,field_cbunk);
				}

				change_look = true;
			}
			else
			{
				if (IsAround(miller))
				{
					LookAt(miller,field_cbunk);
				}

				if (IsAround(simms))
				{
					LookAt(simms,player);
				}

				change_look = false;
			}
		}
	}
	////////////////////////////////////////////

	
///////////////////////////////////////////////////////////////////////////
}

/*
if ((!shab_leave_base) && (InBuilding(player)))
{
		scion1 = BuildObject("fvpscou3",2,"base2_espawn1");
		scion2 = BuildObject("fvpscou3",2,"base2_espawn2");
		hauler1 = BuildObject("fvtug3",2,"base2_espawn3");
		//hauler2 = BuildObject("fvtug3",2,"base2_espawn4");

		SetAvoidType(scion1,0);
		SetAvoidType(scion2,0);
		SetAvoidType(hauler1,0);
		
		Stop(scion1);
		Stop(scion2);
		Stop(hauler1);

		wave1_time = GetTime() + 180.0f; // 3 minutes 
		wave2_time = GetTime() + 360.0f; // 6 minutes
		wave3_time = GetTime() + 540.0f; // 9 minutes
//		wave4_time = GetTime() + 900.0f; 

		haulers_dead = false;
		attack_wave_dead = false;
		first_spawn = true;		

	SetObjectiveOn(power1);
	SetObjectiveName(power1,"Power Gen.");
	StopAudioMessage(talk);
	ClearObjectives();
	AddObjective("isdf0308.otf", WHITE);
	talk = AudioMessage("isdf0320.wav"); // (shab) thanks john - I'm on my way. Stay here and protect thos power plants!
	Goto(shabayev,"leave_path"); // this will have to be the nav
	remove_time = GetTime() + 2.0f;
	SetPerceivedTeam(shabayev,2);
	shab_leave_base = true;
}
*/
///////////////////////////////////////////////////////////////////////////


// this is the code after shab leaves the base //////////////////////////


if ((shab_leave_base) && (IsAlive(player)))
{

	// this will remove shab

	if ((!remove_shab) && (remove_time < GetTime()))
	{
		remove_time = GetTime() + 2.0f;


		if (GetDistance(shabayev,player) > 400.0f)
		{
			RemoveObject(shabayev);
			remove_time = GetTime() + 999999.9f;
			looky_time = GetTime() + 999999.9f;

			if (IsAround(miller))
			{
				RemoveObject(miller);
			}

			if (IsAround(simms))
			{
				RemoveObject(simms);
			}

			remove_shab = true;
		}
	}
	////////////////////////////////////////////


	// this is the attack wave code /////

	if ((attack_wave_dead) && (haulers_dead) && (!the_end))
	{
		if (wave1_time < GetTime())// && (GetDistance(player,"base2_espawn1") > 400.0f))
		{
			scion1 = BuildObject("fvpscou3",2,"base2_espawn1");
			scion2 = BuildObject("fvpscou3",2,"base2_espawn2");
			//scion3 = BuildObject("fvtank",2,"base2_espawn3");

			hauler1 = BuildObject("fvtug3",2,"base2_espawn3");
			hauler2 = BuildObject("fvtug3",2,"base2_espawn4");
			
			SetAvoidType(scion1,0);
			SetAvoidType(scion2,0);
			SetAvoidType(hauler1,0);
			SetAvoidType(hauler2,0);

			wave1_time = GetTime() + 999999.9f;
			new_wave_time = GetTime() + 90.0f;
			prep_truck = true;
			haulers_dead = false;
			attack_wave_dead = false;
		}

		if (wave2_time < GetTime())// && (GetDistance(player,"base2_espawn1") > 400.0f))
		{
			scion1 = BuildObject("fvpscou3",2,"base2_espawn1");
			scion2 = BuildObject("fvpsnt3",2,"base2_espawn2");
			scion3 = BuildObject("fvpsnt3",2,"base_espawn1");
			scion4 = BuildObject("fvpsnt3",2,"base_espawn2");

			hauler1 = BuildObject("fvtug3",2,"base2_espawn3");
			hauler2 = BuildObject("fvtug3",2,"base2_espawn4");
			
			SetAvoidType(scion1,0);
			SetAvoidType(scion2,0);
			SetAvoidType(scion3,0);
			SetAvoidType(scion4,0);
			SetAvoidType(hauler1,0);
			SetAvoidType(hauler2,0);
			
			wave2_time = GetTime() + 999999.9f;
			new_wave_time = GetTime() + 90.0f;
			service_help = false;
			haulers_dead = false;
			attack_wave_dead = false;
		}

		if (wave3_time < GetTime())// && (GetDistance(player,"base2_espawn1") > 400.0f))
		{
			scion1 = BuildObject("fvpsnt3",2,"base2_espawn1");
			scion2 = BuildObject("fvpsnt3",2,"base2_espawn2");
			
			if ((GetDistance(player,"bad_guy1")) > (GetDistance(player,"base_espawn1")))
			{
				scion3 = BuildObject("fvpsnt3",2,"bad_guy1");
				scion4 = BuildObject("fvpsnt3",2,"bad_guy2");
			}
			else
			{
				scion3 = BuildObject("fvpsnt3",2,"base_espawn1");
				scion4 = BuildObject("fvpsnt3",2,"base_espawn2");
			}

			hauler1 = BuildObject("fvtug3",2,"base2_espawn3");
			hauler2 = BuildObject("fvtug3",2,"base2_espawn4");

			SetAvoidType(scion1,0);
			SetAvoidType(scion2,0);
			SetAvoidType(scion3,0);
			SetAvoidType(scion4,0);
			//SetAvoidType(scion5,0);
			//SetAvoidType(scion6,0);
			SetAvoidType(hauler1,0);
			SetAvoidType(hauler2,0);
			
			wave3_time = GetTime() + 999999.9f;
			new_wave_time = GetTime() + 90.0f;
			service_help = false;
			attack_wave_dead = false;
			haulers_dead = false;
			the_end = true;
		}
	//	if ((wave4_time < GetTime()) && (GetDistance(player,"base2_espawn1") > 400.0f))
	//	{
	//		scion1 = BuildObject("fvtank",2,"base2_espawn1");
	//		scion2 = BuildObject("fvtank",2,"base2_espawn2");
	//		scion3 = BuildObject("fvtank",2,"base2_espawn3");
	//		scion4 = BuildObject("fvtank",2,"base2_espawn4");
	//		scion5 = BuildObject("fvtank",2,"base2_espawn5");
	//		scion6 = BuildObject("fvtank",2,"base2_espawn6");
	//		wave4_time = GetTime() + 999999.9f;
	//		attack_wave_dead = false;
	//	}
	}


	if ((!attack_wave_dead) && (!attack_go))
	{
		if (IsAlive(scion1))
		{
			if (IsAlive(hauler1))
			{
				Follow(scion1,hauler1,0);
			}
			else
			{
				Goto(scion1,"attack_path1",0);
			}
		}
		if (IsAlive(scion2))
		{
			if (IsAlive(hauler2))
			{
				Follow(scion2,hauler2,0);
			}
			else
			{
				Goto(scion2,"attack_path1",0);
			}
		}
		if (IsAlive(scion3))
		{
			Goto(scion3,"bad_guy2_path",0);
		}
		if (IsAlive(scion4))
		{
			Goto(scion4,"bad_guy2_path",0);
		}
		if (IsAlive(scion5))
		{
			Goto(scion5,"bad_guy1_path",0);
		}
		if (IsAlive(scion6))
		{
			Goto(scion6,"bad_guy1_path",0);
		}

		attack_check = GetTime() + 5.0f;
		attack_go = true;
	}


	if ((attack_go) && (!attack_power) && (attack_check < GetTime()))
	{
		attack_check = GetTime() + 5.0f;

		if ((!scion1_defend) && (hauler1_return))
		{
			if ((IsAlive(scion1)) && (IsAlive(hauler1)))
			{
				Follow(scion1,hauler1,0);
				scion1_defend = true;
			}
		}


		if ((!scion2_defend) && (hauler2_return))
		{
			if ((IsAlive(scion2)) && (IsAlive(hauler2)))
			{
				Follow(scion2,hauler2,0);
				scion2_defend = true;
			}
		}


		if (IsAround(power1))
		{
			if (IsAround(scion3))
			{
				if (GetDistance(scion3,power1) < 100.0f)
				{
					Attack(scion3,power1,0);

					if (IsAround(scion4))
					{
						if (IsAlive(truck))
						{
							Attack(scion4,truck,0);
						}
						else
						{
							Attack(scion4,player);
						}
					}

					if (IsAlive(truck))
					{
						if (IsAround(scion5))
						{
							Attack(scion5,truck,0);
						}
						if (IsAround(scion6))
						{
							Attack(scion6,truck,0);
						}
					}
					else
					{
						if (IsAround(scion5))
						{
							Attack(scion5,player);
						}
						if (IsAround(scion6))
						{
							Attack(scion6,player);
						}
					}

					attack_power = true;
				}
			}
			
			else if (IsAround(scion4))
			{
				if (GetDistance(scion4,power1) < 100.0f)
				{
					Attack(scion4,power1,0);

					if (IsAlive(truck))
					{
						if (IsAround(scion5))
						{
							Attack(scion5,truck,0);
						}
						if (IsAround(scion6))
						{
							Attack(scion6,truck,0);
						}
					}
					else
					{
						if (IsAround(scion5))
						{
							Attack(scion5,player);
						}
						if (IsAround(scion6))
						{
							Attack(scion6,player);
						}
					}

					attack_power = true;
				}
			}
			else if (IsAround(scion5))
			{
				if (GetDistance(scion5,power1) < 100.0f)
				{
					Attack(scion5,power1,0);

					if (IsAlive(truck))
					{
						if (IsAround(scion6))
						{
							Attack(scion6,truck,0);
						}
					}
					else
					{
						if (IsAround(scion6))
						{
							Attack(scion6,player);
						}
					}

					attack_power = true;
				}
			}
			else if ((IsAround(scion6)) && (GetDistance(scion6,power1) < 100.0f))
			{
				Attack(scion6,power1,0);
				attack_power = true;
			}
		}
		else if (IsAlive(truck))
		{
			if (IsAround(scion3))
			{
				if (GetDistance(scion3,armory) < 200.0f)
				{
					Attack(scion3,truck,0);

					if (IsAround(scion4))
					{
						Attack(scion4,truck,0);
					}

					if (IsAround(scion5))
					{
						Attack(scion5,player);
					}
					if (IsAround(scion6))
					{
						Attack(scion6,player);
					}

					attack_power = true;
				}
			}
			
			else if (IsAround(scion4))
			{
				if (GetDistance(scion4,armory) < 200.0f)
				{
					Attack(scion4,truck,0);


					if (IsAround(scion5))
					{
						Attack(scion5,player);
					}
					if (IsAround(scion6))
					{
						Attack(scion6,player);
					}

					attack_power = true;
				}
			}
			else if (IsAround(scion5))
			{
				if (GetDistance(scion5,armory) < 200.0f)
				{
					Attack(scion5,truck,0);

					if (IsAround(scion6))
					{
						Attack(scion6,player);
					}

					attack_power = true;
				}
			}
			else if ((IsAround(scion6)) && (GetDistance(scion6,armory) < 200.0f))
			{
				Attack(scion6,truck,0);
				attack_power = true;
			}
		}
	}


	// this is building the extra enemies
/*
	if (!attack_wave_dead)
	{
		if ((!extra_spawn) && (new_wave_time < GetTime()))
		{
			if ((GetDistance(player,"bad_guy1")) > (GetDistance(player,"base_espawn1")))
			{
				extra1 = BuildObject("fvpsnt",2,"bad_guy1");
				extra2 = BuildObject("fvpsnt",2,"bad_guy2");
				SetAvoidType(extra1,0);
				SetAvoidType(extra2,0);
				Retreat(extra1,"bad_guy1_path");
				Follow(extra2,extra1,1);
				new_wave_time = GetTime() + 999999.9f;
			}
			else
			{
				extra1 = BuildObject("fvpsnt",2,"base_espawn1");
				extra2 = BuildObject("fvpsnt",2,"base_espawn2");
				SetAvoidType(extra1,0);
				SetAvoidType(extra2,0);
				Retreat(extra1,"bad_guy2_path");
				Follow(extra2,extra1,1);
				new_wave_time = GetTime() + 999999.9f;
			}
			
			extras_dead = false;
			extra_spawn = true;
		}
	}
	////////////////////////////////////////////


	// this determines when the two extra scoins are dead

	if ((!extras_dead) && (extra_spawn))
	{
		if ((!extra1_dead) && (!IsAlive(extra1)))
		{
			extra1_dead = true;
		}

		if ((!extra2_dead) && (!IsAlive(extra2)))
		{
			extra2_dead = true;
		}

		if (!extra_attack)
		{
			if (!extra1_dead)
			{
				if (IsAround(power1))
				{
					if (GetDistance(extra1,power1) < 40.0f)
					{
						Attack(extra1,power1);

						if (IsAlive(extra2))
						{
							if (IsAlive(truck))
							{
								Attack(extra2,truck);
							}
							else
							{
								Attack(extra2,player);
							}
						}

						extra_attack = true;
					}
				}
				else if (IsAlive(truck))
				{
					if (GetDistance(extra1,armory) < 60.0f)
					{
						Attack(extra2,truck);

						if (IsAlive(extra2))
						{
							Attack(extra2,player);
						}

						extra_attack = true;
					}
				}
				else
				{
					if (GetDistance(extra1,armory) < 60.0f)
					{
						Attack(extra2,player);

						if (IsAlive(extra2))
						{
							Attack(extra2,player);
						}

						extra_attack = true;
					}
				}
			}
			else if (!extra2_dead)
			{
				if (IsAround(power1))
				{
					Attack(extra2,power1);
					extra_attack = true;
				}
				else if (IsAlive(truck))
				{
					Attack(extra2,truck);
					extra_attack = true;
				}
				else
				{
					Attack(extra2,player);
					extra_attack = true;
				}
			}
		}

		if ((extra1_dead) && (extra2_dead))
		{
			extra_spawn = false;
			extra1_dead = false;
			extra2_dead = false;
			extra_attack = false;
			extras_dead = true;
		}
	}
	////////////////////////////////////////////
*/


	// this keeps the scions from looking stupid

	if ((!scion3_move) && (IsAlive(scion3)))
	{
		if (GetCurAmmo(scion3) < 100)
		{
			Attack(scion3,player);
			scion3_move = true;
		}
	}

		
	if ((!scion4_move) && (IsAlive(scion4)))
	{
		if (GetCurAmmo(scion4) < 100)
		{
			if (IsAlive(truck))
			{
				Attack(scion4,truck,0);
				scion4_move = true;
			}
			else
			{
				Attack(scion3,player);
				scion4_move = true;
			}
		}
	}
	////////////////////////////////////////////

		
	// checking to see when the attack waves are dead

	if (!attack_wave_dead)
	{
		if ((!IsAlive(scion1)) && (!IsAlive(scion2)) && (!IsAlive(scion3)) && (!IsAlive(scion4)) && (!IsAlive(scion5)) && (!IsAlive(scion6)))
		{
			attack_check = GetTime() + 999999.9f;

			scion1_defend = false;
			scion2_defend = false;
			attack_go = false;
			attack_power = false;
			scion3_move = false;
			scion4_move = false;
			attack_wave_dead = true;
		}
	}
	////////////////////////////////////////////


	// this is getting the service truck to help

	if ((!service_help) && (attack_wave_dead))
	{
		if ((IsAlive(truck)) && (IsAlive(power1)))
		{
			if (GetCurHealth(power1) < 2500)
			{
				Service(truck,power1,0);
			}
		}

		service_help = true;
	}
	////////////////////////////////////////////



// this is hauler code /////////////////////////////////

	// when they are first built

	if ((!haulers_dead) && (!haulers_go))
	{
		hauler_time = GetTime() + 2.0f;


		if (IsAlive(hauler1))
		{
			if ((GetDistance(hauler1,ex_tank1)) < (GetDistance(hauler1,"hauler_check1")))
			{
				Pickup(hauler1,ex_tank1);

				if (!blah1)
				{
					SetObjectiveOn(hauler1);
					blah1 = true;
				}

				pickup1 = true;

				if (IsAlive(hauler2))
				{
					if ((GetDistance(hauler2,ex_tank2)) < (GetDistance(hauler2,"hauler_check1")))
					{
						Pickup(hauler2,ex_tank2);

						if (!blah2)
						{
							SetObjectiveOn(hauler2);
							blah2 = true;
						}

						pickup2 = true;
					}
					else
					{
						Retreat(hauler2,"haulerin_path2");
						pickup2 = false;
					}
				}
				
				haulers_go = true;
			}
			else
			{
				Retreat(hauler1,"haulerin_path1");
				pickup1 = false;

				if (IsAlive(hauler2))
				{
					if ((GetDistance(hauler2,ex_tank2)) < (GetDistance(hauler2,"hauler_check1")))
					{
						Pickup(hauler2,ex_tank2);

						if (!blah2)
						{
							SetObjectiveOn(hauler2);
							blah2 = true;
						}

						pickup2 = true;
					}
					else
					{
						Retreat(hauler2,"haulerin_path2");
						pickup2 = false;
					}
				}
			}
		}
		else if (IsAlive(hauler2))
		{
			if ((GetDistance(hauler2,ex_tank2)) < (GetDistance(hauler2,"hauler_check1")))
			{
				Pickup(hauler2,ex_tank2);

				if (!blah2)
				{
					SetObjectiveOn(hauler2);
					blah2 = true;
				}

				pickup2 = true;
			}
			else
			{
				Retreat(hauler2,"haulerin_path2");
				pickup2 = false;
			}
		}


		haulers_go = true;
	}
	////////////////////////////////////////////


	// this is making the haulers go for ships when in range

	if ((haulers_go) && (hauler_time < GetTime()))
	{
		hauler_time = GetTime() + 2.0f;


		// this is checkpoint 1

		if ((!pickup1) && (!hauler1_at_check1))
		{
			if ((IsAlive(hauler1)) && (GetDistance(hauler1,"hauler_check1") < 30.0f))
			{
				if ((GetDistance(hauler1,ex_tank1)) < (GetDistance(hauler1,"hauler_check2")))
				{
					Pickup(hauler1,ex_tank1);

					if (!blah1)
					{
						SetObjectiveOn(hauler1);
						blah1 = true;
					}

					pickup1 = true;
				}
				else
				{
					hauler1_at_check1 = true;
				}
			}
		}

		if ((!pickup2) && (!hauler2_at_check1))
		{
			if ((IsAlive(hauler2)) && (GetDistance(hauler2,"hauler_check1") < 30.0f))
			{
				if ((GetDistance(hauler2,ex_tank2)) < (GetDistance(hauler2,"hauler_check2")))
				{
					Pickup(hauler2,ex_tank2);

					if (!blah2)
					{
						SetObjectiveOn(hauler2);
						blah2 = true;
					}

					pickup2 = true;
				}
				else
				{
					hauler2_at_check1 = true;
				}
			}
		}

		// this is checkpoint 2


		if ((!pickup1) && (hauler1_at_check1))
		{
			if ((IsAlive(hauler1)) && (GetDistance(hauler1,"hauler_check2") < 30.0f))
			{
				Pickup(hauler1,ex_tank1);

				if (!blah1)
				{
					SetObjectiveOn(hauler1);
					blah1 = true;
				}

				pickup1 = true;
			}
		}

		if ((!pickup2) && (hauler2_at_check1))
		{
			if ((IsAlive(hauler2)) && (GetDistance(hauler2,"hauler_check2") < 30.0f))
			{
				Pickup(hauler2,ex_tank2);

				if (!blah2)
				{
					SetObjectiveOn(hauler2);
					blah2 = true;
				}

				pickup2 = true;
			}
		}
	}
	////////////////////////////////////////////

	// this is brads first message

	if ((!brad_warning) && ((pickup1) || (pickup2)))
	{
//		audmsg = AudioMessage("isdf0310.wav"); // (braddock) Don't let those enemies get the experimental tanks!
		brad_warning = true;
	}


	// checking to see when they have cargo

	if ((pickup1) && (!hauler1_return))
	{
		if ((IsAlive(hauler1)) && (HasCargo(hauler1)))
		{
			escape_check1 = GetTime() + 5.0f;

			if ((GetDistance(hauler1,"hauler_check1")) > (GetDistance(hauler1,"hauler_check2")))
			{
				Retreat(hauler1,"haulerout_path2");
			}
			else
			{
				Retreat(hauler1,"final_check");
			}

			hauler1_return = true;
		}
	}

	if ((pickup2) && (!hauler2_return))
	{
		if ((IsAlive(hauler2)) && (HasCargo(hauler2)))
		{
			escape_check1 = GetTime() + 5.0f;

			if ((GetDistance(hauler2,"hauler_check1")) > (GetDistance(hauler2,"hauler_check2")))
			{
				Retreat(hauler2,"haulerout_path2");
			}
			else
			{
				Retreat(hauler2,"final_check");
			}

			hauler2_return = true;
		}
	}
	////////////////////////////////////////////
	

	// this determines if the haulers have escaped

	if ((!hauler_escape) && (escape_check1 < GetTime()))
	{
		escape_check1 = GetTime() + 1.0f;


		if ((hauler1_return) && (IsAlive(hauler1)))
		{
			if (GetDistance(hauler1,"final_check") < 30.0f)
			{
				CameraReady();
				Goto(hauler1,"drop_path");
				SetCurHealth(hauler1,1000);
				AudioMessage("isdf0324.wav"); // (Braddock) you allowed my vehicles to fall in enemy hands
				movie_time = GetTime() + 20.0f;
				hauler1_escape = true;
				hauler_escape = true;
			}
		}


		if ((hauler2_return) && (IsAlive(hauler2)))
		{
			if (GetDistance(hauler2,"final_check") < 30.0f)
			{
				CameraReady();
				Goto(hauler2,"drop_path");
				SetCurHealth(hauler2,1000);
				AudioMessage("isdf0324.wav"); // (Braddock) you allowed my vehicles to fall in enemy hands
				movie_time = GetTime() + 20.0f;
				hauler2_escape = true;
				hauler_escape = true;
			}
		}
	}
	////////////////////////////////////////////

	
	// this is checking to see when the hauler gets to the dropship

	if ((!camera1) && (hauler1_escape))
	{
		if (GetDistance(hauler1,"drop_point") < 15.0f)
		{
			SetAnimation(sdrop,"deploy",1);
			camera1 = true;
		}
	}

	// this is going to be the loosing movie

	if  ((!camera1) && (hauler1_escape))
	{
		CameraPath("camera_spawn",500,0,hauler1);
	}
	////////////////////////////////////////////


	// this is checking to see when the hauler gets to the dropship

	if ((!camera1) && (hauler2_escape))
	{
		if (GetDistance(hauler2,"drop_point") < 15.0f)
		{
			SetAnimation(sdrop,"deploy",1);
			camera1 = true;
		}
	}

	// this is going to be the loosing movie

	if  ((!camera1) && (hauler2_escape))
	{
		CameraPath("camera_spawn",500,0,hauler2);
	}
	////////////////////////////////////////////


	if ((!game_over) && (camera1))
	{
		CameraPath("final_check",40,0,sdrop);
	}
	////////////////////////////////////////////


	// if the haulers are killed

	if ((!haulers_dead) && (!IsAlive(hauler1)) && (!IsAlive(hauler2)))
	{
		hauler_time = GetTime() + 999999.9f;
		escape_check1 = GetTime() + 999999.0f;

		hauler1_at_check1 = false;
		hauler2_at_check1 = false;
		pickup1 = false;
		pickup2 = false;
		haulers_go = false;
		hauler1_at_base = false;
		hauler2_at_base = false;
		hauler1_return = false;
		hauler2_return = false;
		first_h1_chance = false;
		first_h2_chance = false;

		haulers_dead = true;
	}
	////////////////////////////////////////////


/*
	// this builds more haulers

	if ((haulers_dead) && (!the_end))
	{
		hauler1 = BuildObject("fvtug3",2,"base2_espawn3");
		hauler2 = BuildObject("fvtug3",2,"base2_espawn4");
		haulers_dead = false;
	}
	////////////////////////////////////////////
*/

	// this is where Braddock contacts the player

	if ((first_spawn) && (!braddock_message1))
	{
		if ((hauler1_return) || (hauler1_return))
		{
			if (IsAround(ex_tank1))
			{
				SetObjectiveOn(ex_tank1);
				TranslateString2(tempstr, sizeof(tempstr), "Mission0303");  // Hardware
				SetObjectiveName(ex_tank1,tempstr);
			}
			
			if (IsAround(ex_tank2))
			{
				SetObjectiveOn(ex_tank2);
				TranslateString2(tempstr, sizeof(tempstr), "Mission0303");  // Hardware
				SetObjectiveName(ex_tank2,tempstr);
			}
				
			//audmsg = AudioMessage("isdf0310.wav"); // (braddock) Don't let those enemies get the experimental tanks!
			braddock_message1 = true;
		}

		if ((!braddock_message1) && (attack_wave_dead) && (haulers_dead))
		{
			if (!set_brad_time)
			{
				brad_time = GetTime() + 3.0f;
				set_brad_time = true;
			}

			if ((set_brad_time) && (brad_time < GetTime()))
			{
				if (IsAround(ex_tank1))
				{
					SetObjectiveOn(ex_tank1);
					TranslateString2(tempstr, sizeof(tempstr), "Mission0303");  // Hardware
					SetObjectiveName(ex_tank1,tempstr);
				}

				if (IsAround(ex_tank2))
				{
					SetObjectiveOn(ex_tank2);
					TranslateString2(tempstr, sizeof(tempstr), "Mission0303");  // Hardware
					SetObjectiveName(ex_tank2,tempstr);
				}
				
//				audmsg = AudioMessage("isdf0310.wav"); // (braddock) Don't let those enemies get the experimental tanks!
				braddock_message1 = true;
			}
		}
	}
	////////////////////////////////////////////


	// this changes the objectives after braddocks message

	if ((!new_orders) && (braddock_message1) && (IsAudioMessageDone(audmsg)))
	{
		ClearObjectives();
		AddObjective("isdf0308a.otf", WHITE);
		new_orders = true;
	}


	// this is the truck telling the player about the armory

	if ((prep_truck) && (attack_wave_dead) && (haulers_dead) && (!armory_message1))
	{
		if (IsAround(truck))
		{
			if (!power_up_alive)
			{
				talk = AudioMessage("isdf0334.wav"); //(truck) with the armory online you can build more weapons
				armory_message1 = true;
			}
		}
	}


	if ((armory_message1) && (!armory_message2) && (IsAudioMessageDone(talk)))
	{
		talk = AudioMessage("isdf0335.wav"); //(truck) select the armory and have it build a missile power-up
		armory_message2 = true;
	}


	if (!power_up_alive)
	{
		if ((armory_message1) && (!armory_message3) && (IsSelected(armory)))
		{
			StopAudioMessage(talk);
			talk = AudioMessage("isdf0336.wav"); //(truck) Now you can have the armory build you a missile
			armory_message3 = true;
		}
	}
	////////////////////////////////////////////


	// this is when the last enemies are destoyed

	if (!game_over)
	{
		if ((!shab_return) && (the_end) && (attack_wave_dead) && (haulers_dead)) //(extras_dead))
		{
			AudioMessage("isdf0338.wav");//(shab) I'm on my way back to you!

			shabayev = BuildObject("ivpscou",1,"shab_spawn");
			miller = BuildObject("ivpscou",1,"miller_spawn2");
			simms = BuildObject("ivpscou",1,"simms_spawn2");

			SetObjectiveOn(shabayev);
			SetObjectiveName(shabayev,"Cmd. Shabayev");

			SetAvoidType(shabayev,0);
			SetAvoidType(miller,0);
			SetAvoidType(simms,0);

			Damage(shabayev,500);
			Damage(miller,1000);
			Damage(simms,1000);
			
			Goto(shabayev,"last_path");
			Follow(miller,shabayev);
			Follow(simms,miller);

			ClearObjectives();
			AddObjective("isdf0309.otf", WHITE);

			shab_return = true;
		}
	}


	if ((shab_return) && (IsAround(armory)) && (!shab_home))
	{
		if (GetDistance(shabayev,armory) < 100.0f)
		{
			if (GetDistance(shabayev,player) < 60.0f)
			{
				speak = AudioMessage("isdf0321.wav");//(shab) I knew you could do it
				LookAt(shabayev,player);
				shab_home = true;
			}
		}
	}


	if ((shab_home) && (!endbrad_message) && (IsAudioMessageDone(speak)))
	{
		AudioMessage("isdf0337.wav"); //(brad) condors are on the way!
		movie_start_time = GetTime() + 9.0f;
		movie_set = true;
		endbrad_message = true;
	}
	////////////////////////////////////////////

	//this is the shab movie of her entering the base followed by the movie of the drop ship landing

}

	// this is if the player's ship gets destroyed

	if ((!IsAround(player_ship)) && (!ship_destroyed))
	{
		ship_destroyed_time = GetTime() + 5.0f;
		ship_destroyed = true;
	}


	if ((!tank_message) && (ship_destroyed) && (ship_destroyed_time < GetTime()))
	{
		if ((IsAlive(truck)) && (IsAround(dead_tank)) && (!first_tank_check))
		{
			AudioMessage("isdf0339.wav"); // (truck) get in the tank!
			SetObjectiveOn(dead_tank);
			TranslateString2(tempstr, sizeof(tempstr), "Mission0304");  // Sabre
			SetObjectiveName(dead_tank,tempstr);
			doo = true;
			tank_message = true;
		}
		else
		{
			tank_message = true;
		}
	}


	if ((!clear_tank) && (doo) && (IsAround(dead_tank)))
	{
		if (player_in_tank)
		{
			SetObjectiveOff(dead_tank);
			clear_tank = true;
		}
	}
	////////////////////////////////////////////



///////////////////////////////////////////////////////////////////////////
//if (!ON_HOLD)
//{
///////////////////////////////////////////////////////////////////////////


// these are the win/loose conditions

if (!game_over)
{
	if ((!remove_shab) && (!shab_outside) && (!IsAlive(shabayev)))
	{
		if (IsAlive(truck))
		{
			AudioMessage("isdf0322.wav"); // (truck) you let shab die
			FailMission(GetTime() + 15.0f);
			game_over = true;
		}
		else
		{
			AudioMessage("isdf0323.wav"); // (Braddock) you let shab die
			FailMission(GetTime() + 15.0f);
			game_over = true;
		}
	}

/*
	if ((suspend_death) && (!IsAround(shab)))
	{
		if (IsAlive(truck))
		{
			AudioMessage("isdf0322.wav"); // (truck) you let shab die
			FailMission(GetTime() + 15.0f);
			game_over = true;
		}
		else
		{
			AudioMessage("isdf0323.wav"); // (Braddock) you let shab die
			FailMission(GetTime() + 15.0f);
			game_over = true;
		}
	}
*/

	if ((hauler_escape) && (!game_over) && (camera1))//(movie_time < GetTime()))
	{
		FailMission(GetTime() + 0.0f);
		game_over = true;
	}


	// this is if the player approaches miller or simms

	if ((cbunk_message3) && (!remove_shab))
	{
		if (!InBuilding(player))
		{
			if (IsAround(miller))
			{
				if (GetDistance(player,miller) < 300.0f)
				{
					AudioMessage("isdf0329a.wav"); // (shab) if you refuse to follow my orders you are dismissed
					FailMission(GetTime() + 15.0f);
					game_over = true;
				}
			}
		}
	}


	// this is the destruction of the power plant

	if (!IsAround(power1))
	{
		ClearObjectives();
		AddObjective("isdf0308.otf", RED);
		FailMission(GetTime() + 10.0f);
		game_over = true;
	}

	
	// movie_set needs to be changed
	if ((movie_set) && (!game_over))
	{
		SucceedMission(GetTime() + 15.0f,"isdf03w1.txt");
		game_over = true;
	}
}

///////////////////////////////////////////////////////////////////////////
//}
///////////////////////////////////////////////////////////////////////////



}
