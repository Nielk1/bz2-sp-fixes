#include "..\Shared\SPMission.h"

class isdf17Mission : public SPMission 
{
public:
	isdf17Mission(void)
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
		missionstart,
		playeratcore,obj3,obj1,obj2,obj4,
		playeratdropship,vo1,vo2,vo3,vo4,
		shielda_down,shieldb_down,shieldc_down,shieldd_down,shielde_down,shieldf_down,
		temp,
		collapse_1,collapse_2,collapse_3,
		collapse_1a,collapse_2a,collapse_3a,
		reset_quake1,reset_quake2,reset_quake3,
		planet_go_boom,kill_player_more,
		dropper1_drop,dropper1b_drop,dropper2_drop,dropper2b_drop,dropper3_drop,dropper4_drop,
		dropper5_drop,dropper6_drop,dropper7_drop,dropper8_drop,dropper9_drop,
		noz1_killed,noz2_killed,noz3_killed,noz4_killed,
		all_noz_killed,two_noz_killed,spawners_over,set_spawner_times,
		anim_side,anim_spinside,anim_fall,anim_spin,
		remove_big_daddy,
		swap_turret1,swap_turret2,swap_turret3,
		dropper10_drop,dropper11_drop,
		vo_robot,
		b_last;

	// floats
	float
		f_first,
		obj3time,
		vo1time,vo2time,vo3time,
		power_down_soundtime,
		collapse_soundtime,
		reset_quake1time,reset_quake2time,reset_quake3time,
		planet_go_boomtime,kill_player_moretime,

		spawner1time,spawner2time,spawner3time,spawner4time,spawner5time,spawner234time,
		anim_spinsidetime,remove_big_daddytime,
		
		f_last;


	// handles
	Handle
		h_first,
		core,
		player,
		dropship,msg1,msg2,msg3,
		shielda,shieldb,shieldc,shieldd,shielde,shieldf,
		triggera,triggerb,triggerc,triggerd,triggere,triggerf,
		holdera,holderb,holderc,holderd,holdere,holderf,holderg,
		collapsea,collapseb,collapsec,
		collapsea1,collapseb1,collapsec1,
		turret1,turret2,turret3,
		dropper1,dropper1b,dropper2,dropper2b,dropper3,dropper4,dropper5,
		dropper6,dropper7,dropper8,dropper9,dropper10,dropper11,
		health1,
		noz1,noz2,noz3,noz4,
		spawner1,spawner2,spawner3,spawner4,spawner5,
		big_daddy,
		sound_shielda,sound_shieldb,sound_shieldc,sound_shieldd,sound_shielde,sound_shieldf,
		sound_polea,sound_poleb,sound_polec,sound_poled,sound_polee,sound_polef,
	//	bad_pilot,



		h_last;

	// integers
	int
		i_first,

		i_last;
};
DLLBase * BuildMission(void)
{
	return new isdf17Mission();
}

void isdf17Mission::Setup(void)
{
	SetAutoGroupUnits(false);
/*
	Here's where you set the values at the start.  
*/

//  bools
	missionstart = false;
	playeratcore = false;
	obj3 = false;
	playeratdropship = false;
	vo1 = false;
	vo2 = false;
	vo3 = false;
	obj1 = false;
	obj2 = false;
	obj4 = false;
	shielda_down = false;
	shieldb_down = false;
	shieldc_down = false;
	shieldd_down = false;
	shielde_down = false;
	shieldf_down = false;
	temp = false;
	collapse_1 = false;
	collapse_2 = false;
	collapse_3 = false;
	collapse_1a = false;
	collapse_2a = false;
	collapse_3a = false;
	reset_quake1 = false;
	reset_quake2 = false;
	reset_quake3 = false;
	planet_go_boom = false;
	kill_player_more = false;
	dropper1_drop = false;
	dropper1b_drop = false;
	dropper2_drop = false;
	dropper2b_drop = false;
	dropper3_drop = false;
	dropper4_drop = false;
	dropper5_drop = false;
	dropper6_drop = false;
	dropper7_drop = false;
	dropper8_drop = false;
	dropper9_drop = false;
	noz1_killed = false;
	noz2_killed = false;
	noz3_killed = false;
	noz4_killed = false;
	all_noz_killed = false;
	spawners_over = false;
	set_spawner_times = false;
	two_noz_killed = false;
	anim_side = false;
	anim_spinside = false;
	anim_fall = false;
	anim_spin = false;
	remove_big_daddy = false;
	swap_turret1 = false;
	swap_turret2 = false;
	swap_turret3 = false;
	dropper10_drop = false;
	dropper11_drop = false;
	vo4 = false;
	vo_robot = false;
//  floats
	obj3time = 999999.9f;
	vo1time = 999999.9f;
	vo2time = 999999.9f;
	vo3time = 999999.9f;
	power_down_soundtime = 999999.9f;
	collapse_soundtime = 999999.9f;
	reset_quake1time = 999999.9f;
	reset_quake2time = 999999.9f;
	reset_quake3time = 999999.9f;
	planet_go_boomtime = 999999.9f;
	kill_player_moretime = 999999.9f;
	spawner1time = 999999.9f;
	spawner2time = 999999.9f;
	spawner3time = 999999.9f;
	spawner4time = 999999.9f;
	spawner5time = 999999.9f;
	spawner234time = 999999.9f;
	anim_spinsidetime = 999999.9f;
	remove_big_daddytime = 999999.9f;
//  handles
	core = GetHandle("core");
	player = NULL;
	dropship = NULL;
	msg1 = NULL;
	msg2 = NULL;
	msg3 = NULL;
	shielda = GetHandle("shielda");
	shieldb = GetHandle("shieldb");
	shieldc = GetHandle("shieldc");
	shieldd = GetHandle("shieldd");
	shielde = GetHandle("shielde");
	shieldf = GetHandle("shieldf");
	triggera = GetHandle("triggera");
	triggerb = GetHandle("triggerb");
	triggerc = GetHandle("triggerc");
	triggerd = GetHandle("triggerd");
	triggere = GetHandle("triggere");
	triggerf = GetHandle("triggerf");
	holdera = GetHandle("holdera");
	holderb = GetHandle("holderb");
	holderc = GetHandle("holderc");
	holderd = GetHandle("holderd");
	holdere = GetHandle("holdere");
	holderf = GetHandle("holderf");

	collapsea = GetHandle("collapsea");
	collapseb = GetHandle("collapseb");
	collapsec = GetHandle("collapsec");

	collapsea1 = NULL;
	collapseb1 = NULL;
	collapsec1 = NULL;
	turret1 = GetHandle("turret1");
	turret2 = GetHandle("turret2");
	turret3 = GetHandle("turret3");

	dropper1 = GetHandle("dropper1");
	dropper1b = GetHandle("dropper1b");
	dropper2 = GetHandle("dropper2");
	dropper2b = GetHandle("dropper2b");
	dropper3 = GetHandle("dropper3");
	dropper4 = GetHandle("dropper4");
	dropper5 = GetHandle("dropper5");
	dropper6 = GetHandle("dropper6");
	dropper7 = GetHandle("dropper7");
	dropper8 = GetHandle("dropper8");
	dropper9 = GetHandle("dropper9");
	dropper10 = GetHandle("dropper10");
	dropper11 = GetHandle("dropper11");

	noz1 = GetHandle("noz1");
	noz2 = GetHandle("noz2");
	noz3 = GetHandle("noz3");
	noz4 = GetHandle("noz4");
	spawner1 = GetHandle("spawner1");
	spawner2 = GetHandle("spawner2");
	spawner3 = GetHandle("spawner3");
	spawner4 = GetHandle("spawner4");
	spawner5 = GetHandle("spawner5");
	big_daddy = GetHandle("big_daddy");
//	bad_pilot = NULL;
	health1 = NULL;
	sound_shielda = GetHandle("sound_shielda");
	sound_shieldb = GetHandle("sound_shieldb");
	sound_shieldc = GetHandle("sound_shieldc");
	sound_shieldd = GetHandle("sound_shieldd");
	sound_shielde = GetHandle("sound_shielde");
	sound_shieldf = GetHandle("sound_shieldf");

	sound_polea = GetHandle("sound_polea");
	sound_poleb = GetHandle("sound_poleb");
	sound_polec = GetHandle("sound_polec");
	sound_poled = GetHandle("sound_poled");
	sound_polee = GetHandle("sound_polee");
	sound_polef = GetHandle("sound_polef");
	//  integers

}

bool isdf17Mission::PostLoad(bool missionSave)
{
	bool ret = SPMission::PostLoad(missionSave);

	if (missionSave)
		return ret;

	if (all_noz_killed)
		SetAnimation(dropship,"deploy",1);

///////////////

	if (!two_noz_killed)
		SetAnimation(big_daddy,"spin",0);
///////////////

	if ((anim_side) && (!anim_spinside))
		SetAnimation(big_daddy,"side",1);
///////////////

	if ((anim_spinside) && (!anim_fall))
		SetAnimation(big_daddy,"spinside",0);

///////////////

	if (anim_fall)
		SetAnimation(big_daddy,"fall",1);
	
	return ret;


}

void isdf17Mission::AddObject(Handle h)
{
}

void isdf17Mission::Execute(void)
{

	player = GetPlayerHandle();
	char tempstr[128];
	if (!missionstart)
	{
		SetMaxHealth(player,4000);
		SetCurHealth(player,4000);
		vo1time = (GetTime() + 2);
		SetSkill(turret1,1);
		SetSkill(turret2,1);
		SetSkill(turret3,1);
		GiveWeapon(player,"gspstab_c");
		GiveWeapon(player,"gmortar");
		SetAnimation(big_daddy,"spin",0);	
		missionstart = true;
	}

	if ((!vo_robot) && (GetDistance(player,"end_mission") < 30))
	{
		AudioMessage("isdf1703.wav");//Are you picking up these robot signals major??
		vo_robot = true;
	}

	//makes big daddy spin
	if (!anim_spin)
	{
		SetAnimation(big_daddy,"spin",0);	
		anim_spin = true;
	}

	if ((!vo1) && (vo1time < GetTime()))
	{
		msg1 = AudioMessage("isdf1701.wav");	//Ok cowboy, it's time to see what you're really made of.  Find the core and blow this place up
		vo1 = true;
	}

	if ((!obj1) && (vo1) && (IsAudioMessageDone(msg1)))
	{
		ClearObjectives();
		AddObjective("isdf1701.otf", WHITE);
		obj1 = true;
	}


	//Controlling the shield doors and their de-activation
	//Shield A
	if ((!shielda_down) && (!IsAround(triggera)))
	{
		power_down_soundtime = (GetTime() + 0.1f);

		Matrix pos_holdera;
		GetPosition(holdera,pos_holdera);
		RemoveObject(holdera);
		holdera = BuildObject("cbhangd2",0,pos_holdera);
		
		Matrix pos_shielda;
		GetPosition(shielda,pos_shielda);
		RemoveObject(shielda);
		BuildObject("cbroad04",0,pos_shielda);

		RemoveObject(sound_polea);
		RemoveObject(sound_shielda);

		shielda_down = true;	
	}
	//Shield B
	if ((!shieldb_down) && (!IsAround(triggerb)))
	{
		power_down_soundtime = (GetTime() + 0.1f);

		Matrix pos_holderb;
		GetPosition(holderb,pos_holderb);
		RemoveObject(holderb);
		holderb = BuildObject("cbhangd2",0,pos_holderb);

		Matrix pos_shieldb;
		GetPosition(shieldb,pos_shieldb);
		RemoveObject(shieldb);
		BuildObject("cbroad04",0,pos_shieldb);

		RemoveObject(sound_poleb);
		RemoveObject(sound_shieldb);

		shieldb_down = true;	
	}
	//Shield C
	if ((!shieldc_down) && (!IsAround(triggerc)))
	{
		power_down_soundtime = (GetTime() + 0.1f);

		Matrix pos_holderc;
		GetPosition(holderc,pos_holderc);
		RemoveObject(holderc);
		holderc = BuildObject("cbhangd2",0,pos_holderc);

		Matrix pos_shieldc;
		GetPosition(shieldc,pos_shieldc);
		RemoveObject(shieldc);
		BuildObject("cbroad04",0,pos_shieldc);

		RemoveObject(sound_polec);
		RemoveObject(sound_shieldc);

		shieldc_down = true;	
	}
	//Shield D
	if ((!shieldd_down) && (!IsAround(triggerd)))
	{
		power_down_soundtime = (GetTime() + 0.1f);

		Matrix pos_holderd;
		GetPosition(holderd,pos_holderd);
		RemoveObject(holderd);
		holderd = BuildObject("cbhangd2",0,pos_holderd);

		Matrix pos_shieldd;
		GetPosition(shieldd,pos_shieldd);
		RemoveObject(shieldd);
		BuildObject("cbroad04",0,pos_shieldd);

		RemoveObject(sound_poled);
		RemoveObject(sound_shieldd);

		shieldd_down = true;	
	}
	//Shield E
	if ((!shielde_down) && (!IsAround(triggere)))
	{
		power_down_soundtime = (GetTime() + 0.1f);

		Matrix pos_holdere;
		GetPosition(holdere,pos_holdere);
		RemoveObject(holdere);
		holdere = BuildObject("cbhangd2",0,pos_holdere);

		Matrix pos_shielde;
		GetPosition(shielde,pos_shielde);
		RemoveObject(shielde);
		BuildObject("cbroad04",0,pos_shielde);

		RemoveObject(sound_polee);
		RemoveObject(sound_shielde);

		shielde_down = true;	
	}
	//Shield F
	if ((!shieldf_down) && (!IsAround(triggerf)))
	{
		power_down_soundtime = (GetTime() + 0.1f);

		Matrix pos_holderf;
		GetPosition(holderf,pos_holderf);
		RemoveObject(holderf);
		holderf = BuildObject("cbhangd2",0,pos_holderf);

		Matrix pos_shieldf;
		GetPosition(shieldf,pos_shieldf);
		RemoveObject(shieldf);
		BuildObject("cbroad04",0,pos_shieldf);

		RemoveObject(sound_polef);
		RemoveObject(sound_shieldf);

		shieldf_down = true;	
	}
	//playing powerdown sound whenever a shield is deactivated
	if ((power_down_soundtime < GetTime()))
	{
		AudioMessage("tcmort02.wav");
		power_down_soundtime = 999999.9f;
	}

	//This controls the swapping of the Turrets once they are destroyed
	if ((!swap_turret1) && (GetCurHealth(turret1) < 400))
	{
		Matrix pos_turret1;
		GetPosition(turret1,pos_turret1);
		Damage(turret1,999);
		BuildObject("cbturrd1",0,pos_turret1);	
		swap_turret1 = true;
	}

	if ((!swap_turret2) && (GetCurHealth(turret2) < 400))
	{
		Matrix pos_turret2;
		GetPosition(turret2,pos_turret2);
		Damage(turret2,999);
		BuildObject("cbturrd1",0,pos_turret2);	
		swap_turret2 = true;
	}

	if ((!swap_turret3) && (GetCurHealth(turret3) < 400))
	{
		Matrix pos_turret3;
		GetPosition(turret3,pos_turret3);
		Damage(turret3,999);
		BuildObject("cbturrd1",0,pos_turret3);	
		swap_turret3 = true;
	}

	//will play a VO when player is sort of near core
	if ((!vo4) && (GetDistance(player,core) < 500))
	{
		AudioMessage("isdf1704.wav"); //You should be nearing the core now
		vo4 = true;
	}



	//checking when the player gets to the core
	if ((!playeratcore) && (GetDistance(player,core) < 260))
	{
		SetObjectiveOn(noz1);
		TranslateString2(tempstr, sizeof(tempstr), "Mission1701");  // Beam Emitter

		SetObjectiveName(noz1,tempstr);
		SetObjectiveOn(noz2);
		SetObjectiveName(noz2,tempstr);
		SetObjectiveOn(noz3);
		SetObjectiveName(noz3,tempstr);
		SetObjectiveOn(noz4);
		SetObjectiveName(noz4,tempstr);
		AudioMessage("isdf1705.wav"); //Ah, there it is...the brain of planet core...
		playeratcore = true;
	}

	//this controls the objects that spawn into the computer room while player is trying to blow up the nozzles
	if ((!spawners_over) && (playeratcore))
	{
		if (!set_spawner_times)
		{
			spawner1time = (GetTime() + 1);
			spawner234time = (GetTime() + 31);
			spawner5time = (GetTime() + 50);
			set_spawner_times = true;
		}

		if (spawner1time < GetTime())
		{
			Matrix pos_spawner1;
			GetPosition(spawner1,pos_spawner1);
			BuildObject("Cseeker",2,pos_spawner1);	
			spawner1time = (GetTime() + 10);
		}

		if (spawner234time < GetTime())
		{
			Matrix pos_spawner2;
			GetPosition(spawner2,pos_spawner2);
			BuildObject("Cseeker",2,pos_spawner2);	

			Matrix pos_spawner3;
			GetPosition(spawner3,pos_spawner3);
			BuildObject("Cseeker",2,pos_spawner3);	
		
			Matrix pos_spawner4;
			GetPosition(spawner4,pos_spawner4);
			BuildObject("Cseeker",2,pos_spawner4);	

			spawner234time = (GetTime() + 30);		
		}

		if (spawner5time < GetTime())
		{
			Matrix pos_spawner5;
			GetPosition(spawner5,pos_spawner5);
			BuildObject("apcserv",0,pos_spawner5);	
			spawner5time = (GetTime() + 50);
		}

		if (all_noz_killed)
		{
			spawners_over = true;
		}
	
	}

	//checking when the nozzles (beam emitters) are destroyed
	if (playeratcore)
	{
		if ((!noz1_killed) && (!IsAround(noz1)))
		{
			noz1_killed = true;
		}

		if ((!noz2_killed) && (!IsAround(noz2)))
		{
			noz2_killed = true;
		}

		if ((!noz3_killed) && (!IsAround(noz3)))
		{
			noz3_killed = true;
		}

		if ((!noz4_killed) && (!IsAround(noz4)))
		{
			noz4_killed = true;
		}
		
		//tells me when ANY two nozzles have been killed
		if (!two_noz_killed)
		{
			if ((!IsAround(noz1)) && (!IsAround(noz2)))
			{
				two_noz_killed = true;
			}
		
			if ((!IsAround(noz1)) && (!IsAround(noz3)))
			{
				two_noz_killed = true;
			}
		
			if ((!IsAround(noz1)) && (!IsAround(noz4)))
			{
				two_noz_killed = true;
			}		
		
			if ((!IsAround(noz2)) && (!IsAround(noz3)))
			{
				two_noz_killed = true;
			}
			
			if ((!IsAround(noz2)) && (!IsAround(noz4)))
			{
				two_noz_killed = true;
			}

			if ((!IsAround(noz3)) && (!IsAround(noz4)))
			{
				two_noz_killed = true;
			}
		}

		//tells me when ALL  nozzles are killed
		if ((!all_noz_killed) && (noz1_killed) && (noz2_killed) && (noz3_killed) && (noz4_killed))
		{
			vo2time = (GetTime() + 5);
			dropship = BuildObject("ivpdrop2",1,"dropship_spawn");
			all_noz_killed = true;
		}

		//when 2 nozs killed, object first tilts, then spins while tilted...
		if ((!anim_side) && (two_noz_killed))
		{
			SetAnimation(big_daddy,"side",1);	
			anim_spinsidetime = (GetTime() + 5);
		    anim_side = true;
		}

		if ((!anim_spinside) && (anim_spinsidetime < GetTime()))
		{
			SetAnimation(big_daddy,"spinside",0);
			anim_spinside = true;
		}

		//when all nozs are killed, object is destroyed (falling animation)
		if ((!anim_fall) && (all_noz_killed))
		{
			SetAnimation(big_daddy,"fall",1);
		//	remove_big_daddytime = (GetTime() + 10);
			anim_fall = true;
		}

	//	if ((!remove_big_daddy) && (remove_big_daddytime < GetTime()))
	//	{
	//		RemoveObject(big_daddy);
	//		remove_big_daddy = true;
	//	}
	}


	//**Escape Sequence**//
	if ((!vo2) && (vo2time < GetTime()))
	{
		msg2 = AudioMessage("isdf1702.wav");	//Get out of there
		StartEarthQuake(15); //starting earthquake
		vo2 = true;
	}

	if ((!obj3) && (vo2) && (IsAudioMessageDone(msg2)))
	{
		ClearObjectives();
		AddObjective("isdf1703.otf", WHITE);
		SetObjectiveOn(dropship);
		TranslateString2(tempstr, sizeof(tempstr), "Mission1702");  // Dropship

		SetObjectiveName(dropship,tempstr);
		planet_go_boomtime = (GetTime() + 100);
		StartCockpitTimer(100, 60, 10); 
		SetAnimation(dropship,"deploy",1);
		obj3 = true;
	}

	//Controlling the collapsing tunnels!!
	if (playeratcore)
	{
		if ((!collapse_1) && (GetDistance(player,collapsea) < 100))
		{
			Matrix pos_collapsea;
			GetPosition(collapsea,pos_collapsea);
			RemoveObject(collapsea);
			collapsea1 = BuildObject("cbroadA4",0,pos_collapsea);
			collapse_1 = true;
		}

		if ((!collapse_1a) && (IsAround(collapsea1)))
		{
			StopEarthQuake();
			StartEarthQuake(50);
			reset_quake1time = (GetTime() + 6);
			SetAnimation(collapsea1,"collapse",1);	
			collapse_soundtime = (GetTime() +1);
			collapse_1a = true;
		}

		if ((!reset_quake1) && (reset_quake1time < GetTime()))
		{
			StopEarthQuake();
			StartEarthQuake(15);
			reset_quake1 = true;
		}
///////////////////
		if ((!collapse_2) && (GetDistance(player,collapseb) < 100))
		{
			Matrix pos_collapseb;
			GetPosition(collapseb,pos_collapseb);
			RemoveObject(collapseb);
			collapseb1 = BuildObject("cbroadA4",0,pos_collapseb);	
			collapse_2 = true;
		}

		if ((!collapse_2a) && (IsAround(collapseb1)))
		{
			StopEarthQuake();
			StartEarthQuake(50);
			reset_quake2time = (GetTime() + 6);

			SetAnimation(collapseb1,"collapse",1);	
			collapse_soundtime = (GetTime() +1);
			collapse_2a = true;
		}

		if ((!reset_quake2) && (reset_quake2time < GetTime()))
		{
			StopEarthQuake();
			StartEarthQuake(15);
			reset_quake2 = true;
		}
//////////////////////////
		if ((!collapse_3) && (GetDistance(player,collapsec) < 100))
		{
			Matrix pos_collapsec;
			GetPosition(collapsec,pos_collapsec);
			RemoveObject(collapsec);
			collapsec1 = BuildObject("cbroadA4",0,pos_collapsec);
			collapse_3 = true;
		}

		if ((!collapse_3a) && (IsAround(collapsec1)))
		{
			StopEarthQuake();
			StartEarthQuake(50);
			reset_quake3time = (GetTime() + 6);

			SetAnimation(collapsec1,"collapse",1);	
			collapse_soundtime = (GetTime() +1);
			collapse_3a = true;
		}

		if ((!reset_quake3) && (reset_quake3time < GetTime()))
		{
			StopEarthQuake();
			StartEarthQuake(15);
			reset_quake3 = true;
		}
///////////////////
		if (collapse_soundtime < GetTime())
		{
			AudioMessage("xcollapse.wav");
			collapse_soundtime = 999999.9f;
		}
	}


	//checking to see when player gets back to his dropship
	if ((!playeratdropship) && (obj3) && (GetDistance(player,"end_mission") < 40))
	{
		SucceedMission(GetTime() + 0.1f);
		//	msg3 = AudioMessage("isdf1703.wav"); //yahoo we did it	
		playeratdropship = true;
	}

//	if ((!obj4) && (playeratdropship) && (IsAudioMessageDone(msg3)))
//	{
//		ClearObjectives();
//		AddObjective("isdf1704.otf", WHITE);	//mission accomplished
//		SucceedMission(GetTime() + 10);
//		obj4 = true;
//	}

	//PLANET GO BOOM if player doesn't make it back to dropship in time
	if ((!planet_go_boom) && (obj3) && (!playeratdropship) && (planet_go_boomtime < GetTime()))
	{
		Damage(player,10000);
	//	kill_player_moretime = (GetTime() + 0.5f);
		ClearObjectives();
		AddObjective("isdf1705.otf", WHITE); //mission failed
		FailMission(GetTime() + 2,"isdf17L1.txt");
		planet_go_boom = true;
	}

//	if ((!kill_player_more) && (kill_player_moretime < GetTime()))
//	{
//		Damage(player,10000);
//		FailMission(GetTime() + 10.0f);
//		kill_player_more = true;
//	}




	//this makes some of the robots drop health

	if ((!dropper1_drop) && (GetCurHealth(dropper1) < 350))
	{
		Matrix pos_dropper1;
		GetPosition(dropper1,pos_dropper1);
		Damage(dropper1,999);
		health1 = BuildObject("apcserv",0,pos_dropper1);
		dropper1_drop = true;
	}

	if ((!dropper1b_drop) && (GetCurHealth(dropper1b) < 350))
	{
		Matrix pos_dropper1b;
		GetPosition(dropper1b,pos_dropper1b);
		Damage(dropper1b,999);
		health1 = BuildObject("apcserv",0,pos_dropper1b);
		dropper1b_drop = true;
	}

	if ((!dropper2_drop) && (GetCurHealth(dropper2) < 350))
	{
		Matrix pos_dropper2;
		GetPosition(dropper2,pos_dropper2);
		Damage(dropper2,999);
		health1 = BuildObject("apcserv",0,pos_dropper2);
		dropper2_drop = true;
	}

	if ((!dropper2b_drop) && (GetCurHealth(dropper2b) < 350))
	{
		Matrix pos_dropper2b;
		GetPosition(dropper2b,pos_dropper2b);
		Damage(dropper2b,999);
		health1 = BuildObject("apcserv",0,pos_dropper2b);
		dropper2b_drop = true;
	}

	if ((!dropper3_drop) && (GetCurHealth(dropper3) < 350))
	{
		Matrix pos_dropper3;
		GetPosition(dropper3,pos_dropper3);
		Damage(dropper3,999);
		health1 = BuildObject("apcserv",0,pos_dropper3);
		dropper3_drop = true;
	}

	if ((!dropper4_drop) && (GetCurHealth(dropper4) < 350))
	{
		Matrix pos_dropper4;
		GetPosition(dropper4,pos_dropper4);
		Damage(dropper4,999);
		health1 = BuildObject("apcserv",0,pos_dropper4);
		dropper4_drop = true;
	}

//	if ((!dropper5_drop) && (GetCurHealth(dropper5) < 350))
//	{
//		Matrix pos_dropper5;
//		GetPosition(dropper5,pos_dropper5);
//		Damage(dropper5,999);
//		health1 = BuildObject("apcserv",0,pos_dropper5);
//		dropper5_drop = true;
//	}

	if ((!dropper6_drop) && (GetCurHealth(dropper6) < 350))
	{
		Matrix pos_dropper6;
		GetPosition(dropper6,pos_dropper6);
		Damage(dropper6,999);
		health1 = BuildObject("apcserv",0,pos_dropper6);
		dropper6_drop = true;
	}

	if ((!dropper7_drop) && (GetCurHealth(dropper7) < 350))
	{
		Matrix pos_dropper7;
		GetPosition(dropper7,pos_dropper7);
		Damage(dropper7,999);
		health1 = BuildObject("apcserv",0,pos_dropper7);
		dropper7_drop = true;
	}

	if ((!dropper8_drop) && (GetCurHealth(dropper8) < 350))
	{
		Matrix pos_dropper8;
		GetPosition(dropper8,pos_dropper8);
		Damage(dropper8,999);
		health1 = BuildObject("apcserv",0,pos_dropper8);
		dropper8_drop = true;
	}

//	if ((!dropper9_drop) && (GetCurHealth(dropper9) < 350))
//	{
//		Matrix pos_dropper9;
//		GetPosition(dropper9,pos_dropper9);
//		Damage(dropper9,999);
//		health1 = BuildObject("apcserv",0,pos_dropper9);
//		dropper9_drop = true;
//	}

	if ((!dropper10_drop) && (GetCurHealth(dropper10) < 350))
	{
		Matrix pos_dropper10;
		GetPosition(dropper10,pos_dropper10);
		Damage(dropper10,999);
		health1 = BuildObject("apcserv",0,pos_dropper10);
		dropper10_drop = true;
	}

	if ((!dropper11_drop) && (GetCurHealth(dropper11) < 350))
	{
		Matrix pos_dropper11;
		GetPosition(dropper11,pos_dropper11);
		Damage(dropper11,999);
		health1 = BuildObject("apcserv",0,pos_dropper11);
		dropper11_drop = true;
	}

}
