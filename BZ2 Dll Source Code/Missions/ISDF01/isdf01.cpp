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
		ON_HOLD,start_done,shab_down_path1,shab_down_path2,shab_down_path3,
		shab_at_point1,shab_at_point2,shab_at_point3,shab_at_cliff,shab_down_tight,
		shab_at_base,player_lost,player_lost2,set_lost_times,second_warning,game_over,
		squad1_start,squad1_off,shab_shot,first_time,roger_message,message1,base_center,
		left_base,shab_to_center,shab_centered,search_base,return_to_base, return_to_base2,
		encouragement,first_leave,wingman_away,shab_to_tunnel,comm_identified,johns_orders,
		comm_help,find_herself,shab_at_comm,ship_destroyed,wingman_message1,shab_response,
		shab_warning1,shab_response1,john_in_ship,on_route,base_detected,throttle_down,
		in_range,targeted, scion1_target, scion2_target,in_combat,battle1_over,roger1,
		wingman_report,next_wave1,returned,second_dead,base_return,
		
		mayday_message1, mayday_message2, mayday_message3, mayday_message4, mayday_message5,
		next_detected,john_away,attack2,freed,john_close,battle2_over,thanks_message,
		red1_return,coward2,truck_found, no_find_truck,truck_response1,truck_response2,
		truck_response3,truck_return,last_wave_dead,last_spawned,out_of_ship,inside, fire_message,
		at_player, squad1_astop, squad1_bstop, squad1_cstop, jumped, cheat_death, giveahand, bubba,
		cliff_fall, player_there,wingat_player, single_dead, bang_up_message, return_message, 
		radio_for_help, alt_message1,alt_message2, alt_message3, alt_message4, to_goalone, change_look1, 
		goto_sbay, last_message, last_attack, gus, the_end, tubby, wait_4_wing, wing_orders, go_shab_go,
		at_sbay, last_message2, squad1_talk, wing_look, wing_first, wingman_there, shab_through,
		to_comm, shab_wait, done, shab_hold, wing_hold, plane_time_set, reroute1, player_off,

		stayput,door_open,release_crew,up_quake,landed,pilot_speak1,pilot_speak2,pilot_speak3,
		landed_message,free_player,clear_warning,remove_condor1,remove_condor2,go_shab_go2,
		turret_detected,turret_retreat,shab_turret_comment,shab_cutoff_turret,turret_dead,
		turret_deploy,turret_hostle,alert_skyeye,simms_turret_comment,shab_weapon_comment,
		wing_lookat_turret,in_comm,cineractive_over,simms_tank_comment,first_scion_dead,
		simms_panic,player_awl,squad1_stopped,what_doing,didnt_listen,at_doors,
		crate1_dead,crate2_dead,crate3_dead,crate4_dead,crate5_dead,crate6_dead,crate7_dead,crate8_dead,
		last_crate_dead,red_look_truck,very_last_message,extra_spawned,hold_fire_message,
		start_cineractive,line2,line3,line4,line5,line6,line7,
		camera1_over,camera2_over,first_frame,fade_done,first_squad_removed,
		camera3_over,camera4_over,movie1,movie2,reframe1,chatter1,chatter_set,
		b_last;

	// floats
	float
		f_first,
		wait_time,wait1_time,wait2_time,player_lost_time,lost_warning_time,
		return_check_time,shot_me_time,message_time,cliff_check,base_check_time,
		comm_check_time,shab_comm_check,ship_destroyed_time,john_ship_check,
		dialog1_time,dialog2_time,on_route_check,coward_check,coward_message,
		next_wave_time,return_time,away_check,attack_check,red1_check,truck_check,
		away_check2,truck_lost_check,truck_talk_time,spawn_check,out_check, fire_reset,
		look_time, squad1_time, john_check, whatever, wing_look_time, lula_time,
		to_alone_check, facing_time, last_check, wingman_check, tunnel_check,planes_wait,
		open_doors_time,quake_time,pilot_speak_time,release_player_time,
		off_drop_check,condor2_remove_time,condor1_remove_time,tit_time,wingy,
		really_last_time,emit_time,camera_time,fade_time,next_shot_time,chatter_time,
		f_last;

	// handles
	Handle
		h_first,
		squad1_a, squad1_b, squad1_c,
		squad2_a, squad2_b, squad2_c,
		player,
		wingman,
		shabayev,
		comm_building,
		player_ship,
		scion1, scion2, scion3,
		red1, red2, truck, talk,
		storage_bay,
		power_up1, power_up2, power_up3, power_up4,
		condor1, condor2,
		holder1,holder2,holder3,
		nav,speak,turret,
		dead_tank,magic_crate,
		crate1,crate2,crate3,crate4,crate5,crate6,crate7,crate8,
		last_crate,
		crumble_cliff,
		smoker1,smoker2,smoker3,smoker4,
		look_thing,manson,
		line,pilot,
		h_last;

	// integers
	int
		i_first,
		x, y, a,
		h1,a1,
		h2,a2,
		quake_level,
		i_last;
};
DLLBase * BuildMission(void)
{
	return new Misn04Mission();
}

void Misn04Mission::Setup(void)
{
/*
	Here's where you set the values at the start.  
*/

	SetAutoGroupUnits(false);

//  bools
	movie1 = true;movie2 = false;reframe1 = false;
	ON_HOLD = false;

	start_done = false;
	shab_down_path1 = false; what_doing = false; didnt_listen = false;
	shab_down_path2 = false; at_doors = false;
	shab_down_path3 = false;
	shab_at_point1 = false;
	shab_at_cliff = false;
	shab_at_point2 = false;
	shab_at_point3 = false;
	shab_down_tight = false;
	shab_at_base = false;
	player_lost = false;
	player_lost2 = false;
	set_lost_times = false;
	second_warning = false;
	game_over = false;
	squad1_start = false;
	squad1_off = false;
	shab_shot = false;
	first_time = true;
	roger_message = false;
	message1 = false;
	base_center = false;
	left_base = false;
	shab_centered =false;
	shab_to_center = false;
	search_base = false;
	return_to_base = false;
	return_to_base2 = false;
	encouragement = false;
	first_leave = false;
	wingman_away = false;
	shab_to_tunnel = false;
	comm_identified = false;
	johns_orders = false;
	comm_help = false;
	find_herself = false;
	shab_at_comm = false;
	ship_destroyed = false;
	wingman_message1 = false;
	shab_response = false;
	shab_warning1 = false;
	shab_response1 = false;
	john_in_ship = false;
	on_route = false;
	base_detected = false;
	throttle_down = false;
	in_range = false;
	targeted = false;
	scion1_target = false;
	scion2_target = false;
	coward_message = false;
	in_combat = false;
	battle1_over = false;
	roger1 = false;
	wingman_report = false;
	next_wave1 = false;
	returned = false;
	second_dead = false;
	base_return = false;
	mayday_message1 = false;
	mayday_message2 = false;
	mayday_message3 = false;
	mayday_message4 = false;
	mayday_message5 = false;
	next_detected = false;
	john_away = false;
	attack2 = false;
	truck_return = false;
	freed = false;
	john_close = false;
	battle2_over = false;
	thanks_message = false;
	red1_return = false;
	coward2 = false;
	truck_found = false;
	no_find_truck = false;
	truck_response1 = false;
	truck_response2 = false;
	truck_response3 = false;
	last_wave_dead = false;
	last_spawned = false;
	out_of_ship = false;
	inside = false;
	fire_message = false;
	at_player = false;
	squad1_astop = false;
	squad1_bstop = false;
	squad1_cstop = false;
	jumped = false;
	cheat_death = false;
	giveahand = false;
	bubba = false;
	cliff_fall = false;
	player_there = false;
	wingat_player = false;
	single_dead = false;
	bang_up_message = false;
	return_message = false;
	radio_for_help = false;
	alt_message1 = false;
	alt_message2 = false;
	alt_message3 = false;
	alt_message4 = false;
	to_goalone = false;
	change_look1 = false;
	goto_sbay = false;
	at_sbay = false;
	last_message = false;
	last_message2 = false;
	last_attack = false;
	gus = false;
	the_end = false;
	tubby = false;
	wait_4_wing = false;
	wing_orders = false;
	go_shab_go = false;
	squad1_talk = false;
	wing_look = false;
	wing_first = false;
	wingman_there = false;
	shab_through = false;
	to_comm = false;
	shab_wait = false;
	done = false;
	shab_hold = false;
	wing_hold = false;
	plane_time_set = false;
	reroute1 = false;
	player_off = false;
	stayput = false;
	door_open = false;
	release_crew = false;
	up_quake = false;
	landed = false;
	pilot_speak1 = false; pilot_speak2 = false; pilot_speak3 = false;
	landed_message = false;
	free_player = false;
	clear_warning = false;
	remove_condor1 = false; remove_condor2 = false;
	go_shab_go2 = false;
	turret_detected = false;
	turret_retreat = false;
	shab_turret_comment = false;
	shab_cutoff_turret = false;
	turret_dead = false;
	turret_deploy = false;
	turret_hostle = false;
	alert_skyeye = false;
	simms_turret_comment = false; shab_weapon_comment = false;
	wing_lookat_turret = false;
	in_comm = false; cineractive_over = false; simms_tank_comment = false;
	first_scion_dead = false; simms_panic = false; player_awl = false;
	squad1_stopped = false;
	crate1_dead = false; crate2_dead = false; crate3_dead = false; crate4_dead = false; 
	crate5_dead = false; crate6_dead = false; crate7_dead = false; crate8_dead = false; 
	last_crate_dead = false; red_look_truck = false;
	very_last_message = false; extra_spawned = false;
	hold_fire_message = false;
	start_cineractive = false;
	line2 = false; line3 = false; line4 = false; line5 = false; line6 = false; line7 = false;
	camera1_over = false; camera2_over = false; 
	first_frame = false; fade_done = false;first_squad_removed = false;
	camera3_over = false; camera4_over = false; 
	chatter1 = false; 
	chatter_set = false; 

//  floats
	wait_time = 999999.9f;
	wait1_time = 999999.9f;
//wait2_time = 10.0f;
	wait2_time = 999999.9f;
	player_lost_time = 999999.9f;
	return_check_time = 999999.9f;
	lost_warning_time = 999999.9f;
	shot_me_time = 999999.9f;
	message_time = 999999.9f;
	cliff_check = 999999.9f;
	base_check_time = 999999.9f;
	comm_check_time = 999999.9f;
	shab_comm_check = 999999.9f;
	ship_destroyed_time = 999999.9f;
	dialog1_time = 999999.9f;
	on_route_check = 999999.9f;
	john_ship_check = 999999.9f;
	coward_check = 999999.9f;
	dialog2_time = 999999.9f;
	next_wave_time = 999999.9f;
	return_time = 999999.9f;
	away_check = 999999.9f;
	attack_check = 999999.9f;
	red1_check = 999999.9f;
	truck_check = 999999.9f;
	truck_lost_check = 999999.9f;
	truck_talk_time = 999999.9f;
	away_check2 = 999999.9f;
	spawn_check = 999999.9f;
	out_check = 999999.9f;
	fire_reset = 999999.9f;
	look_time = 999999.9f;
	squad1_time = 999999.9f;
	john_check = 999999.9f;
	whatever = 999999.9f;
	wing_look_time = 999999.9f;
	lula_time = 999999.9f;
	to_alone_check = 999999.9f;
	facing_time = 999999.9f;
	last_check = 999999.9f;
	wingman_check = 999999.9f;
	tunnel_check = 999999.9f;
	planes_wait = 999999.9f;
	open_doors_time = 999999.9f;
	quake_time = 999999.9f;
	pilot_speak_time = 999999.9f;
	release_player_time = 999999.9f;
	off_drop_check = 999999.9f;
	condor2_remove_time = 999999.9f;
	condor1_remove_time = 999999.9f;
	tit_time = 999999.9f;
	wingy = 999999.9f;
	really_last_time = 999999.9f;
	emit_time = 999999.9f;
	camera_time = 999999.9f;
	fade_time = 5.0f;
	next_shot_time = 999999.9f;
	chatter_time = 999999.9f;

//  handles
	player = GetPlayerHandle();
	shabayev = GetHandle("shabayev");
	squad1_a = GetHandle("squad1_a");
	squad1_b = GetHandle("squad1_b");
	squad1_c = GetHandle("squad1_c");
	wingman = GetHandle("wingman");
	comm_building = GetHandle("comm_building");
	player_ship = GetHandle("player_ship");
	storage_bay = GetHandle("storage_bay");
	condor1 = GetHandle("condor1");
	condor2 = GetHandle("condor2");
	turret = GetHandle("turret");
	dead_tank = GetHandle("dead_tank");
	magic_crate = GetHandle("magic_crate");
	crate1 = GetHandle("crate1");
	crate2 = GetHandle("crate2");
	crate3 = GetHandle("crate3");
	crate4 = GetHandle("crate4");
	crate5 = GetHandle("crate5");
	crate6 = GetHandle("crate6");
	//crate7 = GetHandle("crate7");
	crate8 = NULL;
	last_crate = GetHandle("last_crate");
	crumble_cliff = GetHandle("crumble_cliff");
	look_thing = GetHandle("look_thing");
	manson = GetHandle("manson");
	scion1 = NULL;
	scion2 = NULL;
	scion3 = NULL;
	red1 = NULL;
	red2 = NULL;
	truck = NULL;
	holder1 = NULL; holder2 = NULL; holder3 = NULL;
	nav = NULL;
	smoker1 = NULL; smoker2 = NULL; smoker3 = NULL; smoker4 = NULL;
	speak = 0;
	talk = 0;
	line = 0;
	pilot = NULL;


//  integers
	a = 5;
	x = NULL;
	y = NULL;
	h1 = NULL;
	a1 = NULL;
	h2 = NULL;
	a2 = NULL;
	quake_level = 0;

	SetTeamColor(3,255,50,50);  //Red

	Ally(1,3);
	Ally(3,1);
}

void Misn04Mission::AddObject(Handle h)
{
	char ODFName[64];
	GetObjInfo(h, Get_CFG, ODFName);

	if (IsOdf2(h,"ibnav"))
	{
		nav = h;
		RemoveObject(nav);
	}
	else if (IsOdf2(h,"fspilo"))
	{
		pilot = h;
		Damage(pilot,100);
		//RemoveObject(pilot);
	}
}

bool Misn04Mission::PostLoad(bool missionSave)
{
	bool ret = SPMission::PostLoad(missionSave);

	if (missionSave)
		return ret;

	SetTeamColor(3,255,50,50);  //Red

	return ret;
}

void Misn04Mission::Execute(void)
{
/*
	Here is where you put what happens every frame.  
*/
	char tempstr[128];

	player = GetPlayerHandle();


	// this checks to see of the player is out of his ship

	if (IsOdf(player,"ivplysct"))
	{
		out_of_ship = false;
	}
	else
	{
		out_of_ship = true;
	}
	/////////////////////////////////////////////////
/*
	if (fade_time < GetTime())
	{
		fade_done = true;
	}

	if (!fade_done)
	{
		SetColorFade(0,-5.0f,RGBA_MAKE(0, 0, 0, 255));
	}

*/

/////////////////////////////////////////////////////////////	
if (!ON_HOLD)
{
/////////////////////////////////////////////////////////////	


	
	// this removes the condors

	if (!remove_condor1)
	{
		if (condor1_remove_time < GetTime())
		{
			RemoveObject(condor1);
			//RemoveObject(smoker1);
			//RemoveObject(smoker2);
			remove_condor1 = true;
		}
	}

	if (!remove_condor2)
	{
		if (condor2_remove_time < GetTime())
		{
			RemoveObject(condor2);
			//RemoveObject(smoker3);
			//RemoveObject(smoker4);
			remove_condor2 = true;
		}
	}
	/////////////////////////////////////////////////


if ((!player_off) && (!game_over))
{
	// this holds the player in place

	if (!stayput)
	{
		SetColorFade(1,0.5f,RGBA_MAKE(0, 0, 0, 255));

		//SetColorFade(0, - 1.0f,RGBA_MAKE(0, 0, 0, 255));

		MaskEmitter(condor2, 0);

		holder1 = BuildObject("stayput",0,player);
		holder2 = BuildObject("stayput",0,shabayev);
		holder3 = BuildObject("stayput",0,wingman);

		RemoveObject(squad1_a);
		RemoveObject(squad1_b);
		RemoveObject(squad1_c);
		SetTeamNum(shabayev,1);
		SetTeamNum(wingman,1);
		//SetAvoidType(squad1_a,0);
		//SetAvoidType(squad1_b,0);
		//SetAvoidType(squad1_c,0);
		//Stop(squad1_a);
		//Stop(squad1_b);
		//Stop(squad1_c);

		LookAt(shabayev,look_thing);
		LookAt(wingman,look_thing);

		StartEarthQuake(5.0);
		quake_time = GetTime() + 15.0f;
		pilot_speak_time = GetTime() + 3.0f;

		stayput = true;
	}
	/////////////////////////////////////////////////

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

	// this is the pilot VO

	if ((!pilot_speak1) && (pilot_speak_time < GetTime()))
	{
		ClearObjectives();
		AddObjective("isdf0101a.otf", WHITE);
		speak = AudioMessage("isdf0163a.wav");// (pilot) crossing 12 hundred watch that wake
		pilot_speak1 = true;
	}


	if ((!pilot_speak2) && (pilot_speak1) && (IsAudioMessageDone(speak)))
	{
		speak = AudioMessage("isdf0164b.wav"); // (pilot) roger prepare for landing
		quake_time = GetTime() + 12.0f;
		pilot_speak2 = true;
	}
	/////////////////////////////////////////////////
/*
	// this is playing the chatter wav

	if (!chatter1)
	{
		if ((!chatter_set) && (pilot_speak2) && (IsAudioMessageDone(speak)))
		{
			chatter_time = GetTime() + 5.0f;
			chatter_set = true;
		}

		if ((chatter_set) && (chatter_time < GetTime()))
		{
			speak = AudioMessage("chatter6.wav"); // (pilot) chatter
			chatter_time = GetTime() + 99999.9f;
			chatter1 = true;
		}
	}
*/
	// this makes the quake bigger

	if ((!up_quake) && (quake_time < GetTime()))
	{
		quake_time = GetTime() + 0.4f;
		UpdateEarthQuake(30.0);
		up_quake = true;
	}
	/////////////////////////////////////////////////


	// this is the landing

	if ((!landed) && (up_quake) && (quake_time < GetTime()))
	{
		StopEarthQuake();

		LookAt(shabayev,look_thing);
		LookAt(wingman,look_thing);

		quake_time = GetTime() + 3.0f;
		landed = true;
	}
	/////////////////////////////////////////////////


	// this is the on the gound message

	if ((!landed_message) && (landed) && (quake_time < GetTime()))
	{
		speak = AudioMessage("isdf0164c.wav");// (pilot) we are on the ground
		landed_message = true;
	}
	

	// this is shabs message after the landing

	if ((!pilot_speak3) && (landed_message) && (IsAudioMessageDone(speak)))
	{
		SetObjectiveOn(shabayev);

		LookAt(shabayev,wingman);
		look_time = GetTime() + 5.0f;
		at_player = false;

		SetObjectiveName(shabayev,"Cmd. Shabayev");
		speak = AudioMessage("isdf0165.wav");// (shab) follow me off the ship
		open_doors_time = GetTime() + 8.0f;
		pilot_speak3 = true;
	}
	/////////////////////////////////////////////////

/*
	// this will make shab look at the doors

	if ((!at_doors) && (pilot_speak3) && (IsAudioMessageDone(speak)))
	{
		LookAt(shabayev,wingman);
		look_time = GetTime() + 5.0f;
		at_doors = true;
	}
*/
	
	// this opens the doors

	if ((!door_open) && (pilot_speak3) && (open_doors_time < GetTime()))
	{
		//StartSoundEffect("dropdoor.wav");
		SetAnimation(condor1,"deploy",1);
		open_doors_time = GetTime() + 3.0f;
		door_open = true;
	}
	/////////////////////////////////////////////////


	// this releases the ships

	if ((!release_crew) && (door_open) && (open_doors_time < GetTime()))
	{
		StartSoundEffect("dropdoor.wav");
		RemoveObject(holder2);
		RemoveObject(holder3);
		open_doors_time = GetTime() + 2.0f;
		release_crew = true;
	}
	/////////////////////////////////////////////////


	// this is holding shab and the wingman

	if (!release_crew)
	{
		if (IsAlive(shabayev))
		{
			Stop(shabayev);
		}
		if (IsAlive(wingman))
		{
			Stop(wingman);
		}
	}
	/////////////////////////////////////////////////


	// this sends shab off the ship

	if ((!start_done) && (release_crew) && (open_doors_time < GetTime()))
	{
		MaskEmitter(condor1, 0);

		SetPerceivedTeam(turret,1);

		//RemoveObject(holder2);
		//RemoveObject(holder3);
		RemoveObject(look_thing);

		SetAvoidType(shabayev,0);
		SetAvoidType(wingman,0);
		Goto(shabayev,"shab_firststoppoint",1);
		Goto(wingman,"wingoffdrop_path",1);

		release_player_time = GetTime() + 2.0f;

		squad1_a = BuildObject("p1scout",3,"a_spawn");
		squad1_b = BuildObject("p1scout",3,"b_spawn");
		squad1_c = BuildObject("p1scout",3,"c_spawn");
		SetAvoidType(squad1_a,0);
		SetAvoidType(squad1_b,0);
		SetAvoidType(squad1_c,0);
		Stop(squad1_a);
		Stop(squad1_b);
		Stop(squad1_c);

		open_doors_time = GetTime() + 99999.9f;

		start_done = true;
	}
	/////////////////////////////////////////////////


	// this frees the player

	if ((!free_player) && (start_done) && (release_player_time < GetTime()))
	{
		ClearObjectives();
		//Goto(wingman,"wingoffdrop_path",1);
		AddObjective("isdf0101.otf", WHITE);
		RemoveObject(holder1);
		free_player = true;
	}


	// makes shab stop and look at player

	if ((!shab_hold) && (start_done) && (GetDistance(shabayev,"shab_firststoppoint") < 20.0f))
	{
		LookAt(shabayev,player);
		SetAnimation(condor2,"takeoff",1);
		StartEmitter(condor2, 1);
		StartEmitter(condor2, 2);
		StartSoundEffect("dropleav.wav",condor2);
		//smoker3 = BuildObject("kickup",0,"smoker2_a");
		//smoker4 = BuildObject("kickup",0,"smoker2_b");		
		off_drop_check = GetTime() + 15.0f;
		condor2_remove_time = GetTime() + 15.0f;
		look_time = GetTime() + 6.0f;
		at_player = true;
		shab_hold = true;
	}
	///////////////////////////////////////////


	// makes the wingman stop and look at shab

	if ((!wing_hold) && (free_player) && (GetDistance(wingman,"wing_first_point") < 20.0f))
	{
		LookAt(wingman,shabayev);
		wing_hold = true;
	}
	///////////////////////////////////////////


	// this is checking to see when the player is off the ship

	if (!player_off)
	{
		if (shab_hold)
		{
			if (GetDistance(player,shabayev) < 30.0f)
			{
				SetAnimation(condor1,"takeoff",1);
				StartSoundEffect("dropleav.wav",condor1);
				emit_time = GetTime() + 3.0f;
				condor1_remove_time = GetTime() + 20.0f;
				message_time = GetTime() + 7.0f;
				hold_fire_message = true;
				player_off = true;
			}

			if ((!clear_warning) && (off_drop_check < GetTime()))
			{
				speak = AudioMessage("isdf0166.wav"); // (shab) clear the ship John
				off_drop_check = GetTime() + 30.0f;
				clear_warning = true;
			}
		}
	}
	/////////////////////////////////////////////////
}
else if (!game_over)
{
	// this is checking to make sure the player does not attack his wingman

	if ((!in_combat) && (!fire_message))
	{
		if ((!hold_fire_message) && (IsAlive(shabayev)) && (IsAlive(player)))
		{
			if (GetTime() - GetLastFriendShot(shabayev) < .2f)
			{
				AudioMessage("ff01.wav"); // (shab) watch your firing!
				fire_reset = GetTime() + 2.f;
				fire_message = true;
			}
		}


		if ((!hold_fire_message) && (IsAlive(wingman)) && (IsAlive(player)))
		{
			if (GetTime() - GetLastFriendShot(wingman) < .2f)
			{
				AudioMessage("ff02.wav"); // (wingman) watch your firing!
				fire_reset = GetTime() + 2.f;
				fire_message = true;
			}
		}


		if ((shab_at_point1) && (IsAlive(red1)) && (IsAlive(player)))
		{
			if (GetTime() - GetLastFriendShot(red1) < .2f)
			{
				AudioMessage("ff03.wav"); // (red1) watch your firing!
				fire_reset = GetTime() + 2.f;
				fire_message = true;
			}
		}


		//if ((IsAlive(truck)) && (IsAlive(player)))
		//{
		//	if (GetTime() - GetLastFriendShot(truck) < .2f)
		//	{
		//		AudioMessage("ff01.wav"); // (truck) watch your firing!
		//		fire_reset = GetTime() + 2.f;
		//		fire_message = true;
		//	}
		//}
	}


	if ((fire_message) && (fire_reset < GetTime()))
	{
		fire_reset = GetTime() + 999999.9f;
		fire_message = false;
	}
	/////////////////////////////////////////////////


	// this keeps wingman alive

	if ((IsAlive(wingman)) && (GetCurHealth(wingman) < 200))
	{
		SetCurHealth(wingman, 800);
	}


	if (look_time < GetTime())
	{
		if (!at_player)
		{
			LookAt(shabayev,player);
			look_time = GetTime() + 15.0f;
			at_player = true;
		}
		else if (IsAlive(wingman))
		{
			LookAt(shabayev,wingman);
			look_time = GetTime() + 9.0f;
			at_player = false;
		}
	}
	/////////////////////////////////////////////////

	
	// this is the crate code

	if (shab_at_base)
	{
		if ((!crate1_dead) && (GetCurHealth(crate1) < 10))
		{
			BuildObject("apammo",1,crate1);
			Damage(crate1,20);
			crate1_dead = true;
		}
		if ((!crate2_dead) && (GetCurHealth(crate2) < 10))
		{
			BuildObject("aprepa",1,crate2);
			Damage(crate2,20);
			crate2_dead = true;
		}
		if ((!crate3_dead) && (GetCurHealth(crate3) < 10))
		{
			BuildObject("apammo",1,crate3);
			Damage(crate3,20);
			crate3_dead = true;
		}
		if ((!crate4_dead) && (GetCurHealth(crate4) < 10))
		{
			BuildObject("aprepa",1,crate4);
			Damage(crate4,20);
			crate4_dead = true;
		}
		if ((!crate5_dead) && (GetCurHealth(crate5) < 10))
		{
			BuildObject("apammo",1,crate5);
			Damage(crate5,20);
			crate5_dead = true;
		}
		if ((!crate6_dead) && (GetCurHealth(crate6) < 10))
		{
			BuildObject("aprepa",1,crate6);
			Damage(crate6,20);
			crate6_dead = true;
		}
		//if ((!crate7_dead) && (GetCurHealth(crate7) < 10))
		//{
		//	BuildObject("apammo",1,crate7);
		//	Damage(crate7,20);
		//	crate7_dead = true;
		//}
		//if ((!crate8_dead) && (GetCurHealth(crate8) < 10))
		//{
		//	BuildObject("aprepa",1,crate8);
		//	Damage(crate8,20);
		//	crate8_dead = true;
		//}
		if ((!last_crate_dead) && (GetCurHealth(last_crate) < 10))
		{
			BuildObject("apammo",1,last_crate);
			Damage(last_crate,20);
			last_crate_dead = true;
		}
	}

}

	// this starts the emmiters and the kickup

	if (emit_time < GetTime())
	{
		StartEmitter(condor1, 1);
		StartEmitter(condor1, 2);
		//smoker1 = BuildObject("kickup",0,"smoker1_a");
		//smoker2 = BuildObject("kickup",0,"smoker1_b");
		emit_time = GetTime() + 999999.9f;
	}
	///////////////////////////////////////////


// this is sending shabayev on her way to the falling cliff ////////////////////////////////



if ((player_off) && (!shab_down_path3) && (IsAlive(shabayev)) && (!game_over))
{
	// this is redundant to make sure the wingman holds

	if ((start_done) && (!wing_hold) && (GetDistance(shabayev,"wing_first_point") < 20.0f))
	{
		LookAt(wingman,shabayev);
		wing_hold = true;
	}
	///////////////////////////////////////////


	// sends the ai squad underway

	if (!squad1_start)
	{
		if (!plane_time_set)
		{
			planes_wait = GetTime() + 5.0f;
			plane_time_set = true;
		}

		if ((plane_time_set) && (planes_wait < GetTime()))
		{
			if (IsAlive(squad1_a))
			{
				Goto(squad1_a,"ok_path1");
			}


			if (IsAlive(squad1_b))
			{
				Follow(squad1_b,squad1_a);
			}


			if (IsAlive(squad1_c))
			{
				Follow(squad1_c,squad1_b);
			}

			wait1_time = GetTime() + 3.0f;
			squad1_time = GetTime() + 9.0f;
			squad1_start = true;
		}
	}
	///////////////////////////////////////////


	// has the wingman look at the ai sqaud

	if ((squad1_start) && (!wing_look) && (wait1_time < GetTime()))
	{
		LookAt(wingman,squad1_a);
		wing_look = true;
	}
	///////////////////////////////////////////



	// this is shabs first message

	if (!message1)
	{
		SetAvoidType(shabayev,0);
		SetAvoidType(wingman,0);
		StopAudioMessage(speak);
		ClearObjectives();
		AddObjective("isdf0101.otf", GREEN);
		speak = AudioMessage("isdf0101.wav"); // (shab) stick with me - looking for base
		message_time = GetTime() + 20.0f;
		message1 = true;
	}
	///////////////////////////////////////////


	if ((!shab_down_path1) && (squad1_start) && (message_time < GetTime()))
	{
		ClearObjectives();
		AddObjective("isdf0102.otf", WHITE);

		Goto(shabayev,"shab_path1",1);

		if (IsAlive(wingman))
		{
			Follow(wingman,shabayev,1);
		}

		AudioMessage("isdf0102.wav"); // (shab) lets move out!
		look_time = GetTime() + 999999.9f;
		wait1_time = GetTime() + 2.0f;
		shab_down_path1 = true;
	}


	if ((!shab_at_point1) && (shab_down_path1) && (wait1_time < GetTime()))
	{
		wait1_time = GetTime() + 2.0f;


		if (GetDistance(shabayev,"shab_point1") < 30.0f)
		{
			LookAt(shabayev,squad1_a);
			talk = AudioMessage("isdf0162.wav");//(shab) hold up men - looking for a place to puke-up Tom?!
			wait2_time = GetTime() + 3.5f;
			look_time = GetTime() + 25.0f;
			hold_fire_message = false;
			shab_at_point1 = true;
		}
	}


	// this is holding the three amigos for the first dialouge

	if ((!squad1_stopped) && (!squad1_off) && (squad1_start) && (squad1_time < GetTime()))
	{
		squad1_time = GetTime() + 1.0f;

		if ((!squad1_astop) && (GetDistance(squad1_a,"squad1_point1") < 20.0f))
		{
			LookAt(squad1_a,shabayev);
			squad1_astop = true;
		}


		if ((!squad1_bstop) && (GetDistance(squad1_b,"squad1_point1") < 25.0f))
		{
			LookAt(squad1_b,wingman);
			//Stop(squad1_b,wingman);
			squad1_bstop = true;
		}


		if ((!squad1_cstop) && (GetDistance(squad1_c,"squad1_point1") < 30.0f))
		{
			LookAt(squad1_c,player);
			//Stop(squad1_b,wingman);
			squad1_cstop = true;
		}

		if ((squad1_astop) && (squad1_bstop) && (squad1_cstop))
		{
			squad1_stopped = true;
		}
	}
	/////////////////////////////////////////////////


	// this is sending squad1 down its second path

	if (!player_lost)
	{
		if ((!squad1_talk) && (shab_at_point1) && (IsAudioMessageDone(talk)))
		{
			if (!squad1_talk)
			{
				SetAvoidType(squad1_a,0);
				SetAvoidType(squad1_b,0);
				SetAvoidType(squad1_c,0);
				LookAt(wingman,squad1_a);
				SetObjectiveOn(squad1_a);
				TranslateString2(tempstr, sizeof(tempstr), "Mission0102");  // Red 1

				SetObjectiveName(squad1_a,tempstr);
				talk = AudioMessage("isdf0139.wav"); // (squad1) Its just puke Yelena or throw up and I don't have to do either... we'll take low road
				//wait2_time = GetTime() + 12.0f;
				squad1_talk = true;
			}
		}


		if ((squad1_talk) && (!squad1_off) && (IsAudioMessageDone(talk)))
		{
			if (IsAlive(squad1_a))
			{
				//SetTeamNum(squad1_a,0);
				Goto(squad1_a,"squad1_point2",1);

				if (IsAlive(squad1_b))
				{
					//SetTeamNum(squad1_b,0);
					Follow(squad1_b,squad1_a,1);

					if (IsAlive(squad1_c))
					{
						//SetTeamNum(squad1_c,0);
						Follow(squad1_c,squad1_b,1);
					}
				}
			}
		
			SetObjectiveOff(squad1_a);
			//Ally(0,1);
			//Ally(1,0);
			squad1_off = true;
		}
		/////////////////////////////////////////////////


		// this is sending shabayev down the second path

		if ((!roger_message) && (squad1_off))
		{
			LookAt(shabayev,wingman);
			look_time = GetTime() + 3.0f;
			at_player = false;
			AudioMessage("isdf0103.wav"); // (shab) Roger that red1
			wait2_time = GetTime() + 5.0f;
			roger_message = true;

			// this is new
			if (GetDistance(shabayev,player) > 150.0f)
			{
				ClearObjectives();
				AddObjective("isdf0102.otf", RED);
				player_lost = true;
			}
		}
		/////////////////////////////////////////////////


		if ((!shab_down_path2) && (roger_message) && (wait2_time < GetTime()))
		{
			//Goto(shabayev,"shab_path2a");
			Goto(shabayev,"shab_path2");

			if (IsAlive(wingman))
			{
				//Goto(wingman,"shab_path2a");
				Follow(wingman,shabayev);
			}

			ClearObjectives();
			AddObjective("isdf0102.otf", WHITE);
			AudioMessage("isdf0104.wav"); // (shab) All right numbers 1 and 2 lets move out!
			wait2_time = GetTime() + 2.0f;
			cliff_check = GetTime() + 1.0f;
			look_time = GetTime() + 999999.9f;
			shab_down_path2 = true;
		}
	}
	/////////////////////////////////////////////////


	// this removes red1's squad

	if ((!shab_at_cliff) && (cliff_check < GetTime()))
	{
		cliff_check = GetTime() + 1.0f;

		if (GetDistance(shabayev,"cliff_point") < 30.0f)
		{
			if (GetDistance(player,shabayev) < 200.0f)
			{
				if (IsAlive(squad1_a))
				{
					RemoveObject(squad1_a);
				}
				if (IsAlive(squad1_b))
				{
					RemoveObject(squad1_b);
				}
				if (IsAlive(squad1_c))
				{
					RemoveObject(squad1_c);
				}
				if (IsAlive(squad2_a))
				{
					RemoveObject(squad2_a);
				}
				if (IsAlive(squad2_b))
				{
					RemoveObject(squad2_b);
				}
				if (IsAlive(squad2_c))
				{
					RemoveObject(squad2_c);
				}

				first_squad_removed = true;
			}

			cliff_check = GetTime() + 2.0f;
			//wait2_time = GetTime() + 0.5f;
			shab_at_cliff = true;
		}
	}
	/////////////////////////////////////////////////



	// this triggers the cliff falling animation

	if ((!cliff_fall) && (shab_at_cliff) && (cliff_check < GetTime()))
	{
		SetAnimation(crumble_cliff,"crumble",1);
		StartSoundEffect("pecrack.wav",crumble_cliff);
		AudioMessage("isdf0105.wav"); // (shab) whoa - we better be carful out here
		Goto(wingman,"out_of_way");
		cliff_fall = true;
	}
	/////////////////////////////////////////////////



	// this is when shab is in place before the jump path
	
	if ((!shab_at_point2) && (shab_at_cliff)/* && (wait2_time < GetTime())*/)
	{
		//wait2_time = GetTime() + 0.5f;


		if ((GetDistance(shabayev,"shab_point2") < 30.0f) || (GetCurrentCommand(shabayev) == CMD_NONE))
		{
			LookAt(shabayev,player);
			wait2_time = GetTime() + .1f;
			shab_at_point2 = true;


			if (GetDistance(shabayev,player) > 150.0f)
			{
				ClearObjectives();
				AddObjective("isdf0102.otf", RED);
				player_lost = true;
			}
		}
	}
	/////////////////////////////////////////////////


	// this is when the wingman is in place before the jump path

	if ((!shab_down_path3) && (shab_at_point2)/* && (wait2_time < GetTime())*/)
	{
		if (GetDistance(wingman,"out_of_way") < 30.0f)
		{
			if (wait_4_wing)
			{
				if (!player_lost)
				{
					AudioMessage("isdf0160.wav");//(wing) sorry about that (getting lost)
				}

				LookAt(wingman,shabayev);
				LookAt(shabayev,wingman);
				wait2_time = GetTime() + 3.0f;
				shab_down_path3 = true;
			}
			else
			{
				LookAt(wingman,shabayev);
				LookAt(shabayev,wingman);
				look_time = GetTime() + 999999.9f;
				wait2_time = GetTime() + 0.5f;
				shab_down_path3 = true;
			}
		}
		else if ((!wait_4_wing) && (GetDistance(shabayev,wingman) > 150.0f))
		{
			AudioMessage("isdf0159.wav");//(shab) wing2 would you like to kick in the afterburners?
			LookAt(shabayev,wingman);
			wait_4_wing = true;
		}
	}
	/////////////////////////////////////////////////
}



// this is sending shabayev on her way to the base ////////////////////////////////



if ((shab_down_path3) && (!shab_at_point3) && (IsAlive(shabayev)) && (!player_lost))
{
	// this is shab telling the wingman to take off down the pass

	if ((shab_down_path3) && (!wing_orders) && (wait2_time < GetTime()))
	{
		//Goto(shabayev,"shab_path3");
		talk = AudioMessage("isdf0106.wav"); // (shab) all right number 2 check out that other pass
		//wait2_time = GetTime() + 5.0f;
		wing_orders = true;
	}
	/////////////////////////////////////////////////


	// this is the wingman taking off down the pass

	if ((wing_orders) && (!roger1) && (IsAudioMessageDone(talk)))
	{
		if (IsAlive(wingman))
		{
			Goto(wingman,"explore_path1");
		}

		AudioMessage("isdf0112.wav"); // (wingman) copy that
		wait2_time = GetTime() + 1.0f;
		roger1 = true;
	}
	/////////////////////////////////////////////////


	// this is shab taking off down her path

	if ((roger1) && (!go_shab_go) && (wait2_time < GetTime()))
	{
		LookAt(shabayev,player);
		ClearObjectives();
		AddObjective("isdf0102.otf", WHITE);
		talk = AudioMessage("isdf0161.wav");//(shab) number one - your with me
		wait2_time = GetTime() + 2.0f;
		look_time = GetTime() + 999999.9f;
		go_shab_go = true;
	}
	/////////////////////////////////////////////////


	// this is making shab move down the jump path

	if ((!go_shab_go2) && (go_shab_go) && (wait2_time < GetTime()))
	{
		Goto(shabayev,"jump_path2");
		go_shab_go2 = true;
	}
	/////////////////////////////////////////////////


	// this is detecting the scout

	if ((!turret_detected) && (roger1))
	{
		if (IsAlive(turret))
		{
			if (GetDistance(wingman,turret) < 200.0f)
			{
				speak = AudioMessage("isdf0167.wav"); // (simms) I'm detecting something strange headed north
				Retreat(turret,"turret_path");
				Follow(wingman,turret);
				turret_retreat = true;
				turret_detected = true;
			}
		}
		else if ((go_shab_go) && (IsAudioMessageDone(talk)))
		{
			turret_detected = true;
		}
	}
	/////////////////////////////////////////////////

	
	// this checks to see when the turret is dead and deployed 

	if (turret_retreat)
	{
		// this is shab commenting on the turret

		if ((!shab_turret_comment) && (IsAudioMessageDone(speak)))
		{
			speak = AudioMessage("isdf0168.wav"); // (shab) stay on it we'll try and cut it off
			shab_turret_comment = true;
		}
		/////////////////////////////////////////////////
		

		// this is checking to see when she reaches the bluff before the base

		if ((!shab_cutoff_turret) && (go_shab_go2) && (wait2_time < GetTime()))
		{
			wait2_time = GetTime() + 1.0f;


			if (GetDistance(shabayev,"shab_point3") < 30.0f)
			{
				if (IsAlive(turret))
				{
					LookAt(shabayev,turret);
					shab_cutoff_turret = true;
				}
				else
				{
					LookAt(shabayev,player);
					shab_cutoff_turret = true;
				}
			}
		}
		/////////////////////////////////////////////////


		// this is when the turret dies

		if (!turret_dead)
		{
			if (!IsAlive(turret))
			{
				Follow(wingman,shabayev);
				turret_dead = true;
			}


			if (!turret_dead)
			{
				// this tells the turret to stop and attack
				if ((!turret_deploy) && (GetDistance(turret,"shab_point3") < 35.0f))
				{
					//Stop(turret,0);
					Attack(turret,shabayev);
					//Deploy(turret);
					Follow(wingman,turret);
					in_combat = true;
					turret_deploy = true;
				}


				if ((!wing_lookat_turret) && (turret_deploy) && (GetDistance(wingman,turret) < 50.0f))
				{
					LookAt(wingman,turret);
					wing_lookat_turret = true;
				}


				// this is simms commenting on the turret
				if ((!what_doing) && (turret_deploy) && (IsDeployed(turret)))
				{
					//Attack(turret,shabayev);
					AudioMessage("isdf0174.wav"); // (Simms) what's it doing
					what_doing = true;

				}


				if ((!turret_hostle) && (turret_deploy))
				{
					if (GetCurAmmo(turret) < 1490)
					{
						SetPerceivedTeam(turret,2);
						Attack(shabayev,turret);
						Attack(wingman,turret);
						AudioMessage("isdf0169.wav"); // (shab) Open fire!
						turret_hostle = true;
					}
				}
			}
		}
		else if (turret_dead)
		{
			if (shab_cutoff_turret)
			{
				if (GetDistance(shabayev,player) > 150.0f)
				{
					ClearObjectives();
					AddObjective("isdf0102.otf", RED);
					player_lost = true;
				}

				wait2_time = GetTime() + 2.0f;
				shab_at_point3 = true;
			}
		}
	}
	/////////////////////////////////////////////////
	else if (!turret_retreat)
	{
		// this is checking to see when she reaches the bluff before the base

		if ((!shab_at_point3) && (go_shab_go2) && (wait2_time < GetTime()))
		{
			wait2_time = GetTime() + 1.0f;


			if (GetDistance(shabayev,"shab_point3") < 30.0f)
			{
				LookAt(shabayev,player);
				wait2_time = GetTime() + 5.0f;
				shab_at_point3 = true;


				if (GetDistance(shabayev,player) > 150.0f)
				{
					ClearObjectives();
					AddObjective("isdf0102.otf", RED);
					player_lost = true;
				}
			}
			else if ((!wing_first) && (GetDistance(wingman,"shab_point3") < 30.0f))
			{
				LookAt(wingman,shabayev);
				wing_first = true;
			}
		}
		/////////////////////////////////////////////////
	}
/*
	// this is checking to see when she reaches the bluff before the base

	if ((!shab_at_point3) && (wing_orders) && (wait2_time < GetTime()))
	{
		wait2_time = GetTime() + 1.0f;


		if (GetDistance(shabayev,"shab_point3") < 30.0f)
		{
			LookAt(shabayev,player);
			wait2_time = GetTime() + 5.0f;
			shab_at_point3 = true;


			if (GetDistance(shabayev,player) > 150.0f)
			{
				ClearObjectives();
				AddObjective("isdf0102.otf", RED);
				player_lost = true;
			}
		}
		else if ((!wing_first) && (GetDistance(wingman,"shab_point3") < 30.0f))
		{
			LookAt(wingman,shabayev);
			wing_first = true;
		}
	}
	/////////////////////////////////////////////////
*/
}


// this is sending shabayev on her way to the base ////////////////////////////////



if ((shab_at_point3) && (!shab_at_base) && (IsAlive(shabayev)) && (!player_lost))
{
	// this is sending shabayev down the "tight" path

	if (!turret_retreat)
	{
		if (!player_lost)
		{
			// this is shab trying to contact the base

			if ((shab_at_point3) && (!base_detected) && (wait2_time < GetTime()))
			{
				LookAt(shabayev,comm_building);
				talk = AudioMessage("isdf0107.wav"); //(shab) I'm detecting the base just over those hills
				wingy = GetTime() + 3.5f;
				base_detected = true;
			}
			/////////////////////////////////////////////////

			// this is making the wingman look at the base

			if ((base_detected) && (wingy < GetTime()))
			{
				LookAt(wingman,comm_building);
				wingy = GetTime() + 999999.9f;
			}
			/////////////////////////////////////////////////

			// this is shab giving the go ahead command

			if ((!alert_skyeye) && (base_detected) && (IsAudioMessageDone(talk)))
			{
				LookAt(shabayev,player);
				LookAt(wingman,shabayev);
				talk = AudioMessage("isdf0170.wav"); //(shab) comm is down - follow me men
				alert_skyeye = true;
			}
			/////////////////////////////////////////////////


			// this is shab moving on

			if ((!shab_down_tight) && (alert_skyeye) && (IsAudioMessageDone(talk)))
			{
				if (GetDistance(shabayev,wingman) < 100.0f)
				{
					ClearObjectives();
					AddObjective("isdf0102.otf", WHITE);
					Goto(shabayev,"tight_path3");

					if (IsAlive(wingman))
					{
						Follow(wingman,shabayev);
					}

					wait2_time = GetTime() + 10.0f;
					shab_down_tight = true;
				}
			}
			/////////////////////////////////////////////////
		}
	}
	else if (turret_retreat)
	{
		if (!player_lost)
		{
			// this is Simms commenting on the turret

			if ((!simms_turret_comment) && (shab_at_point3) && (wait2_time < GetTime()))
			{
				Follow(wingman,shabayev);
				talk = AudioMessage("isdf0171.wav"); //(simms) what was that thing
				in_combat = false;
				simms_turret_comment = true;
			}
			/////////////////////////////////////////////////


			// this is shab commenting on the turret

			if ((!shab_weapon_comment) && (simms_turret_comment) && (IsAudioMessageDone(talk)))
			{
				LookAt(shabayev,wingman);
				LookAt(wingman,shabayev);
				talk = AudioMessage("isdf0172.wav"); //(shab) we got missles
				shab_weapon_comment = true;
			}
			/////////////////////////////////////////////////


			// this is shab trying to contact the base

			if ((!base_detected) && (shab_weapon_comment) && (IsAudioMessageDone(talk)))
			{
				LookAt(shabayev,comm_building);
				talk = AudioMessage("isdf0107.wav"); //(shab) I'm detecting the base just over those hills
				wingy = GetTime() + 5.0f;
				base_detected = true;
			}
			/////////////////////////////////////////////////


			// this is making the wingman look at the base

			if ((base_detected) && (wingy < GetTime()))
			{
				LookAt(wingman,comm_building);
				wingy = GetTime() + 999999.9f;
			}
			/////////////////////////////////////////////////


			// this is shab giving the go ahead command

			if ((!alert_skyeye) && (base_detected) && (IsAudioMessageDone(talk)))
			{
				LookAt(shabayev,player);
				LookAt(wingman,shabayev);
				talk = AudioMessage("isdf0170.wav"); //(shab) comm is down - follow me men
				alert_skyeye = true;
			}
			/////////////////////////////////////////////////


			// this is shab moving on

			if ((!shab_down_tight) && (alert_skyeye) && (IsAudioMessageDone(talk)))
			{
				ClearObjectives();
				AddObjective("isdf0102.otf", WHITE);
				Goto(shabayev,"tight_path2");

				if (IsAlive(wingman))
				{
					Follow(wingman,shabayev);
				}

				wait2_time = GetTime() + 10.0f;
				shab_down_tight = true;
			}
			/////////////////////////////////////////////////
		}
	}
	/////////////////////////////////////////////////


	if ((shab_down_tight) && (!throttle_down) && (wait2_time < GetTime()))
	{
		wait2_time = GetTime() + 1.0f;


		if ((GetDistance(shabayev,"atbase_point") < 200.0f) || (GetDistance(player,"atbase_point") < 200.0f))
		{
			AudioMessage("isdf0108.wav"); // (shab) base is coming into range - throttle down
			throttle_down = true;
		}
	}


	if ((!shab_at_base) && (shab_down_tight) && (wait2_time < GetTime()))
	{
		wait2_time = GetTime() + 2.0f;


		if (GetDistance(shabayev,"atbase_point") < 30.0f)
		{
			LookAt(shabayev,player);
			wait2_time = GetTime() + 2.0f;
			shab_at_base = true;


			if (GetDistance(shabayev,player) > 150.0f)
			{
				ClearObjectives();
				AddObjective("isdf0102.otf", RED);
				player_lost = true;
			}
		}
	}
}



// this is the code that takes over when the player & shabayev reach the base 



if ((shab_at_base) && (!left_base) && (IsAlive(shabayev)) && (!player_lost))
{
	// this is Simms commenting on the tank

	if ((!simms_tank_comment) && (wait2_time < GetTime()))
	{
		if (IsAround(dead_tank))
		{
			LookAt(shabayev,dead_tank);

			if (GetDistance(wingman,dead_tank) < 50.0f)
			{
				LookAt(wingman,dead_tank);
			}
		}

		if (!first_squad_removed)
		{
			if (IsAlive(squad1_a))
			{
				RemoveObject(squad1_a);
			}
			if (IsAlive(squad1_b))
			{
				RemoveObject(squad1_b);
			}
			if (IsAlive(squad1_c))
			{
				RemoveObject(squad1_c);
			}
			if (IsAlive(squad2_a))
			{
				RemoveObject(squad2_a);
			}
			if (IsAlive(squad2_b))
			{
				RemoveObject(squad2_b);
			}
			if (IsAlive(squad2_c))
			{
				RemoveObject(squad2_c);
			}

			first_squad_removed = true;
		}
		
		wait2_time = GetTime() + 5.0f;
		talk = AudioMessage("isdf0173.wav"); // (simms) that looks like one of ours
		simms_tank_comment = true;
	}
	/////////////////////////////////////////////////


	// this sends shab into the base

	if ((!shab_to_center) && (IsAudioMessageDone(talk)) && (wait2_time < GetTime()))
	{
		ClearObjectives();
		AddObjective("isdf0102.otf", WHITE);
		AddObjective("isdf0103.otf", WHITE);
		Goto(shabayev,"base_center");
		AudioMessage("isdf0109.wav"); // (shab) lets head for the center


		if (IsAlive(wingman))
		{
			Follow(wingman, shabayev);
		}

		shab_to_center = true;
	}
	/////////////////////////////////////////////////


	// this is when shab reaches the center of the base

	if ((!shab_centered) && (shab_to_center) && (GetDistance(shabayev,"base_center") < 30.0f))
	{
		LookAt(shabayev,player); // this should be changed to the gun tower
		//look_time = GetTime() + 1.0f;
		//at_player = true;
		//wait_time = GetTime() + 10.0f;
		speak = AudioMessage("isdf0110.wav"); // (shab) For an "outpost" this place sure was heavily armed
		base_check_time = GetTime() + 3.0f;
		shab_centered = true;
	}
	////////////////////////////////////////////////


	// this is shab telling wingman to sweep

	if ((shab_centered) && (!search_base) && (IsAudioMessageDone(speak)))//(wait_time < GetTime()))
	{
		LookAt(shabayev,wingman);
		LookAt(wingman,shabayev);
		speak = AudioMessage("isdf0111.wav"); // (shab) wingman sweep perimeter.
		//wait_time = GetTime() + 5.0f;
		search_base = true;
	}
	////////////////////////////////////////////////


	// this is simms acknowloging command

	if ((search_base) && (!wingman_away) && (IsAudioMessageDone(speak)))//(wait_time < GetTime()))
	{
		AudioMessage("isdf0112.wav"); // (wingman) roger - on my way
		Goto(wingman,"combat1a");
		wait_time = GetTime() + 3.0f;
		wingman_check = GetTime() + 1.0f;
		wingman_away = true;
	}
	////////////////////////////////////////////////


		// this is checking to see when the wingman reaches the spot

		if ((wingman_away) && (!wingman_there) && (wingman_check < GetTime()))
		{
			wingman_check = GetTime() + 1.0f;

			if (GetDistance(wingman,"combat1a") < 50.0f)
			{
				LookAt(wingman,player);
				wingman_there = true;
			}
		}
		////////////////////////////////////////////////


	// this is shab giving the player to search order

	if ((wingman_away) && (!johns_orders) && (wait_time < GetTime()))
	{
		LookAt(shabayev,player);
		look_time = GetTime() + 999999.9f;
		talk = AudioMessage("isdf0113.wav"); // (shab) John, use "I" key to search for comm bunker - I'm going in tunnels
		comm_check_time = GetTime() + 60.0f;
		johns_orders = true;
	}
	////////////////////////////////////////////////



	// shab leaves for the tunnels

	if ((johns_orders) && (!shab_to_tunnel) && (IsAudioMessageDone(talk))/*(wait_time < GetTime()*/)
	{
		ClearObjectives();
		AddObjective("isdf0103.otf", GREEN);
		AddObjective("isdf0104.otf", WHITE);
		Patrol(shabayev,"around_path2");
		//Patrol(shabayev,"circlebase_path2");
		//Goto(shabayev,"tunnel_path");
		//tunnel_check = GetTime() + 1.0f;
		shab_to_tunnel = true;
	}

/*
	if ((!shab_through) && (shab_to_tunnel) && (tunnel_check < GetTime()))
	{
		tunnel_check = GetTime() + 1.0f;


		if (GetDistance(shabayev,"through_tunnel") < 30.0f)
		{
			shab_through = true;
		}
	}


	if ((shab_through) && (!to_comm))
	{
		if (comm_identified)
		{
			Goto(shabayev,"comm_point",1);
			shab_comm_check = GetTime() + 1.0f;
			to_comm = true;
		}
		else if (!shab_wait)
		{
			LookAt(shabayev,player);
			shab_wait = true;
		}
	}
*/

	if ((shab_to_tunnel) && (!to_comm))
	{
		if (comm_identified)
		{
			Goto(shabayev,"comm_point");
			shab_comm_check = GetTime() + 0.5f;
			to_comm = true;
		}
	}
	////////////////////////////////////////////////


	// this is where I check to see if the player identifies the comm building

	if ((shab_to_tunnel) && (IsInfo("pbcomm") == true) && (!comm_identified))
	{
		ClearObjectives();
		AddObjective("isdf0104.otf", GREEN);
		AudioMessage("isdf0114.wav"); // (shab) nice work John - stay there, I'm on my way
		//Goto(shabayev,"comm_point");
		//shab_comm_check = GetTime() + 1.0f;
		comm_identified = true;
	}
	/////////////////////////////////////////////////


	// this is code that plays if the player spends too much time looking for the comm building

	if ((!comm_identified) && (johns_orders) && (!comm_help) && (comm_check_time < GetTime()))
	{
		ClearObjectives();
		AddObjective("isdf0104.otf", WHITE);
		AudioMessage("isdf0113v2.wav"); // (shab) // Hurry up and find comm - remember to use "I" key
		comm_check_time = GetTime() + 40.0f;
		comm_help = true;
	}
	/////////////////////////////////////////////////


	if ((!comm_identified) && (!find_herself) && (comm_help) && (comm_check_time < GetTime()))
	{
		Goto(shabayev,"comm_point");
		comm_check_time = GetTime() + 999999.9f;
		shab_comm_check = GetTime() + 1.0f;
		find_herself = true;
	}


	// this tells when shabayev reaches the comm buidling after it has been identified or she finds it herself
	
	if (((comm_identified) || (find_herself)) && (!shab_at_comm))
	{
		if ((IsAlive(comm_building)) && (shab_comm_check < GetTime()))
		{
			shab_comm_check = GetTime() + 1.0f;


			if (GetDistance(shabayev,"comm_point") < 50.0f)
			{
				if (!in_comm)
				{
					AudioMessage("isdf0116.wav"); // (shab) I'm detecting life readings too - go in and check it out
					ClearObjectives();
					AddObjective("isdf0105.otf", WHITE);
				}

				//SetObjectiveOn(manson);
				//SetObjectiveName(manson, "Life Reading");
				LookAt(shabayev,player);
				shab_comm_check = GetTime() + 180.0f;
				out_check = GetTime() + 180.0f;
				shab_at_comm = true;
			}
		}
	}
	/////////////////////////////////////////////////


	// I'm going to delete this when I can determine if the player is inside the building
	// for now I will just check to see if he gets our
	//if ((shab_at_comm) && (out_of_ship) && (!inside))
	//{
	//	inside = true;
	//}
	/////////////////////////////////////////////////


	// this is where I need to determine if the player is in the building

	if (InBuilding(player))
	{
		inside = true;

		if ((!in_comm) && (GetDistance(player,comm_building) < 20.0f))
		{
			in_comm = true;
		}
	}
	else
	{
		inside = false;
		in_comm = false;
	}


	// this is where I trigger the cineractive

	if (johns_orders)
	{
		if ((!start_cineractive) && (in_comm) && (GetDistance(player,manson) < 4))
		{
			//SetObjectiveOff(manson);
			CameraReady();
			line = AudioMessage("cut0201.wav"); // (cook) Someone is in here!
			//camera_time = GetTime() + 5.0f;
			start_cineractive = true;
		}
	}


	// this is the movie code

	if ((!camera1_over) && (start_cineractive))
	{
		if (!first_frame) 
		{
			CameraReady();
			first_frame = true;
		}
		
		PlayMovie("manson1");
	}


	if ((!camera2_over) && (first_frame) && (line4))
	{
		CameraObject(shabayev,0,1,5,shabayev); // 3.7
		//a = a + 0.1;
		camera1_over = true;
	}


	if ((movie1) && (line5))
	{
		if (!reframe1)
		{
			//StopMovie();
			CameraReady();
			reframe1 = true;
		}

		movie1 = PlayMovie("base_look");
		movie2 = true;
	}

	
	if ((!movie1) && (movie2))
	{
		movie2 = PlayMovie("manson2");
		camera3_over = true;
	}

	////////////////////////////////////////////


	if ((!line2) && (start_cineractive) && (IsAudioMessageDone(line)))
	{
		line = AudioMessage("cut0202.wav"); // (shab) A man? Is he alive?
		line2 = true;
	}
	if ((!line3) && (line2) && (IsAudioMessageDone(line)))
	{
		line = AudioMessage("cut0203.wav"); // (manson) If you call this living - who is this?
		SetAnimation(manson,"line1",1);
		line3 = true;
	}
	if ((!line4) && (line3) && (IsAudioMessageDone(line)))
	{
		line = AudioMessage("cut0204.wav"); // (shab) This is shab?
		line4 = true;
	}
	if ((!line5) && (line4) && (IsAudioMessageDone(line)))
	{
		line = AudioMessage("cut0205.wav"); // (manson) is your radio working?
		//SetAnimation(manson,"line2",1);
		StopMovie();
		CameraFinish();
		camera2_over = true;
		line5 = true;
	}
	if ((!line6) && (line5) && (IsAudioMessageDone(line)))
	{
		//Matrix pos;
		//GetPosition(manson,pos);
		//RemoveObject(manson);
		//manson = BuildObject("manson2",0,pos);

		line = AudioMessage("cut0206.wav"); // (shab) no - interfierence?
		line6 = true;
	}
	if ((!line7) && (line6) && (IsAudioMessageDone(line)))
	{
		SetAnimation(manson,"line2",1);
		line = AudioMessage("cut0207.wav"); // (manson) Then they already know you are hear!
		line7 = true;
	}


	// this is where I trigger the cineractive

	if ((!cineractive_over) && (line7) && (IsAudioMessageDone(line)))
	{
		CameraFinish();
		cineractive_over = true;

		if (!shab_at_comm)
		{
			Goto(shabayev,player_ship);
			shab_at_comm = true;
		}
	}
	/////////////////////////////////////////////////


	// this is where the code will go to determine if player is out of his ship

	if ((shab_at_comm) && (!out_of_ship) && (!wingman_message1) && (out_check < GetTime()))
	{
		ClearObjectives();
		AddObjective("isdf0105.otf", WHITE);
		out_check = GetTime() + 180.0f;
		AudioMessage("isdf0140.wav"); // (shab) Get out of your ship john!
	}
	/////////////////////////////////////////////////




	// this is the wingman sending the first encounter message

	if (IsAlive(wingman))
	{
		if ((!wingman_message1) && (shab_at_comm) && (cineractive_over))
		{
			AudioMessage("cut0208.wav"); //(wingman) I'm picking up some enemy ships sir
			SetObjectiveOn(wingman);
			dialog1_time = GetTime() + 5.0f;
			shab_comm_check = GetTime() + 999999.9f;
			wingman_message1 = true;
		}
	}
	/////////////////////////////////////////////////


	if ((wingman_message1) && (!shab_response) && (dialog1_time < GetTime()))
	{
		ClearObjectives();
		AddObjective("isdf0106.otf", WHITE);
		AudioMessage("cut0209.wav"); //(shab) we're on our way! John leave Manson and get to your ship
		john_ship_check = GetTime() + 60.0f; // this will be activated when I can tell when the player is in and out of ship
		shab_response = true;
	}


	// this tells john to hurry if he's taking his time

	if ((!shab_warning1) && (john_ship_check < GetTime()) && (shab_response) && (out_of_ship))
	{
		ClearObjectives();
		AddObjective("isdf0106.otf", WHITE);
		AudioMessage("isdf0119.wav"); //(shab) you wanna get the lead out john?!
		john_ship_check = GetTime() + 60.0f;
		shab_warning1 = true;
	}
	/////////////////////////////////////////////////


	// this is where she leavses the base with John

	if ((shab_response) && (!out_of_ship) && (!left_base))
	{
		ClearObjectives();
		AddObjective("isdf0106.otf", GREEN);
		AddObjective("isdf0102.otf", WHITE);
		Goto(shabayev,"shab_attack_path");
		AudioMessage("isdf0120.wav");// (shab) lets go - follow me John
		on_route_check = GetTime() + 2.0f;
		left_base = true;
	}
	/////////////////////////////////////////////////


	// this is special code that makes sure that the player stays inside base area

	if ((shab_to_center) && (base_check_time < GetTime()))
	{
		base_check_time = GetTime() + 3.0f;


		if (GetDistance(player,"base_center") > 250.0f)
		{
			player_lost = true;
		}
	}
	/////////////////////////////////////////////////
}



// this is when shabayev and the player leave to go and help the wingman



if ((left_base) && (!base_return) && (IsAlive(shabayev)) && (!player_lost))
{
	// this checks to see that shab and the player are on there way

	if ((!on_route) && (on_route_check < GetTime()))
	{
		on_route_check = GetTime() + 0.5f;


		// this is the wingman saying that he is engaging the targets

		if (GetDistance(shabayev,"combat1a") < 500.0f) 
		{
			AudioMessage("isdf0121.wav"); // (wingman) engaging targets


			if (IsAlive(wingman))
			{
				RemoveObject(wingman);
			}

			wingman = BuildObject("p1scout", 1,"combat1a");
			SetAvoidType(wingman,0);
			scion1 = BuildObject("fvpsnt", 2,"combat1c");
			scion2 = BuildObject("fvpsnt", 2,"combat1b");
			SetPerceivedTeam(wingman, 2);
			SetObjectiveOn(wingman);
			LookAt(wingman,scion1);
			Patrol(scion1,"circle_path", 1);
			Patrol(scion2,"circle_path", 1);
			on_route_check = GetTime() + 1.5f;
			on_route = true;
		}
		/////////////////////////////////////////////////
	}
	/////////////////////////////////////////////////

	
	// this holds the wingman until shab and the player arrive

	if ((on_route) && (!in_range) && (IsAlive(wingman)))
	{
		Stop(wingman);
	}
	/////////////////////////////////////////////////


	// this is shab saying she's detecting the enemy on radar

	if ((on_route) && (!in_range) && (on_route_check < GetTime()))
	{
		on_route_check = GetTime() + 1.0f;


		if ((IsAlive(scion1)) && (GetDistance(shabayev,scion1) < 400.0f))
		{
			if (IsAlive(wingman))
			{
				SetPerceivedTeam(wingman,1);
			}

			AudioMessage("isdf0122.wav"); // (shab) I've got them on radar -I'll paint a target for you when we're in range
			on_route_check = GetTime() + 1.0f;
			in_range = true;
		}
		else if ((IsAlive(scion2)) && (GetDistance(shabayev,scion2) < 400.0f))
		{
			if (IsAlive(wingman))
			{
				SetPerceivedTeam(wingman,1);
			}

			AudioMessage("isdf0122.wav"); // (shab) I've got them on radar - I'll paint a target for you when we're in range
			on_route_check = GetTime() + 1.0f;
			in_range = true;
		}
	}
	/////////////////////////////////////////////////


	// this is shab "painting" John a target

	if ((in_range) && (!targeted) && (on_route_check < GetTime()))
	{
		on_route_check = GetTime() + 0.5f;


		if ((IsAlive(scion1)) && ((GetDistance(shabayev,scion1) < 150.0f) || (GetDistance(player,scion1) < 150.0f)))
		{
			ClearObjectives();
			AddObjective("isdf0107.otf", WHITE);
			AudioMessage("isdf0123.wav"); // (shab) Get this target John
			SetObjectiveOn(scion1);
			Attack(scion1,player);


			if (IsAlive(scion2))
			{
				Attack(shabayev,scion2);
			}
			else
			{
				Attack(shabayev,scion1);
			}


			if (IsAlive(wingman))
			{
				Attack(wingman,scion1);
				SetObjectiveOff(wingman);
				//SetCurHealth(wingman,200);
			}

			coward_check = GetTime() + 10.0f;
			in_combat = true;
			scion1_target = true;
			targeted = true;
		}
		else if ((IsAlive(scion2)) && ((GetDistance(shabayev,scion2) < 150.0f) || (GetDistance(player,scion2) < 150.0f)))
		{
			ClearObjectives();
			AddObjective("isdf0107.otf", WHITE);
			AudioMessage("isdf0123.wav"); // (shab) Get this target John
			SetObjectiveOn(scion2);
			Attack(scion2,player);


			if (IsAlive(scion1))
			{
				Attack(shabayev,scion1);
			}
			else
			{
				Attack(shabayev,scion2);
			}


			if (IsAlive(wingman))
			{
				Attack(wingman,scion2);
				SetObjectiveOff(wingman);

			}

			coward_check = GetTime() + 10.0f;
			in_combat = true;
			scion2_target = true;
			targeted = true;
		}
	}
	/////////////////////////////////////////////////


/*	// this is checking to see if the player is attacking the enemy painted
	if ((targeted) && (!coward_message) && (coward_check < GetTime()))
	{
		coward_check = GetTime() + 10.0f;


		if ((scion1_target) && (IsAlive(scion1)))
		{
			if (GetDistance(player,scion1) > 300.0f)
			{
				AudioMessage("isdf0124.wav"); // (shab) what's up John?!
				coward_message = true;
			}
		}


		if ((scion2_target) && (IsAlive(scion2)))
		{
			if (GetDistance(player,scion2) > 300.0f)
			{
				AudioMessage("isdf0124.wav"); // (shab) what's up John?!
				coward_message = true;
			}
		}
	}

*/
	// this is when the player kills his scion

	if ((!battle1_over) && (scion1_target) && (!IsAround(scion1)))
	{
		if (IsAlive(scion2))
		{
			if (!giveahand)
			{
				ClearObjectives();
				AddObjective("isdf0107.otf", WHITE);
				AudioMessage("isdf0141.wav");//(shab) good work John - give us a hand with this one!
				SetObjectiveOn(scion2);
				giveahand = true;
			}


			if ((!cheat_death) && (GetCurAmmo(scion2) < 10))
			{
				SetCurHealth(scion2,5);
				cheat_death = true;
			}
		}
	}
	/////////////////////////////////////////////////


	if ((!battle1_over) && (scion2_target) && (!IsAround(scion2)))
	{
		if (IsAlive(scion1))
		{
			if (!giveahand)
			{
				ClearObjectives();
				AddObjective("isdf0107.otf", WHITE);
				AudioMessage("isdf0141.wav");//(shab) good work John - give us a hand with this one!
				SetObjectiveOn(scion1);
				giveahand = true;
			}


			if ((!cheat_death) && (GetCurAmmo(scion1) < 10))
			{
				SetCurHealth(scion1,5);
				cheat_death = true;
			}
		}
	}
	/////////////////////////////////////////


	// this is if shab destoys her scion first

	if (!reroute1)
	{
		if ((scion1_target) && (!IsAlive(scion2)) && (IsAlive(scion1)))
		{
			if (IsAlive(shabayev))
			{
				Attack(shabayev,scion2);
			}

			if (IsAlive(wingman))
			{
				Attack(wingman,scion2);
			}

			reroute1 = true;
		}

		if ((scion2_target) && (!IsAlive(scion1)) && (IsAlive(scion2)))
		{
			if (IsAlive(shabayev))
			{
				Attack(shabayev,scion2);
			}

			if (IsAlive(wingman))
			{
				Attack(wingman,scion2);
			}

			reroute1 = true;
		}
	}
	/////////////////////////////////////////


	// this is checking to see when the first two scions are dead

	if ((!first_scion_dead) && (on_route))
	{

		if (GetCurAmmo(player_ship) < 10)
		{
			if (IsAlive(scion1))
			{
				Damage(scion1,2000);
			}
			if (IsAlive(scion2))
			{
				Damage(scion2,2000);
			}

			tit_time = GetTime() + 3.0f;
			SetCurHealth(wingman,200);
			first_scion_dead = true;
		}
		if ((!IsAlive(scion1)) && (!IsAlive(scion2)))
		{
			tit_time = GetTime() + 3.0f;
			SetCurHealth(wingman,200);
			first_scion_dead = true;
		}
	}
	/////////////////////////////////////////


	// this is when the two scion ships are destroyed

	if ((!simms_panic) && (on_route) && (first_scion_dead) && (tit_time < GetTime()))
	{
		ClearObjectives();
		AddObjective("isdf0107.otf", GREEN);
		talk = AudioMessage("isdf0125.wav"); // (wingman) what the hell were those things?!
		LookAt(shabayev,player);

		if (IsAlive(wingman))
		{
			Follow(wingman,shabayev);
		}

		reroute1 = true;
		in_combat = false;
		simms_panic = true;
	}
	

	// this is if the player is far away from shab
	
	if ((!battle1_over) && (simms_panic) && (IsAudioMessageDone(talk)))
	{
		if (GetDistance(player,shabayev) > 100.0f)
		{
			ClearObjectives();
			AddObjective("isdf0107.otf", GREEN);
			AddObjective("isdf0108.otf", WHITE);
			AudioMessage("isdf0125a.wav"); // (shab) Im not sure - john rondezvous with me!
			john_check = GetTime() + 60.0f;
			dialog2_time = GetTime() + 1.0f;
			player_awl = true;
		}
		
		battle1_over = true;
	}
	/////////////////////////////////////////


	// this declares the player lost if he does not return

	if (player_awl)
	{
		if (dialog2_time < GetTime())
		{
			dialog2_time = GetTime() + 1.0f;

			if (GetDistance(player,shabayev) < 100.0f)
			{
				player_awl = false;
			}
		}

		if ((!wingman_report) && (battle1_over) && (!bubba) && (john_check < GetTime()))
		{
			ClearObjectives();
			AddObjective("isdf0108.otf", RED);
			player_lost = true;
			bubba = true;
		}
	}
	/////////////////////////////////////////


	// this is shab giving the order to return to base

	if ((!player_lost) && (!player_awl))
	{
		if ((battle1_over) && (!wingman_report) && (IsAudioMessageDone(talk)))
		{
			if (IsAlive(wingman))
			{
				LookAt(wingman,shabayev);
				LookAt(shabayev,player);
				talk = AudioMessage("isdf0142.wav"); // (shab) looks like we got company lets get back to base!


				//if (GetCurAmmo(player_ship) > 375)
				//{
				//	scion1 = BuildObject("fvpsnt", 2,"atbase_point");
				//	done = true;
				//}

				if (GetCurAmmo(player_ship) > 100)
				{
					scion1 = BuildObject("fvpscou", 2,"bad_spawn1");
					scion2 = BuildObject("fvpscou", 2,"bad_spawn2");
					whatever = GetTime() + 1.0f;
					done = true;
				}

				look_time = GetTime() + 1.0f;
				john_check = 999999.9f;
				wingman_report = true;
			}
			else
			{
				LookAt(shabayev,player);
				talk = AudioMessage("isdf0142.wav"); // (shab) we got company lets get back to base!


				//if (GetCurAmmo(player_ship) > 375)
				//{
				//	scion1 = BuildObject("fvpsnt", 2,"atbase_point");
				//	done = true;
				//}

				if (GetCurAmmo(player_ship) > 100)
				{
					scion1 = BuildObject("fvpscou", 2,"bad_spawn1");
					scion2 = BuildObject("fvpscou", 2,"bad_spawn2");
					SetSkill(scion1,3);
					SetSkill(scion2,3);
					whatever = GetTime() + 1.0f;
					done = true;
				}

				look_time = GetTime() + 1.0f;
				john_check = 999999.9f;
				wingman_report = true;
			}
		}
	}
	/////////////////////////////////////////


	// this is shab heading back to base

	if ((!base_return) && (wingman_report) && (IsAudioMessageDone(talk)))
	{
		ClearObjectives();
		AddObjective("isdf0108.otf", GREEN);
		AddObjective("isdf0102.otf", WHITE);
		//Goto(shabayev,"base_center");
		Goto(shabayev,"return_path2");
		//Goto(shabayev,"path_3");
		Follow(wingman,shabayev);
		return_time = GetTime() + 5.0f;
		next_wave_time = GetTime() + 2.0f;
		look_time = GetTime() + 999999.9f;
		base_return = true;
	}
	/////////////////////////////////////////


	// this holds the new scions until the player is there

	if ((done) && (!player_there))
	{
		if (IsAlive(scion1))
		{
			Stop(scion1);
		}


		if (IsAlive(scion2))
		{
			Stop(scion2);
		}
	}
	/////////////////////////////////////////
}



// this is when shabayev and the player leave to go and help the wingman



if ((base_return) && (!john_away) && (IsAlive(shabayev)) && (!player_lost))
{
	if (done)
	{
		// checking to see if the second wave is destroyed

		if ((!second_dead) && (!IsAlive(scion1)) && (!IsAlive(scion2)))
		{
			lula_time = GetTime() + 4.0f;
			second_dead = true;
		}
		/////////////////////////////////////////////////


		// this is shab warning of the appoaching scion

		if ((!next_detected) && (next_wave_time < GetTime()))
		{
			next_wave_time = GetTime() + 0.5f;

			// this is warning the player of the two new scions
			
			if (!second_dead)
			{
				if (GetDistance(shabayev,"bad_detected") < 40.0f)
				{
					if (!player_there)
					{
						ClearObjectives();
						AddObjective("isdf0109.otf", WHITE);
						SetObjectiveOn(scion1);
						SetObjectiveOn(scion2);
						TranslateString2(tempstr, sizeof(tempstr), "Mission0101");  // hostile

						SetObjectiveName(scion1,tempstr);
						SetObjectiveName(scion2,tempstr);
					}
					
					Goto(scion1,magic_crate);
					Goto(scion2,magic_crate);
					AudioMessage("isdf0126.wav"); // (shab) I detect more bogies - John move to intercept
					next_detected = true;
				}
			}
			/////////////////////////////////////////////////

/*
			if ((IsAlive(scion1)) && (GetDistance(scion1,player) < 375.0f))
			{
				ClearObjectives();
				AddObjective("isdf0109.otf", WHITE);
				AudioMessage("isdf0126.wav"); // (shab) I detect more bogies at the base - John move to intercept
				next_detected = true;
			}
			else if ((IsAlive(scion1)) && (GetDistance(scion1,shabayev) < 375.0f))
			{
				ClearObjectives();
				AddObjective("isdf0109.otf", WHITE);
				AudioMessage("isdf0126.wav"); // (shab) I detect more bogies at the base - John move to intercept
				next_detected = true;
			}
*/
		}
		/////////////////////////////////////////////////

		
		// this is ording the scion to attack the player

		if ((!player_there) && (whatever < GetTime()))
		{
			whatever = GetTime() + 1.0f;


			if ((GetDistance(player,scion1) < 200.0f) || (GetDistance(player,scion2) < 200.0f))
			{
				if (!next_detected)
				{
					ClearObjectives();
					AddObjective("isdf0109.otf", WHITE);
				}

				//Defend(scion1,magic_crate);
				//Defend(scion2,magic_crate);
				Attack(scion1,player);
				Attack(scion2,player);
				player_there = true;
			}
		}
		/////////////////////////////////////////////////
	}

	
	// checking to see if shabayev returns to the center

	if ((base_return) && (!returned) && (return_time < GetTime()))
	{
		return_time = GetTime() + 0.1f;


		if (GetDistance(shabayev,"base_center") < 60.0f)
		{
			//look_time = GetTime();
			return_time = GetTime() + 0.1f;
			returned = true;
		}
	}
	/////////////////////////////////////////////////


	// this is if the player disreguards the attack message
	
	if (!didnt_listen)
	{
		if ((!second_dead) && (returned) && (return_time < GetTime()))
		{
			return_time = GetTime() + 0.1f;

			if (GetDistance(player,shabayev) < 70.0f)
			{
				if (IsAlive(scion1))
				{
					Attack(scion1,player);
				}
				if (IsAlive(scion2))
				{
					Attack(scion2,player);
				}

				didnt_listen = true;
			}
		}
	}
	/////////////////////////////////////////////////


	// this is red one calling for help after the second battle

	if ((!mayday_message1) && (second_dead) && (lula_time < GetTime()))
	{
		talk = AudioMessage("isdf0127.wav"); // (red1) mayday - we need assistance
		mayday_message1 = true;
	}
	/////////////////////////////////////////////////

	
	// this is shab telling player to return and the wingman reporting that he is banged up

	if ((!bang_up_message) && (returned) && (mayday_message1) && (IsAudioMessageDone(talk)))
	{
		lula_time = GetTime() + 1.0f;


		if (GetDistance(player,shabayev) < 100.0f)
		{
			ClearObjectives();
			AddObjective("isdf0108.otf", GREEN);
			Goto(wingman,"simms_last_point");
			talk = AudioMessage("isdf0128.wav"); // (shab) Red 1 - can you send location
			//wing_look_time = GetTime() + 0.5f;
			bang_up_message = true;
		}
		else if (!return_message)
		{
			ClearObjectives();
			AddObjective("isdf0109.otf", GREEN);
			AddObjective("isdf0108.otf", WHITE);
			AudioMessage("isdf0143.wav");//(shab) Roger Red one. John - rondeszous at base center
			return_message = true;
		}
	}
	////////////////////////////////////////////////


	// this is shab calling for support
/*
	if ((bang_up_message) && (!radio_for_help) && (IsAudioMessageDone(talk)))
	{
		talk = AudioMessage("isdf0144.wav");//(shab) roger that number two - come in base
		radio_for_help = true;
	}
	/////////////////////////////////////////////////


	// this is the messages from the attacked squad and shabayev

	if ((!mayday_message1) && (radio_for_help) && (IsAudioMessageDone(talk)))
	{
		if (GetDistance(shabayev,player) < 150.0f)
		{
			talk = AudioMessage("isdf0127.wav"); // (red1) mayday - we need assistance
			dialog2_time = GetTime() + 20.0f;
			mayday_message1 = true;
		}
	}
	/////////////////////////////////////////////////
*/


	if ((!mayday_message3) && (bang_up_message) && (IsAudioMessageDone(talk)))
	{
		talk = AudioMessage("isdf0129.wav"); // (red1) Affirmative - hurry!

		scion1 = BuildObject("fvpsnt", 2, "combat2c");
		scion2 = BuildObject("fvpsnt", 2, "combat2d");
//		scion3 = BuildObject("fvpsnt", 2, "combat2e");
		red1 = BuildObject("p1scout", 3, "combat2a");
		red2 = BuildObject("p1scout", 3, "combat2b");
		truck = BuildObject("ivserv", 0, "truck_spawn");
		Ally(0,1);
		Ally(1,0);
		Stop(scion1);
		Stop(scion2);
//		Stop(scion3);
		LookAt(red1,player);
		SetObjectiveOn(red1);
		TranslateString2(tempstr, sizeof(tempstr), "Mission0102");  // hostile
		SetObjectiveName(red1,tempstr);
		LookAt(red2,player);
		LookAt(truck,player);

		//dialog2_time = GetTime() + 10.0f;
		look_time = GetTime() + 1.5f;
		away_check = GetTime() + 2.0f;
		attack_check = GetTime() + 1.5f;
		at_player = true;
		mayday_message3 = true;
	}


	// this is Simms saying he can't make it

	if ((!mayday_message2) && (mayday_message3) && (IsAudioMessageDone(talk)))
	{
		LookAt(wingman,shabayev);
		talk = AudioMessage("isdf0130.wav"); // (wingman) I got banged up pretty bad out there sir
		//dialog2_time = GetTime() + 10.0f;
		mayday_message2 = true;
	}
	/////////////////////////////////////////////////


	// this holds all the parties until it's time to fight

	if (mayday_message3)
	{
		if (IsAlive(scion1))
		{
			Stop(scion1);
		}

		if (IsAlive(scion2))
		{
			Stop(scion2);
		}
		
		if (IsAlive(scion3))
		{
			Stop(scion3);
		}

		if (IsAlive(red1))
		{
			//SetTeamNum(red1,1);
			Stop(red1);
		}

		if (IsAlive(red2))
		{
			//SetTeamNum(red2,1);
			Stop(red2);
		}

		if (IsAlive(truck))
		{
			SetTeamNum(truck,1);
			Stop(truck);
		}
	}
	/////////////////////////////////////////////////


	// this is when shab sends the player out into the field

	if (!john_away)
	{
		if ((!alt_message1) && (mayday_message2) && (IsAudioMessageDone(talk)))
		{
			talk = AudioMessage("isdf0145.wav");//(shab) roger that - number 2 stay here - number one follow me!
			alt_message1 = true;
		}


		if ((!to_goalone) && (alt_message1) && (IsAudioMessageDone(talk)))
		{
			ClearObjectives();
			AddObjective("isdf0102.otf", WHITE);
			Goto(shabayev,"goal_one_path");
			Goto(wingman,"base_center");
			to_alone_check = GetTime() + 1.0f;
			look_time = 999999.9f;
			to_goalone = true;
		}


		if ((to_goalone) && (!alt_message2) && (to_alone_check < GetTime()))
		{
			to_alone_check = GetTime() + 1.0f;


			if (GetDistance(shabayev,"goalone_point") < 30.0f)
			{
				LookAt(shabayev,player);
				facing_time = GetTime() + 6.0f;
				talk = AudioMessage("isdf0146.wav");//(shab) This area's too hot, I'll have to stay with number 2. The squad in trouble is just over those hills
				alt_message2 = true;
			}
		}


		if ((alt_message2) && (!change_look1) && (facing_time < GetTime()))
		{
			LookAt(shabayev,red1);
			change_look1 = true;
		}


		// this is if the player's ammo is low

		if ((change_look1) && ((GetCurHealth(player_ship) < 1800) || (GetCurAmmo(player_ship) < 750)))
		{	
			if ((!alt_message3) && (IsAudioMessageDone(talk)))
			{
				LookAt(shabayev,storage_bay);
				h1 = GetCurHealth(player_ship);
				a1 = GetCurAmmo(player_ship);
				talk = AudioMessage("isdf0147.wav");//(shab) I noticed that there were some ammo and repair supplys in that storage bay!
				facing_time = GetTime() + 5.0f;// load up before here before you head out!
				alt_message3 = true;
			}


			if ((alt_message3) && (!goto_sbay) && (facing_time < GetTime()))
			{
				Goto(shabayev,"getammo_point");
				facing_time = GetTime() + 1.0f;
				goto_sbay = true;
			}


			if ((goto_sbay) && (!at_sbay) && (facing_time < GetTime()))
			{
				facing_time = GetTime() + 1.0f;


				if (GetDistance(shabayev,"getammo_point") < 30.0f)
				{
					LookAt(shabayev,player);
					at_sbay = true;
				}
			}
		}
		/////////////////////////////////////////////////

		// this tells the player to go out there and help

		if ((!alt_message4) && (alt_message2))
		{
			if (alt_message3)
			{
				h2 = GetCurHealth(player_ship);
				a2 = GetCurAmmo(player_ship);


				if ((a2>a1) || (h2>h1))
				{
					StopAudioMessage(talk);
					ClearObjectives();
					AddObjective("isdf0110.otf", WHITE);
					AudioMessage("isdf0148.wav");//(shab) alright John - now go help those men!
					away_check2 = GetTime() + 120.0f;
					attack_check = GetTime() + 1.5f;
					alt_message4 = true;
				}
			}
			else if (IsAudioMessageDone(talk))
			{
				ClearObjectives();
				AddObjective("isdf0110.otf", WHITE);
				LookAt(shabayev,player);
				AudioMessage("isdf0148.wav");//(shab) alright John - now go help those men!
				away_check2 = GetTime() + 120.0f;
				attack_check = GetTime() + 1.5f;
				alt_message4 = true;
			}
		}
		/////////////////////////////////////////////////
	}
	/////////////////////////////////////////////////

/*
	if ((!mayday_message5) && (mayday_message3) && (IsAudioMessageDone(talk)))
	{
//		talk = AudioMessage("isdf0131.wav"); // (shab) Roger - John, you're going to have to go!
//		dialog2_time = GetTime() + 10.0f;
//		away_check = GetTime() + 2.0f;
//		away_check2 = GetTime() + 120.0f;
//		attack_check = GetTime() + 1.5f;
//		mayday_message5 = true;
	}


	// this contols who the wingman is looking at

	if (!john_away)
	{
		if (wing_look_time < GetTime())
		{
			if ((!wingat_player) && (IsAlive(wingman)))
			{
				LookAt(wingman,player);
				wing_look_time = GetTime() + 6.0f;
				wingat_player = true;
			}
			else if (IsAlive(wingman))
			{
				LookAt(wingman,shabayev);
				wing_look_time = GetTime() + 15.0f;
				wingat_player = false;
			}
		}
	}
	/////////////////////////////////////////////////	
*/

	// this is checking to see if the player actually goes to help

	if ((!coward2) && (alt_message4) && (away_check2 < GetTime()))
	{
		ClearObjectives();
		AddObjective("isdf0110.otf", WHITE);
		AudioMessage("isdf0132.wav"); // (shab) what's the hold up John?
		away_check2 = GetTime() + 160.0f;
		coward2 = true;
	}
	/////////////////////////////////////////////////	


	// this is checking to see of john is heading for the battlezone or wasting time

	if ((!john_away) && (away_check < GetTime()))
	{
		away_check = GetTime() + 1.0f;

		if (GetDistance(player,red1) < 200.0f)
		{
			Goto(shabayev,"base_center");
			attack_check = GetTime() + 1.0f;
			SetObjectiveOff(shabayev);
			john_away = true;
			coward2 = false;
		}
	}
	/////////////////////////////////////////////////	
}



// now the player is on his own ///////////////////////////////////



if (john_away)
{
	if (!john_close)
	{
		// this holds all the players until the time is right

		if (IsAlive(scion1))
		{
			Stop(scion1);
		}
		if (IsAlive(scion2))
		{
			Stop(scion2);
		}	
		if (IsAlive(scion3))
		{
			Stop(scion3);
		}
		if (IsAlive(red1))
		{
			Stop(red1);
		}
		if (IsAlive(red2))
		{
			Stop(red2);
		}
		if (IsAlive(truck))
		{
			Stop(truck);
		}
	}
	/////////////////////////////////////////////////	


	// this is triggering the attack and blowing up red 2

	if ((!john_close) && (attack_check < GetTime()))
	{
		attack_check = GetTime() + 0.5f;


		if (GetDistance(player,red1) < 200.0f)
		{
			if (IsAlive(red2))
			{
				Damage(red2, 1990);
				Defend(red2,last_crate);
			}

			if (IsAlive(red1))
			{
				Attack(red1,scion1);
			}

			if (IsAlive(scion1))
			{
				Defend(scion1,last_crate);
			}

			if (IsAlive(scion2))
			{
				Defend(scion2,last_crate);
			}

			if (IsAlive(scion3))
			{
				Defend(scion3,last_crate);
			}

			in_combat = true;
			john_close = true;
		}
	}
	/////////////////////////////////////////////////	


	// this keeps red1 alive

	if ((!red1_return) && (IsAlive(red1)))
	{
		if ((attack2) && (GetCurHealth(red1) < 200))
		{
			SetCurHealth(red1, 200);
		}
	}
	/////////////////////////////////////////////////

/*
	if ((!truck_return) && (attack2))
	{	
		if (!freed)
		{
			if (IsAlive(scion1))
			{
				Goto(scion1,"combat2a");
			}
			

			if (IsAlive(scion2))
			{
				Goto(scion2,"combat2b");
			}


			if (IsAlive(scion3))
			{
				Goto(scion3,"combat2b");
			}

			freed = true;
		}


		if (!john_close)
		{
			if (IsAlive(red2)) 
			{
				LookAt(red2,player);
			}

			if (IsAlive(truck))
			{
				LookAt(truck,player);
			}
		}
	}
*/
	
	// this is checking to see when the battle is over

	if ((!battle2_over) && (!IsAlive(scion1)) && (!IsAlive(scion2)) && (!IsAlive(scion3)))
	{
		if (IsAlive(red1))
		{
			Goto(red1,player);
		}

		if (IsAlive(red2))
		{
			Damage(red2, 2000);
		}
		
		ClearObjectives();
		AddObjective("isdf0110.otf", GREEN);
		red1_check = GetTime() + 1.0f;
		in_combat = false;
		battle2_over = true;
	}
	/////////////////////////////////////////////////

	
	// this is when red1 thanks player

	if ((!thanks_message) && (battle2_over) && (IsAlive(red1)) && (red1_check < GetTime()))
	{
		red1_check = GetTime() + 0.2f;

		if (GetDistance(red1,player) < 60.0f)
		{
			LookAt(red1,player);
			speak = AudioMessage("isdf0133.wav"); // red1 thanks! look for my service truck in crater
			red1_check = GetTime() + 2.5f;
			in_combat = false;		
			thanks_message = true;
		}
	}
	/////////////////////////////////////////////////


	// this makes red1 look at the truck

	if ((!red_look_truck) && (thanks_message) && (red1_check < GetTime()))
	{
		LookAt(red1,truck);
		SetObjectiveOn(truck);
		TranslateString2(tempstr, sizeof(tempstr), "Mission0103");  // hostile
		SetObjectiveName(truck,tempstr);
		red_look_truck = true;
	}


	// this is sending red1 back to base

	if ((!red1_return) && (red_look_truck) && (IsAudioMessageDone(speak)))
	{
		ClearObjectives();
		AddObjective("isdf0111.otf", WHITE);
		SetObjectiveOff(red1);
		Goto(red1, "truck_home_point");
		truck_check = GetTime() + 2.0f;
		truck_lost_check = GetTime() + 160.0f;
		red1_return = true;
	}
	/////////////////////////////////////////////////


	// this is if the player does not reach the truck

	if (IsAlive(truck))
	{
		if ((!truck_found) && (!no_find_truck) && (red1_return) && (truck_lost_check < GetTime()))
		{
			ClearObjectives();
			AddObjective("isdf0111.otf", WHITE);
			truck_lost_check = GetTime() + 180.0f;
			AudioMessage("isdf0134.wav"); // (shab) go to truck!
			SetObjectiveOn(truck);
			no_find_truck = true;
		}
		

		// this is checking to see if the player reaches the lost truck

		if ((!truck_found) && (red1_return) && (truck_check < GetTime()))
		{
			truck_check = GetTime() + 2.0f;


			 if (GetDistance(player,truck) < 100.0f)
			 {
				ClearObjectives();
				AddObjective("isdf0111.otf", GREEN);
				talk = AudioMessage("isdf0135.wav"); // (truck) get me out of here!
				truck_talk_time = GetTime() + 10.0f;
				truck_found = true;
			 }
		}
		/////////////////////////////////////////////////


		if ((!truck_response1) && (truck_found) && (IsAudioMessageDone(talk)))
		{
			SetObjectiveOn(shabayev);
			SetObjectiveName(shabayev,"Cmd. Shabayev");
			talk = AudioMessage("isdf0136.wav"); // (shab) truck john will escort you back to base you must leave that area!
			truck_talk_time = GetTime() + 10.0f;
			spawn_check = GetTime() + 1.0f;
			truck_response1 = true;
		}


		if ((!truck_return) && (truck_response1) && (IsAudioMessageDone(talk)))
		{
			talk = AudioMessage("isdf0137.wav"); // (truck) all right
			truck_talk_time = GetTime() + 10.0f;
			Goto(truck,"truck_path",1);
			truck_return = true;
		}


		if ((!truck_response2) && (truck_return) && (IsAudioMessageDone(talk)))
		{
			ClearObjectives();
			AddObjective("isdf0112.otf", WHITE);
			talk = AudioMessage("isdf0138.wav"); // (shab) john - protect that truck
			truck_talk_time = GetTime() + 10.0f;
			in_combat = true;
			truck_response2 = true;
		}
	}
	/////////////////////////////////////////////////


	if ((!last_spawned) && (truck_response2) && (spawn_check < GetTime()))
	{
		//spawn_check = GetTime() + 3.0f;

		//x = GetDistance(player,"espawn_truck");
		//y = GetDistance(player,"espawn1_combat2");

		
		//if ((x > 300) && (y > 300))
		//{
			scion1 = BuildObject("fvpsnt", 2,"espawn_truck");
			scion2 = BuildObject("fvpsnt", 2,"espawn1_combat2");


			if (IsAlive(truck))
			{
				Attack(scion1,truck,0);
				Attack(scion2,truck,0);
			}

			spawn_check = GetTime() + 3.0f;
			last_check = GetTime() + 2.0f;
			last_spawned = true;
		//}
	}

	// this will build the third scion

	if ((!extra_spawned) && (last_spawned) && (spawn_check < GetTime()))
	{
		scion3 = BuildObject("fvpsnt", 2,"espawn1_combat2");

		if (IsAlive(truck))
		{
			Attack(scion3,truck);
		}

		extra_spawned = true;
	}

	
	// this will have shab come and help John if he is close to the base at the end.

	if ((last_spawned) && (!last_message) && (last_check < GetTime()))
	{
		last_check = GetTime() + 2.0f;


		if ((IsAlive(scion1)) && (GetDistance(player,scion1) < 450.0f))
		{
			AudioMessage("isdf0149.wav");//(shab) I picking up two more on an intercept course - hold them off - I'm on my way!
			Goto(shabayev,player);
			last_check = GetTime() + 2.0f;
			last_message = true;
		}
		else if ((IsAlive(scion2)) && (GetDistance(player,scion2) < 450.0f))
		{
			AudioMessage("isdf0149.wav");//(shab) I picking up two more on an intercept course - hold them off - I'm on my way!
			Follow(shabayev,truck,1);
			last_check = GetTime() + 2.0f;
			last_message = true;
		}
	}
	/////////////////////////////////////////////////


	if ((last_message) && (!last_message2) && (!last_attack) && (last_check < GetTime()))
	{
		last_check = GetTime() + 2.0f;


		if (GetDistance(shabayev,truck) < 100.0f)
		{
			if (IsAlive(scion1))
			{
				Attack(shabayev,scion1);
				Attack(scion1,truck);

				if (IsAlive(scion2))
				{
					Attack(scion2,truck);
				}

				last_attack = true;
			}
			else if (IsAlive(scion2))
			{
				Attack(shabayev,scion2);
				Attack(scion2,truck);
				last_attack = true;
			}
		}
	}


	if ((last_message) & (!last_message2))
	{
		if ((!IsAlive(scion1)) && (!IsAlive(scion2)) && (!IsAlive(scion3)))
		{
			if (GetDistance(truck,"base_center") > 100.0f)
			{
				Follow(shabayev,truck);
				talk = AudioMessage("isdf0158.wav");//(shab) good job follow THE TRUCK back to base
				
				//scion1 = BuildObject("fvpsnt", 2,"espawn_truck");
				//scion2 = BuildObject("fvpsnt", 2,"espawn1_combat2");
				//Attack(scion1,truck);
				//Attack(scion2,truck);
				//really_last_time = GetTime() + 1.0f;				
				
				tubby = true;
			}

			last_message2 = true;
		}

		else if ((!gus) && (!IsAlive(scion1)))
		{
			Attack(shabayev,scion2);
			gus = true;
		}
		else if ((!gus) && (!IsAlive(scion2)))
		{
			Attack(shabayev,scion1);
			gus = true;
		}
		
	}

	// this is sending in the VERY last wave

	if (tubby)
	{
		if ((!very_last_message) && (really_last_time < GetTime()))
		{
			really_last_time = GetTime() + 1.0f;

			if ((GetDistance(scion1,player) < 350.0f) || (GetDistance(scion2,player) < 350.0f))
			{
				AudioMessage("isdf0175.wav"); // (shab) two more coming in!
				very_last_message = true;
			}
		}
		/////////////////////////////////////////////////
	}
}


// this is what happens if the player gets "lost" /////////////////



if ((player_lost) && (IsAlive(shabayev)))
{
	LookAt(shabayev,player);

	if (!set_lost_times) // reset
	{
		// this is when he leaves the base after getting there

		if ((!left_base) && (shab_to_center))
		{
			if (!return_to_base) // reset
			{
				AudioMessage("isdf0150.wav"); // (Shab) where are you going John?!
				LookAt(shabayev,player);
				player_lost_time = GetTime() + 2.0f;
				lost_warning_time = GetTime() + 40.0f;
				return_to_base = true;
				set_lost_times = true;
			}
		}
		// this is what happens when he leaves in the field
		else
		{
			AudioMessage("return01.wav"); // (Shab) number 1 return to squad!
			player_lost_time = GetTime() + 2.0f;


			if (!first_time)
			{
				lost_warning_time = GetTime() + 40.0f;
			}
			else
			{
				lost_warning_time = GetTime() + 60.0f;
			}

			set_lost_times = true;
		}
	}
	/////////////////////////////////////////////////


	if (set_lost_times)
	{
		if ((return_to_base) && (!return_to_base2) && (lost_warning_time < GetTime()))
		{
			AudioMessage("isdf0151.wav"); // (Shab) return to the base immediately!
			LookAt(shabayev,player);
			lost_warning_time = GetTime() + 40.0f;
			return_to_base2 = true;
		}


		if ((!shab_to_center) || ((shab_to_center) && (left_base)))
		{
			if ((first_time) && (lost_warning_time < GetTime()))
			{
				LookAt(shabayev,player);
				AudioMessage("return04.wav"); // (Shab) use your radar to find me!
				lost_warning_time = GetTime() + 90.0f;
				first_time = false;
			}


			if ((!second_warning)  && (lost_warning_time < GetTime()))
			{
				LookAt(shabayev,player);
				AudioMessage("return02.wav"); // (Shab) This is your last warning!
				lost_warning_time = GetTime() + 40.0f;
				second_warning = true;
			}
		}
	}




	// this is if the player returns

	if ((set_lost_times) && (player_lost_time < GetTime()))
	{
		player_lost_time = GetTime() + 2.0f;


		if ((shab_to_center) && (!left_base))
		{
			if (GetDistance(player,"base_center") < 100.0f)
			{
//				AudioMessage("return05.wav"); // (shab) thanks for complying - do you want to carry out my orders now?!
				player_lost = false;
				set_lost_times = false;
				return_to_base = false;
				return_to_base2 = false;
			}
		}
		else if (GetDistance(shabayev,player) < 50.0f)
		{
			if ((!first_time) && (!encouragement))
			{
				AudioMessage("return05.wav"); // (shab) Good! hang in there, the terrain is pretty trecherous!
				encouragement = true;
			}

			wait2_time = GetTime() + 5.0f;
			player_lost = false;
			player_awl = false;
			set_lost_times = false;
			second_warning = false;
		}
	}
	/////////////////////////////////////////////////
}
	

// these are the win/loose conditions ///////////////////////////


if (!game_over)
{
	// this is the winning condition

	if ((truck_response2) && (!game_over) && (truck_talk_time < GetTime()))
	{
		truck_talk_time = GetTime() + 1.0f;

		if (/*(last_message2)*/(last_spawned) && (!IsAlive(scion1)) && (!IsAlive(scion2)) && (!IsAlive(scion3)))
		{
			if (GetDistance(truck,"truck_home_point") < 100.0f)
			{
				ClearObjectives();
				AddObjective("isdf0112.otf", GREEN);
				AudioMessage("isdf0157.wav"); // (shab) Well done John!
				SucceedMission(GetTime() + 10.0f,"isdf01w1.txt");
				game_over = true;
			}
		}
	}
	/////////////////////////////////////////////////


	// this is if the player kills one of the openning wingman
	
	if ((start_done) && (!first_squad_removed))
	{
		if ((!IsAlive(squad1_a)) || (!IsAlive(squad1_b)) || (!IsAlive(squad1_c)))
		{
			FailMission(GetTime() + 1.0f);
			game_over = true;
		}
	}
	/////////////////////////////////////////////////


	// this is for when the player is away from shabayev for too long

	if ((player_lost) && ((second_warning) || (return_to_base2)) && (lost_warning_time < GetTime()))
	{
		if ((shab_at_base) && (!left_base))
		{
			AudioMessage("isdf0152.wav"); // have fun out there - your demoted for not obeying orders
		}
		else if ((shab_at_base) && (left_base)) // she was at the base but now left
		{
			AudioMessage("return03.wav"); // (shab) I'm moving on without you
		}
		else
		{
			AudioMessage("return03.wav"); // (shab) I'm moving on without you!
		}

		FailMission(GetTime() + 15.0f);
		game_over = true;
	}
	/////////////////////////////////////////////////


	// this is if shabayev gets destroyed

	if ((!IsAlive(shabayev)) && (!game_over))
	{
		FailMission(GetTime() + 5.0f);
		game_over = true;
	}
	/////////////////////////////////////////////////


	// this is if the player blows up the comm. building

	if ((!IsAround(comm_building)) && (!game_over))
	{
		AudioMessage("isdf0153.wav"); // (shab) I gave no order to destroy anything!
		FailMission(GetTime() + 15.0f);
		game_over = true;
	}
	/////////////////////////////////////////////////


	// this is if the player's ship gets destroyed

	if ((!IsAround(player_ship)) && (!ship_destroyed))
	{
		ship_destroyed_time = GetTime() + 3.0f;
		ship_destroyed = true;
	}


	if ((ship_destroyed) && (!game_over) && (ship_destroyed_time < GetTime()))
	{
		AudioMessage("isdf0154.wav"); // (shab) we don't have another ship in the area!
		FailMission(GetTime() + 15.0f);
		game_over = true;
	}
	/////////////////////////////////////////////////


	// if the player does not return to his ship after entering building

	if ((shab_warning1) && (!left_base) && (!game_over) && (john_ship_check < GetTime()))
	{
		AudioMessage("return03.wav"); // (shab) I'm moving on without you!
		FailMission(GetTime() + 15.0f);
		game_over = true;
	}
	/////////////////////////////////////////////////


	// this is if the player never shows up at the second battle

	if ((coward2) && (!attack2) && (!game_over) && (away_check2 < GetTime()))
	{
		ClearObjectives();
		AddObjective("isdf0110.otf", WHITE);
		AudioMessage("isdf0155.wav"); // (shab) those men are lost because you did not follow orders!
		FailMission(GetTime() + 15.0f);
		game_over = true;
	}
	/////////////////////////////////////////////////


	// this is chcking to see if the truck is alive

	if ((truck_return) && (!game_over) && (!IsAlive(truck)))
	{
		ClearObjectives();
		AddObjective("isdf0112.otf", RED);
		AudioMessage("isdf0156.wav"); // (shab) You let the truck get destroyed john!
		FailMission(GetTime() + 15.0f);
		game_over = true;
	}
	/////////////////////////////////////////////////

	if (GetCurAmmo(player)<105)
		SetCurAmmo(player,106);  // HACK HACK
}


/////////////////////////////////////////////////////////////	
} // ON_HOLD

if (ON_HOLD)
{
/////////////////////////////////////////////////////////////	

	johns_orders = true;

	// this is where I need to determine if the player is in the building

	if (InBuilding(player))
	{
		inside = true;

		if ((!in_comm) && (GetDistance(player,comm_building) < 20.0f))
		{
			in_comm = true;
		}
	}
	else
	{
		inside = false;
		in_comm = false;
	}


	// this is where I trigger the cineractive

	if (johns_orders)
	{
		if ((!start_cineractive) && (in_comm) && (GetDistance(player,manson) < 4))
		{
			CameraReady();
			line = AudioMessage("cut0201.wav"); // (cook) Someone is in here!
			//camera_time = GetTime() + 5.0f;
			start_cineractive = true;
		}
	}


	// this is the movie code

	if ((!camera1_over) && (start_cineractive))
	{
		if (!first_frame) 
		{
			CameraReady();
			first_frame = true;
		}
		
		PlayMovie("manson1");
	}


	if ((!camera2_over) && (first_frame) && (line4))
	{
		CameraObject(shabayev,0,1,5,shabayev); // 3.7
		//a = a + 0.1;
		camera1_over = true;
	}


	if ((movie1) && (line5))
	{
		if (!reframe1)
		{
			//StopMovie();
			CameraReady();
			reframe1 = true;
		}

		movie1 = PlayMovie("base_look");
		movie2 = true;
	}

	
	if ((!movie1) && (movie2))
	{
		movie2 = PlayMovie("manson2");
		camera3_over = true;
	}

	////////////////////////////////////////////


	if ((!line2) && (start_cineractive) && (IsAudioMessageDone(line)))
	{
		line = AudioMessage("cut0202.wav"); // (shab) A man? Is he alive?
		line2 = true;
	}
	if ((!line3) && (line2) && (IsAudioMessageDone(line)))
	{
		line = AudioMessage("cut0203.wav"); // (manson) If you call this living - who is this?
		SetAnimation(manson,"line1",1);
		line3 = true;
	}
	if ((!line4) && (line3) && (IsAudioMessageDone(line)))
	{
		line = AudioMessage("cut0204.wav"); // (shab) This is shab?
		line4 = true;
	}
	if ((!line5) && (line4) && (IsAudioMessageDone(line)))
	{
		line = AudioMessage("cut0205.wav"); // (manson) is your radio working?
		//SetAnimation(manson,"line2",1);
		StopMovie();
		CameraFinish();
		camera2_over = true;
		line5 = true;
	}
	if ((!line6) && (line5) && (IsAudioMessageDone(line)))
	{
		//Matrix pos;
		//GetPosition(manson,pos);
		//RemoveObject(manson);
		//manson = BuildObject("manson2",0,pos);

		line = AudioMessage("cut0206.wav"); // (shab) no - interfierence?
		line6 = true;
	}
	if ((!line7) && (line6) && (IsAudioMessageDone(line)))
	{
		SetAnimation(manson,"line2",1);
		line = AudioMessage("cut0207.wav"); // (manson) Then they already know you are hear!
		line7 = true;
	}


	// this is where I trigger the cineractive

	if ((!cineractive_over) && (line7) && (IsAudioMessageDone(line)))
	{
		CameraFinish();
		cineractive_over = true;

		if (!shab_at_comm)
		{
			Goto(shabayev,player_ship);
			shab_at_comm = true;
		}
	}
	/////////////////////////////////////////////////

///////////////////////////////////////////////////////
} // ON_HOLD
///////////////////////////////////////////////////////


}
