#include "..\Shared\SPMission.h"


class isdf05Mission : public SPMission 
{
public:
	isdf05Mission(void)
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
		warning_message,
		start_done, out_of_range, out_of_ship, in_combat, fire_message, 
		patrol_phase,  // while you patrol
		scout_phase,  // while you scout
		get_mbike,		// you get mbikes to destroy turret
		turrets_destroyed,  // turrets destroyed
		been_north,
		been_south,
		been_east,
		been_west,
		found_field1,
		found_field2,
		found_field3,
		scav1_deployed,
		scav2_deployed,
		attack_phase,
		killed_turrets,  // killed all turrets
		wait_up,  // manson waits for the player
		manson_message,
		gun_tower_message,  // got gun tower message
		hop_out_message,
		teleport_blown,
		MoviePlaying,
		com1,
		factory,
		out_of_ship_ever,
		shab_dead,
		b_last;

	// floats
	float
		f_first,
		fire_reset, range_check,
		mortar_delay,
		patrol_reminder_time,  // remind player to patrol recycler
		manson_shows,		// time for manson to show up
		f_last;

	// handles
	Handle
		h_first,
		player, player_ship, shabayev, manson, recycler,
		scav1, scav2, scav3,scav4,
		off_power, off_service, teleportal,
		empty_scav1, empty_scav2, empty_scav3,
		empty_construct1, empty_construct2, empty_construct3,
		recycler2,
		sturret1, sturret2, sturret3, sturret4,sturret5,sturret6,
		pool1,pool2,pool3,
		raid1,raid2,raid3,raid4,
		constructor,
		lurker1,
		lurker2,
		lurker3,
		lurker4,
		wasDead1,
		wasDead2,
		nav1,
		nav2,
		audmsg,
		mbike1,
		recy,
		drop_off,
		power2,
		scav_comp,
		atk1,
		pgen1,
		pgen2,
		cbunker,
		h_last;

	// integers
	int
		i_first,
		gun_tower_counter,
		mission_state,
		raid_count,
		wait_count,
		ReallyKillCineractive,
		i_last;
};
DLLBase * BuildMission(void)
{
	return new isdf05Mission();
}

void isdf05Mission::Setup(void)
{
	SetAutoGroupUnits(false);
	/*
	Here's where you set the values at the start.  
	*/
	Ally(3,1);
	Ally(1,3);

	//  bools
	start_done = false;
	out_of_range = false;
	out_of_ship = false;
	in_combat = false;
	fire_message = false;

	patrol_phase=false;  // while you patrol
	scout_phase=false;  // while you scout
	attack_phase=false;
	get_mbike=false;		// you get mbikes to destroy turret
	turrets_destroyed=false;  // turrets destroyed
	been_north=false;
	been_south=false;
	been_east=false;
	been_west=false;
	found_field1=false;
	found_field2=false;
	scav1_deployed=false;
	scav2_deployed=false;
	killed_turrets=false;
	manson_message=false;
	gun_tower_message=false;  // got gun tower message
	hop_out_message=false;
	warning_message=false;
	teleport_blown=false;
	wait_up=true;
	power2=false;
	drop_off=false;
	com1=false;
	factory=false;
	out_of_ship_ever=false;  // if you ever get out of your ship
	shab_dead=false;
	wasDead1=false;
	wasDead2=false;
	//  floats
	fire_reset = 1.0f;
	range_check = 999999.9f;

	//  handles
	player = GetPlayerHandle();
	//	player_ship = GetHandle("player_ship");
	//	recycler = GetHandle("unnamed_ivrec5");
	//	wingman1 = GetHandle("wingman1");
	off_power = GetHandle("off_power");
	off_service = GetHandle("off_service");
	teleportal = GetHandle("unnamed_ibtele");
	//	empty_scav1 = GetHandle("empty_scav1");
	//	empty_scav2 = GetHandle("empty_scav2");
	//	empty_scav3 = GetHandle("empty_scav3");
	//	empty_construct1 = GetHandle("empty_construct1");
	//	empty_construct2 = GetHandle("empty_construct2");
	//	empty_construct3 = GetHandle("empty_construct3");
	//	recycler2 = GetHandle("recycler2");

	pool1=GetHandle("pool1");
	pool2=GetHandle("pool2");

	sturret1 = GetHandle("sturret1");
	sturret2 = GetHandle("sturret2");
	sturret3 = GetHandle("sturret3");
	sturret4 = GetHandle("sturret4");
	sturret5 = GetHandle("sturret5");
	sturret6 = GetHandle("sturret6");


	lurker1=NULL;
	lurker2=NULL;
	lurker3=NULL;
	lurker4=NULL;

	scav1 = NULL;
	scav2 = NULL;
	manson = NULL;
	nav1=NULL;
	nav2=NULL;
	atk1=NULL;
	pgen1=NULL;
	pgen2=NULL;
	cbunker=NULL;
	//  integers
	mission_state=0;
	raid_count=0;
	wait_count=0;
	ReallyKillCineractive = 0;

	SetTeamColor(3,0,127,255);  //Blue
}

void isdf05Mission::AddObject(Handle h)
{
	char ODFName[64];
	GetObjInfo(h, Get_CFG, ODFName);

	if (IsOdf2(h,"ibrec5"))
	{
		recy=h;
	}
	if (IsOdf2(h,"ibpgen"))
	{
		if (!pgen1)
		{

			pgen1=h;
			//			Follow(shabayev,pgen1);
			Stop(shabayev,1);
			SetIndependence(shabayev,1);
		}
		else 
		{
			Stop(shabayev,1);
			pgen2=h;
		}
	}
	if (IsOdf2(h,"ibcbun"))
	{
		cbunker=h;
		Stop(shabayev,1);
	}
	if (start_done)
	{
		if ((scav1 == NULL) && (IsOdf2(h,"ivscav")))
		{
			scav1 = h;
		}
		else if ((scav2 == NULL) && (IsOdf2(h,"ivscav")))
		{
			scav2 = h;
		}
		else if ((scav3==NULL) && (IsOdf2(h,"ivscav")))
		{
			scav3=h;
		}
		else if ((scav4==NULL) && (IsOdf2(h,"ivscav")))
		{
			scav4=h;
		}
		else if (IsOdf2(h,"ibscav")) 
		{
			if (!scav1_deployed)
			{
				scav1_deployed=true;
			}
			else
			{
				scav2_deployed=true;
			}
		}

	}
	if (IsOdf2(h,"satchel")) {
		Goto(manson,"manson_path1",1);
		AudioMessage("isdf0542.wav");
	}
}

void isdf05Mission::Execute(void)
{

	/*
	a) The player is asked to patrol around the base

	(through steps b-d sent & scouts attack)

	b) Once the base is secure, the player is supposed
	to look for scrap veins and send a scavenger (twice)

	c)Eventually you get to some turrets.  
	Shebayev detaches some mortar bikes to help you take 
	out the turrets.  

	d) Once the turrets are destroyed you need to
	deploy

	e) Follow Manson to the teleporter?  Drop off a bomb
	*/
	char tempstr[128];
	Handle nearguy = 0;
	// this is the start of the mission
	if (!start_done)
	{

		/*
		Alright Sgt Cooke, this looks like
		a good place to establish a base.  
		Patrol the area around this recycler.  
		If it looks safe, deploy the recycler.  
		*/
		shabayev = BuildObject("ivtan5",1,"shab_start");//"patrol_east");
		constructor = BuildObject("ivcons",1,"spawn_constructor");
		Stop(constructor,1);
		scav_comp= GetHandle("scav3");
		SetGroup(scav_comp,-1);
		Handle temppool=GetHandle("poolx");
		Goto(scav_comp,temppool,1);
		//	SetPlan("isdf05.aip",3);  // build stuff
		AudioMessage("isdf0500.wav");
		SetObjectiveOn(shabayev);
		SetObjectiveName(shabayev,"Cmdr. Shabayev");


		audmsg=AudioMessage("isdf0501.wav");
		patrol_phase=true;
		start_done = true;

		Handle tempscav=GetHandle("ivscav1");
		KillPilot(tempscav);
		tempscav=GetHandle("ivscav2");
		KillPilot(tempscav);
		//		Handle fv=BuildObject("fvarch",2,"scrap_field1");
		//		SetSkill(fv,3);
		SetSkill(shabayev,3);
		//		Patrol(shabayev,"patrol1",1);
		//		Attack(shabayev,fv,1);
		recy=BuildObject("ivrec5",1,"recy_start");
		//		Goto(recy,"recy_deploy");
		Dropoff(recy, "recy_deploy");
		Follow(shabayev,recy,1);
		SetScrap(1,40);
		SetScrap(3,40);  // allied resources
	}

	/*
	Here is where you put what happens every frame.  
	*/

	player = GetPlayerHandle();
	if ((!IsAlive(shabayev) && (!shab_dead)))
	{
		AudioMessage("isdf0732.wav");
		ClearObjectives();
		AddObjective("isdf05l1.otf",RED,15.0f);
		FailMission(GetTime()+5.0f,"isdf05l1.otf");
		shab_dead=true;
	}

	// determining if the player is out of his ship
	if (IsOdf(player,"isuser"))
	{
		if (!out_of_ship) GiveWeapon(player, "igsatc");
		out_of_ship = true;
	}
	else
	{
		out_of_ship = false;
	}

	if ((GetDistance(player,"spawn2")<150.f) && (!warning_message))
	{
		AudioMessage("isdf0520.wav");
		/*
		Stay away from those alien structures
		they aren't 
		vital to our mission-
		but they may be dangerous. 
		*/
		warning_message=true;
	}
	// this is checking to make sure the player does not attack his wingman /////////
	if ((!in_combat) && (!fire_message))
	{
		if ((IsAlive(shabayev)) && (IsAlive(player)))
		{
			if (GetTime() - GetLastFriendShot(shabayev) < .2f)
			{
				AudioMessage("ff01.wav"); // (shab) watch your firing!
				fire_reset = GetTime() + 2.f;
				fire_message = true;
			}
		}

		if ((IsAlive(manson)) && (IsAlive(player)))
		{
			if (GetTime() - GetLastFriendShot(manson) < .2f)
			{
				AudioMessage("isdf0555.wav"); // (manson) watch your firing!
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
	if ((!IsAlive(constructor)) && (mission_state<10))
	{
		// the constructor is dead, you lose
		mission_state=12;
	}

	switch (mission_state)
	{
	case 0:

		// Shabayev starts the base
		if (GetDistance(recy,"recy_deploy") < 25.0)
		{
			//				Dropoff(recy,"recy_deploy");
			Patrol(shabayev,"patrol1",1);
			SetIndependence(shabayev,1);
			ClearObjectives();
			AddObjective("isdf0501.otf", WHITE, 10.0f);
			patrol_reminder_time=GetTime()+30.0f;
			MoviePlaying=true;
			CameraReady();
			// but danger looms..
			atk1=BuildObject("fvscout",2,"spawn1");
			wasDead1=false;
			Attack(atk1,player);
			mission_state++;
		}
		break;

	case 1:
		if (MoviePlaying)
		{
			//CameraObject(recycler,5,5,5,recycler);
			MoviePlaying = PlayMovie("isdf0501.cin");	
			//		if (IsAudioMessageDone(audmsg)) {
			if (!MoviePlaying)
			{
				//	MoviePlaying=false;
				CameraFinish();
				Build(constructor,"ibpge5",1);
				drop_off=true;
				Attack(shabayev,atk1);
				mission_state++;
			}
		}
		ReallyKillCineractive = 0;
		break;

	case 2: // patrol_phase

		// Kick this out a few extra times.
		if((ReallyKillCineractive == 0) || (ReallyKillCineractive == 10) || 
			(ReallyKillCineractive == 20))
			CameraFinish();
		ReallyKillCineractive++;

		if (drop_off)
		{
			Dropoff(constructor,"pgen1",1);
			drop_off=false;
			Handle temp=GetHandle("unnamed_ivdrop");
			Attack(shabayev,atk1,1);
			RemoveObject(temp);
		}

		if (!IsAlive(atk1))
		{
			wait_count++;
			if (wait_count==250)
			{
				wasDead1=false;
				wasDead2=false;
				raid1=BuildObject("fvsent",2,"raid1");
				Goto(raid1,recy);
				raid2=BuildObject("fvtank",2,"raid2");
				Goto(raid2,recy);
				//				raid3=BuildObject("fvsent",2,"raid3");
				//				Goto(raid3,recy);
				//				raid4=BuildObject("fvtank",2,"raid4");
				//				Goto(raid4,recy);
				ClearObjectives();
				AddObjective("isdf0517.otf",WHITE,10.0f);
				Goto(shabayev,constructor);
				AudioMessage("isdf0543.wav");
				mission_state++;
				wait_count=0;
			}
		}
		break;

	case 3:
		if (power2)
		{
			Dropoff(constructor,"pgen2",1);
			power2=false;
		}
		if (com1)
		{
			Dropoff(constructor,"rbunker1",1);
			com1=false;
		}
		if (!IsAliveAndPilot(raid1)) {
			wasDead1=true;	
		}
		if (!IsAliveAndPilot(raid2)) {
			wasDead2=true;
		}
		if ((wasDead1) && (wasDead2))
		{
			if (raid_count==1)  // should be 2
			{
				/*
				Now look for scrap veins
				around the base.  
				If you find one mark it with 
				a nav beacon.  
				*/
				scout_phase=true;
				ClearObjectives();
				AddObjective("isdf0507.otf",WHITE,5.0f);
				SetObjectiveOff(shabayev);
				nav1=BuildObject("ibnav",1,"scrap_field1");
				TranslateString2(tempstr, sizeof(tempstr), "Mission0501");  // tempstr
				SetObjectiveName(nav1,tempstr);
				SetObjectiveOn(nav1);
				//					SetObjectiveName(pool1,"bio-metal");
				//					SetObjectiveOn(pool1);

				AudioMessage("isdf0507.wav");	
				// Add an attacked for spice
				Handle atk1=BuildObject("fvscout",2,"spawn1");
				Goto(atk1,"attack1");
				Patrol(shabayev,"patrol1",1);
				SetIndependence(shabayev,1);
				// AudioMessage(
				// You go on John, I'll guard the base
				mission_state++;
			}
			else
			{
				wait_count++;
				if (wait_count==400)
				{
					if  (pgen2==NULL)
					{	
						// was follow
						Goto(shabayev,constructor,1);
						Build(constructor,"ibpge5");
						power2=true;
					}
					else 
					{
						//was Follow
						Goto(shabayev,constructor,1);
						Build(constructor,"ibcbu5");
						com1=true;
					}
					raid_count++;
					AddHealth(constructor,500);
					AddHealth(shabayev,500);
					raid1=BuildObject("fvtank",2,"raid1");
					Goto(raid1,recy);
					raid2=BuildObject("fvtank",2,"raid2");
					Goto(raid2,recy);
					wasDead1=false;
					wasDead2=false;
					//					raid3=BuildObject("fvsent",2,"raid3");
					//					Goto(raid3,recy);
					//					raid4=BuildObject("fvtank",2,"raid4");
					//					Goto(raid4,recy);
					wait_count=0;
				}
			}
		}

		break;

	case 4: 	
		// there is one, mark it with the geyser
		// mark that with a power up
		// good, now find another.  
		if ((GetDistance(player,pool1)<75.0f) && (!found_field1))
		{
			// there is a field, deploy the scavenger

			AudioMessage("isdf0508.wav");
			found_field1=true;
		}
		if (scav2_deployed) // any scav is deployed
		{
			mission_state++;
			scav1_deployed=true;
			ClearObjectives();
			AddObjective("isdf0508.otf",WHITE,10.0f);
			/*
			SetObjectiveOff(pool1);
			SetObjectiveName(pool2,"bio-metal 1");
			SetObjectiveOn(pool2);
			*/
			nav2=BuildObject("ibnav",1,"scrap_field3");
			TranslateString2(tempstr, sizeof(tempstr), "Mission0502");  // Bio-Metal 2
			SetObjectiveName(nav2,tempstr);
			SetObjectiveOff(nav1);
			SetObjectiveOn(nav2);
			AudioMessage("isdf0509.wav");  // good job
			if (!found_field1)
			{
				AudioMessage("isdf0519.wav");
				/*
				Don't send out scavengers unescorted.  
				Be sure to stay with them.
				*/
			}
		}
		break;

	case 5:
		if ((scav2_deployed) && (!found_field3) && (GetDistance(player,"scrap_field3")<225.0f))
		{
			found_field3=true;
			/*
			Watch out!
			That field looks hot.  
			*/
			AudioMessage("isdf0512.wav");
			ClearObjectives();
			AddObjective("isdf0511.otf",RED,10.0f);
			mortar_delay=GetTime()+15.0f;
		}
		nearguy=GetNearestEnemy(player);
		if ((found_field3) && (GetTime()>mortar_delay)
			&& (GetDistance(player,nearguy)>150.0f))
		{
			/*
			Cineractive
			Cooke, I'm sending you
			force to help 
			you take out those turrets!
			Here are some mortar bikes.  
			*/

			Build(constructor,"ibfact5",1);
			factory=true;

			audmsg=AudioMessage("isdf0527.wav");
			//was AudioMessage("isdf0513.wav");
			ClearObjectives();
			AddObjective("isdf0516.otf",WHITE,10.0f);
			/*
			int grp=GetFirstEmptyGroup();			
			mbike1=BuildObject("ivmbike",1,"patrol_south");
			SetGroup(mbike1,grp);
			Follow(mbike1,player,0);
			Handle mb=BuildObject("ivmbike",1,"patrol_east");
			SetGroup(mb,grp);
			Follow(mb,player,0);
			mb=BuildObject("ivmbike",1,"patrol_west");
			SetGroup(mb,grp);
			Follow(mb,player,0);
			mb=BuildObject("ivmbike",1,"patrol_north");
			SetGroup(mb,grp);
			Follow(mb,player,0);
			*/
			mission_state++;
			CameraReady();
			MoviePlaying=true;
		}
		break;

	case 6:// attack phase 
		/*
		First check to see if you blew up
		sturret1-4
		then create Manson
		at manson_start
		"Good job Cooke, you show promise"
		Then follow Manson (he's an objective)
		into the base
		When you get close
		lets run past those towers

		when you get there
		hop out and use your demolition charge

		Then run away.  Everything blows up.  
		*/
		if (factory)
		{
			Dropoff(constructor,"fact");
			factory=false;
		}
		if (MoviePlaying)
		{
			CameraObject(constructor,1,11,22,constructor);
			if (IsAudioMessageDone(audmsg))
			{
				MoviePlaying=false;
				CameraFinish();
			}
		}

		if ((!killed_turrets) &&
			(!IsAlive(sturret1)) && 
			(!IsAlive(sturret2)) &&
			(!IsAlive(sturret3)) && (!IsAlive(sturret4))
			&&
			(!IsAlive(sturret5)) && (!IsAlive(sturret6)))
		{
			AudioMessage("isdf0514.wav"); // you show promise
			killed_turrets=true;
			ClearObjectives();
			AddObjective("isdf0512.otf",WHITE,10.0f);
			manson_shows=GetTime()+10.0f;
			manson=BuildObject("ivtank",3,"manson_start");
			SetObjectiveName(manson, "Maj. Manson");
			Handle minion=BuildObject("ivtank",3,"manson_escort1");
			SetObjectiveName(minion, "Sgt. Zdarko");
			Follow(minion,manson);
			minion=BuildObject("ivtank",3,"manson_escort2");
			SetObjectiveName(minion, "Sgt. Masiker");
			Follow(minion,manson);
		}
		if ((killed_turrets) && (!manson_message) && 
			(GetTime()>manson_shows))
		{
			/*
			We found the objective, 
			follow me
			*/
			AudioMessage("isdf0515.wav");
			SetObjectiveOff(nav2);
			SetObjectiveOn(manson);
			ClearObjectives();
			AddObjective("isdf0518.otf",WHITE,10.0f);
			manson_message=true;
			mission_state++;
		}
		break;

	case 7:
		if (GetDistance(player,manson)<50.0f)
		{
			ClearObjectives();
			AddObjective("isdf0513.otf",WHITE,10.0f);
			SetIndependence(manson,0);
			SetAvoidType(manson,0);
			AudioMessage("isdf0539a.wav");
			Goto(manson,"manson_path1");				
			mission_state++;
		}	
		break;

	case 8:
		AddHealth(manson,100); // we don't want him to die here
		if ((wait_up) && (GetDistance(player,manson)<100.0f))
		{
			// right now this goes off too 
			// soon.   You go on to path 2 before 1 is doen
			// But at least it makes sure
			// you are close once.  
			wait_up=false;
			Goto(manson,"manson_path2");
		}
		if ((!gun_tower_message) && (GetDistance(manson,"guntower2")<200.0f))
		{
			/*
			There are gun towers ahead
			let's try to go past fast.  
			*/
			AudioMessage("isdf0516.wav");
			gun_tower_message=true;
			ClearObjectives();
			AddObjective("isdf0514.otf",WHITE,10.0f);
			gun_tower_counter=0;
		}
		if (gun_tower_message) 
		{
			gun_tower_counter++;
			if (gun_tower_counter>450)  // you are on a timer
			{
				AudioMessage("isdf0529.wav");
				ClearObjectives();
				AddObjective("isdf0520.otf",RED,10.0f);
				FailMission(GetTime()+10.0f,"isdf0520.otf");
				mission_state=12;
			}
			if (gun_tower_counter==300)
			{
				AudioMessage("isdf0528.wav");
			}
		}
		if ((gun_tower_message) && (!hop_out_message) &&
			(GetDistance(player,teleportal)<100.0f))
		{
			/* 
			Get out and use your
			demolition charge on
			that building
			*/
			AudioMessage("isdf0173.wav");  // that looks like one of ours?
			AudioMessage("isdf0517.wav");
			hop_out_message=true;
			SetObjectiveOff(manson);
			SetObjectiveOn(teleportal);
			TranslateString2(tempstr, sizeof(tempstr), "Mission0503");  // Excavator
			SetObjectiveName(teleportal,tempstr);
			ClearObjectives();
			AddObjective("isdf0515.otf",WHITE,10.0f);
			SetIndependence(manson,1);
			mission_state++;
		}
		break;

	case 9:
		if ((!out_of_ship_ever) && (out_of_ship)) {
			out_of_ship_ever=true;
			ClearObjectives();
			AddObjective("isdf0521.otf",WHITE,5.0f);
		}
		if (!IsAlive(teleportal))
		{
			if (out_of_ship_ever)
			{
				AudioMessage("isdf0518.wav");
				SucceedMission(GetTime()+10.0f,"isdf05w1.txt");
				mission_state++;
			}
			else
			{
				AudioMessage("isdf0521.wav");
				/*
				I said use your
				demolition charge
				*/
				FailMission(GetTime()+10.0f,"isdfl1.txt");
				mission_state++;
			}
		}
		break;

	case 12:
		/*
		If you lose the constructor
		this condition occurs.  
		*/
		AudioMessage("isdf0522.wav");
		ClearObjectives();
		AddObjective("isdf0519.otf",RED,10.0f);
		FailMission(GetTime()+10.0f,"isdf0519.otf");
		mission_state++;
		break;
	case 13:
		// waiting for the end of the world.  
		break;
	}



	/*
	the lurkers
	*/
	if ((lurker1==NULL) && (GetDistance(player,"lurker1")<150.0f))
	{
		lurker1=BuildObject("fvsent",2,"lurker1");
	}
	if ((lurker2==NULL) && (GetDistance(player,"lurker2")<150.0f))
	{
		lurker2=BuildObject("fvsent",2,"lurker1");
	}
	if ((lurker3==NULL) && (GetDistance(player,"lurker3")<150.0f))
	{
		lurker3=BuildObject("fvsent",2,"lurker3");
	}
	if ((lurker4==NULL) && (GetDistance(player,"lurker4")<150.0f))
	{
		lurker4=BuildObject("fvsent",2,"lurker4");
	}
}
