#include "..\Shared\SPMission.h"

class scion04 : public SPMission 
{
public:
	scion04(void)
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

	bool PostLoad(bool missionSave);

	// bools
	bool
		b_first,
		missionstart,vo1,obj1,attack1,playermeetevil,evilgo1,evilattacked,
		playernotcoming1,firstwarning,secondwarning,thirdwarning,playercaughtup,warn1,warn2,
		playerattackedevil,evilgo2,warn3,playeratambush,ambushstart,missionwon,missionlost,
		powerdead,tankscharge1,tankscharge2,vo10,obj4,haulerdead,vo9,missionlost2,obj3,
		warn2a,bigspawnstart,walk_spawn,walk1_stop,walk2_stop,
		spawn1_7,spawn2_8,spawn3_9,spawn4_10,spawn5_11,spawn6_12,bigspawn_cin_over,
		stop1,stop2,stop3,stop4,stop5,stop6,stop7,stop8,stop9,stop10,stop11,stop12,
		rdycam1,bigspawn_shot1_over,bigspawn_shot2,rdycam2,bigspawn_shot3,rdycam3,
		bigspawn_shot1,player_at_machine,tug_at_machine,start_bigspawn,
		bossman_stop,succeedmission,
		bossman_go,vo7,
		bigspawn_shot4,rdycam4,rebels_attack,
		player_at_dropship1,fakers_stop_attack,
		takeoff_shot1,takeoff,
		takeoff_rdycam1,picktarget,release_others,
		evil1dead,evil2dead,evil3dead,vo6,all_evils_dead,vo8,vo12,
		spawn_circle_tank1,circle_tank1_dead,circle_spawns_over,
		spawn_circle_tank2,circle_tank2_dead,
		spawn_circle_scout1,circle_scout1_dead,
		spawn_circle_scout2,circle_scout2_dead,
		circle_scout1_attack,circle_scout2_attack,
		circle_tank1_attack,circle_tank2_attack,tug1_stop,
		bigspawn_shot5,rdycam5,
		cutvo1,bigspawn_shot6,rdycam6,attack_tug,
		check_tug_dead,stealer11_12_goback,
		stealer11_relook,stealer12_relook,stealer9_relook,stealer10_relook,
		cutvo3,bigspawn_shot7,rdycam7,cutvo4,cutvo5,cutvo6,
		cutvo4over,cutvo5over,cutvo6over,
		sick_first6_on_player,
		take_off_sound,


		b_last;

	// floats
	float
		f_first,
		vo1time,
		warn1time,
		warn2time,warn3time,vo9time,
		vo10time,walk_spawntime,succeedmission_time,
		stealer1_7time,stealer2_8time,stealer3_9time,stealer4_10time,stealer5_11time,stealer6_12time,
		bigspawn_shot1_overtime,bigspawn_shot2_overtime,bossman_gotime,bigspawn_shot3_overtime,
		bigspawn_shot4_overtime,bigspawn_shot1_starttime,takeoff_time,
		fakers_stop_attacktime,stealers_attacktime,release_otherstime,vo8time,
		vo6time,vo7time,vo12time,spawn_circle_tank1time,spawn_circle_tank2time,
		spawn_circle_scout1time,spawn_circle_scout2time,
		bigspawn_shot5_overtime,cutvo1time,
		bigspawn_shot6_overtime,attack_tugtime,cutvo3time,
		bigspawn_shot7_overtime,cutvo4time,cutvo5time,cutvo6time,
		sick_first6_on_playertime,take_off_soundtime,


		f_last;

	// handles
	Handle
		h_first,
		tug1,power,msg1,machine,
		rtattack1,rtattack2,rtattack3,rtattack4,rtattack5,rtattack6,rtattack7,rtattack8,player,
		evil1,evil2,evil3,msg2,ambusher1,ambusher2,ambusher3,ambusher4,ambusher5,
		ambusher6,rckt1,rckt2,rckt3,rckt4,tank1,tank2,tank3,tank4,circle_scout1,circle_scout2,
		fvtank1,fvtank2,fvtank3,fvsent1,fvsent2,fvsent3,fvserv1,msg10,msg9,
		stealer1,stealer2,stealer3,stealer4,stealer5,stealer6,stealer7,stealer8,
		stealer9,stealer10,stealer11,stealer12,ailook,stealer_walk1,stealer_walk2,
		bossman,bigspawn_cam1look,bigspawn_cam2look,bigspawn_camlook3,
		bigspawn_cam4look,dropship1,dropship2,
		faker1,faker2,faker3,faker4,fvarch1,fvarch2,circle_tank1,circle_tank2,
		tugshot_look1,cutmsg4,cutmsg5,cutmsg6,
		
		h_last;


	// integers
	int
		i_first,


		i_last;
};
DLLBase * BuildMission(void)
{
	return new scion04();
}

void scion04::Setup(void)
{
	SetAutoGroupUnits(false);
/*
	Here's where you set the values at the start.  
*/

//  bools
	missionstart = false;
	vo1 = false;
	obj1 = false;
	attack1 = false;
	playermeetevil = false;
	evilgo1 = false;
	evilattacked = false;
	playernotcoming1 = false;
	firstwarning = false;
	secondwarning = false;
	thirdwarning = false;
	playercaughtup = false;
	warn1 = false;
	warn2 = false;
	warn2a = false;
	playerattackedevil = false;
	evilgo2 = false;
	warn3 = false;
	playeratambush = false;
	ambushstart = false;
	missionwon = false;
	missionlost = false;
	powerdead = false;
	tankscharge1 = false;
	tankscharge2 = false;
	vo10 = false;
	obj4 = false;
	haulerdead = false;
	vo9=false;
	missionlost2 = false;
	obj3 = false;
	bigspawnstart = false;
	spawn1_7 = false;
	spawn2_8 = false;
	spawn3_9 = false;
	spawn4_10 = false;
	spawn5_11 = false;
	spawn6_12 = false;
	stop1 = false;
	stop2 = false;
	stop3 = false;
	stop4 = false;
	stop5 = false;
	stop6 = false;
	stop7 = false;
	stop8 = false;
	stop9 = false;
	stop10 = false;
	stop11 = false;
	stop12 = false;
	walk_spawn = false;
	walk1_stop = false;
	walk2_stop = false;
	bossman_go = false;
	bossman_stop = false;
	bigspawn_cin_over = false;
	rdycam1 = false;
	bigspawn_shot1_over = false;
	bigspawn_shot2 = false;
	rdycam2 = false;
	bigspawn_shot3=false;
	rdycam3 = false;
	bigspawn_shot4 = false;
	rdycam4 = false;
	player_at_machine = false;
	tug_at_machine = false;
	start_bigspawn = false;
	succeedmission = false;
	rebels_attack = false;
	player_at_dropship1 = false;
	takeoff_shot1 = false;
	takeoff_rdycam1 = false;
	takeoff = false;
	fakers_stop_attack = false;
	picktarget = false;
	release_others = false;
	evil1dead = false;
	evil2dead = false;
	evil3dead = false;	
	vo6 = false;
	vo7 = false;
	all_evils_dead = false;
	vo8 = false;
	vo12 = false;
	circle_spawns_over = false;

	spawn_circle_tank1 = false;
	circle_tank1_dead = false;


	spawn_circle_tank2 = false;
	circle_tank2_dead = false;

	spawn_circle_scout1 = false;
	circle_scout1_dead = false;

	spawn_circle_scout2 = false;
	circle_scout2_dead = false;

	circle_scout1_attack = false;
	circle_scout2_attack = false;
	circle_tank1_attack = false;
	circle_tank2_attack = false;

	tug1_stop = false;

	bigspawn_shot5 = false;
	rdycam5 = false;
	cutvo1 = false;
	bigspawn_shot6 = false;
	rdycam6 = false;
	attack_tug = false;
	check_tug_dead = false;
	stealer11_12_goback = false;
	stealer11_relook = false;
	stealer12_relook = false;
	cutvo3 = false;
	bigspawn_shot7 = false;
	rdycam7 = false;
	cutvo4 = false;
	cutvo5 = false;
	cutvo6 = false;
	cutvo4over = false;
	cutvo5over = false;
	cutvo6over = false;
	sick_first6_on_player = false;
	stealer9_relook = false;
	stealer10_relook = false;
	take_off_sound = false;

//  floats
	vo1time = 999999.9f;
	warn1time = 999999.9f;
	warn2time = 999999.9f;	
	warn3time = 999999.9f;
	vo9time = 999999.9f;
	vo10time = 999999.9f;
	stealer1_7time = 999999.9f;
	stealer2_8time = 999999.9f;
	stealer3_9time = 999999.9f;
	stealer4_10time = 999999.9f;
	stealer5_11time = 999999.9f;
	stealer6_12time = 999999.9f;
	walk_spawntime = 999999.9f;
	bigspawn_shot1_overtime = 999999.9f;
	bigspawn_shot2_overtime = 999999.9f;
	bigspawn_shot3_overtime = 999999.9f;
	bossman_gotime = 999999.9f;
	bigspawn_shot4_overtime = 999999.9f;
	bigspawn_shot1_starttime = 999999.9f;
	succeedmission_time = 999999.9f;
	takeoff_time = 999999.9f;
	fakers_stop_attacktime = 999999.9f;
	stealers_attacktime = 999999.9f;
	release_otherstime = 999999.9f;
	vo6time = 999999.9f;
	vo7time = 999999.9f;
	vo8time = 999999.9f;
	vo12time = 999999.9f;
	spawn_circle_tank1time = 999999.9f;
	spawn_circle_tank2time = 999999.9f;
	spawn_circle_scout1time = 999999.9f;
	spawn_circle_scout2time = 999999.9f;
	bigspawn_shot5_overtime = 999999.9f;
	cutvo1time = 999999.9f;
	bigspawn_shot6_overtime = 999999.9f;
	attack_tugtime = 999999.9f;
	cutvo3time = 999999.9f;
	bigspawn_shot7_overtime = 999999.9f;
	cutvo4time = 999999.9f;
	cutvo5time = 999999.9f;
	cutvo6time = 999999.9f;
	sick_first6_on_playertime = 999999.9f;
	take_off_soundtime = 999999.9f;
//  handles
	tug1 = GetHandle("tug1");
	power = GetHandle("power");
	msg1 = NULL;
	machine = GetHandle("machine");
	rtattack1 = GetHandle("rtattack1");
	rtattack2 = GetHandle("rtattack2");
	rtattack3 = GetHandle("rtattack3");
	evil1 = GetHandle("evil1");
	evil2 = GetHandle("evil2");
	evil3 = GetHandle("evil3");
	rtattack4 = NULL;
	rtattack5 = NULL;
	rtattack6 = NULL;
	rtattack7 = NULL;
	rtattack8 = NULL;
	player = NULL;
	msg2 = NULL;
	ambusher1 = GetHandle("ambusher1");
	ambusher2 = GetHandle("ambusher2");
	ambusher3 = GetHandle("ambusher3");
	ambusher4 = GetHandle("ambusher4");
	ambusher5 = GetHandle("ambusher5");
	ambusher6 = GetHandle("ambusher6");
	rckt1 = GetHandle("rckt1");
	rckt2 = GetHandle("rckt2");
	rckt3 = GetHandle("rckt3");
	rckt4 = GetHandle("rckt4");
	tank1 = GetHandle("tank1");
	tank2 = GetHandle("tank2");
	tank3 = GetHandle("tank3");
	tank4 = GetHandle("tank4");
	circle_scout1 = NULL;
	circle_scout2 = NULL;
	fvtank1 = GetHandle("fvtank1");
	fvtank2 = GetHandle("fvtank2");
	fvtank3 = GetHandle("fvtank3");
	fvsent1 = GetHandle("fvsent1");
	fvsent2 = GetHandle("fvsent2");
	fvsent3 = GetHandle("fvsent3");
	fvserv1 = GetHandle("fvserv1");
	ailook = GetHandle("ailook");
	stealer_walk1 = NULL;
	stealer_walk2 = NULL;
	msg10 = NULL;
	msg9=NULL;
	stealer1 = NULL;
	stealer2 = NULL;
	stealer3 = NULL;
	stealer4 = NULL;
	stealer5 = NULL;
	stealer6 = NULL;
	stealer7 = NULL;
	stealer8 = NULL;
	stealer9 = NULL;
	stealer10 = NULL;
	stealer11 = NULL;
	stealer12 = NULL;
	bossman = NULL;
	bigspawn_cam1look = GetHandle("bigspawn_cam1look");
	bigspawn_cam2look = GetHandle("bigspawn_cam2look");
	bigspawn_camlook3 = GetHandle("bigspawn_camlook3");
	bigspawn_cam4look = GetHandle("bigspawn_cam4look");
	dropship1 = GetHandle("dropship1");
	dropship2 = GetHandle("dropship2");
	faker1 = NULL;
	faker2 = NULL;
	faker3 = NULL;
	faker4 = NULL;
	fvarch1 = GetHandle("fvarch1");
	fvarch2 = GetHandle("fvarch2");
	circle_tank1 = NULL;
	circle_tank2 = NULL;
	tugshot_look1 = GetHandle("tugshot_look1");
	cutmsg4 = NULL;
	cutmsg5 = NULL;
	cutmsg6 = NULL;
//  integers

	SetTeamColor(3,85,255,85);  //REBELS		
	SetTeamColor(2,85,255,85);  //REBELS



}

bool scion04::PostLoad(bool missionSave)
{
	bool ret = SPMission::PostLoad(missionSave);

	if (missionSave)
		return ret;

	SetAnimation(dropship1,"deploy",1);
	SetAnimation(dropship2,"deploy",1);
	SetTeamColor(3,85,255,85);  //REBELS		
	SetTeamColor(2,85,255,85);  //REBELS

	return ret;
}

void scion04::AddObject(Handle h)
{
}

void scion04::Execute(void)
{
/*
	Here is where you put what happens every frame.  
*/	
	player = GetPlayerHandle();
	char tempstr[128];
//	SetCurHealth(tug1,2500);
	if (!missionstart)
	{
		SetTeamNum(evil1,2);
		SetTeamNum(evil2,2);
		SetTeamNum(evil3,2);
		SetIndependence(evil1,0);
		SetIndependence(evil2,0);
		SetIndependence(evil3,0);
		
		SetMaxHealth(machine,999999);
		SetCurHealth(machine,999999);
		Ally(2,3);
		Ally(2,4);
		Ally(3,4);
		vo1time = (GetTime() + 4);
		Pickup(tug1,power,0);
		SetMaxHealth(tug1,8000);
		SetCurHealth(tug1,8000);
		Patrol(rckt1,"rckt1path");
		Patrol(rckt2,"rckt2path");
		Patrol(rckt3,"rckt3path");
		Patrol(rckt4,"rckt4path");
	//	Patrol(scout1,"scoutpath");
	//	Patrol(scout2,"scoutpath");
		SetAvoidType(tug1,0);
		SetAvoidType(fvserv1,0);
		SetAvoidType(fvtank1,0);
		SetAvoidType(fvtank2,0);
		SetAvoidType(fvtank3,0);
		SetAvoidType(fvsent1,0);
		SetAvoidType(fvsent2,0);
		SetAvoidType(fvsent3,0);
		SetAvoidType(fvarch1,0);
		SetAvoidType(fvarch2,0);

		SetSkill(tug1,2);
		SetSkill(fvserv1,2);
		SetSkill(fvtank1,2);
		SetSkill(fvtank2,2);
		SetSkill(fvtank3,2);
		SetSkill(fvsent1,2);
		SetSkill(fvsent2,2);
		SetSkill(fvsent3,2);
		SetSkill(fvarch1,2);
		SetSkill(fvarch2,2);

		SetAvoidType(evil1,0);
		SetAvoidType(evil2,0);
		SetAvoidType(evil3,0);
		SetAnimation(dropship1,"deploy",1);
		SetAnimation(dropship2,"deploy",1);

		spawn_circle_tank1time = (GetTime() + 1);
		spawn_circle_tank2time = (GetTime() + 1);
		spawn_circle_scout1time = (GetTime() + 1);
		spawn_circle_scout2time = (GetTime() + 1);

		SetIndependence(ambusher1,0);
		SetIndependence(ambusher2,0);
		SetIndependence(ambusher3,0);
		SetIndependence(ambusher4,0);
		SetIndependence(ambusher5,0);
		SetIndependence(ambusher6,0);

		SetAvoidType(ambusher1,0);
		SetAvoidType(ambusher2,0);
		SetAvoidType(ambusher3,0);
		SetAvoidType(ambusher4,0);
		SetAvoidType(ambusher5,0);
		SetAvoidType(ambusher6,0);

		missionstart = true;
	
	}
	
	if ((!vo1) && (vo1time < GetTime()))
	{
		msg1 = AudioMessage("scion0401.wav"); //  Ok Cook, we MUST get this power source to the data transfer machine.  We have been unable to locate any scrap veins in the area, so you will have to make due with the units we have available.  Good luck Cook, the fate of an entire race is in your hands. (SHAB)
		vo1 = true;
	}

	if ((!obj1) && (vo1) && (IsAudioMessageDone(msg1)))
	{
		ClearObjectives();
		AddObjective("scion0401.otf", WHITE);
		SetObjectiveOn(machine);
		TranslateString2(tempstr, sizeof(tempstr), "MissionS0401");  // Alchemator		
		SetObjectiveName(machine,tempstr);
		Goto(rtattack1,player);
		obj1 = true;
	}

	if ((!attack1) && (GetDistance(player,rtattack2) < 150))
	{
		Goto(rtattack2,player);
		Goto(rtattack3,player);
		attack1 = true;
	}

	// player first meets the evil scions
	if ((!playermeetevil) && (GetDistance(player,evil1) < 85))
	{
		msg2 = AudioMessage("scion0402.wav"); //Cook stop!  The way ahead is very dangerous, a massive ISDF blockade is intrenched in the canyon.  Follow us we know a safe way through the pass!
		LookAt(evil1,player);
		LookAt(evil2,player);
		LookAt(evil3,player);
		playermeetevil = true;
	}

	if ((!evilgo1) && (!playerattackedevil) && (!warn2) && (!warn2a)
		&& (playermeetevil) && (IsAudioMessageDone(msg2)))
	{
		Retreat(evil1,"evilpath");
		Follow(evil2,evil1);
		Follow(evil3,evil2);
		evilgo1 = true;
	}

	if ((!playernotcoming1) && (evilgo1) && (GetDistance(player,evil1) > 150))
	{
		Stop(evil1);
		Stop(evil2);		
		Stop(evil3);
		LookAt(evil1,player);
		LookAt(evil2,player);
		LookAt(evil3,player);
		warn1time = (GetTime() + 4);
		playernotcoming1 = true;
	}

	if ((!playercaughtup) && (playernotcoming1) && (!warn2) && (!warn2a) && (!playerattackedevil)
		&& (GetDistance(player,evil1) < 100))
	{
		Retreat(evil1,"evilpath");
		Follow(evil2,evil1);
		Follow(evil3,evil2);
		playercaughtup = true;
	}

	if ((!warn1) && (playernotcoming1) && (!ambushstart) && (!warn2) && (!warn3) && (!playerattackedevil)
		&& (!playercaughtup))
	{
		AudioMessage("scion0403.wav");//C'mon Cook, you coming with us or not?
		warn2time = (GetTime() + 50);
		warn1 = true;
	}

	if ((!warn2) && (!playercaughtup) && (!playerattackedevil) && (!warn3) && (warn2time < GetTime()))
	{
		AudioMessage("scion0405.wav"); //	Ok Cook, I was hoping we could do this the easy way but you are too stubborn!  Attack men!
		SetIndependence(evil1,1);
		SetIndependence(evil2,1);
		SetIndependence(evil3,1);

		Attack(evil1,player);
		Attack(evil2,player);
		Attack(evil3,player);
		warn2 = true;
	}

	if ((!warn2a) && (!playerattackedevil) && (!warn2) && (playercaughtup) && (GetDistance(evil1,"ambush") < 50))
	{

		Stop(evil1);
		Stop(evil2);
		Stop(evil3);
		LookAt(evil1,player);
		LookAt(evil2,player);
		LookAt(evil3,player);
		warn2a = true;
	}

	if ((!playeratambush) && (warn2a) && (GetDistance(player,"ambush") < 100))
	{
		playeratambush = true;
	}

	if ((!warn3) && (!playeratambush) && (!playerattackedevil) && (!warn2) && (GetDistance(player,"goodroute") < 150))
	{
		AudioMessage("scion0405.wav"); //	Ok Cook, I was hoping we could do this the easy way but you are too stubborn!  Attack men!
		RemoveObject(evil1); 
		RemoveObject(evil2);		
		RemoveObject(evil3);
		evil1 = BuildObject("fvscout",2,"evil1respawn");
		evil2 = BuildObject("fvscout",2,"evil2respawn");
		evil3 = BuildObject("fvscout",2,"evil3respawn");
		SetSkill(evil1,2);
		SetSkill(evil2,2);
		SetSkill(evil3,2);
		Attack(evil1,player); 
		Attack(evil2,player);
		Attack(evil3,player);
		warn3 = true;
	}
////////////////When player attacks first
	if ((!playerattackedevil) && (!warn2) && (!warn3) && (GetCurHealth(evil1) < 750) && (!ambushstart))  

	{
		if (!IsAudioMessageDone(msg2))
		{
			StopAudioMessage(msg2);
		}
		
		AudioMessage("scion0404.wav");//He's onto us! Attack!
		SetIndependence(evil1,1);
		SetIndependence(evil2,1);
		SetIndependence(evil3,1);
		Attack(evil1,player);
		Attack(evil2,player);
		Attack(evil3,player);
		playerattackedevil = true;
	}

	if ((!playerattackedevil) && (!warn2) && (!warn3) && (GetCurHealth(evil2) < 750) && (!ambushstart)) 

	{
		if (!IsAudioMessageDone(msg2))
		{
			StopAudioMessage(msg2);
		}
	
		AudioMessage("scion0404.wav");//He's onto us! Attack!
		SetIndependence(evil1,1);
		SetIndependence(evil2,1);
		SetIndependence(evil3,1);
		Attack(evil1,player);
		Attack(evil2,player);
		Attack(evil3,player);
		playerattackedevil = true;
	}

	if ((!playerattackedevil) && (!warn2) && (!warn3) && (GetCurHealth(evil3) < 750) && (!ambushstart))  

	{

		if (!IsAudioMessageDone(msg2))
		{
			StopAudioMessage(msg2);
		}
		
		AudioMessage("scion0404.wav");//He's onto us! Attack!
		SetIndependence(evil1,1);
		SetIndependence(evil2,1);
		SetIndependence(evil3,1);
		Attack(evil1,player);
		Attack(evil2,player);
		Attack(evil3,player);
		playerattackedevil = true;
	}
	//////////

	//seeing when the evils are destroyed
	if ((!all_evils_dead) && (playerattackedevil))
	{
		if ((!evil1dead) && (playerattackedevil) && (!ambushstart) && (!IsAlive(evil1)))
		{
			vo7time = (GetTime() + 3);
			evil1dead = true;
		}

		if ((!evil2dead) && (playerattackedevil) && (!ambushstart) && (!IsAlive(evil2)))
		{
			vo7time = (GetTime() + 3);
			evil2dead = true;
		}

		if ((!evil3dead) && (playerattackedevil) && (!ambushstart) && (!IsAlive(evil3)))
		{
			vo7time = (GetTime() + 3);
			evil3dead = true;
		}

		//taunts from evils as player fights them
	//	if ((!vo6) && (vo6time < GetTime()))
	//	{
	//		AudioMessage("scion0406.wav");	//You are powerless against us!
	//		vo6 = true;
	//	}

		if ((!vo7) && (vo7time < GetTime()))
		{
			AudioMessage("scion0407.wav");	//Tell burns we will never return with him to earth!
			vo7 = true;
		}

		//when all evils are dead...
		if ((evil1dead) && (evil2dead) && (evil3dead))
		{
			vo8time = (GetTime() + 3);
			all_evils_dead = true;
		}
	}

	if ((!vo8) && (all_evils_dead) && (vo8time < GetTime()))
	{
		AudioMessage("scion0408.wav"); //You did the right thing, John,  Those were the rebels!
		vo8 = true;
	}

	/// If player falls for the trap......the ambush
	if ((!ambushstart) && (GetDistance(player,"ambush") < 120))
	{

		SetIndependence(ambusher1,1);
		SetIndependence(ambusher2,1);
		SetIndependence(ambusher3,1);
		SetIndependence(ambusher4,1);
		SetIndependence(ambusher5,1);
		SetIndependence(ambusher6,1);

		Attack(ambusher1,tug1);
		Attack(ambusher2,player);
		Attack(ambusher3,tug1);
		Goto(ambusher4,player);
		Attack(ambusher5,fvserv1);
		Goto(ambusher6,player);
		
		if (IsAlive(evil1))
		{
			SetIndependence(evil1,1);
			Attack(evil1,player);
		}

		if (IsAlive(evil2))
		{
			SetIndependence(evil2,1);
			Attack(evil2,player);		
		}

		if (IsAlive(evil3))
		{
			SetIndependence(evil3,1);
			Attack(evil3,player);
		}


		vo12time = (GetTime() + 2);
		ambushstart = true;
	}

	if ((!vo12) && (ambushstart) && (!warn2) && (!warn3) && (!playerattackedevil) && (vo12time < GetTime()))
	{
		AudioMessage("scion0412.wav");	//John, you fell right into a trap...those were the rebels!
		vo12 = true;
	}

	//attackers along way
	if ((!tankscharge1) && (GetDistance(player,tank1) < 200))
	{
		Goto(tank1,player);
		Goto(tank2,player);
		tankscharge1 = true;
	}

	if ((!tankscharge2) && (GetDistance(player,tank3) < 200))
	{
		Goto(tank3,player);
		Goto(tank4,player);
		tankscharge2 = true;
	}

//**CINERACTIVE** when Cooke and the tug make it to the machine

//seeing when TUG is at the machine

/*	if ((!player_at_machine) && (GetDistance(player,machine) < 250))
	{
		start_bigspawn = true;
		player_at_machine = true;
	}
*/
	if ((!tug_at_machine) && (IsAround(tug1) && (GetDistance(tug1,machine) < 200)))
	{
		start_bigspawn = true;
		tug_at_machine = true;
	}

	if ((!bigspawn_cin_over) && (start_bigspawn))
	{
		if (!bigspawnstart)
		{
			Retreat(tug1,"tug_die_here");
			stealer1_7time = (GetTime() + 0);
			stealer2_8time = (GetTime() + 1.5f);
			stealer3_9time = (GetTime() + 3.0f);
			stealer4_10time = (GetTime() + 4.5f);
			stealer5_11time = (GetTime() + 6.0f);
			stealer6_12time = (GetTime() + 7.5f);
			bigspawn_shot1_starttime = (GetTime() + 1);

			//removing circle spawners so they don't interfere after the CIN starts
			if (IsAlive(circle_tank1))
			{
				RemoveObject(circle_tank1);
			}

			if (IsAlive(circle_tank2))
			{
				RemoveObject(circle_tank2);
			}

			if (IsAlive(circle_scout1))
			{
				RemoveObject(circle_scout1);
			}

			if (IsAlive(circle_scout2))
			{
				RemoveObject(circle_scout2);
			}

			//turning off players units AI so they don't try to fight the guys who kill his tug
			if (IsAlive(fvsent1))
			{
				SetIndependence(fvsent1,0);
				Goto(fvsent1,"fvsent1");//getting them out of the way for the cineractive
			}

			if (IsAlive(fvsent2))
			{
				SetIndependence(fvsent2,0);
				Goto(fvsent2,"fvsent2");
			}

			if (IsAlive(fvsent3))
			{
				SetIndependence(fvsent3,0);
				Goto(fvsent3,"fvsent3");
			}

			if (IsAlive(fvtank1))
			{
				SetIndependence(fvtank1,0);
				Goto(fvtank1,"fvtank1");
			}

			if (IsAlive(fvtank2))
			{
				SetIndependence(fvtank2,0);
				Goto(fvtank2,"fvtank2");
			}

			if (IsAlive(fvtank3))
			{
				SetIndependence(fvtank3,0);
				Goto(fvtank3,"fvtank3");
			}

			if (IsAlive(fvserv1))
			{
				SetIndependence(fvserv1,0);
				Goto(fvserv1,"fvserv1");
			}

			if (IsAlive(fvarch1))
			{
				SetIndependence(fvarch1,0);
				Goto(fvarch1,"fvarch1");
			}

			if (IsAlive(fvarch2))
			{
				SetIndependence(fvarch2,0);
				Goto(fvarch2,"fvarch2");
			}
				circle_spawns_over = true;
				bigspawnstart = true;
		}

		//CAM CONTROLS********
		//FIRST SHOT -- Rebels coming out of canyon1
		if ((!bigspawn_shot1) && (bigspawn_shot1_starttime < GetTime()))
		{
			if (!rdycam1)
			{
				CameraReady();
				bigspawn_shot1_overtime = (GetTime() + 7);
				rdycam1 = true;
			}

			CameraPath("bigspawn_campath1",1000,0,bigspawn_cam1look);

			if ((bigspawn_shot1_overtime) < GetTime())
			{
				bigspawn_shot1 = true;

			}
		}

		//SECOND SHOT -- rebels coming out of canyon 2
		if ((!bigspawn_shot2) && (bigspawn_shot1))
		{
			if (!rdycam2)
			{
				CameraReady();
				bigspawn_shot2_overtime = (GetTime() + 5);
				rdycam2 = true;
			}

			CameraPath("bigspawn_campath2",1000,0,bigspawn_cam2look);

			if ((bigspawn_shot2_overtime) < GetTime())
			{
				bigspawn_shot2 = true;
			}
		}

		//THIRD SHOT -- Pan shot of area
		if ((!bigspawn_shot3) && (bigspawn_shot2))
		{
			if (!rdycam3)
			{
				CameraReady();
				bigspawn_shot3_overtime = (GetTime() + 15);
				rdycam3 = true;
			}

			CameraPath("bigspawn_campath3",3000,1200,bigspawn_camlook3);

			if ((bigspawn_shot3_overtime) < GetTime())
			{
				bigspawn_shot3 = true;
			}
		}

		//FOURTH SHOT -- Shot of Bossman coming down the ramp in his walker
		if ((!bigspawn_shot4) && (bigspawn_shot3))
		{
			if (!rdycam4)
			{
				CameraReady();
				bigspawn_shot4_overtime = (GetTime() + 10);
				rdycam4 = true;
			}

			CameraPath("bigspawn_campath4",3000,100,bigspawn_cam4look);

			if ((bigspawn_shot4_overtime) < GetTime())
			{
				bigspawn_shot4 = true;
			}
		}

		//FIFTH SHOT -- Shot of bossman talking 1
		if ((!bigspawn_shot5) && (bigspawn_shot4))
		{
			if (!rdycam5)
			{
				CameraReady();
				cutvo1time = (GetTime() + 2);
				bigspawn_shot5_overtime = (GetTime() + 7);
				rdycam5 = true;
			}

			if ((!cutvo1) && (cutvo1time < GetTime()))
			{
				AudioMessage("cutsc0401.wav"); //So...you thought it would be that easy?  I think not
				cutvo1 = true;
			}

			CameraObject(bossman,0,-5,20,bossman);

			if ((bigspawn_shot5_overtime) < GetTime())
			{
				bigspawn_shot5 = true;
			}
		}
		
		//SIXTH SHOT -- Shot of hauler getting killed
		if ((!bigspawn_shot6) && (bigspawn_shot5))
		{
			if (!rdycam6)
			{
				CameraReady();
				SetMaxHealth(tug1,775);
				SetCurHealth(tug1,775);
				SetIndependence(stealer9,1);
				SetIndependence(stealer10,1);
				SetIndependence(stealer11,1);
				SetIndependence(stealer12,1);
				attack_tugtime = (GetTime() + 0.5f);
				rdycam6 = true;
			}
			//telling a couple rebels to kill tug
			if ((!attack_tug) && (attack_tugtime < GetTime()))
			{
				Attack(stealer9,tug1);	
				Attack(stealer10,tug1);				
				Attack(stealer11,tug1);
				Attack(stealer12,tug1);
				attack_tug = true;
			}
			//checking when tug is killed
			if ((!check_tug_dead) && (!IsAround(tug1)))
			{
				SetIndependence(stealer9,0);
				SetIndependence(stealer10,0);				
				SetIndependence(stealer11,0);
				SetIndependence(stealer12,0);
				bigspawn_shot6_overtime = (GetTime() + 7.5f);
				cutvo3time = (GetTime() + 4);
				check_tug_dead = true;
			}

			if ((!cutvo3) && (cutvo3time < GetTime()))
			{
				AudioMessage("cutsc0403.wav");  //burns/shab  "why do you betray us?"
				cutvo3 = true;
			}

			//making killers go back into position after tug is killed
			if ((!stealer11_12_goback) && (check_tug_dead))
			{
				Retreat(stealer9,"stealer9");
				Retreat(stealer10,"stealer10");				
				Retreat(stealer11,"stealer11");
				Retreat(stealer12,"stealer12");
				stealer11_12_goback = true;
			}

			//making killers relook after going back
			if ((!stealer9_relook) && (stealer11_12_goback) && 
				(GetDistance(stealer9,"stealer9") < 8))
			{
				LookAt(stealer9,ailook);
				stealer9_relook = true;
			}

			if ((!stealer10_relook) && (stealer11_12_goback) && 
				(GetDistance(stealer10,"stealer10") < 8))
			{
				LookAt(stealer10,ailook);
				stealer10_relook = true;
			}
			
			if ((!stealer11_relook) && (stealer11_12_goback) && 
				(GetDistance(stealer11,"stealer11") < 8))
			{
				LookAt(stealer11,ailook);
				stealer11_relook = true;
			}

			if ((!stealer12_relook) && (stealer11_12_goback) && 
				(GetDistance(stealer12,"stealer12") < 8))
			{
				LookAt(stealer12,ailook);
				stealer12_relook = true;
			}

			CameraPath("tugshot_campath1",3000,0,tugshot_look1);

			if ((bigspawn_shot6_overtime) < GetTime())
			{
				bigspawn_shot6 = true;
			}
		}

		//SEVENTH SHOT -- Bossman saying how he hates earth and humans
		if ((!bigspawn_shot7) && (bigspawn_shot6))
		{
			if (!rdycam7)
			{
				CameraReady();
				cutvo4time = (GetTime() + 0.5f);
				rdycam7 = true;
			}

			if ((!cutvo4) && (cutvo4time < GetTime()))
			{
				cutmsg4 = AudioMessage("cutsc0404.wav");//Our home is here, and if our core planet dies, we die with it.  we will not return to earth to live among humans
				cutvo4 = true;
			}

			if ((!cutvo4over) && (cutvo4) && (IsAudioMessageDone(cutmsg4)))
			{
				cutvo5time = (GetTime() + 1);
				cutvo4over = true;
			}

			if ((!cutvo5) && (cutvo5time < GetTime()))
			{
				cutmsg5 = AudioMessage("cutsc0405.wav"); //SHAB/BURNS "Were WE not once human?"
				cutvo5 = true;
			}

			if ((!cutvo5over) && (cutvo5) && (IsAudioMessageDone(cutmsg5)))
			{
				cutvo6time = (GetTime() + 0.5f);
				cutvo5over = true;
			}

			if ((!cutvo6) && (cutvo6time < GetTime()))
			{
				cutmsg6 = AudioMessage("cutsc0406.wav");//Scion pilot "You perhaps, but I am scion through and through!  Enough talking, destroy all of them!		
				cutvo6 = true;
			}

			if ((!cutvo6over) && (cutvo6) && (IsAudioMessageDone(cutmsg6)))
			{
				bigspawn_shot7_overtime = (GetTime() + 0.25f);
				cutvo6over = true;
			}

			CameraPath("shot7_path1",500,120,bossman);


		}
	


		// THE "ACTORS"
		if ((!spawn1_7) && (stealer1_7time < GetTime()))
		{
			stealer1 = BuildObject("fvtkscn4",2,"bigspawn1");
			stealer7 = BuildObject("fvtkscn4",2,"bigspawn2");
			Retreat(stealer1,"stealer1");
			Retreat(stealer7,"stealer7");
			SetAvoidType(stealer1,0);
			SetAvoidType(stealer7,0);
			SetMaxHealth(stealer1,6000);
			SetCurHealth(stealer1,6000);
			SetMaxHealth(stealer7,6000);
			SetCurHealth(stealer7,6000);

		//	SetIndependence(stealer1,0);
		//	SetIndependence(stealer2,0);

			spawn1_7 = true;
		}

		if ((!spawn2_8) && (stealer2_8time < GetTime()))
		{
			stealer2 = BuildObject("fvtkscn4",2,"bigspawn1");
			Retreat(stealer2,"stealer2");
			stealer8 = BuildObject("fvtkscn4",2,"bigspawn2");
			Retreat(stealer8,"stealer8");
			SetAvoidType(stealer2,0);
			SetAvoidType(stealer8,0);
			SetMaxHealth(stealer2,6000);
			SetCurHealth(stealer2,6000);
			SetMaxHealth(stealer8,6000);
			SetCurHealth(stealer8,6000);

			SetIndependence(stealer2,0);
			SetIndependence(stealer8,0);

			spawn2_8 = true;
		}

		if ((!spawn3_9) && (stealer3_9time < GetTime()))
		{
			stealer3 = BuildObject("fvtkscn4",2,"bigspawn1");
			Retreat(stealer3,"stealer3");
			stealer9 = BuildObject("fvtkscn4",2,"bigspawn2");
			Retreat(stealer9,"stealer9");
			SetAvoidType(stealer3,0);
			SetAvoidType(stealer9,0);
			SetMaxHealth(stealer3,6000);
			SetCurHealth(stealer3,6000);
			SetMaxHealth(stealer9,6000);
			SetCurHealth(stealer9,6000);

			SetIndependence(stealer3,0);
			SetIndependence(stealer9,0);

			spawn3_9 = true;
		}

		if ((!spawn4_10) && (stealer4_10time < GetTime()))
		{
			stealer4 = BuildObject("fvtkscn4",2,"bigspawn1");
			Retreat(stealer4,"stealer4");
			stealer10 = BuildObject("fvtkscn4",2,"bigspawn2");
			Retreat(stealer10,"stealer10");
			SetAvoidType(stealer4,0);
			SetAvoidType(stealer10,0);
			SetMaxHealth(stealer4,6000);
			SetCurHealth(stealer4,6000);
			SetMaxHealth(stealer10,6000);
			SetCurHealth(stealer10,6000);

			SetIndependence(stealer4,0);
			SetIndependence(stealer10,0);

			spawn4_10 = true;
		}

		if ((!spawn5_11) && (stealer5_11time < GetTime()))
		{
			stealer5 = BuildObject("fvtkscn4",2,"bigspawn1");
			Retreat(stealer5,"stealer5");
			stealer11 = BuildObject("fvtkscn4",2,"bigspawn2");
			Retreat(stealer11,"stealer11");
			SetAvoidType(stealer5,0);
			SetAvoidType(stealer11,0);
			SetMaxHealth(stealer5,6000);
			SetCurHealth(stealer5,6000);
			SetMaxHealth(stealer1,6000);
			SetCurHealth(stealer1,6000);

			SetIndependence(stealer5,0);
			SetIndependence(stealer11,0);

			spawn5_11 = true;
		}

		if ((!spawn6_12) && (stealer6_12time < GetTime()))
		{
			stealer6 = BuildObject("fvtkscn4",2,"bigspawn1");
			Retreat(stealer6,"stealer6");
			stealer12 = BuildObject("fvtkscn4",2,"bigspawn2");
			Retreat(stealer12,"stealer12");
			SetAvoidType(stealer6,0);
			SetAvoidType(stealer12,0);
			walk_spawntime = (GetTime() + 5);
			SetMaxHealth(stealer6,6000);
			SetCurHealth(stealer6,6000);
			SetMaxHealth(stealer12,6000);
			SetCurHealth(stealer12,6000);

			SetIndependence(stealer6,0);
			SetIndependence(stealer12,0);

			spawn6_12 = true;
		}

		///CONTROLLING WALKERS
		if ((!walk_spawn) && (walk_spawntime < GetTime()))
		{
			stealer_walk1 = BuildObject("fvwalk",2,"stealer_walk1");	
			stealer_walk2 = BuildObject("fvwalk",2,"stealer_walk2");
			bossman = BuildObject("fvwalk",2,"bossman_spawn");
			Retreat(stealer_walk1,"walk1_path");
			Retreat(stealer_walk2,"walk2_path");
			bossman_gotime = (GetTime() + 15);

			SetIndependence(stealer_walk1,0);
			SetIndependence(stealer_walk2,0);
			SetIndependence(bossman,0);

			walk_spawn = true;
		}

		if ((!walk1_stop) && (GetDistance(stealer_walk1,"walk1_path_end") < 15))
		{
			LookAt(stealer_walk1,ailook);
			walk1_stop = true;
		}

		if ((!walk2_stop) && (GetDistance(stealer_walk2,"walk2_path_end") < 15))
		{
			LookAt(stealer_walk2,ailook);
			walk2_stop = true;
		}

		if ((!bossman_go) && (walk_spawn) && (bossman_gotime < GetTime()))
		{
			Retreat(bossman,"bossman");
			bossman_go = true;
		}

		if ((!bossman_stop) && (walk_spawn) && (GetDistance(bossman,"bossman") < 5))
		{
			Stop(bossman);
			LookAt(bossman,ailook);
			bossman_stop = true;
		}
		////////
		
		//stopping vehicles when they get near thier destination
		if ((!stop1) && (spawn1_7) && (GetDistance(stealer1,"stealer1") < 5))
		{
			LookAt(stealer1,ailook);
			stop1 = true;
		}

		if ((!stop2) && (spawn2_8) && (GetDistance(stealer2,"stealer2") < 5))
		{
			LookAt(stealer2,ailook);
			stop2 = true;
		}

		if ((!stop3) && (spawn3_9) && (GetDistance(stealer3,"stealer3") < 5))
		{
			LookAt(stealer3,ailook);
			stop3 = true;
		}
		if ((!stop4) && (spawn4_10) && (GetDistance(stealer4,"stealer4") < 5))
		{
			LookAt(stealer4,ailook);
			stop4 = true;
		}

		if ((!stop5) && (spawn5_11) && (GetDistance(stealer5,"stealer5") < 5))
		{
			LookAt(stealer5,ailook);
			stop5 = true;
		}

		if ((!stop6) && (spawn6_12) && (GetDistance(stealer6,"stealer6") < 5))
		{
			LookAt(stealer6,ailook);
			stop6 = true;
		}

		if ((!stop7) && (spawn1_7) && (GetDistance(stealer7,"stealer7") < 5))
		{
			LookAt(stealer7,ailook);
			stop7 = true;
		}

		if ((!stop8) && (spawn2_8) && (GetDistance(stealer8,"stealer8") < 5))
		{
			LookAt(stealer8,ailook);
			stop8 = true;
		}

		if ((!stop9) && (spawn3_9) && (GetDistance(stealer9,"stealer9") < 5))
		{
			LookAt(stealer9,ailook);
			stop9 = true;
		}

		if ((!stop10) && (spawn4_10) && (GetDistance(stealer10,"stealer10") < 5))
		{
			LookAt(stealer10,ailook);
			stop10 = true;
		}

		if ((!stop11) && (spawn5_11) && (GetDistance(stealer11,"stealer11") < 5))
		{
			LookAt(stealer11,ailook);
			stop11 = true;
		}
		if ((!stop12) && (spawn6_12) && (GetDistance(stealer12,"stealer12") < 5))
		{
			LookAt(stealer12,ailook);
			stop12 = true;
		}

		//this stops the tug when it gets to the machine and makes it look towards the machine
		if ((!tug1_stop) && (bigspawnstart))
		{
			if (GetDistance(tug1,"tug_die_here") < 10)
			{
				Stop(tug1);
				LookAt(tug1,machine);
				tug1_stop = true;
			}
		}
		//checking when last VO has played, ENDS THE CIN
		if ((bigspawn_shot7_overtime) < GetTime())
		{
			bigspawn_shot7 = true;
			stealers_attacktime = (GetTime() + 1);
			CameraFinish();

			//giving player his units back
			if (IsAlive(fvsent1))
			{

				SetIndependence(fvsent1,1);
				Stop(fvsent1,0);
			}

			if (IsAlive(fvsent2))
			{

				SetIndependence(fvsent2,1);
				Stop(fvsent2,0);
			}

			if (IsAlive(fvsent3))
			{

				SetIndependence(fvsent3,1);
				Stop(fvsent3,0);
			}

			if (IsAlive(fvtank1))
			{

				SetIndependence(fvtank1,1);
				Stop(fvtank1,0);
			}

			if (IsAlive(fvtank2))
			{

				SetIndependence(fvtank2,1);
				Stop(fvtank2,0);
			}

			if (IsAlive(fvtank3))
			{

				SetIndependence(fvtank3,1);
				Stop(fvtank3,0);
			}

			if (IsAlive(fvserv1))
			{

				SetIndependence(fvserv1,1);
				Stop(fvserv1,0);
			}

			if (IsAlive(fvarch1))
			{

				SetIndependence(fvarch1,1);
				Stop(fvarch1,0);
			}

			if (IsAlive(fvarch2))
			{

				SetIndependence(fvarch2,1);
				Stop(fvarch2,0);
			}

			bigspawn_cin_over = true;
		}
	}
	//**BIGSPAWN CINERACTIVE OVER**//

	//after bigspawn, player must escape from the rebel scions and make it to
	//his dropship...

	if ((!rebels_attack) && (stealers_attacktime < GetTime()))
	{
		AudioMessage("scion0410.wav"); //John, get out of there!  Make it to the dropship!


		SetIndependence(stealer1,1);
		SetIndependence(stealer2,1);
		SetIndependence(stealer3,1);
		SetIndependence(stealer4,1);
		SetIndependence(stealer5,1);
		SetIndependence(stealer6,1);
		SetIndependence(stealer7,0);
		SetIndependence(stealer8,0);
		SetIndependence(stealer9,0);
		SetIndependence(stealer10,0);
		SetIndependence(stealer11,0);
		SetIndependence(stealer12,0);
		release_otherstime = (GetTime() + 15);
	//	SetIndependence(bossman,1);
	//	SetIndependence(stealer_walk1,1);
	//	SetIndependence(stealer_walk2,1);

		//giving the attackers a target other than player, so player has a chance to get away
		if (!picktarget)
		{
			if ((IsAround(fvtank1) && (GetDistance(fvtank1,machine) < 600)))
			{
				Attack(stealer1,fvtank1);
				Attack(stealer2,fvtank1);
				Attack(stealer3,fvtank1);
				Attack(stealer4,fvtank1);
				Attack(stealer5,fvtank1);
				Attack(stealer6,fvtank1);
				picktarget = true;
			}
		
			if ((!picktarget) && (IsAround(fvtank2) && (GetDistance(fvtank2,machine) < 600)))
			{
				Attack(stealer1,fvtank2);
				Attack(stealer2,fvtank2);
				Attack(stealer3,fvtank2);
				Attack(stealer4,fvtank2);
				Attack(stealer5,fvtank2);
				Attack(stealer6,fvtank2);
				picktarget = true;
			}		

			if ((!picktarget) && (IsAround(fvtank3) && (GetDistance(fvtank3,machine) < 600)))
			{
				Attack(stealer1,fvtank3);
				Attack(stealer2,fvtank3);
				Attack(stealer3,fvtank3);
				Attack(stealer4,fvtank3);
				Attack(stealer5,fvtank3);
				Attack(stealer6,fvtank3);
				picktarget = true;
			}		

			if ((!picktarget) && (IsAround(fvsent1) && (GetDistance(fvsent1,machine) < 600)))
			{
				Attack(stealer1,fvsent1);
				Attack(stealer2,fvsent1);
				Attack(stealer3,fvsent1);
				Attack(stealer4,fvsent1);
				Attack(stealer5,fvsent1);
				Attack(stealer6,fvsent1);
				picktarget = true;
			}		
		
			if ((!picktarget) && (IsAround(fvsent2) && (GetDistance(fvsent2,machine) < 600)))
			{
				Attack(stealer1,fvsent2);
				Attack(stealer2,fvsent2);
				Attack(stealer3,fvsent2);
				Attack(stealer4,fvsent2);
				Attack(stealer5,fvsent2);
				Attack(stealer6,fvsent2);
				picktarget = true;
			}		
		
			if ((!picktarget) && (IsAround(fvsent3) && (GetDistance(fvsent3,machine) < 600)))
			{
				Attack(stealer1,fvsent3);
				Attack(stealer2,fvsent3);
				Attack(stealer3,fvsent3);
				Attack(stealer4,fvsent3);
				Attack(stealer5,fvsent3);
				Attack(stealer6,fvsent3);
				picktarget = true;
			}		
		}

		ClearObjectives();
		AddObjective("scion0406.otf", WHITE);
		SetObjectiveOff(machine);
		SetObjectiveOn(dropship1);
		TranslateString2(tempstr, sizeof(tempstr), "Mission1702");  // Dropship
		SetObjectiveName(dropship1,tempstr);
		rebels_attack = true;
	}
		//sending 6 of them after player
	if ((rebels_attack) && (!release_others) && (release_otherstime < GetTime()))
	{
		SetIndependence(stealer7,1);
		SetIndependence(stealer8,1);
		SetIndependence(stealer9,1);
		SetIndependence(stealer10,1);
		SetIndependence(stealer11,1);
		SetIndependence(stealer12,1);
		Attack(stealer7,player);
		Attack(stealer8,player);
		Attack(stealer9,player);
		Attack(stealer10,player);
		Attack(stealer11,player);
		Attack(stealer12,player);
		sick_first6_on_playertime = (GetTime() + 10);
		release_others = true;
	}
	//10 sec later, send the rest after player...
	if ((!sick_first6_on_player) && (sick_first6_on_playertime < GetTime()))
	{
		Attack(stealer1,player);
		Attack(stealer2,player);
		Attack(stealer3,player);
		Attack(stealer4,player);
		Attack(stealer5,player);
		Attack(stealer6,player);
		SetIndependence(stealer_walk1,1);
		SetIndependence(stealer_walk2,1);
		SetIndependence(bossman,1);
		Attack(stealer_walk1,player);
		Attack(stealer_walk2,player);
		Attack(bossman,player);
		sick_first6_on_player = true;
	}


	if ((rebels_attack) && (!player_at_dropship1) && (GetDistance(player,"dropship1") < 15))
	{


		//removing enemies so they donb't kill player during cineractive
		if (IsAlive(stealer1))
		{
			RemoveObject(stealer1);
		}

		if (IsAlive(stealer2))
		{
			RemoveObject(stealer2);
		}

		if (IsAlive(stealer3))
		{
			RemoveObject(stealer3);
		}

		if (IsAlive(stealer4))
		{
			RemoveObject(stealer4);
		}

		if (IsAlive(stealer5))
		{
			RemoveObject(stealer5);
		}

		if (IsAlive(stealer6))
		{
			RemoveObject(stealer6);
		}

		if (IsAlive(stealer7))
		{
			RemoveObject(stealer7);
		}

		if (IsAlive(stealer8))
		{
			RemoveObject(stealer8);
		}

		if (IsAlive(stealer9))
		{
			RemoveObject(stealer9);
		}

		if (IsAlive(stealer10))
		{
			RemoveObject(stealer10);
		}

		if (IsAlive(stealer11))
		{
			RemoveObject(stealer11);
		}

		if (IsAlive(stealer12))
		{
			RemoveObject(stealer12);
		}
		
		//telling players wingmen to stop so they don't try to follow him into the dropship (this makes framerate go to hell)
		if (IsAlive(fvsent1))
		{
			Stop(fvsent1);
		}

		if (IsAlive(fvsent2))
		{
			Stop(fvsent2);
		}

		if (IsAlive(fvsent3))
		{
			Stop(fvsent3);
		}

		if (IsAlive(fvtank1))
		{
			Stop(fvtank1);
		}

		if (IsAlive(fvtank2))
		{
			Stop(fvtank2);
		}

		if (IsAlive(fvtank3))
		{
			Stop(fvtank3);
		}

		if (IsAlive(tug1))
		{
			Stop(tug1);
		}

		if (IsAlive(fvserv1))
		{
			Stop(fvserv1);
		}

		if (IsAlive(fvarch1))
		{
			Stop(fvarch1);
		}

		if (IsAlive(fvarch2))
		{
			Stop(fvarch2);
		}

		player_at_dropship1 = true;
	}

	//CINERACTIVE of dropship taking off
	if ((!takeoff_shot1) && (player_at_dropship1))
	{
		if (!takeoff_rdycam1)
		{
			CameraReady();
			faker1 = BuildObject("fvtank",3,"faker1");
			faker2 = BuildObject("fvtank",3,"faker2");
			faker3 = BuildObject("fvtank",3,"faker3");
			faker4 = BuildObject("fvtank",3,"faker4");
			Attack(faker1,dropship2);
			Attack(faker2,dropship2);
			Attack(faker3,dropship2);
			Attack(faker4,dropship2);
			takeoff_time = (GetTime() + 8);
			takeoff_rdycam1 = true;
		}

		CameraPath("takeoff_campath1",1000,0,dropship2);

		if ((!takeoff) && (takeoff_time < GetTime()))
		{
			SetAnimation(dropship2,"takeoff",1);
			fakers_stop_attacktime = (GetTime() + 3);
			take_off_soundtime = (GetTime() + 4);
			takeoff = true;
		}

		//play dropship taking off sound
		if ((!take_off_sound) && (take_off_soundtime < GetTime()))
		{
			AudioMessage("droptoff.wav");
			take_off_sound = true;
		}

		if ((!fakers_stop_attack) && (fakers_stop_attacktime < GetTime()))
		{
			SetIndependence(faker1,0);
			SetIndependence(faker2,0);
			SetIndependence(faker3,0);
			SetIndependence(faker4,0);
			Stop(faker1);
			Stop(faker2);
			Stop(faker3);
			Stop(faker4);	
			Patrol(faker1,"faker_path");
			Patrol(faker2,"faker_path");
			Patrol(faker3,"faker_path");
			Patrol(faker4,"faker_path");
			SucceedMission(GetTime() + 10,"scion04w1.txt");
			fakers_stop_attack = true;
		}
	}

	//This controls the circlers around the lava ocean
	if (!circle_spawns_over)
	{
		//circle_tank1
		if ((!spawn_circle_tank1) && (spawn_circle_tank1time < GetTime()))
		{
			circle_tank1 = BuildObject("ivtank",4,"circle4");
			SetSkill(circle_tank1,2);
			Patrol(circle_tank1,"scoutpath2");
			circle_tank1_dead = false;
			spawn_circle_tank1 = true;
		}

		if ((!circle_tank1_dead) && (spawn_circle_tank1) && (!IsAlive(circle_tank1)))
		{
			spawn_circle_tank1time = (GetTime() + 200);
			circle_tank1_attack = false;
			spawn_circle_tank1 = false;
			circle_tank1_dead = true;
		}

		//circle_tank2
		if ((!spawn_circle_tank2) && (spawn_circle_tank2time < GetTime()))
		{
			circle_tank2 = BuildObject("ivtank",4,"circle2");
			SetSkill(circle_tank2,2);
			Patrol(circle_tank2,"scoutpath2");
			circle_tank2_dead = false;
			spawn_circle_tank2 = true;
		}

		if ((!circle_tank2_dead) && (spawn_circle_tank2) && (!IsAlive(circle_tank2)))
		{
			spawn_circle_tank2time = (GetTime() + 200);
			spawn_circle_tank2 = false;
			circle_tank2_dead = true;
		}

		//circle_scout1
		if ((!spawn_circle_scout1) && (spawn_circle_scout1time < GetTime()))
		{
			circle_scout1 = BuildObject("ivscout",4,"circle1");
			SetSkill(circle_scout1,2);
			Patrol(circle_scout1,"scoutpath");
			circle_scout1_dead = false;
			spawn_circle_scout1 = true;
		}

		if ((!circle_scout1_dead) && (spawn_circle_scout1) && (!IsAlive(circle_scout1)))
		{
			spawn_circle_scout1time = (GetTime() + 200);
			circle_scout1_attack = false;
			spawn_circle_scout1 = false;
			circle_scout1_dead = true;
		}

		//circle_scout2
		if ((!spawn_circle_scout2) && (spawn_circle_scout2time < GetTime()))
		{
			circle_scout2 = BuildObject("ivscout",4,"circle3");
			SetSkill(circle_scout2,2);
			Patrol(circle_scout2,"scoutpath");
			circle_scout2_dead = false;
			spawn_circle_scout2 = true;
		}

		if ((!circle_scout2_dead) && (spawn_circle_scout2) && (!IsAlive(circle_scout2)))
		{
			spawn_circle_scout2time = (GetTime() + 200);
			circle_scout2_attack = false;
			spawn_circle_scout2 = false;
			circle_scout2_dead = true;
		}

		//This will make the 1 circle tank and 1 circle scout attack the players service truck when they
		//get near it
		if ((!circle_tank1_attack) && (IsAlive(circle_tank1) && (IsAlive(fvserv1)
		&& (GetDistance(circle_tank1,fvserv1) < 200))))
		{
			Attack(circle_tank1,fvserv1);
			circle_tank1_attack = true;
		}

		if ((!circle_scout1_attack) && (IsAlive(circle_scout1) && (IsAlive(fvserv1)
		&& (GetDistance(circle_scout1,fvserv1) < 200))))
		{
			Attack(circle_scout1,fvserv1);
			circle_scout1_attack = true;
		}

		//This will make the 2 circle tank and 2 circle scout attack the tug
	
		if ((!circle_tank2_attack) && (IsAlive(circle_tank2) && (IsAlive(tug1)
		&& (GetDistance(circle_tank2,tug1) < 200))))
		{
			Attack(circle_tank2,tug1);
			circle_tank2_attack = true;
		}

		if ((!circle_scout2_attack) && (IsAlive(circle_scout2) && (IsAlive(tug1)
		&& (GetDistance(circle_scout2,tug1) < 200))))
		{
			Attack(circle_scout2,tug1);
			circle_scout2_attack = true;
		}
	}
	////////

	//mission lost if power source ever destroyed
	if ((!IsAround(power) && (!start_bigspawn)))
	{
		if ((!powerdead) && (!haulerdead))
		{
			vo9time = (GetTime() + 2);
			powerdead = true;
		}

		if ((!missionlost) && (vo9time < GetTime()))
		{
			msg9 = AudioMessage("scion0409.wav"); // the powersource has been destroyed!
			missionlost = true;
		}

		if ((!obj3) && (missionlost) && (IsAudioMessageDone(msg9)))
		{
			ClearObjectives();
			AddObjective("scion0403.otf", WHITE);
			FailMission(GetTime() + 10,"scion04L1.txt");	
			obj3 = true;
		}
	}

	//mission lost if Hauler gets destroyed
	if (!IsAround(tug1) && (!start_bigspawn))
	{
		if ((!haulerdead) && (!powerdead))
		{
			vo10time = (GetTime() + 2);
			haulerdead = true;
		}

		if ((!missionlost2) && (vo10time < GetTime()))
		{
			msg10=AudioMessage("scion0415.wav"); //Dammit the Hauler has been destroyed!
			missionlost2 = true;		
		}

		if ((!obj4) && (missionlost2) && (IsAudioMessageDone(msg10)))
		{
			ClearObjectives();
			AddObjective("scion0404.otf", WHITE);
			FailMission(GetTime() + 10,"scion04L2.txt");
			obj4=true;
		}
	}
}

