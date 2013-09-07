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
		start_done,briefing_message,truck_lost,shab_message1,
		find_truck_message, truck_lost_message,follow_player,	
		first_warning, second_warning,recover_message,in_combat,
		at_truck_stop,wrong_message,wrong_person,move_out,
		player_lost, return_message1, truck_following,at_base,	
		caught_up,wait_message,to_shab1, to_builder,at_jammer,
		shab_builder_detect,builder_change,follow_off,jammer_message,
		player_at_builder, jammer_built,builder_morph, builder1_run,
		jammer_dead,scrammbled_message,build_drone, remove_drone,
		drone_to_shab2, drone_to_shab3, drone_to_field,builder1_run2, 
		first_wave_built, first_wave_attack,shab_attack_jammer,
		dead_message,first_over,to_shab2,after_first_message,
		builder1_to_shab2,builder_morph1, builder1_stop, drone_dead,
		show_ready, make_switch,drone_run,part_two,builder_dead,no_show,

		shab_message2, show_over, to_shab2a, shab_message3, temp_spawn,
		start_second_morph,reroute,start_show2,in_range, second_over,
		end_show2, combat2, john_injured, john_full_health, shabayev_injured,
		shab_full_health, john_low_ammo, shab_low_ammo, repair_check1, shab_injured,
		repairs_needed, repair_message1, repair_message2, repair_message3, 
		john_over_shab, shab_over_john, keep_moving_message, on_to_base, truck_wait,
		move_to_center, endbase_detected, hit_hard_message, at_center, game_over,
		all_clear, surprise_spawn, surprise_successful, surprise_attack, last_morph,
		last_attack, truck_message, ship_destroyed, shab_to_ship, shab_get_in, shab_in_ship,
		shab_in_ship1, shab_in_ship2, shab_in_ship3, shab_in_ship4, john_in_ship, dump,
		truck_ready, free_truck, at_base_center, selected_message, make_jammer, jammer_sets,
		come_here,  cheat1, cheat2, dead_now_message, move_on, scion_message, bert,
		return_message, repair_done, at_player, watch_player, shab_to_point, shab_at_point,
		shab_follow_build, at1, at2, at3, reroute1, reroute2, reroute3, jammer2_dead,
		after_second_check, come_here2, shab_at_jam2, scrammbled_message2, scavs_found,
		after_scavs, free_temp, got_it_message, jammer2_dead_message, three_to_go, two_to_go,
		one_to_go, mistake, goose,temp_patrol,temp_change,made_cheat,shab_out,shab_hop_out,
		shab_to_con,shab_in,prep_cons,to_power_spot,base_powered,shab_dead,cons_dead,
		last_wave_dead,shab_find_con,shab_first,truck_explain,plan,plan2,attack_last_turret1,
		on_to_construct,return_to_base,last_turret1_dead,new_prep,startup_over,con_switch,
		attack_last_turret2,turrets_stop,extra_help,service_scout,movie1,firstFrame,
		pole3_switch,pole4_switch,pole5_switch,pole6_switch,pole7_switch,pole8_switch,
		pole9_switch,pole10_switch,pole11_switch,stop_service,shab_switch,

		ON_HOLD,

		b_last;

	// floats
	float
		f_first,message1_time,briefing_time,truck_check,
		find_truck_message_time,wait1_time,move_time,check1_time,
		player_check,player_lost_time,first_warning_time,builder_change_time,
		player_builder_check,jammer_build_time,jammer_message_time,
		builder_run_check,builder_run_time,morphing_time,list_time,
		drone_time, remove_drone_time,dead_jammer_message,
		get_truck_time,combat_check,morph_time,show_ready_time,
		
		encounter1_check, checkpoint2_check, show2_start_time, onto_base_time,
		center_check, safe_check, ship_destroyed_time, shab_check, trucker_time,
		shabalab, fire_check, service_time, look_time, watch_player_time,
		point_check, spawn_time, sue_check,change_time,con_wait,
		pole3_time,pole4_time,pole5_time,pole6_time,pole7_time,pole8_time,pole9_time,pole10_time,pole11_time,
		start_cheat,prep_wait,service_time2,
		
		f_last;

	// handles
	Handle
		h_first, player, shabayev, player_ship,
		truck_command, shab,
		ship1, ship2, ship3, ship4, truck,
		scion1, scion2, scion3,
		power1, power2, tech_power, new_power,
		armory, tech_center, new_armory,
		startbase_cbunk, endbase_cbunk, field_cbunk,
		builder1, jammer, drone,
		temp1,temp2,temp3,
		blah, talk,
		leader, fixing, temp_check,
		garbble, jammer2,
		dead_scav1, dead_scav2,
		cheat,shab2,cons,tester,base_power,
		off_gen,last_turret1,last_turret2,
		dead_power1,dead_power2,temp_shabayev,
		holder,
		pole3,pole4,pole5,pole6,pole7,pole8,pole9,pole10,pole11,
		look_pole,pilot,
		h_last;

	// integers
	int
		i_first,
		x, y, x1, y1, a1, b1,
		x2, y2, a2, b2,
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
	truck_lost = true;
	shab_message1 = false;
	find_truck_message = false;
	truck_lost_message = false;
	follow_player = false;
	first_warning = false;
	second_warning = false;
	recover_message = true;
	in_combat = false;
	at_truck_stop = false;
	wrong_message = false;
	player_lost = false;
	return_message1 = false;
	move_out = false;
	truck_following = false;
	wrong_person = false;
	at_base = false;
	caught_up = false;
	wait_message = false;
	to_shab1 = false;
	to_builder = false;
	shab_builder_detect = false;
	follow_off = false;
	builder_change = false;
	at_jammer = false;
	jammer_message = false;
	player_at_builder = false;
	jammer_built = false;
	builder_morph = false;
	jammer_dead = false;
	scrammbled_message = false;
	builder1_run = false;
	build_drone = false;
	remove_drone = false;
	drone_to_shab2 = false;
	drone_to_shab3 = false;
	drone_to_field = false;
	first_wave_built = false;
	first_wave_attack = false;
	shab_attack_jammer = false;
	dead_message = false;
	first_over = false;
	to_shab2 = false;
	after_first_message = false;
	builder1_run2 = false;
	builder1_to_shab2 = false;
	builder_morph1 = false;
	builder1_stop = false;
	show_ready = false;
	drone_run = false;
	make_switch = false;
	part_two = false;
	builder_dead = false;
	drone_dead =false;
	no_show = false;

	shab_message2 = false;
	show_over = false;
	to_shab2a = false;
	shab_message3 = false;
	temp_spawn = false;
	start_second_morph = false;
	reroute = false;
	start_show2 = false;
	in_range = false;
	end_show2 = false;
	second_over = false;
	combat2 = false;
	john_injured = false;
	john_full_health = false;
	shabayev_injured = false;
	shab_full_health = false;
	john_low_ammo = false;
	shab_low_ammo = false;
	repair_check1 = false;
	shab_injured = false;
	repairs_needed = false;
	repair_message1 = false;
	repair_message2 = false;
	repair_message3 = false;
	john_over_shab = false;
	shab_over_john = false;
	keep_moving_message = false;
	on_to_base = false;
	truck_wait = false;
	move_to_center = false;
	endbase_detected = false;
	hit_hard_message = false;
	at_center = false;
	game_over = false;
	all_clear = false;
	surprise_spawn = false;
	surprise_attack = false;
	surprise_successful = false;
	last_morph = false;
	last_attack = false;
	truck_message = false;
	ship_destroyed = true;
	shab_to_ship = false;
	shab_get_in = false;
	shab_in_ship = false;
	shab_to_ship = false;
	shab_get_in = false;
	shab_in_ship1 = false;
	shab_in_ship2 = false;
	shab_in_ship3 = false;
	shab_in_ship4 = false;
	john_in_ship = false;
	dump = false;
	truck_ready = false;
	free_truck = false;
	at_base_center = false;
	selected_message = false;
	make_jammer = false;
	jammer_sets = false;
	come_here = false;
	cheat1 = false;
	cheat2 = false;
	dead_now_message = false;
	move_on = false;
	scion_message = false;
	bert = false;
	return_message = false;
	repair_done = false;
	at_player = false;
	watch_player = false;
	shab_to_point = false;
	shab_at_point = false;
	shab_follow_build = false;
	at1 = false;
	at2 = false;
	at3 = false;
	reroute1 = false;
	reroute2 = false;
	reroute3 = false;
	jammer2_dead = false;
	after_second_check = false;
	come_here2 = false;
	shab_at_jam2 = false;
	scrammbled_message2 = false;
	scavs_found = false;
	after_scavs = false;
	free_temp = false;
	got_it_message = false;
	jammer2_dead_message = false;
	three_to_go = false;
	two_to_go = false;
	one_to_go = false;
	mistake = false;
	goose = false;
	temp_patrol = false;
	temp_change = false;
	made_cheat = false;
	shab_out = false;
	shab_hop_out = false;
	shab_to_con = false;
	shab_in = false;
	prep_cons = false;
	to_power_spot = false;
	base_powered = false;
	shab_dead = false;
	cons_dead = false;
	last_wave_dead = false;
	shab_find_con = false;
	shab_first = false;
	truck_explain = false;
	plan = false; plan2 = false;
	attack_last_turret1 = false;
	attack_last_turret2 = false;
	on_to_construct = false;
	return_to_base = false;
	last_turret1_dead = false;
	new_prep = false;
	startup_over = false;
	con_switch = false;
	turrets_stop = false;
	extra_help = false;
	service_scout = false;
	movie1 = false;
	firstFrame = false;
	pole3_switch = false;
	pole4_switch = false;
	pole5_switch = false;
	pole6_switch = false;
	pole7_switch = false;
	pole8_switch = false;
	pole9_switch = false;
	pole10_switch = false;
	pole11_switch = false;
	stop_service = false;
	shab_switch = false;

//  floats
	briefing_time = 999999.9f;
	message1_time = 999999.9f;
	truck_check = 999999.9f;
	find_truck_message_time = 999999.9f;
	wait1_time = 1.0f;
	check1_time = 999999.9f;
	move_time = 999999.9f;
	player_check = 999999.9f;
	player_lost_time = 999999.9f;
	first_warning_time = 180.0f;
	builder_change_time = 999999.9f;
	player_builder_check = 999999.9f;
	jammer_build_time = 999999.9f;
	jammer_message_time = 999999.9f;
	builder_run_check = 999999.9f;
	builder_run_time = 999999.9f;
	morphing_time = 999999.9f;
	drone_time = 999999.9f;
	remove_drone_time = 999999.9f;
	dead_jammer_message = 999999.9f;
	list_time = 999999.9f;
	get_truck_time = 999999.9f;
	combat_check = 999999.9f;
	morph_time = 999999.9f;
	show_ready_time = 999999.9f;

	encounter1_check = 999999.9f;
	checkpoint2_check = 999999.9f;
	show2_start_time = 999999.9f;
	onto_base_time = 999999.9f;
	center_check = 999999.9f;
	safe_check = 999999.9f;
	ship_destroyed_time = 999999.9f;
	shab_check = 999999.9f;
	trucker_time = 999999.9f;
	shabalab = 999999.9f;
	fire_check = 999999.9f;
	service_time = 999999.9f;
	look_time = 999999.9f;
	watch_player_time = 999999.9f;
	point_check = 999999.9f;
	spawn_time = 999999.9f;
	sue_check = 999999.9f;
	change_time = 999999.9f;
	start_cheat = 999999.9f;
	prep_wait = 999999.9f;
	con_wait = 999999.9f;
	pole3_time = 999999.9f;
	pole4_time = 999999.9f;
	pole5_time = 999999.9f;
	pole6_time = 999999.9f;
	pole7_time = 999999.9f;
	pole8_time = 999999.9f;
	pole9_time = 999999.9f;
	pole10_time = 999999.9f;
	pole11_time = 999999.9f;
	service_time2 = 999999.9f;


//  handles
	player = GetPlayerHandle();

	shab = GetHandle("shab");
	shab2 = NULL;
	truck_command = NULL;
	ship1 = GetHandle("ship1");
	ship2 = GetHandle("ship2");
	ship3 = GetHandle("ship3");
	ship4 = GetHandle("ship4");	
	truck = GetHandle("truck");
	armory = GetHandle("armory");
	//tech_center = GetHandle("tech_center");
	//startbase_cbunk = GetHandle("startbase_cbunk");
	endbase_cbunk = GetHandle("endbase_cbunk");
	field_cbunk = GetHandle("field_cbunk");
	builder1 = GetHandle("builder1");
	dead_scav1 = GetHandle("dead_scav1");
	dead_scav2 = GetHandle("dead_scav2");
	cons = GetHandle("construct");
	last_turret1 = GetHandle("last_turret1");
	last_turret2 = GetHandle("last_turret2");
	dead_power1 = GetHandle("dead_power1");
	dead_power2 = GetHandle("dead_power2");
	pole3 = GetHandle("pole3");
	pole4 = GetHandle("pole4");
	pole5 = GetHandle("pole5");
	pole6 = GetHandle("pole6");
	pole7 = GetHandle("pole7");
	pole8 = GetHandle("pole8");
	pole9 = GetHandle("pole9");
	pole10 = GetHandle("pole10");
	pole11 = GetHandle("pole11");
	look_pole = GetHandle("look_pole");
	holder = NULL;
	temp_shabayev = NULL;
	off_gen = NULL;
	temp_check = NULL;
	shabayev = NULL;
	player_ship = NULL;
	jammer = NULL;
	drone = NULL;
	scion1 = NULL;
	scion2 = NULL;
	scion3 = NULL;
	leader = NULL;
	fixing = NULL;
	new_power = NULL;
	new_armory = NULL;
	jammer2 = NULL;
	tester = NULL;
	base_power = NULL;

	temp1 = NULL;
	temp2 = NULL;
	temp3 = NULL;
	blah = 0;
	talk = 0;
	garbble = 0;
	cheat = NULL;
	pilot = NULL;


//  integers
	x = NULL;
	y = NULL;
	x1 = NULL;
	y1 = NULL;
	a1 = NULL;
	b1 = NULL;
	x2 = NULL;
	y2 = NULL;
	a2 = NULL;
	b2 = NULL;


}

// this is the handle thing brad made for me
void Misn04Mission::AddObject(Handle h)
{
	char ODFName[64];
	GetObjInfo(h, Get_CFG, ODFName);

	if ((!jammer_built) && (jammer == NULL) && (IsOdf2(h,"fbpjam")))
	{
		jammer = h;
		jammer_built = true;
	}
	else if ((cheat == NULL) && (IsOdf2(h,"ivpscou")))
	{
		cheat = h;
		start_cheat = GetTime() + 15.0f;
		made_cheat = true;
	}
	else if ((shab_hop_out) && (shab2 == NULL) && (IsOdf2(h,"ispilo")))
	{
		if (GetDistance(h,shabayev) < 10.0f)
		{
			shab2 = h;
			SetGroup(shab2,-1);
			SetTeamNum(shab2,1);
			shab_out = true;
		}
	}
	else if (IsOdf2(h,"fspilo"))
	{
		pilot = h;
		Damage(pilot,101);
		//RemoveObject(pilot);
	}
	else if ((shab_in) && (base_power == NULL) && (IsOdf2(h,"ibpgn1")))
	{
		base_power = h;
		base_powered = true;
	}

}

void Misn04Mission::Execute(void)
{
/*
	Here is where you put what happens every frame.  
*/
	char tempstr[128];

	player = GetPlayerHandle();


	// this swithes out the constructors

	if (!con_switch)
	{
		//RemoveObject(last_turret2);
		RemoveObject(cons);
		RemoveObject(builder1);
		builder1 = BuildObject("fvpcon",2,"thai_spawn");
		//builder1 = BuildObject("fvpcon",2,"jammer_spawn");
		cons = BuildObject("ivcons2",0,"con_spawn");
		con_switch = true;
	}
	///////////////////////////////////////////

	if (!player_at_builder)
	{
		LookAt(builder1,player);
	}


//////////////////////////////////////////////////////////////////////
if (!ON_HOLD)
{
//////////////////////////////////////////////////////////////////////


	
	// this is what happens when the player gets lost
	
	if (player_lost)
	{
		if (!return_message)
		{
			AudioMessage("isdf0206.wav"); // (shab) do you want to join me
			player_check = GetTime() + 1.5f;
			player_lost_time = GetTime() + 120.0f;
			return_message1 = false;
			return_message = true;
		}


		if (return_message)
		{
			if ((!return_message1) && (player_lost_time < GetTime()))
			{
				AudioMessage("isdf0208.wav"); // (shab) this is the last warning to return john
				player_check = GetTime() + 3.0f;
				player_lost_time = GetTime() + 300.0f;
				return_message1 = true;
			}


			if ((!game_over) && (player_check < GetTime()))
			{
				player_check = GetTime() + 1.5f;


				if (GetDistance(shabayev,player) < 100.0f)
				{
					player_check = GetTime() + 999999.9f;
					player_lost_time = GetTime() + 999999.9f;
					return_message = false;
					player_lost = false;
				}
			}
		}
	}
	///////////////////////////////////////////

	
	// this is checking to make sure the player does not attack his wingman /////////

	if ((!in_combat) && (!startup_over))
	{
		if (fire_check < GetTime())
		{
			if ((IsAlive(shabayev)) && (IsAlive(player)))
			{
				if (GetTime() - GetLastFriendShot(shabayev) < .2f)
				{
					AudioMessage("ff02.wav"); // (shab) watch your firing!
					fire_check = GetTime() + 2.0f;
				}
			}


			if ((IsAlive(truck)) && (IsAlive(player)))
			{
				if (GetTime() - GetLastFriendShot(truck) < .2f)
				{
					AudioMessage("ff02.wav"); // (truck) watch your firing!
					fire_check = GetTime() + 2.0f;
				}
			}
		}
	}
	///////////////////////////////////////////


	// this keeps people alive for a time

	if ((!at_base) && (IsAlive(shabayev)) && (GetCurHealth(shabayev) < 100))
	{
		AddHealth(shabayev, 100);
	}

	// this keeps the builder1 alive for a time

	if ((!part_two) && (IsAlive(builder1)) && (GetCurHealth(builder1) < 100))
	{
		AddHealth(builder1, 100);
	}

	// this is the code that checks to see if john or shab are injured

	if ((IsAround(player_ship)) && (!john_injured))
	{
		if (GetCurHealth(player_ship) < 500)
		{
			john_injured = true;
			john_full_health = false;
		}
	}
	///////////////////////////////////////////


	// this is checking to see if the player and shab are injured
	
	if ((IsAround(player_ship)) && (john_injured))
	{
		if (GetCurHealth(player_ship) > 1600)
		{
			john_injured = false;
		}
	}

	if ((free_truck) && (IsAlive(shabayev)) && (!shabayev_injured))
	{
		if (GetCurHealth(shabayev) < 1100)
		{
			shabayev_injured = true;
			shab_full_health = false;
		}
	}

	if ((IsAlive(shabayev)) && (shabayev_injured))
	{
		if (GetCurHealth(shabayev) > 1700)
		{
			shabayev_injured = false;
		}
	}

	if ((IsAround(player_ship)) && (!john_low_ammo))
	{
		if (GetCurAmmo(player_ship) < 500)
		{
			john_low_ammo = true;
			john_full_health = false;
		}
	}

	if ((IsAround(player_ship)) && (john_low_ammo))
	{
		if (GetCurAmmo(player_ship) > 1400)
		{
			john_low_ammo = false;
		}
	}

	if ((IsAlive(shabayev)) && (!shab_low_ammo))
	{
		if (GetCurAmmo(shabayev) < 500)
		{
			shab_low_ammo = true;
			shab_full_health = false;
		}
	}

	if ((IsAlive(shabayev)) && (shab_low_ammo))
	{
		if (GetCurAmmo(shabayev) > 1000)
		{
			shab_low_ammo = false;
		}
	}

	if ((!john_injured) && (!john_low_ammo))
	{
		john_full_health = true;
	}

	if ((!shabayev_injured) && (!shab_low_ammo))
	{
		shab_full_health = true;
	}
	///////////////////////////////////////////


	// this controls where shab is looking
	
	if (look_time < GetTime())
	{
		if (!at_player)
		{
			LookAt(shabayev,player);
			look_time = GetTime() + 13.0f;
			at_player = true;
		}
		else if (IsAlive(truck))
		{
			LookAt(shabayev,truck);
			look_time = GetTime() + 9.0f;
			at_player = false;
		}
	}
	///////////////////////////////////////////


	// this keep shab from running out of ammo

	if ((in_combat) && (GetCurAmmo(shabayev) < 100))
	{
		SetCurAmmo(shabayev,100);
	}
	///////////////////////////////////////////


/*
This area will hold the opening cineractive plus the code that will make
shabayev have the service truck repair some of the other ships.
*/


 // this is NEW code to make sure the truck is following john

	
	if (!start_done)
	{
		Stop(truck);
		SetGroup(shab,-1);
		SetTeamNum(shab,1);
		SetGroup(truck,-1);
		SetTeamNum(truck,1);
		ClearObjectives();
		AddObjective("to_ship.otf", WHITE);
		SetPerceivedTeam(builder1,1);
		Ally(3,1);
		Ally(1,3);
		Build(builder1,"fbpjam");
		truck_check = GetTime() + 0.5f;
		player_check = GetTime() + 5.0f;
		briefing_time = GetTime() + 1.0f;
		first_warning_time = GetTime() + 300.0f;
		player_builder_check = GetTime() + 5.0f;
		fire_check = GetTime() + 1.0f;
		AudioMessage("isdf0263.wav"); // (shab) ok, follow me
		start_done = true;
	}


	// this makes the service truck repair the wounded shout

	if ((!service_scout) && (GetDistance(player,truck) < 100.0f))
	{
		holder = BuildObject("stayput",0,ship4);
		Damage(ship4,200);
		Service(truck,ship4,1);
		service_time2 = GetTime() + 5.0f;
		service_scout = true;
	}
	///////////////////////////////////////////


	// this turns off the service truck

	if ((service_scout) && (!stop_service) && (service_time2 < GetTime()))
	{
		SetCurHealth(ship4,1800);
		LookAt(truck,player);
		RemoveObject(holder);
		service_time2 = GetTime() + 999999.9f;
		stop_service = true;
	}
	///////////////////////////////////////////


	// this is sending the pilot shab to here ship and the truck in motion
	
	if ((IsAlive(shab)) && (!shab_to_ship))
	{
		Retreat(shab,"shab_run_path2");


		//if (IsAlive(truck))
		//{
		//	Goto(truck,"truck_move",1);
		//}

		trucker_time = GetTime() + 1.0f;
		shab_to_ship = true;
	}
	///////////////////////////////////////////
	

	// this is checking to see when shab is in her ship

	if ((!IsAround(shab)) && (shab_to_ship) && (!shab_in_ship))
	{
		Handle temp = ship1;


		if ((IsAlive(temp)) && (temp != player))
		{
			temp_shabayev = GetHandle("ship1");
			SetGroup(temp_shabayev,-1);
			LookAt(temp_shabayev,player);
			SetObjectiveOn(temp_shabayev);
			SetObjectiveName(temp_shabayev,"Cmd. Shabayev");
			shab_in_ship1 = true;
			shab_in_ship = true;
		}
		else
		{
			Handle temp = ship2;


			if ((IsAlive(temp)) && (temp != player))
			{
				temp_shabayev = GetHandle("ship2");
				SetGroup(temp_shabayev,-1);
				LookAt(temp_shabayev,player);
				SetObjectiveOn(temp_shabayev);
				SetObjectiveName(temp_shabayev,"Cmd. Shabayev");
				shab_in_ship2 = true;
				shab_in_ship = true;
			}
			else
			{
				Handle temp = ship3;


				if ((IsAlive(temp)) && (temp != player))
				{
					temp_shabayev = GetHandle("ship3");
					SetGroup(temp_shabayev,-1);
					LookAt(temp_shabayev,player);
					SetObjectiveOn(temp_shabayev);
					SetObjectiveName(temp_shabayev,"Cmd. Shabayev");
					shab_in_ship3 = true;
					shab_in_ship = true;
				}
				else
				{
					Handle temp = ship4;


					if ((IsAlive(temp)) && (temp != player))
					{
						temp_shabayev = GetHandle("ship4");
						SetGroup(temp_shabayev,-1);
						LookAt(temp_shabayev,player);
						SetObjectiveOn(temp_shabayev);
						SetObjectiveName(temp_shabayev,"Cmd. Shabayev");
						shab_in_ship4 = true;
						shab_in_ship = true;
					}
				}
			}
		}
	}
	///////////////////////////////////////////

	
	// checks to see if the player kills shab on the way to her ship

	if ((!shab_in_ship) && (!IsAlive(shab)))
	{
		shab_dead = true;
	}
	///////////////////////////////////////////


	// this is making shabayev stay still until the player is too his ship

	//if ((shab_in_ship) && (!john_in_ship))
	//{
	//	if ((IsAlive(shabayev)) && (!dump))
	//	{
	//		Stop(shabayev);
	//	}
	//}///////////////////////////////////////////

	
	// checking the truck code
/*
	if ((!truck_ready) && (shab_to_ship) && (trucker_time < GetTime()))
	{
		trucker_time = GetTime() + 1.0f;


		if (GetDistance(truck,"truck_move") < 10.0f)
		{
			LookAt(truck,shabayev);
			truck_ready = true;
		}
	}
	///////////////////////////////////////////
*/

	// this checks to see when the player is in his ship

	if ((IsOdf(player,"ivplysct")) && (shab_in_ship))
	{
		john_in_ship = true;
		player_ship = player;
		dump = true;
	}
	else
	{
		john_in_ship = false;
	}
	///////////////////////////////////////////

	if (!dump && !game_over)
	{
		// check to see if all player ships are dead
		if (!IsAround(ship4) && !IsAround(ship2) && !IsAround(ship3))
		{
			AudioMessage("isdf0242.wav"); // (shab) if you cannot follow my orders I'll leave you behind
			FailMission(GetTime() + 7.0f);
			game_over = true;
		}
	}

	// This moves shabayev out when the player gets in his ship for the first time

	if ((dump) && (!free_truck) && (shab_in_ship))
	{
		//RemoveObject(holder);
		SetCurHealth(ship4,1800);
		SetBestGroup(truck);
		//LookAt(truck,player,0);
		Goto(truck,"truck_move",0);
		//Goto(truck,"trucky_ducky",0);
		shabayev = BuildObject("ivpscou",1,temp_shabayev);
		RemoveObject(temp_shabayev);

		SetAvoidType(shabayev,0);
		SetAvoidType(truck,0);
		SetObjectiveOn(truck);
		TranslateString2(tempstr, sizeof(tempstr), "Mission0103");  // Service Truck
		SetObjectiveName(truck,tempstr);
		SetObjectiveOn(shabayev);
		SetObjectiveName(shabayev,"Cmd. Shabayev");	
		Retreat(shabayev,"oldbase_center");
		shabalab = GetTime() + 1.0f;
		talk = AudioMessage("isdf0226.wav");//(shab) I want you to have the service truck follow you - select the truck john
		ClearObjectives();
		AddObjective("to_ship.otf", GREEN);
		AddObjective("truck_follow.otf", WHITE);
		truck_ready = true;
		free_truck = true;
	}
	///////////////////////////////////////////


	
	// this makes shab stop at the base center

	if ((free_truck) && (!at_base_center))
	{
		if ((!move_out) && (GetDistance(shabayev,"oldbase_center") < 25.0f))
		{
			LookAt(shabayev,player);
			look_time = GetTime() + 5.0f;
			at_player = true;
			at_base_center = true;
		}
	}
	///////////////////////////////////////////



	// this is when the player selects the truck for the first time

	if (dump)
	{
		if ((!first_over) && (IsSelected(truck)))
		{
			if (!selected_message)
			{
				StopAudioMessage(talk);
				talk = AudioMessage("isdf0227.wav");//(shab) good - choose the "follow" command or press spave bar.
				selected_message = true;
			}
		}
	}
	///////////////////////////////////////////



	// this is keeping an eye on the player and making sure he does not leave the base

	if ((watch_player) && (watch_player_time < GetTime()))
	{
		if (GetDistance(shabayev,player) > 300.0f)
		{
			watch_player_time = GetTime() + 999999.9f;
			player_lost = true;
			watch_player = false;
		}
	}
	///////////////////////////////////////////



	// This sees if truck is following

	if (!player_lost)
	{	
		if ((IsAlive(truck)) && (!IsSelected(truck)) && (!repairs_needed))
		{
			if ((!truck_following) && (truck_check < GetTime()))
			{
				truck_check = GetTime() + 0.5f;


				if (GetCurrentCommand(truck) == CMD_FOLLOW)
				{
					leader = GetCurrentWho(truck);


					if ((!shab_message1) && (leader == player))
					{
						truck_check = GetTime() + 2.0f;
						message1_time = GetTime() + 0.5f;
						truck_message = false;
						truck_following = true;
					}
					else if (shab_message1)
					{
						if ((leader == player) || (leader == shabayev))
						{
							truck_check = GetTime() + 2.5f;
							truck_message = false;
							truck_following = true;
							ClearObjectives();
							AddObjective("truck.otf", GREEN);
							AddObjective("follow_shab.otf", WHITE);
						}
					}
					else if (!wrong_person)
					{
						//get_truck_time =  GetTime() + 3.0f;
						truck_check = GetTime() + 0.5f;
						wrong_person = true;
					}
				}
			}


			// checking to see if the truck is NOT following john

			if ((truck_following) && (truck_check < GetTime()))
			{
				truck_check = GetTime() + 2.0f;


				if (GetCurrentCommand(truck) != CMD_FOLLOW)
				{
					//get_truck_time =  GetTime() + 3.0f;
					truck_check = GetTime() + 1.0f;
					truck_following = false;
				}
			}
			///////////////////////////////////////////


			// if john tells the truck to follow the wrong person when the mission starts

			if ((wrong_person) && (!wrong_message))
			{
				AudioMessage("isdf0201.wav");// (shab) wrong person john
				first_warning_time = GetTime() + 60.0f;
				wrong_message = true;
			}
			///////////////////////////////////////////


			// orders the truck to follow himself for the first time

			if (!shab_message1)
			{
				if ((truck_following) && (message1_time < GetTime()))
				{
					StopAudioMessage(talk);
					talk = AudioMessage("isdf0202.wav"); // (shab) good - lets go
					ClearObjectives();
					AddObjective("truck.otf", GREEN);
					AddObjective("follow_shab.otf", WHITE);
					shab_message1 = true;
				}


				if ((!truck_following) && (!first_warning) && (first_warning_time < GetTime()))
				{
					AudioMessage("isdf0203.wav"); // (shab) hurry up and get truck to follow us
					first_warning_time = GetTime() + 240.0f;
					first_warning = true;		
				}
			}
			///////////////////////////////////////////


			// this is shab telling john to get the truck

			if ((truck_message) && (get_truck_time < GetTime()))
			{
				get_truck_time = GetTime() + 20.0f;
				ClearObjectives();
				AddObjective("truck.otf", WHITE);
				AudioMessage("isdf0204.wav"); // (shab) make sure the truck is following us john
			}
			///////////////////////////////////////////
		}
	}
	///////////////////////////////////////////




// now I know if the player is lost and if the truck is following so I will have shab move out	




if ((!shab_at_point) && (shab_message1) && (IsAlive(shabayev)))
{
	// this sends shab out of the base for the first time

	if ((!move_out) && (shab_message1) && (IsAudioMessageDone(talk)))
	{
		Goto(shabayev,"truckwait_path");
		//Goto(shabayev,"fuck_path");
		//Goto(truck,"fuck_path");
		look_time = GetTime() + 999999.9f;
		check1_time = GetTime() + 3.0f;
		move_out = true;
	}
	///////////////////////////////////////////



	// this is when shab first reaches the trck wait point
	
	if ((!at_truck_stop) && (move_out) && (check1_time < GetTime()))
	{
		check1_time = GetTime() + 1.0f;


		if (GetDistance(shabayev,"truckwait_point") < 20.0f)
		{
			LookAt(shabayev,player);
			look_time = GetTime() + 3.0f;
			at_player = true;
			check1_time = GetTime() + 0.5f;

			
			if (GetDistance(shabayev,player) > 200.0f)
			{
				player_lost = true;
			}

			if ((!player_lost) && (!truck_following))
			{
				get_truck_time =  GetTime() + 2.0f;
				truck_message = true;
			}

			at_truck_stop = true;
		}
	}
	///////////////////////////////////////////



	// checking to see if the truck is caught up

	if (!player_lost)
	{
		if ((!caught_up) && (at_truck_stop) && (check1_time < GetTime()))
		{
			check1_time = GetTime() + 2.0f;


			if (GetDistance(shabayev,player) < 100.0f)
			{
				if (truck_following)
				{
					if (GetDistance(player,truck) < 70.0f)
					{
						talk = AudioMessage("isdf0209.wav"); // (shab) ok, follow me
						//check1_time = GetTime() + 1.0f;
						caught_up = true;
					}
					else if (!wait_message)
					{
						AudioMessage("isdf0210.wav"); // (shab) sometimes you have to wait for slower vehicles
						check1_time = GetTime() + 1.0f;
						wait_message = true;
					}
				}
				else if ((!truck_message) && (!truck_following))
				{
					get_truck_time = GetTime() + 1.0f;
					truck_message = true;
				}
			}
		}
	}
	///////////////////////////////////////////


	// now that the truck is caught up she moves on

	if ((caught_up) && (!to_shab1) && (IsAudioMessageDone(talk)))
	{
		Goto(shabayev,"shab_path1");
		look_time = GetTime() + 999999.9f;
		check1_time = GetTime() + 1.0f;
		builder_change_time = GetTime()  + 2.0f;
		truck_message = false;
		to_shab1 = true;
	}
	///////////////////////////////////////////

	
	// this is shab commenting on the the builder she has detected

	if (IsAlive(builder1))
	{
		if ((to_shab1) && (!builder_change) && (builder_change_time < GetTime()))
		{
			builder_change_time = GetTime() + 0.5f;


			if (GetDistance(shabayev,"detect_spot") < 30.0f)
			{
				SetPerceivedTeam(builder1,2);
				builder_change_time = GetTime() + 10.0f;
				//follow_off = true; // I don't want shab to be concerned with the truck at this point
				builder_change = true;
			}
		}


		if ((caught_up) && (!shab_builder_detect) && (IsAudioMessageDone(talk)))
		{
			AudioMessage("isdf0211.wav"); // (shab) We got something - appears  stationary - I'm checking
			shab_builder_detect = true;
		}
	}
	///////////////////////////////////////////


	// checking to see when she reaches the first check point (should have already detected the builder)

	if ((to_shab1) && (!to_builder) && (check1_time < GetTime()))
	{
		check1_time = GetTime() + 2.0f;


		if (GetDistance(shabayev,"checkpoint1") < 40.0f)
		{
			Goto(shabayev,"shabstop_jammer");
			check1_time = GetTime() + 0.5f;
			to_builder = true;
		}
	}
	///////////////////////////////////////////


	// shab see the builder

	if ((to_builder) && (!jammer_message) && (check1_time < GetTime()))
	{
		check1_time = GetTime() + 0.5f;


		if ((!jammer_built) && (GetDistance(shabayev,"shabstop_jammer") < 20.0f))
		{
			AudioMessage("isdf0212.wav"); // (shab) what the hell is that!
			LookAt(shabayev,builder1);
			jammer_message = true;
		}
	}
	///////////////////////////////////////////

	
	// now the player sees the builder (here is where the builder will finish building the jammer

	if ((!player_at_builder) && (IsAlive(builder1)) && (player_builder_check < GetTime()))
	{
		if (to_builder)
		{
			player_builder_check = GetTime() + 1.0f;


			if ((GetDistance(builder1,player)) < (GetDistance(builder1,"dist_check")))
			{
				Dropoff(builder1,"jammer_spawn",2);

				jammer_build_time = GetTime() + 5.0f;
				player_at_builder = true;
			}
		}
		else
		{
			player_builder_check = GetTime() + 1.0f;


			if ((GetDistance(builder1,player)) < (GetDistance(builder1,"dist_check")))
			{
				Dropoff(builder1,"jammer_spawn",2);

				jammer_build_time = GetTime() + 10.0f;
				player_at_builder = true;
			}
		}
	}
	///////////////////////////////////////////


	// this sets some time up for the jammer

	if ((!jammer_sets) && (jammer_built) && (player_at_builder))
	{
		jammer_message_time = GetTime() + 3.0f;
		builder_run_time = GetTime() + 0.2f;
		jammer_sets = true;
	}
	///////////////////////////////////////////


	// this is the first attack by the ScionS

	if ((!first_wave_built) && (player_at_builder))
	{
		if ((!first_wave_built) && (GetDistance(player,"espawn1_jammer") > 200.0f))
		{
			scion1 = BuildObject("fvpsnt",2,"espawn1_jammer");
			scion2 = BuildObject("fvpsnt",2,"espawn2_jammer");
			SetSkill(scion1,2);
			SetSkill(scion2,2);
			Stop(scion1);
			Stop(scion2);
			first_wave_built = true;
		}


		if ((!first_wave_built) && (GetDistance(player,"espawn3_jammer") > 200.0f))
		{
			scion1 = BuildObject("fvpsnt",2,"espawn3_jammer");
			scion2 = BuildObject("fvpsnt",2,"espawn4_jammer");
			Stop(scion1);
			Stop(scion2);
			first_wave_built = true;
		}
	}
	///////////////////////////////////////////


	// sending the first wave in to attack

	if ((!first_wave_attack) && (first_wave_built))
	{
		if (builder1_run)
		{
			if (IsAlive(scion1))
			{
				Goto(scion1,"jammer_spawn");
			}
			if (IsAlive(scion2))
			{
				Goto(scion2,"jammer_spawn");
			}

			combat_check = GetTime() + 3.0f;
			first_wave_attack = true;
		}
		else if ((IsAlive(builder1)) && (GetHealth(builder1) < 0.50f))
		{
			if (IsAlive(scion1))
			{
				Goto(scion1,"jammer_spawn");
			}
			if (IsAlive(scion2))
			{
				Goto(scion2,"jammer_spawn");
			}

			combat_check = GetTime() + 3.0f;
			first_wave_attack = true;
		}
		else if (!IsAlive(builder1))
		{
			if (IsAlive(scion1))
			{
				Goto(scion1,"jammer_spawn");
			}
			if (IsAlive(scion2))
			{
				Goto(scion2,"jammer_spawn");
			}

			combat_check = GetTime() + 3.0f;
			first_wave_attack = true;
		}
	}
	///////////////////////////////////////////


	// this is the garbled message sent by shab

	if (!dead_message)
	{
		if ((jammer_built) && (to_builder) && (!jammer_dead) && (jammer_message_time < GetTime()))
		{
			if (!scrammbled_message)
			{
				garbble = AudioMessage("isdf0213.wav"); // (shab) *shab's garbled message*
				jammer_message_time = GetTime() + 15.0f;
				scrammbled_message = true;
			}
			else
			{
				garbble = AudioMessage("isdf0229.wav"); // (shab) *SECOND shab's garbled message*
				jammer_message_time = GetTime() + 25.0f;
				scrammbled_message = false;
			}
		}
	}
	///////////////////////////////////////////


	// this is telling shab to attack the jammer

	if ((scrammbled_message) && (!shab_attack_jammer) && (!jammer_dead))
	{
		Attack(shabayev,jammer,1);
		SetObjectiveOn(jammer);
		shab_attack_jammer = true;
	}
	///////////////////////////////////////////


	// this is checking to see if the jammer is still alive

	if ((jammer_built) && (!jammer_dead) && (!IsAround(jammer)))
	{
		dead_jammer_message = GetTime() + 2.0f;
		LookAt(shabayev,player);
		jammer_dead = true;
	}
	///////////////////////////////////////////


	// this shab warning of the up comming attack by the two scion forces after the jammer is destroyed

	if ((jammer_dead) && (!dead_message) && (dead_jammer_message < GetTime()))
	{
		if (IsAlive(scion1))
		{
			StopAudioMessage(garbble);
			AudioMessage("isdf0228.wav");//(shab) that thing was jamming our communications - defend the truck I'll go for the hostiles
			ClearObjectives();
			AddObjective("defend_truck.otf", WHITE);
			Attack(shabayev,scion1);


			if (IsAlive(scion2))
			{
				Attack(scion2,truck);
				Attack(scion1,truck);
			}
			else
			{
				Attack(scion1,truck);
			}

			dead_message = true;
		}
		else if (IsAlive(scion2))
		{
			AudioMessage("isdf0228.wav");//(shab) that thing was jamming our communications - defend the truck I'll go for the hostiles
			ClearObjectives();
			AddObjective("defend_truck.otf", WHITE);
			Attack(shabayev,scion2);
			Attack(scion2,truck);
			jammer_message_time = GetTime() + 999999.9f;
			dead_message = true;
		}
		else if (first_over)
		{
			talk = AudioMessage("isdf0214.wav"); // (shab) that thing was jamming our communications!
			jammer_message_time = GetTime() + 999999.9f;
			dead_message = true;
		}
	}
	///////////////////////////////////////////



	// this is setting "combat" conditions

	if ((!in_combat) && (combat_check < GetTime()))
	{
		combat_check = GetTime() + 1.0f;


		if ((IsAlive(scion1)) && (GetDistance(scion1,player) < 180.0f))
		{
			combat_check = GetTime() + 999999.9f;
			in_combat = true;
		}
		if ((IsAlive(scion2)) && (GetDistance(scion2,player) < 180.0f))
		{
			combat_check = GetTime() + 999999.9f;
			in_combat = true;
		}
	}
	///////////////////////////////////////////


	// this is shab asking for help with the other one


	if ((dead_message) && (IsAudioMessageDone(talk)))
	{
		if ((!scion_message) && (!first_over) && (first_wave_built))
		{
			if ((!IsAlive(scion1)) && (IsAlive(scion2)))
			{		
				AudioMessage("isdf0247.wav"); // (shab) Good Job John - give me a hand with this other one
				Attack(shabayev,scion2);

				if (IsAlive(truck))
				{
					Attack(scion2,truck);
				}

				SetObjectiveOn(scion2);
				TranslateString2(tempstr, sizeof(tempstr), "Mission0101");  // Hostile
				SetObjectiveName(scion2,tempstr);
				ClearObjectives();
				AddObjective("defend_truck.otf", GREEN);
				AddObjective("assist_shab.otf", WHITE);
				scion_message = true;
			}
			else if ((!IsAlive(scion2)) && (IsAlive(scion1)))
			{
				AudioMessage("isdf0247.wav"); // (shab) Good Job John - give me a hand with this other one
				Attack(shabayev,scion1);

				if (IsAlive(truck))
				{
					Attack(scion1,truck);
				}

				SetObjectiveOn(scion1);
				TranslateString2(tempstr, sizeof(tempstr), "Mission0101");  // Hostile
				SetObjectiveName(scion1,tempstr);
				ClearObjectives();
				AddObjective("defend_truck.otf", GREEN);
				AddObjective("assist_shab.otf", WHITE);
				scion_message = true;
			}

		}
	}
	///////////////////////////////////////////


	// this is the code that determines if the battle is over

	if ((first_wave_built) && (!first_over) && (!IsAlive(scion1)) && (!IsAlive(scion2)) && (!IsAlive(scion3)))
	{
		LookAt(shabayev,player);
		SetCurHealth(shabayev,900);
		at_player = true;
		in_combat = false;
		first_over = true;
	}
	///////////////////////////////////////////


	// this is when the first wave is dead and the player has destroyed the jammer

	if ((first_over) && (dead_message))
	{
		// this is shab telling john to rendezvous with her

		if ((!come_here) && (IsAudioMessageDone(talk)))
		{
			if (GetDistance(shabayev,"super_rendezvous") > 100.0f)
			{
				Retreat(shabayev,"super_rendezvous");
				point_check = GetTime() + 1.0f;
				
				
				if (GetCurrentCommand(truck) == CMD_FOLLOW)
				{
					talk = AudioMessage("isdf0230.wav");//(shab) rondezvous with me
					ClearObjectives();
					AddObjective("rendezvous.otf", WHITE);
					shab_to_point = true;
					come_here = true;
				}
				else
				{
					talk = AudioMessage("isdf0230.wav");//(shab) rondezvous with me and make sure truck is following us
					ClearObjectives();
					AddObjective("rendezvous.otf", WHITE);	
					AddObjective("truck.otf", WHITE);
					shab_to_point = true;
					come_here = true;
				}
			}
			else if (GetDistance(player,shabayev) > 25.0f)
			{
				LookAt(shabayev,player);

				if (GetCurrentCommand(truck) == CMD_FOLLOW)
				{
					talk = AudioMessage("isdf0230.wav");//(shab) rondezvous with me
					ClearObjectives();
					AddObjective("rendezvous.otf", WHITE);
					shab_at_point = true;
					come_here = true;
				}
				else
				{
					talk = AudioMessage("isdf0230.wav");//(shab) rondezvous with me and make sure truck is following us
					ClearObjectives();
					AddObjective("rendezvous.otf", WHITE);	
					AddObjective("truck.otf", WHITE);
					shab_at_point = true;
					come_here = true;
				}
			}
			else
			{
				LookAt(shabayev,player);
				shab_at_point = true;
				come_here = true;
			}
		}
		///////////////////////////////////////////


		if ((come_here) && (shab_to_point))
		{
			if ((!shab_at_point) && (point_check < GetTime()))
			{
				point_check = GetTime() + 0.5f;


				if (GetDistance(shabayev,"super_rendezvous") < 40.0f)
				{
					LookAt(shabayev,player);
					look_time = GetTime() + 10.0f;
					at_player = true;
					shab_at_point = true;
				}
			}
		}
		///////////////////////////////////////////
	}
	///////////////////////////////////////////
}


// this is builder code ////////////////////////////////////////////////


if (IsAlive(builder1))
{
	// this is making the builder run to the morph spot

	if ((!builder1_run) && (jammer_built) && (builder_run_time < GetTime()))
	{
		SetAvoidType(builder1,0);
		Retreat(builder1,"builder_goto_path",1);
		builder_run_check = GetTime() + 3.0f;
		in_combat = true;
		builder1_run = true;
	}

/*
	if ((!builder1_run2) && (builder1_run) && (builder_run_check < GetTime()))
	{
		builder_run_check = GetTime() + 1.0f;

		if (GetDistance(builder1,"buildermorph_point") < 25.0f)
		{
			Retreat(builder1,"droneescape_point");
			builder_run_check = GetTime() + 15.0f;
			builder1_run2 = true;
		}
	}
	///////////////////////////////////////////


	// this making the builder run for shab2_path

	if ((!builder1_to_shab2) && (builder1_run2) && (builder_run_check < GetTime()))
	{
		builder_run_check = GetTime() + 2.0f;


		if (GetDistance(builder1,"droneescape_point") < 40.0f)
		{
			Retreat(builder1,"shab_path2");
			builder_run_check = GetTime() + 2.0f;
			builder1_to_shab2 = true;
		}
	}
	///////////////////////////////////////////
*/

	// this is making the builder stop and wait to be caught
	
	if ((!builder_morph1) && /*(builder1_to_shab2)*/(builder1_run) && (builder_run_check < GetTime()))
	{
		builder_run_check = GetTime() + 2.0f;

		
		if (!builder1_stop)
		{
			if (GetDistance(builder1,"morph_point1") < 50)
			{
				Stop(builder1);
				builder1_stop = true;
			}
			else if (((to_shab2) && (GetDistance(builder1,shabayev) < 130)) || ((to_shab2) && (GetDistance(builder1,player) < 140)))
			{
				Stop(builder1);
				show_ready = true;
				builder1_stop = true;
			}
		}


		if ((!show_ready) && (builder1_stop) & (first_over))
		{
			if ((GetDistance(builder1,shabayev) < 150) || (GetDistance(builder1,player) < 150))
			{
				show_ready = true;
			}
		}


		if ((show_ready) && (!builder_morph1))
		{
			Retreat(builder1,"drone_path");
			builder_morph1 = true;
		}
	}
	///////////////////////////////////////////
}
else if ((!builder_dead) && (!builder_morph1))
{
	builder_dead = true;


	if (!temp_spawn)
	{
		temp1 = BuildObject("fvpsnt",2,"morph2_point1");
		temp2 = BuildObject("fvpsnt",2,"morph2_point2");
		temp3 = BuildObject("fvpsnt",2,"morph2_point3");

		SetSkill(temp1,1);
		SetSkill(temp2,1);
		SetSkill(temp3,1);

		//Deploy(temp1);
		//Deploy(temp2);
		//Deploy(temp3);

		jammer2 = BuildObject("fbpjam",2,"jam2_spawn");

		temp_spawn = true;
	}
}


// this is contiued builder code ///////////////////////////////


if (IsAlive(builder1))
{
	if (builder_morph1)
	{
		// this is building the second wave

		if (!temp_spawn)
		{
			temp1 = BuildObject("fvpsnt",2,"morph2_point1");
			temp2 = BuildObject("fvpsnt",2,"morph2_point2");
			temp3 = BuildObject("fvpsnt",2,"morph2_point3");

			SetSkill(temp1,1);
			SetSkill(temp2,1);
			SetSkill(temp3,1);

			//Deploy(temp1);
			//Deploy(temp2);
			//Deploy(temp3);

			jammer2 = BuildObject("fbjamm",2,"jam2_spawn");
			temp_spawn = true;
			//drone_run = true;
		}
		///////////////////////////////////////////
	}


	if ((to_shab2) && (!remove_drone) && (temp_spawn))
	{
		// checking to see if I can get rid of the drone

		if (remove_drone_time < GetTime())
		{
			remove_drone_time = GetTime() + 1.0f;


			// this is shab commenting on the builder

			if ((GetDistance(builder1,player) < 175.0f) && (!shab_message3))
			{
				AudioMessage("isdf0241.wav"); // (shab) it's getting away - follow it!
				shab_message3 = true;
			}
			///////////////////////////////////////////
		}
	}
}
else if ((!builder_dead) && (!remove_drone))
{
	builder_dead = true;

	if (!temp_spawn)
	{
		temp1 = BuildObject("fvpsnt",2,"morph2_point1");
		temp2 = BuildObject("fvpsnt",2,"morph2_point2");
		temp3 = BuildObject("fvpsnt",2,"morph2_point3");

		SetSkill(temp1,1);
		SetSkill(temp2,1);
		SetSkill(temp3,1);

		//Deploy(temp1);
		//Deploy(temp2);
		//Deploy(temp3);

		jammer2 = BuildObject("fbjamm",2,"jam2_spawn");

		temp_spawn = true;
	}
}




// this is shab saying they have to move out after first battle





if ((!after_first_message) && (shab_at_point))
{
	// I'm furst checking to find the states of shab and the player

	if ((!repair_check1) && (GetDistance(player,shabayev) < 50.0f))
	{
		if ((!shab_full_health) || (!john_full_health))
		{
			repairs_needed = true;
		}
		else
		{
			repair_done = true;
		}

		repair_check1 = true;
	}
	///////////////////////////////////////////


	// I'm having the truck service here

	if ((repairs_needed) && (!repair_done))
	{
		if (!bert)
		{
			// if shab needs it first

			if (!shab_full_health)
			{
				SetCurHealth(shabayev,1200);
				Service(truck,shabayev,1);
				AudioMessage("isdf0248.wav"); // Truck - repair me
				look_time = GetTime() + 2.0f;
				Service(truck,shabayev);
				service_time = GetTime() + 8.0f;
				shab_first = true;
				bert = true;
			}

			// then I send it to the player
/*
			else
			{
				blah = AudioMessage("isdf0249.wav"); // (shab) You took a beating - the service truck will repair you automatically if you stnad near it
				look_time = GetTime() + 2.0f;
				ClearObjectives();
				AddObjective("service.otf", WHITE);	
				bert = true;
				repair_message1 = true;
			}
			///////////////////////////////////////////
*/
		}


		// this is shab telling the player about the truck

		if ((!truck_explain) && (shab_first) && (service_time < GetTime()))
		{
			blah = AudioMessage("isdf0261.wav");// (shab) Get close to the truck and it will repair you
			truck_explain = true;
		}
		///////////////////////////////////////////

		
		// this checks to see if the player stops the service process

		if ((!repair_message1) && (shab_first))
		{
			if (shab_full_health)
			{
				Follow(truck,player,0);
				//Stop(truck,0);
				repairs_needed = false;
				john_full_health = true;
				repair_done = true;

/*
				if ((GetCurAmmo(player_ship) < 1300) || (GetCurHealth(player_ship) < 1600))
				{
					Follow(truck,player,0);
					//Stop(truck,0);
					blah = AudioMessage("isdf0216a.wav"); // (shab) now I'm fixed - move close to the truck and it will repair you
					repair_message1 = true;
				}
				else
				{
					Follow(truck,player,0);
					//Stop(truck,0);
					repairs_needed = false;
					john_full_health = true;
					repair_done = true;
				}
*/
			}
		}
		///////////////////////////////////////////


		// this is after the player is fixed up

		if ((repair_message1) && (john_full_health))
		{
			repairs_needed = false;
			repair_done = true;
		}
		///////////////////////////////////////////


/*		
		// this is if shab needed fixing

		if ((bert) && (!repair_message1) && (!repair_done))
		{
			if ((shab_full_health) && (!john_full_health))
			{
				blah = AudioMessage("isdf0216.wav"); // (shab) now I'm fixed - hold still while the truck fixes you up
				ClearObjectives();
				AddObjective("service.otf", WHITE);
				repair_message1 = true;
			}


			if ((shab_full_health) && (john_full_health))
			{
				repairs_needed = false;
				repair_done = true;
			}
		}
		///////////////////////////////////////////


		// this is if only the player needed fixing
		
		if ((repair_message1) && (!repair_message2))
		{
			if (IsSelected(truck))
			{
				StopAudioMessage(blah);
				blah = AudioMessage("isdf0217.wav"); // (shab) good! now select the "repair command" using the "" key and press your space bar.
				repair_message2 = true;
			}
		}
		///////////////////////////////////////////


		if ((repair_message2) && (!repair_message3))
		{
			if (IsSelected(truck))
			{
				//goose = true;
				mistake = false;
			}


			//if ((goose) && (!IsSelected(truck)))
			//{
				if (GetCurrentCommand(truck) == CMD_SERVICE)
				{
					fixing = GetCurrentWho(truck);

					if (fixing == player)
					{
						StopAudioMessage(blah);
						blah = AudioMessage("isdf0218.wav"); // (shab) Good - just hold still for a second while it repairs you
						ClearObjectives();
						AddObjective("service_done.otf", GREEN);
						AddObjective("hold_still.otf", WHITE);						
						repair_message3 = true;
					}
				}
				else if ((!mistake) && (GetCurrentCommand(truck) == CMD_FOLLOW))
				{
					StopAudioMessage(blah);
					blah = AudioMessage("isdf0256.wav"); // (shab) oops1 you told the truck to follow!
					ClearObjectives();
					AddObjective("service.otf", WHITE);
					mistake = true;
				}

				//goose = false;
			//}
		}

*/
	}


	
	// this is sending shab after she and the player are repaired
	
	if (repair_done)
	{
		if (!after_first_message)
		{
			if (builder_dead)
			{
				talk = AudioMessage("isdf0215.wav"); // shab we need to get to that base
				checkpoint2_check = GetTime() + 1.0f;


				if (!temp_spawn)
				{
					temp1 = BuildObject("fvpsnt",2,"morph2_point1");
					temp2 = BuildObject("fvpsnt",2,"morph2_point2");
					temp3 = BuildObject("fvpsnt",2,"morph2_point3");

					SetSkill(temp1,1);
					SetSkill(temp2,1);
					SetSkill(temp3,1);

					//Deploy(temp1);
					//Deploy(temp2);
					//Deploy(temp3);

					jammer2 = BuildObject("fbjamm",2,"jam2_spawn");

					temp_spawn = true;
				}


				if (GetCurrentCommand(truck) != CMD_FOLLOW)
				{
					get_truck_time =  GetTime() + 3.0f;
					truck_check = GetTime() + 5.0f;
					truck_message = true;
					truck_following = false;
				}

				after_first_message = true;
			}
			else if (!builder_dead)
			{
				talk = AudioMessage("isdf0222.wav"); // lets investigate that constructor
				checkpoint2_check = GetTime() + 1.0f;


				if (GetCurrentCommand(truck) != CMD_FOLLOW)
				{
					get_truck_time =  GetTime() + 5.0f;
					truck_check = GetTime() + 5.0f;
					truck_message = true;
					truck_following = false;
				}

				after_first_message = true;
			}
		}
	}
}



	// This sends shab to the builder or the other ambush when she is repaired and the truck is following

	if ((!player_lost) && (truck_following))
	{
		if ((!to_shab2) && (after_first_message) && (IsAudioMessageDone(talk)))
		{
			if (builder_dead)
			{
				Goto(shabayev,"shab_path2");
				ClearObjectives();
				AddObjective("truck.otf", GREEN);
				AddObjective("follow_shab.otf", WHITE);
				AudioMessage("isdf0209.wav");
				look_time = GetTime() + 999999.9f;
				encounter1_check = GetTime() + 1.0f;
				truck_message = false;
				john_over_shab = false;
				shab_over_john = false;
				no_show = true;
				part_two = true;
				to_shab2 = true;
			}
			else
			{
				Goto(shabayev,"shab_path2");
				ClearObjectives();
				AddObjective("truck.otf", GREEN);
				AddObjective("follow_shab.otf", WHITE);
				AudioMessage("isdf0209.wav");
				look_time = GetTime() + 999999.9f;
				encounter1_check = GetTime() + 1.0f;
				remove_drone_time = GetTime() + 1.0f;
				truck_message = false;
				john_over_shab = false;
				shab_over_john = false;
				no_show = false;
				part_two = true;
				to_shab2 = true;
			}
		}
	}
	///////////////////////////////////////////




// this is after the first battle and on to the second




if ((part_two) && (!at_base))
{
	if ((!on_to_base) && (IsAlive(shabayev)) && (IsAlive(truck)))
	{
		// this is the code gives the player the "show"
		if (!no_show)
		{
			if ((!start_second_morph) && (!shab_message2) && (encounter1_check < GetTime()))
			{
				encounter1_check = GetTime() + 1.0f;


				if ((IsAlive(builder1)) && (builder_morph1))
				{
					AudioMessage("isdf0223.wav"); // (shab) There it is! what IS that thing
					shab_message2 = true;
				}
			}


			if ((show_ready) && (!shab_follow_build))
			{
				if (IsAlive(builder1))
				{
					Follow(shabayev,builder1,1);
					shab_follow_build = true;
				}
			}
		}
		else if ((!to_shab2a) && (encounter1_check < GetTime()))
		{
			encounter1_check = GetTime() + 1.0f;


			//if (!truck_following)
			//{
			//	get_truck_time =  GetTime() + 2.0f;
			//	truck_message = true;
			//}
			if (GetDistance(shabayev,"morph_point1") < 50)
			{
				Retreat(shabayev,"shab_path2a");
				truck_message = false;
				to_shab2a = true;
			}
		}


		// checking to see if the builder is killed
		if ((to_shab2) && (!start_second_morph) && (builder_dead) && (!dead_now_message))
		{
			talk = AudioMessage("isdf0232.wav");//(shab) whatever it was its dead now
			LookAt(shabayev,player);
			dead_now_message = true;
		}


		if ((!move_on) && (dead_now_message) && (IsAudioMessageDone(talk)))
		{
			Retreat(shabayev,"shab_path2a");
			encounter1_check = GetTime() + 1.0f;
			move_on = true;
		}

// from here you need to look at the builder1 code below
		
		if ((!start_second_morph) && (checkpoint2_check < GetTime()))
		{
			checkpoint2_check = GetTime() + 1.0f;


			if (IsAlive(temp1))
			{
				if (GetDistance(player,temp1) < 150.0f)
				{
					Attack(shabayev,temp1);
					Defend(temp1,jammer2);
					Defend(temp2,jammer2);
					Defend(temp3,jammer2);
					jammer_message_time = GetTime() + 2.0f;
					at1 = true;
					in_combat = true;
					start_second_morph = true;
				}
				else if (to_shab2a)
				{
					if (GetDistance(shabayev,temp1) < 150.0f)
					{
						Attack(shabayev,temp1);
						Defend(temp1,jammer2);
						Defend(temp2,jammer2);
						Defend(temp3,jammer2);
 						jammer_message_time = GetTime() + 2.0f;
						at1 = true;
						in_combat = true;
						start_second_morph = true;
					}
				}
			}


			if ((IsAlive(temp2)) && (!start_second_morph))
			{
				if (GetDistance(player,temp2) < 150.0f)
				{
					Attack(shabayev,temp2);
					Defend(temp1,jammer2);
					Defend(temp2,jammer2);
					Defend(temp3,jammer2);
					jammer_message_time = GetTime() + 2.0f;
					at2 = true;
					in_combat = true;
					start_second_morph = true;
				}
				else if (to_shab2a)
				{
					if (GetDistance(shabayev,temp2) < 150.0f)
					{
						Attack(shabayev,temp2);
						Defend(temp1,jammer2);
						Defend(temp2,jammer2);
						Defend(temp3,jammer2);
						jammer_message_time = GetTime() + 2.0f;
						at2 = true;
						in_combat = true;
						start_second_morph = true;
					}
				}
			}


			if ((IsAlive(temp3)) && (!start_second_morph))
			{
				if (GetDistance(player,temp3) < 150.0f)
				{
					Attack(shabayev,temp3);
					Defend(temp1,jammer2);
					Defend(temp2,jammer2);
					Defend(temp3,jammer2);
					jammer_message_time = GetTime() + 2.0f;
					at3 = true;
					in_combat = true;
					start_second_morph = true;
				}
				else if (to_shab2a)
				{
					if (GetDistance(shabayev,temp3) < 150.0f)
					{
						Attack(shabayev,temp3);
						Defend(temp1,jammer2);
						Defend(temp2,jammer2);
						Defend(temp3,jammer2);
						jammer_message_time = GetTime() + 2.0f;
						at3 = true;
						in_combat = true;
						start_second_morph = true;
					}
				}
			}
		}


		// this is going to reroute shab to attack a differnt temp should one temp get killed
		if ((start_second_morph) && (!in_range))
		{
			if (at1)
			{
				if ((!reroute) && (!IsAlive(temp1)))
				{
					if (IsAlive(temp2))
					{
						Attack(shabayev,temp2);
						reroute2 = true;
						reroute = true;
					}
					else if (IsAlive(temp3))
					{
						Attack(shabayev,temp3);
						reroute3 = true;
						reroute = true;
					}
				}

				if ((reroute2) && (!IsAlive(temp2)))
				{
					if ((!reroute3) && (IsAlive(temp3)))
					{
						Attack(shabayev,temp3);
						reroute3 = true;
					}
				}
			}


			if (at2)
			{
				if ((!reroute) && (!IsAlive(temp2)))
				{
					if (IsAlive(temp1))
					{
						Attack(shabayev,temp1);
						reroute1 = true;
						reroute = true;
					}
					else if (IsAlive(temp3))
					{
						Attack(shabayev,temp3);
						reroute3 = true;
						reroute = true;
					}
				}

				if ((reroute1) && (!IsAlive(temp1)))
				{
					if ((!reroute3) && (IsAlive(temp3)))
					{
						Attack(shabayev,temp3);
						reroute3 = true;
					}
				}
			}


			if (at3)
			{
				if ((!reroute) && (!IsAlive(temp3)))
				{
					if (IsAlive(temp1))
					{
						Attack(shabayev,temp1);
						reroute1 = true;
						reroute = true;
					}
					else if (IsAlive(temp2))
					{
						Attack(shabayev,temp2);
						reroute2 = true;
						reroute = true;
					}
				}

				if ((reroute1) && (!IsAlive(temp1)))
				{
					if ((!reroute2) && (IsAlive(temp2)))
					{
						Attack(shabayev,temp2);
						reroute2 = true;
					}
				}
			}
		}



		// this is keeping the temps in place
		if ((temp_spawn) && (!free_temp))
		{
			if (!temp_patrol)
			{
				if (IsAlive(temp1))
				{
					Patrol(temp1,"patrol2_a");
				}
				if (IsAlive(temp2))
				{
					Patrol(temp2,"patrol2_b");
				}

				temp_patrol = true;
			}


			if (IsAlive(temp3))
			{
				Stop(temp3);
			}


			if ((start_second_morph) && (GetDistance(player,"jam2_spawn") < 150.0f))
			{
				SetObjectiveOn(jammer2);
				change_time = GetTime() + 30.0f;
				free_temp = true;
			}
		}


		// this is making the scions morph
		if ((free_temp) && (!temp_change) && (change_time < GetTime()))
		{
			if (IsAlive(temp1))
			{
				Deploy(temp1);
			}
			if (IsAlive(temp2))
			{
				Deploy(temp2);
			}
			if (IsAlive(temp3))
			{
				Deploy(temp3);
			}

			temp_change = true;
		}

		// this is checking to see when the second combat is over

		if (!second_over)
		{
			if ((temp_spawn) && (!IsAlive(temp1)) && (!IsAlive(temp2)) && (!IsAlive(temp3)))
			{
				if (!jammer2_dead)
				{
					Attack(shabayev,jammer2);
					AudioMessage("isdf0213a.wav"); // (shab) *SECOND shab's garbled message*
				}

				follow_off = false;
				second_over = true;
			}
		}


		// this is telling john to rondezvous with shab after second battle

		if ((second_over) && (jammer2_dead))
		{
			if ((!after_second_check) && (GetDistance(shabayev,"jam2_spawn") > 100.0f))
			{
				Retreat(shabayev,"jam2_spawn");
				point_check = GetTime() + 1.0f;

				
				if (GetCurrentCommand(truck) == CMD_FOLLOW)
				{
					talk = AudioMessage("isdf0230.wav");//(shab) rondezvous with me
					ClearObjectives();
					AddObjective("follow_shab.otf", WHITE);
					watch_player_time = GetTime() + 180.0f;
					watch_player = true;
					come_here2 = true;
				}
				else
				{
					talk = AudioMessage("isdf0230.wav");//(shab) rondezvous with me and make sure truck is following us
					ClearObjectives();
					AddObjective("follow_shab.otf", WHITE);	
					AddObjective("truck.otf", WHITE);
					watch_player_time = GetTime() + 180.0f;
					watch_player = true;
					come_here2 = true;
				}

				after_second_check = true;
			}
			else
			{
				after_second_check = true;
			}


			if (come_here2)
			{
				if ((!shab_at_jam2) && (point_check < GetTime()))
				{
					point_check = GetTime() + 1.0f;


					if (GetDistance(shabayev,"jam2_spawn") < 50.0f)
					{
						LookAt(shabayev,player);
						look_time = GetTime() + 10.0f;
						at_player = true;
						shab_at_jam2 = true;
					}
				}
			}
			else if (after_second_check)
			{
					if (GetDistance(player,shabayev) > 80.0f)
					{
						if (GetCurrentCommand(truck) == CMD_FOLLOW)
						{
							LookAt(shabayev,player);
							talk = AudioMessage("isdf0230.wav");//(shab) rondezvous with me
							ClearObjectives();
							AddObjective("follow_shab.otf", WHITE);
							watch_player_time = GetTime() + 180.0f;
							watch_player = true;
							come_here2 = true;
						}
						else
						{
							LookAt(shabayev,player);
							talk = AudioMessage("isdf0230.wav");//(shab) rondezvous with me and make sure truck is following us
							ClearObjectives();
							AddObjective("follow_shab.otf", WHITE);	
							AddObjective("truck.otf", WHITE);
							watch_player_time = GetTime() + 180.0f;
							watch_player = true;
							come_here2 = true;
						}
					}
					else
					{
						LookAt(shabayev,player);
						look_time = GetTime() + 10.0f;
						at_player = true;
						come_here2 = true;
					}
			}


			if ((!player_lost) && (come_here2) && (GetDistance(player,shabayev) < 80.0f))
			{
				if (!keep_moving_message)
				{
					blah = AudioMessage("isdf0233.wav"); // (shab) this place is hotter than hell
					onto_base_time = GetTime() + 5.0f;


					if (GetCurrentCommand(truck) != CMD_FOLLOW)
					{
						get_truck_time =  GetTime() + 3.0f;
						truck_check = GetTime() + 5.0f;
						truck_message = true;
						truck_following = false;
					}

					watch_player_time = GetTime() + 180.0f;
					watch_player = true;
					in_combat = false;
					keep_moving_message = true;
				}
			}
		}


		if ((!player_lost) && (truck_following))
		{
			if ((keep_moving_message) && (!on_to_base) && (IsAudioMessageDone(blah)))//(onto_base_time < GetTime()))
			{
				AudioMessage("isdf0234.wav"); // (shab) Lets press on!
				Retreat(shabayev,"shab_path3");
				look_time = GetTime() + 999999.9f;
				onto_base_time = GetTime() + 2.0f;
				watch_player_time = GetTime() + 999999.9f;
				watch_player = false;
				truck_message = false;
				on_to_base = true;
			}
		}
	}


	if ((on_to_base) && (IsAlive(shabayev)) && (IsAlive(truck)))
	{
		if (onto_base_time < GetTime())
		{
			onto_base_time = GetTime() + 2.0f;


			if ((!scavs_found) && (GetDistance(shabayev,"scav_point") < 40.0f))
			{
				LookAt(shabayev,player);


				if (GetDistance(shabayev,player) > 300.0f)
				{
					player_lost = true;
				}

				scavs_found = true;
			}


			if ((scavs_found) && (!player_lost))
			{
				if (!endbase_detected)
				{
					LookAt(shabayev,dead_scav1);
					look_time = GetTime() + 3.0f;
					at_player = false;
					talk = AudioMessage("isdf0235.wav"); // (shab) Constructor and Scavengers - these guys didn't have a chance. I'm detecting the base lets go!!
					endbase_detected = true;
				}
			}


			if ((endbase_detected) && (!after_scavs) && (IsAudioMessageDone(talk)))
			{
				Retreat(shabayev,"sue_path");
				look_time = GetTime() + 999999.9f;
				sue_check = GetTime() + 1.0f;
				after_scavs = true;
			}


			if ((after_scavs) && (sue_check < GetTime()))
			{
				sue_check = GetTime() + 1.0f;

				if (GetDistance(shabayev,"sue_point") < 40.0f)
				{
					AudioMessage("isdf0238.wav"); // (shab) this looks like it, lets move inside - stick with me!
					onto_base_time = GetTime() + 4.0f;
					LookAt(shabayev,player);
					look_time = GetTime() + 5.0f;
					at_player = true;

					if (!truck_following)
					{
						get_truck_time =  GetTime() + 2.0f;
						truck_message = true;
					}

					at_base = true;
/*

					if (GetDistance(shabayev,truck) > 150.0f)
					{
						AudioMessage("isdf0236.wav"); // (shab) this looks like it, lets wait here for the truck before going in
						onto_base_time = GetTime() + 10.0f;
						safe_check = GetTime() + 2.0f;
						LookAt(shabayev,player);
						look_time = GetTime() + 5.0f;
						at_player = true;


						if (!truck_following)
						{
							get_truck_time =  GetTime() + 2.0f;
							truck_message = true;
						}

						truck_wait = true;
						at_base = true;
					}
					else
					{
						AudioMessage("isdf0237.wav"); // (shab) this looks like it, lets move inside - stick with me!
						onto_base_time = GetTime() + 10.0f;
						safe_check = GetTime() + 2.0f;
						LookAt(shabayev,player);
						look_time = GetTime() + 5.0f;
						at_player = true;


						if (!truck_following)
						{
							get_truck_time =  GetTime() + 2.0f;
							truck_message = true;
						}

						at_base = true;
					}

*/
				}
			}
		}
	}
}



// this is second jammer code



if ((temp_spawn) && (!jammer2_dead))
{
	if (IsAlive(jammer2))
	{
		if ((start_second_morph) && (jammer_message_time < GetTime()))
		{
			if (!scrammbled_message2)
			{
				garbble = AudioMessage("isdf0213a.wav"); // (shab) *shab's garbled message*
				jammer_message_time = GetTime() + 25.0f;
				scrammbled_message2 = true;
			}
			else
			{
				garbble = AudioMessage("isdf0213a.wav"); // (shab) *SECOND shab's garbled message*
				jammer_message_time = GetTime() + 15.0f;
				scrammbled_message2 = false;
			}
		}
	}
	else
	{
		if (!jammer2_dead_message)
		{
			if (IsAlive(temp1))
			{
				if (IsAlive(temp2))
				{
					if (IsAlive(temp3))
					{
						AudioMessage("isdf0251.wav");//(shab) we got 3 left

						Attack(temp1,truck);
						Attack(temp2,truck);
						Attack(temp3,truck);

						three_to_go = true;
						jammer2_dead_message = true;
					}
					else
					{
						AudioMessage("isdf0252.wav");//(shab) we got 2 left

						Attack(temp1,truck);
						Attack(temp2,truck);

						two_to_go = true;
						jammer2_dead_message = true;
					}
				}
				else if (IsAlive(temp3))
				{
					AudioMessage("isdf0252.wav");//(shab) we got 2 left

					Attack(temp1,truck);
					Attack(temp3,truck);

					two_to_go = true;
					jammer2_dead_message = true;
				}
				else
				{
					AudioMessage("isdf0253.wav");//(shab) we got 1 left

					Attack(temp1,truck);

					one_to_go = true;
					jammer2_dead_message = true;
				}
			}
			else if (IsAlive(temp2))
			{
				if (IsAlive(temp3))
				{
					AudioMessage("isdf0252.wav");//(shab) we got 2 left
					
					Attack(temp2,truck);
					Attack(temp3,truck);
					
					two_to_go = true;
					jammer2_dead_message = true;
				}
				else
				{
					AudioMessage("isdf0253.wav");//(shab) we got 1 left

					Attack(temp2,truck);

					one_to_go = true;
					jammer2_dead_message = true;
				}
			}
			else if (IsAlive(temp3))
			{
				AudioMessage("isdf0253.wav");//(shab) we got 1 left

				Attack(temp3,truck);

				one_to_go = true;
				jammer2_dead_message = true;
			}
		}

		// this is special to remove the builder

		if (!builder_dead)
		{
			Damage(builder1,2000);
		}
		///////////////////////////////////////

		jammer_message_time = GetTime() + 999999.9f;
		jammer2_dead = true;
	}
}


if (three_to_go)
{
	if (!two_to_go)
	{
		if ((!IsAlive(temp1)) && (IsAlive(temp2)) && (IsAlive(temp3)))
		{
			AudioMessage("isdf0254.wav");//(shab) we got 2 left
			two_to_go = true;
		}
		else if ((!IsAlive(temp2)) && (IsAlive(temp1)) && (IsAlive(temp3)))
		{
			AudioMessage("isdf0254.wav");//(shab) we got 2 left
			two_to_go = true;
		}
		 else if ((!IsAlive(temp3)) && (IsAlive(temp1)) && (IsAlive(temp2)))
		{
			AudioMessage("isdf0254.wav");//(shab) we got 2 left
			two_to_go = true;
		}
	}
	else if (!one_to_go)
	{
		if ((IsAlive(temp1)) && (!IsAlive(temp2)) && (!IsAlive(temp3)))
		{
			AudioMessage("isdf0255.wav");//(shab) we got 1 left
			one_to_go = true;
		}
		else if ((!IsAlive(temp1)) && (IsAlive(temp2)) && (!IsAlive(temp3)))
		{
			AudioMessage("isdf0255.wav");//(shab) we got 1 left
			one_to_go = true;
		}
		 else if ((!IsAlive(temp1)) && (!IsAlive(temp2)) && (IsAlive(temp3)))
		{
			AudioMessage("isdf0255.wav");//(shab) we got 1 left
			one_to_go = true;
		}
	}
}
else if (two_to_go)
{
	if (!one_to_go)
	{
		if ((IsAlive(temp1)) && (!IsAlive(temp2)) && (!IsAlive(temp3)))
		{
			AudioMessage("isdf0255.wav");//(shab) we got 1 left
			one_to_go = true;
		}
		else if ((!IsAlive(temp1)) && (IsAlive(temp2)) && (!IsAlive(temp3)))
		{
			AudioMessage("isdf0255.wav");//(shab) we got 1 left
			one_to_go = true;
		}
		 else if ((!IsAlive(temp1)) && (!IsAlive(temp2)) && (IsAlive(temp3)))
		{
			AudioMessage("isdf0255.wav");//(shab) we got 1 left
			one_to_go = true;
		}		
	}
}


/*
//////////////////////////////////////////////////////////////////////
}

if ((!at_base) && (made_cheat) && (start_cheat < GetTime()))
{
	onto_base_time = GetTime() + 1.0f;
	shabayev = cheat;
	SetAvoidType(shabayev,0);
	SetSkill(shabayev,3);
	truck_following = true;
	player_lost = false;
	truck_wait = true;
	at_base = true;
}
//////////////////////////////////////////////////////////////////////
*/

// this is after the second battle and on to the base



if (at_base)
{
	if ((IsAlive(shabayev)) && (IsAlive(truck)))
	{
		if ((!move_to_center) && (onto_base_time < GetTime()))
		{
			onto_base_time = GetTime() + 0.5f;

			if ((truck_following) && (!player_lost) && (truck_wait))
			{
				if (GetDistance(shabayev,player) < 100.0f) //&& (GetDistance(shabayev,truck) < 150.0f))
				{
					AudioMessage("isdf0238.wav"); // (shab) Ok, lets move in - stay sharp!
					Goto(shabayev,"base_center");

					if (IsAlive(last_turret1))
					{
						SetAvoidType(last_turret1,0);
						Retreat(last_turret1,"last_turret_path");
					}

					if (IsAlive(last_turret2))
					{
						SetAvoidType(last_turret2,0);
						Retreat(last_turret2,"last_turret_path");
					}

					center_check = GetTime() + 0.5f;
					look_time = GetTime() + 999999.9f;
					truck_message = false;
					move_to_center = true;
				}
			}
			else if ((truck_following) && (!player_lost))
			{
				Goto(shabayev,"base_center");

				if (IsAlive(last_turret1))
				{
					SetAvoidType(last_turret1,0);
					Retreat(last_turret1,"last_turret_path");
				}

				if (IsAlive(last_turret2))
				{
					SetAvoidType(last_turret2,0);
					Retreat(last_turret2,"last_turret_path");
				}

				center_check = GetTime() + 0.5f;
				look_time = GetTime() + 999999.9f;
				move_to_center = true;
			}
		}


		if ((move_to_center) && (!at_center) && (center_check < GetTime()))
		{
			center_check = GetTime() + 0.5f;


			if ((!hit_hard_message) && ((GetDistance(shabayev,"base_center")) < (GetDistance(shabayev,"sue_point"))))
			{
				talk = AudioMessage("isdf0239.wav"); // (shab) looks like those things hit here pretty hard!
				hit_hard_message = true;
			}

/*
			if (GetDistance(shabayev,"base_center") < 40.0f)
			{
				if (IsAround(cons))
				{
					Goto(shabayev,cons);
				}

				AudioMessage("isdf0257.wav"); // (shab) theres the power plants - instruct the truck to repair them the same you had it repair me
				at_center = true;
			}
*/
		}


		// this is making the turrets deploy

		if ((!last_turret1_dead) && (!turrets_stop) && (move_to_center))
		{
			if (IsAlive(last_turret1))
			{
				if (GetDistance(last_turret1,"base_center") < 20.0f)
				{
					//Stop(last_turret1,0);
					Attack(last_turret1,shabayev);

					if (IsAlive(last_turret2))
					{
						//Stop(last_turret2,0);
						Attack(last_turret1,player);
					}

					turrets_stop = true;
				}
			}
			else if (IsAlive(last_turret2))
			{
				if (GetDistance(last_turret2,"base_center") < 20.0f)
				{
					//Stop(last_turret2,0);
					Attack(last_turret2,player);
					turrets_stop = true;
				}
			}
		}
		///////////////////////////////////////////

			
		// this is shab attacking the turret

		if (!attack_last_turret1)
		{
			if (IsAlive(last_turret1))
			{
				if ((hit_hard_message) && (IsAudioMessageDone(talk)))
				{
					Attack(shabayev,last_turret1);
					AudioMessage("isdf0264.wav"); // we've got company
					attack_last_turret1 = true;
				}

				if (at_base)
				{
					if ((GetTime() - GetLastEnemyShot(last_turret1) < .2f) || (GetTime() - GetLastEnemyShot(last_turret1) < .2f))
					{
						Attack(shabayev,last_turret1);
						AudioMessage("isdf0264.wav"); // we've got company
						attack_last_turret1 = true;
					}
				}
			}
			else if ((at_base) && (IsAlive(last_turret2)))
			{
				Attack(shabayev,last_turret2);
				AudioMessage("isdf0264.wav"); // we've got company
				attack_last_turret1 = true;
				attack_last_turret2 = true;
			}
		}

		// this sends her after the last turret

		if ((!attack_last_turret2) && (attack_last_turret1))
		{
			if (!IsAlive(last_turret1))
			{
				Attack(shabayev,last_turret2);
				attack_last_turret2 = true;
			}
		}
		///////////////////////////////////////////


		// checks to see when the last turret dies

		if ((!last_turret1_dead) && (!IsAlive(last_turret1)) && (!IsAlive(last_turret2)))
		{
			Goto(shabayev,"base_center");
			last_turret1_dead = true;
		}
		//////////////////////////////////////////


		// this is shab telling the player about the plan to get the constructor

		if ((!plan) && (at_base) && (last_turret1_dead))
		{
			if (GetDistance(shabayev,"base_center") < 30.0f)
			{
				talk = AudioMessage("isdf0257a.wav");// (shab) This place is crawling - we've got to get power online to this base now!
												 // I have an idea - follow me!	
				onto_base_time = GetTime() + 3.0f;
				
				LookAt(shabayev,player);
				Goto(truck,"sue_point",0);

				//if (IsAround(dead_power1))
				//{
				//	LookAt(shabayev,dead_power1);
				//}
				//else if (IsAround(dead_power2))
				//{
				//	LookAt(shabayev,dead_power2);
				//}
				
				plan = true;
			}
		}
		///////////////////////////////////////////


		// this makes shab look at the player

		if ((!plan2) && (plan) && (onto_base_time < GetTime()))
		{
			//LookAt(shabayev,player);

			if (IsAround(dead_power1))
			{
				LookAt(shabayev,dead_power1);
			}
			else if (IsAround(dead_power2))
			{
				LookAt(shabayev,dead_power2);
			}

			plan2 = true;
		}
		///////////////////////////////////////////


		// this is sending shab to the constructor

		if ((!on_to_construct) && (plan) && (IsAudioMessageDone(talk)))
		{
			Goto(shabayev,"to_builder_path");
			on_to_construct = true;
		}
		///////////////////////////////////////////
	}
}

	// make sure cons stays around
	if (!shab_switch && !game_over)
	{
		if (!IsAround(cons))
		{
			FailMission(GetTime() + 7.0f, "isdf02L1.txt");
			game_over = true;
		}
	}

	// this is the new ending code with the constructor
	
	if (on_to_construct)
	{
		if ((!shab_find_con) && (GetDistance(shabayev,cons) < 30.0f))
		{
			LookAt(shabayev,cons);
			con_wait = GetTime() + 5.0f;
			shab_find_con = true;
		}


		// this is switching out shab
		if ((!shab_switch) && (shab_find_con) && (con_wait < GetTime()))
		{
			Matrix pos;
			GetPosition(shabayev,pos);
			RemoveObject(shabayev);
			shabayev = BuildObject("ivplysct",1,pos);
			con_wait = GetTime() + 0.5f;
			shab_switch = true;
		}


		if ((shab_switch) && (!shab_hop_out) && (con_wait < GetTime()))
		{
			con_wait = GetTime() + 1.0f;

			if (GetDistance(shabayev,player) < 70.0f)
			{
				HopOut(shabayev);
				SetObjectiveOff(shabayev);
				shab_hop_out = true;
			}
		}


		if ((shab_hop_out) && (shab_out) && (!shab_to_con))
		{
			if (IsAround(shab2))
			{
				Goto(shab2,"con_spawn",1);
				//GetIn(shab2,cons,1);
				shab_to_con = true;
			}
		}


		// this is putting shab in the cons

		if ((shab_out) && (!shab_in))
		{
			if (!IsAround(shab2))
			{
				shab_dead = true;
			}

			if (!IsAround(cons))
			{
				cons_dead = true;
			}

			if ((IsAround(cons)) && (IsAround(shab2)))
			{
				if (GetDistance(cons,shab2) < 10.0f)
				{
					RemoveObject(shab2);

					SetTeamNum(cons,1);

					SetAnimation(cons,"startup",1);

					SetObjectiveOn(cons);
					SetObjectiveName(cons,"Cmd. Shabayev");

					prep_wait = GetTime() + 3.0f;

					safe_check = GetTime() + 2.0f;
/*
					RemoveObject(cons);
					shabayev = BuildObject("ivpcon",1,"con_spawn");

					//tester = BuildObject("ivpcon",1,cons);
					//RemoveObject(cons);
					//shabayev = tester;
	
					Stop(shabayev);
					SetAvoidType(shabayev,0);
					SetObjectiveOn(shabayev);
					SetObjectiveName(shabayev,"Cmd. Shabayev");
*/

					shab_in = true;
				}
			}
		}


		// this is shab talking in the constructor

		if ((shab_in) && (!prep_cons) && (prep_wait < GetTime()))
		{
			talk = AudioMessage("isdf0258a.wav"); //(shab) I'm going to build a power plant
			prep_wait = GetTime() + 5.0f;
			prep_cons = true;
		}
		///////////////////////////////////////////


		// this is me switching out the cons after the animation plays

		if ((!startup_over) && (prep_cons) && (prep_wait < GetTime()))
		{
			RemoveObject(cons);
			shabayev = BuildObject("ivpcon",1,"con_spawn");
			Stop(shabayev);
			SetAvoidType(shabayev,0);
			SetObjectiveOn(shabayev);
			SetObjectiveName(shabayev,"Cmd. Shabayev");
			prep_wait = GetTime() + 1.0f;
			startup_over = true;
		}
		///////////////////////////////////////////


		// preping the power plant

		if ((startup_over) && (!new_prep) && (prep_wait < GetTime()))
		{
			Build(shabayev,"ibpgn1");
			prep_wait = GetTime() + 0.2f;
			new_prep = true;
		}
		///////////////////////////////////////////


		// sending her to the base

		if ((!return_to_base) && (new_prep) && (prep_wait < GetTime()))
		{
			Goto(shabayev,"to_power_path2");
			prep_wait = GetTime() + 10.0f;
			return_to_base = true;
		}
		///////////////////////////////////////////


		if ((return_to_base) && (!to_power_spot) && (prep_wait < GetTime()))
		{
			prep_wait = GetTime() + 1.0f;

			// building the power plant

			if (GetDistance(shabayev,"back_at_base") < 20.0f)
			{
				AudioMessage("isdf0262.wav"); // (shab) OK I'm starting to build
				Dropoff(shabayev,"power_point",1);

				if (IsAlive(scion3))
				{
					Attack(scion3,shabayev);
				}

				to_power_spot = true;
			}
			///////////////////////////////////////////
		}
	}


// this is the code that conducts the final attack on shab and john

if (return_to_base)
{
	if ((!surprise_spawn) && (safe_check < GetTime()))
	{
		safe_check = GetTime() + 2.0f;


		if (GetDistance(player,"base_espawn2") > 200.0f)
		{
			scion1 = BuildObject("fvpsnt",2,"base_espawn1");
			scion2 = BuildObject("fvpsnt",2,"base_espawn2");
			scion3 = BuildObject("fvpsnt",2,"base_espawn3");
			Attack(scion1,shabayev);
			Attack(scion2,shabayev);
			Goto(scion3,"base_center");
			safe_check = GetTime() + 2.0f;
			surprise_spawn = true;
		}
	}

	// this is making the scion morph

	if ((surprise_spawn) && (!surprise_attack) && (safe_check < GetTime()))
	{
		safe_check = GetTime() + 1.0f;

		if ((IsAlive(scion2)) && (IsAlive(shabayev)))
		{
			if ((GetDistance(scion2,shabayev) < 100.0f) || (GetDistance(scion2,player) < 70.0f))
			{
				AudioMessage("isdf0259.wav"); // (shab) we've got company
				//Attack(scion2,shabayev);
				surprise_attack = true;
			}
		}
		else if ((IsAlive(scion1)) && (IsAlive(shabayev)))
		{
			if ((GetDistance(scion1,shabayev) < 100.0f) || (GetDistance(scion1,player) < 70.0f))
			{
				AudioMessage("isdf0259.wav"); // (shab) we've got company
				//Attack(scion1,shabayev);
				surprise_attack = true;
			}
		}
	}
	///////////////////////////////////////////

	if ((!last_wave_dead) && (!extra_help) && (surprise_spawn))
	{
		if ((!IsAlive(scion1)) && (IsAlive(scion3)))
		{
			scion1 = BuildObject("fvpsnt",2,"base_espawn1");
			Attack(scion1,shabayev);
			extra_help = true;
		}
	}

	// this is checking to see when the last wave is dead

	if ((surprise_spawn) && (!IsAlive(scion1)) && (!IsAlive(scion2)) && (!IsAlive(scion3)))
	{
		last_wave_dead = true;
	}
	///////////////////////////////////////////
}



//////////////////////////////////////////////////////////////////////
//if (!ON_HOLD)
//{
//////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////
}
//////////////////////////////////////////////////////////////////////



// these are the win/loose conditions


if (!game_over)
{
		// this is if the player's ship gets destroyed
	if ((player_ship == NULL) && (!ship_destroyed))
	{
		ship_destroyed_time = GetTime() + 2.0f;
		ship_destroyed = true;
	}


	if ((ship_destroyed) && (!game_over) && (ship_destroyed_time < GetTime()))
	{
		AudioMessage("isdf0154.wav"); // (shab) we don't have another ship in the area!
		FailMission(GetTime() + 7.0f);
		game_over = true;
	}


	if ((first_warning) && (!game_over) && (first_warning_time < GetTime()))
	{
		AudioMessage("isdf0242.wav"); // (shab) if you cannot follow my orders I'll leave you behind
		FailMission(GetTime() + 7.0f);
		game_over = true;
	}


	if ((return_message1) && (!game_over) && (player_lost_time < GetTime()))
	{
		AudioMessage("isdf0242.wav"); // (shab) if you cannot follow my orders I'll leave you behind
		FailMission(GetTime() + 7.0f);
		game_over = true;
	}


	// this is checking to see if shabayev gets killed

	if ((!shab_hop_out) && (free_truck) && (!IsAround(shabayev)))
	{
		if (IsAlive(truck))
		{
			AudioMessage("isdf0243.wav"); // (truck) you let the commander get killed!
			FailMission(GetTime() + 7.0f);
			game_over = true;
		}
		else
		{
			FailMission(GetTime() + 7.0f);
			game_over = true;
		}
	}
	else if ((startup_over) && (!IsAround(shabayev)))
	{
		if (IsAlive(truck))
		{
			AudioMessage("isdf0243.wav"); // (truck) you let the commander get killed!
			FailMission(GetTime() + 7.0f);
			game_over = true;
		}
		else
		{
			FailMission(GetTime() + 7.0f);
			game_over = true;
		}
	}
	/////////////////////////////////////////////////


	if ((!IsAlive(truck)) && (IsAlive(shabayev)))
	{
		AudioMessage("isdf0244.wav"); // (shab) you let the truck get killed!
		FailMission(GetTime() + 7.0f);
		game_over = true;
	}


	if ((!shab_in) && (cons_dead))
	{
		FailMission(GetTime() + 7.0f);
		AudioMessage("isdf0260.wav"); // (shab) I need that constructor!
		game_over = true;
	}


	if (shab_dead)
	{
		if (IsAlive(truck))
		{
			AudioMessage("isdf0243.wav"); // (truck) you let the commander get killed!
			FailMission(GetTime() + 7.0f);
			game_over = true;
		}
		else
		{
			FailMission(GetTime() + 7.0f);
			game_over = true;
		}
	}


	if ((!movie1) && (base_powered) && (last_wave_dead))
	{
		AudioMessage("cin0201.wav"); // (shab) well done john!

		pole3_time = GetTime() + 2.0f;
		pole4_time = GetTime() + 3.5f;
		pole5_time = GetTime() + 5.0f;
		pole6_time = GetTime() + 6.5f;
		pole7_time = GetTime() + 8.0f;
		pole8_time = GetTime() + 9.5f;
		pole9_time = GetTime() + 11.0f;
		pole10_time = GetTime() + 12.5f;
		pole11_time = GetTime() + 14.0f;

		if (IsAround(pole3))
		{
			RemoveObject(pole3);
			pole3 = BuildObject("pbtele01a",0,"pole3_point");
		}
		if (IsAround(pole4))
		{
			RemoveObject(pole4);
			pole4 = BuildObject("pbtele01a",0,"pole4_point");
		}
		if (IsAround(pole5))
		{
			RemoveObject(pole5);
			pole5 = BuildObject("pbtele01a",0,"pole5_point");
		}
		if (IsAround(pole6))
		{
			RemoveObject(pole6);
			pole6 = BuildObject("pbtele01a",0,"pole6_point");
		}
		if (IsAround(pole7))
		{
			RemoveObject(pole7);
			pole7 = BuildObject("pbtele01a",0,"pole7_point");
		}
		if (IsAround(pole8))
		{
			RemoveObject(pole8);
			pole8 = BuildObject("pbtele01a",0,"pole8_point");
		}
		if (IsAround(pole9))
		{
			RemoveObject(pole9);
			pole9 = BuildObject("pbtele01a",0,"pole9_point");
		}
		if (IsAround(pole10))
		{
			RemoveObject(pole10);
			pole10 = BuildObject("pbtele01a",0,"pole10_point");
		}
		if (IsAround(pole11))
		{
			RemoveObject(pole11);
			pole11 = BuildObject("pbtele01a",0,"pole11_point");
		}

		movie1 = true;
	}

	// this is the movie code
	
	if ((movie1) && (!game_over))
	{
		if (!firstFrame) 
		{
			CameraReady();

			firstFrame = true;
		}

		CameraPath("camera_point2", 700, 0, look_pole);
		//movie1 = PlayMovie("lights2");
	}
	///////////////////////////////////////////


	// this switches the poles

	if ((!pole3_switch) && (pole3_time < GetTime()))
	{
		Matrix pos;
		GetPosition(pole3,pos);
		RemoveObject(pole3);
		pole3 = BuildObject("pbtele01",1,pos);

		//RemoveObject(pole3);
		//BuildObject("pbtele01",0,"pole3_point");
		pole3_switch = true;
	}

	if ((!pole4_switch) && (pole4_time < GetTime()))
	{
		Matrix pos;
		GetPosition(pole4,pos);
		RemoveObject(pole4);
		pole4 = BuildObject("pbtele01",1,pos);

		//RemoveObject(pole4);
		//BuildObject("pbtele01",0,"pole4_point");
		pole4_switch = true;
	}

	if ((!pole5_switch) && (pole5_time < GetTime()))
	{
		Matrix pos;
		GetPosition(pole5,pos);
		RemoveObject(pole5);
		pole5 = BuildObject("pbtele01",1,pos);

		//RemoveObject(pole5);
		//BuildObject("pbtele01",0,"pole5_point");
		pole5_switch = true;
	}

	if ((!pole6_switch) && (pole6_time < GetTime()))
	{
		Matrix pos;
		GetPosition(pole6,pos);
		RemoveObject(pole6);
		pole6 = BuildObject("pbtele01",1,pos);

		//RemoveObject(pole6);
		//BuildObject("pbtele01",0,"pole6_point");
		pole6_switch = true;
	}

	if ((!pole7_switch) && (pole7_time < GetTime()))
	{
		Matrix pos;
		GetPosition(pole7,pos);
		RemoveObject(pole7);
		pole7 = BuildObject("pbtele01",1,pos);

		//RemoveObject(pole7);
		//BuildObject("pbtele01",0,"pole7_point");
		pole7_switch = true;
	}

	if ((!pole8_switch) && (pole8_time < GetTime()))
	{
		Matrix pos;
		GetPosition(pole8,pos);
		RemoveObject(pole8);
		pole8 = BuildObject("pbtele01",1,pos);

		//RemoveObject(pole8);
		//BuildObject("pbtele01",0,"pole8_point");
		pole8_switch = true;
	}

	if ((!pole9_switch) && (pole9_time < GetTime()))
	{
		Matrix pos;
		GetPosition(pole9,pos);
		RemoveObject(pole9);
		pole9 = BuildObject("pbtele01",1,pos);

		//RemoveObject(pole9);
		//BuildObject("pbtele01",0,"pole9_point");
		pole9_switch = true;
	}

	if ((!pole10_switch) && (pole10_time < GetTime()))
	{
		Matrix pos;
		GetPosition(pole10,pos);
		RemoveObject(pole10);
		pole10 = BuildObject("pbtele01",1,pos);

		//RemoveObject(pole10);
		//BuildObject("pbtele01",0,"pole10_point");
		pole10_switch = true;
	}

	if ((!pole11_switch) && (pole11_time < GetTime()))
	{
		Matrix pos;
		GetPosition(pole11,pos);
		RemoveObject(pole11);
		pole11 = BuildObject("pbtele01",1,pos);

		//RemoveObject(pole11);
		//BuildObject("pbtele01",0,"pole11_point");
		pole11_time = GetTime() + 2.0f;
		pole11_switch = true;
	}
	///////////////////////////////////////////


	if ((pole11_switch) && (pole11_time < GetTime()))
	{
		SucceedMission(GetTime() + 0.1f,"isdf02w1.txt");
		CameraFinish();
		game_over = true;
	}
	///////////////////////////////////////////
}



}
