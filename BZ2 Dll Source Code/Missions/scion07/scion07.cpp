//TODO RIGHT NOW BASE IS CONSIDERED DEAD WHEN RECY GONE.  MAKE IT SO THEY HAVE TO KILL ALL THE BUILDINGS
//TODO ISDF BASE AND BASE BATTLE NEED WORK
//TODO probably make base much harder.  
//probably make braddock battle harder, or add some smaller swarming units
//i fixed spawns at beginning and made the scav attackers come faster, play through and see how this is
//find out why base attackers come at such long intervals (when they should come in pair)
#include "..\Shared\SPMission.h"

class scion07 : public SPMission 
{
public:
	scion07(void)
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
		missionstart,pool1taken,vo1,obj1,vo2,obj2,extractor1_deployed,vo3,obj3,
		pool2taken,vo2b,obj2b,extractor2_deployed,vo4,obj3b,pool3taken,
		extractor3_deployed,vo5,obj5,isdfbasekilled,checkturret1alive,turret1alive,
		checkturret1dead,turret1go,checkturret2alive,turret2alive,checkturret2dead,turret2go,
		obj2c,checkbasetank1alive,basetank1alive,checkbasetank1dead,basetank1go,
		checkbasetank2alive,basetank2alive,checkbasetank2dead,basetank2go,
		checkbasescout1alive,basescout1alive,checkbasescout1dead,basescout1go,
		checkbasescout2alive,basescout2alive,checkbasescout2dead,basescout2go,
		checkbasescout3alive,basescout3alive,checkbasescout3dead,basescout3go,vo8,
		playeratmachine,machineclear,obj7,settimes_pool1,pool1guarda_attack,
		vo6,vo7,obj6,vo9,pool1guardb_attack,settimes_pool2,pool2guarda_attack,pool2guardb_attack,
		vo2c,settimes_pool3,pool3guarda_attack,pool3guardb_attack,playersrecy_dead,vo_recydead,
		obj8,walker_cin_over,walker_shot1,walker_rdycam1,walkers_move1,
		walk1_stop,braddock_stop,walk2_stop,
		walker_shot2,walker_shot2_settime,timed_attacks_over,base_attack1,base_attack2,
		base_attack3,cinvo1,vo10,vo11,settime_reset_walks,reset_walks,
		done_controlling_walks,
		b_last;

	// floats
	float
		f_first,
		vo1time,
		vo2time,
		vo3time,
		vo2btime,
		vo4time,
		vo2ctime,
		vo5time,
		basetank1movetime,
		turret1movetime,
		turret2movetime,
		basetank2movetime,
		basescout1movetime,
		basescout2movetime,
		basescout3movetime,
		vo6time,
		vo7time,
		vo8time,
		vo9time,
		pool1guarda_attacktime,
		pool1guardb_attacktime,
		pool2guarda_attacktime,
		pool2guardb_attacktime,
		pool3guarda_attacktime,
		pool3guardb_attacktime,
		vo_recydeadtime,walker_shot1_overtime,walker_shot2_overtime,
		base_attack1time,base_attack2time,base_attack3time,cinvo1time,vo10time,reset_walkstime,
		f_last;

	// handles
	Handle
		h_first,
		ivscav1,ivscav2,player,msg1,tank1,tank2,tank3,tank4,tank5,tank6,tank7,
		msg2,extractor1,ivscav3,msg2c,msg5,rover1,rover6,rover2a,rover2b,
		msg3,extractor2,msg2b,msg4,surprise1,surprise2,rover3,rover4,rover5,
		turret1,turret2,basetank1,basetank2,basescout1,basescout2,basescout3,
		ibrecy1,msg7,machine,braddock,nav1,nav2,nav3,
		msg9,pool1guarda,pool1guardb,pool2guarda,pool2guardb,pool3guarda,
		pool3guardb,playersrecy,vofail1,
		ivwalk1,ivwalk2,walkers_look,nav4,
		attacker1,attacker2,attacker3,attacker4,attacker5,msgcin1,
		attacker1b,attacker2b,attacker3b,attacker4b,attacker5b,
		end_tank1,end_tank2,
		h_last;


	// integers
	int
		i_first,


		i_last;
};
DLLBase * BuildMission(void)
{
	return new scion07();
}

void scion07::Setup(void)
{
	SetAutoGroupUnits(false);
/*
	Here's where you set the values at the start.  
*/

//  bools
	missionstart = false;
	pool1taken = false;
	vo1 = false;
	obj1 = false;
	vo2 = false;
	obj2 = false;
	extractor1_deployed = false;
	extractor2_deployed = false;
	vo3 = false;
	obj3 = false;
	pool2taken = false;
	vo2b = false;
	obj2b = false;
	vo4 = false;
	obj3b = false;
	pool3taken = false;
	vo2c = false;
	obj2c = false;
	extractor3_deployed = false;
	vo5 = false;
	obj5 = false;
	isdfbasekilled = false;
	checkturret1alive = false;
	turret1alive = false;
	checkturret1dead = false;
	turret1go = false;
	checkturret2alive = false;
	turret2alive = false;
	checkturret2dead = false;
	turret2go = false;
	checkbasetank1alive = false;
	basetank1alive = false;
	checkbasetank1dead = false;
	basetank1go = false;
	checkbasetank2alive = false;
	basetank2alive = false;
	checkbasetank2dead = false;
	basetank2go = false;
	checkbasescout1alive = false;
	basescout1alive = false;
	checkbasescout1dead = false;
	basescout1go = false;
	checkbasescout2alive = false;
	basescout2alive = false;
	checkbasescout2dead = false;
	basescout2go = false;
	checkbasescout3alive = false;
	basescout3alive = false;
	checkbasescout3dead = false;
	basescout3go = false;
	vo6 = false;
	vo7 = false;
	obj6 = false;
	playeratmachine = false;
	vo8 = false;
	machineclear = false;
	vo9 = false;
	obj7 = false;
	settimes_pool1 = false;
	pool1guarda_attack = false;
	pool1guardb_attack = false;
	settimes_pool2 = false;
	pool2guarda_attack = false;
	pool2guardb_attack = false;
	pool3guarda_attack = false;
	pool3guardb_attack = false;
	settimes_pool3 = false;
	playersrecy_dead = false;
	vo_recydead = false;
	obj8 = false;
	walker_cin_over = false;
	walker_shot1 = false;
	walker_rdycam1 = false;
	walkers_move1 = false;
	walk1_stop = false;
	braddock_stop = false;
	walk2_stop = false;
	walker_shot2 = false;
	walker_shot2_settime = false;
	timed_attacks_over = false;
	base_attack1 = false;
	base_attack2 = false;
	base_attack3 = false;
	cinvo1 = false;
	vo10 = false;
	vo11 = false;
	settime_reset_walks = false;
	reset_walks = false;
	done_controlling_walks = false;
//  floats
	vo1time = 999999.9f;
	vo2time = 999999.9f;
	vo2btime = 999999.9f;
	vo2ctime = 999999.9f;
	vo3time = 999999.9f;	
	vo4time = 999999.9f;
	vo5time = 999999.9f;
	basetank1movetime = 999999.9f;
	basetank2movetime = 999999.9f;
	turret1movetime = 999999.9f;
	turret2movetime = 999999.9f;
	turret2movetime = 999999.9f;
	basescout1movetime = 999999.9f;
	basescout2movetime = 999999.9f;
	basescout3movetime = 999999.9f;
	vo6time = 999999.9f;
	vo7time = 999999.9f;
	vo8time = 999999.9f;
	vo9time = 999999.9f;
	pool1guarda_attacktime = 999999.9f;
	pool1guardb_attacktime = 999999.9f;
	pool2guarda_attacktime = 999999.9f;
	pool2guardb_attacktime = 999999.9f;
	pool3guarda_attacktime = 999999.9f;
	pool3guardb_attacktime = 999999.9f;
	vo_recydeadtime = 999999.9f;
	walker_shot1_overtime = 999999.9f;
	walker_shot2_overtime = 999999.9f;
	base_attack1time = 999999.9f;
	base_attack2time = 999999.9f;
	base_attack3time = 999999.9f;
	cinvo1time = 999999.9f;
	vo10time = 999999.9f;
	reset_walkstime = 999999.9f;
//  handles

	ivscav1 = GetHandle("ivscav1");
	ivscav2 = GetHandle("ivscav2");
	ivscav3 = GetHandle("ivscav3");
	player = NULL;
	msg1 = NULL;
	msg2 = NULL;
	msg2b = NULL;
	msg2c = NULL;
	msg3 = NULL;
	msg5 = NULL;
	msg7 = NULL;
	tank1 = GetHandle("tank1");
	tank2 = GetHandle("tank2");
	tank3 = GetHandle("tank3");
	tank4 = GetHandle("tank4");
	tank5 = GetHandle("tank5");
	tank6 = GetHandle("tank6");
	tank7 = GetHandle("tank7");
	rover1 = GetHandle("rover1");
	rover6 = GetHandle("rover6");
	rover2a = GetHandle("rover2a");
	rover2b = GetHandle("rover2b");
	rover3 = GetHandle("rover3");
	rover4 = GetHandle("rover4");
	rover5 = GetHandle("rover5");
	ibrecy1 = GetHandle("ibrecy1");
	machine = GetHandle("machine");
	braddock = GetHandle("braddock");
	extractor1 = NULL;
	extractor2 = NULL;
	msg4 = NULL;
	msg9 = NULL;
	surprise1 = NULL;
	surprise2 = NULL;
	turret1 = NULL;
	turret2 = NULL;
	basetank1 = NULL;
	basetank2 = NULL;
	basescout1 = NULL;
	basescout2 = NULL;
	basescout3 = NULL;
	nav1 = NULL;
	nav2 = NULL;
	nav3 = NULL;
	pool1guarda = NULL;
	pool1guardb = NULL;
	pool2guarda = NULL;
	pool2guardb = NULL;
	pool3guarda = NULL;
	pool3guardb = NULL;
	playersrecy = GetHandle("playersrecy");
	vofail1 = NULL;

	ivwalk1 = GetHandle("ivwalk1");
	ivwalk2 = GetHandle("ivwalk2");
	walkers_look = GetHandle("walkers_look");
	end_tank1 = GetHandle("end_tank1");
	end_tank2 = GetHandle("end_tank2");
	attacker1 = NULL;
	attacker2 = NULL;
	attacker3 = NULL;
	attacker4 = NULL;
	attacker5 = NULL;
	attacker1b = NULL;
	attacker2b = NULL;
	attacker3b = NULL;
	attacker4b= NULL;
	attacker5b = NULL;
	nav4= NULL;
	msgcin1 = NULL;
//  integers


}
void scion07::AddObject(Handle h)
{
	char ODFName[64];
	GetObjInfo(h, Get_CFG, ODFName);

	if (missionstart)
	{
		if ((IsOdf2(h,"fbscav")))
		{
			extractor1 = h;
		}

		else if ((turret1 == NULL) && (IsOdf2(h,"ivturr")))
		{
			turret1 = h;	
		}

		else if ((turret2 == NULL) && (IsOdf2(h,"ivturr")))
		{
			turret2 = h;	
		}

		else if ((basetank1 == NULL) && (IsOdf2(h,"ivtank")))
		{
			basetank1 = h;	
		}
	
		else if ((basetank2 == NULL) && (IsOdf2(h,"ivtank")))
		{
			basetank2 = h;	
		}

		else if ((basescout1 == NULL) && (IsOdf2(h,"ivscout")))
		{
			basescout1 = h;	
		}

		else if ((basescout2 == NULL) && (IsOdf2(h,"ivscout")))
		{
			basescout2 = h;	
		}

		else if ((basescout3 == NULL) && (IsOdf2(h,"ivscout")))
		{
			basescout3 = h;	
		}
	}
}



void scion07::Execute(void)
{
/*
	Here is where you put what happens every frame.  
*/
	player = GetPlayerHandle();
	char tempstr[128];

//	AddScrap(3,10);

//OPENING CINERACTIVE
//controlling walkers
	if (!done_controlling_walks)
	{
		if (!walkers_move1)
		{
			SetAvoidType(ivwalk1,0);
			SetAvoidType(ivwalk2,0);
			SetAvoidType(braddock,0);
			Retreat(ivwalk1,"walker_path");
			Retreat(braddock,"walker_path");
			Retreat(ivwalk2,"walker_path");
			walkers_move1 = true;
		}

		if ((!walk1_stop) && (GetDistance(ivwalk1,"walk1_stop") < 8))
		{
			Stop(ivwalk1);
			LookAt(ivwalk1,walkers_look);
			walk1_stop = true;
		}
			
		if ((!braddock_stop) && (GetDistance(braddock,"braddock_stop") < 8))
		{
			Stop(braddock);
			LookAt(braddock,walkers_look);
			braddock_stop = true;
		}
		
		if ((!walk2_stop) && (GetDistance(ivwalk2,"walk2_stop") < 8))
		{
			Stop(ivwalk2);
			LookAt(ivwalk2,walkers_look);
			walk2_stop = true;
		}

		if ((!settime_reset_walks) && (walk1_stop) && (walk2_stop) && (braddock_stop))
		{
			reset_walkstime = (GetTime() + 15);
			settime_reset_walks = true;
		}

		if ((!reset_walks) && (reset_walkstime < GetTime()))
		{
			Stop(braddock,0);
			Stop(ivwalk1,0);
			Stop(ivwalk2,0);
			SetIndependence(braddock,1);
			SetIndependence(ivwalk1,1);
			SetIndependence(ivwalk2,1);
			done_controlling_walks = true;
			reset_walks = true;
		}
	}

	
	if (!walker_cin_over)
	{
		if (!walker_shot1)
		{
			if (!walker_rdycam1)
			{
				CameraReady();
				walker_shot1_overtime = (GetTime() + 18);
				cinvo1time = (GetTime() + 10);
				walker_rdycam1 = true;
			}
				
			CameraObject(ivwalk2,-10,20,-10,braddock);

			if ((walker_shot1_overtime < GetTime()))
			{
				walker_shot1 = true;
			}
		
		}
		
		//cin vo
		if ((!cinvo1) && (cinvo1time < GetTime()))
		{
			msgcin1 = AudioMessage("CinSc0401.wav");
			cinvo1 = true;
		}


		if ((!walker_shot2) && (walker_shot1))
		{
			if (!walker_shot2_settime)
			{
				walker_shot2_overtime = (GetTime() + 19);
				Patrol(end_tank1,"end_tank1path");
				Patrol(end_tank2,"end_tank2path");
				walker_shot2_settime = true;
			}

			CameraPath("walker_shot2_path",600,100,machine);

			if ((walker_shot2_overtime < GetTime()))
			{
				CameraFinish();
				walker_cin_over = true;
				walker_shot2 = true;
			}		
		}

		if (CameraCancelled())
		{
			if ((cinvo1) && (!IsAudioMessageDone(msgcin1)))
			{
				StopAudioMessage(msgcin1);
			}
		
			Patrol(end_tank1,"end_tank1path");
			Patrol(end_tank2,"end_tank2path");
			CameraFinish();
			walker_cin_over = true;
		}
	}

	if ((!missionstart) && (walker_cin_over))
	{
		SetScrap(1,20);
		SetPlan("scion0701.aip",3);
		vo1time = (GetTime() + 4);
		Ally(2,3);
		SetSkill(tank1,1);
		SetSkill(tank2,1);
		SetSkill(tank3,1);
		SetSkill(tank4,2);
		SetSkill(ivwalk1,2);
		SetSkill(braddock,3);
		SetSkill(ivwalk2,2);
		Patrol(tank1,"tank1patrol");
		Patrol(tank2,"tank2patrol");
		Patrol(tank3,"tank3patrol");
		Patrol(tank4,"tank4patrol");
		Patrol(tank5,"tank5patrol");
		Patrol(tank6,"tank6patrol");
		Patrol(tank7,"tank7patrol");
		Patrol(rover1,"rover1path");
		Patrol(rover6,"rover6path");
		Patrol(rover2a,"rover2path");	
		Follow(rover2b,rover2a);
		Patrol(rover3,"rover3path");
		Patrol(rover4,"rover4path");
		Patrol(rover5,"rover5path");
		SetMaxHealth(machine,999999);
		SetCurHealth(machine,999999);
	    base_attack1time = (GetTime() + 150);
	    base_attack2time = (GetTime() + 300);
	    base_attack3time = (GetTime() + 450);
		missionstart = true;
	}

	if ((!vo1) && (vo1time < GetTime()))
	{
		msg1 = AudioMessage("scion0701.wav"); //scion0701.wav //the best place to start is with the biometal pools...
		vo1 = true;
	}

	/////////////////////////////
	////////////////////////////
	//GETTING POOL1
	if ((!obj1) && (vo1) && (IsAudioMessageDone(msg1)))
	{
		ClearObjectives();
		AddObjective("scion0701.otf", WHITE); //take over biopool
		nav1 = BuildObject("ibnav",1,"nav1");
		SetObjectiveOn(nav1);
		TranslateString2(tempstr, sizeof(tempstr), "MissionS0701");  // Biometal 1 		
		SetObjectiveName(nav1,tempstr);
		obj1 = true;
	}

	if ((!pool1taken) && (obj1) && (!IsAround(tank1) && (!IsAround(tank2) && (!IsAround(ivscav1)))))
	{
		vo2time = (GetTime() + 3);
		pool1taken = true;
	}
	//when player has taken the pool
	if ((!vo2) && (vo2time < GetTime()))
	{
		msg2 = AudioMessage("scion0702.wav"); //scion0702.wav Nice job.  Get an extractor out there ASAP
		vo2 = true;
	}

	if ((!obj2) && (vo2) && (IsAudioMessageDone(msg2)))
	{
		ClearObjectives();
		AddObjective("scion0702.otf", WHITE); //put extractor on biopool
		obj2 = true;
	} 

//checking when the player has deployed a scav at pool1
	if ((!extractor1_deployed) && (vo2) && (IsAround(extractor1) && 
	   (GetDistance(extractor1,"pool1") < 25)))
	{
		vo3time = (GetTime() + 3);
		extractor1_deployed = true;
	}

	if ((!vo3) && (vo3time < GetTime()))
	{
		msg3 = AudioMessage("scion0703.wav");//scion0703 Good.  I'm giving you the location of another pool...
	//	SetPlan("scion0702.aip",3);
		vo3 = true;
	}

	///THIS CONTROLS THE TIMED ATTACKS ON PLAYER'S SCAVENGER AT POOL 1
	if (extractor1_deployed)
	{
		if (!settimes_pool1)
		{
			pool1guarda_attacktime = (GetTime() + 300);
			pool1guardb_attacktime = (GetTime() + 600);	
			pool1guarda_attack = false;
			pool1guardb_attack = false;
			settimes_pool1 = true;
		}

		if ((!pool1guarda_attack) && (pool1guarda_attacktime < GetTime()))
		{
			pool1guarda = BuildObject("ivscout",2,"pool1guarda");
			SetSkill(pool1guarda,0);
			Goto(pool1guarda,"pool1");
			pool1guarda_attack = true;
		}

		if ((!pool1guardb_attack) && (pool1guardb_attacktime < GetTime()))
		{
			pool1guardb = BuildObject("ivtank",2,"pool1guardb");
			SetSkill(pool1guardb,0);
			Goto(pool1guardb,"pool1");
			settimes_pool1 = false;
			pool1guardb_attack = true;
		}


	}

	/////////////////////////////
	////////////////////////////
	//GETTING POOL2
	if ((!obj3) && (vo3) && (IsAudioMessageDone(msg3)))
	{
		ClearObjectives();
		AddObjective("scion0703.otf", WHITE);// take out pool
		SetObjectiveOff(nav1);
		nav2 = BuildObject("ibnav",1,"nav2");
		SetObjectiveOn(nav2);
		TranslateString2(tempstr, sizeof(tempstr), "MissionS0702");  // Biometal 2
		SetObjectiveName(nav2,tempstr);
		obj3 = true;
	}

	if ((!pool2taken) && (obj3) && (!IsAround(tank3) && (!IsAround(tank4) && (!IsAround(ivscav2)))))
	{
		vo2btime = (GetTime() + 3);
		pool2taken = true;
	}

	if ((!vo2b) && (vo2btime < GetTime()))
	{
		msg2b = AudioMessage("scion0712.wav"); //scion0702.wav Again, set up your extractor and put defensive units around the pool	
		vo2b = true;
	}

	if ((!obj2b) && (vo2b) && (IsAudioMessageDone(msg2b)))
	{
		ClearObjectives();
		AddObjective("scion0702.otf", WHITE); //put extractor on biopool
		obj2b = true;
	}

	if ((!extractor2_deployed) && (vo2b) &&  
	   (GetDistance(extractor1,"pool2") < 25))
	{
		vo4time = (GetTime() + 3);
		extractor2_deployed = true;
	}

	if ((!vo4) && (vo4time < GetTime()))
	{
		msg4 = AudioMessage("scion0704.wav"); //scion0703 Good ...there's one more pool
		SetObjectiveOff(nav2);
	//	SetPlan("scion0703.aip",3);
		vo4 = true;	
	}

	///THIS CONTROLS THE TIMED ATTACKS ON PLAYER'S SCAVENGER AT POOL 2
	if (extractor2_deployed)
	{
		if (!settimes_pool2)
		{
			pool2guarda_attacktime = (GetTime() + 300);
			pool2guardb_attacktime = (GetTime() + 600);	
			pool2guarda_attack = false;
			pool2guardb_attack = false;
			settimes_pool2 = true;
		}

		if ((!pool2guarda_attack) && (pool2guarda_attacktime < GetTime()))
		{
			pool2guarda = BuildObject("ivscout",2,"pool2guarda");
			SetSkill(pool2guarda,0);
			Goto(pool2guarda,"pool2");
			pool2guarda_attack = true;
		}

		if ((!pool2guardb_attack) && (pool2guardb_attacktime < GetTime()))
		{
			pool2guardb = BuildObject("ivtank",2,"pool2guardb");
			SetSkill(pool2guardb,0);
			Goto(pool2guardb,"pool2");
			settimes_pool2 = false;
			pool2guardb_attack = true;
		}
	}



	/////////////////////////////
	////////////////////////////
	//GETTING POOL3
	if ((!obj3b) && (vo4) && (IsAudioMessageDone(msg4)))
	{
		ClearObjectives();
		AddObjective("scion0703.otf", WHITE);// gain control of pool
		nav3 = BuildObject("ibnav",1,"nav3");
		SetObjectiveOn(nav3);
		TranslateString2(tempstr, sizeof(tempstr), "MissionS0703");  // Biometal 3
		SetObjectiveName(nav3,tempstr);
		obj3b = true;
	}

	if ((!pool3taken) && (vo4) && (!IsAround(tank5) && (!IsAround(tank6) 
		&& (!IsAround(tank7) && (!IsAround(ivscav3))))))
	{
		vo2ctime = (GetTime() + 3);
		pool3taken = true;
	}

	if ((!vo2c) && (vo2ctime < GetTime()))
	{
		msg2c = AudioMessage("scion0713.wav"); //scion0713.wav Get an extractor out there!		
		vo2c = true;
	}
	
	if ((!obj2c) && (vo2c) && (IsAudioMessageDone(msg2c)))
	{
		ClearObjectives();
		AddObjective("scion0702.otf", WHITE); //put extractor on biopool
		obj2c = true;
	}

	if ((!extractor3_deployed) && (vo2c) &&  
	   (GetDistance(extractor1,"pool3") < 25))
	{
		vo5time = (GetTime() + 3);
		extractor3_deployed = true;
	}

	///THIS CONTROLS THE TIMED ATTACKS ON PLAYER'S SCAVENGER AT POOL 3
	if (extractor3_deployed)
	{
		if (!settimes_pool3)
		{
			pool3guarda_attacktime = (GetTime() + 300);
			pool3guardb_attacktime = (GetTime() + 600);	
			pool3guarda_attack = false;
			pool3guardb_attack = false;
			settimes_pool3 = true;
		}

		if ((!pool3guarda_attack) && (pool3guarda_attacktime < GetTime()))
		{
			pool3guarda = BuildObject("ivscout",2,"pool3guarda");
			SetSkill(pool3guarda,0);
			Goto(pool3guarda,"pool3");
			pool3guarda_attack = true;
		}

		if ((!pool3guardb_attack) && (pool3guardb_attacktime < GetTime()))
		{
			pool3guardb = BuildObject("ivtank",2,"pool3guardb");
			SetSkill(pool3guardb,0);
			Goto(pool3guardb,"pool3");
			settimes_pool3 = false;
			pool3guardb_attack = true;
		}
	}

	if ((!vo5) && (vo5time < GetTime()))
	{
		msg5 = AudioMessage("scion0705.wav"); //scion0705.wav Ok Cook, now just try to hold onto those Biometal pools.  The ISDF should be significanlty weakened now.  The only thing standing between us and the machine now is the ISDF base.  I'm giving you the coordinates, that base must be destroyed.
	//	SetPlan("scion0704.aip",3);
		SetObjectiveOff(nav3);
		vo5 = true;	
	}

	
	///////BASE DESTROYING TIME
	if ((!obj5) && (vo5) && (IsAudioMessageDone(msg5)))
	{
		ClearObjectives();
		AddObjective("scion0705.otf", WHITE); //Destroy the ISDF base.
		nav4 = BuildObject("ibnav",1,"nav4");
		SetObjectiveOn(nav4);
		TranslateString2(tempstr, sizeof(tempstr), "MissionS0704");  // ISDF Base
		SetObjectiveName(nav4,tempstr);
		obj5 = true;
	}

	if ((!isdfbasekilled) && (vo5) && (!IsAround(ibrecy1)))
	{
		vo6time = (GetTime() + 3);
		SetObjectiveOff(nav4);
		isdfbasekilled = true;
	}

	if ((!vo6) && (vo6time < GetTime()))
	{
		AudioMessage("scion0706.wav"); //scion0706.wav Good job, you've knocked the base out of commision!
		vo7time = (GetTime() + 10);
		vo6 = true;
	}

	if ((!vo7) && (vo7time < GetTime()))
	{
		msg7 = AudioMessage("scion0707.wav"); //scion0707.wav Ok Cook, the last thing we need to do is secure the machine area.  Go to the machine and be sure there are no ISDF about.
		vo7 = true;
	}

	if ((!obj6) && (vo7) && (IsAudioMessageDone(msg7)))
	{
		ClearObjectives();
		AddObjective("scion0706.otf", WHITE); //Secure the Machine area.
		SetObjectiveOff(nav4);
		SetObjectiveOn(braddock);
		SetObjectiveName(braddock,"Braddock");
		obj6 = true;
	}

	/////MACHINE AREA SEQUENCE WITH BRADDOCK

	if ((!playeratmachine) && (vo7) && (GetDistance(player,braddock) < 500))
	{
	//	Goto(braddock,"braddockpath");
		vo8time = (GetTime() +5);
		playeratmachine = true;
	}


		if ((!vo8) && (vo8time < GetTime()))
		{
			AudioMessage("scion0708.wav"); //scion0708.wav - BRADDOCK: You may be a hero to these mutated freaks....
			vo8 = true;
		}

		//when player does certain damage to braddock, he taunts
		if ((!vo10) && (GetCurHealth(braddock) < 6000))
		{
			AudioMessage("scion0710.wav"); //You think you can beat me at my own game?
			vo10 = true;
		}

		//when braddock dies, he says a mean thing to the player
		if ((!vo11) && (GetCurHealth(braddock) < 10))
		{
			AudioMessage("scion0711.wav"); // Damned Scion!
			vo11 = true;
		}
		
		//when player kills everything around machine
		if ((!machineclear) &&  (!IsAlive(braddock) &&
			(!IsAlive(ivwalk1)) && (!IsAlive(ivwalk2))))
		{
			vo9time = (GetTime() + 4);
			machineclear = true;
		}

		if ((!vo9) && (vo9time < GetTime()))
		{
			msg9 = AudioMessage("scion0709.wav"); //scion0709.wav The machine area is clear.  Great job Cook.  Stand by while we move in with a Hauler and activate the machine.
			vo9 = true;
		}
	

	///Braddock dead, mission won
	if ((!obj7) && (vo9) && (IsAudioMessageDone(msg9)))
	{
		SucceedMission(GetTime() + 12);
		ClearObjectives();
		AddObjective("scion0707.otf", WHITE); //MISSION ACCOMPLISHED
		obj7 = true;
	}



	/////////AIP CONTROLS
	//TURRET1
	if ((!checkturret1alive) && (IsAlive(turret1)))	
	{
		turret1movetime = (GetTime() + 2);
		turret1alive = true;
		checkturret1alive = true;
		checkturret1dead = false;
		turret1go = false;
	}

	if ((!checkturret1dead) && (!IsAlive(turret1)))
	{
		turret1alive = false;
		checkturret1alive = false;
		checkturret1dead = true;
	}

	if ((!turret1go) && (turret1alive) && (turret1movetime < GetTime()))
	{
		Goto(turret1,"turret1point");
		turret1go = true;
	}

////TURRET 2
	if ((!checkturret2alive) && (IsAlive(turret2)))	
	{
		turret2movetime = (GetTime() + 2);
		turret2alive = true;
		checkturret2alive = true;
		checkturret2dead = false;
		turret2go = false;
	}

	if ((!checkturret1dead) && (!IsAlive(turret2)))
	{
		turret2alive = false;
		checkturret2alive = false;
		checkturret2dead = true;
	}

	if ((!turret2go) && (turret2alive) && (turret2movetime < GetTime()))
	{
		Goto(turret2,"turret2point");
		turret2go = true;
	}

////BASETANK1
	if ((!checkbasetank1alive) && (IsAlive(basetank1)))	
	{
		basetank1alive = true;
		basetank1movetime = (GetTime() + 2);
		checkbasetank1alive = true;
		checkbasetank1dead = false;
		basetank1go = false;
	}

	if ((!checkbasetank1dead) && (!IsAlive(basetank1)))
	{
		basetank1alive = false;
		checkbasetank1alive = false;
		checkbasetank1dead = true;
	}

	if ((!basetank1go) && (basetank1alive) && (basetank1movetime < GetTime()))
	{
		Goto(basetank1,"basetank1point");
		basetank1go = true;
	}

///BASETANK2
	if ((!checkbasetank2alive) && (IsAlive(basetank2)))	
	{
		basetank2movetime = (GetTime() + 2);
		basetank2alive = true;
		checkbasetank2alive = true;
		checkbasetank2dead = false;
		basetank2go = false;
	}

	if ((!checkbasetank2dead) && (!IsAlive(basetank2)))
	{
		basetank2alive = false;
		checkbasetank2alive = false;
		checkbasetank2dead = true;
	}

	if ((!basetank2go) && (basetank2alive) && (basetank2movetime < GetTime()))
	{
		Goto(basetank2,"basetank2point");
		basetank2go = true;
	}

	//if the player's recycler is ever destroyed--MISSION FAILED
	if ((!playersrecy_dead) && (!IsAround(playersrecy)))
	{
		vo_recydeadtime = (GetTime() + 3);
		playersrecy_dead = true;
	}

	if ((!vo_recydead) && (vo_recydeadtime < GetTime()))
	{
		vofail1 = AudioMessage("scion0799.wav"); 	//Dammit cooke, the recycler has been destroyed
		vo_recydead = true;
	}

	if ((!obj8) && (vo_recydead) && (IsAudioMessageDone(vofail1)))
	{
		ClearObjectives();
		AddObjective("scion0708.otf", WHITE);
		FailMission(GetTime() + 6,"scion07L1.txt");  
		obj8 = true;
	}


		//Timed attacks on the player's base
	if (!timed_attacks_over)
	{
		if ((!base_attack1) && (base_attack1time < GetTime()))
		{
			 attacker1 = BuildObject("ivscout",2,"base_attacker1");	
			 attacker2 = BuildObject("ivscout",2,"base_attacker2");
			 Goto(attacker1,playersrecy);
			 Goto(attacker2,playersrecy);
			 SetAvoidType(attacker1,0);
			 SetAvoidType(attacker2,0);
			 SetSkill(attacker1,1);
			 SetSkill(attacker2,1);
			 base_attack1 = true;
		}
	
		if ((!base_attack2) && (base_attack2time < GetTime()))
		{
			 attacker3 = BuildObject("ivtank",2,"base_attacker1");	
			 attacker4 = BuildObject("ivmbike",2,"base_attacker2");
			 Goto(attacker3,playersrecy);
			 Goto(attacker4,playersrecy);
			 SetAvoidType(attacker3,0);
			 SetAvoidType(attacker4,0);
			 SetSkill(attacker3,1);
			 SetSkill(attacker4,2);
			 base_attack2 = true;
		}	

		if ((!base_attack3) && (base_attack3time < GetTime()))
		{
			 attacker5 = BuildObject("ivtank",2,"base_attacker1");	
			 attacker5b = BuildObject("ivtank",2,"base_attacker2");	
			 Goto(attacker5,playersrecy);
			 Goto(attacker5b,playersrecy);
			 SetAvoidType(attacker5,0);
			 SetAvoidType(attacker5b,0);
			 SetSkill(attacker5,2);
			 SetSkill(attacker5b,2);
		     base_attack1time = (GetTime() + 175);
			 base_attack2time = (GetTime() + 325);
		     base_attack3time = (GetTime() + 475);
			 base_attack1 = false;
			 base_attack2 = false;
		}
	}
	/*
	//BASESCOUT1
	if ((!checkbasescout1alive) && (IsAlive(basescout1)))	
	{
		basescout1movetime = (GetTime() + 2);
		basescout1alive = true;
		checkbasescout1alive = true;
		checkbasescout1dead = false;
		basescout1go = false;
	}

	if ((!checkbasescout1dead) && (!IsAlive(basescout1)))
	{
		basescout1alive = false;
		checkbasescout1alive = false;
		checkbasescout1dead = true;
	}

	if ((!basescout1go) && (basescout1alive) && (basescout1movetime < GetTime()))
	{
		Goto(basescout1,"pool1");
		basescout1go = true;
	}

//BASESCOUT2

	if ((!checkbasescout2alive) && (IsAlive(basescout2)))	
	{
		basescout2movetime = (GetTime() + 2);
		basescout2alive = true;
		checkbasescout2alive = true;
		checkbasescout2dead = false;
		basescout2go = false;
	}

	if ((!checkbasescout2dead) && (!IsAlive(basescout2)))
	{
		basescout2alive = false;
		checkbasescout2alive = false;
		checkbasescout2dead = true;
	}

	if ((!basescout2go) && (basescout2alive) && (basescout2movetime < GetTime()))
	{
		Goto(basescout2,"pool2");
		basescout2go = true;
	}

//BASESCOUT3
	if ((!checkbasescout3alive) && (IsAlive(basescout3)))	
	{
		basescout3movetime = (GetTime() + 2);
		basescout3alive = true;
		checkbasescout3alive = true;
		checkbasescout3dead = false;
		basescout3go = false;
	}

	if ((!checkbasescout3dead) && (!IsAlive(basescout3)))
	{
		basescout3alive = false;
		checkbasescout3alive = false;
		checkbasescout3dead = true;
	}

	if ((!basescout3go) && (basescout3alive) && (basescout3movetime < GetTime()))
	{
		Goto(basescout3,"pool3");
		basescout3go = true;
	}
	*/

}


