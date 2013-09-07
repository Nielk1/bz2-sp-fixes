#include "..\Shared\SPMission.h"

class isdf20Mission : public SPMission 
{
public:
	isdf20Mission(void)
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
	void PeriodicAttack(void);
	bool PostLoad(bool missionSave);
	// bools
	bool
		b_first,
		first_thing,
		start_done,
		ambush1_spawned,
		go_home,
		killed_spire,
		ebase_dead,
		uhoh_played,
		seen_scout1,
		seen_scout2,
		seen_manson,
		b_last;

	// floats
	float
		next_scrap, // for Nathan's debugging
		f_first,
		after_briefing,
		uhoh,
		ambush_delay,
		f_last;

	// handles
	Handle
		h_first,
		audio, // audio msg
		nav, // selected nav
		player,
		mbike_1,
	    mbike_2,
		mbike_3,
		tank_1,
		tank_2,
		etank_1,
		etank_2,
		etank_3,
		earch_1,
		earch_2,
		earch_3,
		eatank_1,
		eatank_2,
		eatank_3,
		scav_1,	
		scav_2,
		serv_1,
		espir_2,
		esent_1,
		esent_2,
		espir_1,
		rckt_1,
		rckt_2,
		base_1,
		base_2,
		base_3,
		base_4,
		espir_3,
		esent_3,
		esent_4,
		manson,
		slide1,
		slide2, // slide objects??
		annoy_scout1,
		annoy_scout2,
		h_last;

	// integers
	int
		i_first,
		comp_team,
		mission_state,
		annoy_timer,
		i_last;
};
DLLBase * BuildMission(void)
{
	return new isdf20Mission();
}

void isdf20Mission::Setup(void)
{
	SetAutoGroupUnits(false);
/*
	Here's where you set the values at the start.  
*/

//  bools
	start_done = false;
	first_thing= true;
	ambush1_spawned= false;
	go_home= false;
	seen_scout1= false;
	seen_scout2= false;
  //  floats
  uhoh = 99999.0f;
  ambush_delay=999999.0f;

	next_scrap=GetTime()+30.0f;
//  handles
	player = GetPlayerHandle();
	mbike_1 = NULL;
	mbike_2 = NULL;
	mbike_3 = NULL;
	tank_1 = NULL;
	tank_2 = NULL;
	etank_1 = NULL;
	etank_2 = NULL;
//  etank_3 = NULL;
	earch_1 = NULL;
	earch_2 = NULL;
//  earch_3 = NULL;
	eatank_1 = NULL;
	eatank_2 = NULL;
	eatank_3 = NULL;
	scav_1 = NULL;
	scav_2 = NULL;
	espir_2 = NULL;
	esent_1 = NULL;
	esent_2 = NULL;
	espir_1 = NULL;
	after_briefing = NULL;
	rckt_1 = NULL;
	rckt_2 = NULL;
	base_1 = NULL;
	base_2 = NULL;
	base_3 = NULL;
	espir_3 = NULL;
	esent_3 = NULL;
	esent_4 = NULL;
	annoy_scout1=NULL;
	annoy_scout2=NULL;
//  integers
	annoy_timer=0;
	comp_team=6;
	SetTeamColor(comp_team,114,197,255);
	mission_state=0;

}

void isdf20Mission::AddObject(Handle h)
{
/*
	if ((scav1 == NULL) && (IsOdf(h,"ivscav")))
	{
		scav1 = h;
	}
	else if ((scav2 == NULL) && (IsOdf(h,"ivscav")))
	{
		scav2 = h;
	}
	else if ((turret1 == NULL) && (IsOdf(h,"ivturr")))
	{
		turret1 = h;
	}
	else if ((turret2 == NULL) && (IsOdf(h,"ivturr")))
	{
		turret2 = h;
	}
	else if ((wingman1 == NULL) && (IsOdf(h,"ivscout")))
	{
		wingman1 = h;
	}
	else if ((wingman2 == NULL) && (IsOdf(h,"ivscout")))
	{
		wingman2 = h;
	}
*/
}


void isdf20Mission::PeriodicAttack(void)
{
	char tempstr[128];
	if ((mission_state<6) && (!IsAlive(annoy_scout1))
		&& (!IsAlive(annoy_scout2))
		&& (annoy_timer>300))
	{
		annoy_timer=0;
	}
	if (annoy_timer==300)
	{
		annoy_scout1=BuildObject("ivscout",comp_team,"lung2");
		annoy_scout2=BuildObject("ivscout",comp_team,"lung2");
		Attack(annoy_scout1,player);
		Attack(annoy_scout2,serv_1);
		seen_scout1=false;
		seen_scout2=false;
	}
	if ((!seen_scout1) && 
		(GetDistance(annoy_scout1,player)<100.0f)) 
	{
		seen_scout1=true;
		SetObjectiveOn(annoy_scout1);
		TranslateString2(tempstr, sizeof(tempstr), "Mission2001");  // Rebel
		SetObjectiveName(annoy_scout1,tempstr);
	}
	if ((!seen_scout2) && (GetDistance(annoy_scout2,player)<100.0f))
	{
		seen_scout2=true;
		SetObjectiveOn(annoy_scout2);
		TranslateString2(tempstr, sizeof(tempstr), "Mission2001");  // Rebel
		SetObjectiveName(annoy_scout2,tempstr);

	}
	annoy_timer++;
}

bool isdf20Mission::PostLoad(bool missionSave)
{
	bool ret = SPMission::PostLoad(missionSave);

	if (missionSave)
		return ret;
	SetTeamColor(comp_team,114,197,255);

//	SetTeamColor(2,0,127,255);  //BRADDOCK
//	SetTeamColor(3,0,127,255);  //BRADDOCK


	return ret;
}

void isdf20Mission::Execute(void)
{
/*
	Here is where you put what happens every frame.  
*/


	/*
		LANDSLIDE INFO
		- .bzn has file reslida1.odf
		- Don't forget to delete bin data before you try this
		- Run animation on reslid01.odf
		- Replace it with reslidea1.odf
	*/
	player = GetPlayerHandle();
	char tempstr[128]; 
	Ally(1,3);
	switch (mission_state)
	{
		case 0:
				    // build this stuff at start
		/*	
				Handle recy=BuildObject("ivrecy",1,"Recycler");
				int grp=GetFirstEmptyGroup();
			SetGroup(recy,grp);			
			SetScrap(1,30);
			*/
			// deleted for Nathan
			  /*
			mbike_1=BuildObject("ivmbike",3,"mbike1");
			mbike_2=BuildObject("ivmbike",3,"mbike2");
		    mbike_3=BuildObject("ivmbike",3,"mbike3");
			*/
		    tank_1=BuildObject("ivatank",1,"tank1");  // was atank
			SetGroup(tank_1,0);
			tank_2=BuildObject("ivrckt",1,"tank2");  // was atank
			SetGroup(tank_2,1);
			// serv= BuildObject("ivserv",1,"serv");
			// Set
			//    scav_1=BuildObject("ivscav",1,"scav1");
			//    scav_2=BuildObject("ivscav",1,"scav2");
//			rckt_1=BuildObject("ivrckt",1,"rckt1");
//			rckt_2=BuildObject("ivrckt",1,"rckt2");
			SetGroup(rckt_1,1);
			SetGroup(rckt_2,1);
			serv_1=BuildObject("ivserv",1,"scav1");
			SetGroup(serv_1,2);

			espir_2=BuildObject("ibgtow",comp_team,"base_here");
			esent_1=BuildObject("ivmisl",comp_team,"esentpath1");
			esent_2=BuildObject("ivmisl",comp_team,"esentpath1");
			espir_1=BuildObject("ibgtow",comp_team,"espir1");
			base_1=BuildObject("ibfact",comp_team,"estro1");
			base_2=BuildObject("ibpgen",comp_team,"ekiln1");

			base_3=BuildObject("ibpgen",comp_team,"power_x");  // was eforg1
			base_4=BuildObject("ibcbun",comp_team,"bunker_x");
			espir_3=BuildObject("ibgtow",comp_team,"espir3");
			esent_3=BuildObject("ivscout",comp_team,"esent3");
			esent_4=BuildObject("ivscout",comp_team,"esent4");
			ClearObjectives();
			AddObjective("isdf20a.otf",WHITE,10.0f);
			Patrol(esent_1,"esentpath1");
			Follow(esent_2,esent_1);
			after_briefing= GetTime()+20.0f;
			slide1=GetHandle("unnamed_reslida1");
			//Vector temp=GetPosition(slide1);
			RemoveObject(slide1);

			nav=BuildObject("ibnav",1,"lung2");
			SetObjectiveOn(nav);
			TranslateString2(tempstr, sizeof(tempstr), "Mission2002");  // Rebel Base
			SetObjectiveName(nav,tempstr);
			// SetPosition(slide2??

			/*
				So the mission isn't too slow. 
			*/
			AddHealth(espir_1,-3000);
			AddHealth(espir_2,-3000);
			mission_state++;
			audio=AudioMessage("isdf2021.wav");
			CameraReady();
			break;
		case 1:
			CameraPath("camera1",200,200,player);

//			CameraObject(espir_1,30,20,20,espir_1);
			if (IsAudioMessageDone(audio))
			{
				audio=AudioMessage("isdf2022.wav");
				mission_state++;	
			}
			break;
		case 2 :
			CameraPath("camera2",200,200,espir_2);
			if (IsAudioMessageDone(audio))
			{	
				AudioMessage("isdf2001.wav");
				CameraFinish();
				mission_state++;
			}
			break;
		case 3:  //the attack begins
			
				// after the opening briefing, AI squadron drives to fight sentry units on their own
				if (GetTime() > after_briefing)
				{
				//	Goto(mbike_1,"front_ambush");
				//	Goto(mbike_2,"front_ambush");
				//	Goto(mbike_3,"front_ambush");
				//	Goto(rckt_1,"front_ambush");
				//	Goto(rckt_2,"front_ambush");
					Handle temp=BuildObject("ivscout",comp_team,"lung2");
					Attack(temp,player);
					mission_state++;
				}
			
			break;
		case 4: // Kill the sentries

  			// AI squadron engages sentry units
			if ((GetDistance(tank_1,"front_ambush")<200.0f)  ||
			      (GetDistance(tank_2,"front_ambush")<200.0f)  ||
					(GetDistance(rckt_1,"front_ambush")<200.0f)  ||
					(GetDistance(rckt_2,"front_ambush")<200.0f)  ||
					(GetDistance(player,"front_ambush")<200.0f) )
			{
				/*
				Attack(mbike_1,esent_1);
				Attack(mbike_2,esent_2);
				Attack(mbike_3,esent_1);
				*/
				SetObjectiveOn(esent_1);

				TranslateString2(tempstr, sizeof(tempstr), "Mission2001");  // Rebel
				SetObjectiveName(esent_1,tempstr);
				SetObjectiveOn(esent_2);
				SetObjectiveName(esent_2,tempstr);
		//		Attack(rckt_1,esent_2);
		//		Attack(rckt_2,esent_1);
			}
// once the sentrys are destroyed, AI squadron heads to enemy gun tower and stops
			if ((!IsAlive(esent_1))  &&  (!IsAlive(esent_2)))
			{
				/*
				Goto(mbike_1,"front_ambush");
				Goto(mbike_2,"front_ambush");
				Goto(mbike_3,"front_ambush");
				*/
		//		Goto(rckt_1,"front_ambush");
		//		Goto(rckt_2,"front_ambush");
		//		temp=BuildObject("ivscout",2,"lung2");
		//		Attack(temp,serv_1);
				mission_state++;
			}
			break;
		case 5:  // wait till they get to the tower
			if ((
				(GetDistance(tank_1,"front_ambush")<75.0f)  ||
				(GetDistance(rckt_2,"front_ambush")<75.0f)  ||
				(GetDistance(player,"front_ambush")<75.0f)))
				{
					Handle temp=BuildObject("ivscout",comp_team,"lung2");
					Attack(temp,player);
					AudioMessage("isdf2002.wav"); // use your assault tanks
					ClearObjectives();
					AddObjective("isdf2002.otf",WHITE,20.0f);
					SetObjectiveOn(espir_1);
				TranslateString2(tempstr, sizeof(tempstr), "Mission2003");  // Gun Tower
					SetObjectiveName(espir_1,tempstr);
					//temp=BuildObject("ivscout",2,"lung2");
					//Attack(temp,player);
					mission_state++;
				}
			break;
		case 6: // destroy the tower
// once you destroy the gun tower, AI squadron heads to next gun tower and stops
				if (!IsAlive(espir_1))  
				{
					Goto(mbike_1,"exit1");
					Goto(mbike_2,"exit1");
					Goto(mbike_3,"exit1");
		//			AudioMessage("isdf2003.wav"); // now let's press on to the base
		//			Goto(rckt_1,"exit1");
		//			Goto(rckt_2,"exit1");
		//			temp=BuildObject("ivscout",2,"lung2");
		//			Attack(temp,serv_1);
					mission_state++;
  
				}			
			break;
		case 7:  // now go to the next tower
			if (((GetDistance(tank_1,"exit1")<50.0f)  ||
				(GetDistance(rckt_1,"exit1")<50.0f)  ||
				(GetDistance(player,"exit1")<50.0f))) 
			{
				ClearObjectives();
				AddObjective("isdf2003.otf",WHITE,20.0f);
				AudioMessage("isdf2003.wav");
				mission_state++;
			}
			break;
		case 8:  // until enemy spire is dead
			if (!IsAlive(espir_2))	
			{
//				Attack(mbike_1,base_1);
//				Attack(mbike_2,base_1);
//				Attack(mbike_3,base_1);
				Attack(rckt_1,base_1,0);
				Attack(rckt_2,base_1,0);
				mission_state++;
			}
			break;
		case 9:
			if (!IsAlive(base_1)) 
			{
//				Attack(mbike_1,base_2);
//				Attack(mbike_2,base_2);
//				Attack(mbike_3,base_2);
				AudioMessage("isdf2004.wav");
				Attack(rckt_1,base_2,0);
				Attack(rckt_2,base_2,0);
				mission_state++;
			}

			break;
		case 10:
			if (!IsAlive(base_2))
			{
//				Attack(mbike_1,base_3);
//				Attack(mbike_2,base_3);
//				Attack(mbike_3,base_3);
				Attack(rckt_1,base_3,0);
				Attack(rckt_2,base_3,0);
				mission_state++;
			}
			break;
		case 11:// is the third base dead?
			if (!IsAlive(base_3))  
			{
/*
				Goto(mbike_1,"homebase");
				Goto(mbike_2,"homebase");
				Goto(mbike_3,"homebase");
*/
				Goto(rckt_1,"homebase",0);
				Goto(rckt_2,"homebase",0);
				// keep the player bunched up
				Follow(tank_1,player,0);
				Follow(tank_2,player,0);

				ClearObjectives();
				AddObjective("isdf2004.otf",WHITE,20.0f);
				SetObjectiveOff(nav);
				nav=BuildObject("ibnav",1,"scav2");
				TranslateString2(tempstr, sizeof(tempstr), "Mission2004");  // Rencezvous
				SetObjectiveName(nav,tempstr);
				SetObjectiveOn(nav);
				AudioMessage("isdf2005.wav");
				mission_state++;
			}
			break;
		case 12:
// first ambush launches as soon as you exit enemy base after destroying it
// second ambush comes in from behind
			if  (GetDistance(player,"exit1")<125.0f)
			{		
	  
				  ambush_delay=GetTime()+15.0f;
				  mission_state++;
			}
			break;
		case 13:
			if (GetTime()>ambush_delay) 
			{
				eatank_1=BuildObject("ivtank",comp_team,"eatank1");
				eatank_2=BuildObject("ivtank",comp_team,"eatank2");
				eatank_3=BuildObject("ivmbike",comp_team,"eatank3");
				SetSkill(eatank_1,2);
				SetSkill(eatank_2,2);
				SetSkill(eatank_3,2);
				Attack(eatank_1,player);
				Attack(eatank_2,player);
				Attack(eatank_3,player);
				etank_1=BuildObject("ivtank",comp_team,"etank1");
				etank_2=BuildObject("ivtank",comp_team,"etank2");
				etank_3=BuildObject("ivmbike",comp_team,"etank3");
				earch_1=BuildObject("ivtank",comp_team,"earch1");
				earch_2=BuildObject("ivtank",comp_team,"earch2");
				earch_3=BuildObject("ivmisl",comp_team,"earch3");
				manson= BuildObject("ivatank",comp_team,"manson");
				Attack(etank_1,player);
				Attack(etank_2,player);
				Attack(etank_3,player);
				Attack(earch_1,player);
				Attack(earch_2,player);
				Attack(earch_3,player);
				Attack(manson,player);
				uhoh= GetTime()+20.0f;
				mission_state++;
			}
			break;			
		case 14:
			if (GetTime() > uhoh) 
			{
				AudioMessage("isdf2006.wav");
				AudioMessage("isdf2007.wav");
				ClearObjectives();
				AddObjective("isdf2005.otf",WHITE,20.0f);
				Handle temp=BuildObject("ivapc",comp_team,"lung2");  // now you are screwed
				Attack(temp,player);
//				temp=BuildObject("ivapc",2,"lung2");
//				Attack(temp,player);
				mission_state++;
			}
			break;
		case 15:
			// how do you win??
			if ((!seen_manson) && (GetDistance(player,manson)<200.0f))
			{
				seen_manson=true;
				SetObjectiveOn(manson);
			}
			if (!IsAlive(manson))
			{
				AudioMessage("isdf2010.wav");	
				SucceedMission(GetTime()+10.0f,"isdf20w1.txt");
				mission_state++;
			}

			break;
	}  // switch (mission_state)
	PeriodicAttack();











// once you destroy the second gun tower, AI squadron enters enemy base and levels it

// infinite health and ammo
//    SetCurAmmo(player, 1200);
//    SetCurHealth(player, 3000);

// tells player to head back to base
//  if ((!IsAlive(enemybase))  &&  (!go_home))
//  {
//    AudioMessage("wahoo.wav");
//    go_home=true;
//  }

 

}