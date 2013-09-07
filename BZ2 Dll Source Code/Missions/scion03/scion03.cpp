//TODO AIP needs work.  
//TODO Cutomize the AI searcher scouts some way so that they do not objectify distant targets
//TODO Find out why terrain tears when building base
//worked on spawns and made a tank attack the scav pool after the player kills it.  Playtest this!



#include "..\Shared\SPMission.h"

class scion03 : public SPMission 
{
public:
	scion03(void)
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
		b_first,alpha1die,insurance1,
		missionstart,wave1,wave2,wave3,wave4,wave5,checktank1alive,tank1alive,checktank1dead,
		tank1go,checktank2alive,tank2alive,checktank2dead,tank2go,checktank3alive,tank3alive,
		checktank3dead,tank3go,vo1,obj1,powergotten,powerhome,enemyrecydead,vo3,powerdead,
		obj3,vo6,msg6done,vo7,shabsendspilots,vo7done,vo8,vo8done,vo9,vo10,obj5,wavesover,
		vo5,vo9done,obj4,alphamoveout,vo11,vo11done,vo12,vo12done,vo13,vo14,vo13done,playertoofar,
		vo14done,wave2killed,wave3killed,alphadead,kill_alpha,playersrecy_dead,vo_recydead,
		spawner2atoofar,spawner2btoofar,insurance2,
		spawner3atoofar,spawner3btoofar,
		scav_attack,player_took_scav,scav_attacker_dead,
		wave6,wave7,wave8,player_attacked_scouts,
		b_last;

	// floats
	float
		f_first,
		wave1time,wave2time,wave3time,wave4time,wave5time,vo1time,vo3time,vo5time,vo6time,
		convodelay,vo7time,vo8time,vo9time,vo10time,alphamovetime,alphadietime,vo11time,vo12time,
		vo13time,vo14time,kill_alphatime,vo_recydeadtime,aitank1_movetime,aitank2_movetime,aitank3_movetime,
		scav_attacktime,wave6time,wave7time,wave8time,
		f_last;

	// handles
	Handle
		h_first,
		spawner1a,spawner1b,spawner2a,spawner2b,spawner3a,spawner3b,spawner4a,msg1,recy1,
		spawner4b,spawner4c,spawner5a,spawner5b,spawner5c,aitank1,aitank2,aitank3,power,
		alpha1,alpha2,msg6,msg7,msg8,msg9,msg10,msg11,msg12,msg13,msg14,player,misl1,misl2,
		msg4,playersrecy,vofail1,jak1,jak2,jak3,jak4,jak5,jak6,jak7,
		hauler,
		lung,
		nav1,ivrckt1,ivrckt2,ivrckt3,ivrckt4,ivrckt5,ivrckt6,ivrckt7,
		isdf_scav1,
		scav_attacker,
		spawner6a,spawner6b,spawner7a,spawner7b,spawner8a,spawner8b,
		h_last;


	// integers
	int
		i_first,


		i_last;
};
DLLBase * BuildMission(void)
{
	return new scion03();
}

void scion03::Setup(void)
{
	SetAutoGroupUnits(false);
/*
	Here's where you set the values at the start.  
*/

//  bools
	missionstart = false;
	wave1 = false;
	wave2 = false;
	wave3 = false;
	wave4 = false;
	wave5 = false;	
	checktank1alive = false;
	tank1alive = false;
	checktank1dead = false;
	tank1go = false;
	checktank2alive = false;
	tank2alive = false;
	checktank2dead = false;
	tank2go = false;
	checktank3alive = false;
	tank3alive = false;
	checktank3dead = false;
	tank3go = false;
	vo1 = false;
	obj1 = false;
	powergotten = false;
	powerhome = false;
	enemyrecydead = false;
	vo3 = false;
	powerdead = false;
	vo5 = false;
	obj3 = false;
	vo6 = false;
	msg6done = false;
	vo7 = false;
	shabsendspilots = false;
	vo7done = false;
	vo8done = false;
	vo8 = false;
	vo9 = false;
	vo10 = false;
	vo9done = false;
	obj4 = false;
	alphamoveout = false;
	vo11 = false;
	vo11done = false;
	vo12 = false;
	vo12done = false;
	vo13 = false;
	vo14 = false;
	vo13done = false;
	vo14done = false;
	playertoofar = false;
	wave2killed = false;
	wave3killed = false;
	alphadead = false;
	kill_alpha = false;
	playersrecy_dead = false;
	vo_recydead = false;
	obj5 = false;
	wavesover = false;
	alpha1die = false;
	insurance1 = false;
	spawner2atoofar = false;
	spawner2btoofar = false;
	insurance2 = false;
	spawner3atoofar = false;
	spawner3btoofar = false;
	scav_attack = false;
	player_took_scav = false;
	scav_attacker_dead = false;
	wave6 = false;
	wave7 = false;
	wave8 = false;
	player_attacked_scouts = false;

//  floats
	wave1time = 999999.9f;
	wave2time = 999999.9f;
	wave3time = 999999.9f;	
	wave4time = 999999.9f;
	wave5time = 999999.9f;
	vo1time = 999999.9f;
	vo3time = 999999.9f;
	vo5time = 999999.9f;
	vo6time = 999999.9f;
	vo7time = 999999.9f;
	convodelay = 999999.9f;
	vo8time = 999999.9f;
	vo9time = 999999.9f;
	vo10time = 999999.9f;
	vo11time = 999999.9f;
	vo12time = 999999.9f;
	alphamovetime = 999999.9f;
	alphadietime = 999999.9f;
	vo13time = 999999.9f;
	vo14time = 999999.9f;
	kill_alphatime = 999999.9f;
	vo_recydeadtime = 999999.9f;
	aitank1_movetime = 999999.9f;
	aitank2_movetime = 999999.9f;
	aitank3_movetime = 999999.9f;
	scav_attacktime = 999999.9f;
	wave6time = 999999.9f;
	wave7time = 999999.9f;
	wave8time = 999999.9f;
//  handles
	spawner1a = NULL;
	spawner1b = NULL;
	spawner2a = NULL;
	spawner2b = NULL;
	spawner3a = NULL;
	spawner3b = NULL;
	spawner4a = NULL;
	spawner4b = NULL;
	spawner4c = NULL;
	spawner5a = NULL;
	spawner5b = NULL;
	spawner5c = NULL;
	aitank1 = NULL;
	aitank2 = NULL;
	aitank3 = NULL;
	msg1 = NULL;
	msg4 = NULL;
	msg6 = NULL;
	msg7 = NULL;
	msg8 = NULL;
	msg9 = NULL;
	msg10 = NULL;
	msg11 = NULL;
	msg12 = NULL;
	power = GetHandle("power");
	recy1 = GetHandle("recy1");
	alpha1 = GetHandle("alpha1");
	alpha2 = GetHandle("alpha2");
	misl1 = GetHandle("misl1");
	misl2 = GetHandle("misl2");
	playersrecy = GetHandle("playersrecy");
	player = NULL;
	vofail1 = NULL;
	jak1 = GetHandle("jak1");
	jak2 = GetHandle("jak2");
	jak3 = GetHandle("jak3");
	jak4 = GetHandle("jak4");
	jak5 = GetHandle("jak5");
	jak6 = GetHandle("jak6");
	jak7 = GetHandle("jak7");
	nav1 = NULL;
	lung = NULL;
	hauler = NULL;

	ivrckt1 = GetHandle("ivrckt1");
	ivrckt2 = GetHandle("ivrckt2");
	ivrckt3 = GetHandle("ivrckt3");
	ivrckt4 = GetHandle("ivrckt4");
	ivrckt5 = GetHandle("ivrckt5");
	ivrckt6 = GetHandle("ivrckt6");
	ivrckt7 = GetHandle("ivrckt7");
	isdf_scav1 = GetHandle("isdf_scav1");
	scav_attacker = NULL;
	spawner6a = NULL;
	spawner6b = NULL;
	spawner7a = NULL;
	spawner7b = NULL;
	spawner8a = NULL;
	spawner8b = NULL;
//  integers




}

void scion03::AddObject(Handle h)
{
	char ODFName[64];
	GetObjInfo(h, Get_CFG, ODFName);

	if ((aitank1 == NULL) && (GetTeamNum(h) == 2) && (IsOdf2(h,"ivtank")))
	{
		aitank1 = h;
	}

	else if ((aitank2 == NULL) && (GetTeamNum(h) == 2) && (IsOdf2(h,"ivtank")))
	{
		aitank2 = h;
	}

	else if ((aitank3 == NULL) && (GetTeamNum(h) == 2) && (IsOdf2(h,"ivtank")))
	{
		aitank3 = h;
	}

	if (IsOdf2(h,"fblung"))
	{
		lung = h;
	}

	if (IsOdf2(h,"fvtug"))
	{
		hauler = h;
	}
}

void scion03::Execute(void)
{
/*
	Here is where you put what happens every frame.  
*/
	player = GetPlayerHandle();
	char tempstr[128];

//	AddScrap(2,10);
	if (!missionstart)
	{
		SetScrap(1,40);
		SetScrap(2,30);
		Ally(2,3);
		wave1time = (GetTime() + 70);
		SetPlan("scion0301.aip",2);
		vo6time = (GetTime() + 4);
		Stop(alpha1);
		Stop(alpha2);
		Patrol(misl1,"misl1_patrol");
		Patrol(misl2,"misl2_patrol");
		Patrol(jak1,"jak_1_2_path");
		Follow(jak2,jak1);
		Patrol(jak3,"jak_3_path");
		Patrol(jak4,"jak_4_path");
		Patrol(jak5,"jak_5_path");
		Patrol(jak6,"jak_6_7_path");
		Follow(jak7,jak6);
		missionstart = true;
	}

	//if player shoots scouts at beginning
	if (!vo11)
	{
		if ((!player_attacked_scouts) && (GetCurHealth(alpha1) < 150) && (GetWhoShotMe(alpha1)  ==  player))
		{
			if (!IsAudioMessageDone(msg6))
			{
				StopAudioMessage(msg6);
			}
			
			if (!IsAudioMessageDone(msg7))
			{
				StopAudioMessage(msg7);
			}
			
			if (!IsAudioMessageDone(msg8))
			{
				StopAudioMessage(msg8);
			}

			if (!IsAudioMessageDone(msg9))
			{
				StopAudioMessage(msg9);
			}

			if (!IsAudioMessageDone(msg10))
			{
				StopAudioMessage(msg10);
			}
			vo6 = true;
			vo7 = true;
			vo8 = true;
			vo9 = true;
			vo10 = true;

			AudioMessage("scngen08.wav");
			ClearObjectives();
			AddObjective("scion0306.otf", WHITE);
			FailMission(GetTime() + 15,"scion03L1.txt");
			player_attacked_scouts = true;
		}

		if ((!player_attacked_scouts) && (GetCurHealth(alpha2) < 150) && (GetWhoShotMe(alpha2)  ==  player))
		{
			if (!IsAudioMessageDone(msg6))
			{
				StopAudioMessage(msg6);
			}
			
			if (!IsAudioMessageDone(msg7))
			{
				StopAudioMessage(msg7);
			}
			
			if (!IsAudioMessageDone(msg8))
			{
				StopAudioMessage(msg8);
			}

			if (!IsAudioMessageDone(msg9))
			{
				StopAudioMessage(msg9);
			}

			if (!IsAudioMessageDone(msg10))
			{
				StopAudioMessage(msg10);
			}

			vo6 = true;
			vo7 = true;
			vo8 = true;
			vo9 = true;
			vo10 = true;

			AudioMessage("scngen08.wav");
			ClearObjectives();
			AddObjective("scion0306.otf", WHITE);
			FailMission(GetTime() + 15,"scion03L1.txt");
			player_attacked_scouts = true;
		}
	}
//SHAB is ordering Alpha wing to do a sweep to the North and find the ISDF base
	if (!shabsendspilots)
	{
		if ((!vo6) && (vo6time < GetTime()))
		{
			msg6 = AudioMessage("scion0306.wav"); // scion0306.wav  SHAB - We still do not have precise coordinates of the ISDF base.  I'm sending out a scout patrol to find the base . . . Alpha one, Alpha two do you copy?
			vo6 = true;
		}

		if ((!msg6done) && (vo6) && (IsAudioMessageDone(msg6)))
		{
			vo7time = (GetTime() + 0.5f);
			msg6done = true;
		}

		if ((!vo7) && (vo7time < GetTime()))
		{
			msg7 = AudioMessage("scion0307.wav"); // scion0307.wav ALPHA1 - Yes, Shabayev.
			vo7 = true;
		}

		if ((!vo7done) && (vo7) && (IsAudioMessageDone(msg7)))
		{
			vo8time = (GetTime() + 0.5f);	
			vo7done = true;
		}

		if ((!vo8) && (vo8time < GetTime()))
		{
			msg8 = AudioMessage("scion0308.wav"); // scion0308.wav  SHAB - Alpha wing, do a recon sweep to the North and get us the precise coordinates of the ISDF base.
			vo8 = true;
		}

		if ((!vo8done) && (vo8) && (IsAudioMessageDone(msg8)))
		{
			vo9time = (GetTime() + 0.5f);
			vo8done = true;
		}

		if ((!vo9) && (vo9time < GetTime()))
		{
			msg9 = AudioMessage("scion0309.wav"); // scion0309.wav  ALPHA1 - As you wish.
			vo9 = true;
		}

		if ((!vo9done) && (vo9) && (IsAudioMessageDone(msg9)))
		{
			vo10time = (GetTime() + 1.5f);
			alphamovetime = (GetTime() + 0.5f);
			vo9done = true;
		}

		if ((!vo10) && (vo10time < GetTime()))
		{
			msg10 = AudioMessage("scion0310.wav"); // scion0310.wav SHAB - Cooke, focus on building the base while Alpha wing searches for the ISDF.
			vo10 = true;
		}

		if ((!obj4) && (!player_attacked_scouts) && (vo10) && (IsAudioMessageDone(msg10)))
		{
			ClearObjectives();
			AddObjective("scion0304.otf", WHITE);
			obj4 = true;
			shabsendspilots = true;
		}
	}
//////

	///alpha wing moves out
	if ((!alphamoveout) && (!player_attacked_scouts) && (alphamovetime < GetTime()))
	{
		Retreat(alpha1,"alphapath");
		Follow(alpha2,alpha1);
		alphamoveout = true;
	}
	///
//when wave 2 is killed, alpha wing will start reporting]
	if ((!wave2killed) && (wave2) && (!IsAround(spawner2a) && (!IsAround(spawner2b))))
	{
		alphadietime = (GetTime() + 8);
		insurance1 = true;
		wave2killed = true;
	}

	//when wave 3 killed, shab gives coordinates of the base
	if ((!wave3killed) && (wave3) && (!IsAround(spawner3a) && (!IsAround(spawner3b))))
	{
		vo1time = (GetTime() + 10);
		insurance2 = true;
		wave3killed = true;
	}

//alpha wing finds the base and then gets blown up
	if ((!vo11) && (alphadietime < GetTime()))
	{
		msg11 = AudioMessage("scion0311.wav"); // scion0311.wav ALPHA1 - Alpha wing reporting, we think we've found the base.  Oh no, we've been spotted!  We Are under attack!
		Goto(alpha1,"enemybase");
		Goto(alpha2,"enemybase");
		Attack(misl1,alpha1);
		Attack(misl2,alpha2);
		vo11 = true;
	}

	if ((!vo11done) && (vo11) && (IsAudioMessageDone(msg11)))
	{
		vo12time = (GetTime() + 1);
		vo11done = true;
	}

	if ((!vo12) && (vo12time < GetTime()))
	{
		msg12 = AudioMessage("scion0312.wav"); // scion0312.wav SHAB - Alpha wing, can you handle the situation?
		vo12 = true;
	}

	if ((!vo12done) && (vo12) && (IsAudioMessageDone(msg12)))
	{
		vo13time = (GetTime() + 1);
		vo12done = true;
	}

	if ((!vo13) && (vo13time < GetTime()))
	{
		msg13 = AudioMessage("scion0313.wav"); //scion0313.wav ALPHA1 - Negative, negative, there are too many of them.  I'm breaking up!
		kill_alphatime = (GetTime() + 45);
		vo13 = true;
	}

	if ((!alpha1die) && (vo13) && (IsAudioMessageDone(msg13)))
	{
		Damage(alpha1,5000);
		alpha1die = true;
	}

	//checking to see when alpha wing gets whacked
	if ((!alphadead) && (vo13) && (!IsAround(alpha1) && (!IsAround(alpha2))))
	{
		vo14time = (GetTime() + 6);
		Patrol(misl1,"misl1_patrol");
		Patrol(misl2,"misl2_patrol");
		alphadead = true;
	}

	//this is for if alpha wing doesn't get whacked by the AI...I whack them
	if ((!kill_alpha) && (!alphadead) && (kill_alphatime < GetTime()))
	{
		if (IsAround(alpha1))
		{
			Damage(alpha1,5000);
		}

		if (IsAround(alpha2))
		{
			Damage(alpha2,5000);
		}

		kill_alpha = true;
	}

	if ((!vo14) && (vo14time < GetTime()))
	{
		msg14 = AudioMessage("scion0314.wav"); // scion0314.wav SHAB -We've lost contact with Alpha Wing.  Luckily, we were able to get the coordinates
		vo14 = true;
	}


	if (!obj1)
	{
		//if the player goes too far from the base and tries to help alpha wing

		if ((!playertoofar) && (GetDistance(player,"playerbase") > 500))
		{
			AudioMessage("scion0315.wav"); // scion0315.wav Cooke, where are you going?  You must stay at the base, I can't defend it by myself
			playertoofar = true;
		}
	}


	////////
	if ((!vo1) && (vo1time < GetTime()))
	{
		msg1 = AudioMessage("scion0301.wav"); //I'm giving you the coordinates of the base. First, focus on destroying the base's defenses.  Then when you are able, move in with a Hauler and bring the power crystal back to your base.  Expect VERY heavy resistance, the ISDF will do whatever they can to keep us from the power crystal. Those two Scions died for this mission, Cooke.  If you fail, their deaths will be in vain.
		vo1 = true;
	}

	if ((!obj1) && (vo1) && (IsAudioMessageDone(msg1)))
	{
		ClearObjectives();
		AddObjective("scion0301.otf", WHITE);
		nav1 = BuildObject("ibnav",1,"nav1");
		SetObjectiveOn(nav1);
		TranslateString2(tempstr, sizeof(tempstr), "MissionS0301");  // Convoy
		SetObjectiveName(nav1,tempstr);
		SetObjectiveOn(power);
		TranslateString2(tempstr, sizeof(tempstr), "MissionS0302");  // Convoy
		SetObjectiveName(power,tempstr);
		obj1 = true;
	}

	if ((!powergotten) && (GetTug(power)))
	{
		AudioMessage("scion0302.wav"); //Good Cook, you've got it.  Bring it back to base, hurry!
		SetObjectiveOff(nav1);
		
		//if any rocket tanks are still alive now is the time they will attack the tug
		if ((IsAlive(ivrckt1) && (IsAlive(hauler))))
		{
			Attack(ivrckt1,hauler);
		}

		if ((IsAlive(ivrckt2) && (IsAlive(hauler))))
		{
			Attack(ivrckt2,hauler);
		}

		if ((IsAlive(ivrckt3) && (IsAlive(hauler))))
		{
			Attack(ivrckt3,hauler);
		}

		if ((IsAlive(ivrckt4) && (IsAlive(hauler))))
		{
			Attack(ivrckt4,hauler);
		}

		if ((IsAlive(ivrckt5) && (IsAlive(hauler))))
		{
			Attack(ivrckt5,hauler);
		}

		if ((IsAlive(ivrckt6) && (IsAlive(hauler))))
		{
			Attack(ivrckt6,hauler);
		}

		if ((IsAlive(ivrckt7) && (IsAlive(hauler))))
		{
			Attack(ivrckt7,hauler);
		}

		
		powergotten = true;
	}


//mission lost if powersource ever gets destroyed
	if ((!powerdead) && (!IsAround(power)))
	{
		vo5time = (GetTime() + 4);
		powerdead = true;
	}

	if ((!vo5) && (vo5time < GetTime()))
	{
		AudioMessage("scion0305.wav"); // Burns "Without that power crystal my plans for the scions are ruined...
		FailMission(GetTime() + 20,"scion03L2.txt");
		ClearObjectives();
		AddObjective("scion0302.otf", WHITE);	
		vo5 = true;
	}
//when player takes out the enemy reclycler
	if ((!enemyrecydead) && (!IsAround(recy1)))
	{
		vo3time = (GetTime() + 5);
		enemyrecydead = true;
	}
	
	if ((!vo3) && (vo3time < GetTime()))
	{
		wavesover = true;
		AudioMessage("scion0303.wav"); //You've taken out the enemy's recycler, nice work!
		vo3 = true;
	}

//when power is near player base, mission accomplished
	if ((!powerhome) && (GetDistance(power,playersrecy) < 150))
	{
		msg4 = AudioMessage("scion0304.wav");//All is going according to plan.  Thank you, John.  You're a worthy protege. 
		powerhome = true;
	}

	if ((!obj3) && (powerhome) && (IsAudioMessageDone(msg4)))
	{
		ClearObjectives();
		AddObjective("scion0303.otf", WHITE);	
		SucceedMission(GetTime() + 12,"scion03w1.txt");
		obj3 = true;
	}

	///////helping out the AIP

	if ((!checktank1alive) && (IsAlive(aitank1)))	
	{
		aitank1_movetime = (GetTime() + 2);
		tank1alive = true;
		checktank1alive = true;
		checktank1dead = false;
		tank1go = false;
	}

	if ((!checktank1dead) && (!IsAlive(aitank1)))
	{
		tank1alive = false;
		checktank1alive = false;
		checktank1dead = true;
	}

	if ((!tank1go) && (aitank1_movetime < GetTime()))
	{
		Goto(aitank1,"scout1point");
		tank1go = true;
	}
//////////////
	if ((!checktank2alive) && (IsAlive(aitank2)))	
	{
		aitank2_movetime = (GetTime() + 2);
		tank2alive = true;
		checktank2alive = true;
		checktank2dead = false;
		tank2go = false;
	}

	if ((!checktank2dead) && (!IsAlive(aitank2)))
	{
		tank2alive = false;
		checktank2alive = false;
		checktank2dead = true;
	}

	if ((!tank2go) && (aitank2_movetime < GetTime()))
	{
		Goto(aitank2,"scout2point");
		tank2go = true;
	}
//////////////
	if ((!checktank3alive) && (IsAlive(aitank3)))	
	{
		aitank3_movetime = (GetTime() + 2);
		tank3alive = true;
		checktank3alive = true;
		checktank3dead = false;
		tank3go = false;
	}

	if ((!checktank3dead) && (!IsAlive(aitank3)))
	{
		tank3alive = false;
		checktank3alive = false;
		checktank3dead = true;
	}

	if ((!tank3go) && (aitank3_movetime < GetTime()))
	{
		Goto(aitank3,"scout3point");
		tank3go = true;
	}
//////////////
	//if the player's recycler is ever destroyed--MISSION FAILED
	if ((!playersrecy_dead) && (!IsAround(playersrecy)))
	{
		vo_recydeadtime = (GetTime() + 3);
		playersrecy_dead = true;
	}

	if ((!vo_recydead) && (vo_recydeadtime < GetTime()))
	{
		vofail1 = AudioMessage("scion0399.wav"); 	//Dammit cooke, the recycler has been destroyed
		vo_recydead = true;
	}

	if ((!obj5) && (vo_recydead) && (IsAudioMessageDone(vofail1)))
	{
		ClearObjectives();
		AddObjective("scion0305.otf", WHITE);
		FailMission(GetTime() + 6,"scion03L3.txt");
		obj5 = true;
	}

//****WAVES****//
	if (!wavesover)
	{
		if ((!wave1) && (wave1time < GetTime()))
		{
			spawner1a = BuildObject("ivscout",3,"spawn1");
			spawner1b = BuildObject("ivscout",3,"spawn2");
			SetSkill(spawner1a,2);
			SetSkill(spawner1b,1);
			Goto(spawner1a,"playerbase");
			Goto(spawner1b,"playerbase");
			wave2time = (GetTime() + 120);
			wave1 = true;
		}

		if ((!wave2) && (wave2time < GetTime()))
		{
			spawner2a = BuildObject("ivscout",3,"spawn3");
			spawner2b = BuildObject("ivscout",3,"spawn4");
			SetSkill(spawner2a,2);
			SetSkill(spawner2b,1);
			Goto(spawner2a,"playerbase");
			Goto(spawner2b,"playerbase");
			wave3time = (GetTime() + 120);
			wave2 = true;
		}
   
		///this is to make sure the "alpha-death" sequence is not delayed
		if (!insurance1)
		{
			if (IsAround(spawner2a))
			{
				if ((!spawner2atoofar) && (GetDistance(spawner2a,player) > 130))
				{
					Goto(spawner2a,player);
					spawner2atoofar = true;
				}

				if ((spawner2atoofar) && (GetDistance(spawner2a,player) < 75))
				{		
					spawner2atoofar = false;
				}
			}
		
			if (IsAround(spawner2b))
			{
				if ((!spawner2btoofar) && (GetDistance(spawner2b,player) > 130))
				{
					Goto(spawner2b,player);
					spawner2btoofar = true;
				}

				if ((spawner2btoofar) && (GetDistance(spawner2b,player) < 75))
				{		
					spawner2btoofar = false;
				}
			}
		}
		//this is to make sure the script is not delayed on the first WAVE3
		if (!insurance2)
		{
			if (IsAround(spawner3a))
			{
				if ((!spawner3atoofar) && (GetDistance(spawner3a,player) > 130))
				{
					Goto(spawner3a,player);
					spawner3atoofar = true;
				}

				if ((spawner3atoofar) && (GetDistance(spawner3a,player) < 75))
				{		
					spawner3atoofar = false;
				}
			}
		
			if (IsAround(spawner3b))
			{
				if ((!spawner3btoofar) && (GetDistance(spawner3b,player) > 130))
				{
					Goto(spawner3b,player);
					spawner3btoofar = true;
				}

				if ((spawner3btoofar) && (GetDistance(spawner3b,player) < 75))
				{		
					spawner3btoofar = false;
				}
			}
		}

		if ((!wave3) && (wave3time < GetTime()))
		{
			spawner3a = BuildObject("ivscout",3,"spawn1");
			spawner3b = BuildObject("ivmbike",3,"spawn4");
			SetSkill(spawner3a,1);
			SetSkill(spawner3b,1);
			Goto(spawner3a,"playerbase");
			Goto(spawner3b,"playerbase");
			wave4time = (GetTime() + 120);
			wave3 = true;
		}

		if ((!wave4) && (wave4time < GetTime()))
		{
			spawner4a = BuildObject("ivtank",3,"spawn1");
			spawner4c = BuildObject("ivtank",3,"spawn3");
			SetSkill(spawner4a,1);
			SetSkill(spawner4c,2);
			Goto(spawner4a,"playerbase");
			Goto(spawner4c,"playerbase");
			wave5time = (GetTime() + 130);
			wave4 = true;
		}

		if ((!wave5) && (wave5time < GetTime()))
		{
			spawner5a = BuildObject("ivmbike",3,"spawn1");
			spawner5c = BuildObject("ivtank",3,"spawn2");
			SetSkill(spawner5a,1);
			SetSkill(spawner5c,2);
			Goto(spawner5a,"playerbase");
			Goto(spawner5c,"playerbase");
			wave6time = (GetTime() + 120);
			wave5 = true;
		}

		if ((!wave6) && (wave5time < GetTime()))
		{
			spawner6a = BuildObject("ivmbike",3,"spawn4");
			spawner6b = BuildObject("ivrckt",3,"spawn3");
			SetSkill(spawner6a,1);
			SetSkill(spawner6b,2);
			Goto(spawner6a,"playerbase");
			Goto(spawner6b,"playerbase");
			wave6 = true;
		}

		if ((wave1) && (wave2) && (wave3) && (wave4) && (wave5) && (wave6))
		{
			wave1time = (GetTime() + 165);
			wave2time = (GetTime() + 999999.9f);
			wave3time = (GetTime() + 999999.9f);
			wave4time = (GetTime() + 999999.9f);
			wave5time = (GetTime() + 999999.9f);
			wave6time = (GetTime() + 999999.9f);
			wave1 = false;
			wave2 = false;
			wave3 = false;
			wave4 = false;
			wave5 = false;
			wave6 = false;
		}
	}

	//checking to see when/if player takes the enemy scav near his base
	if (!enemyrecydead)
	{
		if ((!player_took_scav) && ((!IsAround(isdf_scav1))))
		{
			scav_attacktime = (GetTime() + 120);
			player_took_scav = true;
		}
		//sending a tank to attack the location after player has killed scav
		if ((!scav_attack) && (player_took_scav) && (scav_attacktime < GetTime()))
		{
			scav_attacker = BuildObject("ivtank",3,"enemybase");
			SetSkill(scav_attacker,2);
			SetAvoidType(scav_attacker,0);
			Goto(scav_attacker,"scav1");
			scav_attacker_dead = false;
			scav_attack = true;
		}

		if ((!scav_attacker_dead) && (scav_attack) && (!IsAround(scav_attacker)))
		{
			scav_attacktime = (GetTime() + 120);
			scav_attack = false;
			scav_attacker_dead = true;
		}
	}
	
}

