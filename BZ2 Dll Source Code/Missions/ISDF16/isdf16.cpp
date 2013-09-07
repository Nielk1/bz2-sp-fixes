#include "..\Shared\SPMission.h"

class isdf16Mission : public SPMission 
{
public:
	isdf16Mission(void)
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
	void CounterAttacks(void);
	void Execute(void);
	void LateAttacks(void);
	// bools
	bool
		b_first,
		start_done,
		power_strike,
		scav_strike,
		start_takeoff,
		takeoff,
		moving_out,
		found_pool,
		b_last;

	// floats
	float
		f_first,
		emit_time,
		condor1_remove_time,
		takeoff_time,
		f_last;


	// handles
	Handle
		h_first,
		recy,
		power1,
		gtow1,
		scav1,
		pool1,
		pool2,
		pool3,
		pool4,
		pool5,
		goal1,
		goal2,
		goal3,
		goal4,
		sneak1,
		sneak2,
		sneak3,
		atk1,
		atk2,
		atk3,
		atk4,
		atk5,
		atk6,
		atk2_1,
		atk2_2,
		atk2_3,
		atk2_4,
		atk2_5,
		atk2_6,
		atk2_7,
		atk2_8,
		atk2_9,
		tug,
		dropship,
		player,
		h_last;

	// integers
	int
		i_first,
		sneak_timer,
		comp_team,
		comp_teamb,
		comp_teamc,
		mission_state,
		convoy_timer,
		time_counter,
		i_last;
};
DLLBase * BuildMission(void)
{
	return new isdf16Mission();
}

void isdf16Mission::Setup(void)
{
	SetAutoGroupUnits(false);
/*
	Here's where you set the values at the start.  
*/
//  bools

	power_strike=false;
	scav_strike=false;
	start_takeoff=false;
	takeoff=false;
//  floats


//  handles
	player = GetPlayerHandle();
	power1=NULL;
	gtow1=NULL;
	scav1=NULL;
	dropship=NULL;
	recy=GetHandle("recycler");
/*
	pool1=GetHandle("pool1");
	pool2=GetHandle("pool2");
	pool3=GetHandle("pool3");
	pool4=GetHandle("pool4");
	pool5=GetHandle("pool5");
*/
		atk2_1= NULL;
		atk2_2= NULL;
		atk2_3= NULL;
		atk2_4= NULL;
		atk2_5= NULL;
		atk2_6= NULL;
		atk2_7= NULL;
		atk2_8= NULL;
		atk2_9= NULL;

	
	goal1=GetHandle("goal1");
	goal2=GetHandle("goal2");
	goal3=GetHandle("goal3");
	goal4=GetHandle("goal4");

	//  integers
	time_counter=1;
	comp_team=2;
	comp_teamb=4;
	comp_teamc=6;
	Ally(comp_team,comp_teamb);
	Ally(comp_teamb,comp_team);
	Ally(comp_team,comp_teamc);
	Ally(comp_teamc,comp_team);
	Ally(comp_teamc,comp_teamb);
	Ally(comp_teamb,comp_teamc);
	mission_state=0;
}


void isdf16Mission::AddObject(Handle h)
{
	char ODFName[64];
	GetObjInfo(h, Get_CFG, ODFName);

	if (start_done)
	{
		if (IsOdf2(h,"ibpgen") && ((power1==NULL) || (!IsAlive(power1))))
		{
			power1=h;
		}
		if (IsOdf2(h,"ibgtow") && ((gtow1==NULL) || (!IsAlive(gtow1))))
		{
			gtow1=h;
		}
		if ((IsOdf2(h,"ibscav")) && (scav1==NULL))
		{
			scav1=h;
		}

	}
	if (IsOdf2(h,"ibrecy"))
	{
		recy=h;
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


void isdf16Mission::CounterAttacks()
{
	if ((!power_strike) && (power1!=NULL))
	{
		Attack(atk1,power1);
		Attack(atk2,power1);
		Attack(atk3,power1);
		power_strike=true;
	}
}


void isdf16Mission::LateAttacks(void)
{
			if ((!IsAlive(atk2_1)) && (!IsAlive(atk2_2)) && (!IsAlive(atk2_3)))
			{
				atk2_1=BuildObject("fvwalk",comp_teamc,"convoy1");
				atk2_2=BuildObject("fvwalk",comp_teamc,"convoy2");
				atk2_3=BuildObject("fvwalk",comp_teamc,"convoy3");


			}
			if ((!IsAlive(atk2_7)) && (!IsAlive(atk2_8)) && (!IsAlive(atk2_8))) {
				atk2_7=BuildObject("fvscout",comp_teamc,"attack1");
				GiveWeapon(atk2_7,"garc_c");
				GiveWeapon(atk2_7,"gshield");
				atk2_8=BuildObject("fvscout",comp_teamc,"attack2");
				GiveWeapon(atk2_8,"garc_c");
				GiveWeapon(atk2_8,"gshield");
				atk2_9=BuildObject("fvscout",comp_teamc,"attack3");
				GiveWeapon(atk2_9,"garc_c");
				GiveWeapon(atk2_9,"gshield");
			}

			if (time_counter%3001==0) // it takes 6 min time to get back to this
			{
				Goto(atk2_7,player);
				Goto(atk2_8,player);
				Goto(atk2_9,player);
				if ((IsAlive(atk2_1)) && (IsAlive(atk2_2)) && (IsAlive(atk2_3)))
				{
					atk2_4=BuildObject("fvsent",comp_teamc,"convoy1");
					GiveWeapon(atk2_4,"glock_c");
					GiveWeapon(atk2_4,"gshield");
					atk2_5=BuildObject("fvsent",comp_teamc,"convoy2");
					GiveWeapon(atk2_5,"glock_c");
					GiveWeapon(atk2_5,"gshield");
					atk2_6=BuildObject("fvsent",comp_teamc,"convoy3");
					GiveWeapon(atk2_6,"glock_c");
					GiveWeapon(atk2_6,"gshield");
					Follow(atk2_4,atk2_1);
					Follow(atk2_5,atk2_2);
					Follow(atk2_6,atk2_3);
					if (!IsAlive(gtow1))
					{
						Attack(atk2_1,recy);
						Attack(atk2_2,recy);
						Attack(atk2_3,recy);

					}
					else
					{
						Attack(atk2_1,recy);
						Attack(atk2_2,recy);
						Attack(atk2_3,recy);
					}
				}
			}
			else
			{
				// clear everything out
				Goto(atk2_1,recy);
				Goto(atk2_2,recy);
				Goto(atk2_3,recy);
				Goto(atk2_4,recy);
				Goto(atk2_5,recy);
				Goto(atk2_6,recy);

			}

	
}

void isdf16Mission::Execute(void)
{

	/*
		To make this multiplay
		friendly the computer is 
		team 5
	*/
	/*
		We should add a 
		second compute player
		as team 6 at
		sneak_start

		"base2"
	*/
	player = GetPlayerHandle();
	char tempstr[128];

	CounterAttacks();
	if (!start_done)
	{
		// AudioMessage("isdf1601.wav");
		/*
			The fate of humanity depends
			on our successful invasion of
			Core.  
			I have no doubt this will be the
			most hostile planet we have yet
			encountered, and the fiercest
			resistance.  
			Establish your forces carefully
			and press the attack into the
			enemy data transfer facillity.  
		*/
		dropship=GetHandle("dropship");
		atk1=BuildObject("fvarch",comp_team,"attack1");
		atk2=BuildObject("fvarch",comp_team,"attack2");
		atk3=BuildObject("fvarch",comp_team,"attack3");
		atk4=BuildObject("fvatank",comp_team,"attack4");
		atk5=BuildObject("fvatank",comp_team,"attack5");
		atk6=BuildObject("fvserv",comp_team,"attack6");
		SetObjectiveOn(pool1);
		Handle tempturr=BuildObject("fvturr",comp_team,"turret1");
		Deploy(tempturr);
		tempturr=BuildObject("fvturr",comp_team,"turret2");
		Deploy(tempturr);
		tempturr=BuildObject("fvturr",comp_team,"turret3");
		Deploy(tempturr);
		tempturr=BuildObject("fvturr",comp_team,"turret4");
		BuildObject("fvrecy",comp_team,"RecyclerEnemy");
		BuildObject("fvrecy",comp_teamb,"base2"); // buh hah hah!!
		SetScrap(1,60);
		SetScrap(comp_team,40);
		SetPlan("misn16.aip",comp_team);
		SetScrap(comp_teamb,40);
		SetPlan("misn16b.aip",comp_teamb);
		ClearObjectives();
		AddObjective("isdf1601.otf",WHITE,10.0f);
		tempturr=BuildObject("fvwalk",comp_team,"turret1");
		Attack(tempturr,player);
		tempturr=BuildObject("fvwalk",comp_team,"turret2");
		Attack(tempturr,player);
		AudioMessage("isdf1601.wav");

		// this is for the drop ship
		takeoff_time=GetTime()+10.0f;
		SetAnimation(dropship,"deploy",1);
		start_done=true;
	}

	if ((!start_takeoff) && (GetTime()>takeoff_time))
	{
		start_takeoff=true;
		SetAnimation(dropship,"takeoff",1);
		emit_time = GetTime() + 3.0f;
		condor1_remove_time = GetTime() + 20.0f;
	}
	
	if (emit_time < GetTime())
	{
		StartEmitter(dropship, 1);
		StartEmitter(dropship, 2);
		//smoker1 = BuildObject("kickup",0,"smoker1_a");
		//smoker2 = BuildObject("kickup",0,"smoker1_b");
		emit_time = GetTime() + 999999.9f;
	}
	if (!takeoff)
	{
		if (condor1_remove_time < GetTime())
		{
			RemoveObject(dropship);
			//RemoveObject(smoker1);
			//RemoveObject(smoker2);
			takeoff = true;
		}
	}
	
	
	/*
		If you lose the recycler
		you lose.  
	*/
	if ((mission_state<12) && (!IsAlive(recy)))
	{
		mission_state=12; // buh-bye!
		ClearObjectives();
		AddObjective("isdf1605.otf",RED,10.0f);
	}

	
			
	if (((GetDistance(player,goal1)<150.0f)
				||
			(GetDistance(player,goal2)<150.0f)
							||
			(GetDistance(player,goal3)<150.0f)
			||
			(GetDistance(player,goal4)<150.0f))
			&& (mission_state<7))
		{
			ClearObjectives();
			AddObjective("isdf1602.otf",WHITE,10.0f);
			AudioMessage("isdf1602.wav");
			/*
				That's it!  
				We need to get to that
				structure?
			*/
			Handle atk=BuildObject("fvatank",comp_team,"convoy1");
			Goto(atk,"convoy_path");
			tug=BuildObject("fvtug",comp_team,"convoy2");
			Follow(tug,atk);
			Handle tempx=BuildObject("fvatank",comp_team,"convoy3");
			Follow(tempx,tug);
			atk= BuildObject("fvsent",comp_team,"convoy4");
			Follow(atk,tempx);
			atk= BuildObject("fvsent",comp_team,"convoy5");
			Follow(atk,tug);
			mission_state=7;
			convoy_timer=200;
		}

	// just for general purpose
	time_counter++;
	
	switch (mission_state)
	{
		case 0:  // haven't found defenses
			// build up
				AddScrap(comp_team,1);
				AddScrap(comp_teamb,1);
			
			if ((GetDistance(player,"turret1")<200.0f)
				||
				(GetDistance(player,"turret4")<200.0f))
			{
				/*
					Satalite recon shows
					you are heading into the
					heart of enemy defenses.  
				*/
				// finish up these attacks
				Attack(atk1,recy);
				Attack(atk2,recy);

				if (IsOdf(atk6,"fvserv")) {
					Follow(atk3,atk2);
				} else {
					Attack(atk3,recy);
				}
				if (!IsAlive(power1))
				{
					Attack(atk4,recy);
					Attack(atk5,recy);
					if (IsOdf(atk6,"fvserv")) {
						Follow(atk6,atk5);
					} else {
						Attack(atk6,recy);
					}
				}
				else
				{
					Attack(atk4,power1);
					Attack(atk5,power1);
					if (IsOdf(atk6,"fvserv")) {
						Follow(atk6,atk5);
					} else {
						Attack(atk6,power1);
					}

				}

				
				AudioMessage("isdf1603.wav");
				sneak_timer=0;
				mission_state=5;
			}
			if (time_counter%1500==0)  // every 90 sec, surprise
			{
				/*
				if (!takeoff)
				{
					takeoff=true;
					RemoveObject(dropship);
				}
				*/
				Attack(atk1,recy);
				Attack(atk2,recy);
				if (IsOdf(atk6,"fvserv")) {
					Follow(atk6,atk5);
				} else {
					Attack(atk6,recy);
				}
			}
			if (time_counter%1801==0) // it takes 3 min time to get back to this
			{
				if (!IsAlive(power1))
				{
					Attack(atk4,recy);
					Attack(atk5,recy);
					if (IsOdf(atk6,"fvserv")) {
						Follow(atk6,atk5);
					} else {
						Attack(atk6,recy);
					}

				}
				else
				{
					Attack(atk4,power1);
					Attack(atk5,power1);
					Follow(atk6,atk5);
					if (IsOdf(atk6,"fvserv")) {
						Follow(atk6,atk5);
					} else {
						Attack(atk6,power1);
					}

				}
			}
			if ((!IsAlive(atk1)) && (!IsAlive(atk2)) && (!IsAlive(atk3)))
			{
				atk1=BuildObject("fvatank",comp_team,"attack1");
				atk2=BuildObject("fvatank",comp_team,"attack2");
				atk3=BuildObject("fvserv",comp_team,"attack3");
			}
			if ((!IsAlive(atk4)) && (!IsAlive(atk5)) && (!IsAlive(atk6)))
			{
				atk4=BuildObject("fvwalk",comp_team,"attack4");
				atk5=BuildObject("fvwalk",comp_team,"attack5");
				atk6=BuildObject("fvwalk",comp_team,"attack6");
			}
			break;

		case 5:
			// in case we didn't before
			LateAttacks();
			sneak_timer++;
			if (sneak_timer%4000==0)  // was 8000
			{
				sneak1=BuildObject("fvartl",comp_team,"attack1");
				sneak2=BuildObject("fvartl",comp_team,"attack2");
				sneak3=BuildObject("fvartl",comp_team,"attack3");
				Goto(sneak1,"sneak1");
				Goto(sneak2,"sneak2");
				Goto(sneak3,"sneak3");
				mission_state++;
			}

			break;
		case 6:
			LateAttacks();
			if ((GetDistance(sneak1,"sneak1")<10.0f) &&
				(GetDistance(sneak2,"sneak2")<10.0f) && 
				(GetDistance(sneak3,"sneak3")<10.0f) )
			{
				Attack(sneak1,recy);
				Attack(sneak2,recy);
				mission_state=5;// get back
			}
			break;
		case 7:
			/*
				We've identified retreating 
				units coming towards your position.  
				Destroy them.  
			*/

			convoy_timer--;
			if (convoy_timer==0)
			{
				AudioMessage("isdf1603a.wav");
				AudioMessage("isdf1604.wav");
				ClearObjectives();
				AddObjective("isdf1603.otf",WHITE,5.0f);
				SetObjectiveOn(tug);
				TranslateString2(tempstr, sizeof(tempstr), "Mission1101");  // Convoy
				SetObjectiveName(tug,tempstr);
				mission_state++;
			}
			break;
		
		case 8:
			if (!IsAlive(tug))
			{
				ClearObjectives();
				AddObjective("isdf1604.otf",WHITE,5.0f);
				mission_state++;
				SucceedMission(GetTime()+15.0f,"isdf16w1.txt");
				AudioMessage("isdf1605.wav");
			}
			/*
			if (GetDistance(tug,"gtow3")<100.0f)
			{
				FailMission(GetTime()+5.0f,"isdf16l1");
				mission_state=10;
			}
			*/
			break;
			
		case 9:  // player gets into the bigh
			if ((GetDistance(player,goal1)<25.0f)
				||
				(GetDistance(player,goal2)<25.0f)
								||
				(GetDistance(player,goal3)<25.0f)
				||
				(GetDistance(player,goal4)<25.0f))
			{
				// Play cineractive
				mission_state++;
			}
			break;
			/*
				End cineractive.
			*/
		case 10:
			break;
		case 12:
			/*
				You lose

			*/
				FailMission(GetTime()+10.0f,"isdf1605.otf");
				mission_state++;
			break;

	} // switch	
	
}
