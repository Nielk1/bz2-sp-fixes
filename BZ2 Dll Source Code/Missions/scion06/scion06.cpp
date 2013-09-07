//At the end of mission, you can win, and then blow up the crystal and lose also.  Put in conditions for this!!!!!!

#include "..\Shared\SPMission.h"

class scion06 : public SPMission 
{
public:
	scion06(void)
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
		missionstart,
		powerout,vo1,vo2,
		obj1,obj2,obj3,vo3,
		base_repaired,repairs_started,vo4,spawn1,spawn2,spawn3,spawn4,spawn5,spawn6,
		spawn7,spawn8,spawn9,spawn10,
		repairtakingtoolong,basekilled,vo6,vo7,convoymove,
		escort1close,escort1farahead,convoy_enroute,convoykilled,tugretreat,
		convoyattack,vo9,obj4,escortsdead,tugdead,tugdead_escortsalive,
		escortsdead_tugalive,vo10,vo11,convoy_dead,vo12,obj5,powerdead,vo13,obj6,
		convoy1toofar,convoy2toofar,convoy3toofar,convoy4toofar,convoy1close,
		convoy2close,convoy3close,convoy4close,
		checkbasetank1alive,basetank1alive,checkbasetank1dead,basetank1go,
		checkbasetank2alive,basetank2alive,checkbasetank2dead,basetank2go,
		checkbasetank3alive,basetank3alive,checkbasetank3dead,basetank3go,
		factkilled,pgen1killed,vo14,obj7,vo15,obj7b,pgen2killed,vo15b,obj7c,wavesover,
		playersrecy_dead,vo_recydead,obj8,repairtakingtoolong2,repairtakingtoolong3,
		repairs_took_forever,
		checkass1alive,ass1alive,checkass1dead,ass1go,
		checkass2alive,ass2alive,checkass2dead,ass2go,
		vo1a,
		bomb_dropped,
		b_last;

	// floats
	float
		f_first,
		vo1time,vo_recydeadtime,
		vo2time,
		vo3time,
		vo6time,
		vo7time,
		spawn1time,
		spawn2time,
		spawn3time,
		spawn4time,
		spawn5time,		
		spawn6time,		
		spawn7time,		
		spawn8time,		
		spawn9time,		
		spawn10time,		
		repairtime,
		convoymovetime,
		tugretreattime,
		vo9time,
		vo10time,
		vo11time,
		vo12time,
		vo13time,
		turret1movetime,
		basetank1movetime,
		basetank2movetime,
		basetank3movetime,
		vo15time,
		vo14time,
		vo15btime,
		vo16time,vo17time,
		repeat_spawntime,
		ass1movetime,
		ass2movetime,
		swap_aiptime,
		
		f_last;

	// handles
	Handle
		h_first,
		enemyrecy,
		player,
		pgen1,
		pgen2,
		msg1,
		msg2,msg3,msg9,
		playersrecy,playersfact,playerspgen1,playerspgen2,
		spawner1a,spawner1b,spawner2a,spawner2b,spawner3a,spawner3b,
		power,convoy_tug1,convoy_scout1,convoy_scout2,convoy_sent1,convoy_sent2,
		msg8,turret1,basetank1,basetank2,basetank3,
		msg7,msg12,msg13,
		checkturret1alive,turret1alive,checkturret1dead,turret1go,enemyfact,
		spawner4a,spawner4b,spawner5a, spawner5b,spawner6a,spawner6b,
		spawner7a,spawner8a,spawner9a,spawner10a,msg14,msg15,msg15b,vofail1,
		spawner7b,pete,repeat,msg17,ass1,ass2,
		spawner8b,spawner8c,spawner9b,spawner9c,spawner10b,spawner10c,
		nav1,repeat2,msg1a,
		spawner1c,spawner1d,spawner2c,spawner2d,spawner3c,spawner3d,spawner4c,spawner4d,
		spawner5c,spawner5d,spawner6c,spawner6d,spawner7c,spawner7d,spawner8d,
		spawner9d,spawner10d,
		h_last;


	// integers
	int
		i_first,


		i_last;
};
DLLBase * BuildMission(void)
{
	return new scion06();
}

void scion06::Setup(void)
{
	SetAutoGroupUnits(false);
/*
	Here's where you set the values at the start.  
*/

//  bools
	missionstart = false;
	powerout = false;
	vo1 = false;
	vo2 = false;
	obj1 = false;
	base_repaired = false;
	obj2 = false;
	vo3 = false;
	repairs_started = false;
	vo4 = false;
	spawn1 = false;
	spawn2 = false;
	spawn3 = false;
	spawn4 = false;
	spawn5 = false;	
	spawn6 = false;	
	spawn7 = false;	
	spawn8 = false;	
	spawn9 = false;	
	spawn10 = false;	
	vo14 = false;
	repairtakingtoolong = false;
	basekilled = false;
	vo6 = false;
	vo7 = false;
	obj3 = false;
	convoymove = false;
	convoy_enroute = false;
	convoykilled = false;
	convoyattack = false;
	tugretreat = false;
	vo9 = false;
	obj4 = false;
	escortsdead = false;
	tugdead = false;
	tugdead_escortsalive = false;
	escortsdead_tugalive = false;
	vo10 = false;
	vo11 = false;
	convoy_dead = false;
	vo12 = false;
	obj5 = false;
	powerdead = false;
	vo13 = false;
	obj6 = false;
	convoy1toofar = false;
	convoy2toofar = false;
	convoy3toofar = false;
	convoy4toofar = false;
	convoy1close = false;
	convoy2close = false;
	convoy3close = false;
	convoy4close = false;
	checkturret1alive = false;
	turret1alive = false;
	checkturret1dead = false;
	turret1go = false;
	checkbasetank1alive = false;
	basetank1alive = false;
	checkbasetank1dead = false;
	basetank1go = false;
	checkbasetank2alive = false;
	basetank2alive = false;
	checkbasetank2dead = false;
	basetank2go = false;
	checkbasetank3alive = false;
	basetank3alive = false;
	checkbasetank3dead = false;
	basetank3go = false;
	factkilled = false;
	pgen1killed = false;
	pgen2killed = false;
	obj7 = false;
	vo15 = false;
	obj7b = false;
	vo15b = false;
	obj7c = false;
	wavesover = false;
	playersrecy_dead = false;
	vo_recydead = false;
	obj8 = false;
	repairtakingtoolong2 = false;
	repairs_took_forever = false;
	checkass1alive = false;
	ass1alive = false;
	checkass1dead = false;
	ass1go = false;
	checkass2alive = false;
	ass2alive = false;
	checkass2dead = false;
	ass2go = false;
	vo1a = false;
	bomb_dropped = false;



//  floats
	vo1time = 999999.9f;
	vo2time = 999999.9f;
	vo3time = 999999.9f;
	vo6time = 999999.9f;
	vo7time = 999999.9f;
	spawn1time = 999999.9f;	
	spawn2time = 999999.9f;	
	spawn3time = 999999.9f;	
	spawn4time = 999999.9f;
	spawn5time = 999999.9f;
	spawn6time = 999999.9f;
	spawn7time = 999999.9f;
	spawn8time = 999999.9f;
	spawn9time = 999999.9f;
	spawn10time = 999999.9f;
	repairtime = 999999.9f;	
	convoymovetime = 999999.9f;	   
	tugretreattime = 999999.9f;
	vo9time = 999999.9f;
	vo10time = 999999.9f;
	vo11time = 999999.9f;
	vo12time = 999999.9f;
	vo13time = 999999.9f;
	turret1movetime = 999999.9f;
	basetank1movetime = 999999.9f;
	basetank2movetime = 999999.9f;
	basetank3movetime = 999999.9f;
	vo14time = 999999.9f;
	vo15time = 999999.9f;
	vo15btime = 999999.9f;
	vo_recydeadtime = 999999.9f;
	repeat_spawntime = 999999.9f;
	vo16time = 999999.9f;
	vo17time = 999999.9f;
	ass1movetime = 999999.9f;
	ass2movetime = 999999.9f;
	swap_aiptime = 999999.9f;
//  handles
	enemyrecy = GetHandle("enemyrecy");
	enemyfact = GetHandle("enemyfact");
	playersrecy = GetHandle("playersrecy");
	pgen1 = GetHandle("pgen1");
	pgen2 = GetHandle("pgen2");
	power = GetHandle("power");
	convoy_tug1 = GetHandle("convoy_tug1");
	convoy_scout1 = GetHandle("convoy_scout1");
	convoy_scout2 = GetHandle("convoy_scout2");
	convoy_sent1 = GetHandle("convoy_sent1");
	convoy_sent2 = GetHandle("convoy_sent2");
	playersfact = GetHandle("playersfact");
	playerspgen1 = GetHandle("playerspgen1");
	playerspgen2 = GetHandle("playerspgen2");
	spawner7b = NULL;
	msg15b = NULL;
	player = NULL;
	msg1 = NULL;
	msg2 = NULL;
	msg3 = NULL;
	msg7 = NULL;
	msg8 = NULL;
	msg9 = NULL;
	msg12 = NULL;
	msg13 = NULL;
	spawner1a= NULL;
	spawner1b = NULL;
	spawner2a = NULL;
	spawner2b = NULL;
	spawner3a = NULL;
	spawner3b = NULL;
	spawner4a = NULL;
	spawner4b = NULL;
	spawner5a = NULL;
	spawner5b = NULL;
	spawner6a = NULL;
	spawner6b = NULL;
	msg14 = NULL;
	msg15 = NULL;
	turret1 = NULL;
	basetank1 = NULL;
	basetank2 = NULL;
	basetank3 = NULL;
	spawner7a = NULL;
	spawner8a = NULL;
	spawner8b = NULL;
	spawner8c = NULL;
	spawner9a = NULL;
	spawner9b = NULL;
	spawner9c = NULL;
	spawner10a = NULL;
	spawner10b = NULL;
	spawner10c = NULL;
	spawner1c = NULL;
	spawner1d = NULL;
	spawner2c = NULL;
	spawner2d = NULL;
	spawner3c = NULL;
	spawner3d = NULL;
	spawner4c = NULL;
	spawner4d = NULL;
	spawner5c = NULL;
	spawner5d = NULL;
	spawner6c = NULL;
	spawner6d = NULL;
	spawner7c = NULL;
	spawner7d = NULL;

	spawner8d = NULL;

	spawner9d = NULL;

	spawner10d = NULL;

	vofail1 = NULL;
	pete = NULL;
	repeat = NULL;
	nav1 = NULL;
	msg17 = NULL;
	ass1 = NULL;
	ass2 = NULL;
	repeat2 = NULL;
	msg1a = NULL;

//  integers
	SetTeamColor(2,0,127,255);  //BRADDOCK	
	SetTeamColor(3,85,255,85); //REBELS
	SetTeamColor(4,0,127,255);  //BRADDOCK	



}

void scion06::AddObject(Handle h)
{
	char ODFName[64];
	GetObjInfo(h, Get_CFG, ODFName);

	if (missionstart)
	{
		if ((IsOdf2(h,"apwrck") && (GetTeamNum(h) == 2)))
		{
			bomb_dropped = true;
		}
		

		if ((turret1 == NULL) && (GetTeamNum(h) == 2) && (GetDistance(h,enemyrecy) < 50)
		&& (IsOdf2(h,"ivturr")))
		{
			turret1 = h;
		}
	
		if ((basetank1 == NULL) && (GetTeamNum(h) == 2) && (GetDistance(h,enemyfact) < 50)
		&& (IsOdf2(h,"ivtank")))
		{
			basetank1 = h;
		}

		else if ((basetank2 == NULL) && (GetTeamNum(h) == 2) && (GetDistance(h,enemyfact) < 50)
		&& (IsOdf2(h,"ivtank")))
		{
			basetank2 = h;
		}

		else if ((basetank3 == NULL) && (GetTeamNum(h) == 2) && (GetDistance(h,enemyfact) < 50)
		&& (IsOdf2(h,"ivtank")))
		{
			basetank3 = h;
		}

		else if ((ass1 == NULL) && (GetTeamNum(h) == 2) && (GetDistance(h,enemyfact) < 50)
		&& (IsOdf2(h,"ivatank")))
		{
			ass1 = h;
		}

		else if ((ass2 == NULL) && (GetTeamNum(h) == 2) && (GetDistance(h,enemyfact) < 50)
		&& (IsOdf2(h,"ivatank")))
		{
			ass2 = h;
		}
	}
}

bool scion06::PostLoad(bool missionSave)
{
	bool ret = SPMission::PostLoad(missionSave);

	if (missionSave)
		return ret;

	SetTeamColor(2,0,127,255);  //BRADDOCK		
	SetTeamColor(4,0,127,255);  //BRADDOCK	
	SetTeamColor(3,85,255,85); //REBELS	

	return ret;
}
 
void scion06::Execute(void)
{
/*
	Here is where you put what happens every frame.  
*/
	player = (GetPlayerHandle());
	char tempstr[128];

	if (!missionstart)
	{
		SetScrap(1,40);
		vo1time = (GetTime() + 3);
		Pickup(convoy_tug1,power);
		Ally(2,3);  
		Ally(2,4);
		Ally(3,4);
		SetPlan("scion0601.aip",2); 
		SetMaxHealth(power,10000);
		SetCurHealth(power,10000);

		SetMaxHealth(playersfact,6000);
		SetCurHealth(playersfact,2200);

		SetMaxHealth(playerspgen1,3000);
		SetCurHealth(playerspgen1,1500);
		
		SetMaxHealth(playerspgen2,3000);
		SetCurHealth(playerspgen2,1800);

	//	SetObjectiveOn(enemyrecy);
	//	SetObjectiveName(enemyrecy,"Enemy");
		missionstart = true;
	}

	//controlling bomber AI
	if (bomb_dropped)
	{
		swap_aiptime = (GetTime() + 120); //250
		bomb_dropped = false;
	}

	if (swap_aiptime < GetTime())
	{
		SetPlan("scion0601.aip",2); 
		swap_aiptime = (GetTime() + 999999.9f);
	}

	if ((!vo1) && (vo1time < GetTime()))
	{
		msg1 = AudioMessage("scion0601.wav"); //scion0601.wav First we must work on getting this base in shape...
		vo1 = true;
	}

	if ((!vo1a) && (vo1) && (IsAudioMessageDone(msg1)))
	{
		msg1a = AudioMessage("scion0601a.wav"); //build a service truck and fix the factory and power generators.
		vo1a = true;
	}

	if ((!obj1) && (vo1a) && (IsAudioMessageDone(msg1a)))
	{
		ClearObjectives();
		AddObjective("scion0601.otf", WHITE);///Make base repairs!
		repairtime = (GetTime() + 550);  //the time for first warning of repairs taking too long
		spawn1time = (GetTime() + 65);
		obj1 = true;
	}

//1st WAVE
	if ((!spawn1) && (spawn1time < GetTime()))
	{
		spawner1a = BuildObject("ivscout",4,"spawn1a");	
		spawner1b = BuildObject("ivscout",4,"spawn2b");	
		SetSkill(spawner1a,1);
		SetSkill(spawner1b,2);
		Goto(spawner1a,"playerbase");
		Goto(spawner1b,"playerbase");
		spawn2time = (GetTime() +160);
		spawn1 = true;
	}
///////
///checking to see when player has started the base repairs

	if (!repairs_started)
	{
		if ((IsAround(playersfact)) && (GetCurHealth(playersfact) > 2250))
		{
			AudioMessage("scion0602.wav"); // scion0602.wav Good.  Continue to build up your forces while waiting for the repairs.
			repairs_started = true;
		}

		if ((IsAround(playerspgen1)) && (GetCurHealth(playerspgen1) > 1550))
		{
			AudioMessage("scion0602.wav"); // scion0602.wav Good.  Continue to build up your forces while waiting for the repairs.
			spawn2time = (GetTime() +25);
			repairs_started = true;
		}

		if ((IsAround(playerspgen2)) && (GetCurHealth(playerspgen2) > 1850))
		{
			AudioMessage("scion0602.wav"); // scion0602.wav Good.  Continue to build up your forces while waiting for the repairs.
			spawn2time = (GetTime() +25);
			repairs_started = true;
		}

	}

	////Checking to see when the repairs are complete
	if ((!base_repaired) && (obj1) && (GetCurHealth(playersfact) > 5900) && 
		(GetCurHealth(playerspgen1) > 2900) && (GetCurHealth(playerspgen2) > 2900))
	{
		vo3time = (GetTime() + 2);
		base_repaired = true;
	}

	//if the repairs seem to be taking too long
	if (!base_repaired)
	{
		if ((!repairtakingtoolong) && (!base_repaired) && (repairtime < GetTime()))
		{
			AudioMessage("scion0605.wav"); //scion0605.wav Those repairs should have been finished by now,  What's going on? 
			vo16time = (GetTime() + 90); //next warning time
			repairtakingtoolong = true;
		}
			//next warning if repairs are still not complete
		if ((!repairtakingtoolong2) && (!base_repaired) && (vo16time < GetTime()))
		{
			AudioMessage("scion0616.wav"); // The base STILL is not fully repaired
			vo17time = (GetTime() + 90);//next warning time (fail mission)
			repairtakingtoolong2 = true;
		}

		if ((!repairtakingtoolong3) && (!base_repaired) && (vo17time < GetTime()))
		{
			msg17 = AudioMessage("scion0617.wav"); //That's it... I'm pissed now, mission over
			repairtakingtoolong3 = true;
		}

		if ((!repairs_took_forever) && (repairtakingtoolong3) && (IsAudioMessageDone(msg17)))
		{
			ClearObjectives();
			AddObjective("scion0607.otf", WHITE);		
			FailMission(GetTime() + 6,"scion06L1.txt");
			repairs_took_forever = true;
		}
	}

	//2nd WAVE
	if ((!spawn2) && (spawn2time < GetTime()))
	{
		spawner2a = BuildObject("ivtank",4,"spawn2a"); 
		SetSkill(spawner2a,1);
		Goto(spawner2a,"playerbase");
		spawn3time = (GetTime() + 140);
		spawn2 = true;	
	}
	///


	//If the factory or the power gens get destroyed before the repairs are complete,
	//the mission is failed
	if (!base_repaired)
	{
		if ((!factkilled) && (!IsAround(playersfact)))
		{
			vo14time = (GetTime() + 3);
			factkilled = true;
		}

		if ((!vo14) && (vo14time < GetTime()))
		{
			msg14 = AudioMessage("scion0614.wav"); // scion0614.wav John, the factory has been destroyed…that was a loss we can't afford, this mission is scrubbed.   
			vo14 = true;
		}

		if ((!obj7) && (vo14) && (IsAudioMessageDone(msg14)))
		{
			ClearObjectives();
			AddObjective("scion0607.otf", WHITE); // Mission Failed.
			FailMission(GetTime() + 5,"scion06L2.txt");
			obj7 = true;
		}
	//****//
		if ((!pgen1killed) && (!IsAround(playerspgen1)))
		{
			vo15time = (GetTime() + 3);
			pgen1killed = true;
		}

		if ((!vo15) && (vo15time < GetTime()))
		{
			msg15 = AudioMessage("scion0615.wav"); // scion0615 John, you let a Power Generator get destroyed…You mustn't let anything happen to these buildings, this mission is scrubbed.  
			vo15 = true;
		}

		if ((!obj7b) && (vo15) && (IsAudioMessageDone(msg15)))
		{
			ClearObjectives();
			AddObjective("scion0607.otf", WHITE); // Mission Failed.
			FailMission(GetTime() + 5,"scion06L2.txt");
			obj7b = true;
		}
	//****//
		if ((!pgen2killed) && (!IsAround(playerspgen2)))
		{
			vo15btime = (GetTime() + 3);
			pgen2killed = true;
		}

		if ((!vo15b) && (vo15btime < GetTime()))
		{
			msg15b = AudioMessage("scion0615.wav"); // scion0615 John, you let a Power Generator get destroyed…You mustn't let anything happen to these buildings, this mission is scrubbed.  
			vo15b = true;
		}

		if ((!obj7c) && (vo15b) && (IsAudioMessageDone(msg15b)))
		{
			ClearObjectives();
			AddObjective("scion0607.otf", WHITE); // Mission Failed.
			FailMission(GetTime() + 5,"scion06L2.txt");
			obj7c = true;
		}
	//****//
	}

	if (!wavesover)
	{
		//3rd WAVE
		if ((!spawn3) && (spawn3time < GetTime()))
		{
			spawner3a = BuildObject("ivtank",4,"spawn3a");
			spawner3b = BuildObject("ivscout",4,"spawn3b");
			SetSkill(spawner3a,1);
			SetSkill(spawner3b,1);
			Goto(spawner3a,"playerbase");
			Goto(spawner3b,"playerbase");
			spawn4time = (GetTime() + 40);
			spawn3 = true;
		}

		//4th wave
		if ((!spawn4) && (spawn4time < GetTime()))
		{
			spawner4a = BuildObject("ivtank",4,"spawn1a");
			spawner4b = BuildObject("ivmbike",4,"spawn1b");
			SetSkill(spawner4a,1);
			SetSkill(spawner4b,1);
			Goto(spawner4a,"playerbase");
			Goto(spawner4b,"playerbase");
			spawn5time = (GetTime() + 90);
			spawn4 = true;
		}

		//5th wave
		if ((!spawn5) && (spawn5time < GetTime()))
		{
			spawner5a = BuildObject("ivtank",4,"spawn3a");
			spawner5b = BuildObject("ivmbike",4,"spawn3b");
			spawner5c = BuildObject("ivtank",4,"spawn4a");

			SetSkill(spawner5a,1);
			SetSkill(spawner5b,1);
			SetSkill(spawner5c,1);
			Goto(spawner5a,"playerbase");
			Goto(spawner5b,"playerbase");
			Goto(spawner5c,"playerbase");
			spawn6time = (GetTime() + 100);
			spawn5 = true;
		}

		//6th wave
		if ((!spawn6) && (spawn6time < GetTime()))
		{
			spawner6a = BuildObject("ivtank",4,"spawn4a");
			spawner6b = BuildObject("ivatank",4,"spawn3b");
			SetSkill(spawner6a,1);
			SetSkill(spawner6b,1);
			Goto(spawner6a,"playerbase");
			Goto(spawner6b,"playerbase");
			spawn7time = (GetTime() + 100);
			spawn6 = true;
		}

		// 7th wave
		if ((!spawn7) && (spawn7time < GetTime()))
		{
			spawner7a = BuildObject("ivatank",4,"spawn1a");
			spawner7b = BuildObject("ivatank",4,"spawn1b");
			spawner7c = BuildObject("ivatank",4,"spawn1b");
			SetSkill(spawner7a,1);
			SetSkill(spawner7b,1);
			SetSkill(spawner7c,2);
			Goto(spawner7a,"playerbase");
			Goto(spawner7b,"playerbase");
			Goto(spawner7c,"playerbase");
			spawn8time = (GetTime() + 120);
			spawn7 = true;
		}

		// 8th wave
		if ((!spawn8) && (spawn8time < GetTime()))
		{
			spawner8a = BuildObject("ivtank",4,"spawn1a");
			spawner8b = BuildObject("ivmbike",4,"spawn4a");
			spawner8c = BuildObject("ivmbike",4,"spawn4b");
			SetSkill(spawner8a,1);
			SetSkill(spawner8b,2);
			SetSkill(spawner8c,2);
			Goto(spawner8a,"playerbase");
			Goto(spawner8b,"playerbase");
			Goto(spawner8c,"playerbase");
			spawn9time = (GetTime() + 150);
			spawn8 = true;
		}

		// 9th wave
		if ((!spawn9) && (spawn9time < GetTime()))
		{
			spawner9a = BuildObject("ivatank",4,"spawn1a");
			spawner9b = BuildObject("ivatank",4,"spawn1b");
			spawner9c = BuildObject("ivmbike",4,"spawn3a");
			SetSkill(spawner9a,1);
			SetSkill(spawner9b,2);
			SetSkill(spawner9c,2);
			Goto(spawner9a,"playerbase");
			Goto(spawner9b,"playerbase");
			Goto(spawner9c,"playerbase");
			spawn10time = (GetTime() + 150);
			spawn9 = true;
		}

		// 10th wave
		if ((!spawn10) && (spawn10time < GetTime()))
		{
			spawner10a = BuildObject("ivatank",4,"spawn1a");
			spawner10b = BuildObject("ivtank",4,"spawn4a");
			spawner10c = BuildObject("ivtank",4,"spawn4b");
			SetSkill(spawner10a,1);
			SetSkill(spawner10b,2);
			SetSkill(spawner10c,1);
			Goto(spawner10a,"playerbase");
			Goto(spawner10b,"playerbase");
			Goto(spawner10c,"playerbase");
			repeat_spawntime = (GetTime() +150);
			spawn10 = true;
			wavesover = true;
		}
	}

	//when main waves are over i will keep sending a couple tanks every few min
	if (!basekilled)
	{
		if (repeat_spawntime < GetTime())
		{
			pete = BuildObject("ivtank",4,"spawn2a");	
			repeat = BuildObject("ivatank",4,"spawn1a");	
			repeat2 = BuildObject("ivatank",4,"spawn1b");	
			SetSkill(pete,1);
			SetSkill(repeat,1);
			SetSkill(repeat2,1);
			Goto(pete,"playerbase");
			Goto(repeat,"playerbase");
			Goto(repeat2,"playerbase");
			repeat_spawntime = (GetTime() + 180);
		}
	}

	////
	//SPAWNS OVER


	if ((!vo3) && (vo3time < GetTime()))
	{
		msg3 = AudioMessage("scion0603.wav"); ///Scion0603.wav Ok the repairs are complete.  Now we should be in good shape for the base assault.  Continue to build your forces, and take out that base!	
		vo3 = true;
	}


	if ((!obj2) && (vo3) && (IsAudioMessageDone(msg3)))
	{
		ClearObjectives();
		AddObjective("scion0602.otf", WHITE);///Destroy Braddock's Base
		nav1 = BuildObject("ibnav",1,"enemybase");
		SetObjectiveOn(nav1);
		TranslateString2(tempstr, sizeof(tempstr), "MissionS0601");  // Braddock's Base		
		SetObjectiveName(nav1,tempstr);
		obj2 = true;
	}

	//when player gets near enemy base
	if ((!vo4) && (obj2) && (GetDistance(player,"enemybase") < 220))
	{
		AudioMessage("scion0604.wav"); //Scion0604.wav Cook go for the power generators, that will buy you some time to take out those guntowers.
		vo4 = true;
	}

//// When braddock's base is KILLED before the convoy gets there
	if ((!basekilled) && (obj2) && (!IsAround(enemyrecy)))
	{
		vo6time = (GetTime() + 4);
		wavesover = true;
		basekilled = true;
	}

	if ((!vo6) && (vo6time < GetTime()))
	{
		AudioMessage("scion0606.wav"); //Scion0606.wav Good job, you've knocked the base out of commission.

		vo7time = (GetTime() + 8);
		vo6 = true;
	}

	if ((!vo7) && (vo7time < GetTime()))
	{
		msg7 = AudioMessage("scion0607.wav"); ///Scion0607.wav It looks like we took out that base just in time, we've just picked up the Evil Scion convoy on radar and they are nearing the base!  Move as many forces to the destroyed base as you can, we must take out that convoy. Remember, do not damage the power source.  (SHAB)
		convoymovetime = (GetTime() + 1);
		vo7 = true;
	}

	if ((!obj3) && (vo7) && (IsAudioMessageDone(msg7)))
	{
		ClearObjectives();
		AddObjective("scion0603.otf", WHITE);///Move forces to destroyed base, intercept Evil Scion convoy
		obj3 = true;
	}

	if ((!convoymove) && (convoymovetime < GetTime()))
	{
		Retreat(convoy_scout1,"convoypath");
		Follow(convoy_scout2,convoy_scout1);
		Retreat(convoy_tug1,"convoypath");
		Follow(convoy_sent1,convoy_tug1);
		Follow(convoy_sent2,convoy_tug1);
		convoymove = true;
	}

	if (!convoy_enroute)
	{
		if ((!escort1farahead) && (GetDistance(convoy_scout1,convoy_tug1) > 100))
		{
			Stop(convoy_scout1);
			Stop(convoy_scout2);
			escort1close = false;
			escort1farahead = true;
		}

		if ((!escort1close) && (escort1farahead) && (GetDistance(convoy_scout1,convoy_tug1) < 90))
		{
			Retreat(convoy_scout1,"convoypath");
			Follow(convoy_scout2,convoy_scout1);		
			escort1close = true;
			escort1farahead = false;
		}

	////When convoy meets player
		if ((GetDistance(player,convoy_scout1) < 200))
		{
			msg8 = AudioMessage("scion0608.wav");  //scion0608.wav EVIL CONVOY:  Squad alpha here, we have the package…Hey wait a minute, those aren't Braddock's forces!  Destroy them!
			convoy_enroute = true;
		}
	}

	if ((!convoyattack) && (convoy_enroute) && (IsAudioMessageDone(msg8)))
	{
		Attack(convoy_scout1,player);
		tugretreattime = (GetTime() + 15);
		convoyattack = true;
	}

	if ((!tugretreat) && (IsAround(convoy_tug1) && (tugretreattime < GetTime())))
	{
		Retreat(convoy_tug1,"tugretreatpath");
		vo9time = (GetTime() + 15);
		tugretreat = true;
	}

	if ((!vo9) && (vo9time < GetTime()))
	{
		msg9 = AudioMessage("scion0609.wav"); // scion0609.wav Cook, the tug is retreating, do not let it get away!!
		vo9 = true;
	}

	if ((!obj4) && (vo9) && (IsAround(convoy_tug1) && (IsAudioMessageDone(msg9))))
	{
		ClearObjectives();
		AddObjective("scion0604.otf", WHITE); //  Do not let the Hauler escape	
		SetObjectiveOn(convoy_tug1);
		obj4 = true;
	}

	//checking to see if escorts dead
	if ((!escortsdead) && (convoymove) && (!IsAround(convoy_scout1) && (!IsAround(convoy_scout2)
		&& (!IsAround(convoy_sent1) && (!IsAround(convoy_sent2))))))
	{
		escortsdead = true;
	}

	//checking to see if tug is killed
	if ((!tugdead) && (convoymove) && (!IsAround(convoy_tug1)))
	{
		tugdead = true;
	}

	//when tug is killed but escorts are still alive
	if ((!tugdead_escortsalive) && (tugdead) && (!escortsdead))
	{
		vo10time = (GetTime() + 3);
		tugdead_escortsalive = true;
	}

	if ((!vo10) && (vo10time < GetTime()))
	{
		AudioMessage("scion0610.wav"); //scion0610 Great Cook, you got the hauler!  Now take care of the rest of the convoy!
		vo10 = true;
	}

	//when escorts are killed but tug is still alive
	if ((!escortsdead_tugalive) && (!tugdead) && (escortsdead))
	{
		vo11time = (GetTime() + 3);
		escortsdead_tugalive = true;	
	}

	if ((!vo11) && (vo11time < GetTime()))
	{
		AudioMessage("scion0611.wav"); //scion0611 Great Cook, you got the escorts.  Now get that tug!
		vo11 = true;	
	}
//////////////////
	//This is telling the escorts to GOTO the player if they get too far away from the player
	if ((!convoy_dead) && (convoyattack))
	{
		////CONVOY1
		if ((!convoy1toofar) && (convoyattack) && (IsAround(convoy_scout1) && 
			(GetDistance(convoy_scout1,player) > 225)))
		{
			Goto(convoy_scout1,player);
			convoy1close = false;
			convoy1toofar = true;
		}

		if ((!convoy1close) && (convoyattack) && (IsAround(convoy_scout1) &&
			(GetDistance(convoy_scout1,player) < 125)))
		{
			convoy1toofar = false;
			convoy1close = true;
		}

				////CONVOY2
		if ((!convoy2toofar) && (convoyattack) && (IsAround(convoy_scout2) && 
			(GetDistance(convoy_scout2,player) > 225)))
		{
			Goto(convoy_scout2,player);
			convoy2close = false;
			convoy2toofar = true;
		}

		if ((!convoy2close) && (convoyattack) && (IsAround(convoy_scout2) &&
			(GetDistance(convoy_scout2,player) < 125)))
		{
			convoy2toofar = false;
			convoy2close = true;
		}

				////CONVOY3
		if ((!convoy3toofar) && (convoyattack) && (IsAround(convoy_sent1) && 
			(GetDistance(convoy_sent1,player) > 225)))
		{
			Goto(convoy_sent1,player);
			convoy3close = false;
			convoy3toofar = true;
		}

		if ((!convoy3close) && (convoyattack) && (IsAround(convoy_sent1) &&
			(GetDistance(convoy_sent1,player) < 125)))
		{
			convoy3toofar = false;
			convoy3close = true;
		}

				////CONVOY4
		if ((!convoy4toofar) && (convoyattack) && (IsAround(convoy_sent2) && 
			(GetDistance(convoy_sent2,player) > 225)))
		{
			Goto(convoy_sent2,player);
			convoy4close = false;
			convoy4toofar = true;
		}

		if ((!convoy4close) && (convoyattack) && (IsAround(convoy_sent2) &&
			(GetDistance(convoy_sent2,player) < 125)))
		{
			convoy4toofar = false;
			convoy4close = true;
		}
/////////////////////////


		//WHEN player kills the entire convoy

		if ((!convoy_dead) && (convoymove) && (!IsAlive(convoy_scout1) && (!IsAlive(convoy_scout2)
			&& (!IsAlive(convoy_sent1) && (!IsAlive(convoy_sent2) && (!IsAlive(convoy_tug1)))))))
		{
			vo12time = (GetTime() + 4);
			convoy_dead = true;
		}
	}

	if ((!vo12) && (vo12time < GetTime()))
	{
		msg12 = AudioMessage("scion0612.wav"); //scion0612 Alright Cook, excellent job.  We will send out a tug and pick up that power source.  Mission Accomplished.
		vo12 = true;
	}

	if ((!obj5) && (vo12) && (IsAudioMessageDone(msg12)))
	{
		ClearObjectives();
		AddObjective("scion0605.otf", WHITE); //mission accomplished
		SucceedMission(GetTime() + 10,"scion06w1.txt");
		obj5 = true;
	}

	//if powersource is destroyed, mission failed
	if ((!powerdead) && (!IsAround(power)))
	{
		vo13time = (GetTime() + 3);
		powerdead = true;
	}

	if ((!vo13) && (!obj5) && (vo13time < GetTime()))
	{
		msg13 = AudioMessage("scion0613.wav"); //Dammit cook, the powersource has been destroyed
		vo13 = true;
	}

	if ((!obj6) && (vo13) && (IsAudioMessageDone(msg13)))
	{
		ClearObjectives();
		AddObjective("scion0606.otf", WHITE); //Mission Failed
		obj6 = true;
	}

	//////HELPING THE AIP

	///TURRET 1
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
		Goto(turret1,"turret1");
		turret1go = true;
	}

///BASETANK1

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
		Patrol(basetank1,"basetank1");
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
		Patrol(basetank2,"basetank2");
		basetank2go = true;
	}

///BASETANK3
	if ((!checkbasetank3alive) && (IsAlive(basetank3)))	
	{
		basetank3movetime = (GetTime() + 2);
		basetank3alive = true;
		checkbasetank3alive = true;
		checkbasetank3dead = false;
		basetank3go = false;
	}

	if ((!checkbasetank3dead) && (!IsAlive(basetank3)))
	{
		basetank3alive = false;
		checkbasetank3alive = false;
		checkbasetank3dead = true;
	}

	if ((!basetank3go) && (basetank3alive) && (basetank3movetime < GetTime()))
	{
		Patrol(basetank3,"basetank3");
		basetank3go = true;
	}

///ASS1
	if ((!checkass1alive) && (IsAlive(ass1)))	
	{
		ass1movetime = (GetTime() + 2);
		ass1alive = true;
		checkass1alive = true;
		checkass1dead = false;
		ass1go = false;
	}

	if ((!checkass1dead) && (!IsAlive(ass1)))
	{
		ass1alive = false;
		ass1alive = false;
		checkass1dead = true;
	}

	if ((!ass1go) && (ass1alive) && (ass1movetime < GetTime()))
	{
		Goto(ass1,"ass1");
		ass1go = true;
	}

///ASS2
	if ((!checkass2alive) && (IsAlive(ass2)))	
	{
		ass2movetime = (GetTime() + 2);
		ass2alive = true;
		checkass2alive = true;
		checkass2dead = false;
		ass2go = false;
	}

	if ((!checkass2dead) && (!IsAlive(ass2)))
	{
		ass2alive = false;
		ass2alive = false;
		checkass2dead = true;
	}

	if ((!ass2go) && (ass2alive) && (ass2movetime < GetTime()))
	{
		Goto(ass2,"ass2");
		ass2go = true;
	}

	//if the player's recycler is ever destroyed--MISSION FAILED
	if ((!playersrecy_dead) && (!IsAround(playersrecy)))
	{
		vo_recydeadtime = (GetTime() + 3);
		playersrecy_dead = true;
	}

	if ((!vo_recydead) && (vo_recydeadtime < GetTime()))
	{
		vofail1 = AudioMessage("scion0699.wav"); 	//Dammit cooke, the recycler has been destroyed
		vo_recydead = true;
	}

	if ((!obj8) && (vo_recydead) && (IsAudioMessageDone(vofail1)))
	{
		ClearObjectives();
		AddObjective("scion0608.otf", WHITE);
		FailMission(GetTime() + 6,"scion06L3.txt");
		obj8 = true;
	}
}
