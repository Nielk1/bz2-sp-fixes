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
		start_done, out_of_ship,game_over,first_message,first_over,scrap_message,
		guard1a, guard2a, guard3a, guard4a,sent1a, sent2a, sent3a, sent4a,
		war1a, war2a, war3a, war4a,lance1a, lance2a, lance3a, lance4a,
		scout1a, scout2a, scout3a, scout4a,power1a,power2a,power3a,power4a,
		titana,guntower1a,guntower2a,guntower3a,guntower4a,power_message,change_otf1,
		send_second,change_otf2,change_otf3,player_in_scav,scav1_alive,scav2_alive,
		pilot_made,build_health_set,guntower_show,base_powered,scav_deployed,
		powered_message1,training_message,first_done,base_first,scav_first,train_first,
		second_done,train_second,scav_second,base_second,last_done,new_plan1,
		scav1_deployed,scav2_deployed,scav3_deployed,titan_attack,last_aip,
		power_explained,
		b_last;

	// floats
	float
		f_first,
		land_time,guntower_check,power_check,scav_check,titan_time,
		f_last;

	// handles
	Handle
		h_first,bigass_machine,
		player,srecycler,
		factory,service,armory,training,commbunk1,
		power1,power2,power3,power4,
		guntower1,guntower2,guntower3,guntower4,
		dmound1,dmound2,
		scav1,scav2,empty_scav1,empty_scav2,
		sscav1,sscav2,sscav3,
		forge,overseer,dower,stronghold,
		spire1,spire2,spire3,spire4,
		guard1, guard2, guard3, guard4,
		sent1, sent2, sent3, sent4,
		war1, war2, war3, war4,
		lance1, lance2, lance3, lance4,
		scout1, scout2, scout3, scout4,
		tank1,tank2,tbolt1,tbolt2,rocket1,
		titan,talk,
		key_device,tugger,constructor,tug,
		spool1,spool2,spool3,
		pilot,
		pool1_nav,pool2_nav,pool3_nav,
		titan1,titan2,
		scav_a,scav_b,scav_c,
		start_sent1,start_sent2,start_war1,start_war2,start_war3,
		sturret1,sturret2,sturret3,sturret4,sturret5,
		sturret6,sturret7,sturret8,sturret9,sturret10,
		cons2,
		h_last;

	// integers
	int
		i_first,
		a,b,c,d,e,f,z,
		buildings,power,
		i_last;
};

DLLBase * BuildMission(void)
{
	return new Misn04Mission();
}

// this is big messy code to determine when the base has power

bool IsPowered(Handle bld)
{
	int a,b,c,d,e,f,z;
	int buildings,power;
	bool powered;

	a = CountUnitsNearObject(0,99999.0f,1,"ibfact");// factory
	b = CountUnitsNearObject(0,99999.0f,1,"ibarmo");// armory
	c = CountUnitsNearObject(0,99999.0f,1,"ibsbay");// service bay
	d = CountUnitsNearObject(0,99999.0f,1,"ibcbun");// comm bunker
	e = CountUnitsNearObject(0,99999.0f,1,"ibtrain");// training facility 
	f = CountUnitsNearObject(0,99999.0f,1,"ibgtow");// gun towers
	z = CountUnitsNearObject(0,99999.0f,1,"ibpgen");// power

	buildings = a+b+c+d+e+f;
	power = z;

	powered = false;
	if (buildings > power)
	{
		if (((buildings == 2) && (power == 1)) ||
			((buildings == 3) && (power == 1)) ||
			((buildings == 4) && (power == 2)) ||
			((buildings == 5) && (power == 2)) ||
			((buildings == 6) && (power == 2)) ||
			((buildings == 7) && (power == 3)))
		{
			powered = true;
		}
	}
	else
	{
		powered = true;
	}
	return powered;
}

void Misn04Mission::Setup(void)
{
	SetAutoGroupUnits(false);
/*
	Here's where you set the values at the start.  
*/

//  bools
	start_done = false;
	out_of_ship = true;
	game_over = false;
	first_message = true;
	first_over = false;
	scrap_message = false;
	guard1a = false;
	guard2a = false;
	guard3a = false;
	guard4a = false;
	sent1a = true;
	sent2a = true;
	sent3a = false;
	sent4a = false;
	war1a = true;
	war2a = true;
	war3a = true;
	war4a = false;
	lance1a = false;
	lance2a = false;
	lance3a = false;
	lance4a = false;
	scout1a = false;
	scout2a = false;
	scout3a = false;
	scout4a = false;
	titana = false;
	power1a = true;
	power2a = false;
	power3a = false;
	power4a = false;
	guntower1a = true;
	guntower2a = true;
	guntower3a = false;
	guntower4a = false;
	send_second = false;
	power_message = false;
	change_otf1 = false;
	change_otf2 = false;
	change_otf3 = false;
	player_in_scav = false;
	scav1_alive = false;
	scav2_alive = false;
	pilot_made = false;
	build_health_set = false;
	guntower_show = false;
	base_powered = false;
	scav_deployed = false;
	powered_message1 = false;
	training_message = false;
	first_done = false;
	base_first = false;
	scav_first = false;
	train_first = false;
	second_done = false;
	train_second = false;
	scav_second = false;
	base_second = false;
	last_done = false;
	new_plan1 = false;
	scav1_deployed = false;
	scav2_deployed = false;
	scav3_deployed = false;
	titan_attack = false;
	last_aip = false;
	power_explained = false;


//  floats
	land_time = 999999.9f;
	guntower_check = 999999.9f;
	power_check = 999999.9f;
	scav_check = 999999.9f;
	titan_time = 999999.9f;

//  handles
	player = GetPlayerHandle();
	srecycler = GetHandle("srecycler");
	factory = GetHandle("factory");
	service = GetHandle("service");
	armory = GetHandle("armory");
	training = GetHandle("training");
	commbunk1 = GetHandle("commbunk1");
	power1 = GetHandle("power1");
	power2 = NULL;
	power3 = NULL;
	power4 = NULL;
	guntower1 = GetHandle("guntower1");
	guntower2 = GetHandle("guntower2");
	guntower3 = GetHandle("guntower3");
	guntower4 = NULL;
	scav1 = GetHandle("scav1");
	empty_scav1 = GetHandle("empty_scav");
	empty_scav2 = GetHandle("scav2");
	sscav1 = GetHandle("sscav1");
	sscav2 = GetHandle("sscav2");
	sscav3 = GetHandle("sscav3");
	forge = GetHandle("forge");
	overseer = GetHandle("overseer");
	dower = GetHandle("dower");
	stronghold = GetHandle("stronghold");
	spire1 = GetHandle("spire1");
	spire2 = GetHandle("spire2");
	spire3 = GetHandle("spire3");
	spire4 = NULL;
	bigass_machine = GetHandle("bigass_machine");
	tank1 = GetHandle("tank1");
	tank2 = GetHandle("tank2");
	tbolt1 = GetHandle("scout1");
	tbolt2 = GetHandle("scout2");
	rocket1 = GetHandle("rocket1");
	constructor = GetHandle("constructor");
	tug = GetHandle("tug");
	//spool1 = GetHandle("spool1");
	//spool2 = GetHandle("spool2");
	//spool3 = GetHandle("spool3");
	pool1_nav = GetHandle("pool1_nav");
	pool2_nav = GetHandle("pool2_nav");
	pool3_nav = GetHandle("pool3_nav");
	titan1 = GetHandle("titan1");
	titan2 = GetHandle("titan2");
	key_device = GetHandle("key_device");
	sturret1 = GetHandle("sturret1");
	sturret2 = GetHandle("sturret2");
	sturret3 = GetHandle("sturret3");
	sturret4 = GetHandle("sturret4");
	sturret5 = GetHandle("sturret5");
	sturret6 = GetHandle("sturret6");
	sturret7 = GetHandle("sturret7");
	sturret8 = GetHandle("sturret8");
	sturret9 = GetHandle("sturret9");
	sturret10 = GetHandle("sturret10");
	scav_a = NULL;
	scav_b = NULL;
	scav_c = NULL;
	guard1 = NULL;
	guard2 = NULL;
	guard3 = NULL;
	guard4 = NULL;
	sent1 = NULL;
	sent2 = NULL;
	sent3 = NULL;
	sent4 = NULL;
	war1 = NULL;
	war2 = NULL;
	war3 = NULL;
	war4 = NULL;
	lance1 = NULL;
	lance2 = NULL;
	lance3 = NULL;
	lance4 = NULL;
	scout1 = NULL;
	scout2 = NULL;
	scout3 = NULL;
	scout4 = NULL;
	titan = NULL;
	tugger = NULL;
	talk = NULL;
	pilot = NULL;
	start_sent1 = NULL;
	start_sent2 = NULL;
	start_war1 = NULL;
	start_war2 = NULL;
	start_war3 = NULL;
	cons2 = NULL;



//  integers
	a = 0; b = 0; c = 0; d = 0; e = 0; f = 0; z = 0; 
	buildings = 0; power = 0; 

}

void Misn04Mission::AddObject(Handle h)
{
	char ODFName[64];
	GetObjInfo(h, Get_CFG, ODFName);

	if (first_over)
	{
		// ISDF POWER PLANTS
		if ((power1 == NULL) && (IsOdf2(h,"ibpgen")))
		{
			power1 = h;
			power1a = true;
		}
		else if ((power2 == NULL) && (IsOdf2(h,"ibpgen")))
		{
			power2 = h;
			power2a = true;
		}
		else if ((power3 == NULL) && (IsOdf2(h,"ibpgen")))
		{
			power3 = h;
			power3a = true;
		}
		else if ((power4 == NULL) && (IsOdf2(h,"ibpgen")))
		{
			power4 = h;
			power4a = true;
		}

		// SCAV DEPLOYED
		else if ((!scav_deployed) && (IsOdf2(h,"ibscav")))
		{
			float a = (GetDistance(h,"scav1_point"));
			float b = (GetDistance(h,"scav2_point"));
			float c = (GetDistance(h,"scav3_point"));

			if ((a<b) && (a<c))
			{
				scav_a = h;
			}
			else if ((b<a) && (b<c))
			{
				scav_b = h;
			}
			else
			{
				scav_c = h;
			}

			scav1_deployed = true;
			scav_deployed = true;
		}
		else if ((scav1_deployed) && (!scav2_deployed) && (IsOdf2(h,"ibscav")))
		{
			float a = (GetDistance(h,"scav1_point"));
			float b = (GetDistance(h,"scav2_point"));
			float c = (GetDistance(h,"scav3_point"));

			if ((a<b) && (a<c))
			{
				scav_a = h;
			}
			else if ((b<a) && (b<c))
			{
				scav_b = h;
			}
			else
			{
				scav_c = h;
			}

			scav2_deployed = true;
		}
		else if ((scav2_deployed) && (!scav3_deployed) && (IsOdf2(h,"ibscav")))
		{
			if ((a<b) && (a<c))
			{
				scav_a = h;
			}
			else if ((b<a) && (b<c))
			{
				scav_b = h;
			}
			else
			{
				scav_c = h;
			}

			titan_time = GetTime() + 300.0f;
			scav3_deployed = true;
		}		


		// ISDF GUNTOWERS
		else if ((guntower1 == NULL) && (IsOdf2(h,"ibgtow")))
		{
			guntower1 = h;
			guntower1a = true;
		}
		else if ((guntower2 == NULL) && (IsOdf2(h,"ibgtow")))
		{
			guntower2 = h;
			guntower2a = true;
		}
		else if ((guntower3 == NULL) && (IsOdf2(h,"ibgtow")))
		{
			guntower3 = h;
			guntower3a = true;
		}
		else if ((guntower4 == NULL) && (IsOdf2(h,"ibgtow")))
		{
			guntower4 = h;
			guntower4a = true;
		}

		// SCOUT
		if ((scout1 == NULL) && (IsOdf2(h,"fvscout")))
		{
			scout1 = h;
			scout1a = true;
		}
		else if ((scout2 == NULL) && (IsOdf2(h,"fvscout")))
		{
			scout2 = h;
			scout2a = true;
		}
		else if ((scout3 == NULL) && (IsOdf2(h,"fvscout")))
		{
			scout3 = h;
			scout3a = true;
		}
		else if ((scout4 == NULL) && (IsOdf2(h,"fvscout")))
		{
			scout4 = h;
			scout4a = true;
		}
		
		// GUARDIAN
		else if ((guard1 == NULL) && (IsOdf2(h,"fvturr")))
		{
			guard1 = h;
			guard1a = true;
		}
		else if ((guard2 == NULL) && (IsOdf2(h,"fvturr")))
		{
			guard2 = h;
			guard2a = true;
		}
		else if ((guard3 == NULL) && (IsOdf2(h,"fvturr")))
		{
			guard3 = h;
			guard3a = true;
		}
		else if ((guard4 == NULL) && (IsOdf2(h,"fvturr")))
		{
			guard4 = h;
			guard4a = true;
		}

		// SENTRY
		else if ((sent1 == NULL) && (IsOdf2(h,"fvsent")))
		{
			sent1 = h;
			sent1a = true;
		}
		else if ((sent2 == NULL) && (IsOdf2(h,"fvsent")))
		{
			sent2 = h;
			sent2a = true;
		}
		else if ((sent3 == NULL) && (IsOdf2(h,"fvsent")))
		{
			sent3 = h;
			sent3a = true;
		}
		else if ((sent4 == NULL) && (IsOdf2(h,"fvsent")))
		{
			sent4 = h;
			sent4a = true;
		}

		// WARRIOR
		else if ((war1 == NULL) && (IsOdf2(h,"fvtank")))
		{
			war1 = h;
			war1a = true;
		}
		else if ((war2 == NULL) && (IsOdf2(h,"fvtank")))
		{
			war2 = h;
			war2a = true;
		}
		else if ((war3 == NULL) && (IsOdf2(h,"fvtank")))
		{
			war3 = h;
			war3a = true;
		}
		else if ((war4 == NULL) && (IsOdf2(h,"fvtank")))
		{
			war4 = h;
			war4a = true;
		}

		// LANCER
		else if ((lance1 == NULL) && (IsOdf2(h,"fvarch")))
		{
			lance1 = h;
			lance1a = true;
		}
		else if ((lance2 == NULL) && (IsOdf2(h,"fvarch")))
		{
			lance2 = h;
			lance2a = true;
		}
		else if ((lance3 == NULL) && (IsOdf2(h,"fvarch")))
		{
			lance3 = h;
			lance3a = true;
		}
		else if ((lance4 == NULL) && (IsOdf2(h,"fvarch")))
		{
			lance4 = h;
			lance4a = true;
		}
		
		// MAULERS
		else if ((titan == NULL) && (IsOdf2(h,"fvwalk")))
		{
			titan = h;
			titana = true;
		}
	}
	else
	{
		/*
			This is to prevent stray scion pilots
			from jumping into scavengers and making
			the mission un-winable.  

		*/
		if (IsOdf2(h,"fspilo"))
		{
			RemoveObject(h);
		}
	}
}

void Misn04Mission::Execute(void)
{
/*
	Here is where you put what happens every frame.  
*/

	player = GetPlayerHandle();	
	char tempstr[128];

	// this is reseting the vaules when things are built

	if ((guard1a) && (!IsAlive(guard1)))
	{
		guard1a = false;
	}
	if ((guard2a) && (!IsAlive(guard2)))
	{
		guard2a = false;
	}
	if ((guard3a) && (!IsAlive(guard3)))
	{
		guard3a = false;
	}
	if ((guard4a) && (!IsAlive(guard4)))
	{
		guard4a = false;
	}

	if ((sent1a) && (!IsAlive(sent1)))
	{
		sent1a = false;
	}
	if ((sent2a) && (!IsAlive(sent2)))
	{
		sent2a = false;
	}
	if ((sent3a) && (!IsAlive(sent3)))
	{
		sent3a = false;
	}
	if ((sent4a) && (!IsAlive(sent4)))
	{
		sent4a = false;
	}

	if ((war1a) && (!IsAlive(war1)))
	{
		war1a = false;
	}
	if ((war2a) && (!IsAlive(war2)))
	{
		war2a = false;
	}
	if ((war3a) && (!IsAlive(war3)))
	{
		war3a = false;
	}
	if ((war4a) && (!IsAlive(war4)))
	{
		war4a = false;
	}

	if ((lance1a) && (!IsAlive(lance1)))
	{
		lance1a = false;
	}
	if ((lance2a) && (!IsAlive(lance2)))
	{
		lance2a = false;
	}
	if ((lance3a) && (!IsAlive(lance3)))
	{
		lance3a = false;
	}
	if ((lance4a) && (!IsAlive(lance4)))
	{
		lance4a = false;
	}

	if ((scout1a) && (!IsAlive(scout1)))
	{
		scout1a = false;
	}
	if ((scout2a) && (!IsAlive(scout2)))
	{
		scout2a = false;
	}
	if ((scout3a) && (!IsAlive(scout3)))
	{
		scout3a = false;
	}
	if ((scout4a) && (!IsAlive(scout4)))
	{
		scout4a = false;
	}
	
	if ((titana) && (!IsAlive(titan)))
	{
		titana = false;
	}
	////////////////////////////////////////////


	// this is checking to see if the player is out of his ship
	char ODFName[64];
	GetObjInfo(player, Get_CFG, ODFName);

	if (IsOdf2(player,"ispilo"))
	{
		out_of_ship = true;
	}
	else
	{
		out_of_ship = false;
	}
	////////////////////////////////////////////


	// this is kepping the bigass machine alive

	if (IsAround(bigass_machine))
	{
		if (GetCurHealth(bigass_machine) < 4000)
		{
			SetCurHealth(bigass_machine,4000);
		}
	}
	////////////////////////////////////////////


	// this is keeping the key device alive

	if (IsAround(key_device))
	{
		if (GetCurHealth(key_device) < 4000)
		{
			SetCurHealth(key_device,4000);
		}
	}
	////////////////////////////////////////////


	if (!start_done)
	{
		ClearObjectives();
		AddObjective("isdf1201.otf", WHITE);
		
		start_sent1 = BuildObject("fvsent",2,"sent1_spawn");
		start_sent2 = BuildObject("fvsent",2,"sent2_spawn");
		start_war1 = BuildObject("fvtank",2,"war1_spawn");
		start_war2 = BuildObject("fvtank",2,"war2_spawn");
		start_war3 = BuildObject("fvtank",2,"war3_spawn");
		cons2 = BuildObject("ivcons",1,"train_point");
		SetGroup(cons2,4);

		SetSkill(spire1,2);
		SetSkill(spire2,3);
		SetSkill(spire3,2);
		SetSkill(start_war2,2);
		SetSkill(start_war3,2);
		SetSkill(rocket1,2);

		SetPlan("isdf1204.aip",2);

		//Goto(sscav1,spool1);
		//Goto(sscav2,spool2);
		//Goto(sscav3,spool3);

		scav_check = GetTime() + 2.0f;
		power_check = GetTime() + 3.0f;
		guntower_check = GetTime() + 2.0f;
		land_time = GetTime() + 15.0f;

		SetObjectiveOn(pool1_nav);
		TranslateString2(tempstr, sizeof(tempstr), "Mission1201");  // BioMetalPool
		SetObjectiveName(pool1_nav,tempstr);
		SetObjectiveOn(pool2_nav);
		SetObjectiveName(pool2_nav,tempstr);
		SetObjectiveOn(pool3_nav);
		SetObjectiveName(pool3_nav,tempstr);
		SetObjectiveOff(pool1_nav);
		SetObjectiveOff(pool2_nav);
		SetObjectiveOff(pool3_nav);

		SetSkill(sturret1,2);
		//Defend(sturret1);
		SetSkill(sturret2,2);
		//Defend(sturret2);
		SetSkill(sturret3,2);
		//Defend(sturret3);
		SetSkill(sturret4,2);
		//Defend(sturret4);
		SetSkill(sturret5,2);
		//Defend(sturret5);
		SetSkill(sturret6,2);
		//Defend(sturret6);
		SetSkill(sturret7,2);
		//Defend(sturret7);
		SetSkill(sturret8,2);
		//Defend(sturret8);
		SetSkill(sturret9,2);
		//Defend(sturret9);
		SetSkill(sturret10,2);
		//Defend(sturret10);

		Defend(scav1,0);

		start_done = true;
	}


	// this is the first message when the player gets into a tank

	if ((!power_message) && (land_time < GetTime()))
	{
		talk = AudioMessage("isdf1201.wav");//(unit) glad you could join the battle sir! The bastards have taken out the power - we need to get it back online but I'm low on scrap.
		power_message = true;
	}


	if ((power_message) && (!change_otf1) && (IsAudioMessageDone(talk)))
	{
		ClearObjectives();
		AddObjective("isdf1201.otf", WHITE);
		AddObjective("isdf1202.otf", WHITE);
		change_otf1 = true;
	}
	////////////////////////////////////////////


	// this is destroying guntower3

	if (!guntower_show)
	{
		if (first_over)
		{
			Damage(guntower3,5001);
			guntower_show = true;
		}

		if (guntower_check < GetTime())
		{
			guntower_check = GetTime() + 2.0f;

			if (GetDistance(player,guntower3) < 40.0f)
			{
				Damage(guntower3,5001);
				guntower_show = true;
			}
		}
	}
	////////////////////////////////////////////



	// this is checking to see when the first wave is destroyed

	if (!first_over)
	{
		// this is kepping the things alive

		if (IsAlive(constructor))
		{
			if (GetCurHealth(constructor) < 500)
			{
				SetCurHealth(constructor,500);
			}
		}

		if (IsAlive(tug))
		{
			if (GetCurHealth(tug) < 500)
			{
				SetCurHealth(tug,500);
			}
		}

		if (IsAround(factory))
		{
			if (GetCurHealth(factory) < 1000)
			{
				SetCurHealth(factory,1000);
			}
		}

		if (IsAround(service))
		{
			if (GetCurHealth(service) < 1000)
			{
				SetCurHealth(service,1000);
			}
		}

		if (IsAround(armory))
		{
			if (GetCurHealth(armory) < 1000)
			{
				SetCurHealth(armory,1000);
			}
		}

		if (IsAround(training))
		{
			if (GetCurHealth(training) < 1000)
			{
				SetCurHealth(training,1000);
			}
		}

		if (IsAround(commbunk1))
		{
			if (GetCurHealth(commbunk1) < 1000)
			{
				SetCurHealth(commbunk1,1000);
			}
		}

		if (IsAround(power1))
		{
			if (GetCurHealth(power1) < 1000)
			{
				SetCurHealth(power1,1000);
			}
		}

		if (IsAround(guntower1))
		{
			if (GetCurHealth(guntower1) < 1000)
			{
				SetCurHealth(guntower1,1000);
			}
		}

		if (IsAround(guntower2))
		{
			if (GetCurHealth(guntower2) < 1000)
			{
				SetCurHealth(guntower2,1000);
			}
		}
		////////////////////////////////////////////


		// this is checking to see when the first wave is over

		if ((!IsAlive(start_sent1)) && (!IsAlive(start_sent2)) && (!IsAlive(start_war1)) && (!IsAlive(start_war2)) && (!IsAlive(start_war3)))
		{
			if (IsAlive(tank1))
			{
				Goto(tank1,player,0);
			}
			if (IsAlive(tank2))
			{
				Goto(tank2,player,0);
			}
			if (IsAlive(tbolt1))
			{
				Goto(tbolt1,player,0);
			}
			if (IsAlive(tbolt2))
			{
				Goto(tbolt2,player,0);
			}
			if (IsAlive(rocket1))
			{
				Goto(rocket1,player,0);
			}
			if (IsAround(guntower2))
			{
				SetCurHealth(guntower2,500);
			}

			//SetObjectiveOn(pool1_nav);
			//SetObjectiveName(pool1_nav,"BioMetal Pool");
			//SetObjectiveOn(pool2_nav);
			//SetObjectiveName(pool2_nav,"BioMetal Pool");
			//SetObjectiveOn(pool3_nav);
			//SetObjectiveName(pool3_nav,"BioMetal Pool");

			first_over = true;
		}
	}
	////////////////////////////////////////////


	// this is setting the health of the buildings after the first wave is done

	if ((first_over) && (!build_health_set))
	{
		if (IsAround(guntower3))
		{
			Damage(guntower3,5001);
			guntower_show = true;
		}

		if (IsAround(armory))
		{
			SetCurHealth(armory,1500);
		}

		if (IsAround(commbunk1))
		{
			SetCurHealth(commbunk1,1500);
		}

		if (IsAround(factory))
		{
			SetCurHealth(factory,5000);
		}

		if (IsAround(service))
		{
			SetCurHealth(service,5000);
		}

		build_health_set = true;
	}
	////////////////////////////////////////////


	// this is the message after the first battle is over

	if ((first_over) && (!scrap_message))
	{
		SetPlan("isdf1201.aip",2);
		ClearObjectives();
		AddObjective("isdf1201.otf", GREEN);
		AddObjective("isdf1202.otf", WHITE);
		AddObjective("isdf1207.otf", WHITE);
		AddObjective("isdf1203.otf", WHITE);
		talk = AudioMessage("isdf1202.wav");//(manson) My orders were to take out that new machine at nav 2, but its not going to be easy with the base in this condition
		first_message = true;				// I've got one scav left.
		scrap_message = true;
	}
	////////////////////////////////////////////


	// this is the next set of odf files 

	if ((scrap_message) && (!change_otf2) && (IsAudioMessageDone(talk)))
	{
		SetObjectiveOn(key_device);
		TranslateString2(tempstr, sizeof(tempstr), "Mission1202");  // Power Source
		SetObjectiveName(key_device,tempstr);
		ClearObjectives();
		AddObjective("isdf1202.otf", WHITE);
		AddObjective("isdf1203.otf", WHITE);
		change_otf2 = true;
	}
	////////////////////////////////////////////


	// this is the second attack wave
	if ((first_over) && (!send_second))
	{
		if ((war1a) && (war2a) && (sent1a) && (sent2a))
		{
			Goto(war1a,"isdf_base");
			Goto(war2a,"isdf_base");
			Goto(sent1a,"isdf_base");
			Goto(sent2a,"isdf_base");
			send_second = true;
		}
	}
	////////////////////////////////////////////


	// this is the scav code

	if (IsOdf(player,"ivscav"))
	{
		player_in_scav = true;
	}
	else
	{
		player_in_scav = false;
	}


	if ((!scav1_alive) && (!player_in_scav))
	{
		Handle temp = empty_scav1;

		if (IsAlive(temp))
		{
			Handle tugger = GetTug(empty_scav1);

			if (tugger != 0)
			{
				Dropoff(tug,NULL,0);
			}

			pilot_made = false;
			scav1_alive = true;
		}
	}


	if ((!scav2_alive) && (!player_in_scav))
	{
		Handle temp2 = empty_scav2;

		if (IsAlive(temp2))
		{
			Handle tugger = GetTug(empty_scav2);

			if (tugger != 0)
			{
				Dropoff(tug,NULL,0);
			}

			pilot_made = false;
			scav2_alive = true;
		}
	}
	////////////////////////////////////////////


	// this is big messy code to determine when the base has power

	if ((!base_powered) && (power_check < GetTime()))
	{
		power_check = GetTime() + 3.0f;


		if (IsPowered(factory))
		{
			base_powered = true;
		}
	}
	////////////////////////////////////////////


	if (!powered_message1)
	{
		if ((base_powered) && (!scav_deployed))
		{
			talk = AudioMessage("isdf1206.wav");// (manson) Nice thinking sir - the power is back online. We're still going to need to get some money
			powered_message1 = true;
		}
		else if ((base_powered) && (scav_deployed))
		{
			talk = AudioMessage("isdf1205.wav");//(Manson) Nice - the power is back up.
			powered_message1 = true;
		}
	}
	////////////////////////////////////////////

	// this manson explaining how to deactivate the machine

	if ((!power_explained) && (powered_message1) && (IsAudioMessageDone(talk)))
	{
		talk = AudioMessage("isdf1220.wav");//(Manson) to get the power machine...
		power_explained = true;
	}


	// this is checking to see when the player gets near the empty scavs

	if ((!training_message) && (scav_check < GetTime()))
	{
		scav_check = GetTime() + 2.0f;

		if (GetDistance(player,empty_scav1) < 70.0f)
		{
			if (base_powered)
			{
				AudioMessage("isdf1207.wav");//(Manson) If we can get those two scavs back to the training faciltiy we can get them pilots
				training_message = true;
			}
			else if (!base_powered)
			{
				AudioMessage("isdf1208.wav");//(Manson) If we can get those two scavs back to the training faciltiy we can get them pilots
				training_message = true;	// but we need to reestablish poer to the base first
			}
		}
	}
	////////////////////////////////////////////


	// this is setting the correct odfs depending on the circumstances

	if (!first_done)
	{
		if ((!base_first) && (base_powered) && (!training_message) && (!scav_deployed))
		{
			ClearObjectives();
			AddObjective("isdf1202.otf", GREEN);
			AddObjective("isdf1203.otf", WHITE);
			AddObjective("isdf1207.otf", WHITE);
			AddObjective("isdf1206.otf", WHITE);
			first_done = true;
			base_first = true;
		}


		if ((!scav_first) && (!base_powered) && (!training_message) && (scav_deployed))
		{
			ClearObjectives();
			AddObjective("isdf1202.otf", WHITE);
			AddObjective("isdf1203.otf", WHITE);
			AddObjective("isdf1207.otf", GREEN);
			AddObjective("isdf1206.otf", WHITE);
			first_done = true;
			scav_first = true;
		}


		if ((!train_first) && (!base_powered) && (training_message) && (!scav_deployed))
		{
			ClearObjectives();
			AddObjective("isdf1202.otf", WHITE);
			AddObjective("isdf1203.otf", WHITE);
			AddObjective("isdf1205.otf", WHITE);
			AddObjective("isdf1207.otf", WHITE);
			AddObjective("isdf1206.otf", WHITE);
			first_done = true;
			train_first = true;
		}
	}
	////////////////////////////////////////////

		
	if ((first_done) && (!second_done))
	{
		if (base_first)
		{
			if ((training_message) && (!scav_deployed))
			{
				ClearObjectives();
				AddObjective("isdf1203.otf", WHITE);
				AddObjective("isdf1205.otf", WHITE);
				AddObjective("isdf1207.otf", WHITE);
				AddObjective("isdf1206.otf", WHITE);
				second_done = true;
				train_second = true;
			}
			else if ((!training_message) && (scav_deployed))
			{
				ClearObjectives();
				AddObjective("isdf1203.otf", WHITE);
				AddObjective("isdf1207.otf", GREEN);
				AddObjective("isdf1206.otf", WHITE);
				second_done = true;
				scav_second = true;
			}
		}

		if (train_first)
		{
			if ((base_powered) && (!scav_deployed))
			{
				ClearObjectives();
				AddObjective("isdf1202.otf", WHITE);
				AddObjective("isdf1203.otf", WHITE);
				AddObjective("isdf1205.otf", WHITE);
				AddObjective("isdf1207.otf", WHITE);
				AddObjective("isdf1206.otf", WHITE);
				second_done = true;
				base_second = true;
			}
			else if ((!base_powered) && (scav_deployed))
			{
				ClearObjectives();
				AddObjective("isdf1202.otf", WHITE);
				AddObjective("isdf1203.otf", WHITE);
				AddObjective("isdf1205.otf", WHITE);
				AddObjective("isdf1207.otf", GREEN);
				AddObjective("isdf1206.otf", WHITE);
				second_done = true;
				scav_second = true;
			}
		}

		if (scav_first)
		{
			if ((base_powered) && (!training_message))
			{
				ClearObjectives();
				AddObjective("isdf1202.otf", GREEN);
				AddObjective("isdf1203.otf", WHITE);
				AddObjective("isdf1206.otf", WHITE);
				second_done = true;
				base_second = true;
			}
			else if ((!base_powered) && (training_message))
			{
				ClearObjectives();
				AddObjective("isdf1202.otf", WHITE);
				AddObjective("isdf1203.otf", WHITE);
				AddObjective("isdf1205.otf", WHITE);
				AddObjective("isdf1206.otf", WHITE);
				second_done = true;
				train_second = true;
			}
		}
	}
	////////////////////////////////////////////


	if ((second_done) && (!last_done))
	{
		if ((base_first) && (train_second))
		{
			if (scav_deployed)
			{
				ClearObjectives();
				AddObjective("isdf1203.otf", WHITE);
				AddObjective("isdf1205.otf", WHITE);
				AddObjective("isdf1207.otf", GREEN);
				AddObjective("isdf1206.otf", WHITE);
				last_done = true;
			}
		}
		else if ((base_first) && (scav_second))
		{
			if (training_message)
			{
				ClearObjectives();
				AddObjective("isdf1203.otf", WHITE);
				AddObjective("isdf1205.otf", WHITE);
				AddObjective("isdf1206.otf", WHITE);
				last_done = true;
			}
		}
		else if ((train_first) && (base_second))
		{
			if (scav_deployed)
			{
				ClearObjectives();
				AddObjective("isdf1203.otf", WHITE);
				AddObjective("isdf1205.otf", WHITE);
				AddObjective("isdf1207.otf", GREEN);
				AddObjective("isdf1206.otf", WHITE);
				last_done = true;
			}
		}
		else if ((train_first) && (scav_second))
		{
			if (base_powered)
			{
				ClearObjectives();
				AddObjective("isdf1202.otf", GREEN);
				AddObjective("isdf1203.otf", WHITE);
				AddObjective("isdf1205.otf", WHITE);
				AddObjective("isdf1206.otf", WHITE);
				last_done = true;
			}
		}
		else if ((scav_first) && (train_second))
		{
			if (base_powered)
			{
				ClearObjectives();
				AddObjective("isdf1202.otf", GREEN);
				AddObjective("isdf1203.otf", WHITE);
				AddObjective("isdf1205.otf", WHITE);
				AddObjective("isdf1206.otf", WHITE);
				last_done = true;
			}
		}
		else if ((scav_first) && (base_second))
		{
			if (training_message)
			{
				ClearObjectives();
				AddObjective("isdf1203.otf", WHITE);
				AddObjective("isdf1205.otf", WHITE);
				AddObjective("isdf1206.otf", WHITE);
				last_done = true;
			}
		}
	}
	////////////////////////////////////////////


	// this is loading a new plan
/*
	if (!new_plan1)
	{
		if (scav3_deployed)
		{
			SetPlan("isdf1202.aip",2);
			new_plan1 = true;
		}
	}
	////////////////////////////////////////////
*/

	// this is sending the titans to attack

	if ((!titan_attack) && (titan_time < GetTime()))
	{
		if (IsAlive(titan1))
		{
			if (IsAround(factory))
			{
				Attack(titan1,factory);
			}

			if (IsAlive(titan2))
			{
				if (IsAround(armory))
				{
					Attack(titan2,armory);
				}
			}
		}
		else if (IsAlive(titan2))
		{
			if (IsAround(factory))
			{
				Attack(titan2,factory);
			}
		}

		titan_attack = true;
	}
	////////////////////////////////////////////


	// this is setting the new aip once the titans are sent

	if ((!last_aip) && (titan_attack) && (!IsAlive(titan1)) && (!IsAlive(titan2)))
	{
		SetPlan("isdf1203.aip",2);
		last_aip = true;
	}
	////////////////////////////////////////////


// these are the win/loose conditions

	if (!game_over)
	{
		// this is if the player wins

		if (IsAlive(key_device))
		{
			tugger = GetTug(key_device);

			if (IsAlive(tugger))
			{
				if (GetTeamNum(tugger) == 1)
				{
					SucceedMission(GetTime() + 10.0f,"isdf12w1.txt");
					AudioMessage("isdf1203.wav");//(braddock) well done
					game_over = true;
				}
			}
		}
		////////////////////////////////////////////


		// this is if the tug gets destoyed

		if (!IsAlive(tug))
		{
			FailMission(GetTime() + 10.0f);
			AudioMessage("isdf1204.wav");//(braddock) you let the tug get destroyed
			game_over = true;
		}
		////////////////////////////////////////////

	}
}
