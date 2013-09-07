#include "..\Shared\SPMission.h"

class isdf06Mission : public SPMission 
{
public:
	isdf06Mission(void)
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

	virtual void Setup(void);
	virtual void AddObject(Handle h);
	virtual void DeleteObject(Handle h);
	virtual void Execute(void);
	void ConstructionMessage(void);

	bool PostLoad(bool missionSave);

	// bools
	bool
		b_first,
		start_done,
		wave_launched,
		warning,
		defend_warning,
		repair_hint,
		b_last;

	// floats
	float
		f_first,
		attack_wave_time,
		f_last;

	// handles
	Handle
		h_first,
		player,
		atk1,
		atk2,
		atk3,
		atk4,
		atk5,
		atk6,
		atk7,
		atk8,
		turret1,
		turret2,
		escav,
		got_to_scav,
		scrap_pool,
		constructor,
		cbunker,
		mbike1,
		mbike2,
		mbike3,
		back1,
		back2,
		back3,
		guntow1,
		guntow2,
		scout1,
		scout2,
		scav,
		scav1,
		scav2,
		scav3,
		goal,
		h_last;

	// integers
	int
		i_first,
		mission_state,
		wave_count,
		time_counter,
		scav_count,
		i_last;
};
DLLBase * BuildMission(void)
{
	return new isdf06Mission();
}

bool isdf06Mission::PostLoad(bool missionSave)
{
	PreloadODF("ivcons");
	return SPMission::PostLoad(missionSave);
}

void isdf06Mission::Setup(void)
{
	SetAutoGroupUnits(false);
/*
	Here's where you set the values at the start.  
*/
	Ally(3,1);
	Ally(1,3);
//  bools
	start_done = false;
	got_to_scav=false;
	warning=false;
	defend_warning=false;
	repair_hint=false;
	
//  floats


//  handles
	cbunker=NULL;
	guntow1=NULL;
	guntow2=NULL;
	constructor=NULL;
	player = GetPlayerHandle();

	scrap_pool=GetHandle("goal1");
	goal=GetHandle("goal");
	mbike1=GetHandle("bike1");
	mbike2=GetHandle("bike2");
//	mbike3=GetHandle("bike3");
//	constructor=GetHandle("constructor");
	scav1=GetHandle("scav1");
	scav2=GetHandle("scav2");
	scav3=GetHandle("scav3");
	scav_count=3;
	//  integers
	wave_count=0;
	time_counter=0;
	mission_state=0; 
}
void isdf06Mission::ConstructionMessage(void)
{
		ClearObjectives();
		AddObjective("isdf0604.otf",WHITE,10.0f);
		if (cbunker!=NULL)
		{
			AddObjective("isdf0605.otf",GREEN,10.0f);
		} else
			AddObjective("isdf0605.otf",WHITE,10.0f);

		if ((guntow1!=NULL) && (guntow2!=NULL))
		{
			AddObjective("isdf0606.otf",GREEN,10.0f);
		}	else
			AddObjective("isdf0606.otf",WHITE,10.0f);

				
}

void isdf06Mission::AddObject(Handle h)
{
	char ODFName[64];
	GetObjInfo(h, Get_CFG, ODFName);

	if (start_done)
	{
		if ((cbunker==NULL) && (IsOdf2(h,"ibcbun")))
		{
			if (GetDistance(h,"pool")<200.0f)
			{
				cbunker=h;
				ConstructionMessage();
			}
			else
			{
				// consturction warning
				ClearObjectives();
				AddObjective("isdf0610.otf",RED,10.0f);
			}
		}
		else {
			if ((guntow1==NULL) && (IsOdf2(h,"ibgtow")))
			{
				if (GetDistance(h,"pool")<400.0f)
				{
					guntow1=h;
					ConstructionMessage();
				}
				else
				{
					// construction warning
					ClearObjectives();
					AddObjective("isdf0610.otf",RED,10.0f);
				}
			}	
			else
			{
				if ((guntow2==NULL) && (IsOdf2(h,"ibgtow")))
				{
					if (GetDistance(h,"pool")<400.0f)
					{
						guntow2=h;
						ConstructionMessage();
					}
					else
					{
						// construction warning
						ClearObjectives();
						AddObjective("isdf0610.otf",RED,10.0f);
					}
				}
			}
		}
		if (IsOdf2(h,"fbscav"))  // assuming fvscav-> ibscav
		{
			escav=h;
		}

		if (IsOdf2(h,"ivbomb"))
		{
			SetPerceivedTeam(h,2);  // so they won't shoot it
		}
	}
	if (IsOdf2(h,"ibscav")) {
		scav_count++;
	}

	// Tweak NM 12/20/03 if the spawned-in scav dies, use any built scav
	// as a replacement
	if((mission_state == 4) && (scav == NULL) && (IsOdf2(h,"ivscav"))) {
		scav = h;
		Goto(scav,"pool");
	}

/*
	if ((scav1 == NULL) && (IsOdf2(h,"ivscav")))
	{
		scav1 = h;
	}
	else if ((scav2 == NULL) && (IsOdf2(h,"ivscav")))
	{
		scav2 = h;
	}
	else if ((turret1 == NULL) && (IsOdf2(h,"ivturr")))
	{
		turret1 = h;
	}
	else if ((turret2 == NULL) && (IsOdf2(h,"ivturr")))
	{
		turret2 = h;
	}
	else if ((wingman1 == NULL) && (IsOdf2(h,"ivscout")))
	{
		wingman1 = h;
	}
	else if ((wingman2 == NULL) && (IsOdf2(h,"ivscout")))
	{
		wingman2 = h;
	}
*/
}

void isdf06Mission::DeleteObject(Handle h)
{
	char ODFName[64];
	GetObjInfo(h, Get_CFG, ODFName);

	if (IsOdf2(h,"ivscav")) {
		scav_count--;
	}
}

void isdf06Mission::Execute(void)
{

	/*
		Stuff in 6
		You are responsible for
		the northern aproach to the base
		Alien units approach from the south
		and you battle them.  

		Shabayev discovers a scrap pool.
		She highlights it.  
		You must go to it and destroy a 
		scion scavenger.  

		You are given control of 
		constructor.  Your job is to build
		a bunker and a gun tower around it
		to protect it.  

		Once the bunker is built
		you are told to go on the 
		offensive.  

	  
		At the first place
		you go you find the 
		voyager probe.  

		The second is the 
		climatic battle.  
	*/
	
	player = GetPlayerHandle();

	if (!start_done)
	{
		start_done=true;
		/*
			This is one of our three 
			key bases on the Planet
			You must defend this approach.  
		*/
		ClearObjectives();
		AddObjective("isdf0601.otf",WHITE,20.0f);
		AudioMessage("isdf0601.wav");
		// Manson:
		// Prepare for enemy attacks
		// You are a reserve for a counter attack
		// or in case they break through.  
		attack_wave_time=GetTime()+10.0f;
		wave_launched=false;
		SetScrap(1,20);
		SetIndependence(escav,0);
		escav=BuildObject("fvscav",2,"pool");
		Goto(escav,scrap_pool,0);
		Handle temp=GetHandle("gtow1");
		AddHealth(temp,-2500);
		temp=GetHandle("gtow2");
		AddHealth(temp,-2500);
		GiveWeapon(player, "gshadow_c");
		/*
		turret1=BuildObject("ivturr",3,"turret1");
		turret2=BuildObject("ivturr",3,"turret2");
		Deploy(turret1);
		Deploy(turret2);
		*/
	}
	
	if ((!IsAlive(constructor)) && (mission_state>1) && (mission_state!=99))
	{
			// you loose
			AudioMessage("isdf0607.wav");
			// Manson:
			// That constructor was vital
			// to our effort.  I'm pulling
			// back immeadiately.  
			FailMission(GetTime()+15.0f,"isdf06l2.txt");
			mission_state=99;  // out of the loop
	}
	
	switch (mission_state)
	{
		case 0: // attack starts
			if ((!warning) && 
				(GetDistance(atk1,turret1)<250.0f))
			{
				AudioMessage("isdf0602.wav");
				warning=true;
			}
			if ((!wave_launched) && (GetTime()>attack_wave_time))
			{
				atk1=BuildObject("fvtank",2,"attack_start1");
				Goto(atk1,"attack_path1");
				SetSkill(atk1,3);
				atk2=BuildObject("fvtank",2,"attack_start1");
				Goto(atk2,"attack_path1");
				SetSkill(atk2,3);
				atk3=BuildObject("fvsent",2,"attack_start1");
				Goto(atk3,"attack_path1");
				SetSkill(atk3,3);
				atk4=BuildObject("fvsent",2,"attack_start1");
				Goto(atk4,"attack_path1");
				SetSkill(atk4,3);
				atk5=BuildObject("fvtank",2,"attack_start2");
				Goto(atk5,"attack_path2");
				SetSkill(atk5,3);
				atk6=BuildObject("fvtank",2,"attack_start2");
				Goto(atk6,"attack_path2");
				SetSkill(atk6,3);
				atk7=BuildObject("fvsent",2,"attack_start2");
				Goto(atk7,"attack_path2");
				SetSkill(atk7,3);
		//		atk8=BuildObject("fvsent",2,"attack_start2");
		//		Goto(atk8,"attack_path2");
		//		SetSkill(atk8,3);
				wave_launched=true;
			}
			if ((wave_launched) && (!IsAlive(atk1))
				&& (!IsAlive(atk2))
				&& (!IsAlive(atk3))
				&& (!IsAlive(atk4)) 
				&& (!IsAlive(atk5))
				&& (!IsAlive(atk6))
				&& (!IsAlive(atk7))
				&& (!IsAlive(atk8)))
			{
				warning=false;
				wave_launched=false;
				wave_count++;
				if (!repair_hint)
				{
					repair_hint=true;
					AudioMessage("isdf0612.wav");
					/*
						MANSON
						Take advantage of the
						breaks between attacks 
						to repair your forces at the service 
						bay.  
					*/
				}
				if (wave_count==2)
				{
					back1=BuildObject("fvarch",2,"back1");
					Goto(back1,"back_door");
					back2=BuildObject("fvarch",2,"back2");
					Goto(back2,"back_door");
					back3=BuildObject("fvsent",2,"back3");
					Goto(back3,"back_door");
					SetObjectiveOn(back1);
					AudioMessage("isdf0614.wav");
				}
				if (wave_count>(2)) //was 2
				{
					if ((!IsAlive(back1))
						&& (!IsAlive(back2))
						&& (!IsAlive(back3)))
					{

						mission_state++;
						SetObjectiveOn(escav);
						ClearObjectives();
						AddObjective("isdf0602.otf",WHITE,10.0f);
						AudioMessage("isdf0603.wav");
						// Shabayev
						// I have detected the scavenger
						// which is supplying the enemy.  
						// Its time to counter attack.  
						// Manson
						// Alright, Cooke, you heard
							// the lieutenant.  Get that
						// scavenger
						AudioMessage("isdf0604.wav");
					}
				}
				else attack_wave_time=GetTime()+5.0f;
				// hold back your forces
				if ((GetDistance(turret1,mbike1)<50.0f) && (!defend_warning))
				{
					AudioMessage("isdf0610.wav");
					// MansoN:
					// Cooke, hold back your forces.  
					defend_warning=true;

				}
			}
			break;
		case 1: // shabayev highlights the scavenger
			/*
			*/
			if (scav_count<3)
			{
				FailMission(GetTime()+5.0f,"isdf06l1.txt");
				mission_state=99;
			}
			else
			{
	
				if ((GetDistance(player,escav)<150.0f)
					&& (!got_to_scav))
				{
					AudioMessage("isdf0605.wav");
					// Shabayev: Attack!
					got_to_scav=true;	
	
				}
				if (!IsAlive(escav))
				{
					ClearObjectives();
					AddObjective("isdf0603.otf",WHITE,10.0f);
			
					constructor=BuildObject("ivcon6",1,"constructor_spawn");
					int grp=GetFirstEmptyGroup();			
					SetGroup(constructor,grp);
					Goto(constructor,"pool",0);
		
					mission_state++;
					AudioMessage("isdf0606.wav");
					// Manson:
					// Cooke, I'm sending you a 
					// constructor to fortify your
					// position.  Use the constructor
					// to build defenses around that
					// scrap pool.  
				}
			}
			break;
		case 2:	 // you get a constructor 
			if (GetDistance(constructor,"pool")<250.0f)
			{
				AudioMessage("isdf0611.wav");
				// Shabayev
				// Build a communications bunker to 
				// anchor the base.  
				// Once you have a communications bunker
				// build two adjacent
				// gun towers
				// The gun towers will be powered from
				// the surplus power of the main base.  
				// Good luck. 

				ConstructionMessage();
				// spawn in attackers
				scout1=BuildObject("fvscout",2,"patrol_spawn");
				scout2=BuildObject("fvscout",2,"patrol_spawn");
				if (IsAlive(mbike1))
				{
					Attack(scout1,player);
				}
				else
				{
					Attack(scout1,player);
				}
				if (IsAlive(mbike2))
				{
					Attack(scout2,player);
				}
				else Attack(scout2,mbike2);
				mission_state++;
			}
	
			break;
		case 3:
			if ((!IsAlive(scout1)) && (!IsAlive(scout2)))
			{
				scout1=BuildObject("fvscout",2,"patrol_spawn");
				scout2=BuildObject("fvscout",2,"patrol_spawn");
				if (IsAlive(mbike1))
				{
					Attack(scout1,mbike1);
				}	
				else Attack(scout1,player);
				if (IsAlive(mbike2))
				{
					Attack(scout2,mbike2);
				}	
				else	Attack(scout2,player);
			}
			if ((cbunker!=NULL) && (guntow1!=NULL)
				&& (guntow2!=NULL))
			{
				AudioMessage("isdf0608.wav");
				/*
					Manson:
					Great!  
					I'm sending a scavenger to secure
					that pool.  
					Prepare for further orders.  

				*/
				// more cannon foder to get pulverized
				atk1=BuildObject("fvtank",2,"patrol_spawn1");
				Attack(atk1,guntow1);  // cannon foder
				atk2=BuildObject("fvtank",2,"patrol_spawn2");
				Attack(atk2,guntow2);  // cannon foder

				// FraKTal says this scav doesn't want to deploy on its
				// own. So, put it under 100% human control - NM 6/27/03
#if 0
				// was
				scav=BuildObject("ivscav",3,"constructor_spawn");
#else
				// now
				scav=BuildObject("ivscav",1,"constructor_spawn");
#endif

				Goto(scav,"pool");
				ClearObjectives();
				AddObjective("isdf0607.otf",WHITE,10.0f);
				mission_state++;
			}
			break;
		case 4:  // when the scavenger gets there-- attack!!
				if (GetDistance(scav,"pool")<100.0f)
				{
					AudioMessage("isdf0609.wav");
					AudioMessage("isdf0613.wav");
					// Shabayev:
					// Its time we finish them off.  
					// All forces, converge on the enemy base! 
					SetObjectiveOn(goal);
					mission_state++;
					// spawn in patrols
					atk1=BuildObject("fvtank",2,"patrol_spawn2");
					atk2=BuildObject("fvtank",2,"patrol_spawn2");
					atk3=BuildObject("fvsent",2,"patrol_spawn");
					atk4=BuildObject("fvsent",2,"patrol_spawn");
					Patrol(atk1,"patrol");
					Patrol(atk2,"patrol");
					Patrol(atk3,"patrol");
					Patrol(atk4,"patrol");
					// spawn in attackers
					atk1=BuildObject("ivtank",3,"constructor_spawn");
					atk2=BuildObject("ivtank",3,"constructor_spawn");
					Goto(atk1,goal);
					Goto(atk2,goal);
					BuildObject("ibbomb",1,"bomber");  // you get a bomber
//					BuildObject("ivbomb",1,"bomber");
					ClearObjectives();
					AddObjective("isdf0608.otf",WHITE,10.0f);
				}
			break;
		case 5:  // test to destroy base
				time_counter++;
				if (time_counter%1200==0) // every minute 1/2
				{
					atk1=BuildObject("fvtank",2,"patrol_spawn2");
					atk2=BuildObject("fvtank",2,"patrol_spawn2");
					Patrol(atk1,"patrol");
					Patrol(atk2,"patrol");
				}
				if (!IsAlive(goal))
				{
					// you win
					SucceedMission(GetTime()+20.0f,"isdf06w1.txt");
					mission_state++;
					ClearObjectives();
					AddObjective("isdf0609.otf",WHITE,10.0f);
				}
			break;
		case 6:
			// cineractive
			// Through the worm hole
			break;

	} // switch		
}
