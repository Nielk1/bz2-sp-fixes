//the force that kills aan base when player rushes or takes too long works every time (recy is damaged in the script).  might need to adjust spawn points to make it more believeable
#include "..\Shared\SPMission.h"

class scion05 : public SPMission 
{
public:
	scion05(void)
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
		vo1,vo2,vo3,unitsbuilt,obj1,obj2,obj4,
		bridgegoboom,bstr1goboom,bstr2goboom,bseg1goboom,bseg2goboom,bseg3goboom,
		bridgegoboomover,vo5,obj3,playeratAAN,playeratbridge,atankattack,reroute1,
		reroute1a,reroute1b,bridgedone,spawn2,wave1over,vo7,spire1built,vo8,
		spawn3,spawn4,spawn5,spawn6,spawn7,spawn8,changeplan1,checkturret1alive,turret1alive,checkturret1dead,
		turret1go,cin1over,shot1over,rdycam1,rckt_attack,rckt_attackcbunk,
		checkbasetank1alive,basetank1alive,checkbasetank1dead,basetank1dead,
		checkbasetank2alive,basetank2alive,checkbasetank2dead,basetank2dead,
		checkbasetank3alive,basetank3alive,checkbasetank3dead,basetank3dead,
		basetank1go,basetank2go,basetank3go,pk1attack,pk2attack,pk3attack,obj7,
		player_at_aan_early,cutvo1,
		aanrecykilled,vo9,obj5,wavesover,vo10,obj6,pk4attack,pk5attack,pk6attack,pk7attack,
		pk9attack,delay1,pkover,pk10dead,playersrecy_dead,vo_recydead,playertakingtoolong1,
		pk8attack,pk10attack,spawn1,tank1alive,tank2alive,tank3alive,sent1alive,sent2alive,sent3alive,
		pk11attack,pk12attack,pk13attack,pk14attack,reset_atank1,reset_atank2,
		reset_bridge_tanks,shit,
		spawn9,spawn10,spawn11,spawn12,
		aan_recy_goboom,ass1_attacked,ass2_attacked,
		after_spawn,
		b_last;

	// floats
	float
		f_first,
		vo1time,
		vo2time,
		vo3time,
		vo5time,
		bstr1boomtime,bstr2boomtime,bseg1boomtime,bseg2boomtime,bseg3boomtime,
		spawn2time,vo7time,vo8time,spawn3time,spawn4time,spawn5time,spawn6time,spawn7time,spawn8time,
		ChangePlanTime1,turret1movetime,basetank1movetime,basetank2movetime,basetank3movetime,
		pk1time,pk2time,pk3time,vo9time,vo10time,pk4time,pk5time,pk6time,pk7time,pk8time,
		pk9time,pk10time,spawn1time,vo_recydeadtime,
		playertakingtoolong1time,pk11time,pk12time,pk13time,pk14time,
		//cineractive floats
		rckt_attacktime,cin1overtime,cutvo1time,
		spawn9time,spawn10time,spawn11time,spawn12time,
		aan_recy_goboomtime,after_spawntime,
		f_last;

	// handles
	Handle
		h_first,
		player,msg1,msg2,
		fvtank1,fvtank2,fvtank3,fvsent1,fvsent2,fvsent3,
		bseg1,bseg2,bseg3,bstr1,bstr2,msg5,aanbase,spawner1,spawner2,spawner3,spawner4,
		spawner5,spawner6,spawner7,spawner8,atank1,atank2,bridgetank,bridgescout,
		msg7,spire1site,gspire1,msg8,msg6,
		spawner9,spawner10,spawner11,spawner12,spawner13,spawner14,spawner15,spawner16,spawner17,
		spawner18,spawner19,spawner20,spawner21,spawner22,
		baseturr1,basetank1,basetank2,basetank3,pk1,pk1b,pk2,pk2b,pk3,pk3b,aanrecy,msg9,msg10,pk4,pk4b,pk5,pk5b,pk8,
		pk6,pk7,pk9,pk10,playersrecy,vofail1,pk6b,pk8b,pk7b,pk9b,pk9c,pk10b,pk10c,
		pk11,pk11b,pk12,pk12b,pk12c,pk13,pk13b,pk14,pk14b,
		death1,death2,death3,death4,death5,death6,look1,aan_fact,aansbay,
		aan_cons,
		aanpgen1,aanpgen2,lastspawn1,lastspawn2,lastspawn3,lastspawn4,lastspawn5,
		death7,death8,rhino1,rhino2,rhino3,pk11c,

		//cineractive handles
		aan_cintank1,aan_cintank2,aan_cinturr1,aan_cinturr2,
		aan_cingtow1,
		nr_cinrckt1,nr_cinmbike1,nr_cinmbike2,nr_cintank1,
		nr_cintank2,aan_cbunk,aan_cinscout1,msgcin1,
		h_last;

	// integers
	int
		i_first,
		i_last;
};
DLLBase * BuildMission(void)
{
	return new scion05();
}

void scion05::Setup(void)
{
	SetAutoGroupUnits(false);
/*
	Here's where you set the values at the start.
*/

//  bools
	missionstart = false;
	vo1 = false;
	vo2 = false;
	vo3 = false;
	unitsbuilt = false;
	obj1 = false;
	obj2 = false;	
	bridgegoboom = false;
	bseg1goboom = false;
	bseg2goboom = false;
	bseg3goboom = false;
	bstr1goboom = false;
	bstr2goboom = false;
	bridgegoboomover = false;
	vo5 = false;
	obj3 = false;
	playeratAAN = false;
	playeratbridge = false;
	atankattack = false;
	reroute1 = false;
	reroute1a = false;
	reroute1b = false;
	bridgedone = false;
	spawn2 = false;
	spawn3 = false;
	spawn4 = false;	
	spawn5 = false;
	spawn6 = false;
	spawn7 = false;
	spawn8 = false;
	wave1over = false;
	vo7 = false;
	obj4 = false;
	spire1built = false;
	vo8 = false;
	changeplan1 = false;
	checkturret1alive = false;
	turret1movetime = false;
	checkturret1dead = false;
	turret1go = false;
	checkbasetank1alive = false;
	basetank1alive = false;
	checkbasetank1dead = false;
	basetank1dead = false;
	basetank1go = false;
	checkbasetank2alive = false;
	basetank2alive = false;
	checkbasetank2dead = false;
	basetank2dead = false;
	basetank2go = false;
	checkbasetank3alive = false;
	basetank3alive = false;
	checkbasetank3dead = false;
	basetank3dead = false;
	basetank3go = false;
	pk1attack = false;
	pk2attack = false;
	pk3attack = false;
	aanrecykilled = false;
	vo9 = false;
	obj5 = false;
	wavesover = false;
	vo10 = false;
	obj6 = false;
	pk4attack = false;
	pk5attack = false;
	pk6attack = false;
	pk7attack = false;
	pk8attack = false;
	pk9attack = false;
	pk10attack = false;
	spawn1 = false;
	delay1 = false;
	tank1alive = false;
	tank2alive = false;
	tank3alive = false;
	sent1alive = false;
	sent2alive = false;
	sent3alive = false;
	pkover = false;
	pk10dead = false;
	playersrecy_dead = false;
	vo_recydead = false;
	obj7 = false;
	playertakingtoolong1 = false;
	cin1over = false;
	shot1over=false;
	rdycam1=false;
	rckt_attack = false;
	rckt_attackcbunk = false;
	player_at_aan_early = false;
	cutvo1 = false;
	pk11attack = false;
	pk12attack = false;
	pk13attack = false;
	pk14attack = false;
	reset_atank1 = false;
	reset_atank2 = false;
	reset_bridge_tanks = false;
	spawn9 = false;
	spawn10 = false;
	spawn11 = false;
	spawn12 = false;
	aan_recy_goboom = false;
	shit = false;
	ass1_attacked = false;
	ass2_attacked = false;
	after_spawn = false;

//  floats
	vo1time = 999999.9f;
	vo2time = 999999.9f;
	vo3time = 999999.9f;
	bstr1boomtime = 999999.9f;	
	bstr2boomtime = 999999.9f;
	bseg1boomtime = 999999.9f;
	bseg2boomtime = 999999.9f;
	bseg3boomtime = 999999.9f;
	vo5time = 999999.9f;
	spawn2time = 999999.9f;
	spawn3time = 999999.9f;
	spawn4time = 999999.9f;
	spawn5time = 999999.9f;
	spawn6time = 999999.9f;
	spawn7time = 999999.9f;
	spawn8time = 999999.9f;
	vo7time = 999999.9f;
	vo8time = 999999.9f;
	ChangePlanTime1 = 999999.9f;
	turret1movetime = 999999.9f;
	basetank1movetime = 999999.9f;
	basetank2movetime = 999999.9f;
	basetank3movetime = 999999.9f;
	pk1time = 999999.9f;
	pk2time = 999999.9f;
	pk3time = 999999.9f;
	vo9time = 999999.9f;
	vo10time = 999999.9f;
	pk4time = 999999.9f;
	pk5time = 999999.9f;
	pk6time = 999999.9f;
	pk7time = 999999.9f;
	pk8time = 999999.9f;
	pk9time = 999999.9f;
	pk10time = 999999.9f;
	pk11time = 999999.9f;
	pk12time = 999999.9f;
	pk13time = 999999.9f;
	pk14time = 999999.9f;
	spawn1time = 999999.9f;
	vo_recydeadtime = 999999.9f;
	playertakingtoolong1time = 999999.9f;
	rckt_attacktime = 999999.9f;
	cin1overtime = 999999.9f;
	cutvo1time = 999999.9f;
	spawn9time = 999999.9f;
	spawn10time = 999999.9f;
	spawn11time = 999999.9f;
	spawn12time = 999999.9f;
	aan_recy_goboomtime = 999999.9f;
	after_spawntime = 999999.9f;
//  handles
	player = NULL;
	msg1 = NULL;
	msg2 = NULL;
	msg5 = NULL;
	fvtank1 = NULL;
	fvtank2 = NULL;
	fvtank3 = NULL;
	fvsent1 = NULL;
	fvsent2 = NULL;
	fvsent3 = NULL;
	spawner1 = NULL;
	spawner2 = NULL;
	spawner3 = NULL;
	spawner4 = NULL;
	spawner5 = NULL;
	spawner6 = NULL;
	spawner7 = NULL;
	spawner8 = NULL;
	spawner9 = NULL;
	spawner10 = NULL;
	spawner11= NULL;
	spawner12 = NULL;
	spawner13 = NULL;
	spawner14 = NULL;
	spawner15 = NULL;
	spawner16 = NULL;
	spawner17 = NULL;
	spawner18 = NULL;
	spawner19 = NULL;
	spawner20 = NULL;
	spawner21 = NULL;
	spawner22 = NULL;
	baseturr1 = NULL;
	basetank1 = NULL;
	basetank2 = NULL;
	basetank3 = NULL;
	lastspawn1 = NULL;
	lastspawn2 = NULL;
	lastspawn3 = NULL;
	lastspawn4 = NULL;
	lastspawn5 = NULL;
	atank1 = NULL;
	atank2 = NULL;
	vofail1 = NULL;
	bseg1 = GetHandle("bseg1");
	bseg2 = GetHandle("bseg2");
	bseg3 = GetHandle("bseg3");
	bstr1 = GetHandle("bstr1");
	SetCurHealth(bstr1,5000);
	SetMaxHealth(bstr1,5000);
	bstr2 = GetHandle("bstr2");
	SetCurHealth(bstr2,5000);
	SetMaxHealth(bstr2,5000);
	rhino1 = GetHandle("rhino1");
	rhino2 = GetHandle("rhino2");
	rhino3 = GetHandle("rhino3");

	aanbase = NULL;
	bridgetank = GetHandle("bridgetank");
	bridgescout = GetHandle("bridgescout");
	spire1site = NULL;
	aanrecy = GetHandle("aanrecy");
	playersrecy = GetHandle("playersrecy");
	aan_fact = GetHandle("aan_fact");
	aansbay = GetHandle("aansbay");
	aanpgen1 = GetHandle("aanpgen1");
	aanpgen2 = GetHandle("aanpgen2");
	msg7 = NULL;
	msg8 = NULL;
	gspire1 = NULL;
	pk1 = NULL;
	pk1b = NULL;
	pk2 = NULL;
	pk2b = NULL;

	pk3 = NULL;
	pk3b = NULL;
	pk4 = NULL;
	pk4b = NULL;
	pk5 = NULL;
	pk5b = NULL;
	pk6 = NULL;
	pk6b = NULL;


	pk7 = NULL;
	pk7b = NULL;
	pk8 = NULL;
	pk8b = NULL;
	pk9 = NULL;
	pk9b = NULL;
	pk9c = NULL;

	pk10 = NULL;
	pk10b = NULL;
	pk10c = NULL;

	pk11 = NULL;
	pk11b = NULL;
	pk11c = NULL;

	pk12 = NULL;
	pk12b = NULL;
	pk12c = NULL;

	pk13 = NULL;
	pk13b = NULL;

	pk14 = NULL;
	pk14b = NULL;

	msg9 = NULL;
	msg10 = NULL;
	msg6 = NULL;
	death1 = NULL;
	death2 = NULL;
	death3 = NULL;
	death4 = NULL;
	death5 = NULL;
	death6 = NULL;
	death7 = NULL;
	death8 = NULL;
	look1 = GetHandle("look1");
	aan_cbunk = GetHandle("aan_cbunk");
	msgcin1 = NULL;
	aan_cons = GetHandle("aan_cons");
	//Cineractive handles
	aan_cintank1 = GetHandle("aan_cintank1");
	aan_cintank2 = GetHandle("aan_cintank2");
	aan_cinturr1 = GetHandle("aan_cinturr1");
	aan_cinturr2 = GetHandle("aan_cinturr2");
	aan_cingtow1 = GetHandle("aan_cingtow1");
	nr_cinrckt1 = GetHandle("nr_cinrckt1");
	nr_cinmbike1 = GetHandle("nr_cinmbike1");
	nr_cinmbike2 = GetHandle("nr_cinmbike2");
	nr_cintank1 = GetHandle("nr_cintank1");
	nr_cintank2 = GetHandle("nr_cintank2");
	aan_cinscout1 = GetHandle("aan_cinscout1");



//  integers
	SetTeamColor(3,0,127,255);  //BRADDOCK	
}

void scion05::AddObject(Handle h)
{
	char ODFName[64];
	GetObjInfo(h, Get_CFG, ODFName);

	if (missionstart)
	{

		
//****PLAYER'S VEHICLES****//
		//TANKS

	/*	if (!tank1alive)
		{
			if ((IsOdf2(h,"fvtank") && (fvtank1 == NULL)))
			{
				fvtank1 = h;
				tank1alive = true;
			}
		}

		else if (!tank2alive)
		{
			if ((IsOdf2(h,"fvtank") && (fvtank2 == NULL)))
			{
				fvtank2 = h;
				tank2alive = true;
			}
		}

		else if (!tank3alive)
		{
			if ((IsOdf2(h,"fvtank") && (fvtank3 == NULL)))
			{
				fvtank3 = h;
				tank3alive = true;
			}
		}
		

			//SENTS
		else if (!sent1alive)
		{
			if ((IsOdf2(h,"fvsent") && (fvsent1 == NULL)))
			{
				fvsent1 = h;
				sent1alive = true;
			}
		}

		else if (!sent2alive)
		{
			if ((IsOdf2(h,"fvsent") && (fvsent2 == NULL)))
			{
				fvsent2 = h;
				sent2alive = true;
			}
		}
	
		else if (!sent3alive)
		{
			if ((IsOdf2(h,"fvsent") && (fvsent3 == NULL)))
			{
				fvsent3 = h;
				sent3alive = true;
			}
		}
		*/

		//GUN SPIRES
		if  (IsOdf2(h,"fbspir"))
		{
			gspire1 = h;
		}

//****AAN BASE VEHICLES****//
		if ((baseturr1 == NULL) && (GetTeamNum(h) == 2) && (GetDistance(h,"aanbase") < 150)
		&& (IsOdf2(h,"ivturr")))
		{
			baseturr1 = h;
		}

//TANK1
		if (!basetank1alive)
		{
			if ((IsOdf2(h,"ivtank")) && (GetTeamNum(h) == 2) && (GetDistance(h,"aanbase") < 150))
		
			{
				basetank1 = h;
				basetank1movetime = (GetTime() + 1.4f);
				basetank1go = false;
				basetank1alive = true;
			}
		}
//TANK2
		else if (!basetank2alive)
		{
			if ((IsOdf2(h,"ivtank")) && (GetTeamNum(h) == 2) && (GetDistance(h,"aanbase") < 150))
		
			{
				basetank2 = h;
				basetank2movetime = (GetTime() + 1.4f);
				basetank2go = false;
				basetank2alive = true;
			}
		}
//TANK3
		else if (!basetank3alive)
		{
			if ((IsOdf2(h,"ivtank")) && (GetTeamNum(h) == 2) && (GetDistance(h,"aanbase") < 150))
		
			{
				basetank3 = h;
				basetank3movetime = (GetTime() + 1.4f);
				basetank3go = false;
				basetank3alive = true;
			}
		}
	}
}

bool scion05::PostLoad(bool missionSave)
{
	bool ret = SPMission::PostLoad(missionSave);

	if (missionSave)
		return ret;

	SetTeamColor(3,0,127,255);  //BRADDOCK		


	return ret;
}

void scion05::Execute(void)
{
/*
	Here is where you put what happens every frame.  
*/
	player = GetPlayerHandle();
	char tempstr[128];
//AddScrap(2,10);

	// INTRO CINERACTIVE SHOWING THE ANN BASE UNDER ATTACK BY BRADDOCK'S FORCES
	if (!cin1over)
	{
		if (!shot1over)
		{
			if (!rdycam1)
			{
				CameraReady();
				cin1overtime = (GetTime() + 35);
				Retreat(nr_cinrckt1,"nr_cinrckt1_path");

				SetTeamNum(nr_cinmbike1,3);
				SetTeamNum(nr_cinmbike2,3);
				SetTeamNum(nr_cintank1,3);
				SetTeamNum(nr_cintank2,3);

				SetTeamNum(nr_cinrckt1,3);


				SetMaxHealth(rhino1,1000);
				SetCurHealth(rhino1,1000);
				SetMaxHealth(rhino2,1000);
				SetCurHealth(rhino2,1000);
				SetMaxHealth(rhino3,1000);
				SetCurHealth(rhino3,1000);

				Patrol(rhino1,"rhino1path");
				Patrol(rhino2,"rhino2path");
				Patrol(rhino3,"rhino3path");

				SetMaxHealth(aan_cinscout1,8000);
				SetCurHealth(aan_cinscout1,8000);
			
				SetMaxHealth(aan_cintank1,8000);
				SetCurHealth(aan_cintank1,8000);

				SetMaxHealth(aan_cintank2,8000);
				SetCurHealth(aan_cintank2,8000);
				
				SetAvoidType(nr_cinmbike1,0);
				SetAvoidType(nr_cinmbike2,0);
				SetAvoidType(nr_cintank1,0);
				SetAvoidType(nr_cintank2,0);
				SetAvoidType(nr_cinrckt1,0);

		
				Attack(nr_cinmbike1,aan_cinturr1);
				Attack(nr_cinmbike2,aan_cinturr2);

				Attack(aan_cinturr1,nr_cinmbike1);

				Attack(nr_cintank1,aan_cintank1);
			//	Attack(aan_cintank1,nr_cintank1);

				Attack(nr_cintank2,aan_cintank2);
			//	Attack(aan_cintank2,nr_cintank2);		

				rckt_attacktime = (GetTime() + 5);
				cutvo1time = (GetTime() + 3);
				rdycam1 = true;
			}
			
			CameraPath("campath1",2000,700,look1);
		}

		//cin vo
		if ((!cutvo1) && (cutvo1time < GetTime()))
		{
			msgcin1 = AudioMessage("CutSc0501.wav");
			cutvo1 = true;
		}

	
		
		if ((!rckt_attack) && (rckt_attacktime < GetTime()))
		{

			Attack(nr_cinrckt1,aan_cingtow1);

			//Attack(aan_cingtow1,nr_cinrckt1);
			rckt_attack = true;
		}

		if ((!rckt_attackcbunk) && (!IsAround(aan_cingtow1)))
		{
			if (IsAround(nr_cinrckt1))
			{
				Attack(nr_cinrckt1,aan_cbunk);
			}

	
			
			rckt_attackcbunk = true;
		}

		//this ends the cin
		if ((!cin1over) && (cin1overtime < GetTime()))
		{
			CameraFinish();

			//this deletes the CIN units
			if(IsAround(nr_cintank1))
			{
				RemoveObject(nr_cintank1);
			}
			if(IsAround(nr_cintank2))
			{
				RemoveObject(nr_cintank2);
			}
			if(IsAround(nr_cinmbike1))
			{
				RemoveObject(nr_cinmbike1);
			}
			if(IsAround(nr_cinmbike2))
			{
				RemoveObject(nr_cinmbike2);
			}
			if(IsAround(nr_cinrckt1))
			{
				RemoveObject(nr_cinrckt1);
			}

			if(IsAround(aan_cintank1))
			{
				RemoveObject(aan_cintank1);
			}
			if(IsAround(aan_cintank2))
			{
				RemoveObject(aan_cintank2);
			}
			if(IsAround(aan_cinscout1))
			{
				RemoveObject(aan_cinscout1);
			}
			if(IsAround(aan_cinturr1))
			{
				RemoveObject(aan_cinturr1);
			}
			if(IsAround(aan_cinturr2))
			{
				RemoveObject(aan_cinturr2);
			}

			shot1over = true;
			cin1over = true;		
		}

	//if the user hits spacebar to bypass the cin...
		if ((CameraCancelled() && (!cin1over)))
		{
			CameraFinish();
			
			//this deletes the CIN units
			if(IsAround(nr_cintank1))
			{
				RemoveObject(nr_cintank1); 
			}
			if(IsAround(nr_cintank2))
			{
				RemoveObject(nr_cintank2);
			}
			if(IsAround(nr_cinmbike1))
			{
				RemoveObject(nr_cinmbike1);
			}
			if(IsAround(nr_cinmbike2))
			{
				RemoveObject(nr_cinmbike2);
			}
			if(IsAround(nr_cinrckt1))
			{
				RemoveObject(nr_cinrckt1);
			}

			if(IsAround(aan_cintank1))
			{
				RemoveObject(aan_cintank1);
			}
			if(IsAround(aan_cintank2))
			{
				RemoveObject(aan_cintank2);
			}
			if(IsAround(aan_cinscout1))
			{
				RemoveObject(aan_cinscout1);
			}
			if(IsAround(aan_cinturr1))
			{
				RemoveObject(aan_cinturr1);
			}
			if(IsAround(aan_cinturr2))
			{
				RemoveObject(aan_cinturr2);
			}

			if ((cutvo1) && (!IsAudioMessageDone(msgcin1)))
			{
				StopAudioMessage(msgcin1);
			}
			shot1over = true;
			cin1over = true;
		}
	}


	// after the intro cineractive, the mission begins
	if ((!missionstart) && (cin1over))
	{
		Ally(1,2);
		//first i replace/build all the AAN base units so that they appear blue on player's radar in the mission (big ol workaround)
		if (IsAround(aan_cingtow1))
		{
			RemoveObject(aan_cingtow1);
		}

		if (IsAround(aan_cbunk))
		{
			RemoveObject(aan_cbunk);
		}

		if (IsAround(aan_cons))
		{
			RemoveObject(aan_cons);
		}

		aan_cingtow1 = BuildObject("ibgtow",2,"aigtow");//gtow
		aan_cbunk = BuildObject("ibcbun",2,"aicbun");//com bunk
		aan_cons = BuildObject("ivcons",2,"aan_cons");//com bunk

		//factory
		Matrix pos_aan_fact;
		GetPosition(aan_fact,pos_aan_fact);
		RemoveObject(aan_fact);
		aan_fact=BuildObject("ibfact",2,pos_aan_fact);

		//pgen1
		Matrix pos_aanpgen1;
		GetPosition(aanpgen1,pos_aanpgen1);
		RemoveObject(aanpgen1);
		aanpgen1=BuildObject("ibpgen",2,pos_aanpgen1);

		//pgen2
		Matrix pos_aanpgen2;
		GetPosition(aanpgen2,pos_aanpgen2);
		RemoveObject(aanpgen2);
		aanpgen2=BuildObject("ibpgen",2,pos_aanpgen2);

		//recy
		Matrix pos_aan_recy;
		GetPosition(aanrecy,pos_aan_recy);
		RemoveObject(aanrecy);
		aanrecy=BuildObject("ibrecy",2,pos_aan_recy);

		//sbay
		Matrix pos_aan_sbay;
		GetPosition(aansbay,pos_aan_sbay);
		RemoveObject(aansbay);
		aansbay=BuildObject("ibsbay",2,pos_aan_sbay);

		SetScrap(1,40);
		SetScrap(2,40);
		vo1time = (GetTime() + 3);
		vo3time = (GetTime() + 60);
		pk1time = (GetTime() + 70);
		SetPlan("scion0501.aip",2);
		missionstart = true;
	}

	//Scout attacks on player's base near the beginning of mission
	if (!pkover)
	{
		if ((!pk1attack) && (pk1time < GetTime()))
		{
			pk1 = BuildObject("ivscout",3,"pk1");
			SetSkill(pk1,1);
			Goto(pk1,"playerbase");
			pk2time = (GetTime() + 60);
			pk1attack = true;
		}

		if ((!pk2attack) && (pk2time < GetTime()))
		{
			pk2 = BuildObject("ivscout",3,"pk2");
			pk2b = BuildObject("ivscout",3,"pk3");
			SetSkill(pk2,1);
			SetSkill(pk2b,2);
			Goto(pk2,"playerbase");
			Goto(pk2b,"playerbase");
			pk3time = (GetTime() + 60);
			pk2attack = true;
		}

		if ((!pk3attack) && (pk3time < GetTime()))
		{
			AudioMessage("scion0504.wav");  //Manson -- "We just lost a guntower!"
			pk3 = BuildObject("ivmbike",3,"pk1");
			SetSkill(pk3,1);
			Goto(pk3,"playerbase");
			pk4time = (GetTime() + 75);
			pk3attack = true;
		}

		if ((!pk4attack) && (pk4time < GetTime()))
		{
			pk4 = BuildObject("ivtank",3,"pk1");
			pk4b = BuildObject("ivmbike",3,"pk1");
			SetSkill(pk4,1);
			SetSkill(pk4b,1);
			Goto(pk4,"playerbase");
			Goto(pk4b,"playerbase");
			pk5time = (GetTime() + 60);
			pk4attack = true;
		}

		if ((!pk5attack) && (pk5time < GetTime()))
		{
			pk5 = BuildObject("ivscout",3,"pk2");
			pk5b = BuildObject("ivtank",3,"pk1");
			SetSkill(pk5,1);
			SetSkill(pk5b,1);
			Goto(pk5,"playerbase");
			Goto(pk5b,"playerbase");
			pk6time = (GetTime() + 85);
			pk5attack = true;
		}

		if ((!pk6attack) && (pk6time < GetTime()))
		{
			pk6 = BuildObject("ivscout",3,"pk1");
			pk6b = BuildObject("ivscout",3,"pk2");
			SetSkill(pk6,1);
			SetSkill(pk6b,1);
			Goto(pk6,"playerbase");
			Goto(pk6b,"playerbase");
			pk7time = (GetTime() + 70);
			pk6attack = true;
		}

		if ((!pk7attack) && (pk7time < GetTime()))
		{
			pk7 = BuildObject("ivmbike",3,"pk1");
			pk7b = BuildObject("ivtank",3,"pk1b");
			SetSkill(pk7,2);
			SetSkill(pk7b,1);
			Goto(pk7,"playerbase");
			Goto(pk7b,"playerbase");
			pk8time = (GetTime() + 65);
			pk7attack = true;
		}
		
		if ((!pk8attack) && (pk8time < GetTime()))
		{
			pk8 = BuildObject("ivtank",3,"pk1");
			pk8b = BuildObject("ivtank",3,"pk2");
			SetSkill(pk8,1);
			SetSkill(pk8b,2);
			Goto(pk8,"playerbase");
			Goto(pk8b,"playerbase");
			pk9time = (GetTime() + 3);
			pk8attack = true;
		}	

		if ((!pk9attack) && (pk9time < GetTime()))
		{
			pk9 = BuildObject("ivscout",3,"pk1");
			pk9b = BuildObject("ivscout",3,"pk1");
			SetSkill(pk9,1);
			SetSkill(pk9b,2);
			Goto(pk9,"playerbase");
			Goto(pk9b,"playerbase");
			pk10time = (GetTime() + 20);
			pk9attack = true;
		}
		
		if ((!pk10attack) && (pk10time < GetTime()))
		{
			AudioMessage("scion0512.wav");// Manson We just lost power!
			pk10 = BuildObject("ivtank",3,"pk2");
			pk10b = BuildObject("ivscout",3,"pk2");
			pk10c = BuildObject("ivmbike",3,"pk2");
			SetSkill(pk10,1);
			SetSkill(pk10b,1);
			SetSkill(pk10c,2);
			Goto(pk10,"playerbase");
			Goto(pk10b,"playerbase");
			Goto(pk10c,"playerbase");
			pk11time = (GetTime() + 60);
			pk10attack = true;

		}

		if ((!pk11attack) && (pk11time < GetTime()))
		{
			pk11 = BuildObject("ivtank",3,"pk2");
			pk11b = BuildObject("ivtank",3,"pk4");
			pk11c = BuildObject("ivmbike",3,"pk1");
			SetSkill(pk11,2);
			SetSkill(pk11b,2);
			SetSkill(pk11c,1);
			Goto(pk11,"playerbase");
			Goto(pk11b,"playerbase");
			Goto(pk11c,"playerbase");
			pk12time = (GetTime() + 50);
			pk11attack = true;

		}

		if ((!pk12attack) && (pk12time < GetTime()))
		{
			pk12 = BuildObject("ivtank",3,"pk2");
			pk12b = BuildObject("ivtank",3,"pk4");
			pk12c = BuildObject("ivmbike",3,"pk4b");
			SetSkill(pk12,2);
			SetSkill(pk12b,2);
			SetSkill(pk12c,2);
			Goto(pk12,"playerbase");
			Goto(pk12b,"playerbase");
			Goto(pk12c,"playerbase");
			vo2time = (GetTime() + 70);
			pk12attack = true;
			pkover = true;
		}
	}
	
	/////*******//
	////
	if ((!vo1) && (vo1time < GetTime()))
	{
		msg1 = AudioMessage("scion0501.wav"); //scion0501.wav We have no time to waste
		vo1 = true;
	}

	if ((!obj1) && (vo1) && (IsAudioMessageDone(msg1)))
	{
		ClearObjectives();
		AddObjective("scion0501.otf", WHITE);///  Build your base as quickly as possible.
		obj1 = true;
	}

	if ((!vo3) && (vo3time < GetTime()))
	{
		AudioMessage("scion0503.wav"); // scion0503.wav  (AAN BASE)  "Shabayev, hurry with that support, We are taking massive hits."
		vo3 = true;
	}



///telling player "go blow up bridge"
	if ((!vo2) && (vo2time < GetTime()))
	{
		msg2 = AudioMessage("scion0502.wav"); // scion0502.wav --  Ok, there is an ISDF bridge that braddock is using to easily get his forces to the AAN base, lets take it out.  It won't stop him completely but it will slow down his forces.  I'm giving you the coordinates, destroy that bridge.
		after_spawntime = (GetTime() + 120);
		vo2 = true;
	}

	if ((!obj2) && (vo2) && (IsAudioMessageDone(msg2)))
	{
		ClearObjectives();
		AddObjective("scion0502.otf", WHITE); // Destroy the ISDF bridge
		SetObjectiveOn(bseg2);
		TranslateString2(tempstr, sizeof(tempstr), "MissionS0501");  // ISDF Bridge
		SetObjectiveName(bseg2,tempstr);
		playertakingtoolong1time = (GetTime() + 250); //CHANGE THIS!!!
		obj2 = true;
	}

	//this will spawn in a couple scouts to harras the players base after he has left base
	if ((!after_spawn) && (vo2) && (after_spawntime < GetTime()))
	{
		pk1 = BuildObject("ivscout",3,"pk4");	
		SetSkill(pk1,2);
		Goto(pk1,"playerbase");
		after_spawntime = (GetTime() + 250);
	}

	//if player takes too long in getting to bridge and begin defending, I spawn a huge
	//force to nuke the AAN base
	if ((!playertakingtoolong1) && (!playeratbridge) && (playertakingtoolong1time < GetTime()))
	{
		death1 = BuildObject("ivmisl",3,"death1");	
		death2 = BuildObject("ivmisl",3,"death2");
		death3 = BuildObject("ivmisl",3,"death3");
		death4 = BuildObject("ivmisl",3,"death4");
		death5 = BuildObject("ivatank",3,"death5");
		death6 = BuildObject("ivatank",3,"death6");
		death7 = BuildObject("ivatank",3,"death7");
		death8 = BuildObject("ivatank",3,"death8");

		SetMaxHealth(death5,10000);
		SetCurHealth(death5,10000);
		SetMaxHealth(death6,10000);
		SetCurHealth(death6,10000);
		SetMaxHealth(death7,10000);
		SetCurHealth(death7,10000);
		SetMaxHealth(death8,10000);
		SetCurHealth(death8,10000);

		SetSkill(death1,3);
		SetSkill(death2,3);
		SetSkill(death3,3);
		SetSkill(death4,3);
		SetSkill(death5,3);
		SetSkill(death6,3);
		SetSkill(death7,3);
		SetSkill(death8,3);

		SetAvoidType(death1,0);
		SetAvoidType(death2,0);
		SetAvoidType(death3,0);
		SetAvoidType(death4,0);
		SetAvoidType(death5,0);
		SetAvoidType(death6,0);
		SetAvoidType(death7,0);
		SetAvoidType(death8,0);

		Attack(death1,aanrecy);
		Attack(death2,aanrecy);
		Attack(death3,aanrecy);
		Attack(death4,aanrecy);
		Attack(death5,aanrecy);
		Attack(death6,aanrecy);
		Attack(death7,aanrecy);
		Attack(death8,aanrecy);
		shit = true;

		aan_recy_goboomtime = (GetTime() + 50);

		playertakingtoolong1 = true;
	}

	//if the player goes to the AAN base too early, I spawn in the same spawn 
	//to NUKE the base (bad player!)
	if ((!player_at_aan_early) && (!vo2) && (GetDistance(player,"aanbase") < 200))
	{
		death1 = BuildObject("ivmisl",3,"death1");	
		death2 = BuildObject("ivmisl",3,"death2");
		death3 = BuildObject("ivmisl",3,"death3");
		death4 = BuildObject("ivmisl",3,"death4");
		death5 = BuildObject("ivatank",3,"death5");
		death6 = BuildObject("ivatank",3,"death6");
		death7 = BuildObject("ivatank",3,"death7");
		death8 = BuildObject("ivatank",3,"death8");

		SetMaxHealth(death5,10000);
		SetCurHealth(death5,10000);
		SetMaxHealth(death6,10000);
		SetCurHealth(death6,10000);
		SetMaxHealth(death7,10000);
		SetCurHealth(death7,10000);
		SetMaxHealth(death8,10000);
		SetCurHealth(death8,10000);


		SetSkill(death1,3);
		SetSkill(death2,3);
		SetSkill(death3,3);
		SetSkill(death4,3);
		SetSkill(death5,3);
		SetSkill(death6,3);
		SetSkill(death7,3);
		SetSkill(death8,3);

		SetAvoidType(death1,0);
		SetAvoidType(death2,0);
		SetAvoidType(death3,0);
		SetAvoidType(death4,0);
		SetAvoidType(death5,0);
		SetAvoidType(death6,0);
		SetAvoidType(death7,0);
		SetAvoidType(death8,0);

		Attack(death1,aanrecy);
		Attack(death2,aanrecy);
		Attack(death3,aanrecy);
		Attack(death4,aanrecy);
		Attack(death5,aanrecy);
		Attack(death6,aanrecy);
		Attack(death7,aanrecy);
		Attack(death8,aanrecy);
		shit = true;

		aan_recy_goboomtime = (GetTime() + 50);

		player_at_aan_early = true;
	}

	//nuking the ann recycler as a result of the above
	if ((shit) && (!aan_recy_goboom) &&  (aan_recy_goboomtime) < GetTime())
	{
		Damage(aanrecy,999999);
		aan_recy_goboom = true;
	}

////spawning in 2 IVATANK to be crossing the bridge when the player is there
	if ((!playeratbridge) && (vo2) && (GetDistance(player,bstr1) < 190))
	{
		atank1 = BuildObject("ivatank",3,"atankspawn");
		atank2 = BuildObject("ivatank",3,"atankspawn2");
		SetMaxHealth(atank1,4500);
		SetCurHealth(atank1,4500);
		SetMaxHealth(atank2,4500);
		SetCurHealth(atank2,4500);
		SetSkill(atank1,1);
		SetSkill(atank2,1);
		Retreat(atank1,"bridgepath");
		Retreat(atank2,"bridgepath");
		playeratbridge = true;
	}

	//if player attacks the ASSTANKS before they can cross the bridge, their
	//independance gets set back to 1

	if ((!ass1_attacked) && (playeratbridge) && (GetCurHealth(atank1) < 4450))
	{
		SetIndependence(atank1,1);
		ass1_attacked = true;
	}

	if ((!ass2_attacked) && (playeratbridge) && (GetCurHealth(atank2) < 4450))
	{
		SetIndependence(atank2,1);
		ass2_attacked = true;
	}


//This sets the Ass Tanks independance back to 1 after i've told them to retreat over the bridge
	if ((!reset_bridge_tanks) && (playeratbridge))
	{
		if ((!reset_atank1) && (GetDistance(atank1,"endbridgepath") < 25))
		{
			SetIndependence(atank1,1);
			reset_atank1 = true;
		}

		if ((!reset_atank2) && (GetDistance(atank2,"endbridgepath") < 25))
		{
			SetIndependence(atank2,1);
			reset_atank2 = true;
		}

		if ((reset_atank1) && (reset_atank2))
		{
			reset_bridge_tanks = true;
		}
	}
//if player destroys bridge before the atanks can cross, they are just told to Goto the player
	if ((!reroute1) && (playeratbridge) && (bridgegoboomover))
	{
		if (IsAround(atank1))
		{
			Goto(atank1,"player");
		}

		if (IsAround(atank2))
		{
			Goto(atank2,"player");
		}	

		reroute1 = true;
	}
//when bridge is destroyed and the area is clear
	if ((!bridgedone) && (bridgegoboomover) && (playeratbridge) &&
		(!IsAround(bridgetank) && (!IsAround(bridgescout) && (!IsAround(atank1)
		&& (!IsAround(atank2))))))
	{
		vo5time = (GetTime() + 5);
		bridgedone = true;
	}


	if ((!vo5) && (vo2) && (vo5time < GetTime()))
	{
		msg5 = AudioMessage("scion0505.wav");	// scion0505.wav Good job cook. That won't stop them completely but it will slow them down.  Now, go to the AAN base and help defend it from the incoming waves!
		vo5 = true;
	}

	if ((!obj3) && (vo5) && (IsAudioMessageDone(msg5)))
	{
		ClearObjectives();
		AddObjective("scion0503.otf", WHITE); // Goto the AAN base and help in it's defense against Braddock's forces.	
		aanbase = BuildObject("ibnav",1,"aan_base");
		SetObjectiveOn(aanbase);
		TranslateString2(tempstr, sizeof(tempstr), "MissionS0502");  // AAN Base
		SetObjectiveName(aanbase,tempstr);
		obj3 = true;
	}

/// Player reaches the AAN base
	if ((!playeratAAN) && (vo5) && (GetDistance(player,"aanbase") < 200))
	{  //WAVE 1
		msg6 = AudioMessage("scion0506.wav"); // scion0506.wav AAN BASE.  Cook, thank god you are here.  Help us stave off Braddock's forces!  I'm having my recycler make some repair and ammo  pods for you, to help you through the next few waves.  
		SetPlan("scion0502.aip",2);
		ChangePlanTime1 = (GetTime() + 50);
		SetObjectiveOff(aanbase);
		playeratAAN = true;
	}

	if ((!delay1) && (playeratAAN) && (IsAudioMessageDone(msg6)))
	{
		vo7time = (GetTime() +5);
		delay1 = true;
	}

//SHAB IS TELLING COOK TO BUILD A GUN SPIRE AT THE LOCATION SHE GIVES
	if ((!vo7) && (vo7time < GetTime()))
	{
		msg7 = AudioMessage("scion0507.wav"); // scion0507 SHAB FROM SCION BASE - Cook, I want you to build a Gun Spire near the main chokepoint into the AAN base, I will objectify just where I want you to build it.  This should help you considerably.
		spawn1time = (GetTime() + 2);
		vo7 = true;
	}

	if ((!obj4) && (vo7) && (IsAudioMessageDone(msg7)))
	{
		spire1site = BuildObject("ibnav",1,"spire1site");
		ClearObjectives();
		AddObjective("scion0504.otf", WHITE); // build a gun spire at the specified location
		SetObjectiveOn(spire1site);
		TranslateString2(tempstr, sizeof(tempstr), "MissionS0503");  // Gun Spire Site
		SetObjectiveName(spire1site,tempstr);
		obj4 = true;
	}

	//Checking to see when the spire is built
	if ((!spire1built) && (vo7) && (IsAround(gspire1) && (GetDistance(gspire1,"spire1site") < 200)))
	{
		vo8time = (GetTime() + 3);
		spire1built = true;
	}

	if ((!vo8) && (vo8time < GetTime()))
	{
		AudioMessage("scion0508.wav");	// scion0508.wav Good job, now just try to hold off the rest of the waves. (confirmation of spire being built)
		SetObjectiveOff(spire1site);
		ClearObjectives();
		AddObjective("scion0504a.otf", WHITE);
		AddObjective("scion0504b.otf", GREEN);
		vo8 = true;
	}

	///This changes the plan back to the default plan after the AAN base has made health for player
	if ((!changeplan1) && (ChangePlanTime1 < GetTime()))
	{
		SetPlan("scion0501.aip",2);	
		changeplan1 = true;
	}

	//incoming waves of braddock's forces VS the AAN base
	//WAVE 1
	if (playeratAAN)
	{
		if ((!spawn1) && (spawn1time < GetTime()))
		{
			spawner1 = BuildObject("ivtank",3,"spawn4");
			spawner2 = BuildObject("ivtank",3,"spawn1");
			SetSkill(spawner1,1);
			SetSkill(spawner2,1);
			Goto(spawner1,"aanbase");
			Goto(spawner2,"aanbase");
			spawn2time = (GetTime() + 60);
			spawn3time = (GetTime() + 145);
			spawn4time = (GetTime() + 245);
			spawn5time = (GetTime() + 350);
			spawn6time = (GetTime() + 450);
			spawn7time = (GetTime() + 550);
			spawn8time = (GetTime() + 655);
			spawn9time = (GetTime() + 755);
			spawn10time = (GetTime() + 850);
		//	spawn11time = (GetTime() + 690);
		//	spawn12time = (GetTime() + 690);
			spawn1 = true;
		
		}

		//WAVE 2
		if ((!spawn2) && (spawn2time < GetTime()))
		{
			spawner4 = BuildObject("ivatank",3,"spawn4");
			spawner5 = BuildObject("ivatank",3,"spawn3");	
			SetSkill(spawner4,1);
			SetSkill(spawner5,1);
			Goto(spawner4,"trackedpath");
			Goto(spawner5,"trackedpath");
			spawn2 = true;
		}

	// WAVES 3 - 8 ATTACKING THE AAN BASE
		if ((!spawn3) && (spawn3time < GetTime()))
		{
			spawner6 = BuildObject("ivscout",3,"pk1");	
			spawner7 = BuildObject("ivtank",3,"below1");
			spawner8 = BuildObject("ivtank",3,"below2");
			SetSkill(spawner6,0);
			SetSkill(spawner7,0);
			SetSkill(spawner8,1);
			Goto(spawner6,"hoverpath");
			Goto(spawner7,"hoverpath");
			Goto(spawner8,"hoverpath");
			spawn3 = true;
		}

		if ((!spawn4) && (spawn4time < GetTime()))
		{
			spawner9 = BuildObject("ivtank",3,"death7");	
			spawner10 = BuildObject("ivscout",3,"death8");
			SetSkill(spawner9,1);
			SetSkill(spawner10,1);
			Goto(spawner9,"hoverpath");
			Goto(spawner10,"hoverpath");
			spawn4 = true;
		}

		if ((!spawn5) && (spawn5time < GetTime()))
		{
			spawner11 = BuildObject("ivtank",3,"below1");	
			spawner12 = BuildObject("ivtank",3,"below2");

			spawner14 = BuildObject("ivscout",3,"spawn3");		
			SetSkill(spawner11,1);
			SetSkill(spawner12,1);

			SetSkill(spawner14,1);		
			Goto(spawner11,"hoverpath");
			Goto(spawner12,"hoverpath");

			Goto(spawner14,"hoverpath");
			spawn5 = true;
		}

		if ((!spawn6) && (spawn6time < GetTime()))
		{
			spawner13 = BuildObject("ivtank",3,"spawn2");
			spawner15 = BuildObject("ivtank",3,"spawn4");	
			spawner16 = BuildObject("ivtank",3,"spawn1");
			SetSkill(spawner13,1);	
			SetSkill(spawner15,1);
			SetSkill(spawner16,1);
			Goto(spawner13,"hoverpath");
			Goto(spawner15,"hoverpath");
			Goto(spawner16,"hoverpath");
			spawn6 = true;
		}

		if ((!spawn7) && (spawn7time < GetTime()))
		{
			spawner17 = BuildObject("ivtank",3,"pk1");	
			spawner18 = BuildObject("ivatank",3,"spawn1");
			spawner19 = BuildObject("ivatank",3,"spawn2");
			SetSkill(spawner17,1);
			SetSkill(spawner18,1);
			SetSkill(spawner19,2);
			Goto(spawner17,"hoverpath");
			Goto(spawner18,"trackedpath");
			Goto(spawner19,"trackedpath");
			spawn7 = true;
		}

		if ((!spawn8) && (spawn8time < GetTime()))
		{
			spawner20 = BuildObject("ivwalk",3,"walk2spawn");	
			spawner21 = BuildObject("ivwalk",3,"walk1spawn");
			spawner22 = BuildObject("ivtank",3,"spawn1");
			SetSkill(spawner20,1);
			SetSkill(spawner21,1);
			SetSkill(spawner22,2);
			Goto(spawner20,"walkerpath");
			Goto(spawner21,"walkerpath");
			Goto(spawner22,"hoverpath");
			spawn8 = true;
		}

		if ((!spawn9) && (spawn9time < GetTime()))
		{
			spawner1 = BuildObject("ivwalk",3,"walk2spawn");	
			spawner2 = BuildObject("ivwalk",3,"walk1spawn");
			spawner3 = BuildObject("ivatank",3,"below1");
			SetSkill(spawner1,1);
			SetSkill(spawner2,1);
			SetSkill(spawner3,2);
			Goto(spawner1,"walkerpath");
			Goto(spawner2,"walkerpath");
			Goto(spawner3,"hoverpath");
			after_spawn = true;
			spawn9 = true;
		}

		if ((!spawn10) && (spawn10time < GetTime()))
		{
			lastspawn1 = BuildObject("ivwalk",3,"walk2spawn");	
			lastspawn2 = BuildObject("ivwalk",3,"walk1spawn");
			lastspawn3 = BuildObject("ivatank",3,"spawn1");
			SetSkill(lastspawn1,1);
			SetSkill(lastspawn2,1);
			SetSkill(lastspawn3,2);
			Goto(lastspawn1,"walkerpath");
			Goto(lastspawn2,"walkerpath");
			Goto(lastspawn3,"hoverpath");
			spawn10 = true;
		}
	}

//****CONDITIONS FOR MISSION WIN****//
	//When all of Braddocks waves have been killed and tha AAN base is OK
	if ((!wavesover) && (spawn10) && (!IsAround(lastspawn1) && (!IsAround(lastspawn2)
		&& (!IsAround(lastspawn3)))))
	{
		vo10time = (GetTime() + 5);
		wavesover = true;
	}

	if ((!vo10) && (vo10time < GetTime()))
	{
		msg10 = AudioMessage("scion0510.wav");	// scion0510.wav "it appears we've defeated the bulk of braddock's forces...."
		vo10 = true;
	}

	if ((!obj6) && (vo10) && (IsAudioMessageDone(msg10)))
	{
		ClearObjectives();
		AddObjective("scion0506.otf", WHITE); // MISSION ACCOMPLISHED
		SucceedMission(GetTime() + 15,"scion05w1.txt");
		obj6 = true;
	}

	//****CONDITIONS FOR MISSION FAILURE****///
// if the AAN recycler is destroyed..
	if ((!aanrecykilled) && (missionstart) && (!IsAround(aanrecy)))
	{
		vo9time = (GetTime() + 5);
		aanrecykilled = true;
	}

	if ((!vo9) && (vo9time < GetTime()))
	{
		msg9 = AudioMessage("scion0509.wav");	// scion0509.wav The AAN recylcer has been destroyed! 
		vo9 = true;
	}

	if ((!obj5) && (vo9) && (IsAudioMessageDone(msg9)))
	{
		ClearObjectives();
		AddObjective("scion0505.otf", WHITE);
		FailMission(GetTime() + 5,"scion05L1.txt");
		obj5 = true;
	}

	//if the player's recycler is ever destroyed--MISSION FAILED
	if ((!playersrecy_dead) && (!IsAround(playersrecy)))
	{
		vo_recydeadtime = (GetTime() + 3);
		playersrecy_dead = true;
	}

	if ((!vo_recydead) && (vo_recydeadtime < GetTime()))
	{
		vofail1 = AudioMessage("scion0599.wav"); //TEMP to be replaced with standard "our recycler has been destroyed" asset//Dammit cooke, the recycler has been destroyed
		vo_recydead = true;
	}

	if ((!obj7) && (vo_recydead) && (IsAudioMessageDone(vofail1)))
	{
		ClearObjectives();
		AddObjective("scion0507.otf", WHITE);
		FailMission(GetTime() + 6,"scion05L2.txt");
		obj7 = true;
	}

//****HELPING THE AIP****//
	///BASETURR1
	if ((!checkturret1alive) && (IsAlive(baseturr1)))	
	{
		turret1movetime = (GetTime() + 2);
		turret1alive = true;
		checkturret1alive = true;
		checkturret1dead = false;
		turret1go = false;
	}

	if ((!checkturret1dead) && (!IsAlive(baseturr1)))
	{
		turret1alive = false;
		checkturret1alive = false;
		checkturret1dead = true;
	}

	if ((!turret1go) && (turret1alive) && (turret1movetime < GetTime()))
	{
		Goto(baseturr1,"baseturr1");
		turret1go = true;
	}

///BASETANK1

	if (basetank1alive)
	{
		if ((!basetank1go) && (basetank1movetime < GetTime()))
		{
			Goto(basetank1,"basetank1");
			basetank1go = true;
		}

		if (!IsAlive(basetank1))
		{
			basetank1alive = false;
		}
	}

///BASETANK2
	if (basetank2alive)
	{
		if ((!basetank2go) && (basetank2movetime < GetTime()))
		{
			Goto(basetank2,"basetank2");
			basetank2go = true;
		}

		if (!IsAlive(basetank2))
		{
			basetank2alive = false;
		}
	}

///BASETANK3
	if (basetank3alive)
	{
		if ((!basetank3go) && (basetank3movetime < GetTime()))
		{
			Goto(basetank3,"basetank3");
			basetank3go = true;
		}

		if (!IsAlive(basetank3))
		{
			basetank3alive = false;
		}
	}

//////////////////////	
	///THIS IS FOR THE BRIDGE THAT GETS BLOWN UP
	// If one seg of the bridge is blown up, the other segs blow.  BRIDGE GO BOOM
	if (!bridgegoboom)
	{
		if ((!IsAround(bseg1)))
		{
			bstr2boomtime = (GetTime() + .7f);
			bseg2boomtime = (GetTime() + .7f);
			bseg3boomtime = (GetTime() + 1.4f);
			bstr1boomtime = (GetTime() + 2.1f);
			bridgegoboom = true;
		}

		if ((!IsAround(bseg2)))
		{
			bstr2boomtime = (GetTime() + 1.4f);
			bseg1boomtime = (GetTime() + .7f);
			bseg3boomtime = (GetTime() + .7f);
			bstr1boomtime = (GetTime() + 1.4f);
			bridgegoboom = true;
		}
	
		if ((!IsAround(bseg3)))
		{
			bstr2boomtime = (GetTime() + 2.1f);
			bseg1boomtime = (GetTime() + 1.4f);
			bseg2boomtime = (GetTime() + .7f);
			bstr1boomtime = (GetTime() + .7f);
			bridgegoboom = true;
		}

		if ((!IsAround(bstr1)))
		{
			bstr2boomtime = (GetTime() + 2.8f);
			bseg1boomtime = (GetTime() + 2.1f);
			bseg2boomtime = (GetTime() + 1.4f);
			bseg3boomtime = (GetTime() + .7f);
			bridgegoboom = true;
		}

		if ((!IsAround(bstr2)))
		{
			bstr1boomtime = (GetTime() + 2.8f);
			bseg1boomtime = (GetTime() + .7f);
			bseg2boomtime = (GetTime() + 1.4f);
			bseg3boomtime = (GetTime() + 2.1f);
			bridgegoboom = true;
		}
	}

	if (!bridgegoboomover)
	{
		if ((!bseg1goboom) && (bseg1boomtime <= GetTime()))
		{
			Damage(bseg1,6000);
			bseg1goboom = true;
		}

		if ((!bseg2goboom) && (bseg2boomtime <= GetTime()))
		{
			Damage(bseg2,6000);
			bseg2goboom = true;
		}

		if ((!bseg3goboom) && (bseg3boomtime <= GetTime()))
		{
			Damage(bseg3,6000);
			bseg3goboom = true;
		}

		if ((!bstr1goboom) && (bstr1boomtime <= GetTime()))
		{
			Damage(bstr1,6000);
			RemoveObject(bstr1);
			bstr1goboom = true;
		}

		if ((!bstr2goboom) && (bstr2boomtime <= GetTime()))
		{
			Damage(bstr2,6000);
			RemoveObject(bstr2);
			bstr2goboom = true;
		}

		if ((!IsAround(bstr1) && (!IsAround(bstr2) && (!IsAround(bseg1) && (!IsAround(bseg2)
			&& (!IsAround(bseg3)))))))
		{
			bridgegoboomover = true;
		}
	}
/////
/////
/////
}
